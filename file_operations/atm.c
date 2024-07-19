#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//initialize a file pointer.
FILE* creden_pointer;

//A structure to holds the account's cridentials 
struct account
    {
        char name[100];
        char acc_no[100];
        char password[100];
        int balance;
        int check;
    };

//A pointer to hold hold the memory location of the node.
struct account *initial_account;

void memory_allocation()
    {
        static struct account *new_account;

        new_account = (struct account*)malloc(sizeof(struct account));
        initial_account = new_account;
    }

//Define global variables.
char name1[100], name2[100], acc_no1[100], password4[100], password3[100],  account_number[100], Acc_no[100];
int balance1, flag=0;


//Fuction to ensure the required credentials are loaded to memory
void Check()
        {
            if(strcmp(name1, name2) == 0)
                {
                    flag = 5;
                }
        }


//fuction to read from the file and store the contents in a node.
void file_read()
    {
        int i;
        char line[300], temp[50];
        struct account *new_account = initial_account;

        if(flag == 1)
            {
                new_account = (struct account*)malloc(sizeof(struct account));

            }

        //This section is only used by the login fuction 
        if(flag == 1)
            {
                if((creden_pointer = fopen("creden.txt", "r")) == NULL)
                    {
                        printf("There is no registered account yet!!.\n");
                        flag = 9;//This is to enable the login function to know there file does not exist yet.
                        return;
                    }
                else 
                    {
                        fclose(creden_pointer);
                    }
            }

        //This section is general for both fuctions is open or creates the file creden.txt
        creden_pointer = fopen("creden.txt", "r");

        //This section is only used by the Acc_no fuction this is ensured by sent the global flag --> 4 n the fuction before the call
        if(flag == 4)
            {
                if(creden_pointer == NULL)
                    {
                        perror("\tFile does not exist\n\tLets fix this for you .... \n");
                        new_account -> check = 2;//This can be checkd by functions to show that the file does not exit;
                        return;
                    }
                 else 
                    {
                
                        new_account -> check = 0;

                    }
            }

        while( fgets(line, 300, creden_pointer) != NULL)
            {
                i = 0;

                char *ptr = strtok(line, "=#~`");
                strncpy(new_account -> name, ptr, 99);
                //This section should only execute only for login fuction.
                if(flag == 1)
                    {
                        strncpy(name2, new_account -> name, strlen(new_account -> name));
                    }
                while(1)
                   {
                        ptr = strtok(NULL, "=#~`");

                        if (ptr == NULL ) break;
                        i++;
                        if(i == 1)
                            {
                             strncpy(new_account -> acc_no, ptr, 99);
                            }
                        else if ( i == 2)
                            {
                                strncpy(new_account -> password, ptr, 99);
                            }
                        else if ( i == 3)
                            {
                                strncpy(temp, ptr, 49);
                                new_account -> balance = atoi(temp);
                            }
                    }
            
            //This section only executed by the login function.
            if(flag == 1)
                {  
                    Check();
                    //This section will used to check where the enter account is found.
                    if(flag == 5) 
                        { 
                            strncpy(password4, new_account -> password, 99);     
                            strncpy(Acc_no, new_account -> acc_no, 99);

                            return;
                        }
                }


            }
        
        fclose(creden_pointer);
//This will enable the login fuction know that the user name that was entered can not be found in the file.
        if(flag == 1)
            {

                flag = 3;
            }
    }

//function to save the struct's content into a file.
void save()
    {
        creden_pointer = fopen("creden.txt", "a");

        fprintf(creden_pointer, "%s=#~`%s=#~`%s=#~`%d\n", name1, acc_no1, password4, balance1);

        fclose(creden_pointer);
    }

//fuction to create account numbers for created accounts.
static void Acc_number()
    { 
        int i;
        char *ptr;
        struct account *new_account = initial_account;
        char str1[100], str2[100] = "ACC 00", str3[100];
        flag = 4;//this will be used in the file_read() fuction.
        file_read();
        if(new_account -> check == 2)
            {
                i = 1;
            }
        else 
            {
                strncpy(str3, new_account -> acc_no, 99);
                ptr = strtok(str3, " ");
                ptr = strtok(NULL, " ");
                strncpy(str3, ptr, 99);
                i = atoi(str3);
                i = i + 1;    
            }
        sprintf(str1, "%d", i);
        strncat(str2, str1, 100 - strlen(str2) - 1);
        strncpy(account_number, str2, 99);
        

    }

//function to read the users password.
void Read_password()
    {
        char password1[100], password2[100];
        printf("\t\tEnter your password\n\t\tPassword : ");
        fgets(password1, sizeof(password1), stdin);
        password1[strcspn(password1, "\n")]='\0';
        printf("Confirm Your Password\nPassword : ");
        fgets(password2, sizeof(password2), stdin); 
        password2[strcspn(password2, "\n")]='\0';
        if(strcmp(password1, password2) != 0)
            {
                printf("\t\tPassword Did Not match!!\n\t\tTry Again ");
                Read_password();
            }
        else 
            {
                if(strlen(password1) < 8 )
                    {
                        printf("\t\tYour password is very weak\n\t\tPlease try again\nPassword must have a minimum of 8 characters");
                        Read_password();
                    }
                else 
                    {
                        strncpy(password3, password1, 99);
                    }
            }
    }

/*This here is the create account function. It will read from the file to beable to create the  next new account number.
It will also read the other user credentials and using the dave function it will save all the creadentials to a file.*/
void create_acc()
    {
        static struct account *new_account;

        new_account = (struct account*)malloc(sizeof(struct account));
        initial_account = new_account;//creating the node that wil hold the user credentials.

        Acc_number();//Fuction to create tyhe new account number.
        strncpy(new_account -> acc_no, account_number, 99);

        printf("\t\tEnter Your FUll Official Names\n\t\tName : ");
        fgets(new_account -> name, sizeof(new_account -> name), stdin);
        new_account -> name[strcspn(new_account -> name, "\n")]='\0';        

        Read_password();
        strncpy(new_account -> password, password3, 99);

        new_account -> balance = 0;

        strncpy(name1,new_account -> name, strlen(new_account -> name));
        strncpy(acc_no1,new_account -> acc_no, strlen(new_account -> acc_no));
        strncpy(password4,new_account -> password, strlen(new_account -> password));
        balance1 = new_account -> balance;
        save();

        new_account -> check = 0;
    }

int Input()
    {
        printf("\n\t\tPlease Enter your choice here\n\t\tChoice : ");
        char read[100];
        fgets(read, sizeof(read), stdin);
        int i = strlen(read);
        if(i < 1 || i > 2)
            {
                printf("\n\t\tYou Entered a non-existing choice!!\n\t\tPlease try again\n");
                return Input();
            }

        int check = atoi(read);

        switch(check)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                    return check;
                default:
                    printf("\tYou Entered a non-existing choice!!\n\tPlease try again\n");
                    return Input();

            }
    }

//Fuction prototyping;
void login();

int main()
    {
       int choice;

        //Display the first menu to the user.
        printf("\tWhat would you like to do?\n");
        printf("\t\t1. Create an account\n");
        printf("\t\t2. Login to you acccount\n");
        
        //Take the user's choice.
        choice = Input();
        if(choice > 2 )
            {
                printf("\t\tYou Entered a non-existing choice!!\n\t\tPlease try again\n");
                choice = Input();
            }

        switch(choice)
            {
                case 1: 
                    create_acc();
                    printf("Account Creation was a success.\n");
                    break;
                
                case 2: 
                    login();
                    break;
            }
        
        return 0;
    }




//The login fuction
void login()
    {
        char names[100], password[100];

        printf("\tEnter your full name\n\tNames : ");
        fgets(names, sizeof(names), stdin);
        names[strcspn(names, "\n")]='\0';
        strncpy(name1, names, strlen(names));
        flag =1;
        file_read();

         if(flag == 3 || flag == 9)
                {
                    printf("\tYour Account was not found\n\tPlease create an account first\n");
                    return;
                } 

        printf("\tPlease Enter your password\n\tPassword : ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")]='\0';

        if(strcmp(password, password3) == 0)
            {
                printf("Welcome %s", name1);
            }


    }
