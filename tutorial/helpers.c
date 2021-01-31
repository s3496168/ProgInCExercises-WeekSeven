#include "helpers.h"
enum input_result get_string(const char prompt[], char output[], size_t len) {
    printf(prompt);

    if (!fgets(output, len + EXTRACHARS, stdin) || *output == '\n') {
        return RTM;
    }
    if (output[strlen(output) - 1] != '\n') {
        fprintf(stderr,
                "Error: line was too long. Please "
                "try again.\n");
        return FALSE;
    }
    output[strlen(output) - 1] = 0;
    return TRUE;
}

enum input_result get_choice(char output[], size_t len) {
    int input;
    enum input_result result;
    BOOLEAN success = FALSE;

    /*ptr value to be set by strtol*/
    char *ptr;
    /*reset input value so that incoming input is unaffected by previous input*/
    output[strlen(output) - 1] = 0;
    do{
    fgets(output, len + EXTRACHARS, stdin);
    
    printf("Output is: %s \n", output);
    printf("HellO\n");
  
    if (output[strlen(output) - 1] != '\n') {
        fprintf(stderr,
                "Error: line was too long. Please "
                "try again.\n");
        return FALSE;
    }
    success = TRUE;
    }while(success==FALSE);
    output[strlen(output) - 1] = 0;

 
    input = strtol(output, &ptr, DECIMALINT);
   
    /*ensure the input is a number*/
    if (*ptr != '\0') {
        fprintf(stderr, "Error: the input is not numeric.\n");
        return QUIT;
    }

    /*error handling for numbers that are too small*/
    if (input < TOOSMALL) {
        fprintf(stderr,
                "Error: %d is smaller than the boundary. Please enter a number "
                "between %d and %d. \n",
                input, MIN_NUM_MENU_CHOICES, NUM_MENU_CHOICES);
        return INVALID;
    }

    /*error handling for numbers that are too big*/
    else if (input > NUM_MENU_CHOICES) {
        fprintf(stderr,
                "Error: %d is larger than the boundary. Please enter a number "
                "between %d and %d. \n",
                input, MIN_NUM_MENU_CHOICES, NUM_MENU_CHOICES);
        return INVALID;
    } else {
        /*subtract one due to the enum*/
        
        input--;
        result = input;
        
        
    }
    return result;
}
