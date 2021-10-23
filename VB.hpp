#ifndef VB_HPP
#define VB_HPP

#include "VB.h"

#undef __VB_C_CPP_STRUCT
#undef __VB_C_CPP_STRUCT_CONST
#undef STRUCT
#undef STRUCT_CONST
#undef START_STRUCT
#undef END_STRUCT
#define STRUCT struct
#define START_STRUCT {
#define END_STRUCT };

#undef __VB_C_CPP_ENUM
#undef ENUM
#undef START_ENUM
#undef END_ENUM
#define ENUM enum class
#define START_ENUM {
#define END_ENUM };
    
#define CLASS class 
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
