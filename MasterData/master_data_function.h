#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#include "master_data_variables.h"


void AddStudentRecord()
{
    char another,ch;
    do
    {
        //clrscr();
        fseek(fp,0,SEEK_END);
        another='Y';
        printf("\n\nADD NEW STUDENT RECORD");
        printf("\n\t1. ENTER STUDENT ID: ");
        gets(stu.stuID);
        printf("\t2. ENTER FIRST NAME : ");
        gets(stu.fname);
        printf("\t3. ENTER LAST NAME : ");
        gets(stu.lname);
        printf("\t4. ENTER MAIL : ");
        gets(stu.email1);
        printf("\t5. ENTER AGE : ");
        scanf("%d",&stu.age);
        printf("\t6. ENTER PHONE NUMBER :");
        scanf("%ld",&stu.phone);
        printf("\n\n\tSAVE CHANGE (y/n)?");

        ch=getch();
        if(ch=='y'||ch=='Y')
        {
            fwrite(&stu,sizeof(stu),1,fp);
            fflush(stdin);
        }
        printf("\n\nADD ANOTHER Student(Y/N)? ");
        fflush(stdin);
        another=getch();
        fflush(stdin);
    }
    while(another=='Y'|| another=='y');
}


void ListStudentRecord()
{
    int i;
    fseek(fp,0,SEEK_SET);
    printf("\n\tLIST OF STUDENT RECORD\n\n");
    printf("\nSTUDENT ID");
    printf("\tFIRST NAME");
    printf("\tLAST NAME");
    printf("\tMAIL");
    printf("\t\t\tAGE");
    printf("\tPHONE");
    printf("\n");
    for(i=1;i<=90;i++)
    {
        printf("-");
    }
    printf("\n");
    i=4;
    while(fread(&stu,sizeof(stu),1,fp)==1)
    {
        printf("%s",stu.stuID);
        printf("\t\t%s",stu.fname);
        printf("\t\t%s",stu.lname);
        printf("\t\t%s",stu.email1);
        printf("\t\t%8d",stu.age);
        printf("\t%ld",stu.phone);
        printf("\n");
        i++;
    }
    getch();
}



void SearchStudentRecord()
{
    int i,datafound=0;
    char studentId[15];
    char another,ch;
    do
    {
        //clrscr();
        fseek(fp,0,SEEK_SET);
        printf("\n\tSEARCH STUDENT RECORD");
        printf("\nENTER STUDENT ID: ");
        gets(studentId);
        while(fread(&stu,sizeof(stu),1,fp)==1)
        {
            if(strcmp(stu.stuID,studentId)==0)
            {
                 datafound=1;
                 break;
            }
        }
        if(datafound==1)
        {
            printf("\n\tRECORD OF STUDENT");
            printf("——————–");
            printf("\nSTUDENT ID :");
            printf("%s",stu.stuID);
            printf("\nFIRST NAME :");
            printf("%s",stu.fname);
            printf("\nLAST NAME :");
            printf("%s",stu.lname);
            printf("\nMAIL :");
            printf("%s",stu.email1);
            printf("\nAGE :");
            printf("%d",stu.age);
            printf("\nPHONE :");
            printf("%ld",stu.phone);
        }
        else
        {
            printf("\nRECORD NOT FOUND!!!!!");
        }
        printf("\n\n\tSEARCH ANOTHER STUDENT (Y/N)?");
        fflush(stdin);
        another=getch();
        fflush(stdin);
        }
    while(another=='Y'|| another=='y');
}




void UpdateStudentRecord()
{
    int i, datafound=0,recordNo=0;
    char studentId[15];
    char another,ch;
    do
    {
        //clrscr();
        fseek(fp,0,SEEK_SET);
        rewind(fp);
        printf("\n\tUPDATE STUDENT RECORD");
        printf("\nENTER STUDENT ID TO BE UPDATES:");
        gets(studentId);
        while(fread(&stu,sizeof(stu),1,fp)==1)
        {
            if(strcmp(stu.stuID,studentId)==0)
            {
                datafound=1;
                break;
            }
            recordNo++;
        }
        if(datafound==1)
        {
            printf("\n\tOLD RECORD IS:");
            printf("\nSTUDENT ID :");
            printf("%s",stu.stuID);
            printf("\nFIRST NAME :");
            printf("%s",stu.fname);
            printf("\nLAST NAME :");
            printf("%s",stu.lname);
            printf("\nMAIL :");
            printf("%s",stu.email1);
            printf("\nAGE :");
            printf("%d",stu.age);
            printf("\nPHONE :");
            printf("%ld",stu.phone);
            printf("\n\tENTER NEW UPDATION RECORD :");
            printf("STUDENT ID:");
            gets(stu.stuID);
            printf("FIRST NAME :");
            gets(stu.fname);
            printf("LAST NAME :");
            gets(stu.lname);
            printf("MAIL :");
            gets(stu.email1);
            printf("AGE :");
            scanf("%d",&stu.age);
            printf("MAIL :");
            gets(stu.email1);
            printf("PHONE :");
            scanf("%ld",&stu.phone);
            fseek(fp,sizeof(stu)*(recordNo),SEEK_SET);
            if(fwrite(&stu,sizeof(stu),1,fp)==1)
                printf("\n\tTHE RECORD HAS BEEN UPDATED SUCCESSFULLY!!!!!");
            else
                printf("\n\tERORR DURING UPDATION!!!!!");
        }
        else
        {
            printf("\n\tRECORD NOT FOUND!!!!!");
        }
        printf("\n\n\tUPDATE ANOTHER STUDENT RECORD(Y/N)?");
        fflush(stdin);
        another=getch();
        fflush(stdin);
    }
    while(another=='Y'||another=='y');
}




void DeleteStudentRecord()
{
    int i,datafound=0;
    char studentId[15];
    FILE *fpTemp;
    char another,ch;
    do
    {
        //clrscr();
        fseek(fp,0,SEEK_SET);
        rewind(fp);
        printf("\n\tDELETE STUDENT RECORD");
        printf("\nENTER stuLOYEE ID TO BE DELETED: ");
        gets(studentId);
        while(fread(&stu,sizeof(stu),1,fp)==1)
        {
            if(strcmp(stu.stuID,studentId)==0)
            {
                datafound=1;
                break;
            }
        }
        if(datafound==1)
        {
            fpTemp=fopen(tempFileName,"wb");
            rewind(fp);
            while(fread(&stu,sizeof(stu),1,fp)==1)
            {
                if(strcmp(stu.stuID,studentId)!=0)
                fwrite(&stu,sizeof(stu),1,fpTemp);
            }
            fclose(fp);
            fclose(fpTemp);
            remove(fileName);
            rename(tempFileName,fileName);
            fp=fopen(fileName,"rb+");
            printf("RECORD SUCCESSFULLY DELETED!!!!!");
        }
        else
        {
            printf("RECORD NOT FOUND!!!!!");
        }
        printf("DELETE ANOTHER STUDENT RECORD(Y/N)?");
        fflush(stdin);
        another=getch();
        fflush(stdin);
    }
    while(another=='Y'|| another=='y');
}

