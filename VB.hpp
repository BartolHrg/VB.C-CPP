#ifndef VB_HPP
#define VB_HPP

#include "VB.h"

#undef __VB_C_CPP_STRUCT
#define __VB_C_CPP_STRUCT(name, body) struct name body;
#undef __VB_C_CPP_STRUCT_CONST
#define __VB_C_CPP_STRUCT_CONST(name, body) const struct name

#undef __VB_C_CPP_ENUM
#define __VB_C_CPP_ENUM(name, body) enum class name 
    
#define CLASS(name) class name 
#define CLASS_CONST(name) const class name
#define START_CLASS {
#define END_CLASS };

#define NAMESPACE namespace
#define START_NAMESPACE {
#define END_NAMESPACE }

#define USING using

#define TRY try {
#define CATCH } catch (DECL
#define DO_THIS END) {
#define CATCH_ALL } catch (...) {
#define END_TRY }
#define THROW throw

#define TEMPLATE template
#define TYPENAME typename

#define PRIVATE private
#define PUBLIC public
#define PROTECTED protected

#define FRIEND friend

#define STATIC static

#define OPERATOR operator 

#define DEFAULT default

#endif // VB_HPP
