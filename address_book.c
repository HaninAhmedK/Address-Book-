#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#include"address_book.h"

#define MAX_CONTACT 100

Contact contactBook[MAX_CONTACT];     // In-memory database

void saveToFile(Contact contactBook[], int contactCount){
    
    FILE *fptr;
    fptr = fopen("addressbook.csv", "w");
    
    for(int i=0; i<contactCount; i++) {
        fprintf(fptr, "%s,%s,%s\n", contactBook[i].name,contactBook[i].phoneNumber,contactBook[i].email);
    }

    fclose(fptr);
}

int loadToArray() {                // Returns the count of contacts in the file
    FILE *fptr;
    fptr = fopen("addressbook.csv", "r");

    if(fptr == NULL) {
        return 0;
    }

    int count = 0;
    while(fscanf(fptr, "%[^,],%[^,],%[^\n]\n",
        contactBook[count].name,
        contactBook[count].phoneNumber,
        contactBook[count].email) != EOF) {
            count++;

    }

    fclose(fptr);

    return count;
}

//------------------------ Add Function-------------------------
//--------------------------------------------------------------
void addContact() {
    Contact contact;

    printf("enter the name:\n");
    scanf(" %[^\n]", contact.name);
    printf("Enter the phone number: \n");
    scanf(" %[^\n]", contact.phoneNumber);
    printf("enter the email address: \n");
    scanf(" %[^\n]", contact.email);

    int contactCount = loadToArray();
    if(contactCount == MAX_CONTACT) {
        printf("Contact Book is full !\n");
        return;
    }

    contactBook[contactCount] = contact;
    contactCount++;

    saveToFile(contactBook, contactCount);

    printf("Contact added successfully\n");
}

//-------------------------------Delete Function---------------------------
//-------------------------------------------------------------------------
void deleteContact(){
    char name[30];
    char phoneNumber[10];
    char email[30];
    int option;
    bool found = false;

    printf("Delete by  by \n1. Name\n2. Phone number\n3. email \n");
    scanf("%d", &option);

    int contactCount = loadToArray();

    if(contactCount == 0) {
        printf("Address book is empty !");
        return;
    }

    if(option == 1) {
        printf("Enter the name: \n");
        scanf(" %[^\n]", name);

        for(int i=0; i<contactCount; i++) {
            if(strcmp(contactBook[i].name, name) == 0) {
                found = true;
                while(i < contactCount) {
                    contactBook[i] = contactBook[i+1];
                    i++;
                }
                contactCount--;
                break;
            }
        }
        if(!found){
            printf("Contact does not exist !");
            return;
        }

    }else if(option == 2) {
        printf("Enter the phone number: \n");
        scanf(" %[^\n]", phoneNumber);

        for(int i=0; i<contactCount; i++) {
            if(strcmp(contactBook[i].phoneNumber, phoneNumber) == 0) {
                found = true;
                while(i < contactCount) {
                    contactBook[i] = contactBook[i+1];
                    i++;
                }
                contactCount--;
                break;
            }
        }
        if(!found){
            printf("Contact does not exist !");
            return;
        }

    }else {
        printf("Enter the email: \n");
        scanf(" %[^\n]", email);

        for(int i=0; i<contactCount; i++) {
            if(strcmp(contactBook[i].email, email) == 0) {
                found = true;
                while(i < contactCount) {
                    contactBook[i] = contactBook[i+1];
                    i++;
                }
                contactCount--;
                break;
            }
        }
        if(!found){
            printf("Contact does not exist !");
            return;
        }
    }

    saveToFile(contactBook, contactCount);
    printf("Contact deleted succesfully ");
}

//----------------------------Search Function-----------------------------
//------------------------------------------------------------------------
void searchContact() {
    char name[30];
    char phoneNumber[10];
    char email[30];
    int option;
    bool found = false;

    printf("Search by \n1. Name\n2. Phone number\n3. email \n");
    scanf("%d", &option);

    int contactCount = loadToArray();

    if(option == 1){
        printf("Enter the name: \n");
        scanf(" %[^\n]", name);

        for(int i=0; i<contactCount; i++){
            if(strcmp(contactBook[i].name, name) == 0) {
                found = true;
                printf("----------------------------\n");
                printf("Name: %s \nphone number: %s \nemail: %s\n", contactBook[i].name,
                     contactBook[i].phoneNumber, contactBook[i].email);
                printf("----------------------------\n");
                break;     
            }
        }

        if(!found) {
            printf("Contact not found !");
        }

    }else if(option == 2) {
        printf("Enter the phone number: \n");
        scanf(" %[^\n]", phoneNumber);

        for(int i=0; i<contactCount; i++){
            if(strcmp(contactBook[i].phoneNumber, phoneNumber) == 0) {
                found = true;
                printf("----------------------------\n");
                printf("Name: %s \nphone number: %s \nemail: %s\n", contactBook[i].name,
                     contactBook[i].phoneNumber, contactBook[i].email);
                printf("----------------------------\n");
                break;     
            }
        }

        if(!found) {
            printf("Contact not found !");
        }

    }else {
        printf("Enter the email: \n");
        scanf(" %[^\n]", email);

        for(int i=0; i<contactCount; i++){
            if(strcmp(contactBook[i].email, email) == 0) {
                found = true;
                printf("----------------------------\n");
                printf("Name: %s \nphone number: %s \nemail: %s\n", contactBook[i].name,
                     contactBook[i].phoneNumber, contactBook[i].email);
                printf("----------------------------\n");
                break;     
            }
        }

        if(!found) {
            printf("Contact not found !");
        }
    }

    
}


//--------------------------Update Function----------------------------
//--------------------------------------------------------------------
void updateContact() {
    char name[30];
    char phoneNumber[10];
    char email[30];
    int option;
    bool found = false;

    printf("Enter the name: \n");
    scanf(" %[^\n]", name);

    int contactCount = loadToArray();

    for(int i=0; i<contactCount; i++){
        if(strcmp(contactBook[i].name, name) == 0) {
            found = true;
            printf("Do you want to change phone number: \n 1. if Yes\n 2. if No\n");
            scanf("%d", &option);
            if(option == 1){
                printf("Enter phone number: \n");
                scanf(" %[^\n]", phoneNumber);
                strcpy(contactBook[i].phoneNumber, phoneNumber);

                printf("Do you want to change email: \n1. if yes\n2. if No\n");
                scanf("%d", &option);
                if(option == 1) {
                    printf("Enter email address: \n");
                    scanf(" %[^\n]", email);
                    strcpy(contactBook[i].email, email);
                    break;
                }else{
                    break;
                }
            }else{
                printf("Do you want to change email: \n1. if yes\n2. if No\n");
                scanf("%d", &option);
                if(option == 1) {
                    printf("Enter email address: \n");
                    scanf(" %[^\n]", email);
                    strcpy(contactBook[i].email, email);
                    break;
                }else{
                    break;
                }
            }
               
        }
    }

    if(!found) {
        printf("Contact not found !");
        return;
    }

    saveToFile(contactBook, contactCount);
    printf("Contact updated succesfully\n");
}

void listAll() {
    int contactCount = loadToArray();
    if(contactCount == 0) {
        printf("Address book is empty !");
        return;
    }

    printf("---------------------------------------\n");
    for(int i=0; i<contactCount; i++) {
        printf("Name: %s, Phone number: %s, Email: %s\n", contactBook[i].name,
                 contactBook[i].phoneNumber, contactBook[i].email);
    }
    printf("---------------------------------------\n");
}