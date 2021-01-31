#include <stdio.h>
#include <stdlib.h>

#define NAMELEN 7
#define ACCNOLEN 14

struct money{unsigned dollars;
unsigned cents;};
struct account{char custname[NAMELEN + 1];
char accno[ACCNOLEN + 1];struct money balance;};

int main(){
    /*We need CRUD*/

    /*C=Create*/
    /*R=Read*/
    /*U=Update*/
    /*D=Delete*/
    return EXIT_SUCCESS;
}