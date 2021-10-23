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
#define STARTCLASS {
#define ENDCLASS };

#define NAMESPACE namespace
#define STARTNAMESPACE {
#define ENDNAMESPACE }

#define USING using

#define TRY try {
#define CATCH } catch (
#define CATCHALL } catch (...
#define ENDTRY }
#define THROW throw
#define DOTHIS ) {

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
