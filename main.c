#include "function.h"
//#define S1 "Step_0.txt"

int main(){
    char * file = NULL; 
    
    printf("\n");
    display_step("Step_0.txt", true);
    printf("\n");
    printf("\n");

    display_step("Step_1.txt", true);
    printf("\n");
    printf("\n");

    file = choice2("Step_2.txt", "Choice_2.txt", "Step_3.txt", "Choice_3.txt");

    
    return 0;
} 

/* 
cd S2/Projet/Histoire
gcc main.c function.c -o CYdventure.exe
.\CYdventure.exe
*/