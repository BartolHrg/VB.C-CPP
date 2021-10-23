# VB.C/C++
## Visual Basic-like syntax for C/C++

The whole project are just 2 header files with a bunch of macros.  
Do you want to declare a function pointer,   
well then `DECL FUNCTION_POINTER( fp OF (args) ) AS return_type END`

---
## syntax:

Important!!  
Whole file should be surrounded by VB_C_CPP_FILE macro  
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
DECL b AS char const END = 'X'; // char const b;
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
ENDSCOPE               // }
```
if:
```VB
IF 0 <= a && a < 10 THEN
    printf(...);
ELSEIF -10 < a THEN
    printf(...);
ELSE
    printf(...);
ENDIF
```
while:
```VB
WHILE a < 10
STARTWHILE
    printf(...);
ENDWHILE
```
for:  
syntax is `FOR (decl), cond, step STARTFOR code ENDFOR  
decl has to be in parentheses; things are separated with commas  
it is possible to declare multiple variables  
```VB
FOR (DECL a AS int END = 0; DECL j AS unsigned END;), a < 10, ++a;
STARTFOR
    printf(...);
ENDFOR
```
prefor:  
syntax is similar to for (cond & step are in different order)  
like for, but executes step before cond  
```VB
PREFOR (DECL c AS char END), c = getchar();, c != EOF
STARTPREFOR
    printf(...);
ENDPREFOR
```
do:  
variables declared inside are visible in condition
```VB
DO
    DECL a AS int END = 100;
    printf(...);
ALLTHEWHILE a < 10
ENDDO
```
function
```VB
GLOBAL_PRIVATE FUNCTION log OF (DECL message AS char*), ...) AS void ENDFUNCDECL // GLOBAL_PRIVATE is translation unit private (static END
FUNCTION main OF (DECL argc AS int END, DECL argv AS char** END) AS int
STARTFUNCTION
    LOCAL_DEFINE_ONCE DECL counter AS int END = 0;
    log("Hello World %d", counter++);
ENDFUNCTION
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
STARTSTRUCT
    DECL data AS void* END;
    DECL next AS LinkedListNode* END;
    DECL FUNCTION_POINTER( insertAfter OF (
        DECL this AS LinkedListNode* END, 
        DECL item AS LinkedListNode* END
    ) ) AS bool END;
ENDSTRUCT
ENUM DaysOfWeek
STARTENUM
    Monday, 
    ...
ENDENUM
// also there is STRUCT_CONST (& CLASS_CONST in C++) (google "const struct declaration")
```
typedef:
```VB
TYPEDEF(MyName AS int);
```



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
STARTCLASS
    PRIVATE:
        DECL head AS LinkedListNode* END;
        STATIC FUNCTION createFromArray OF (DECL size AS int END, DECL arr AS T* END) AS LinkedList<T>* ENDFUNCDECL
    PROTECTED:
    PUBLIC:
        FRIEND FUNCTION ...
        FUNCTION OPERATOR << OF (DECL item AS T END) AS bool ENDFUNCDECL
ENDCLASS
// also there is CLASS_CONST (google "const struct declaration")
```
namespace:
```VB
NAMESPACE LinkedListNMSP 
STARTNAMESPACE
    ...
ENDNAMESPACE
```
using:
```VB
USING NAMESPACE std;
```
try catch:
```VB
TRY
    THROW std::runtime_error("error");
CATCH DECL e AS std::exception const& END DOTHIS
    ...
CATCHALL DOTHIS
    ...
ENDTRY
```