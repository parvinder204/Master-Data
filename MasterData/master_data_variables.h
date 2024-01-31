#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student
{
    char stuID[15];
    char fname[20];
    char lname[20];
    char email1[40];
    int age;
    long int phone;
} Student;

FILE *fp;
Student stu;
char fileName[]="StudentRecord.txt";
char tempFileName[]="temp.txt";


void first()
{
    printf("Student Master Data loading......................\n\n");
    printf("\t\tWELCOME TO STUDENT MASTER DATA INFORMATION SYSTEM\n");
    getch();
}

char file()
{
    char i;
    printf("\nMAIN MENU");
    printf("\n\t1 >> ADD NEW STUDENT RECORD.");
    printf("\n\t2 >> LIST RECORDS OF ALL STUDENT.");
    printf("\n\t3 >> SEARCH A PARTICULR STUDENT.");
    printf("\n\t4 >> UPDATE PREVIOUS RECORD OF A STUDENT.");
    printf("\n\t5 >> DELETE RECORD OF A STUDENT.");
    printf("\n\t6 >> EXIT STSTEM.");
    printf("\n\n\tENTER YOUR CHOICE: ");
    i=getch();
    return (i);
}