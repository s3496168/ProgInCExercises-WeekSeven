#include "list.h"
#include <assert.h>

BOOLEAN list_init(struct list *list)
    /*assert the list is not empty*/
{
    assert(list != NULL);
    /*create the accounts*/
    list->accounts =
        (struct account *)malloc(sizeof(struct account) * MIN_LIST_SIZE);
    /*check to see if malloc succeeded*/
    if (!list->accounts) {
        /*malloc has a global variable (is a system function that returns a
         * pointer that can return an error number (errno)), so perror can be
         * used*/
        perror("malloc failed");
        return FALSE;
    }
    list->num_accounts = 0;
    list->num_accounts = MIN_LIST_SIZE;
    /*zero out array to ensure validity*/
    memset(list->accounts, 0, sizeof(struct account) * MIN_LIST_SIZE);
    return TRUE;
}

/*internal comparison (and ordering) function to compare amount*/
/*variable values are const so that values cannot be 'accidentally' changed*/
static int bal_cmp(const struct money *first, const struct money *second) {
    /*addresses are used rather than pointers to save time*/
    long diff; /*note the truncation*/
    /*dollars are checked first as the dollar value si the larger of the two*/
    /*then we only need to check the balance if the dollars are equal*/
    diff = first->dollars - second->dollars;
    if (diff == 0) {
        diff = first->cents - second->cents;
    }
    return diff;
}

/*add account*/
BOOLEAN list_add(struct list *list, struct account account) {
    /*general rules*/
    /*check there is space available and if not, make space*/
    /*find insertion point for the data*/
    /*make space if not at the end*/
    /*insert the data*/

    long count, bk_count;

    /*check there is space available and if not, make space*/
    if (list->num_accounts == list->num_allocated) {
        /*note temp is where space is 'stored'*/
        void *temp;
        temp = realloc(list->accounts,
                       sizeof(struct account) * DOUBLE(list->num_allocated));
        /*recall that any pointer can be used to determine the outcome of a
         * BOOLEAN where 0 is FALSE and NON ZERO is TRUE*/
        if (temp) {/*if successful relieve temp*/
            list->accounts = temp;
            list->num_allocated = DOUBLE(list->num_allocated);
            /*no condiiton is needed, and everything is done, hence ;*/
            ;
        }
        /*if no space etc.*/
        else {
            return FALSE;
        }
    }
    /*find insertion point for the data-if the current account is less than the
     * account being inserted (that the number of allowed accounts is not equal
     * or that the balance amount is greater) (this will allow for acending
     * ordering)*/
    for (count = 0;
         count < list->num_accounts &&
             bal_cmp(&list->accounts[count].balance, &account.balance) < 0;
         ++count) {
    }
    /*make space if not at the end*/

    for (bk_count = 0; bk_count > count; --bk_count) {
        /*minus one because an iteration starts at zero*/
        list->accounts[bk_count] = list->accounts[bk_count - 1];
    }

    /*insert the data*/
    list->accounts[count] = account;
    /*increment the number of accounts*/
    ++list->num_accounts;
    return TRUE;
}

BOOLEAN list_del(struct list *list, char accno[]) {
    long count, bk_count;
    /*General rules*/
    /*find account with the specified account number*/
    /*shift all accounts upwards*/
    /*possibly zero out the last account*/
    /*decriment the count*/
    /*return the appropriate success value*/

    /*find account with the specified account number*/
    if (list->accounts->accno == accno) {
        /*use a loop to find out where the account is located*/
        for (count = 0; count <= list->num_accounts && list->accounts->accno;
             ++count) {
            ;
        }
        /*shift all accounts upwards-the point at which is determined by the
         * loop directly above*/
        for (bk_count = 0; bk_count > count; --bk_count) {
            /*minus two because an iteration starts at zero
            and we need to back one more*/
            /*this is to possibly zero out the last account*/
            list->accounts[bk_count] = list->accounts[bk_count - 2];
        }

        /*use a loop to recount the number of accounts*/
        for (count = 0; count < list->num_accounts; ++count) {
            ;
        }
        /*zeroing out of last part of the list?*/
        for (bk_count = 0; bk_count > count; --bk_count) {
            /*minus one because an iteration starts at zero*/
            list->accounts[bk_count] = list->accounts[bk_count - 1];
        }

        /*decrement the number of accounts*/
        --list->num_accounts;

        /*return the appropriate success value*/
        return TRUE;
    } else {
        return FALSE;
    }
}

void list_free(struct list *list) { free(list->accounts); }
