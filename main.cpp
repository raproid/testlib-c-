#include <stdio.h>
#include "mathfuncs.h"

using namespace std;

int main() {

    double a = 4.5;
    int b = 234;

    int addition = mathfuncs::simplemathfuncs::add(a,b);
    
    printf("a + b = %d\n", addition);

printf("WTF are you looking at?\n");
printf("You asked for an example - here it is.\n");
return 0;

}