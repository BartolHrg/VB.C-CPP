#include <iostream>

typedef int F(void);



typedef int (*FP)(void);

TYPEDEF FUNCTION_POINTER( FP OF (void) ) AS int END



typedef int A[5];

char g(void) {
    return 'a';
}

FP p = (FP) g;

A ma = {0, 2, 21};

int main() {
    std::cout << ma[2] << p();
}