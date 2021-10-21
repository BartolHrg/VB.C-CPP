# VB.C/C++
## Visual Basic-like syntax for C/C++

The whole project are just 2 header files with a bunch of macros.  
Do you want to declare a function pointer,   
well then `DECLARE(FUNCTION_POINTER( fp OF (args) ) AS return_type )`

---
## syntax:
### VB.C

declaration of variable:
```VB
DEFINE_LATER DECLARE(a AS int*); // extern int* a;
DECLARE(b AS char const) = 'X'; char const b;
```
declaration of array:
```VB
DECLARE(ARRAY( arr OF_SIZE N ) AS int); // int arr[N];
DECLARE(ARRAY(ARRAY( matrix OF_SIZE I) OF_SIZE J) AS int); // int matrix[I][J];
```
cast:
```VB
CAST(n AS double) / k // ((double)n) / k
```
variable scope:
```VB
SCOPE                  // {
    DECLARE(a AS int); //     int a;
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
WHILE a < 10 DOTHIS
    printf(...);
ENDWHILE
```
for:
```VB
FOR DECLARE(a AS int) = 0; a < 10; ++a DOTHIS
    printf(...);
ENDFOR
```
do:
```VB
DO
    printf(...);
ALLTHEWHILE a < 10
ENDDO
```
function
```VB
GLOBAL_PRIVATE FUNCTION( log OF (DECLARE(message AS char*), ...) AS void ); // GLOBAL_PRIVATE is translation unit private (static)
FUNCTION( main OF (DECLARE(argc AS int), DECLARE(argv AS char**)) AS int )
STARTFUNCTION
    LOCAL_DEFINE_ONCE DECLARE(counter AS int) = 0;
    log("Hello World %d", counter++);
ENDFUNCTION
```
function pointer
```VB
DECLARE(FUNCTION_POINTER( fp OF (int, int) ) AS unsigned long );
// OR
DECLARE(FUNCTION_POINTER( fp OF (DECLARE(AS int), DECLARE(AS int)) ) AS unsigned long );
```
struct & enum:
```VB
STRUCT( LinkedListNode )
STARTSTRUCT
    DECLARE(data AS void*);
    DECLARE(next AS LinkedListNode*);
    DECLARE(FUNCTION_POINTER( insertAfter OF (
        DECLARE(this AS LinkedListNode*), 
        DECLARE(item AS LinkedListNode*)
    ) ) AS bool );
ENDSTRUCT
ENUM( DaysOfWeek ) 
STARTENUM
    Monday, 
    ...
ENDENUM
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
CLASS( LinkedList )
STARTCLASS
    PRIVATE:
        DECLARE( head AS LinkedListNode* );
        STATIC FUNCTION( createFromArray OF (DECLARE(size AS int), DECLARE(arr AS T*)) AS LinkedList<T>* );
    PROTECTED:
    PUBLIC:
        FRIEND FUNCTION ...
        FUNCTION( OPERATOR << OF (DECLARE(item AS T)) AS bool );
ENDCLASS
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
CATCH DECLARE( e AS std::exception const& ) DOTHIS
    ...
CATCHALL DOTHIS
    ...
ENDTRY
```