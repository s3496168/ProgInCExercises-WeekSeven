/* ArrayList.h */
#include "bool.h"
#define LISTSIZE 32
struct int_list
{
  int list[LISTSIZE];
  unsigned size;
};
void ListMake(struct int_list *);
BOOLEAN ListInsert(struct int_list *, int);
void ListDisplay(struct int_list *);
void ListFree(struct int_list *);
