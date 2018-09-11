#include<stdio.h>
#include<conio.h>
void main()
{
    FILE *fp;
    fp=fopen("Newtest.txt","w+");
    fprintf(fp,"This file has to be deleted");
    fclose(fp);
    if(remove("E:/Vinayak/Impor/College/SE/DS/Mini Project/ReservDetails.txt")!=0)
    {
        printf("\nError cannot delete file");
    }
    else
    {
        printf("\nFile deleted successfully");
    }
    getch();
}