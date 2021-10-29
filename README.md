# VB.C/C++
## Visual Basic-like syntax for C/C++

The whole project are just 2 header files with a bunch of macros.  
Do you want to declare a function pointer,   
well then `DECL FUNCTION_POINTER( fp OF (args) ) AS return_type END`

---
## syntax:

Important!!  
Whole file excluding #includes should be surrounded by VB_C_CPP_FILE macro  
// actually, probably only #includes that use VB.H(PP), but better be safe than sorry  
```c
#include "VB.h"
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
DECL ARRAY( arr OF_SIZE N ) AS int END; // int arr[N];
DECL ARRAY(ARRAY( matrix OF_SIZE I) OF_SIZE J) AS int END; // int matrix[I][J];
```
cast:
```VB
CAST(n AS double) / k // ((double)n) / k
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
while:
```VB
WHILE a < 10
START_WHILE
    printf(...);
END_WHILE
```
do:  
variables declared inside are visible in condition
```VB
DO
    DECL a AS int END = 100;
    printf(...);
ALL_THE_WHILE a < 10 END_DO
```
for:  
syntax is `FOR decl, cond, step START_FOR code END_FOR`  
things are separated with commas  
it is possible to declare multiple variables  
and to have however complicated statements in decl and step
be careful with semicolons  
```VB
FOR 
    DECL a AS int END = 0; DECL j AS unsigned END;, 
    a < 10, 
    ++a;,
START_FOR
    printf(...);
END_FOR
```
prefor:  
syntax is similar to for (cond & step are in different order)  
like for, but executes step before cond  
```VB
PREFOR 
    DECL c AS char END;, 
    c = getchar();, 
    c != EOF,
START_PREFOR
    printf(...);
END_PREFOR
```
function
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
DECL FUNCTION_POINTER( fp OF (int, int) ) AS unsigned long END;
// OR
DECL FUNCTION_POINTER( fp OF (DECL AS int END, DECL AS int END) ) AS unsigned long END;
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
// also there is STRUCT_CONST (& CLASS_CONST in C++) (google "const struct declaration")
```
typedef:
```VB
TYPEDEF MyName AS int END
TYPEDEF FUNCTION_POINTER( CommonFunction OF (int, int) ) AS int END
```



You cannot `DECLARE` multiple variables at once  
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
