#include "../VB.h"
#include "mod.h"

VB_C_CPP_FILE(
    

GLOBAL_PRIVATE FUNCTION fp OF (DECL message AS char* END, DECL a AS int END) AS void // GLOBAL_PRIVATE is translation unit private (static)
START_FUNCTION
    LOCAL_DEFINE_ONCE DECL counter AS int END = 0;
    printf("#%d %s %d", counter++, message, a); 
    
    printf("\n");
END_FUNCTION

DECL FUNCTION_POINTER( myLog OF (char*, int) ) AS void END = fp;

)
