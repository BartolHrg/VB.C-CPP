#include "../VB.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

VB_C_CPP_FILE(

GLOBAL_PRIVATE FUNCTION fp OF (DECL message AS char* END, DECL a AS int END) AS void END_FUNC_DECL // GLOBAL_PRIVATE is translation unit private (static)

DEFINE_LATER DECL FUNCTION_POINTER( myLog OF (char*, int) ) AS void END;

)