#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

typedef struct 
{
    char name[30];
    char phoneNumber[10];
    char email[30];

}Contact;

void saveToFile(Contact contactBook[], int contactCount);

int loadToArray();

void addContact();

void deleteContact();

void searchContact();

void updateContact();

void listAll();

#endif