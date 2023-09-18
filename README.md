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

At first, it was just a pair of macros:  
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
- so that they don't clash with C keywords  

## Usage  
  
_side note: as everything defined by VB.C is ALL CAPS_,  
_in examples in this document, things that are not will be some kind of placeholder (e.g. `expr` for C expression)_  

It compiles with any C compiler  
To use VB.C in your program  
1) Copy [VB.H file](https://github.com/HeliumHe-He/VB.C-CPP/blob/main/VB.H) in your project  
2) `#include` it  
3) Write `VB_C_CODE(code)` here code should be any code that uses VB.C (typically the whole file), except for `#includes` (VB_C_FILE is a synonym for VB_C_CODE, though it's deprecated (you can leave it in old code))  
4) It is also recommended that you call your file with the .VB.c extension (or .VB.h) (or even .VB.C/.VB.H if you are daring)  
  so that tools aiming at the VB.C can easily find the VB.C code  
  
It is recommended to compile with the `-ftrack-macro-expansion=0` (or 1) option to not get long error messages full of VB_C macros  
  
## Syntax  
### Declarations  

There are 4 forms:  
1) `DECL var AS type END`  
2) `DECL ptr AS qualifier POINTER TO type END` (if the type is not complex, this can be also `DECL ptr AS type* qualifier END`)  
3) `DECL arr AS (type) ARRAY [m][n]... END` (if the type is not complex, parentheses can be omitted)  
4) `DECL fun AS qualifier FUNC (args) RETURNING type END` (args can be comma-separated: simple types or `DECL`'d arguments, examples down below)  
  (if a function returns `void`, you can omit `RETURNING type`)  
  
Here, in each of the 4 forms, the type can be simple, or complex.  
The type being complex means that it is in the form `POINTER TO`, `ARRAY`, `FUNC`  
This "recursion" can go *only* 10 levels deep  
(therefore, you cannot have `POINTER TO POINTER TO FUNC () RETURNING POINTER TO ((FUNC () RETURNING POINTER TO (POINTER TO POINTER TO char) ARRAY [5]) ARRAY [6]) ARRAY [7] END`).  
  
After the `END` keyword, you can type C assignment ` = expr;` or just `;`.  
  
So, to declare an array of 10 constant pointers to a function, with no arguments, returning char*  
`DECL farr AS (const FUNC () RETURNING char*) ARRAY [10] END`  
  
I recommend you don't declare ARRAY OF ARRAY, because it's not intuitive.  
Dimensions get flipped. Equivalent of  
`DECL mat AS int ARRAY [m][n]` is  
`DECL mat AS (int ARRAY [n]) ARRAY [m] END` (don't do this)  
  
### Type alias (typedef)  
  
Equivalent to the declaration of a variable as type,  
you **typedef type alias as type**  
`TYPEDEF VeryOftenUsedFunctionPointer AS FUNC OF (void*, int) END`  
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
There can also optionally be multiple `CASE THEN`s and/or `DEFAULT` at the end.  
```  
FORK expr  
CASE a THEN  
    stmt  
CASE b THEN  
    stmt  
DEFAULT  
    stmt  
END  
```  
You can use the `FALLTHROUGH` keyword to fallthrough to the next case  
You can also omit `THEN` to fallthrough  
```  
FORK expr  
CASE a THEN  
    FORK IF cond THEN FALLTHROUGH; END  
CASE b  
CASE c THEN  
    code  
END  
```  

### Control flow: looping in general  

_Things written here apply to both `LOOP` and `FOR`_  

Every loop defines its own scope, so it is possible to declare variables.  
Every loop has its name (`LOOP(name) ...`).  
Name can be omitted, but, in MSVC, you maybe can't have more than 1 nameless loop in function (that is because MSVC doesn't implement [local labels](https://gcc.gnu.org/onlinedocs/gcc/Local-Labels.html)).  

Loop control flow:  
- `BREAK(name)` stops the loop execution  
- `STOP(name)` stops the loop execution, but executes the `DIDNT_BREAK` block  
- `SKIP(name)` skips the rest of the loop body and starts the next iteration (but executes the `STEP` block)  

In each of these name is optional, if omitted, it affects the current loop.  

There are also these loop control flows:  
- `BREAK_IF cond OTHERWISE` equivalent to `FORK IF cond THEN BREAK(); END`  
- `STOP_IF cond OTHERWISE` equivalent to `FORK IF cond THEN STOP(); END`  
- `WHILE cond DO` equivalent to `FORK IF !(cond) THEN STOP(); END`  
  `DO` can be omitted if it is the end of the loop (e.g. `LOOP code WHILE cond END`)  
- `SKIP_IF cond OTHERWISE` equivalent to `FORK IF cond THEN SKIP(); END`  

Loop blocks:  
- `BEFORE` executed once before loop starts, defines variable scope (that can_t be used outside the loop)  
- `START` loop body  
- `STEP` executed after each iteration, even if `SKIP` occurred  
- `DIDNT_BREAK` executed once after the loop, if the loop didn't break  
- `AFTER` executed once after the loop  

example:  
```  
LOOP(name)  
START  
    FORK IF cond THEN   
        SKIP(name);  
    END  
WHILE cond DO  
    stmt1  
AFTER  
    stmt2  
END  
```  


### Control flow: `LOOP`  

∞ loop  
```  
LOOP(name)  
    stmt  
END  
```  

If `LOOP` doesn't have a `BEFORE` block, it doesn't need the `START` keyword  
otherwise  
```  
LOOP(name)  
BEFORE  
    stmt  
START  
    stmt  
END  
```  


### Control flow: `FOR`  

```  
FOR element AS type IN iterator  
START  
    stmt  
END  
  
FOR element IN iterator  
START  
    stmt  
END  
```  
What are `element` and `type`, and the name of the loop is determined by the iterator.  


#### Iterators  
Iterator can be custom-defined  
VB.C provides `COUNT`, and some array iterators:  
- `COUNT` numeric iterator  
- `ARRAY_ITERATOR` iterate through an array  
- `VOID_ITERATOR`/`VOID_ARRAY_ITERATOR` iterate through void array  
- `CSTRING_ITERATOR` iterate through a null-terminated string  
- `MATRIX_ITERATOR`, `VOID_MATRIX_ITERATOR`, `TENSOR3_ITERATOR`, `VOID_TENSOR3_ITERATOR`  
- `REVERSED` reverses an iterator, if the iterator implements reversing  

More about custom iterator implementation in [Custom Iterators](#custom-iterators)  

##### COUNT  

The general form is `FOR i AS int IN COUNT(n FROM a BY d UNTIL b TO b)` (though this is actually not valid syntax).  
The loop name is `i`.  
Each part except `n` is unordered.  
Each part is optional.  
You can have only `n`, `UNTIL b`, or `TO b` as an upper bound.  
`a` and `b` can be of any (arithmetic) type (like pointer or float).  
Parts have meanings:  
- `n` there will be exactly `n` iterations  
- `FROM a` starting value, default 0  
- `BY d` increment, default ±1  
- `UNTIL b` upper bound (not inclusive), default ∞  
- `TO b` upper bound (inclusive)  

Exception is syntax `COUNT(a UNTIL b)`:  
Which is equivalent to `COUNT(FROM a UNTIL b)`.  
You can add `BY d`.  
You can use `TO b`.  

Other special cases:  
If `b < a` and `d` is not present, then `d` is set to `-1`.  
If neither `n` or `b` are present, then iteration is ∞.  
If `d = 0`, and `UNTIL b` is present, and `a != b`, then iteration is ∞, it repeats `a`.  
If `d = 0` and `n` is present, then repeat `a` `n` times.  


##### ARRAYs  

###### ARRAY ITERATOR  
`FOR (i, elm_ptr) AS elm_type IN ARRAY_ITERATOR(arr, size)`  
`FOR (i, elm_ptr) AS elm_type IN ARRAY_ITERATOR(arr, size SLICED_BY(COUNT(...)))`  
The loop name is `elm_ptr`.  
`elm_ptr` is initialized as `elm_type* const elm_ptr = &arr[i];`  
Both `i` and `elm_ptr` (pointer, not element inside) are constant.  
The upper bound is automatically inserted into the slice.  

###### VOID ITERATOR  
Alias: `VOID_ARRAY_ITERATOR`  
`FOR (i, elm_ptr) IN VOID_ITERATOR(arr, elm_size, size)`  
`FOR (i, elm_ptr) AS const IN VOID_ITERATOR(arr, elm_size, size SLICED_BY(...))`  
Same as [ARRAY_ITERATOR](#array-iterator) except the type is `void` or `void const` (other qualifiers may be set, like `volatile`).  

###### C-STRING ITERATOR  
`FOR (i, elm_ptr) IN CSTRING_ITERATOR(str)`  
`FOR (i, elm_ptr) AS char const IN CSTRING_ITERATOR(str SLICED_BY(...))`  
`FOR (i, elm_ptr) AS wchar_t const IN CSTRING_ITERATOR(str)`  
Same as [ARRAY_ITERATOR](#array-iterator) except the size is determined by null-char at the end.  

###### MULTIDIMENSIONAL ARRAY ITERATORS  
Have non-void and void versions.  
`MATRIX` and `TENSOR3` iterators (`MATRIX_ITERATOR`, `VOID_MATRIX_ITERATOR`, `TENSOR3_ITERATOR`, `VOID_TENSOR3_ITERATOR`)  
`FOR ((i, j), elm_ptr) AS elm_type IN MATRIX_ITERATOR(arr, (size_i, size_j))`  
`FOR ((i, j), elm_ptr) AS elm_type IN MATRIX_ITERATOR(arr, (size_i, size_j) SLICED_BY(COUNT(...), COUNT(...)))`  
Iterates through contiguous memory.  
~~Subsequent slices can be dependent on the previous.~~  

##### REVERSED  
Can be applied to the COUNT, and unsliced array iterators (even COUNT inside slice).  
It works by appending `__VB_C_REVERSED_M` on the modifiers (note that iterator is free to ignore it).  
And note that REVERSED COUNT may be different than COUNT with `-d`:  
`         COUNT(FROM 12 UNTIL 1 BY -3)` = (12, 9, 6, 3)  
`REVERSED(COUNT(FROM 1 UNTIL 12 BY 3))` = (10, 7, 4, 1)  


  
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
If a function returns `void`, `RETURNING void` can be omitted.  

### Structures  

```  
STRUCT name  
START  
    decl  
END  
```  
Struct will be accessible by `name` (and maybe `struct name`) (e.g. `DECL a AS name END`).  
  
You can also declare struct using `STRUCT name END`.  
You can also use an anonymous struct (e.g. `DECL a AS STRUCT ANONYMOUS members END`).  
`ANON` is an alias for `ANONYMOUS`.  
There is also limited support for generics  
```  
#define Array(T, N) VB_C_CODE( STRUCT GENERIC \  
    decl                                      \  
END )  
```  
The reason for this VB_C_CODE here will be explained in [Miscellaneous](#miscellaneous).  
notice also \\ at ends of lines (except the last) (required by C)  
  
### Enumerations  

```  
ENUM name  
    A, B, C, ...  
END  
```  
`name` will be accessible by itself (and maybe by `enum name`).  
A, B, C, ... will be in global/local scope (or however [C defines it](https://en.cppreference.com/w/c/language/enum)).  
  
### Miscellaneous  

There is the `RETURN` keyword.  
  
There is the `PASS;` statement as an empty statement (no-operation) (it is not standard to not add `;` after `PASS`)  
  
There is the `VB_C_LABEL(name, purpose)` macro to get the name of the label (for purpose `SKIP` uses `NEXT`, `WHILE` uses `AFTER`, and `BREAK` uses `BREAK`).  
  
There is the `GLOBAL_PRIVATE` keyword for global functions and variables that aren't accessible outside of the file (actually translation unit, but whatever).  
Those shouldn't be declared in the header file.  
  
There is the `LOCAL_DEFINE_ONCE` keyword to define a variable inside the function  
that will be defined only once (before the first function call?)  
and whose state will be preserved in between function calls.  
*[cppreference](https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/language/storage_duration.html) search for "Static local variables" on page*  

For instantiation of arrays, there are  
`ZERO_ARRAY` to make the array full of zeroes.  
`REST_ALL_ZEROS` to make other elements of array 0, used like ` = { 1, 5, 8, REST_ALL_ZEROS };`  
  
When defining macros that use VB.C code, enclose that code in `VB_C_CODE`, so that it is usable even when some other program is not using VB.C.  

It is not standard to prefix your identifiers with VB_C or __VB_C as it may conflict with VB.H.  
VB.H might define a new keyword that will be ALL CAPS without those prefixes (sorry about that).  
This means that it's not really safe to make ALL CAPS identifiers at all, though, I believe that migration would be trivial.  

---  

## Conclusion  

I'm not too happy about this project.  
It made some wonderful things, but it also made some ugly.  
  
First, every file has to be enclosed by VB_C_CODE, which is not cool.  
Something even less cool is that error messages are bad:  
you get a huge error message because a lot of macros are involved,  
and you even don't know what line is erroneous, because C macros don't keep newlines (so everything is on the line where VB_C_CODE is)  
  
This also makes debugging, using tools, not possible.  
  
I don't mind the verbosity of the language,  
though it really can be annoying  
when you have a lot of argument declarations  
inside already too long function declaration.  
  
A complaint can be made, that ALL CAPS is not pretty,  
but I think it even helps to differentiate parts of the code  
(of course, I'm actually wrong, there is the syntax highlighting for that).  
  
And that is another low point of the language:  
syntax highlight is trash,  
as no VSCode (or other IDE) extensions exist that recognize those keywords.  
This can be seen even in this file, where no VB.C code is colored.  
  
IntelliSense support (completions) is limited.  
CLion actually can offer completions for members of a `STRUCT`.  
  
## Future  
  
I'm thinking of reviving VB.C++ (that was a thing for a short time during v2 (I think)).  
  
I'm planning to make a VSCode extension and maybe a JetBrains plugin for syntax highlight.  
  
As for debugging, I'm planning to make a tool  
that you will run on your project root (or a single file?)  
which will transform all .VB.c files in the project into normal C code  
(but leaving the VB.C source in the comment at the bottom)  
and back.  
This can be probably done by running through the preprocessor once, and then the formatter.  

Maybe some class-like iterators (using getNext & hasNext methods)  

I want to make it possible to apply `REVERSED` twice.  
  
## Common patterns  

```  
// returns incremented value on each call (first 0, then 1 on next call, then 2, 3, ...)  
FUNCTION counter OF () RETURNING int  
START  
    LOCAL_DEFINE_ONCE DECL count AS int END = 0;  
    RETURN ++count;  
END   
```  
```  
// initialize all elements to 5  
FOR x AS in IN ARRAY_ITERATOR(arr, n) START *x = 5; END  
```  
```  
// while loop  
LOOP() WHILE cond DO  
    stmt  
END  
```  
```  
// do loop  
LOOP()  
    stmt  
WHILE cond  
END  
```  
```  
// read characters from the input, skip if not digit  
LOOP()  
    DECL c AS char END = getchar();  
WHILE() c != EOF DO  
SKIP_IF !('0' <= c && c <= '9') OTHERWISE  
    ...  
```  
```  
// finding if any value that meets the condition  
FOR x IN ...  
START  
    FORK IF cond THEN   
        // there is such value  
        BREAK();   
    END  
DIDNT_BREAK  
    // there isn't such value  
END  
```  

## Custom iterators  

Iterator must return `iterator_function, (iterator_args), (iterator_modifiers)`  
where `iterator_function` is a macro function of the prototype  
`(element, type, (iterator_args), (iterator_modifiers)) -> name, (before), (before_step), (before_each), (after_each), (after_step), (didnt_break), (after)`  
Which will be called with values provided in `FOR element AS type`.  
`element` will have added parentheses (which can be removed with `__VB_C_RRB_F0` (remove required bracket)).  
`type` will be in a format that is accepted by `__VB_C_TYPE_RESOLVE_F0`

For example, let's create a simple array iterator  

```c  
/** (arr, size) -> f, args, modifiers */  
#define MY_ARRAY_ITERATOR(arr, size) MY_ARRAY_ITERATOR_F0, (arr, size), ()  

/** ((i, el), type, (args), (modifiers)) -> name, (before), (before_step), (before_each), (after_each), (after_step), (didnt_break), (after) */  
#define MY_ARRAY_ITERATOR_F0(                    i_el, type, args, modifiers) MY_ARRAY_ITERATOR_F1(__VB_C_RRB2_F0(i_el), type, __VB_C_RRB_F0(args), __VB_C_RRB_F0(modifiers))  
#define MY_ARRAY_ITERATOR_F1(                    ...)                         MY_ARRAY_ITERATOR_F2(__VA_ARGS__) // always skip one for macro expansion  
#define MY_ARRAY_ITERATOR_F2(                    i, el, type, arr, size, ...) MY_ARRAY_ITERATOR_F2 ## __VA_ARGS__ ## _F0(i, el, type, arr, size) // __VA_ARGS__ expands to "" or to "__VB_C_REVERSED_M"  
//                                                                            name, before                                                                                                                               , before_step                                     , before_each                                                                                 , after_each, after_step      , didnt_break, after  
#define MY_ARRAY_ITERATOR_F2_F0(                 i, el, type, arr, size, ...) el  , (int const __MY_VB_C_size = size; int __MY_VB_C_i = 0                 ; __VB_C_TYPE_RESOLVE_F0((* const __MY_VB_C_arr), type) = arr;), (if (__MY_VB_C_i >= __MY_VB_C_size) {STOP(el);}), (int const i = __MY_VB_C_i; __VB_C_TYPE_RESOLVE_F0((* const el), type) = &arr[__MY_VB_C_i];), ()        , (++__MY_VB_C_i;), ()         , ()  
#define MY_ARRAY_ITERATOR_F2__VB_C_REVERSED_M_F0(i, el, type, arr, size)      el  , (int const __MY_VB_C_size = size; int __MY_VB_C_i = __MY_VB_C_size - 1; __VB_C_TYPE_RESOLVE_F0((* const __MY_VB_C_arr), type) = arr;), (if (__MY_VB_C_i >= __MY_VB_C_size) {STOP(el);}), (int const i = __MY_VB_C_i; __VB_C_TYPE_RESOLVE_F0((* const el), type) = &arr[__MY_VB_C_i];), ()        , (--__MY_VB_C_i;), ()         , ()  

int numbers[5];  
FOR (index, number) AS int IN MY_ARRAY_ITERATOR(numbers, 5)  
START  
    *number = index * index;  
END  
for (int i = 0; i < 5; i++) printf("%d    ", numbers[i]);  
// prints: "0    1    4    9    16    "  
```  
