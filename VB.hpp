#ifndef VB_HPP
#define VB_HPP

#include "VB.h"

#undef STRUCT
#define STRUCT(name) struct name 

#undef ENUM
#define ENUM(name) enum name 
    
#define CLASS(name) class name 
#define STARTCLASS {
#define ENDCLASS };

#define NAMESPACE namespace
#define STARTNAMESPACE {
#define ENDNAMESPACE }

#define USING using

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
