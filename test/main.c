#include "../VB.h"
#include "mod.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


VB_C_CPP_FILE(

DEFINE_LATER DECL p AS int* END; // extern int* a;
DECL b AS char const END = 'X'; // char const b;

#define N 10
DECL ARRAY( arr OF_SIZE N ) AS int END; // int arr[N];
#define I 5
#define J 3
DECL ARRAY(ARRAY( matrix OF_SIZE I) OF_SIZE J) AS int END; // int matrix[I][J];


DECL a AS int END = 7;
DECL p AS int* END = &a;

TYPEDEF MyName AS int END

STRUCT LinkedListNode 
START_STRUCT
    DECL data AS MyName END;
    DECL next AS LinkedListNode* END;
    DECL FUNCTION_POINTER( insertAfter OF (
        DECL this AS LinkedListNode* END, 
        DECL item AS LinkedListNode* END
    ) ) AS bool END;
END_STRUCT
ENUM DaysOfWeek
START_ENUM
    Monday, 
    Tueasday
END_ENUM

FUNCTION main OF (DECL argc AS int END, DECL argv AS char** END) AS int
START_FUNCTION
    myLog("%d", a);
    IF 0 <= a && a < 10 THEN
        myLog("0", a);
    ELSE_IF -10 < a THEN
        myLog("1", a);
    ELSE
        myLog("2", a);
    END_IF

    SCOPE                  // {
        DECL a AS int END; //     int a;
        a = 30;
        myLog("%d", a);
    END_SCOPE              // }

    myLog("%d", a);
    WHILE a < 10
    START_WHILE
        myLog("while %d", a);
        a = 40;
    END_WHILE
    
    myLog("%d", a);
    DO
        DECL a AS int END = 100;
        myLog("do %d", a);
    ALL_THE_WHILE a < 50 END_DO
    myLog("%d", a);

    FOR (DECL i AS int END = 0; DECL j AS unsigned END;), i < 10, ++i;
    START_FOR
        myLog("for %d", i);
    END_FOR

    PREFOR (DECL c AS char END;), c = getchar();, c != 'q'
    START_PREFOR
        myLog("prefor %c", c);
    END_PREFOR
    
    DECL n AS int END = 5;
    DECL k AS int END = 2;
    printf("%lf", CAST(n AS double) / k); // ((double)n) / k
    
    DECL llnkrk AS LinkedListNode END;
    
    
    
END_FUNCTION




)
