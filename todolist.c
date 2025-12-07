#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void viewList(char buffer[100],int size, FILE *list);

int main(){

    FILE *list = fopen("hi.txt","r+");
    char buffer[100] ={0};
    int choice = 0;
    do {
        printf("| todo list in c >.< |\n\n(1): View list\n(2): Remove item\n(3): add item\n(0) Exit\n\nChoice: ");
        scanf("%d",&choice);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if (choice == 0){
            break;
        }
        else if (choice == 1)
        {
            list = fopen("hi.txt","r");
            viewList(buffer,sizeof(buffer),list);
            printf("\n");
            fclose(list);
            system("pause");
        }
        else if (choice == 2){
            list = fopen("hi.txt","r");
            char what[100] = {0};
            char templist[1028] = {0};
            printf("What do you want to remove (eg. Johnny)\n");
            fgets(what,sizeof(what),stdin);
            what[strcspn(what,"\n")] = 0;     
            rewind(list); 
            int f = 0;
            while (fgets(buffer,sizeof(buffer),list)){
                buffer[strcspn(buffer,"\n")] = 0;
                if (strcmp(buffer,what) != 0){
                    strcat(templist,buffer);
                    strcat(templist,"\n");
                }
                else {
                    f = 1;
                }
            }
                fclose(list);
                if (f){
                list = fopen("hi.txt","w");
                fputs(templist,list);
                fclose(list);
                }
            }
        else if (choice == 3){
            list = fopen("hi.txt","a");
            char add[100] = {0};
            printf("what do you wanna add: ");
            fgets(add,sizeof(add),stdin);
            fputs(add,list);
            fclose(list);

        }
            
    } while (choice != 0);

    return 0;
}

void viewList(char buffer[],int size, FILE *list){
    rewind(list);
    while (fgets(buffer,size,list)){
        printf("%s",buffer);
    }
}