#include "account_list.h"
#include "helpers.h"
#include <assert.h>

/*We need CRUD*/

/*C=Create*/
/*R=Read*/
/*U=Update*/
/*D=Delete*/

int main(void) {
    /*enum input_result another_result;*/
    BOOLEAN quit = FALSE;
    enum choice choices;

    struct account account;
    struct list list;
    list_init(&list);
    do {
        choices = display_menu();
        switch (choices) {
            case ADD: {
                printf("The add function has been reached. \n");
                
                while (read_account(&account)) {
                    list_add(&list, account);
                }
                break;
            }
            case DELETE: {
                printf("The delete function has been reached. \n");
                
                while (del_account(&account)) {

                    list_del(&list, account.accno);
                }
                break;
            }
            case QUIT: {
                fprintf(stdout, "Bye \n");
                quit = TRUE;
                break;
            }
            default: {
                assert(choices == INVALID);
                fprintf(stderr, "Sorry, your choice is invalid\n");
            }
        }
        printf("\n");
    } while (quit == FALSE);

    return EXIT_SUCCESS;
}
