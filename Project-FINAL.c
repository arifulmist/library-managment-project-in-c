/*

                           MD ARIFUL ISLAM
                    STUDENT OF CSE IN MIST
                         1ST YEAR PROJECT


*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void password();
void password1();
void password2();
void heading();
void STDmenu1();
void ADDmenu2();
void choice();
void addbooks();
void booksList();
void booksearch();
void Reqbooks();
void issuebooks();
void issueList();
void stdrList();
void LoginList();
int globalcount=0;
struct student
{
    int id[50];
    char name[100];
    char dept[5];
    char date[12];
} std;

int d=1;
struct books
{
    int id[50];
    char name[50];
    char author[50];
    char date[12];

} b;
FILE*fp;
FILE*ft;
FILE*fi;
FILE*fl;
int main()
{
    password();
}
void LoginList()
{
    system("cls");
    printf("\t\t\t\t\t\t================== STUDENT LOGIN LIST ==================\t\t\t\t\t\t\t\n\n\n\n\n");
    fl=fopen("login.txt", "rb");
    printf("\n\t\t\t\t %-20s %-30s %-25s %s\n\n", "Student ID", "Name", "Department", "Date");
    while(fread(&std, sizeof(std), 1, fl) == 1)
    {
        printf("\t\t\t\t %-20s %-30s %-25s %s\n\n", std.id, std.name, std.dept, std.date);
    }
    fclose(fl);
    printf("\n\t\t\t\t Press any key to continue...");
    fflush(stdin);
    getchar();
    ADDmenu2();

}
void STDmenu1()
{
    system("cls");
    printf("\t\t\t\t\t\t================== MAIN MENU ==================\t\t\t\t\t\t\t\n\n");
    printf("\t\t\t\t\t\t\t\t Hello %s! \t\t\t\t\t\t\t\n\n\n\n", std.name);
    printf("\n\t\t 1.Request A Book\n");
    printf("\n\t\t 2.Book List\n");
    printf("\n\t\t 3.Search For Books\n");
    printf("\n\t\t 4.Issue Books\n");
    printf("\n\t\t 5.Check Issued Books\n");
    printf("\n\t\t 6.Log Out\n");
    printf("\n\n\t\t Choose an option: ");
    int n;
    scanf(" %d",&n);
    if(n==1)
    {
        Reqbooks();
    }
    else if(n==2)
    {
        globalcount=0;
        booksList();
    }
    else if(n==3)
    {
        globalcount=0;
        booksearch();
    }
    else if(n==4)
    {
        issuebooks();
    }

    else if(n==5)
    {
        issueList();
    }
    else if(n==6)
    {
        password();
    }
    else
    {
        printf("\n\t\t Invalid Option.\n\t\t Press any key to try again...\t\n") ;
        fflush(stdin);
        getchar();
        system("cls");
        STDmenu1();
    }
}
void ADDmenu2()
{
    system("cls");
    printf("\t\t\t\t\t\t================== MAIN MENU ==================\t\t\t\t\t\t\t\n\n");
    printf("\t\t\t\t\t\t\t\t  Hello Admin! \t\t\t\t\t\t\t\n\n\n\n");
    printf("\n\t\t 1.Add Books\n");
    printf("\n\t\t 2.Book List\n");
    printf("\n\t\t 3 Check Student Login\n");
    printf("\n\t\t 4.Check Book Requests\n");
    printf("\n\t\t 5.Search For Books\n");
    printf("\n\t\t 6.Log Out\n");

    printf("\n\n\t\t Choose an option: ");
    int n;
    scanf(" %d",&n);
    if(n==1)
    {
        addbooks();
    }
    if(n==2)
    {
        globalcount=1;
        booksList();
    }
    else if(n==3)
    {
        LoginList();
    }
    else if(n==4)
    {
        stdrList();
    }

    else if(n==5)
    {
        globalcount=1;
        booksearch();
    }
    else if(n==6)
    {
        password();
    }
    else
    {
        printf("\n\t\t Invalid Option.\n\t\t Press any key to try again...\t\n") ;
        fflush(stdin);
        getchar();
        system("cls");
        ADDmenu2();
    }
}

void password()
{

    system("cls");
    printf("\t\t\t\t\t\t================== WELCOME TO MIST LIBRARY ==================\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t CHOOSE A LOGIN OPTION:\n\n");
    printf("\t\t 1.Student Login\n");
    printf("\t\t 2.Admin Login\n\n");
    printf("\t\t Press 0 to exit the program...\n");
    int x;
    printf("\n\n\t\t Choice: ");
    scanf("%d",&x);
    if(x==1)
    {
        password1();
    }
    else if(x==2)
    {
        password2();
    }
    else if(x==0)
    {
        printf("\n\t\t\t\t\t\t\t Thank you for visiting, have a nice day! \t\t\t\t\n\n\n");
        exit(1);
    }
    else
    {
        printf("Invalid option.\n");
        printf("Press enter to try again...");

    }
    fflush(stdin);
    getchar();
    password();

}
void addbooks()
{
    system("cls");
    printf("\t\t\t\t\t\t================== ADD BOOKS ==================\t\t\t\t\t\t\t\n\n\n");
    fp=fopen("books.txt","ab");
    printf("\n\t\t Enter ID: ");
    fflush(stdin);
    scanf(" %s", &b.id);
    printf("\t\t Enter Book Name: ");
    fflush(stdin);
    gets(b.name);
    printf("\t\t Enter Author: ");
    fflush(stdin);
    gets(b.author);

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%d/%d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(b.date, myDate);


    fwrite(&b,sizeof(b),1,fp);
    fclose(fp);
    printf("\n\n\n\t\t Book Added Successfully!\n\t\t Press any key to continue...");
    fflush(stdin);
    getchar();
    ADDmenu2();


}
void booksList()
{

    system("cls");
    printf("\t\t\t\t\t\t================== AVAILABLE BOOKS ==================\t\t\t\t\t\t\t\n\n\n");
    printf("\n\t\t\t %-20s %-50s %-25s %s\n\n", "Book ID", "Book Name", "Author", "Date");
    fp = fopen("books.txt", "rb");
    while(fread(&b, sizeof(b), 1, fp) == 1)
    {
        printf("\t\t\t %-20s %-50s %-25s %s\n\n", b.id, b.name, b.author, b.date);
    }

    fclose(fp);
    printf("\n\t\t\t Press any key to continue...");
    fflush(stdin);
    getchar();
    if(globalcount==1)
    {
        ADDmenu2();
    }
    else
    {
        STDmenu1();
    }
}

void booksearch()
{
    int d[50],count=0;
    system("cls") ;
    printf("\t\t\t\t\t\t================== SEARCH BOOKS ==================\t\t\t\t\t\t\t\n\n\n");
    fp=fopen("books.txt","r");
    getchar();
    printf("\n\t\t Enter ID: ");
    gets(d);
    while(fread(&b,sizeof(b),1,fp)==1)
    {
        if(strcmp(d,b.id)==0)
        {
            printf("\n\t\t Searching...");
            printf("\n\t\t Book Found!\n\n");
            printf("\n\t\t %-20s %-50s %-20s %s\n\n", "Book id", "Book Name", "Author", "Date");
            printf("\n\t\t %-20s %-50s %-20s %s\n", b.id, b.name, b.author, b.date);
            count=1;
        }
    }
    if(count==0)
    {
        printf("\n\n\n\t\t There is no book with this ID.");
    }
    printf("\n\n\t\t Press any key to continue...");
    fflush(stdin);
    getchar();
    if(globalcount==1)
    {
        ADDmenu2();
    }
    else
    {
        STDmenu1();
    }


}


void heading()
{
    system("cls");
    printf("\t\t\t\t\t\t================== MIST LIBRARY ==================\t\t\t\t\t\t\t\n\n\n");


}
void password1()
{
    heading();
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%d/%d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(std.date, myDate);
    char pwd1[10]= {"student"};
    char pwd2[10];
    printf("\n\t\t STUDENT LOGIN \t\t\n\n");
    fl=fopen("login.txt","ab+");

    printf("\t\t Enter Name: ");
    fflush(stdin);
    gets(std.name);


    printf("\t\t Enter ID: ");
    fflush(stdin);
    gets(std.id);


    printf("\t\t Enter Department: ");
    fflush(stdin);
    gets(std.dept);

    printf("\t\t Enter Password: ");
    scanf(" %s",pwd2);
    if(strcmp(pwd1,pwd2)==0)
    {
        fwrite(&std, sizeof(std), 1, fl);
        printf("\n\n\t\t Login confirmed.");
        globalcount=1;
        printf("\n\t\t Press any key to continue...");
    }
    else
    {
        if(d==3)
        {
            exit(0);
        }
        else
        {
            printf("\n\n\t\t Wrong credentials.\n\t\t Press any key to try again...\n");
            printf("\n\t\t (%d out of 3 chances left)\n",d);
            d++;
            fflush(stdin);
            getchar();
            password1();
        }
    }
    fclose(fl);
    fflush(stdin);
    getchar();
    STDmenu1();

}
void password2()
{
    heading();
    char pwd1[10]= {"admin"};
    char pwd2[10];
    printf("\n\t\t ADMIN LOGIN \t\t\n\n");
    printf("\t\t Enter Password: ");
    scanf(" %s",pwd2);
    if(strcmp(pwd1,pwd2)==0)
    {
        printf("\n\n\t\t Login confirmed.");
        printf("\n\t\t Press any key to continue...");
    }
    else
    {
        if(d==3)
        {
            exit(0);
        }
        else
        {
            printf("\n\n\t\t Wrong credentials.\n\t\t Press any key to try again...");
            printf("\n\t\t (%d out of 3 chances left)\n",d);
            d++;
            fflush(stdin);
            getchar();
            password2();
        }
    }
    fflush(stdin);
    getchar();
    ADDmenu2();

}


void Reqbooks()
{
    system("cls");

    printf("\t\t\t\t\t\t================== REQUEST BOOKS ==================\t\t\t\t\t\t\t\n\n\n");
    ft=fopen("request.txt","ab");

    printf("\t\t Enter Book Name: ");
    fflush(stdin);
    gets(b.name);

    printf("\t\t Enter Author: ");
    fflush(stdin);
    gets(b.author);

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%d/%d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    fseek(ft,0,SEEK_END);
    fwrite(&b,sizeof(b),1,ft);
    fclose(ft);
    printf("\n\n\n\t\t Your request has been sent and is awaiting approval.\n\t\t Press any key to continue...");
    fflush(stdin);
    getchar();
    STDmenu1();

}

void issuebooks()
{
    system("cls");
    printf("\t\t\t\t\t\t================== ISSUE BOOKS ==================\t\t\t\t\t\t\t\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t AVAILABLE BOOKS \t\t\t\t\t\t\t\n\n\n");
    printf("\n\t\t\t\t %-20s %-50s %-25s %s\n\n", "Book ID", "Book Name", "Author", "Date");
    fp = fopen("books.txt", "rb");
    while(fread(&b, sizeof(b), 1, fp) == 1)
    {
        printf("\t\t\t\t %-20s %-50s %-25s %s\n\n", b.id, b.name, b.author, b.date);
    }
    fi=fopen("book issue.txt","ab");
    printf("\n\t\t Fill out the form below with information of desired books from the list above: ");
    printf("\n\n\t\t Enter Book Name: ");
    fflush(stdin);
    gets(b.name);

    printf("\t\t Enter Author: ");
    fflush(stdin);
    gets(b.author);

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%d/%d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    fseek(fi,0,SEEK_END);
    fwrite(&b,sizeof(b),1,fi);
    fclose(fi);
    fclose(fp);
    printf("\n\n\n\t\t Book Issued Successfully!\n\t\t Press any key to continue...");
    fflush(stdin);
    getchar();
    STDmenu1();
}

void issueList()
{

    system("cls");
    printf("\t\t\t\t\t\t================== ISSUED BOOKS ==================\t\t\t\t\t\t\t\n\n\n");
    printf("\n\t\t\t\t %-30s %-25s %s\n\n", "Book Name", "Author", "Date");
    fi = fopen("book issue.txt", "rb");
    while(fread(&b, sizeof(b), 1, fi) == 1)
    {
        printf("\t\t\t\t %-30s %-25s %s\n\n", b.name, b.author, b.date);
    }

    fclose(fi);
    printf("\n\t\t\t\t Press any key to continue...");
    fflush(stdin);
    getchar();
    STDmenu1();
}
void stdrList()
{

    system("cls");
    printf("\t\t\t\t\t\t================== REQUESTED BOOKS ==================\t\t\t\t\t\t\t\n\n\n");
    printf("\n\t\t\t\t %-50s %-25s %s\n\n", "Book Name", "Author", "Date");
    fp = fopen("request.txt", "rb");
    while(fread(&b, sizeof(b), 1, fp) == 1)
    {
        printf("\t\t\t\t %-50s %-25s %s\n\n", b.name, b.author, b.date);
    }

    fclose(fp);
    printf("\n\n\n\t\t\t\t Press any key to continue...");
    fflush(stdin);
    getchar();
    ADDmenu2();
}

