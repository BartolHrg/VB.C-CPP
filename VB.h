#ifndef VB_H
#define VB_H


#define VB_C_CPP_FILE(...) __VA_ARGS__

#define __VB_C_CPP_ARGS(...) __VA_ARGS__

#define __VB_C_CPP_LB (

#define IF if (
#define THEN ) {
#define ELSE_IF } else if (
#define ELSE } else {
#define END_IF }

#define WHILE while (
#define START_WHILE ) {
#define END_WHILE }

#define __VB_C_CPP_DO(CODE, COND) while (true) { CODE if (COND) break; }
#define DO __VB_C_CPP_DO __VB_C_CPP_LB
#define ALL_THE_WHILE , (
#define END_DO ))

#define __VB_C_CPP_FOR(DECL, COND, STEP, CODE) { ARGS DECL while (COND) { CODE STEP } }
#define FOR __VB_C_CPP_FOR __VB_C_CPP_LB
#define START_FOR , {
#define END_FOR })

#define __VB_C_CPP_PREFOR(DECL, STEP, COND, CODE) { ARGS DECL STEP while (COND) { CODE STEP } }
#define PREFOR __VB_C_CPP_PREFOR __VB_C_CPP_LB
#define START_PREFOR , {
#define END_PREFOR })


#define SCOPE {
#define END_SCOPE }

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
#define END_FUNCDECL );
#define START_FUNCTION ) {
#define END_FUNCTION }

#define __VB_C_CPP_FUNCTION_POINTER(name, args) (*name) args
#define FUNCTION_POINTER(name_OF_args) __VB_C_CPP_FUNCTION_POINTER(name_OF_args)

#define __VB_C_CPP_STRUCT(name, body) typedef struct name name; struct name body;
#define __VB_C_CPP_STRUCT_CONST(name, body) typedef const struct name name; const struct name body;
#define STRUCT __VB_C_CPP_STRUCT __VB_C_CPP_LB
#define STRUCT_CONST __VB_C_CPP_STRUCT_CONST __VB_C_CPP_LB 
#define START_STRUCT , {
#define END_STRUCT })

#define __VB_C_CPP_ENUM(name, body) typedef enum name name; enum name body;
#define ENUM __VB_C_CPP_ENUM __VB_C_CPP_LB
#define START_ENUM , {
#define END_ENUM })

#define RETURN return

#define DEFINE_LATER extern

#endif

