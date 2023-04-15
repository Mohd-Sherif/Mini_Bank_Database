#ifndef BANK_DATABASE_H_INCLUDED
#define BANK_DATABASE_H_INCLUDED
#define MAX 3

typedef struct customer{
    int id;
    char name[50];
    float cash;
    char acc_type[7];
}customer_t;

void add();
void edit();
void delete_data();
void print();
void transfer();

#endif // BANK_DATABASE_H_INCLUDED
