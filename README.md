# VB.C
## Visual Basic-like syntax for C

The whole project is just a single header file with a bunch of macros.  
Do you want to declare a function pointer,   
well then `DECLARE(FUNCTION_POINTER( fp OF (args) ) AS return_type )`

---
##### syntax:
declaration of variable:
```VB
DECLARE(a AS int*); // int* a;
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
PRIVATE FUNCTION( log OF (DECLARE(message AS char*)) AS void ); // PRIVATE is translation unit private
FUNCTION( main OF (DECLARE(argc AS int), DECLARE(argv AS char**)) AS int )
STARTFUNCTION
    log("Hello World");
ENDFUNCTION
```
function pointer
```VB
DECLARE(FUNCTION_POINTER( fp OF (int, int) ) AS unsigned long );
// OR
DECLARE(FUNCTION_POINTER( fp OF (DECLARE(AS int), DECLARE(AS int)) ) AS unsigned long );
```
struct:
```VB
STRUCT (LinkedListNode)
    DECLARE(data AS void*);
    DECLARE(next AS LinkedListNode*);
    DECLARE(FUNCTION_POINTER( insertAfter OF (
        DECLARE(this AS LinkedListNode*), 
        DECLARE(item AS LinkedListNode*)
    ) ) AS bool );
ENDSTRUCT
```
