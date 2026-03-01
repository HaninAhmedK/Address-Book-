#include<stdio.h>
#include<stdbool.h>
#include"address_book.h"



int main() {
    int input;
    

    while(true) {
        printf("\n1. Add a contact\n");
        printf("2. Delete a contact\n");
        printf("3. Search for contact\n");
        printf("4. Update a contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit the app\n");
        scanf("%d", &input);

        bool exit = false;
        switch (input)
        {
        case 1:
            addContact();
            break;
        
        case 2:
            deleteContact();
            break;

        case 3:
            searchContact();
            break;

        case 4:
            updateContact();
            break;

        case 5:
            listAll();
            break;

        case 6:
            printf("Exiting the program ......\n");
            exit = true;
            break;
        default:
            printf("Invalid input!\n");
            break;
        }

        if(exit){
            return 0;
        }
        
    }
}