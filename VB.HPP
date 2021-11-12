#ifndef VB_HPP
#define VB_HPP

#include "VB.H"

#undef __VB_C_CPP_STRUCT
#define __VB_C_CPP_STRUCT(name, __, body, _) struct __VB_C_CPP_ARGS name { __VB_C_CPP_ARGS body };

#undef __VB_C_CPP_ENUM
#define __VB_C_CPP_ENUM(name, __, body, _) enum class __VB_C_CPP_ARGS name { __VB_C_CPP_ARGS body };
    
#define __VB_C_CPP_CLASS(name, __, body, _) class __VB_C_CPP_ARGS name { __VB_C_CPP_ARGS body };
#define CLASS __VB_C_CPP_CLASS __VB_C_CPP_LB (


#define __VB_C_CPP_CONTAINING(body, _) { __VB_C_CPP_ARGS body };
#define NAMESPACE namespace
#define CONTAINING __VB_C_CPP_CONTAINING __VB_C_CPP_LB (

#define __VB_C_CPP_FOR_EACH(element, type, array, __, body, _) for (__VB_C_CPP_ARGS type __VB_C_CPP_ARGS element : __VB_C_CPP_ARGS array) { __VB_C_CPP_ARGS body }
#define FOR_EACH __VB_C_CPP_FOR_EACH __VB_C_CPP_LB (
#define IN ), (


#define __VB_C_CPP_TRY(body, _) try { __VB_C_CPP_ARGS body }
#define TRY __VB_C_CPP_TRY __VB_C_CPP_LB (
#define CATCH } catch (DECL
#define DO_THIS END) {
#define CATCH_ALL } catch (...) {
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
