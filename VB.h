#ifndef VB_H
#define VB_H


#define VB_C_CPP_FILE(...) __VA_ARGS__

#define ARGS(...) __VA_ARGS__

#define ___LB (

#define IF if (
#define THEN ) {
#define ELSEIF } else if (
#define ELSE } else {
#define ENDIF }

#define WHILE while (
#define STARTWHILE ) {
#define ENDWHILE }

#define ___DO(CODE, COND) while (true) { CODE if (COND) break; }
#define DO ___DO ___LB
#define ALLTHEWHILE , (
#define ENDDO ))

#define ___FOR(DECL, COND, STEP, CODE) { ARGS DECL while (COND) { CODE STEP } }
#define FOR ___FOR ___LB
#define STARTFOR , {
#define ENDFOR })

#define ___PREFOR(DECL, STEP, COND, CODE) { ARGS DECL STEP while (COND) { CODE STEP } }
#define PREFOR ___PREFOR ___LB
#define STARTPREFOR , {
#define ENDPREFOR })


#define SCOPE {
#define ENDSCOPE }

#define AS ,
#define OF ,
#define OF_SIZE ,

#define ___DECLARE(var, type) type var
#define DECLARE(var_AS_type) ___DECLARE(var_AS_type)

#define TYPEDEF(name_AS_type) typedef ___DECLARE(name_AS_type)

#define GLOBAL_PRIVATE static

#define LOCAL_DEFINE_ONCE static

#define ___CAST(exp, type) ((type) (exp))
#define CAST(expression_AS_type) ___CAST(expression_AS_type)

#define ___ARRAY(name, size) name[size]
#define ARRAY(name_OF_SIZE_size) ARRAY(name_OF_SIZE_size) 

#define ___FUNCTION(name, args, type) ___DECLARE(name args, type)
#define FUNCTION ___FUNCTION ___LB
#define ENDFUNCDECL );
#define STARTFUNCTION ) {
#define ENDFUNCTION }

#define ___FUNCTION_POINTER(name, args) (*name) args
#define FUNCTION_POINTER(name_OF_args) ___FUNCTION_POINTER(name_OF_args)

#define ___STRUCT(name, body) typedef struct name name; struct name body;
#define ___STRUCT_CONST(name, body) typedef const struct name name; const struct name body;
#define STRUCT ___STRUCT ___LB
#define STRUCT_CONST ___STRUCT_CONST ___LB 
#define STARTSTRUCT , {
#define ENDSTRUCT })

#define ___ENUM(name, body) typedef enum name name; enum name body;
#define ENUM ___ENUM ___LB
#define STARTENUM , {
#define ENDENUM })

#define RETURN return

#define DEFINE_LATER extern

#endif

