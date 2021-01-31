/* intArrayList.c */
#include "arrayList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void ListMake(struct int_list* list) {
     int i;
    /* assuming that list is a valid pointer */
    assert(list != NULL);
   
   
    /* Nothing much to be done here for this particular
     * implementation of a list. Merely setting the
     * ''size'' member of the struct int_list object to 0 would
     * suffice.
     *
     * This interface routine exists because it is
     * anticipated that other implementations of a
     * list may need to do some initialisation before
     * the list can be manipulated.
     *
     */
    i =0;
  
    list->size =i;
}

BOOLEAN ListInsert(struct int_list* list, int num) {
    /* any required local vars go here */
    int i;
    int anInt;

    assert(list != NULL);
    anInt = 0;
    /* if the list is already full then indicate
     * insertion failure with a return value
     *
     * Check to see how this function was used in
     * main() to determine what value to return
     * for a FAILURE
     */
    if (list->size >= LISTSIZE) {
        fprintf(stderr,
                "\nListInsert failed!"
                "Aborting data entry!");
        return FALSE;
    }
    i = list->size;

    /*
     * Here you'll need to write some code to
     * search for the correct place within the
     * array to insert the new element.
     * Finally return a value indicating SUCCESS
     *
     */
    while (i > 0 && anInt < num) {
        list->list[i] = list->list[i - 1];
        i--;
    }

    list->list[i] = anInt;
    list->size++;
    /* dummy return value until you implement the function - it won't
     * generate a warning that way
     */
    return TRUE;
}
void ListDisplay(struct int_list* pil) {
    /* any required local vars go here */
    int i;
    assert(pil != NULL);
    /* loop through all existing elements within
     * the array and display them one per line
     */
    /*note here that the unsigned s changed to int
    to match the other data types*/
    for (i = 0; i < (int)pil->size; i++) {
        printf("%d\n", pil->list[i]);
    }
}
void ListFree(struct int_list* pil) {
    int i;
    assert(pil != NULL);
    
    
    /* Nothing much to be done here for this particular
     * implementation of a list. Merely setting the
     * size attribute to 0 would suffice
     */
    i=0;
    pil->size =i;

}
