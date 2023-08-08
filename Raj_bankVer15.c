// What to do in this ver15:
// Removing adhr from check_bal(),Transaction() and exist_acc() because this are from Mainmenu 2 and Mainmenu2 will only open when someone login.So adhr is not required again and again .
// Making new Funtion for update documents.

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>

// For text color.
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"
const char *format_specifier = "%lld %s %s %d/%d/%d %s %s %lld %ld %s\n";

// Gloabal variable  can be use in any function.
char respect[10];
void for_delay(int);
void welcome();
void EXIT();
void failed(void (*funtion)());
void login(void (*function)());
void new_acc();
void update_doc();
void check_bal();
void Transactions();
void exist_acc();
void already_acc();
void view_list();
void About_us();
void Mainmenu2();
void Mainmenu1();

struct dob
{
    int date, month, year;
};

struct costumers
{
    long long int adhr_no;
    char name[30];
    char last_name[30];
    struct dob DOB;
    int age;
    char gender[10];
    char citizenship[12];
    long long int phone;
    long int amt;
    char password[20];
} add, check, transaction, preview, update, recheck;

// functions..
void for_delay(int j)
{
    // I use this function to create delay like I did for exit and at Rbi starting .
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}

void welcome()
{
    {
        system("cls");
        printf(ANSI_COLOR_CYAN "\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tWelcome to Raj bank of India.\n");
        printf("\t\t\t\t\t\t\t\t\t\t      Fast and secure bank in India. 24/7 service.\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     *******************************\n");
        printf(ANSI_COLOR_MAGENTA "\n");
        printf(" \t\t\t\t\t\t\t\t\t\t                   RRRRR   BBBB   IIIII\n");
        printf(" \t\t\t\t\t\t\t\t\t\t                   R   R   B   B    I  \n");
        printf(" \t\t\t\t\t\t\t\t\t\t                   RRRRR   BBBB     I  \n");
        printf(" \t\t\t\t\t\t\t\t\t\t                   R R     B   B    I  \n");
        printf(" \t\t\t\t\t\t\t\t\t\t                   R   R   BBBB   IIIII\n");
        ANSI_COLOR_RESET;
        printf(ANSI_COLOR_CYAN "\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     *******************************\n");
        ANSI_COLOR_RESET;
        printf(ANSI_COLOR_YELLOW "");
        printf("\t\t                                                                             ");
        char name[34] = "<---Owned By:Lakshyaraj Purbia--->";
        for (int l = 0; l <= 33; l++)
        {
            printf("%c", name[l]);
            for_delay(20000000);
        }
        ANSI_COLOR_RESET;
        printf(ANSI_COLOR_CYAN "\n");
        printf("\nPress Enter....\n");
        while (getchar() != '\n')
        {
            // Wait for the user to press Enter
        }
    }
}

void EXIT()
{
    printf("\t\t\t\t\t\t\t\t\t\t               .\n");
    printf("\t\t\t\t\t\t\t\t\t\t              / \\\n");
    printf("\t\t\t\t\t\t\t\t\t\t             /   \\\n");
    printf("\t\t\t\t\t\t\t\t\t\t            /     \\\n");
    printf("\t\t\t\t\t\t\t\t\t\t ==============================\n");
    printf("\t\t\t\t                                                 |  ");
    char thanks[28] = " Thank You For Visiting   |\n";
    for (int i = 0; i <= 27; i++)
    {
        printf("%c", thanks[i]);
        for_delay(20000000);
    }
    printf("\t\t\t\t\t\t\t\t\t\t ==============================\n");
    Sleep(1000);
    exit(12);
}

void failed(void (*funtion)())
{
    int tell;
    printf("\nWrong Password.");
wrong_choice:
    printf("\nEnter 0 to Retry, 1 to main menu and 2 to exit.");
    printf("\nEnter your choice %s:", respect);
    scanf("%d", &tell);
    if (tell == 0)
        funtion();
    else if (tell == 1)
        Mainmenu2();
    else if (tell == 2)
        EXIT();
    else
    {
        printf("\nWrong choice.");
        goto wrong_choice;
    }
}

void login(void (*function)())
{
    while (1)
    {
        printf("\nEnter password to confirm: ");
        scanf("%s", check.password);
        if (strcmp(check.password, add.password) == 0)
        {
            printf("\nAccess granted.");
            break;
        }
        else
        {
            int tell;
            printf("\nAccess denied.");
        wrong_choice:
            printf("\nEnter 0 to Retry, 1 to main menu and 2 to exit.");
            printf("\nEnter your choice %s:", respect);
            scanf("%d", &tell);
            if (tell == 0)
                function();
            else if (tell == 1)
                Mainmenu1();
            else if (tell == 2)
                EXIT();
            else
            {
                printf("\nWrong choice.");
                goto wrong_choice;
            }
        }
    }
}

void new_acc()
{
    system("cls");
    printf("\n*Carefully Fill your details.");
    printf("\n*You can change your details(if you want to),after creating a account.");
    printf("\n\n_____________________________________________");
    printf("\nFill your details to create your account.");
    FILE *New_account;
    New_account = fopen("Raj_bankdata.txt", "a+");
    if (New_account == NULL)
    {
        printf("\nNo Records Available.");
    }
    printf("\nEnter Your Adhar Card Number:->");
    scanf("%lld", &check.adhr_no);
    while (fscanf(New_account, format_specifier, &add.adhr_no, &add.name, &add.last_name, &add.DOB.date, &add.DOB.month, &add.DOB.year, &add.gender, &add.citizenship, &add.phone, &add.amt, &add.password) != EOF)
    {
        if (add.adhr_no == check.adhr_no)
        adhrmatchagain:
        {
            int adhrmatch;
            printf("\nAccount Number already in use.");
            printf("\n1.Retry.\n2.Login.\n\nEnter your choice:-->");
            scanf("%d", &adhrmatch);
            if (adhrmatch == 1)
            {
                new_acc();
            }
            else if (adhrmatch == 2)
            {
                already_acc();
            }
            else
            {
                goto adhrmatchagain;
            }
        }
    }
    add.adhr_no = check.adhr_no;
    printf("\nEnter your First name please: ");
    scanf("%s", &add.name);
    printf("\nEnter your Surname please: ");
    scanf("%s", &add.last_name);
    printf("\nEnter your Date of birth please(dd mm yyyy,give space): ");
    scanf("%2d %2d %4d", &add.DOB.date, &add.DOB.month, &add.DOB.year);
    getchar();
gendeR:
    printf("\nEnter your gender: ");
    scanf("%s", &add.gender);
    if (strcmp(add.gender, "male") == 0 || strcmp(add.gender, "m") == 0)
    {
        strcpy(add.gender, "Male");
        strcpy(respect, "Sir");
    }
    else if (strcmp(add.gender, "female") == 0 || strcmp(add.gender, "f") == 0)
    {
        strcpy(add.gender, "Female");
        strcpy(respect, "Mam");
    }
    else
    {
        printf("\nWrite again carefully.");
        goto gendeR;
    }
    printf("\nEnter your Country:");
    scanf("%s", &add.citizenship);
    printf("\nEnter your Phone no.:+91 ");
    scanf("%lld", &add.phone);
re:
    printf("\nDo you want to deposit money?");
    char asking[5];
    printf("-->");
    scanf("%s", &asking);
    if (strcmp(asking, "yes") == 0 || strcmp(asking, "y") == 0)
    {
        printf("\nEnter amount to deposit=");
        scanf("%ld", &add.amt);
    }
    else if (strcmp(asking, "no") == 0 || strcmp(asking, "n") == 0)
    {
        add.amt = 0;
    }
    else
    {
        goto re;
    }
    printf("\nHello  %s %s.\n", add.name, add.last_name);
    printf("Create new password For your account: ");
    scanf("%s", &add.password);
    printf("Password created.");
    fprintf(New_account, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
    fclose(New_account);
    printf("\n\nYour account has been created successfully.\n");
    printf("_____________________________________________");
}

void update_doc()
{
    int flag = 0;
    FILE *updatef, *newupdatef;
    updatef = fopen("Raj_bankdata.txt", "r");
    newupdatef = fopen("newRaj_bankdata.txt", "w");
    printf("\n*FOR CONFIRMATION*");
    printf("\nEnter Your Password to upadte your Documents.\n:->");
    scanf("%s", &recheck.password);
    getchar();
    while (fscanf(updatef, format_specifier, &add.adhr_no, &add.name, &add.last_name, &add.DOB.date, &add.DOB.month, &add.DOB.year, &add.gender, &add.citizenship, &add.phone, &add.amt, &add.password) != EOF)
    {
        int yourchoice;
        if (strcmp(add.password, recheck.password) == 0)
        {
            flag = 1;
        upperswitch:
            printf("\nWhat Do you want to update ?");
            printf("\n1.Full Name\n2.DOB\n3.Citizenship\n4.Phone Number\n5.Password.");
            printf("\nEnter your Choice:-");
            scanf("%d", &yourchoice);
            switch (yourchoice)
            {
            case 1:
                printf("\nEnter your New First Name = ");
                scanf("%s", &update.name);
                printf("\nEnter your New Surname Name = ");
                scanf("%s", &update.last_name);
                getchar();
                strcpy(add.name, update.name);
                strcpy(add.last_name, update.last_name);
                fprintf(newupdatef, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
                printf("\nName changed.");
                sleep(2);
                system("cls");
                break;
            case 2:
                printf("\nEnter your New Date of Birth(give space) =");
                scanf("%2d %2d %4d", &update.DOB.date, &update.DOB.month, &update.DOB.year);
                add.DOB.date = update.DOB.date, add.DOB.month = update.DOB.month, add.DOB.year = update.DOB.year;
                fprintf(newupdatef, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
                printf("\nDOB changed.");
                sleep(2);
                system("cls");
                break;
            case 3:
                printf("\nEnter your New citizenship = ");
                scanf("%s", &update.citizenship);
                strcpy(add.citizenship, update.citizenship);
                fprintf(newupdatef, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
                printf("\nCitizenship changed.");
                sleep(2);
                system("cls");
                break;
            case 4:
                printf("\nEnter your New Phone Number = ");
                scanf("%lld", &update.phone);
                add.phone = update.phone;
                fprintf(newupdatef, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
                printf("\nPhone Number changed.");
                sleep(2);
                system("cls");
                break;
            case 5:
            changepas:
                printf("\nEnter old password = ");
                scanf("%s", &check.password);
                if (strcmp(add.password, check.password) == 0)
                {
                    printf("\nEnter New Password = ");
                    scanf("%s", &update.password);
                    strcpy(add.password, update.password);
                    fprintf(newupdatef, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
                    printf("\nPassword changed.");
                }
                else
                elseagain:
                {
                    int incorrectpass;
                    printf("\nOld Password is incorrect.");
                    printf("\nEnter 0 to Retry , 1 to Mainmenu");
                    printf("\n:-->");
                    scanf("%d", &incorrectpass);
                    if (incorrectpass == 0)
                        goto changepas;
                    else if (incorrectpass == 1)
                        Mainmenu2();
                    else
                    {
                        goto elseagain;
                    }
                }
                    sleep(2);
                system("cls");
                break;

            default:
                printf("\n*Wrong Choice.Try Again*.\n");
                goto upperswitch;
                break;
            }
        }
        else
        {
            fprintf(newupdatef, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
        }
    }
    fclose(updatef);
    fclose(newupdatef);
    remove("Raj_bankdata.txt");
    rename("newRaj_bankdata.txt", "Raj_bankdata.txt");
    if (flag != 1)
    {
        failed(update_doc);
    }
}

void check_bal()
{
    system("cls");
    int flag = 0;
    printf("\n_____________________________________________");
    FILE *check_amt;
    check_amt = fopen("Raj_bankdata.txt", "r");
    if (check_amt == NULL)
    {
        printf("\nNo Records Available.");
    }
    printf("\n*FOR CONFIRMATION*");
    printf("\nEnter Your Password to check your balance\n:->");
    scanf("%s", &check.password);
    while (fscanf(check_amt, format_specifier, &add.adhr_no, &add.name, &add.last_name, &add.DOB.date, &add.DOB.month, &add.DOB.year, &add.gender, &add.citizenship, &add.phone, &add.amt, &add.password) != EOF)
    {
        if (strcmp(add.password, check.password) == 0)
        {
        check_baL:
            printf("\n_______________________________");
            printf("\nDetails-->");
            printf("\nName:- %s %s", add.name, add.last_name);
            printf("\nAdhar Number:-%lld", add.adhr_no);
            printf("\nYour current balance is Rs.%ld", add.amt);
            printf("\n_______________________________");
            printf("\n_____________________________________________");
            flag = 1;
            break;
        }
    }
    fclose(check_amt);
    if (flag != 1)
    {
        failed(check_bal);
    }
    getchar();
    printf("\nPress Enter to continue....\n");
    while (getchar() != '\n')
    {
    }
    system("cls");
}

void Transactions()
{
    system("cls");
    int flag = 0;
    FILE *trans, *newtrans;
    trans = fopen("Raj_bankdata.txt", "r");
    if (trans == NULL)
    {
        printf("\nNo Records Available.\n ");
    }
    newtrans = fopen("newRaj_bankdata.txt", "w");
    printf("\n________________________________________________________________");
    printf("\n*FOR CONFIRMATION*");
    printf("\nEnter your Password for Transations\n:- ");
    scanf("%s", &transaction.password);
    while (fscanf(trans, format_specifier, &add.adhr_no, &add.name, &add.last_name, &add.DOB.date, &add.DOB.month, &add.DOB.year, &add.gender, &add.citizenship, &add.phone, &add.amt, &add.password) != EOF)
    {
        if (strcmp(add.password, transaction.password) == 0)
        {
            flag = 1;
            printf("\n_______________________________");
            getchar();
            printf("\nDetails-->");
            printf("\nName:- %s %s", add.name, add.last_name);
            printf("\nAdhar Number:-%lld", add.adhr_no);
            printf("\nYour current balance is Rs.%ld", add.amt);
            printf("\n_______________________________");
            printf("\nDo you want to \n1.Deposit Money\n2.Withdraw Money");
            printf("\n:-");
            int choice;
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\nHow much money do you want to deposit in your account %s:", respect);
                scanf("%ld", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newtrans, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
                printf("\nTransaction Done.");
            }
            else if (choice == 2)
            {
                printf("\nHow much money do you want to Withdraw in your account %s:", respect);
                scanf("%ld", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newtrans, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
                printf("\nTransaction Done.");
            }
            else
            {
                printf("\nInvalid choice ,");
            }
            printf("\n________________________________________________________________");
        }
        else
        {
            fprintf(newtrans, format_specifier, add.adhr_no, add.name, add.last_name, add.DOB.date, add.DOB.month, add.DOB.year, add.gender, add.citizenship, add.phone, add.amt, add.password);
        }
    }
    fclose(trans);
    fclose(newtrans);
    remove("Raj_bankdata.txt");
    rename("newRaj_bankdata.txt", "Raj_bankdata.txt");
    if (flag != 1)
    {
        failed(Transactions);
    }
    getchar();
    printf("\nPress Enter to continue....\n");
    while (getchar() != '\n')
    {
    }
    system("cls");
}

void exist_acc()
{
    system("cls");
    int flag = 0;
    FILE *exist;
    exist = fopen("Raj_bankdata.txt", "r");
    if (exist == NULL)
    {
        printf("\n No Records Available.\n");
    }
    printf("\n*FOR CONFIRMATION*");
    printf("\nEnter your Password to check your Profile\n:- ");
    scanf("%s", &check.password);
    while (fscanf(exist, format_specifier, &add.adhr_no, &add.name, &add.last_name, &add.DOB.date, &add.DOB.month, &add.DOB.year, &add.gender, &add.citizenship, &add.phone, &add.amt, &add.password) != EOF)
    {
        if (strcmp(add.password, check.password) == 0)
        {
            printf("\n_______________________________");
            printf("\nAdhar Card Number:-> %lld", add.adhr_no);
            printf("\nName:-> %s", add.name);
            printf("\nSurname:-> %s", add.last_name);
            printf("\nDate of birth:-> %d/%d/%d", add.DOB.date, add.DOB.month, add.DOB.year);
            printf("\nGender:-> %s", add.gender);
            printf("\nCitizenship:-> %s", add.citizenship);
            printf("\nPhone no.:-> %lld", add.phone);
            printf("\nYour current account Balance :-> Rs.%ld", add.amt);
            printf("\nYour password :-> %s", add.password);
            printf("\n_______________________________");
            flag = 1;
        }
    }
    fclose(exist);
    if (flag != 1)
    {
        failed(exist_acc);
    }
    getchar();
    printf("\nPress Enter to continue....\n");
    while (getchar() != '\n')
    {
    }
    system("cls");
}

void already_acc()
{
    system("cls");
    int flag = 0;
    printf("\n___________________________________________________________");
    FILE *loginF;
    loginF = fopen("Raj_bankdata.txt", "r");
    if (loginF == NULL)
    {
        printf("\nNo Records Available.");
    }
    printf("\nEnter Your Adhar Number to check your Records:->");
    scanf("%lld", &check.adhr_no);
    while (fscanf(loginF, format_specifier, &add.adhr_no, &add.name, &add.last_name, &add.DOB.date, &add.DOB.month, &add.DOB.year, &add.gender, &add.citizenship, &add.phone, &add.amt, &add.password) != EOF)
    {
        if (add.adhr_no == check.adhr_no)
        {
        check_baL:
            flag = 1;
            printf("\nRecords Found.");
            login(already_acc);
            printf("\n_______________________________");
            printf("\nDetails-->");
            printf("\nName:- %s %s", add.name, add.last_name);
            printf("\nAdhar Number:-%lld", add.adhr_no);
            strcpy(preview.name, add.name);
            strcpy(preview.last_name, add.last_name);
            printf("\n_______________________________");
            getchar();
            printf("\nPress Enter to continue:-->");
            while (getchar() != '\n')
            {
            }
            printf("\n___________________________________________________________");
            break;
        }
    }
    fclose(loginF);
    if (flag != 1)
    {
        failed(already_acc);
    }
    Mainmenu2();
}

void view_list()
{
    system("cls");
    printf("\n_____________________________________________________________________________________________________");
    FILE *view;
    view = fopen("Raj_bankdata.txt", "r");
    if (view == NULL)
    {
        printf("\nNo Records Available.\n");
    }
    printf("\nThese are the customers.. ");
    ANSI_COLOR_RESET;
    printf(ANSI_COLOR_MAGENTA);
    printf("\n\nFirstName\t\t\t\bLastName\t\t\t\t\b\bGender\t\tCitizenship");
    ANSI_COLOR_RESET;
    printf(ANSI_COLOR_CYAN);
    while (fscanf(view, format_specifier, &add.adhr_no, &add.name, &add.last_name, &add.DOB.date, &add.DOB.month, &add.DOB.year, &add.gender, &add.citizenship, &add.phone, &add.amt, &add.password) != EOF)
    {
        printf("\n%-30s %-30s %-10s %15s \n", add.name, add.last_name, add.gender, add.citizenship);
    }
    fclose(view);
    ANSI_COLOR_RESET;
    printf(ANSI_COLOR_GREEN "\n");
    printf("\n_____________________________________________________________________________________________________");
    ANSI_COLOR_RESET;
}

void About_us()
{
    printf("\nWrok will start soon.");
}
// personal Mainmenu
void Mainmenu2()
{
    system("cls");
    int choices;
    do
    {
        printf(ANSI_COLOR_YELLOW "\n\n\t\t\t\t\t\t\t\t\t\t   <-----------MAIN MENU----------->\n" ANSI_COLOR_RESET "\n");
    CHOICE:
        printf("\n\t\t    - - - - - - - - - - - - - - - - - -  ");
        printf(ANSI_COLOR_CYAN "\n\t\t\tName:  %s %s" ANSI_COLOR_RESET, preview.name, preview.last_name);
        printf("\n\t\t    - - - - - - - - - - - - - - - - - -  ");
        printf(ANSI_COLOR_RED "\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |1.Check Documents.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |2.Update Documents.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |3.CHECK BALANCE.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |4.Transactions.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |5.Previous MainMenu.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |6.CLOSE BANKING.\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t    |->Enter your choice=");
        scanf("%d", &choices);
        ANSI_COLOR_RESET;
        printf(ANSI_COLOR_GREEN "\n");
        switch (choices)
        {
        case 1:
            exist_acc();
            break;
        case 2:
            update_doc();
            break;
        case 3:
            check_bal();
            break;
        case 4:
            Transactions();
            break;
        case 5:
            Mainmenu1();
            break;
        case 6:
            EXIT();
            break;
        }
    } while (choices != 5);
}

void Mainmenu1()
{
    system("cls");
    int choices;
    do
    {
        printf(ANSI_COLOR_YELLOW "\n\n\t\t\t\t\t\t\t\t\t\t   <-----------MAIN MENU----------->\n" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_RED "\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |1.CREATE A NEW ACCOUNT.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |2.Already have a account! Login.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |3.View Costumer list.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |4.About Us.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t    |5.CLOSE BANKING.\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t    |->Enter your choice=");
        scanf("%d", &choices);
        ANSI_COLOR_RESET;
        printf(ANSI_COLOR_GREEN "\n");

        switch (choices)
        {
        case 1:
            new_acc();
            break;
        case 2:
            already_acc();
            break;
        case 3:
            view_list();
            break;
        case 4:
            About_us();
            break;
        case 5:
            EXIT();
            break;
        }
    } while (choices != 5);
}

int main()
{
    welcome();
    Mainmenu1();
    return 0;
}
