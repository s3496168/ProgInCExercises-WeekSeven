#include "account.h"

static char *mystrdup(const char str[]) {
    char *newstr = malloc((strlen(str) + 1) * sizeof(char));
    if (!newstr) {
        return NULL;
    }
    strcpy(newstr, str);
    return newstr;
}
static BOOLEAN get_balance(const char balstr[], struct money *balance) {
    char *token;
    char *balcpy = mystrdup(balstr);
    char *endptr;
    long testnum;
    token = strtok(balcpy, ".");
    if (!token) {
        fprintf(stderr,
                "Error: %s is not a valid "
                "currency.\n\n",
                balstr);
        free(balcpy);
        return FALSE;
    }
    testnum = strtol(token, &endptr, 10);
    if (*endptr) {
        fprintf(stderr,
                "Error: %s is not valid "
                "currency.\n\n",
                balstr);
        free(balcpy);
        return FALSE;
    }
    if (testnum > UINT_MAX) {
        fprintf(stderr,
                "Error: %s is not valid "
                "currency.\n\n",
                balstr);
        free(balcpy);
    }
    balance->dollars = testnum;
    token = strtok(NULL, ".");
    if (!token) {
        fprintf(stderr,
                "Error: %s is not a valid "
                "currency.\n\n",
                balstr);
        free(balcpy);
        return FALSE;
    }
    testnum = strtol(token, &endptr, 10);
    if (*endptr) {
        fprintf(stderr,
                "Error: %s is not valid "
                "currency.\n\n",
                balstr);
        free(balcpy);
        return FALSE;
    }
    if (testnum > MAXCENTS) {
        fprintf(stderr,
                "Error: %s is not valid "
                "currency.\n\n",
                balstr);
        free(balcpy);
        return FALSE;
    }
    token = strtok(NULL, ".");
    if (token) {
        fprintf(stderr,
                "Error: %s is not valid "
                "currency.\n\n",
                balstr);
        free(balcpy);
        return FALSE;
    }
    free(balcpy);
    return TRUE;
}

BOOLEAN read_account(struct account *account) {
    char line[LINELEN + EXTRACHARS];
    struct money balance;
    if (get_string("Please enter the customer name: ", line, NAMELEN) == RTM) {
        return FALSE;
    }
    strcpy(account->custname, line);
    if (get_string(
            "Please enter the customer "
            "account number: ",
            line, ACCNOLEN) == RTM) {
        return FALSE;
    }
    strcpy(account->accno, line);
    if (get_string("Please enter the customer balance in AUD and in format $dd.cc: $", line, LINELEN) ==
        RTM) {
        return FALSE;
    }
    if (!get_balance(line, &balance)) {
        fprintf(stderr,
                "Error: %s does not "
                "contain valid currency.\n\n",
                line);
        return FALSE;
    }
    account->balance = balance;
    return TRUE;
}

BOOLEAN del_account(struct account *account) {
    char line[LINELEN + EXTRACHARS];

    if (get_string(
            "Please enter the account number of the account to be removed: ",
            line, ACCNOLEN) == RTM) {
        return FALSE;
    }

    return TRUE;
}

enum choice display_menu(void) {
    char *heading;
    int strlen_heading;
    int count;
    /*enum input_result get_string(const char prompt[], char output[],
            size_t len) helpers.h*/
    /*variables for menu processing*/
    char line[LINELEN + EXTRACHARS];

    enum input_result result;

    /*display menu*/
    char *menu_list[] = {"Add an account", "Delete an account"};
    /*line for spacing*/
    printf("\n");
    
    /*heading*/
    heading = "ACME Accounts System";
    /*get the heading count for the loop below*/
    strlen_heading = strlen(heading);

    puts(heading);
    
    /*loop for headng characters*/
    for (count = 0; count < strlen_heading; ++count) {
        printf("%s", "-");
    }
    printf("\n");

    /*menu display*/

    for (count = 0; count < CHOICES; ++count) {
        printf("%d) %s\n", count + 1, menu_list[count]);
    }
    /*end display menu*/
    printf("Please make a selection: ");
        result=get_choice(line, CHOICES);
    return result;
}
