#ifndef VB_H
#define VB_H


#define __VB_C_CPP_FILE(...) __VA_ARGS__
#define VB_C_CPP_FILE(...) __VB_C_CPP_FILE(__VA_ARGS__)

#define __VB_C_CPP_ARGS(...) __VA_ARGS__

#define __VB_C_CPP_LB (
#define __VB_C_CPP_RB )


#define __VB_C_CPP_FORK(body, _) __VB_C_CPP_ARGS body }
#define FORK __VB_C_CPP_FORK __VB_C_CPP_LB (
#define IF if (
#define THEN ) {
#define ELSE_IF } else if (
#define ELSE } else {


#define __VB_C_CPP_LOOP(body, _) while (1) { __VB_C_CPP_ARGS body }
#define LOOP __VB_C_CPP_LOOP __VB_C_CPP_LB (
#define __VB_C_CPP_WHILE(...) if (!(__VA_ARGS__)) break;
#define WHILE __VB_C_CPP_RB __VB_C_CPP_WHILE __VB_C_CPP_LB
#define DO __VB_C_CPP_RB __VB_C_CPP_ARGS __VB_C_CPP_LB
#define SKIP
#define OTHERWISE ) continue;

#define __VB_C_CPP_FOR(decl, prep, cond, step, body, _) { \
    __VB_C_CPP_ARGS decl                         \
    while(1) {                                   \
        __VB_C_CPP_ARGS prep                     \
        if (!cond) break;                        \
        __VB_C_CPP_ARGS body                     \
        __VB_C_CPP_ARGS step                     \
    }                                            \
}                                             
#define FOR __VB_C_CPP_FOR __VB_C_CPP_LB (
#define PREP ), (
#define COND ), (
#define STEP ), (

#define PASS 
#define CONTINUE continue
#define BREAK break


#define __VB_C_CPP_SCOPE(body, _) { __VB_C_CPP_ARGS body }
#define SCOPE __VB_C_CPP_SCOPE __VB_C_CPP_LB (


#define __VB_C_CPP_DECL(var, type, _) __VB_C_CPP_ARGS type var
#define DECL __VB_C_CPP_DECL __VB_C_CPP_LB (
#define AS ), (

#define __VB_C_CPP_CAST(exp, type) (type exp)
#define CAST(...) __VB_C_CPP_CAST((__VA_ARGS__))

#define DEFINE_LATER extern
#define GLOBAL_PRIVATE static
#define LOCAL_DEFINE_ONCE static

#define ARRAY ), __VB_C_CPP_ARRAY __VB_C_CPP_RB
#define ZERO_ARRAY {0}
#define REST_ALL_ZEROS


#define __VB_C_CPP_FUNC(name) (*name)
#define FUNC __VB_C_CPP_FUNC __VB_C_CPP_LB (

#define __VB_C_CPP_FUNCTION_BODY__VB_C_CPP_OK(body) { __VB_C_CPP_ARGS body }
#define __VB_C_CPP_FUNCTION_BODY__VB_C_CPP_NO_BODY(body) ;
#define __VB_C_CPP_FUNCTION(name_OF_args, ret_t, body, has_body) __VB_C_CPP_ARGS ret_t __VB_C_CPP_ARGS name_OF_args __VB_C_CPP_FUNCTION_BODY##has_body (body)
#define FUNCTION __VB_C_CPP_FUNCTION __VB_C_CPP_LB __VB_C_CPP_ARGS __VB_C_CPP_LB __VB_C_CPP_ARGS __VB_C_CPP_LB (
#define OF ) __VB_C_CPP_RB
#define NO_BODY ), (), __VB_C_CPP_NO_BODY __VB_C_CPP_RB
#define RETURN return


#define __VB_C_CPP_TYPEDEF(name, type, _) typedef __VB_C_CPP_ARGS type __VB_C_CPP_ARGS name;
#define TYPEDEF __VB_C_CPP_TYPEDEF __VB_C_CPP_LB (

#define __VB_C_CPP_STRUCT(name, body, _) typedef struct __VB_C_CPP_ARGS name __VB_C_CPP_ARGS name; struct __VB_C_CPP_ARGS name { __VB_C_CPP_ARGS body };
#define STRUCT __VB_C_CPP_STRUCT __VB_C_CPP_LB (

#define __VB_C_CPP_ENUM(name, body, _) typedef enum __VB_C_CPP_ARGS name __VB_C_CPP_ARGS name; enum __VB_C_CPP_ARGS name { __VB_C_CPP_ARGS body };
#define ENUM __VB_C_CPP_ENUM __VB_C_CPP_LB (


#define START ), (
#define END ), __VB_C_CPP_OK __VB_C_CPP_RB


#endif // VB_H

