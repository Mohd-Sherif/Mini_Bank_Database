#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/bank database.h"

extern customer_t customer[MAX];
extern int index;

void add(){
    L2:
    printf("New customer's id:");
    fflush(stdin);
    scanf("%i",&customer[index].id);
    if(customer[index].id<=0){
        printf("Invalid value!\n");
        goto L2;
    }
    else {
        int i;
        for(i=0;i<MAX-1;i++){
            if((customer[index].id==customer[i].id)&&(index!=i)){
                printf("Error!\nThis id isn't available.\n");
                goto L2;
            }
        }
    }
    printf("New customer's name:");
    fflush(stdin);
    gets(&customer[index].name);
    L3:
    printf("New customer's cash:");
    fflush(stdin);
    scanf("%f",&customer[index].cash);
    if(customer[index].cash<=0){
        printf("Invalid value!\n");
        goto L3;
    }
    L4:
    printf("New customer's account type <debit/credit>:");
    fflush(stdin);
    scanf("%s",&customer[index].acc_type);
    if((strcmp(customer[index].acc_type,"debit")!=0)&&(strcmp(customer[index].acc_type,"credit")!=0)){
        printf("Invalid choice!\n");
        goto L4;
    }
}
