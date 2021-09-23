#define IF if (
#define THEN ) {
#define ELSEIF } else if (
#define ELSE } else {
#define ENDIF }

#define DO do {
#define ALLTHEWHILE } while (
#define ENDDO );

#define WHILE while (
#define DOTHIS ) {
#define ENDWHILE }

#define FOR for (
#define ENDFOR }

#define SCOPE {
#define ENDSCOPE }

#define AS ,
#define OF ,

#define ___DECLARE(var, type) type var
#define DECLARE(var_AS_type) ___DECLARE(var_AS_type)

#define ___CAST(exp, type) ((type) (exp))
#define CAST(expression_AS_type) ___CAST(expression_AS_type)

#define ___FUNCTION(name, args, type) ___DECLARE(name args, type)
#define FUNCTION(name_OF_args_AS_type) ___FUNCTION(name_OF_args_AS_type)
#define STARTFUNCTION {
#define ENDFUNCTION }

#define ___FUNCTION_POINTER(name, args) (*name) args
#define FUNCTION_POINTER(name_OF_args) ___FUNCTION_POINTER(name_OF_args)

#define STRUCT(name) typedef struct name name; struct name {
#define ENDSTRUCT };

