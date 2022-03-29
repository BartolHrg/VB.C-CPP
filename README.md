# VB.C  
## _Visual Basic-like syntax for C_  

[VB.C github](https://github.com/HeliumHe-He/VB.C-CPP)
  
Contrary to what the name suggests, it has little to do with actual (Visual) Basic language(s)  
It only looks similar, so I gave it that name.  
  
The project aims to give a C alternative,  
that is easy to read,  
but doesn't need additional dependencies,  
apart from a single header file.  
  

## How it started  

At first it was just a pair of macros:  
```c  
#define DECL(var, type) type var  
#define AS ,  
DECL(x AS int)
```  
(Though this is not entirely correct)  
Because I didn't like normal C syntax for declaration (among other things in C)  
But this doesn't work for more complex types, like function pointers, pointers to arrays, etc.  
  
Then I defined more fun things (IF, FOR, PREFOR, WHILE, FUNCTION, TYPEDEF, STRUCT, ...)
  
Now, you might wonder, why is it all CAPITAL LETTERS:  
- because the C convention for macros is for them to be CAPS  
- so that they don't ???argue??? with C keywords  

## Usage  
  
_side note: as everything defined by VB.C is ALL CAPS_  
_in examples in this document, things that are not will be some kind of placeholder (e.g. `expr` for C expression)_  

It compiles with any C compiler  
To use VB.C in your program  
1) Copy [VB.H file](https://github.com/HeliumHe-He/VB.C-CPP/blob/main/VB.H) in your project  
2) `#include` it  
3) Write `VB_C_FILE(code)` here code should be the whole code in the file, except for `#includes`  
4) It is also recommended that you call your file with the .VB.c extension (or .VB.h)  
so that tools aiming the VB.C can easily find the VB.C code  
  
## Syntax  
### Declarations  

There are 4 forms:  
1) `DECL var AS type END`  
2) `DECL ptr AS POINTER TO type END` (if the type is not complex, this can be also `DECL ptr AS type* END`)
3) `DECL arr AS ARRAY OF (type) OF SIZE [m][n]... END` (if the type is not complex, parentheses can be omitted)
4) `DECL fun AS FUNC OF (args) RETURNING type END` (args can be comma-separated: simple types, `DECL`'d arguments, examples down below)
  
Here, in each of the 4 forms, the type can be simple, or complex.  
The type being complex means that it is in the form `POINTER TO`, `ARRAY OF`, `FUNC OF`  
This "recursion" can GO *only* 10 levels deep  
(therefore, you cannot have `POINTER TO POINTER TO FUNC OF () RETURNING POINTER TO ARRAY OF (ARRAY OF (FUNC OF () RETURNING POINTER TO ARRAY OF (POINTER TO POINTER TO char) OF SIZE [5]) OF SIZE [6]) OF SIZE [7] END`).  
  
After the `END` keyword, you can type C assignment ` = expr;` or just `;`.  
  
So, to declare an array of 10 constant pointers to a function, with no arguments, returning char*  
`DECL farr AS ARRAY OF (FUNC OF () RETURNING char*) OF SIZE [10] END`  
  
I recommend you don't declare ARRAY OF ARRAY, because it's not really intuitive.  
Dimensions get flipped. Equivalent of  
`DECL mat AS ARRAY OF int OF SIZE [m][n]` is  
`DECL mat AS ARRAY OF (ARRAY OF int OF SIZE [n]) OF SIZE [m] END`  
  
### Type alias (typedef)
  
Equivalent to the declaration of a variable as type,  
you typedef type alias as type  
`TYPEDEF VeryOftenUsedFunctionPointer AS FUNC OF (void*, int) RETURNING void END`  
_(notice, no `;` needed)_  
  
### Casting  

Casting expression to type is similar to the declaration  
`CAST(expr AS type)`  
And, of course, casting will have bigger precedence than any operator  
So it is safe to do `CAST(expr AS type).member`  
  
### Control flow: if  

```  
FORK IF cond THEN  
    statement  
END  
```  
Each `IF` defines its own scope, so it is possible to declare variables.  
In between, there can also optionally be multiple `ELSE IF`s and/or `ELSE` at the end.  
```  
FORK IF cond THEN  
    stmt  
ELSE IF cond THEN  
    stmt  
ELSE IF cond THEN  
    stmt  
ELSE  
    stmt  
END  
```  

### Control flow: switch  

```  
FORK expr  
CASE a THEN  
    stmt  
END  
```  
There doesn't need to be break at the end of `stmt`.  
It is also possible to break out of the outer loop, from inside `stmt` (something that is not possible in C).  
Each `CASE` defines its own scope, so it is possible to declare variables.  
There can also optionally be multiple `CASE a THEN`s and/or `DEFAULT` at the end.  
```  
FORK expr  
CASE a THEN  
    stmt  
CASE B+b THEN  
    stmt  
DEFAULT  
    stmt  
END  
```  

### Control flow: looping in general  

_Things written here apply to both `LOOP` and `FOR`_  

Every loop defines its own scope, so it is possible to declare variables.  
Every loop has its name (`LOOP(name) ...`).  
Name can be omitted, but, in MSVC, you maybe can't have more than 1 nameless loop in function (that is because MSVC doesn't implement [local labels](https://gcc.gnu.org/onlinedocs/gcc/Local-Labels.html)).  
To terminate loop execution (`break`) you use `BREAK(name)` (where the name can be omitted, in which case, it breaks out of the inner-most nameless loop).  
To skip the rest of the loop body, and go to the next iteration (`continue`) you use `SKIP(name)`.  
It is also not safe to use C keywords `break` and `continue` (they might work).  
After the loop body, there can optionally be a `DIDNT_BREAK` block (guess what it does) (it is inspired by [Python's else](https://docs.python.org/3/tutorial/controlflow.html#break-and-continue-statements-and-else-clauses-on-loops)).  
It is not standard to access the loop's variables inside didn't break statement.  
It executes once after the loop if the loop didn't break  
```  
LOOP(name)
    stmt  
DIDNT_BREAK  
    stmt  
END  
```  

### Control flow: `LOOP`  

We start with an ∞ loop  
```  
LOOP(name)
    stmt  
END  
```  
to exit the loop at some point, use  
```  
LOOP(name)
    stmt1  
WHILE(name) cond DO  
    stmt2  
END  
```  
This executes stmt1 once, checks the condition  
If the condition is not met, exit the loop, else execute stmt2 once, and loop back to the beginning of the loop.  
The name has to be the same as the loop name.  
(it doesn't categorize as a break, so if the condition is not met, it executes the `DIDNT_BREAK` block)  
If `WHILE(name) cond` is the last thing in the loop (there is no stmt after it), `DO` can be omitted (to look like the `do` loop)  
```  
LOOP(name)
    stmt  
WHILE(name) cond  
END  
```  

There is also 
```  
LOOP(name)
    stmt1  
SKIP_IF(name) cond OTHERWISE  
    stmt2  
END  
```  
It is similar to `WHILE`, only it doesn't exit the loop, but returns back to the beginning of it (`SKIP`)'.  
Unlike `DO` in `WHILE`, `OTHERWISE` has to be always present,  
as it doesn't make any sense to not have stmt after it  
because then there is nothing to skip.  

`WHILE` and `SKIP_IF` can occur however many times in whatever order.  
  

### Control flow: `FOR`  

_The Devil himself_  
I spent half my time implementing this.  
  
It has 3 forms:  
- FOR CLASSIC  
- FOR RANGE  
- FOR ARRAY  

But they all have in common  
```  
FOR something  
START  
    body  
END  
```  

Loop defines a few scopes. The whole loop looks like  
```c  
{  
    // loop's outer scope  
    looping {  
        // loop's inner scope  
        stmt  
    }  
    didnt_break stmt  
}  
```  

In each form there can be (prep, cond, step), more about that later.  
It might be possible to use `WHILE` and `SKIP_IF` with FOR loop (but it is not standard yet).  
  
#### FOR CLASSIC  

It came first and is the only form of FOR loop in version 3 of the language.  
Like `for(decl; cond; step)` in C it has decl, **prep**, cond, step with similar semantics (prep is not present in C).  
decl is executed once, in the loop's outer scope.  
Then, in every iteration of the loop,  
first prep is executed,  
than cond evaluated (and maybe exit loop),  
than loop body  
and then step.  
```  
FOR(name) decl  
    PREP prep  
    COND cond  
    STEP step  
START...  
```  

decl, prep, and step can be however complex statements (unlike in C where they are limited to a single statement).  
cond is, of course, expression.  
  
Each is optional (cond defaults to true) (e.g. `FOR STEP step START...`).  
  
If body `SKIP`s, step is executed anyway.  
If cond is not met, didn't break *is* executed (because, like with `WHILE`, `COND` is not considered breaking).  
  
prep, cond, step (but not decl) can be present in other `FOR` forms.  
  
In decl you would often find `DECL i AS int END = 0`  
Before I added the name to the loops, that `DECL` would be aligned with `PREP` and others  
and that was very nice and now I'm sad (but not all hope is lost, see [Future](#future)).  
  
#### FOR RANGE  

```  
FOR() var AS (type) IN RANGE FROM a UNTIL b BY inc  
START...  
```  
This iterates over a given range (from a (including) to b (not including) incremented by inc: a, a+inc, ...).  
It is invariant to changes of var (which means that you can change var inside the body),  
and invariant to changes of a, b, inc.  
Instead of `UNTIL`, you can write the `TO` keyword, which includes the upper bound.  
There is also `REVERSED` keyword that flips range (so `RANGE FROM 1 UNTIL 12 BY 3` = (1, 4, 7, 10) becomes `REVERSED RANGE FROM 1 UNTIL 12 BY 3` = (10, 4, 7, 1))
(Notice that `RANGE FROM 12 UNTIL 1 BY -3` = (12, 9, 6, 3) is different)
  
inc can be less than 0, or even equal to 0.  
Each is optional (you could write `RANGE UNTIL n`)  
a defaults to 0, inc to 1, and b is required (except in [FOR ARRAY](#for-array) where it defaults to the length of the array)  
If the type is not complex, parentheses can be omitted.   

It can have  
`    PREP prep`  
`    COND cond`  
`    STEP step`  
(each is optional)  
  
In [FOR RANGE](#for-range) and [FOR ARRAY](#for-array) apart from its name, the loop can be referred to by its variable.  

#### FOR ARRAY  

You can iterate over arrays of 1, 2, or 3 dimensions (keywords `ARRAY`, `MATRIX`, `CUBOID`) (do not use `MATRIX` and `CUBOID` in `DECL`)  
```  
FOR() var IN arr AS ARRAY OF  (type) OF SIZE  m        // notice NO square brackets []  
FOR() var IN arr AS MATRIX OF (type) OF SIZE (m, n)    // notice NO square brackets []  
FOR() var IN arr AS CUBOID OF (type) OF SIZE (m, n, o) // notice NO square brackets []  
```  

Optionally, after `SIZE ()`, there can be `SLICED BY range`.  
For `ARRAY`, range parentheses are optional `(RANGE FROM a UNTIL b BY inc)` or `RANGE FROM a UNTIL b BY inc`  
For `MATRIX` and `CUBOID`, parentheses are required `(RANGE FROM a UNTIL b BY inc, RANGE FROM a UNTIL b BY inc)`  
There is also the `NORMAL` keyword which can be used if you don't want to slice that dimension.  
e.g. every second row of matrix `(RANGE BY 2, NORMAL)`  
Which can be combined with `REVERSED` (`REVERSED NORMAL`).  
  
In the loop body, var is a **pointer to** the array element, so the array element can be modified.  
  
Some variables i, j, k are also defined as const (some) integer type.  
They corespond to position in array (i) / matrix (i, j) / cuboid (i, j, k).  
Using them, you can slice the array (using lesser variable slice greater).  
e.g. upper triangle of the matrix (including diagonal) `(NORMAL, RANGE FROM i)` (j is sliced by i, the other way around is not possible).  
  
It can have  
`    PREP prep`  
`    COND cond`  
`    STEP step`  
(each is optional)  

If the type is not complex, parentheses can be omitted.   
  
In [FOR RANGE](#for-range) and [FOR ARRAY](#for-array) apart from its name, the loop can be referred to by its variable.  
This doesn't apply to i, j, k in [FOR ARRAY](#for-array).  
  
### Scopes  

```  
SCOPE  
    stmt  
END  
```  

### Functions  

To declare a function (similar to the declaration of a function pointer)  
```  
FUNCTION name OF (args) RETURNING type END  
```  
And to instantiate it (yes, ok, "to define it" is official C terminology)  
just add `START body`  
```  
FUNCTION name OF (args) RETURNING type 
START  
    stmt  
END  
```  

### Structures  

```  
STRUCT name  
START  
    decl  
END  
```  
Struct will be accessible by `name` (and maybe `struct name`) (e.g. `DECL a AS name END`).  
  
You can also declare struct using `STRUCT name END`.  
You can also use an anonymous struct (e.g. `DECL a AS STRUCT ANONYMOUS decl END END`).  
`ANON` is a synonym for `ANONYMOUS`.  
There is also limited support for generics  
```  
#define Array(T, N) VB_C_FILE( STRUCT GENERIC \  
    decl                                      \  
END )
```  
The reason for this VB_C_FILE here will be explained in [Miscellaneous](#miscellaneous).  
notice also \ at ends of lines (except the last) (required by C)
  
### Enumerations  

```  
ENUM name  
    A, B, C, ...  
END  
```  
`name` will be accessible by itself (and maybe by `enum name`).  
A, B, C, ... will be in global/local scope (however [C defines it](https://en.cppreference.com/w/c/language/enum)).  
  
### Miscellaneous  

There is the `RETURN` keyword.  
  
There is the `PASS;` statement as an empty statement (nop) (it is not standard to not add `;` after `PASS`)
  
There is the `VB_C_LABEL(name, purpose)` macro to get the name of the label (for purpose `SKIP` uses `NEXT`, `WHILE` uses `AFTER` and `BREAK` uses `BREAK`).  
  
There is the `GLOBAL_PRIVATE` keyword for global functions and variables that aren't accessible outside of the file (actually translation unit, but whatever).  
Those shouldn't be declared in the header file.  
  
There is the `LOCAL_DEFINE_ONCE` keyword to define a variable inside the function  
that will be defined only once (before the first function call?)  
and whose state will be preserved in between function calls.  
*[cppreference](https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/language/storage_duration.html) search for "Static local variables" on page*  

For instantiation of arrays, there are  
`ZERO_ARRAY` to make the array full of zeroes.  
`REST_ALL_ZEROS` to make other elements of array 0, used like ` = { 1, 5, 8, REST_ALL_ZEROS };`  
  
When defining macros that use VB.C code, enclose that code in `VB_C_FILE`, so that it is usable even when some other program is not using VB.C.  
  
---  

## Conclusion  

I'm not too happy about this project.  
It made some wonderful things, but it also made some ugly.  
  
First, every file has to be enclosed by VB_C_FILE, which is really not cool.  
Something even less cool is that error messages are bad:  
you get a huge error message because a lot of macros are involved,  
and you even don't what line is erroneous, because C macros don't keep newlines (so everything is on the line where VB_C_FILE is)
  
This also makes debugging, using tools, not possible.  
  
I don't really mind the verbosity of the language,  
though it really can be annoying  
when you have a lot of argument declarations  
inside already too long function declaration.  
  
A complaint can be made, that ALL CAPS is not pretty,  
but I think it even helps to differentiate parts of code  
(of course, I'm actually wrong, there is the syntax highlighting for that).  
  
And that is another low point of the language:  
syntax highlight is really trash,  
as no VSCode (or other IDE) extensions exist that recognize those keywords.  
This can be clearly seen even in this file, where no VB.C code is colored.  
  
IntelliSense support (completions) is limited.  
CLion actually can offer completions for like members of a `STRUCT`.  
  
## Future  

I'm planning to remove the required parentheses from `LOOP` and `FOR`  
It would be nice to do the same for `WHILE` and `SKIP_IF`, if MSVC wasn't so uncool.  
  
I'm planning to add the `FALLTHROUGH` keyword for [FORK CASE](#Control-flow-switch). (again, hard because of MSVC)  
  
I'm thinking of reviving VB.C++ (that was a thing for a short time during v2 (I think)).  
  
I'm planning to make a VSCode extension and maybe a JetBrains plugin for syntax highlight.  
  
As for debugging, I'm planning to make a tool  
that you will run on your project root (or a single file?)  
which will transform all .VB.c files in the project into normal C code  
(but leaving the VB.C source in the comment at the bottom)  
and back.  
This can be probably done by running through the preprocessor once, and then formatter.  
  
## Common patterns  

```  
// returns incremented value on each call (first 0, than 1 on next call, then 2, 3, ...)
FUNCTION counter OF () RETURNING int  
START  
    LOCAL_DEFINE_ONCE DECL count AS int END = 0;  
    RETURN ++count;  
END  
// iterate over string with index and actual value (similar to enumerate in Python)
FOR() i IN RANGE UNTIL string_length  
    PREP DECL c AS char = string[i];  
START...  
// initialize all elements to 5  
FOR() x IN arr AS ARRAY OF int OF SIZE N  
START  
    *x = 5;  
END  
// iterate over matrix of 2D points, but also get pointers to each x and y member of point  
FOR() p IN points AS MATRIX OF float OF SIZE (m, n)
    PREP  
        DECL x AS float* END = &p->x;  
        DECL y AS float* END = &p->y;  
START...  
// while loop  
LOOP() WHILE() cond DO  
    stmt  
END  
// do loop  
LOOP()
    stmt  
WHILE() cond  
END  
// read characters from the input, skip if not digit  
LOOP()
    DECL c AS char END = getchar();  
WHILE() c != EOF DO  
SKIP_IF !('0' <= c && c <= '9') OTHERWISE  
    ...  
// finding if any value that meets condition  
FOR() x IN arr...  
START  
    FORK IF cond THEN 
        // there is such value  
        BREAK() 
    END  
DIDNT_BREAK  
    // there isn't such value  
END  
```  
