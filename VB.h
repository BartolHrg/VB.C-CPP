#ifndef VB_H
#define VB_H


#define VB_C_CPP_FILE(...) __VA_ARGS__

#define __VB_C_CPP_ARGS(...) __VA_ARGS__

#define __VB_C_CPP_LB (

#define IF if (
#define THEN ) {
#define ELSEIF } else if (
#define ELSE } else {
#define ENDIF }

#define WHILE while (
#define STARTWHILE ) {
#define ENDWHILE }

#define __VB_C_CPP_DO(CODE, COND) while (true) { CODE if (COND) break; }
#define DO __VB_C_CPP_DO __VB_C_CPP_LB
#define ALLTHEWHILE , (
#define ENDDO ))

#define __VB_C_CPP_FOR(DECL, COND, STEP, CODE) { ARGS DECL while (COND) { CODE STEP } }
#define FOR __VB_C_CPP_FOR __VB_C_CPP_LB
#define STARTFOR , {
#define ENDFOR })

#define __VB_C_CPP_PREFOR(DECL, STEP, COND, CODE) { ARGS DECL STEP while (COND) { CODE STEP } }
#define PREFOR __VB_C_CPP_PREFOR __VB_C_CPP_LB
#define STARTPREFOR , {
#define ENDPREFOR })


#define SCOPE {
#define ENDSCOPE }

#define AS ,
#define OF ,
#define OF_SIZE ,

#define __VB_C_CPP_DECL(var, type) type var
#define DECL __VB_C_CPP_DECL __VB_C_CPP_LB
#define END )

#define __VB_C_CPP_TYPEDEF (name, type) typedef type name;
#define TYPEDEF __VB_C_CPP_DECL __VB_C_CPP_LB

#define GLOBAL_PRIVATE static

#define LOCAL_DEFINE_ONCE static

#define __VB_C_CPP_CAST(exp, type) ((type) (exp))
#define CAST(expression_AS_type) __VB_C_CPP_CAST(expression_AS_type)

#define __VB_C_CPP_ARRAY(name, size) name[size]
#define ARRAY(name_OF_SIZE_size) ARRAY(name_OF_SIZE_size) 

#define __VB_C_CPP_FUNCTION(name, args, type) __VB_C_CPP_DECL(name args, type)
#define FUNCTION __VB_C_CPP_FUNCTION __VB_C_CPP_LB
#define ENDFUNCDECL );
#define STARTFUNCTION ) {
#define ENDFUNCTION }

#define __VB_C_CPP_FUNCTION_POINTER(name, args) (*name) args
#define FUNCTION_POINTER(name_OF_args) __VB_C_CPP_FUNCTION_POINTER(name_OF_args)

#define __VB_C_CPP_STRUCT(name, body) typedef struct name name; struct name body;
#define __VB_C_CPP_STRUCT_CONST(name, body) typedef const struct name name; const struct name body;
#define STRUCT __VB_C_CPP_STRUCT __VB_C_CPP_LB
#define STRUCT_CONST __VB_C_CPP_STRUCT_CONST __VB_C_CPP_LB 
#define STARTSTRUCT , {
#define ENDSTRUCT })

#define __VB_C_CPP_ENUM(name, body) typedef enum name name; enum name body;
#define ENUM __VB_C_CPP_ENUM __VB_C_CPP_LB
#define STARTENUM , {
#define ENDENUM })

#define RETURN return

#define DEFINE_LATER extern

#endif

