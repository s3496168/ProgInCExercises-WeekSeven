#include <string.h>
#include <stdio.h>
#include "bool.h"
#include "helpers.h"
#include <limits.h>
#ifndef ACCOUNT_H
#define ACCOUNT_H
#define NAMELEN 20
#define ACCNOLEN 10
#define MAXCENTS 99
#define CHOICES 2
struct money
{
        unsigned dollars;
        unsigned cents;
};

struct account
{
        char custname[NAMELEN + 1];
        char accno[ACCNOLEN + 1];
        struct money balance;
};

BOOLEAN read_account(struct account *);

BOOLEAN del_account(struct account *);

enum choice display_menu(void);
#endif
