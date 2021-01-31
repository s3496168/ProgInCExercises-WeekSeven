#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "account.h"
#include "bool.h"
#ifndef LIST_H
/*forwards declaration for pointers*/
struct list;
/*list definition*/
struct list{
    struct account * accounts;
    long num_accounts;
    /*useful to know to determine the need for memory reallocation*/
    long num_allocated;
};

#define LIST_H
#define MIN_LIST_SIZE 10
#define DOUBLE(X) ((X)*(X))

/*prototypes*/
BOOLEAN list_init(struct list * list);
BOOLEAN list_add(struct list * list, struct account account);
BOOLEAN list_del(struct list * list, char accno[]);
void list_free(struct list * list);
/*end prototypes*/

#endif
