#ifndef VB_H
#define VB_H


#define __VB_C_CPP_FILE(...) __VA_ARGS__
#define VB_C_CPP_FILE(...) __VB_C_CPP_FILE(__VA_ARGS__)

#define __VB_C_CPP_ARGS(...) __VA_ARGS__

#define __VB_C_CPP_LB (
#define __VB_C_CPP_RB )


#define __VB_C_CPP_FORK__VB_C_CPP_IF_M(...)
#define __VB_C_CPP_FORK(a, mark, ...) __VB_C_CPP_FORK##mark (a, __VA_ARGS__)
#define __VB_C_CPP_IF(cond) if cond {{
#define __VB_C_CPP_THEN__VB_C_CPP_ELSE_M(body)  __VB_C_CPP_ARGS body }}
#define __VB_C_CPP_THEN__VB_C_CPP_END_M(body)  __VB_C_CPP_ARGS body }}
#define __VB_C_CPP_THEN(body, mark) __VB_C_CPP_THEN##mark (body)
#define __VB_C_CPP_ELSE__VB_C_CPP_IF_M(body) else
#define __VB_C_CPP_ELSE__VB_C_CPP_END_M(body) else {{ __VB_C_CPP_ARGS body }}
#define __VB_C_CPP_ELSE(body, mark) __VB_C_CPP_ELSE##mark (body)
#define FORK __VB_C_CPP_FORK __VB_C_CPP_LB (
#define IF ), __VB_C_CPP_IF_M __VB_C_CPP_RB __VB_C_CPP_IF __VB_C_CPP_LB (
#define THEN ) __VB_C_CPP_RB __VB_C_CPP_THEN __VB_C_CPP_LB (
#define ELSE ), __VB_C_CPP_ELSE_M __VB_C_CPP_RB __VB_C_CPP_ELSE __VB_C_CPP_LB (

#define __VB_C_CPP_FORK__VB_C_CPP_CASE_M(a, ...) switch a {
#define __VB_C_CPP_CASE(a) case a: {
#define __VB_C_CPP_THEN__VB_C_CPP_CASE_M(body) __VB_C_CPP_ARGS body break; }
#define __VB_C_CPP_THEN__VB_C_CPP_DEFAULT_M(body) __VB_C_CPP_ARGS body break; }
#define __VB_C_CPP_DEFAULT(body, mark) default: { __VB_C_CPP_ARGS body } }
#define CASE ), __VB_C_CPP_CASE_M __VB_C_CPP_RB __VB_C_CPP_CASE __VB_C_CPP_LB (
#define DEFAULT ), __VB_C_CPP_DEFAULT_M __VB_C_CPP_RB __VB_C_CPP_DEFAULT __VB_C_CPP_LB (


#define __VB_C_CPP_LOOP(body, _) while (1) { __VB_C_CPP_ARGS body }
#define LOOP __VB_C_CPP_LOOP __VB_C_CPP_LB (
#define __VB_C_CPP_WHILE(...) if (!(__VA_ARGS__)) break;
#define WHILE __VB_C_CPP_RB __VB_C_CPP_WHILE __VB_C_CPP_LB
#define DO __VB_C_CPP_RB __VB_C_CPP_ARGS __VB_C_CPP_LB
#define SKIP_IF if (
#define OTHERWISE ) continue;

#define __VB_C_CPP_FOR_(decl, prep, cond, step, body, ...) {      \
    __VB_C_CPP_ARGS decl                                          \
    char __VB_C_CPP_is_first = true;                              \
    while(1) {                                                    \
        if (!__VB_C_CPP_is_first) {                               \
            __VB_C_CPP_ARGS step                                  \
        } else {                                                  \
            __VB_C_CPP_is_first = false;                          \
        }                                                         \
        __VB_C_CPP_ARGS prep                                      \
        if (!cond) break;                                         \
        __VB_C_CPP_ARGS body                                      \
    }                                                             \
}
#define __VB_C_CPP_FOR2__VB_C_CPP_STEP_M(decl, prep, cond, step, _, body, ...)  __VB_C_CPP_FOR_(decl, prep, cond, step, body)
#define __VB_C_CPP_FOR2__VB_C_CPP_START_M(decl, prep, cond, body, ...)          __VB_C_CPP_FOR_(decl, prep, cond, (  ), body)
#define __VB_C_CPP_FOR__VB_C_CPP_PREP_M(decl, prep, _, cond, mark, ...) __VB_C_CPP_FOR2##mark(decl, prep, cond, __VA_ARGS__)
#define __VB_C_CPP_FOR__VB_C_CPP_COND_M(decl, cond, mark, ...)          __VB_C_CPP_FOR2##mark(decl, (  ), cond, __VA_ARGS__)
#define __VB_C_CPP_FOR(decl, mark, ...) __VB_C_CPP_FOR##mark(decl, __VA_ARGS__)
#define FOR __VB_C_CPP_FOR __VB_C_CPP_LB (
#define PREP ), __VB_C_CPP_PREP_M, (
#define COND ), __VB_C_CPP_COND_M, (
#define STEP ), __VB_C_CPP_STEP_M, (

#define PASS 
#define SKIP continue
#define BREAK break


#define __VB_C_CPP_SCOPE(body, _) { __VB_C_CPP_ARGS body }
#define SCOPE __VB_C_CPP_SCOPE __VB_C_CPP_LB (

#define __VB_C_CPP_DECL__VB_C_CPP_AS_M9(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M9(name, args, ...) __VB_C_CPP_DECL10((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL9(name, h, ...) __VB_C_CPP_DECL##h##9 (name, __VA_ARGS__)
#define __VB_C_CPP_DECL__VB_C_CPP_AS_M8(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M8(name, args, ...) __VB_C_CPP_DECL9((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL8(name, h, ...) __VB_C_CPP_DECL##h##8 (name, __VA_ARGS__)
#define __VB_C_CPP_DECL__VB_C_CPP_AS_M7(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M7(name, args, ...) __VB_C_CPP_DECL8((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL7(name, h, ...) __VB_C_CPP_DECL##h##7 (name, __VA_ARGS__)
#define __VB_C_CPP_DECL__VB_C_CPP_AS_M6(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M6(name, args, ...) __VB_C_CPP_DECL7((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL6(name, h, ...) __VB_C_CPP_DECL##h##6 (name, __VA_ARGS__)
#define __VB_C_CPP_DECL__VB_C_CPP_AS_M5(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M5(name, args, ...) __VB_C_CPP_DECL6((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL5(name, h, ...) __VB_C_CPP_DECL##h##5 (name, __VA_ARGS__)
#define __VB_C_CPP_DECL__VB_C_CPP_AS_M4(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M4(name, args, ...) __VB_C_CPP_DECL5((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL4(name, h, ...) __VB_C_CPP_DECL##h##4 (name, __VA_ARGS__)
#define __VB_C_CPP_DECL__VB_C_CPP_AS_M3(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M3(name, args, ...) __VB_C_CPP_DECL4((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL3(name, h, ...) __VB_C_CPP_DECL##h##3 (name, __VA_ARGS__)
#define __VB_C_CPP_DECL__VB_C_CPP_AS_M2(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M2(name, args, ...) __VB_C_CPP_DECL3((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL2(name, h, ...) __VB_C_CPP_DECL##h##2 (name, __VA_ARGS__)
#define __VB_C_CPP_DECL__VB_C_CPP_AS_M1(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M1(name, args, ...) __VB_C_CPP_DECL2((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL1(name, h, ...) __VB_C_CPP_DECL##h##1 (name, __VA_ARGS__)
#define __VB_C_CPP_DECL__VB_C_CPP_AS_M0(name, type, ...) (__VB_C_CPP_ARGS type name), __VA_ARGS__
#define __VB_C_CPP_DECL__VB_C_CPP_OF_M0(name, args, ...) __VB_C_CPP_DECL1((*name) __VB_C_CPP_ARGS args, __VA_ARGS__)
#define __VB_C_CPP_DECL0(name, h, ...) __VB_C_CPP_DECL##h##0 (name, __VA_ARGS__)

#define __VB_C_CPP_FIRST(first, ...) first
#define __VB_C_CPP_FIRST_ARGS(first, ...) __VB_C_CPP_ARGS first

#define __VB_C_CPP_DECL_(...)  __VB_C_CPP_FIRST_ARGS(__VA_ARGS__)
#define __VB_C_CPP_DECL(var, handle, ...) __VB_C_CPP_DECL_(__VB_C_CPP_DECL0(var, handle, __VA_ARGS__)) // __VB_C_CPP_ARGS type var
#define DECL __VB_C_CPP_DECL __VB_C_CPP_LB (
#define AS ), __VB_C_CPP_AS_M, (

#define __VB_C_CPP_CAST(exp, ...) ((__VB_C_CPP_DECL(, __VA_ARGS__, __VB_C_CPP_CAST_M)) exp)
#define CAST(...) __VB_C_CPP_CAST((__VA_ARGS__))

#define DEFINE_LATER extern
#define GLOBAL_PRIVATE static
#define LOCAL_DEFINE_ONCE static

#define ARRAY ), __VB_C_CPP_ARRAY_M __VB_C_CPP_RB
#define ZERO_ARRAY {0}
#define REST_ALL_ZEROS


#define AS_FUNC 

#define __VB_C_CPP_FUNCTION_BODY__VB_C_CPP_START_M(body, _) { __VB_C_CPP_ARGS body }
#define __VB_C_CPP_FUNCTION_BODY__VB_C_CPP_END_M(_) ;
#define __VB_C_CPP_FUNCTION__(decl, has_body, ...) __VB_C_CPP_ARGS decl __VB_C_CPP_FUNCTION_BODY##has_body (__VA_ARGS__)
#define __VB_C_CPP_FUNCTION_(...) __VB_C_CPP_FUNCTION__(__VA_ARGS__)
#define __VB_C_CPP_FUNCTION(name, __, args, ...) __VB_C_CPP_FUNCTION_(__VB_C_CPP_DECL0((__VB_C_CPP_ARGS name __VB_C_CPP_ARGS args), __VA_ARGS__))
#define FUNCTION __VB_C_CPP_FUNCTION __VB_C_CPP_LB (
#define OF ), __VB_C_CPP_OF_M, (
#define RETURN return


#define __VB_C_CPP_TYPEDEF(name, ...) typedef __VB_C_CPP_DECL(name, __VA_ARGS__)
#define TYPEDEF __VB_C_CPP_TYPEDEF __VB_C_CPP_LB (
#define TYPE ;

#define __VB_C_CPP_STRUCT__VB_C_CPP_START_M(name, body, _) typedef struct __VB_C_CPP_ARGS name __VB_C_CPP_ARGS name; struct __VB_C_CPP_ARGS name { __VB_C_CPP_ARGS body };
#define __VB_C_CPP_STRUCT__VB_C_CPP_END_M(name, _) typedef struct __VB_C_CPP_ARGS name __VB_C_CPP_ARGS name;
#define __VB_C_CPP_STRUCT(name, mark, ...) __VB_C_CPP_STRUCT##mark(name, __VA_ARGS__)
#define STRUCT __VB_C_CPP_STRUCT __VB_C_CPP_LB (

#define __VB_C_CPP_ENUM__VB_C_CPP_START_M(name, body, _) typedef enum __VB_C_CPP_ARGS name __VB_C_CPP_ARGS name; enum __VB_C_CPP_ARGS name { __VB_C_CPP_ARGS body };
#define __VB_C_CPP_ENUM__VB_C_CPP_END_M(name, __) typedef enum __VB_C_CPP_ARGS name __VB_C_CPP_ARGS name; 
#define __VB_C_CPP_ENUM(name, mark, ...) __VB_C_CPP_ENUM##mark(name, __VA_ARGS__)
#define ENUM __VB_C_CPP_ENUM __VB_C_CPP_LB (


#define START ), __VB_C_CPP_START_M, (
#define END ), __VB_C_CPP_END_M __VB_C_CPP_RB


#endif // VB_H

