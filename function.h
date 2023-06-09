#ifndef HEADER_FUNCTION
#define HEADER_FUNCTION 1

// déclaration des constantes
#define true 1
#define false 0
#define TEXT_SPEED 40

// déclaration des bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// fonction sleep pour Linux
#if defined(__linux__) || defined(__gnu_linux__)
#if _POSIX_C_SOURCE >= 199309L
#include <time.h> // nanosleep
#else
#include <unistd.h> // usleep
#endif
#endif

// déclaration des fonctions
void display_step_file(const char *step, int clear);
void display_step_string(const char *string);
char *choice2(char *step1, char *choice1, char *step2, char *choice2);
char *choice3(char *step1, char *choice1, char *step2, char *choice2, char *step3, char *choice3);
void confirm();
void empty_stdin_buffer();
void clear_console();
void game_sleep(long long ms);

#endif