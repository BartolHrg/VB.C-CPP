#ifndef VB_H
#define VB_H


#define __VB_C_CPP_FILE(...) __VA_ARGS__
#define VB_C_CPP_FILE(...) __VB_C_CPP_FILE(__VA_ARGS__)

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

#define __VB_C_CPP_DO(code, cond) while (1) { __VB_C_CPP_ARGS code if (!cond) break; }
#define DO __VB_C_CPP_DO __VB_C_CPP_LB (
#define ALL_THE_WHILE ), (
#define END_DO ) __VB_C_CPP_RB

#define __VB_C_CPP_FOR(decl, prep, cond, step, code) { decl while (1) { __VB_C_CPP_ARGS prep if (!cond) break; __VB_C_CPP_ARGS code __VB_C_CPP_ARGS step} }
#define FOR __VB_C_CPP_FOR __VB_C_CPP_LB
#define PREP , (
#define COND ), (
#define STEP ), (
#define START_FOR ), ({
#define END_FOR }) __VB_C_CPP_RB

#define PASS 
#define CONTINUE continue
#define BREAK break

#define SCOPE {
#define END_SCOPE }

#define __VB_C_CPP_DECL2(var, type) __VB_C_CPP_ARGS type var
#define __VB_C_CPP_DECL(var, type) __VB_C_CPP_DECL2( var, type)
#define DECL __VB_C_CPP_DECL __VB_C_CPP_LB __VB_C_CPP_ARGS __VB_C_CPP_LB
#define AS __VB_C_CPP_RB, (
#define END ) __VB_C_CPP_RB

#define ARRAY END
#define ZERO_ARRAY {0}
#define REST_ALL_ZEROS

#define __VB_C_CPP_TYPEDEF(name, type) typedef __VB_C_CPP_ARGS type name;
#define TYPEDEF __VB_C_CPP_TYPEDEF __VB_C_CPP_LB __VB_C_CPP_ARGS __VB_C_CPP_LB

#define __VB_C_CPP_CAST(exp, type) (type exp)
#define _CAST(expression_AS_type) __VB_C_CPP_CAST((expression_AS_type))
#define CAST(...) __VB_C_CPP_CAST((__VA_ARGS__))

#define __VB_C_CPP_FUNCTION(name_OF_args, type) __VB_C_CPP_DECL(name_OF_args, type)
#define FUNCTION __VB_C_CPP_FUNCTION __VB_C_CPP_LB __VB_C_CPP_ARGS __VB_C_CPP_LB __VB_C_CPP_ARGS __VB_C_CPP_LB
#define OF __VB_C_CPP_RB
#define END_FUNC_DECL ) __VB_C_CPP_RB;
#define START_FUNCTION ) __VB_C_CPP_RB {
#define END_FUNCTION }
#define RETURN return

#define __VB_C_CPP_FP(name) (*name) 
#define FP __VB_C_CPP_FP __VB_C_CPP_LB
#define FUNCTION_POINTER

#define __VB_C_CPP_STRUCT(name, body) typedef struct __VB_C_CPP_ARGS name __VB_C_CPP_ARGS name; struct __VB_C_CPP_ARGS name __VB_C_CPP_ARGS body;
#define __VB_C_CPP_STRUCT_CONST(name, body) typedef const struct name name; const struct name body;
#define STRUCT __VB_C_CPP_STRUCT __VB_C_CPP_LB (
#define STRUCT_CONST __VB_C_CPP_STRUCT_CONST __VB_C_CPP_LB (
#define START_STRUCT ), ({
#define END_STRUCT }) __VB_C_CPP_RB

#define __VB_C_CPP_ENUM(name, body) typedef enum __VB_C_CPP_ARGS name __VB_C_CPP_ARGS name; enum __VB_C_CPP_ARGS name __VB_C_CPP_ARGS body;
#define ENUM __VB_C_CPP_ENUM __VB_C_CPP_LB (
#define START_ENUM ), ({
#define END_ENUM }) __VB_C_CPP_RB

#define DEFINE_LATER extern
#define GLOBAL_PRIVATE static
#define LOCAL_DEFINE_ONCE static


#endif // VB_H

