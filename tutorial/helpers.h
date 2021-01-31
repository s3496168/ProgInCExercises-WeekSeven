#include "bool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef HELPERS_H
#define HELPERS_H
#define LINELEN 80
#define EXTRACHARS 2
#define DECIMALINT 10
#define TOOSMALL -2
#define MIN_NUM_MENU_CHOICES 1
#define NUM_MENU_CHOICES 3

enum input_result {
    FAILURE,
    SUCCESS,
    RTM
};

/*enum for menu*/
enum choice {
    ADD,
    DELETE,
    QUIT,
    INVALID = -1
};
/*end enum for menu*/

enum input_result get_string(const char[], char[], size_t);
enum input_result get_choice( char[], size_t);
#endif
