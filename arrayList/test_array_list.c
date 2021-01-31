/* Sample application using a list (of integers) module */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#define LINELEN 80
#define EXTRASPACES 2
BOOLEAN get_int(int*);

int main(void)
{
    struct int_list il;
    int an_int;

    ListMake(&il);
    /* reuse the get_int function implemented above */
    while(get_int(&an_int))
    {
        if (!ListInsert(&il, an_int))
        {
            fprintf(stderr,"\nListInsert failed!"
                    "Aborting data entry!");
            break;
        }
    }
    ListDisplay(&il);
    ListFree(&il);
    return EXIT_SUCCESS;
}

BOOLEAN get_int(int* data)
{
    int result;
    char line[LINELEN + EXTRASPACES];
    char * end;

    if(fgets(line, LINELEN + EXTRASPACES, stdin) == NULL ||
            *line=='\n')
    {
        return FALSE;
    }
    if(line[strlen(line)-1]!='\n')
    {
        fprintf(stderr, "Error: line was too long. "
                "Please try again.\n\n");
        return get_int(data);
    }
    line[strlen(line)-1]=0;
    result = (int)strtol(line, &end, 0);
    if(*end)
    {
        fprintf(stderr, "Error: data entered was not numeric. "
                "Please try again.\n\n");
        return get_int(data);
    }
    *data = result;
    return TRUE;
}


