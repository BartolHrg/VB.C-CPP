# VB.C/C++
## Visual Basic-like syntax for C/C++

The whole project are just 2 header files with a bunch of macros.  
Do you want to declare a function pointer,   
well then `DECL FUNCTION_POINTER fp OF (args) AS return_type END`

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
```
variable scope:
```VB
SCOPE                  // {
    DECL a AS int END; //     int a;
END_SCOPE              // }
```
if:
```VB
IF 0 <= a && a < 10 THEN
    printf(...);
ELSE_IF -10 < a THEN
    printf(...);
ELSE
    printf(...);
END_IF
```
loop:  
generic chained loop  
It can have 0 or more `WHILE`s  
and if there is code after `WHILE` there has to be `DO`  
```VB
// chain
LOOP 
    DECL n AS int END = inputInt();
WHILE n > 0 DO
    printf("you entered %d ", n);
SKIP IF n == 0 OTHERWISE DO
    DECL m AS int END = f(n);
WHILE m > 0 DO
    printf("%d ", m);
END_LOOP
// infinite
LOOP
    ...
END_LOOP
// while
LOOP WHILE a < b DO
    ...
END_LOOP
// do
LOOP
    ...
WHILE a < b
END_LOOP
```
for:  
syntax is `FOR decl PREP prep COND cond STEP step START_FOR code END_FOR`  
it is possible to declare multiple variables  
and to have however complicated statements in decl, prep and step
be careful with semicolons  
```VB
FOR DECL i AS int END = 0; DECL c AS char END;
    PREP c = str[i];
    COND c != '\0'
    STEP ++i;
START_FOR
    printf(...);
END_FOR
```
there are also `SKIP`, `BREAK`, `PASS` keywords (continue, break, do nothing)
function:
```VB
GLOBAL_PRIVATE FUNCTION myLog OF (DECL message AS char* END, ...) AS void END_FUNC_DECL // GLOBAL_PRIVATE is translation unit private (static)
FUNCTION main OF (DECL argc AS int END, DECL argv AS char** END) AS int
START_FUNCTION
    myLog(); myLog(); 
END_FUNCTION
GLOBAL_PRIVATE FUNCTION myLog OF (DECL message AS char* END, ...) AS void
START_FUNCTION
    LOCAL_DEFINE_ONCE DECL counter AS int END = 0;
    printf("#%d ", counter++); // printf(message, __VA_ARGS__);
END_FUNCTION
```
function pointer
```VB
DECL FP fp OF (int, int) AS unsigned long END;
// OR
DECL FUNCTION_POINTER fp OF (DECL AS int END, DECL AS int END) AS unsigned long END;
```
struct & enum:
```VB
STRUCT LinkedListNode 
START_STRUCT
    DECL data AS void* END;
    DECL next AS LinkedListNode* END;
    DECL FUNCTION_POINTER( insertAfter OF (
        DECL this AS LinkedListNode* END, 
        DECL item AS LinkedListNode* END
    ) ) AS bool END;
END_STRUCT
ENUM DaysOfWeek
START_ENUM
    Monday, 
    ...
END_ENUM
```
typedef:
```VB
TYPEDEF MyName AS int END
TYPEDEF FUNCTION_POINTER CommonFunction OF (int, int) AS int END
```



You cannot `DECL` multiple variables at once  
Pointers to arrays, and other such shenanigans, are not supported  
// pointer to array would be `int (*a)[N];`


---
### VB.C++

Everything from VB.C applies here  
With some added functionality

class & template:
```VB
TEMPLATE <TYPENAME T>
CLASS LinkedList
START_CLASS
    PRIVATE:
        DECL head AS LinkedListNode* END;
        STATIC FUNCTION createFromArray OF (DECL size AS int END, DECL arr AS T* END) AS LinkedList<T>* END_FUNC_DECL
    PROTECTED:
    PUBLIC:
        FRIEND FUNCTION ...
        FUNCTION OPERATOR << OF (DECL item AS T END) AS bool END_FUNC_DECL
END_CLASS
```
namespace:
```VB
NAMESPACE LinkedListNMSP 
START_NAMESPACE
    ...
END_NAMESPACE
```
using:
```VB
USING NAMESPACE std;
```
foreach:
```VB
FOR_EACH elm AS auto& IN list
START_FOR_EACH
    ...
END_FOR_EACH
```
try catch:
```VB
TRY
    THROW std::runtime_error("error");
CATCH e AS std::exception const& DO_THIS
    ...
CATCH_ALL
    THROW;
END_TRY
```
