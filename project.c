#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>
struct roomdetail
{
  int room_number;
  char name[40];
  int no_of_people;
  char add[120];
  char email[40];
  int start_dd;
  int start_mm;
  int end_dd;
  int end_mm;
}s;
void add();
//void delete();
//void edit();
//void print();
//void input();
void login();
void menu();
void main()
{
  //system("cls");
  int i,j,k;
  printf("\nWelcome to the.....\n");//<--Think of something here..!!
  menu();                                               
}
void menu()
{
  int i;
  Start:
  printf("\nLogin to the system:");
  login();
  printf("MENU:");
  do
  {
   printf("\n1:Add a reservation\n2:Delete a reservation\n3:Edit a reservation\n4:Show a reservation\n5:Exit\n");
   printf("\nEnter your choice:");
   scanf("%d",&i);
   switch(i)
   {
     case 1:add();
            break;
     case 2://delete();
            break;
     case 3://edit();
            break;
     case 4://print();
            break;
     case 5:exit(1);
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
  int i,j,k,chk=0,room_number;
  int start_dd,end_dd,start_mm,end_mm;
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
    ROOM:
    printf("\nEnter the room number which you want to book:");
    scanf("%d",&room_number);
    INDATE:
    printf("\nEnter Check-In Date:");
    printf("\nMonth:-");
    scanf("%d",&start_mm);
    printf("\nDate:");
    scanf("%d",&start_dd);
    OUTDATE:
    printf("\nEnter Check-Out Date:");
    printf("\nMonth:");
    scanf("%d",&end_mm);
    printf("\nDate:");
    scanf("%d",&end_dd);
    //Main loop for checking only
    while((fscanf(fp," %d %s %d %s %s %d %d %d %d ",&s.room_number,s.name,&s.no_of_people,s.add,s.email,&s.start_dd,&s.start_mm,&s.end_dd,&s.end_mm))!=EOF)//Main scanning loop
    {
      if(start_mm==s.start_mm && end_mm==s.end_mm)//Conditions for checking only date
      {       
        if((start_dd=s.start_dd) || (start_dd>s.start_dd && start_dd<s.end_dd) || (start_dd==s.end_dd))
        {
          printf("\nSelected room is booked from %d/%d to %d/%d",s.start_dd,s.start_mm,s.end_dd,s.end_mm);
          printf("\nPlease select a different room or change the date:");
          printf("\n1.Select new room\n2.Change date\n");
          printf("\nEnter your choice:");
          scanf("%d",&j);
          switch(j)
          {
            case 1:goto ROOM;
                   break;
            case 2:goto INDATE;
                   break;       
          }
        }        
      }
      if(room_number==s.room_number && start_mm==s.start_mm && start_dd==s.start_dd)//Don't know why this exists..!!
      {
        printf("\nSelected room is already booked from %d/%d to %d/%d",s.start_dd,s.start_mm,s.end_dd,s.end_mm);//<---
        printf("\nSelect another room..press any key to continue..");
        getch();
        goto ROOM;
      } 
     s.room_number=room_number;
     s.start_dd=start_dd;
     s.start_mm=start_mm;
     s.end_dd=end_dd;
     s.end_mm=end_mm;
    }
    NAME:
    printf("\nEnter your name:");
    gets(s.name);
    if((strlen(s.name))<=2)
    {
      printf("\nEntered name is invalid");
      printf("\nPress any key to continue..");
      getch();
      goto NAME;
    }
    No_of_People:
    printf("\nEnter the number of people:");
    scanf("%d",&s.no_of_people);
    if(s.no_of_people<1)
    {
      printf("\nNumber of people cannot be less than one");
      printf("\nEnter again..press any key to continue");
      goto No_of_People;
      getch();
    }
    ADDRESS:
    printf("\nEnter your current residential address:");
    gets(s.add);
    if((strlen(s.add))<=4)
    {
      printf("\nInvalid Address");
      printf("\nEnter again..press any key to continue");
      getch();
      goto ADDRESS;
    }
    EMAIL:
    printf("Enter your Email-ID:");
    gets(s.email);
    for(i=0;s.email[i]!='\0';i++)
    {
     if(s.email[i]=='@')
      {
        chk=chk+1;
        break;         
      }
    }  
    if(chk!=1)
    {
      printf("\nInvalid Email-ID");
      printf("\nEnter again..press any key to continue");
      getch();
      goto EMAIL;
    }
    fprintf(fp,"\n %d %s %d %s %s %d %d %d %d ",s.room_number,s.name,s.no_of_people,s.add,s.email,s.start_dd,s.start_mm,s.end_dd,s.end_mm);
    printf("\nRoom booked successfully..!!");
    fclose(fp);
  }
  printf("\nPress esc key to exit..or any other key to add another customer detail");
  k=getche();
  if(k==27)
  {
    menu();
  }
  else
  {
    add();
  }
}
void login()
{
  int a=4;
  char uword[100];
  char pword[100];
  do
 {
   clrscr();
   printf("************************LOGIN FORM***************************");
   printf("\nEnter the username:/n");
   scanf("%s",uword);
   printf("/nEnter the password:");
   int i=0;
   while (i<6)
   {
    pword[i]=getch();
    printf("*");
    i++;
   }
   pword[i]='/0';
   if((uword=="admin")&&(pword=="admin"))
   {
     printf("/nInvalid username or password");
     a--;
   }
  else
  {
    printf("/nLogin Successful/n");
    exit(1);
  }
 }while(a);
}  
  
  
  



      
       
 
  
       

    