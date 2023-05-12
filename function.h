#ifndef HEADER_FUNCTION
#define HEADER_FUNCTION 1

#define true 1
#define false 0
#define TEXT_SPEED 40

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void display_step_file(const char *step, int clear);
void display_step_string(const char *string);
int number_char(const char *step);
char *choice2(char *step1, char *choice1, char *step2, char *choice2);
char *choice3(char *step1, char *choice1, char *step2, char *choice2, char *step3, char *choice3);

#endif