# VB.C/C++
## Visual Basic-like syntax for C/C++

The whole project are just 2 header files with a bunch of macros.  
Do you want to declare a function pointer,   
well then `DECL fp AS_FUNC OF (args) AS return_type END`  
!! VB.C++ might be incomlpete !!

---
## syntax:

Important!!  
Whole file excluding #includes should be surrounded by VB_C_CPP_FILE macro  
// actually, probably only #includes that use VB.H(PP), but better be safe than sorry  
```c
#include "VB.H"
VB_C_CPP_FILE(
code in file
)
```

### VB.C

declaration of variable:
```VB
DEFINE_LATER DECL a AS int* END; // extern int* a;
DECL b AS char const END = 'X'; // char const b = 'X';
```
declaration of array:
```VB
DECL arr AS int ARRAY [N] = {1, 1, REST_ALL_ZEROS}; // int arr[N] = {1,1,};
DECL matrix AS int ARRAY [I][J] = ZERO_ARRAY; // int matrix[I][J] = {0};
```
cast:
```VB
CAST(n AS double) / k // ((double)(n)) / k
CAST(f AS_FUNC OF (void*) AS void) // ((void (*)(void*)) f)
```
variable scope:
```VB
SCOPE                  // {
    DECL a AS int END; //     int a;
END                    // }
```
if:
```VB
FORK IF 0 <= a && a < 10 THEN
    printf(...);
ELSE IF -10 < a THEN
    printf(...);
ELSE
    printf(...);
END
```
switch:  
no `BREAK` needed  
however, `BREAK` will exit switch, not loop that may be outside  
```vb
FORK x
CASE a THEN
    printf(...);
CASE a THEN
    printf(...);
DEFAULT
    printf(...);
END
```
loop:  
generic chained loop  
It can have 0 or more `WHILE`s & `SKIP IF`s  
and if there is code after `WHILE` there has to be `DO`  
```VB
// chain
LOOP 
    DECL n AS int END = inputInt();
WHILE n > 0 DO
    printf("you entered %d ", n);
SKIP_IF n == 0 OTHERWISE
    DECL m AS int END = f(n);
WHILE m > 0 DO
    printf("%d ", m);
END
// infinite
LOOP
    ...
END
// while
LOOP WHILE a < b DO
    ...
END
// do
LOOP
    ...
WHILE a < b
END
```
for:  
syntax is `FOR decl PREP prep COND cond STEP step START code END`  
`PREP prep` and `STEP step` are optional  
it is possible to declare multiple variables  
and to have however complicated statements in decl, prep and step  
be careful with semicolons  
```VB
FOR DECL i AS int END = 0; DECL c AS char END;
    PREP c = str[i];
    COND c != '\0'
    STEP ++i;
START
    printf(...);
END
```
there are also `SKIP`, `BREAK`, `PASS` keywords (continue, break, do nothing)  
function:  
```VB
GLOBAL_PRIVATE FUNCTION myLog OF (DECL message AS char* END, ...) AS void END // GLOBAL_PRIVATE is translation unit private (static)
FUNCTION main OF (DECL argc AS int END, DECL argv AS char** END) AS int
START
    myLog(); myLog(); 
END
GLOBAL_PRIVATE FUNCTION myLog OF (DECL message AS char* END, ...) AS void
START
    LOCAL_DEFINE_ONCE DECL counter AS int END = 0;
    printf("#%d ", counter++); // printf(message, __VA_ARGS__);
END
```
function pointer:  
It suports "only" 10 levels of functions returning functions  
```VB
DECL fp AS_FUNC OF (int, int) AS unsigned long END;
// OR (AS_FUNC is optional)
DECL fp OF (DECL AS int END, DECL AS int END) AS unsigned long END;
```
struct & enum:
```VB
STRUCT LinkedListNode 
START
    DECL data AS void* END;
    DECL next AS LinkedListNode* END;
    DECL insertAfter AS_FUNC OF (
        DECL this AS LinkedListNode* END, 
        DECL item AS LinkedListNode* END
    ) AS bool END;
END
ENUM DaysOfWeek
START
    DaysOfWeek_Monday, 
    ...
END
```
typedef:
```VB
TYPEDEF MyName AS int END TYPE
TYPEDEF CommonFunction AS_FUNC OF (int, int) AS int END TYPE
TYPEDEF Row AS int ARRAY [5] TYPE
```



You cannot `DECL` multiple variables at once  
Pointers to arrays, and other such shenanigans, are not supported  
// pointer to array would be `int (*a)[N];`


---
### VB.C++

Everything from VB.C applies here  
With some added functionality  
!! VB.C++ might be incomlpete !!  

class & template:
```VB
TEMPLATE <TYPENAME T>
CLASS LinkedList
START
    PRIVATE:
        DECL head AS LinkedListNode* END;
        STATIC FUNCTION createFromArray OF (DECL size AS int END, DECL arr AS T* END) AS LinkedList<T>* END
    PROTECTED:
    PUBLIC:
        FRIEND FUNCTION ...
        FUNCTION OPERATOR << OF (DECL item AS T END) AS bool END
END
```
namespace:
```VB
NAMESPACE LinkedListNMSP 
CONTAINING
    ...
END
```
using:
```VB
USING NAMESPACE std;
```
foreach:
```VB
FOR_EACH elm AS auto& IN list
START
    ...
END
```
try catch:
```VB
TRY
    THROW std::runtime_error("error");
CATCH e AS std::exception const& DO_THIS
    ...
CATCH_ALL
    THROW;
END
```
