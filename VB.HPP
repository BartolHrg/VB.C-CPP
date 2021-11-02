#ifndef VB_HPP
#define VB_HPP

#include "VB.H"

#undef __VB_C_CPP_STRUCT
#undef __VB_C_CPP_STRUCT_CONST
#undef STRUCT
#undef STRUCT_CONST
#undef START_STRUCT
#undef END_STRUCT
#define __VB_C_CPP_STRUCT(name, body) struct __VB_C_CPP_ARGS name __VB_C_CPP_ARGS body;
#define STRUCT struct
#define START_STRUCT {
#define END_STRUCT };

#undef __VB_C_CPP_ENUM
#undef ENUM
#undef START_ENUM
#undef END_ENUM
#define __VB_C_CPP_ENUM(name, body) enum class __VB_C_CPP_ARGS name __VB_C_CPP_ARGS body;
#define ENUM enum class
#define START_ENUM {
#define END_ENUM };
    
#define CLASS class 
#define START_CLASS {
#define END_CLASS };

#define NAMESPACE namespace
#define START_NAMESPACE {
#define END_NAMESPACE }

#define __VB_C_CPP_FOR_EACH(element, type, array, body) for (__VB_C_CPP_ARGS type element : __VB_C_CPP_ARGS array) __VB_C_CPP_ARGS body
#define FOR_EACH __VB_C_CPP_FOR_EACH __VB_C_CPP_LB __VB_C_CPP_ARGS __VB_C_CPP_LB
#define IN ), (
#define START_FOR_EACH ), ({
#define END_FOR_EACH }) __VB_C_CPP_RB

#define TRY try {
#define CATCH } catch (DECL
#define DO_THIS END) {
#define CATCH_ALL } catch (...) {
#define END_TRY }
#define THROW throw

#define TEMPLATE template
#define TYPENAME typename

#define USING using

#define PRIVATE private
#define PUBLIC public
#define PROTECTED protected

#define STATIC static

#define FRIEND friend

#define OPERATOR operator 

#define DEFAULT default

#endif // VB_HPP
