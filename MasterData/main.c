#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


#include "master_data_function.h"

void main()
{
    char ch='a';
    //clrscr();
    first();
    fp=fopen(fileName,"rb+");
    if(fp==NULL)
    {
        fp=fopen( fileName,"wb+");
        if(fp==NULL)
        {
            printf("Can't Open File");
            exit(0);
        }
    }
    while(ch!='6')
    {
        ch=file();
        switch(ch)
        {
            case '1':
                AddStudentRecord();
                break;
            case '2':
                ListStudentRecord();
                break;
            case '3':
                SearchStudentRecord();
                break;
            case '4':   
                UpdateStudentRecord();
                break;
            case '5':   
                DeleteStudentRecord();
                break;
            case '6':
                exit(0);
                break;
            default:
                printf("WRONG CHOICE!!!");
            getch();
            break;
        }   
    }
}

