#ifndef VB_H
#define VB_H


#define VB_C_CPP_FILE(...) __VA_ARGS__

#define __VB_C_CPP_ARGS(...) __VA_ARGS__

#define __VB_C_CPP_LB (
#define __VB_C_CPP_RB )

#define IF if (
#define THEN ) {
#define ELSE_IF } else if (
#define ELSE } else {
#define END_IF }

#define WHILE while (
#define START_WHILE ) { 
#define END_WHILE }

#define __VB_C_CPP_DO(CODE, COND) while (1) { CODE if (!(COND)) break; }
#define DO __VB_C_CPP_DO __VB_C_CPP_LB
#define ALL_THE_WHILE , (
#define END_DO ) __VB_C_CPP_RB

#define __VB_C_CPP_FOR(decl, prep, cond, step, code) { decl __VB_C_CPP_ARGS prep while cond { __VB_C_CPP_ARGS code __VB_C_CPP_ARGS step __VB_C_CPP_ARGS prep } }
#define FOR __VB_C_CPP_FOR __VB_C_CPP_LB
#define PREP , (
#define COND ), (
#define STEP ), (
#define START_FOR ), ({
#define END_FOR }) __VB_C_CPP_RB

#define SCOPE {
#define END_SCOPE }

#define AS , (
#define OF ,
#define OF_SIZE ,

#define __VB_C_CPP_DECL(var, type) __VB_C_CPP_ARGS type var
#define DECL __VB_C_CPP_DECL __VB_C_CPP_LB
#define END ) __VB_C_CPP_RB

#define __VB_C_CPP_TYPEDEF(name, type) typedef __VB_C_CPP_ARGS type name;
#define TYPEDEF __VB_C_CPP_TYPEDEF __VB_C_CPP_LB

#define GLOBAL_PRIVATE static

#define LOCAL_DEFINE_ONCE static

#define __VB_C_CPP_CAST(exp, type) ((type) (exp))
#define CAST(expression_AS_type) __VB_C_CPP_CAST(expression_AS_type))

#define __VB_C_CPP_ARRAY(name, size) name[size]
#define ARRAY(name_OF_SIZE_size) __VB_C_CPP_ARRAY(name_OF_SIZE_size) 

#define __VB_C_CPP_FUNCTION(name, args, type) __VB_C_CPP_DECL(name args, type)
#define FUNCTION __VB_C_CPP_FUNCTION __VB_C_CPP_LB
#define END_FUNC_DECL ) __VB_C_CPP_RB;
#define START_FUNCTION ) __VB_C_CPP_RB {
#define END_FUNCTION }

#define __VB_C_CPP_FUNCTION_POINTER(name, args) (*name) args
#define FUNCTION_POINTER(name_OF_args) __VB_C_CPP_FUNCTION_POINTER(name_OF_args)

#define __VB_C_CPP_STRUCT(name, body) typedef struct name name; struct name body;
#define __VB_C_CPP_STRUCT_CONST(name, body) typedef const struct name name; const struct name body;
#define STRUCT __VB_C_CPP_STRUCT __VB_C_CPP_LB
#define STRUCT_CONST __VB_C_CPP_STRUCT_CONST __VB_C_CPP_LB 
#define START_STRUCT , {
#define END_STRUCT } __VB_C_CPP_RB

#define __VB_C_CPP_ENUM(name, body) typedef enum name name; enum name __VB_C_CPP_ARGS body;
#define ENUM __VB_C_CPP_ENUM __VB_C_CPP_LB
#define START_ENUM , ({
#define END_ENUM }) __VB_C_CPP_RB

#define RETURN return

#define DEFINE_LATER extern

#endif

