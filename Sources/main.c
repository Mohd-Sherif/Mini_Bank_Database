#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/bank database.h"

customer_t customer[MAX];
int index=0;

int main()
{
    char choice;
    while(1){
        printf("\
               **********Welcome**********\n\n\n\
               Select Operation:-\n\n\
               1-Add a new customer.\n\
               2-Edit customer.\n\
               3-Delete customer.\n\
               4-Print customer's data.\n\
               5-Transfer money from customer to another.\n\
               6-Exit.\n\
               Your choice:");
        fflush(stdin);
        scanf("%i",&choice);
        switch(choice){
        case 1:
            if(index==MAX){
                printf("Sorry, there is no space for the new customer.");
            }
            add();
            index++;
        case 2:
            edit();
        case 3:
            delete_data();
            index--;
        case 4:
            print();
        case 5:
            transfer();
        case 6:
            return 0;
        default:
            printf("Wrong choice.\n");
        }
    }
}
