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
void delete();
void edit();
void print();
//void filemanage();
void login();
void menu();
void main()
{
  //system("cls");
  printf("\n****Welcome to the Hotel Reservation System****\n");//<--Think of something here..!!
  login();
  menu();                                               
}
void menu()
{
  int i;
  printf("\n**********MENU**********");
  do
  {
    printf("\n1:Add a reservation\n2:Delete a reservation\n3:Edit a reservation\n4:Show all reservations\n5:Logout\n6.Exit\n");
    printf("\nEnter your choice:");
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
      case 5:login();
             break;
      case 6:exit(1);
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
  fp=fopen("ReservDetails.txt","a+");
  if(fp==NULL)
  {
    printf("\nDatabse empty....please wait while we create the records");
    fp=fopen("ReservDetails.txt","w+");
    printf("\nProcess completed press any key to continue....");
    getch();
  }
  //system("cls");
  if((fp=fopen("ReservDetails.txt","a+"))!=NULL)
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
    if(start_mm==end_mm)
    {
      if(end_dd<start_dd)
      {
        printf("\nCheck-Out date cannot be before Check-In date");
        printf("\nPlease change the dates");
        goto INDATE;
      }
    }
    if(start_mm>end_mm)
    {
      printf("\nCheck-Out date cannot be before Check-In date");
      printf("\nPlease change the dates");
      goto INDATE;
    }
    //Main loop for checking only
    COMPARE:
    while((fscanf(fp," %d %s %d %s %s %d %d %d %d",&s.room_number,s.name,&s.no_of_people,s.add,s.email,&s.start_dd,&s.start_mm,&s.end_dd,&s.end_mm))!=EOF)//Main scanning loop
    {
      if(start_mm==s.start_mm && end_mm==s.end_mm)//Conditions for checking only date
      {       
        if((start_dd==s.start_dd) || (start_dd==s.end_dd) || (end_dd==s.start_dd) || (end_dd==s.end_dd))
        {
          printf("\nSelected room is booked from %d/%d to %d/%d",s.start_dd,s.start_mm,s.end_dd,s.end_mm);
          printf("\nPlease select a different room or change the date:");
          printf("\n1.Select new room\n2.Change date\n");
          printf("\nEnter your choice:");
          scanf("%d",&j);
          switch(j)
          {
            case 1:printf("\nEnter new room number:");
                   scanf("%d",&room_number);
                   break;
            case 2:goto INDATE;
                   goto COMPARE;
                   break;       
          }
        }
        else if((start_dd>s.start_dd && start_dd<s.end_dd) || (end_dd>s.start_dd && end_dd<s.end_dd))
        {
          printf("\nSelected room is booked from %d/%d to %d/%d",s.start_dd,s.start_mm,s.end_dd,s.end_mm);
          printf("\nPlease select a different room or change the date:");
          printf("\n1.Select new room\n2.Change date\n");
          printf("\nEnter your choice:");
          scanf("%d",&j);
          switch(j)
          {
            case 1:printf("\nEnter new room number:");
                   scanf("%d",&room_number);
                   break;
            case 2:goto INDATE;
                   goto COMPARE;
                   break;
          }
        }          
      }
      else if((start_mm<s.start_mm) && (end_mm==s.start_mm))
      {
        if((end_dd==s.end_dd) || (end_dd>s.start_dd && end_dd<s.end_dd))
        {
          printf("\nSelected room is booked from %d/%d to %d/%d",s.start_dd,s.start_mm,s.end_dd,s.end_mm);
          printf("\nPlease select a different room or change the date:");
          printf("\n1.Select new room\n2.Change date\n");
          printf("\nEnter your choice:");
          scanf("%d",&j);
          switch(j)
          {
            case 1:printf("\nEnter new room number:");
                   scanf("%d",&room_number);
                   break;
            case 2:goto INDATE;
                   goto COMPARE;
                   break;       
          }
        }  
      }
      else if((start_mm==s.start_mm) && (end_mm>s.start_mm))
      {
        if((start_dd==s.start_dd) || (start_dd>s.start_dd && start_dd<s.end_dd))
        {
          printf("\nSelected room is booked from %d/%d to %d/%d",s.start_dd,s.start_mm,s.end_dd,s.end_mm);
          printf("\nPlease select a different room or change the date:");
          printf("\n1.Select new room\n2.Change date\n");
          printf("\nEnter your choice:");
          scanf("%d",&j);
          switch(j)
          {
            case 1:printf("\nEnter new room number:");
                   scanf("%d",&room_number);
                   break;
            case 2:goto INDATE;
                   goto COMPARE;
                   break;
          }
        }  
      }
      /*if(room_number==s.room_number && start_mm==s.start_mm && start_dd==s.start_dd && end_dd==s.end_dd)//Don't know why this exists..!!
      {
        printf("\nSelected room is already booked from %d/%d to %d/%d",s.start_dd,s.start_mm,s.end_dd,s.end_mm);//<---
        printf("\nSelect another room..press any key to continue..");
        getch();
        goto ROOM;
      }*/
    }   
    s.room_number=room_number;
    s.start_dd=start_dd;
    s.start_mm=start_mm;
    s.end_dd=end_dd;
    s.end_mm=end_mm;
    NAME:
    printf("\nEnter your name:");
    scanf("%s",s.name);
    //printf("%d",strlen(s.name));
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
    scanf("%s",s.add);
    //printf("%d",strlen(s.add));
    if((strlen(s.add))<=4)
    {
      printf("\nInvalid Address");
      printf("\nEnter again..press any key to continue");
      getch();
      goto ADDRESS;
    }
    EMAIL:
    printf("Enter your Email-ID:");
    scanf("%s",s.email);
    for(i=0;s.email[i]!='\0';i++)//Loop for checking email-ID
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
    fprintf(fp,"\n %d %s %d %s %s %d %d %d %d",s.room_number,s.name,s.no_of_people,s.add,s.email,s.start_dd,s.start_mm,s.end_dd,s.end_mm);
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
  do
  {
    int i=0;
    char uname[10];
    char pword[10];
    printf("****************LOGIN FORM****************");
    printf("\n Enter the username:");
    scanf("%s",&uname);
    printf("\n Enter the password:");
    while(i<5)
    { 
      pword[i]=getch();
      printf("*");
      i++;
    }
    pword[i]='\0';
    if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0)
    {
      printf("\n LOGIN SUCCESSFUL \n WELCOME TO THE SYSTEM");
      break;
    }
    else
    {
      printf("\n LOGIN UNSUCCESSFUL\n");
      a--;   
    }
  }while(a);
  if(a==0)
  {
    printf("\n You have entered username and password multiple times.!!!\n");
  }
  //system("cls");
}
void edit()
{
  FILE *fp1,*fp2;
  int room_number,i,found=0;
  char geb;
  //char old[]="ReservDetails.txt",new[]="temp.txt";
  fp1=fopen("temp.txt","w+");
  fp2=fopen("ReservDetails.txt","r+");
  if((fp2=fopen("ReservDetails.txt","r"))==NULL)
  {
    printf("\nNo records added..");
    printf("\nPress any key to return to menu..");
    getch();
    menu();
  }
  else
  {
    printf("\nEnter room number of customer to edit:");
    scanf("%d",&room_number);
    while((fscanf(fp2," %d %s %d %s %s %d %d %d %d",&s.room_number,s.name,&s.no_of_people,s.add,s.email,&s.start_dd,&s.start_mm,&s.end_dd,&s.end_mm))!=EOF)
    {
      if(room_number==s.room_number)
      {
        found=1;
        printf("\nRecord Found..");
        printf("\n****Existing Record****");
        printf("\nRoom Number:%d",s.room_number);
        printf("\nName:%s",s.name);
        printf("\nNumber of People:%d",s.no_of_people);
        printf("\nAddress:%s",s.add);
        printf("\nEmail-ID:%s",s.email);
        printf("\nCheck-In Date:%d/%d",s.start_dd,s.start_mm);
        printf("\nCheck-Out Date:%d/%d",s.end_dd,s.end_mm);
        printf("\n****Enter new details****");
        printf("\nEnter new name:");
        fflush(stdin);
        scanf("%s",s.name);
        printf("\nEnter Number of People:");
        scanf("%d",&s.no_of_people);
        printf("\nEnter new Address:");
        scanf("%s",s.add);
        printf("\nEnter new Email-ID:");
        scanf("%s",s.email);
        printf("\nPress 'e' to finish editing the record or press any other key to exit..");
        geb=getche();
        if(geb=='e' || geb=='E')
        {
          fprintf(fp1,"\n %d %s %d %s %s %d %d %d %d",s.room_number,s.name,s.no_of_people,s.add,s.email,s.start_dd,s.start_mm,s.end_dd,s.end_mm);
          fflush(stdin);
          printf("\nRecord Edited Successfully..!!");
        }
      }
      else
      {
        fprintf(fp1,"\n %d %s %d %s %s %d %d %d %d",s.room_number,s.name,s.no_of_people,s.add,s.email,s.start_dd,s.start_mm,s.end_dd,s.end_mm);
        fflush(stdin);
      }
    }
    if(found==0)
    {
      printf("\nThe record dosen't exist..!!");
    }
  }  
  fclose(fp1);
  fclose(fp2);
  if(remove("ReservDetails.txt")!=0)
  {
    printf("\nUnable to delete file");
  }
  else
  {
    printf("\nDeleted successfully");//Do something here
  }
  if(rename("temp.txt","ReservDetails.txt")!=0)
  {
    printf("\nUnable to rename");
  }
  else
  {
    printf("\nRenamed successfully");//Do something here
  }  
  printf("\nPress esc key to exit..or any other key to edit another record");
  i=getche();
  if(i==27)
  {
    menu();
  }
  else
  {
    edit();
  }
}
/*void filemanage()
{
  FILE *o,*t;
  o=fopen("ReservDetails.txt","a");
  t=fopen("temp.txt","a");
  fclose(o);
  if(remove("ReservDetails.txt")!=0)
  {
    printf("\nDelete error");
  }
  else
  {
    printf("\nOperation completed successfully");
  }
  fclose(t);
  if(rename("temp.txt","ReservDetails.txt")!=0)
  {
    printf("\nRename error");
  }
  else
  {
    printf("\n2nd operation completed successfully");
  }
}*/
void print()//Adjust the formatting for printing in tabular format
{
  FILE *fs;
  fs=fopen("ReservDetails.txt","r");
  printf("\nRoom number\tName\tNo of People\tAddress\tEmail-ID\tCheck-In\tCheck-Out\t\n");
  int i;
  for(i=0;i<=150;i++)
  {
    printf("-");
  }
  printf("\n");
  if(fs==NULL)
  {
    printf("\nNo Records Added..!!");
  }
  else
  {
    while(!feof(fs))
    { 
      fscanf(fs," %d %s %d %s %s %d %d %d %d",&s.room_number,s.name,&s.no_of_people,s.add,s.email,&s.start_dd,&s.start_mm,&s.end_dd,&s.end_mm);
      printf("%d\t%-22s\t%d\t%-12s\t%-12s\t%d/%d\t%d/%d\n",s.room_number,s.name,s.no_of_people,s.add,s.email,s.start_dd,s.start_mm,s.end_dd,s.end_mm);
      for(i=0;i<=150;i++)
      {
        printf("-");
      }
    printf("\n");
    }
  }
  fclose(fs);
  printf("\nPress any key to return to menu");
  getch();
}
void delete()
{
  FILE *o,*t;
  int i,room_number,found=0;
  o=fopen("ReservDetails.txt","r");
  t=fopen("temp.txt","w");
  if(o==NULL)
  {
    printf("\nNo records added..");
    printf("\nPress any key to return to menu");
    getch();
    menu();
  }
  else
  {
    printf("\nEnter the room number of the record you want to delete");
    scanf("%d",&room_number);
    while((fscanf(o," %d %s %d %s %s %d %d %d %d",&s.room_number,s.name,&s.no_of_people,s.add,s.email,&s.start_dd,&s.start_mm,&s.end_dd,&s.end_mm))!=EOF)
    {
      if(room_number!=s.room_number)
      {
        fprintf(t,"\n %d %s %d %s %s %d %d %d %d",s.room_number,s.name,s.no_of_people,s.add,s.email,s.start_dd,s.start_mm,s.end_dd,s.end_mm);
      }
      else
      {
        found=1;
      } 
    }
    if(found==0)
    {
      printf("\nNo such record found");
    }
    else
    {
      printf("\nRecord deleted successfully..!!");
    }
    fclose(o);
    fclose(t);
    if(remove("ReservDetails.txt")!=0)
    {
      printf("\nUnable to delete file");
    }
    else
    {
      printf("\nDeleted successfully");//Do something here
    }
    if(rename("temp.txt","ReservDetails.txt")!=0)
    {
      printf("\nUnable to rename");
    }
    else
    {
      printf("\nRenamed successfully");//Do something here
    }
  }
}




      
       
 
  
       

    
