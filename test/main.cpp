#include "../VB.hpp"

#include <iostream>

VB_C_CPP_FILE(
    
USING NAMESPACE std;

NAMESPACE my_own 
START_NAMESPACE
    
    TEMPLATE < TYPENAME A, TYPENAME B >
    STRUCT Pair 
    START_STRUCT
        DECL first AS A END;
        DECL second AS B END;
    END_STRUCT
    
    TEMPLATE <TYPENAME T>
    CLASS LinkedList
    START_CLASS
        PRIVATE:
            DECL head AS void* END;
            STATIC FUNCTION createFromArray OF (DECL size AS int END, DECL arr AS T* END) AS LinkedList<T>* 
            START_FUNCTION
                RETURN nullptr;
            END_FUNCTION
        PROTECTED:
        PUBLIC:
            //FRIEND FUNCTION ...
            FUNCTION OPERATOR << OF (DECL item AS T END) AS bool 
            START_FUNCTION
                RETURN true;
            END_FUNCTION
    END_CLASS
 
END_NAMESPACE

FUNCTION main OF () AS int 
START_FUNCTION
    my_own::LinkedList<int> llhaha;
    cout << (llhaha << 9);
END_FUNCTION

)