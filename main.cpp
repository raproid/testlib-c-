#include <stdio.h>
#include "mathfuncs.h"

using namespace std;

int main() {

    double a = 4.5;
    int b = 234;

    int addition = mathfuncs::simplemathfuncs::add(a,b);

    int subtraction = mathfuncs::simplemathfuncs::subtract(a,b);

    int multiplication = mathfuncs::simplemathfuncs::multiply(a,b);

    int division = mathfuncs::simplemathfuncs::divide(a,b);
    
    printf("a + b = %d\n", addition);
    
    printf("a - b = %d\n",subtraction);

    printf("a * b = %d\n", multiplication);

    printf("a / b = %d\n", division);


printf("An example program using a lib with math functions.\n");
return 0;

}