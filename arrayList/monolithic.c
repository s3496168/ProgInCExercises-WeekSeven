/* Monolithic example of implementing an ordered list using an array */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define LISTSIZE 10
#define LINELEN 80
#define EXTRACHARS 2

typedef enum {
    FALSE,
    TRUE
} BOOLEAN;
BOOLEAN get_int(int*);

int main() {
    int intList[LISTSIZE];
    unsigned listSize;
    int i, anInt;
    listSize = 0;
    while (get_int(&anInt)) {
        if (listSize >= LISTSIZE) {
            fprintf(stderr,
                    "\nListInsert failed!"
                    "Aborting data entry!");
            break;
        }
        i = listSize;
        while (i > 0 && anInt < intList[i - 1]) {
            intList[i] = intList[i - 1];
            i--;
        }
        intList[i] = anInt;
        listSize++;
    }
    for (i = 0; i < (int)listSize; i++) {
        printf("%d\n", intList[i]);
    }
    return EXIT_SUCCESS;
}

BOOLEAN get_int(int* data) {
    int result;
    char line[LINELEN + EXTRACHARS];
    char* end;

    if (fgets(line, LINELEN + EXTRACHARS, stdin) == NULL || *line == '\n') {
        return FALSE;
    }
    if (line[strlen(line) - 1] != '\n') {
        fprintf(stderr,
                "Error: line was too long. "
                "Please try again.\n\n");
        return get_int(data);
    }
    line[strlen(line) - 1] = 0;
    result = (int)strtol(line, &end, 0);
    if (*end) {
        fprintf(stderr,
                "Error: data entered was not numeric. "
                "Please try again.\n\n");
        return get_int(data);
    }
    *data = result;
    return TRUE;
}
