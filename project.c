#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
struct roomdetail
{
  int room_number;
  char name[40];
  int no_of_people;
  char add[40];
  char email[40];
  int start_dd;
  int start_mm;
  int end_dd;
  int end_mm;
}s;
void add();
void delete();
void edit();
void print();
void input();
void login();
void main()
{
  system("cls");
  int i,j,k;
  printf("\nWelcome to the.....\n");
  Start:
  printf("\nLogin to the system:");
  login();
  printf("MENU:");
  do
 {
   printf("\n1:Add a reservation\n2:Delete a reservation\n3:Edit a reservation\n4:Show a reservation:\n");
   scanf("%d",&i);
   switch(i)
   {
     case 1:add();
                 break;
     case 2:delete();
                 break;
     case 3:edit();
                 break;
     case 4:print();
                 break;
     default:printf("\n*Invalid Choice..Enter again*");
                 system("cls");
                 break;
   }
 }while(1);                                               
}
void add()
{
  FILE *fp;
  int i,j,k,room_number;
  fp=fopen("Reserv_Details.txt","a+");
  if(fp==0)
  {
    printf("\nDatabse empty....please wait while we create the records");
    fp=fopen("Reserv_Details.txt","w+");
    printf("\nProcess completed press any key to continue....");
    getch();
  }
  //system("cls");
  if((fp=fopen("Reserv_Details.txt","a+"))!=NULL)
  {
    ADD:
    printf("\nEnter the room number which you want to book:");
    scanf("%d",&room_number);
    while((fscanf(" %d %s %d %s %s %d %d %d %d",&s.room_number,s.name,&s.no_of_people,s.add,s.email,&s.start_dd,&s.start_mm,&s.end_dd,&s.end_mm))!=EOF)
    {
      if(room_number==s.room_number)
      {
        printf("\nEntered room is already booked from %d/%d to %d/%d",s.start_dd,s.start_mm,s.end_dd,s.end_mm);//<---
        printf("\nSelect another room..press any key to continue..");
        getch();
        goto ADD;
      } 
     s.room_number=room_number;
     NAME:
     printf("Enter your name:");
     gets(s.name);
     if((strlen(s.name))<=2)
     {
       printf("\nEntered name is invalid");
       printf("\nPress any key to continue..");
       goto NAME;
       getch();
     }
     No_of_People:
     printf("Enter the number of people:");
     scanf("%d",&s.no_of_people);
      
       
     
       

    