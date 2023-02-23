#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

struct PATIENT
{
    char name[100];
    int age;    
    char bloodgrp[5];
    char gender[10];
    char phonenumber[20];
    char disease[100];
    struct PATIENT *next;
};

struct PATIENT *a[26];
int flag = 0;
FILE *ptr = NULL; //for check in check out
FILE *P=NULL;     //for record
FILE *P1=NULL;    //for modifyrecord

struct PATIENT *createnode()
{
    int t=1;
    struct PATIENT *newnode = (struct PATIENT *)malloc(sizeof(struct PATIENT));

    printf("\t\t\t\t\t\t\t\tENTER THE NAME STARTS WITH 'A' TO 'Z' OR 'a' TO 'z'\n");
    printf("\t\t\t\t\t\t\t\tENTER PATIENT NAME          : ");
    scanf("%s", newnode->name);
    do {
    printf("\t\t\t\t\t\t\t\tENTER PATIENT AGE           : ");
    scanf("%d", &newnode->age);
    if(newnode->age>100)
    {
    printf("\t\t\t\t\t\t\t\tRenter the age less than 100\n");
    }
    else
    {
    t=0;
    }
   }while(t);

    printf("\t\t\t\t\t\t\t\tENTER PATIENT BLOODGRP      : ");
    scanf("%s", newnode->bloodgrp);
    printf("\t\t\t\t\t\t\t\tENTER PATIENT GENDER        : ");
    scanf("%s", newnode->gender);
    printf("\t\t\t\t\t\t\t\tENTER PATIENT PHONENUMBER   : ");
    scanf("%s", newnode->phonenumber);
    printf("\t\t\t\t\t\t\t\tENTER PATIENT DISEASE       : ");
    scanf("%s", newnode->disease);
    newnode->next = NULL;
    printf("\n\n");
   
    return newnode;
}

int Hash(char c){
    if(c>='A' && c<='Z'){
        return (c-'A');
    }
    else{
        return (c-'a');
    }
}

void Insert()
{
    char arr[100];
    flag++;
    struct PATIENT *temp = createnode();
    int y = Hash(temp->name[0]);

    if (a[y] == NULL)//for print patient in sorting order in in a to z
    {
        timeinfo(temp->name, 1);
        a[y] = temp;
        P = fopen("record.txt", "a");
        sprintf(arr,"%s %d %s %s %s %s 1\n",temp->name,temp->age,temp->bloodgrp,temp->gender,temp->phonenumber,temp->disease);
        fputs(arr,P);
        fclose(P);
    }
    else
    {
        struct PATIENT *p = a[y], *q = NULL;
        if (strcmp(temp->name, p->name) < 0)
        {
            timeinfo(temp->name, 1);
            P = fopen("record.txt", "a");
            sprintf(arr,"%s %d %s %s %s %s 1\n",temp->name,temp->age,temp->bloodgrp,temp->gender,temp->phonenumber,temp->disease);
            fputs(arr,P);
            fclose(P);
            a[y] = temp;
            a[y]->next = p;
        }
        else
        {
            while (p && strcmp(temp->name, p->name) >= 0)
            {
                if(strcmp(temp->name,p->name) == 0){
                    printf("\t\t\t\t\t\t\t\tNAME IS ALREADY EXIST , PLZ ENTER ANOTHER NAME\n\n");
                    flag--;
                    return ;
                }
                else{
                    q = p;
                    p = p->next;
                }
            }
            timeinfo(temp->name, 1);
            P = fopen("record.txt", "a");
            sprintf(arr,"%s %d %s %s %s %s 1\n",temp->name,temp->age,temp->bloodgrp,temp->gender,temp->phonenumber,temp->disease);
            fputs(arr,P);
            q->next = temp;
            temp->next = p;
        }
    }
}

void Modify()// for modify the patient history in it.
{
    char arr[100];
    if (flag == 0)
    {
        printf("\t\t\t\t\t\t\t\tRECORD IS EMPTY\n\n");
    }
    else
    {
        char string[100];
        printf("\n\t\t\t\t\t\t\t\tENTER THE NAME OF PATIENT: ");
        scanf("%s", string);
        struct PATIENT *temp = a[Hash(string[0])];

        while (temp && strcmp(string, temp->name) >= 0)
        {
            if (strcmp(string, temp->name) == 0)
            {
                int n;

                P1 = fopen("modifyrecord.txt", "a");
                sprintf(arr,"%s %d %s %s %s %s \n",temp->name,temp->age,temp->bloodgrp,temp->gender,temp->phonenumber,temp->disease);
                fputs(arr,P1);
                fclose(P1);

                printf("\t\t\t\t\t\t\t\tFOR MODIFYING ENTER 1 ELSE ENTER 2\n\n");
                printf("\t\t\t\t\t\t\t\tMODIFY PATIENT AGE              ");
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("\t\t\t\t\t\t\t\tREWRITE PATIENT AGE           : ");
                    scanf("%d", &temp->age);
                }
                printf("\t\t\t\t\t\t\t\tMODIFY PATIENT BLOODGRP         ");
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("\t\t\t\t\t\t\t\tREWRITE PATIENT BLOODGRP      : ");
                    scanf("%s", temp->bloodgrp);
                }
                printf("\t\t\t\t\t\t\t\tMODIFY PATIENT GENDER           ");
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("\t\t\t\t\t\t\t\tREWRITE PATIENT GENDER        : ");
                    scanf("%s", temp->gender);
                }
                printf("\t\t\t\t\t\t\t\tMODIFY PATIENT PHONENUMBER      ");
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("\t\t\t\t\t\t\t\tREWRITE PATIENT PHONENUMBER   : ");
                    scanf("%s", temp->phonenumber);
                }   
                printf("\t\t\t\t\t\t\t\tMODIFY PATIENT DISEASE      ");
                scanf("%d", &n);
                if (n == 1)
                {
                printf("\t\t\t\t\t\t\t\tREWRITE PATIENT DISEASE          : ");
                scanf("%s", temp->disease);
                }

                P1 = fopen("modifyrecord.txt", "a");
                sprintf(arr,"%s %d %s %s %s %s \n",temp->name,temp->age,temp->bloodgrp,temp->gender,temp->phonenumber,temp->disease);
                fputs(arr,P1);
                fclose(P1);
                printf("\n\n");
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        printf("\t\t\t\t\t\t\t\tPATIENT IS NOT FOUND\n\n");
    }
}

void Delete()
{
    char arr[100];
    if (flag == 0)
    {
        printf("\t\t\t\t\t\t\t\tRECORD IS EMPTY\n\n");
    }
    else
    {
        char string[100];
        printf("\t\t\t\t\t\t\t\tENTER THE PATIENT NAME FOR DELETION IN RECORD : ");
        scanf("%s", string);
        int o=Hash(string[0]);
        struct PATIENT *p = a[o], *q = NULL;
        if (p && strcmp(string, p->name) == 0)
        {   
            flag--;
            timeinfo(string,0);
            a[o]=a[o]->next;
            printf("\t\t\t\t\t\t\t\tSUCCESFULLY DELETED\n\n");
            P = fopen("record.txt", "a");
            sprintf(arr,"%s %d %s %s %s %s 0\n",p->name,p->age,p->bloodgrp,p->gender,p->phonenumber,p->disease);
            fputs(arr,P);
            fclose(P);
            free(p);
            return ;
        }
        else
        {
            while (p && strcmp(string, p->name) >= 0)
            {
                if (strcmp(string, p->name) == 0)
                {
                    flag--;
                    timeinfo(string,0);
                    q->next=p->next;
                    printf("\t\t\t\t\t\t\t\tSUCCESFULLY DELETED\n\n");
                    P = fopen("record.txt", "a");
                    sprintf(arr,"%s %d %s %s %s %s 0\n",p->name,p->age,p->bloodgrp,p->gender,p->phonenumber,p->disease);
                    fputs(arr,P);
                    fclose(P);
                    free(p);
                    return;
                }
                else
                {
                    q=p;
                    p = p->next;
                }
            }
        }
        printf("\t\t\t\t\t\t\t\tPATIENT IS NOT FOUND\n\n");
    }
}

void Search()
{
    char string[100];
    printf("\t\t\t\t\t\t\t\tENTER THE NAME YOU WANT TO SEARCH : ");
    scanf("%s", string);

    if (flag == 0)
    {
        printf("\t\t\t\t\t\t\t\tRECORD IS EMPTY\n\n");
    }
    else
    {
        struct PATIENT *temp = a[Hash(string[0])];
        while (temp && strcmp(string, temp->name) >= 0)
        {
            if (strcmp(string, temp->name) == 0)
            {
                printf("\n\t\t\t\t\t\t\t\tYOUR PATIENT DETAILS : \n");
                printf("\t\t\t\t\t\t\t\tPATIENT NAME          : ");
                puts(temp->name);
                printf("\t\t\t\t\t\t\t\tPATIENT AGE           : ");
                printf("%d\n", temp->age);
                printf("\t\t\t\t\t\t\t\tPATIENT BLOODGRP      : ");
                puts(temp->bloodgrp);
                printf("\t\t\t\t\t\t\t\tPATIENT GENDER        : ");
                puts(temp->gender);
                printf("\t\t\t\t\t\t\t\tPATIENT PHONENUMBER   : ");
                printf("%s\n", temp->phonenumber);
                printf("\t\t\t\t\t\t\t\tPATIENT DISEAES       : ");
                printf("%s\n", temp->disease);
                printf("\n");
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        printf("\t\t\t\t\t\t\t\tPATIENT IS NOT FOUND\n\n");
    }
}

void Display()
{
    if (flag == 0)
    {
        printf("\t\t\t\t\t\t\t\tRECORD IS EMPTY\n");
    }
    else
    {
        int k = 0;
        struct PATIENT *temp = NULL;
        int cnt = 1;
        for (int i = 0; i < 26; i++)
        {
            if (a[i])
            {
                temp = a[i];
                while (temp)
                {
  
                    printf("\n\t\t\t\t\t\t\t\tFOR PATIENT %d -->\n", cnt);
                    cnt++;
                    printf("\t\t\t\t\t\t\t\tPATIENT NAME          : ");
                    puts(temp->name);
                    printf("\t\t\t\t\t\t\t\tPATIENT AGE           : ");
                    printf("%d\n", temp->age);
                    printf("\t\t\t\t\t\t\t\tPATIENT BLOODGRP      : ");
                    puts(temp->bloodgrp);
                    printf("\t\t\t\t\t\t\t\tPATIENT GENDER        : ");
                    puts(temp->gender);
                    printf("\t\t\t\t\t\t\t\tPATIENT PHONENUMBER   : ");
                    printf("%s\n", temp->phonenumber);
                    printf("\t\t\t\t\t\t\t\tPATIENT DISEAES       : ");
                    printf("%s\n", temp->disease);
    
                    temp = temp->next;
                }
            }
        }
    }printf("\n");
}

void timeinfo(char string[], int flag)
{
    char first[50], second[50];
    time_t rawtime;
    struct tm *local;

    time(&rawtime);
    local = localtime(&rawtime);
    int hours, minutes, seconds, day, month, year;
    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;

    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;
    //   printf ("%s", asctime (timeinfo));
    if (hours < 12)
    {
        sprintf(first, "%s\t\t\t%02d:%02d:%02dam", string, hours, minutes, seconds);
        fputs(first, ptr);
    }
    else if (hours == 12)
    {
        sprintf(first, "%s\t\t\t%02d:%02d:%02dpm", string, hours, minutes, seconds);
        fputs(first, ptr);
    }
    else
    {
        sprintf(first, "%s\t\t\t%02d:%02d:%02dpm", string, hours - 12, minutes, seconds);
        fputs(first, ptr);
    }
    if (flag == 1)
    {
        sprintf(second, "\t\t%02d/%02d/%d\t\t\tCHECK-IN\n", day, month, year);
    }
    else
    {
        sprintf(second, "\t\t%02d/%02d/%d\t\t\tCHECK-OUT\n", day, month, year);
    }
    fputs(second, ptr);
}

int recordgetline(){
    FILE *op=NULL;
    op=fopen("record.txt","r");
    int line=0;
    char c=fgetc(op);
    while(c!=EOF){
        if(c == '\n'){
            line++;
        }
        c=fgetc(op);
    }
    fclose(op);
    return line;
}

int modifyrecordgetline(){
    FILE *op=NULL;
    op=fopen("modifyrecord.txt","r");
    int line=0;
    char c=fgetc(op);
    while(c!=EOF){
        if(c == '\n'){
            line++;
        }
        c=fgetc(op);
    }
    fclose(op);
    return line;    
}

void restoredata(){
    char str[100];
    char namef[100];
    int agef;
    char bloodgrpf[5];
    char genderf[10];
    char phonenumberf[20];
    char diseasef[100];
    int flg;

    P=fopen("record.txt","r");
    if(P != NULL){
        int line=recordgetline();
        for(int i=1;i<=line;i++){
            fgets(str,100,P);
            sscanf(str,"%s %d %s %s %s %s %d",namef,&agef,bloodgrpf,genderf,phonenumberf,diseasef,&flg);
            if(flg == 1){
                //insertion
                struct PATIENT *temp = (struct PATIENT *)malloc(sizeof(struct PATIENT));
                strcpy(temp->name,namef);
                temp->age=agef;
                strcpy(temp->bloodgrp,bloodgrpf);
                strcpy(temp->gender,genderf);
                strcpy(temp->phonenumber,phonenumberf);
                strcpy(temp->disease,diseasef);
                int y = Hash(temp->name[0]);

                flag++;
                if (a[y] == NULL)
                {
                    a[y] = temp;
                }
                else
                {
                    struct PATIENT *p = a[y], *q = NULL;
                    if (strcmp(temp->name, p->name) < 0)
                    {
                        a[y] = temp;
                        a[y]->next = p;
                    }
                    else
                    {
                        while (p && strcmp(temp->name, p->name) >= 0)
                        {
                            q = p;
                            p = p->next;
                        }
                        q->next = temp;
                        temp->next = p;
                    }
                }
            }
            else if(flg == 0){
                //deletion
                flag--;

                int o=Hash(namef[0]);
                struct PATIENT *p = a[o], *q = NULL;
                if (p && strcmp(namef, p->name) == 0)
                {   
                    a[o]=a[o]->next;
                }
                else
                {
                    while (p && strcmp(namef, p->name) >= 0)
                    {
                        if (strcmp(namef, p->name) == 0)
                        {
                            q->next=p->next;
                            free(p);
                            break;
                        }
                        else
                        {
                            q=p;
                            p = p->next;
                        }
                    }
                }
            }
        }
    }
    fclose(P);
}

void restoredatamodify(){
    char str1[100];
    char name1[100];
    int age1;
    char bloodgrp1[5];
    char gender1[10];
    char phonenumber1[20];
    char disease1[100];

    char str2[100];
    char name2[100];
    int age2;
    char bloodgrp2[5];
    char gender2[10];
    char phonenumber2[20];
    char disease2[100];

    P1=fopen("modifyrecord.txt","r");
    if(P1!=NULL){
        int line = modifyrecordgetline();
        for(int i=1;i<=line;i+=2){
            fgets(str1,100,P1);
            sscanf(str1,"%s %d %s %s %s %s ",name1,&age1,bloodgrp1,gender1,phonenumber1,disease1);
            fgets(str2,100,P1);
            sscanf(str2,"%s %d %s %s %s %s ",name2,&age2,bloodgrp2,gender2,phonenumber2,disease2);

        struct PATIENT *temp = a[Hash(name1[0])];
        while (temp && strcmp(name1, temp->name) >= 0)
        {
            if (strcmp(name1, temp->name) == 0)
            {
                strcpy(temp->name,name2);
                temp->age=age2;
                strcpy(temp->bloodgrp,bloodgrp2);
                strcpy(temp->gender,gender2);
                strcpy(temp->phonenumber,phonenumber2);
                strcpy(temp->disease,disease2);
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        }
    }
    fclose(P1);
}

int main()
{
    for (int i = 0; i < 26; i++)
    {
        a[i] = NULL;
    }

    restoredata();
    restoredatamodify();

    int n, t = 1;
    while (t)
    {
        printf("\t\t\t\t\t\t\t\t/*************HOSPITAL MANAGEMENT SYSTEM***********/\n");

        printf("\n");
        printf("\t\t\t\t\t\t\t\t1.INSERT  PATIENT RECORD\n");
        printf("\t\t\t\t\t\t\t\t2.MODIFY  PATIENT RECORD\n");
        printf("\t\t\t\t\t\t\t\t3.DELETE  PATIENT RECORD\n");
        printf("\t\t\t\t\t\t\t\t4.SEARCH  PATIENT RECORD\n");
        printf("\t\t\t\t\t\t\t\t5.DISPLAY PATIENT RECORD\n");
        printf("\t\t\t\t\t\t\t\t6.FOR TERMINATION\n\n");

        printf("\n");
        
        printf("\t\t\t\t\t\t\t\tENTER CHOICE : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            ptr = fopen("checkin-checkout.txt", "a");
            Insert();
            fclose(ptr);
            break;

        case 2:
            Modify();
            break;

        case 3:
            ptr = fopen("checkin-checkout.txt", "a");
            Delete();
            fclose(ptr);
            break;

        case 4:
            Search();
            break;

        case 5:
            Display();
            break;

        case 6:
            t = 0;
            break;

        default:
            break;
        }
    }
    return 0;
}