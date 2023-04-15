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

void edit(){
    int temp,i;
    char flag=0;
    L5:
    printf("Customer's id:");
    fflush(stdin);
    scanf("%i",&temp);
    for(i=0;i<=MAX-1;i++){
        if(temp==customer[i].id){
            temp=i;
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Error!\nThere's no any customer with this id.\n");
        goto L5;
    }
    else {
        printf("Customer's new id:");
        fflush(stdin);
        scanf("%i",&customer[temp].id);
    }
    printf("Customer's new name:");
    fflush(stdin);
    gets(&customer[temp].name);
    L6:
    printf("Customer's new cash value:");
    fflush(stdin);
    scanf("%f",&customer[temp].cash);
    if(customer[temp].cash<=0){
        printf("Invalid value!\n");
        goto L6;
    }
    L7:
    printf("Customer's new account type <debit/credit>:");
    fflush(stdin);
    scanf("%s",&customer[temp].acc_type);
    if((strcmp(customer[temp].acc_type,"debit")!=0)&&(strcmp(customer[temp].acc_type,"credit")!=0)){
        printf("Invalid choice!\n");
        goto L7;
    }
}

void delete_data(){
    int temp,i;
    char flag=0;
    L8:
    printf("Customer's id:");
    fflush(stdin);
    scanf("%i",&temp);
    if(temp<=0){
        printf("Invalid value!\n");
        goto L8;
    }
    for(i=0;i<=MAX-1;i++){
        if(temp==customer[i].id){
            temp=i;
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Error!\nThere's no customer with this id.\n");
        goto L8;
    }
    else {
        customer[temp].id=-1;
        strcpy(customer[temp].name,"-1");
        customer[temp].cash=-1;
        strcpy(customer[temp].acc_type,"-1");
    }
}
