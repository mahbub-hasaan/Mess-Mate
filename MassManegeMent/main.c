//list of header files
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>
#include <windows.h>
#include<string.h>
//list of function prototype
void addMember();
void member();
void debid();
void expenses();
void mealCount();
void monthlyReport();
void loaderanim();
void password();
void newuser();
void editpassword();
void menu();
int  getdata();
int  checkid(int);

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

COORD coord = {0, 0}; // sets coordinates to 0,0
//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res,cursor_size;

void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//list of global files that can be acceed form anywhere in program
FILE *file;

struct students // Declare all type of input
{
    int id;
    char name[20];
    char mobile[20];
    char religion[20];
    char ocupation[25];
    int count;
    float dabit;

};
struct students a;
//char passwor[10]= {"shakil"};

int main(){
    system("color b");
    loaderanim();
    system("cls");
    char option;
    gotoxy(10,4);
    printf(":::::::::: MESS MANAGEMENT :::::::::");
    gotoxy(22,7);
    printf("1. Login");
    gotoxy(22,8);
    printf("2. New user");
    gotoxy(22,9);
    printf("3. Edit Password");
    gotoxy(22,10);
    printf("4. Exit");
    gotoxy(18,13);
    printf("Enter your option: ");
    option=getch();
    switch(option){
        case '1':
            Password();
            getch();
            break;
        case '2':
            newuser();
            break;
        case '3':
            editpassword();
            break;
        case '4':
            system("cls");
            gotoxy(20,5);
            printf("MADE BY: ");
            gotoxy(20,8);
            printf("Md Mahbub Hasan");
            gotoxy(20,9);
            printf("ID: 161-35-1511");
            gotoxy(20,12);
            printf("Rownak Jahan Tanjil");
            gotoxy(20,13);
            printf("ID: 161-35-1463");
            gotoxy(15,17);
            printf("This application close in 3 sec\n\n");
            int loader;
            gotoxy(15,19);
            for(loader=1; loader<32; loader++)
                {
                    delay(200);
                    printf("%c",222);
                }
            gotoxy(15,23);
             exit(0);
        default:
            system("cls");
            gotoxy(15,5);
    printf("Wrong Input!!!!! Try Again....\n\n\t\tPRESS any key \n");
    getch();
    return main();

    }
    return 0;
}
//main menu of the program
void menu(){
    loaderanim();
    system("cls");
    time_t time1;
    time(&time1);
    gotoxy(10,4);
    printf("============:WELCOME:============");
    gotoxy(15,6);
    printf("%s",ctime(&time1));
    gotoxy(15,7);
    printf("------------------------");
    gotoxy(15,9);
    printf("1. Member Informatiom\n");
    gotoxy(15,10);
    printf("2. Debit");
    gotoxy(15,11);
    printf("3. Expenses");
    gotoxy(15,12);
    printf("4. Meal Count");
    gotoxy(15,13);
    printf("5. Month Report");
    gotoxy(15,14);
    printf("6. Add Member");
    gotoxy(15,15);
    printf("7. Logout");
    int a=0;
    gotoxy(13,18);
    printf("  Enter Your Choice(1-7):  ");
    switch(getch()){
        case '1':member();
                break;
        case '2':debid();
                break;
        case '3':expenses();
                break;
        case '4': mealCount();
                break;
        case '5':monthlyReport();
                break;
        case '6':addMember();
                break;
        case '7':
            main();
            break;
        default:
            system("cls");
            gotoxy(15,5);
    printf("Wrong Input!!!!! Try Again....\n\n\t\tPRESS any key \n");
    getch();
    return menu();
}

}
void member(){
    loaderanim();
    system("cls");
    int i=0,j=5;

    system("cls");

    gotoxy(30,1);
    printf("MEMBER'S IFORMATION");
    file=fopen("member.txt","rb");
    if(file==NULL){
        gotoxy(30,8);
        printf("No Member Added!!");
        gotoxy(30,10);
        printf("PRESS Any Key");
        getch();
        menu();
    }
    else{
    gotoxy(2,3);
    printf("ID           NAME           Mobile No.     RELIGION      OCUPATION     DABIT");
    while(fread(&a,sizeof(a),1,file)==1){
        gotoxy(2,j);
        printf("%d",a.id);
        gotoxy(15,j);
        printf("%s",a.name);
        gotoxy(30,j);
        printf("%s",a.mobile);
        gotoxy(45,j);
        printf("%s",a.religion);
        gotoxy(60,j);
        printf("%s",a.ocupation);
        gotoxy(73,j);
        printf("%.2f",a.dabit);
        printf("\n\n");
        j++;
        i=i+1;
        }
    }
    gotoxy(3,25);
    printf("Total Member = %d",i);
    fclose(file);
    gotoxy(60,25);
    printf("Enter 'H' to Go Home : ");
    char x=getch();
    if(x=='H'||x=='h'){
        return menu();
    }
    else{
        system("cls");
        gotoxy(15,7);
        printf("Wrong input!!!!");
        delay(1000);
        member();
    }

}
//this function count Expenses of every day
void expenses(){
    loaderanim();
    system("cls");
    int totalDabit=0,sum=0;
    file=fopen("member.txt","rb");
    while(fread(&a,sizeof(a),1,file)==1)
    {
       totalDabit=totalDabit+a.dabit;
    }
    fclose(file);
    FILE *expen1 = fopen("expenses1.txt", "r");
    int number=0,totalExpn=0;

    while( fscanf(expen1, "%d,", &number) > 0 )
    {
        totalExpn+= number;
    }
    fclose(expen1);
    if(totalExpn<totalDabit){
            time_t time1;
            time(&time1);
            int dailyExpn=0;
            char Consuming[10];
            system("cls");
            gotoxy(10,1);
            printf("EXPENSES");
            FILE *expen=fopen("expenses.txt","ab+");
            gotoxy(4,3);
            printf("Enter today Expenses (int): ");
            scanf("%d",&dailyExpn);
            gotoxy(4,5);
            printf("Enter Name of Consuming: ");
            scanf("%s",&Consuming);
            fprintf(expen,"Time: %s\t Taka: %d\n\tName of Consuming:  %s\n\n\n",ctime(&time1),dailyExpn,Consuming);
            fclose(expen);
            FILE *expen1=fopen("expenses1.txt","ab+");
            fprintf(expen1,"%d ",dailyExpn);
            fclose(expen1);
            gotoxy(4,8);
            printf("Want add more?(Y/N): ");
            char ch =getch();
            if(ch=='N'||ch=='n'){
                fclose(expen);
                system("cls");
            return menu();
            }
            else{
                expenses();
            }

    }
    else{
        system("cls");
        gotoxy(10,10);
        printf("Don't have enough money");
        delay(2000);
        menu();
    }
    }
//this function count debit of member
void debid(){
    loaderanim();
    system("cls");
    float totalDabit=0;
    int j=5;
    gotoxy(13,1);
    printf("DEBIT");
    gotoxy(2,3);
    printf("ID        NAME          DABIT");
    file=fopen("member.txt","rb");
    while(fread(&a,sizeof(a),1,file)==1)
    {
        gotoxy(2,j);
        printf("%d",a.id);
        gotoxy(12,j);
        printf("%s",a.name);
        gotoxy(25,j);
        printf("%.2f",a.dabit);
       totalDabit=totalDabit+a.dabit;
       j++;
    }
    gotoxy(2,25);
    printf("Total Debit: %.2f",totalDabit);
    gotoxy(30,25);
    printf("Enter 'H' to Go Home : ");
    char x=getch();
    if(x=='H'||x=='h'){
        return menu();
    }
    else{
        system("cls");
        gotoxy(15,7);
        printf("Wrong input!!!!");
        delay(1000);
        debid();
    }


}
//this function will add members
void addMember(){
    loaderanim();
    system("cls");
    int i;

    file=fopen("member.txt","ab+");
    if(getdata()==1)
    {
        fseek(file,0,SEEK_END);
        fwrite(&a,sizeof(a),1,file);
        fclose(file);
        gotoxy(21,14);
        printf("The record is successfully saved ");
        gotoxy(21,15);
        printf("Save any more?(Y / N):");
        char ch=getch();
        if(ch=='n'|| ch=='N')
            menu();
        else
            system("cls");
        addMember();
    }
    }
//this function will count everyday meal of members
void mealCount(){
    loaderanim();
    system("cls");
    gotoxy(10,1);
    printf("MEAL COUNT");
    gotoxy(2,3);
    printf("ID           NAME           MEAL");
    int i=0,j=5,k,meal,totalMeal=0;
    file=fopen("member.txt","rb");
    if(file==NULL){
        gotoxy(10,8);
        printf("No Member Added!!");
        gotoxy(2,25);
        printf("Total Meal: %d",totalMeal);
        gotoxy(25,25);
        printf("PRESS any Key");
        getch();
        menu();
    }
    else{
    while(fread(&a,sizeof(a),1,file)==1)
    {
        gotoxy(2,j);
        printf("%d",a.id);
        gotoxy(15,j);
        printf("%s",a.name);
        j++;
        i=i+1;
    }
    j=5;
    char fileName[20]={0};
    for(k=0;k<i;k++){
        sprintf(fileName,"memberMeal%d.txt",k);
        file=fopen(fileName,"ab+");
        gotoxy(30,j);
        scanf("%d",&meal);
        fprintf(file,"\n%d",meal);
        fclose(file);
        file=fopen("meal.txt","ab+");
        fprintf(file,"\n%d",meal);
        fclose(file);
        j++;
    }
        file=fopen("meal.txt","r");
        while( fscanf(file,"%d",&meal) > 0 ){
        totalMeal += meal;
        }
        fclose(file);
        gotoxy(2,25);
        printf("Total Meal: %d",totalMeal);
        gotoxy(25,25);
        printf("Want add more?(Y/N): ");
        char ch =getch();
        if(ch=='N'||ch=='n'){
                system("cls");
                return menu();
        }
        else if(ch=='Y'|| ch=='y'){
         mealCount();
        }
        else{
            system("cls");
            gotoxy(10,5);
            printf("Wrong input!!");
            delay(1000);
            gotoxy(10,10);
            printf("Enter 'H' to Go Home : ");
            char x=getch();
            if(x=='H'||x=='h'){
                return menu();
            }
        }
    }
}



//this function gives monthly report
void monthlyReport(){
    loaderanim();
    system("cls");
    char c[1000],ch;
    int i=0,k,j=14;
    gotoxy(45,1);
    printf("MONTHLY REPORT");
    gotoxy(44,2);
    printf("----------------");
    gotoxy(6,4);
    printf("EXPENSES DETAILS\n----------------------------------\n\n");
    FILE *expen;
    if ((expen = fopen("expenses.txt", "r")) == NULL){   //Read expenses detail from Expenses file.
        gotoxy(10,10);
        printf("Error!! file not found\n\n");
        gotoxy(10,13);
        printf("Press Any Key to go Home");
        getch();
        menu();
    }
    ch=getc(expen);
    while(ch != EOF){
        printf("%c", ch);
        ch = getc(expen);
    }
    fclose(expen);
    FILE *expen1 = fopen("expenses1.txt", "r");   //Read all expenses to count total expenses
    int number = 0;
    int sum = 0;

    while( fscanf(expen1, "%d,", &number) > 0 )
    {
        sum += number;
    }
    fclose(expen1);
    int totalMeal=0,meal=0;
    float mealRate;
    file=fopen("meal.txt","r");         //Read meal file to count total number of meal
        while( fscanf(file,"%d",&meal) > 0 ){
        totalMeal += meal;
        }
        fclose(file);
    mealRate=sum/totalMeal;   //find out meal rate
    gotoxy(63,12);
    printf("ID    NAME        MEAL      BILL     Due/Payable");  //display member information
    file=fopen("member.txt","rb");
    while(fread(&a,sizeof(a),1,file)==1)
    {
        gotoxy(63,j);
        printf("%d",a.id);
        gotoxy(69,j);
        printf("%s",a.name);
        j++;
        i=i+1;
    }
    fclose(file);
    char fileName[20]={0};
    int mealPerMember[100],totalperM=0,meall=0;
    float bill[100];
    j=14;
    for(k=0;k<i;k++){
        totalperM=0;
        sprintf(fileName,"memberMeal%d.txt",k);         //read each member meal file to count every one meal total
        file=fopen(fileName,"r");
        while( fscanf(file,"%d",&meall) > 0 ){
        totalperM+= meall;
      }
        fclose(file);
        mealPerMember[k]=totalperM;
        bill[k]=mealRate*mealPerMember[k];
        gotoxy(83,j);
        printf("%d",mealPerMember[k]);
        gotoxy(90,j);
        printf("%.2f",bill[k]);
        j++;
   }
   i=0,j=14;
   float DC[i];
   file=fopen("member.txt","rb");            //read each member debit
    while(fread(&a,sizeof(a),1,file)==1)
    {
       DC[i]=a.dabit-bill[i];
       gotoxy(102,j);
       printf("%.2f",DC[i]);           //display each member debit
       j++;
       i++;
    }
    fclose(file);

    gotoxy(88,6);
    printf("Total Cost: %d",sum);    //display total cost
    gotoxy(88,8);
    printf("Total Member: %d",i);   //display total member
    gotoxy(63,6);
    printf("Total Meal: %d",totalMeal); //display total meal
    gotoxy(63,8);
    printf("Meal Rate: %.2f",mealRate); //display meal rate
    gotoxy(65,25);
    printf("Enter 'H' to Go Home : ");
    char x=getch();
    if(x=='H'||x=='h'){
        return menu();
    }
    else{
        system("cls");
        gotoxy(15,7);
        printf("Wrong input!!!!");
        delay(1000);
        monthlyReport();
    }

}
void loaderanim()     //for loader display
{
    int loader;
    system("cls");
    gotoxy(26,7);
    printf("LOADING........");
    gotoxy(15,7);
    for(loader=1; loader<30; loader++)
    {
        delay(50);
        printf("%c",222);
    }
}
void Password(void) //for password option
{

    system("cls");
    gotoxy(10,4);
    char d[25]=" Password Protected";
    char ch,pass[10],passwor[10],userName[10];
    int i=0,j;
    for(j=0; j<10; j++)
    {
        delay(20);
        printf("=");
    }
    for(j=0; j<20; j++)
    {
        delay(20);
        printf("%c",d[j]);
    }
    for(j=0; j<10; j++)
    {
        delay(20);
        printf("=");
    }
    gotoxy(21,6);
    printf("Enter user name:");
    scanf("%s",userName);
    gotoxy(21,7);
    printf("Enter Password:");

    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    file=fopen("password.txt","r");
    fscanf(file,"%s",passwor);
    fclose(file);
   if(strcmp(pass,passwor)==0)
    {
        gotoxy(21,10);
        printf("Password match!!");
        gotoxy(18,12);
        printf("Press any key to continue.....");
        getch();
        menu();
    }
    else
    {
        gotoxy(21,9);
        printf("Warning!! Incorrect Password");
        gotoxy(21,12);
        printf("Try again         Press ENTER ");
        getch();
        Password();
    }
}
void newuser(){
    loaderanim();
    system("cls");
    gotoxy(10,4);
    printf(":::::::::: MESS MANAGEMENT :::::::::");
    char userName[20],pass[20],repass[20];
    gotoxy(15,6);
    printf("ENTER user name:");
    scanf("%s",userName);
    gotoxy(15,8);
    printf("Enter password: ");
    scanf("%s",pass);
    gotoxy(15,10);
    printf("Re-Enter your password: ");
    scanf("%s",repass);
    file=fopen("password.txt","w");
    if(strcmp(pass,repass)==0){
    fprintf(file,"%s",pass);
    fclose(file);
    gotoxy(20,14);
    printf("DONE !!!");
    gotoxy(15,16);
    printf("Press ENTER to login");
    getch();
    Password();
    }
    else{
        gotoxy(15,14);
        printf("Password dont't match");
        gotoxy(15,16);
        printf("Try again    Press ENTER");
        getch();
        newuser();
    }
}
void editpassword(){
    loaderanim();
    system("cls");
    gotoxy(10,4);
    printf(":::::::::: MESS MANAGEMENT :::::::::");
    char oldpass[20],pass[20],repass[20],passwor[20];
    gotoxy(15,6);
    printf("Enter old password:");
    scanf("%s",oldpass);
    gotoxy(15,8);
    file=fopen("password.txt","r");
    fscanf(file,"%s",passwor);
    fclose(file);
    if(strcmp(oldpass,passwor)==0){
        printf("Enter New Password: ");
        scanf("%s",pass);
        gotoxy(15,10);
        printf("Re-Enter your password: ");
        scanf("%s",repass);
            if(strcmp(pass,repass)==0){
                    file=fopen("password.txt","w");
                    fprintf(file,"%s",pass);
                    fclose(file);
                    gotoxy(20,14);
                    printf("DONE !!!");
                    gotoxy(15,16);
                    printf("Press ENTER to go Home");
                    getch();
                    main();
                }
            else{
                gotoxy(15,14);
                printf("Password dont't match");
                gotoxy(15,16);
                printf("Try again    Press ENTER");
                getch();
                editpassword();
            }
    }
    else{
        gotoxy(15,14);
        printf("Old password dont't match");
        gotoxy(15,16);
        printf("Go Home    Press ENTER");
        getch();
        main();
    }

}
//this function get data from user
int getdata()
{
    int t;
    gotoxy(20,3);
    printf("Enter the Information Below");
    gotoxy(46,5);
    printf("");
    gotoxy(20,6);
    printf("");
    gotoxy(46,6);
    printf("");
    gotoxy(20,7);
    printf("");
    gotoxy(46,7);
    printf("");
    gotoxy(20,8);
    printf("");
    gotoxy(46,8);
    printf("");
    gotoxy(20,9);
    printf("");
    gotoxy(46,9);
    printf("");
    gotoxy(20,10);
    printf("");
    gotoxy(46,10);
    printf("");
    gotoxy(20,11);
    printf("");
    gotoxy(46,11);
    printf("");
    gotoxy(20,12);

    gotoxy(21,7);
    printf("Member ID:\t");
    gotoxy(33,7);
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("The member id already exists!");
        gotoxy(21,16);
        printf("Want add Again? (Y/N): ");
        char x=getch();
        if(x=='n'||x=='N'){
            menu();
        }
        else{
           addMember();
    }
    }
    a.id=t;
    gotoxy(21,8);
    printf("Name:");
    gotoxy(28,8);
    fflush(stdin);
    gets(a.name);

    gotoxy(21,9);
    printf("Mobile No.:");
    gotoxy(32,9);
    scanf("%s",a.mobile);
    fflush(stdin);
    gotoxy(21,10);
    printf("Religion:");
    gotoxy(31,10);
    scanf("%s",&a.religion);


    gotoxy(21,11);
    printf("Ocupation :");
    gotoxy(33,11);
    scanf("%s",&a.ocupation);

    gotoxy(21,12);
    printf("Dabit :");
    gotoxy(33,12);
    scanf("%f",&a.dabit);

    return 1;
}
int checkid(int t)  //check member  in mess or not
{
    rewind(file);
    while(fread(&a,sizeof(a),1,file)==1)
        if(a.id==t)
            return 0;
    return 1;
}

