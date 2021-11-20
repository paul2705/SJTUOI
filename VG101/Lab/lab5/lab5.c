#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

void LOAD(char *remain,Database *D)
{ 
    FILE *fp;
    char str[1000];
    fp=fopen(remain,"r");
    D->tableNum+=1;
    if (fgets(D->tables[D->tableNum].name,MAX_NAME,fp)==NULL)
    {
        printf("LOAD: unsucess\n");
        return;
    }
    D->tables[D->tableNum].name[strlen(D->tables[D->tableNum].name)-1]='\0';
    //printf("Name: %s\n",D->tables[D->tableNum].name);
    while(fgets(str, 1000, fp) != NULL)
    {
        D->tables[D->tableNum].assignNum+=1;
        int tmp=D->tables[D->tableNum].assignNum;
        strcpy(D->tables[D->tableNum].assignments[tmp].course,strtok(str," "));
        strcpy(D->tables[D->tableNum].assignments[tmp].name,strtok(NULL," "));
        D->tables[D->tableNum].assignments[tmp].deadline=atoi(strtok(NULL," "));
        D->tables[D->tableNum].assignments[tmp].difficulty=atoi(strtok(NULL," "));
    }
    printf("LOAD: success\n");
    fclose(fp);
}

void SAVE(char *remain,Database *D)
{
    FILE *fp;
    char tablename[MAX_NAME];
    char filename[1000];
    strcpy(tablename,strtok(remain," "));
    strcpy(filename,strtok(NULL,""));
    fp=fopen(filename,"w+");
    for (int i=1;i<=D->tableNum;i++)
    {
        if (strcmp(D->tables[i].name,tablename)==0)
        {
            fprintf(fp,"%s\n",D->tables[i].name);
            for (int k=1;k<D->tables[i].assignNum;k++)
            {
                for (int j=1;j<D->tables[i].assignNum;j++)
                {
                    if (D->tables[i].assignments[j].deadline > D->tables[i].assignments[j+1].deadline) 
                    {
                        Assignment tmp;
                        tmp=D->tables[i].assignments[j];
                        D->tables[i].assignments[j]=D->tables[i].assignments[j+1];
                        D->tables[i].assignments[j+1]=tmp;
                    }
                }
            }

            for (int j=1;j<=D->tables[i].assignNum;j++)
            {
                fprintf(fp,"%s %s %d %d",D->tables[i].assignments[j].course,D->tables[i].assignments[j].name,D->tables[i].assignments[j].deadline,D->tables[i].assignments[j].difficulty);
                fprintf(fp,"\n");
            }
        }
    }
    printf("SAVE: success\n");
    fclose(fp);
}

void PRINT(char *remain,Database *D)
{
    for (int i=1;i<=D->tableNum;i++)
    {
        if (strcmp(D->tables[i].name,remain)==0)
        {
            printf("%s\n",D->tables[i].name);
            printf("course name deadline difficulty\n");
            for (int j=1;j<=D->tables[i].assignNum;j++)
            {
                printf("%s %s %d %d",D->tables[i].assignments[j].course,D->tables[i].assignments[j].name,D->tables[i].assignments[j].deadline,D->tables[i].assignments[j].difficulty);
                printf("\n");
            }
        }
    }
}

void LIST(Database *D)
{
    for (int i=1;i<=D->tableNum;i++)
    {
        printf("%s\n",D->tables[i].name);
    }
}   

void INSERT(char *remain,Database *D)
{
    char coursename[MAX_NAME];
    char taskname[MAX_NAME]; 
    int tmpdeadline;
    int tmpdifficulty;
    char filename[1000];
    strtok(remain," ");
    strcpy(coursename,strtok(NULL," "));
    strcpy(taskname,strtok(NULL," "));
    tmpdeadline=atoi(strtok(NULL," "));
    tmpdifficulty=atoi(strtok(NULL," "));
    strtok(NULL," ");
    strcpy(filename,strtok(NULL," "));
    for (int i=1;i<=D->tableNum;i++)
    {
        if (strcmp(D->tables[i].name,filename)==0)
        {
            int tmp=++D->tables[i].assignNum;
            strcpy(D->tables[i].assignments[tmp].course,coursename);
            strcpy(D->tables[i].assignments[tmp].name,taskname);
            D->tables[i].assignments[tmp].deadline=tmpdeadline;
            D->tables[i].assignments[tmp].difficulty=tmpdifficulty;
        }
    }
    printf("INSERT: success\n");
}

void UPDATE(char *remain,Database *D)
{
    char fieldname[20];
    int newvalue,cnt=0;
    char tablename[MAX_NAME];
    char coursename[MAX_NAME];
    char taskname[MAX_NAME];
    char star[]="*";
    char Deadline[]="deadline";
    char Difficulty[]="difficulty";
    strtok(remain," ");
    strcpy(fieldname,strtok(NULL," "));
    newvalue=atoi(strtok(NULL," "));
    strtok(NULL," ");
    strcpy(tablename,strtok(NULL," "));
    strtok(NULL," ");
    strcpy(coursename,strtok(NULL," "));
    strcpy(taskname,strtok(NULL," "));
    for (int i=1;i<=D->tableNum;i++)
    {
        if (strcmp(D->tables[i].name,tablename)==0)
        {
            for (int j=1;j<=D->tables[i].assignNum;j++)
            {
                if (strcmp(coursename,star)==0)
                {
                    if (strcmp(taskname,star)==0)
                    {
                        if (strcmp(fieldname,Deadline)==0) 
                        D->tables[i].assignments[j].deadline=newvalue;
                        if (strcmp(fieldname,Difficulty)==0) 
                        D->tables[i].assignments[j].difficulty=newvalue;
                        cnt++;
                    }
                    if (strcmp(taskname,D->tables[i].assignments[j].name)==0)
                    {
                        if (strcmp(fieldname,Deadline)==0) 
                        D->tables[i].assignments[j].deadline=newvalue;
                        if (strcmp(fieldname,Difficulty)==0) 
                        D->tables[i].assignments[j].difficulty=newvalue;
                        cnt++;
                    }
                }
                if (strcmp(D->tables[i].assignments[j].course,coursename)==0)
                {
                    if (strcmp(taskname,star)==0)
                    {
                        if (strcmp(fieldname,Deadline)==0) 
                        D->tables[i].assignments[j].deadline=newvalue;
                        if (strcmp(fieldname,Difficulty)==0) 
                        D->tables[i].assignments[j].difficulty=newvalue;
                        cnt++;
                    }
                    if (strcmp(taskname,D->tables[i].assignments[j].name)==0)
                    {
                        if (strcmp(fieldname,Deadline)==0) 
                        D->tables[i].assignments[j].deadline=newvalue;
                        if (strcmp(fieldname,Difficulty)==0) 
                        D->tables[i].assignments[j].difficulty=newvalue;
                        cnt++;
                    }
                }
            }
        }
    }    
    printf("UPDATE: update %d records\n",cnt);
}

void DELETE(char *remain,Database *D)
{
    char tablename[MAX_NAME];
    char coursename[MAX_NAME];
    char taskname[MAX_NAME];
    char star[]="*";
    strcpy(tablename,strtok(remain," "));
    strtok(NULL," ");
    strcpy(coursename,strtok(NULL," "));
    strcpy(taskname,strtok(NULL," "));
    for (int i=1;i<=D->tableNum;i++)
    {
        if (strcmp(D->tables[i].name,tablename)==0)
        {
            for (int j=1;j<=D->tables[i].assignNum;j++)
            {
                if (strcmp(coursename,star)==0)
                {
                    if (strcmp(taskname,star)==0)
                    {
                        //strcpy(D->tables[i].assignments[j]
                    }
                }
            }
        }
    }
}

int main()
{ 
    Database database={.tableNum=0};
    Table table={.assignNum=0,.name={0}};
    Assignment assignment={.course={0},.name={0},.deadline=0,.difficulty=0};
    while (1)
    {
        //初始化struct
        char strin[100];
        char strload[]="LOAD";
        char strsave[]="SAVE";
        char strprint[]="PRINT";
        char strlist[]="LIST";
        char strinsert[]="INSERT";
        char strupdate[]="UPDATE";
        char strdelete[]="DELETE";
        char strselect[]="SELECT";
        char strauto[]="AUTO";
        char exit[]="EXIT";
        gets(strin);
        char *command;
        char *remain;
        command=strtok(strin," ");
        remain=strtok(NULL,"");
        //分开输入的命令
        if (strcmp(command,strload)==0) LOAD(remain,&database);
        if (strcmp(command,strsave)==0) SAVE(remain,&database);
        if (strcmp(command,strprint)==0) PRINT(remain,&database);
        if (strcmp(command,strlist)==0) LIST(&database);
        if (strcmp(command,strinsert)==0) INSERT(remain,&database);
        if (strcmp(command,strupdate)==0) UPDATE(remain,&database);
        if (strcmp(command,strdelete)==0) DELETE(remain,&database);
        if (strcmp(command,exit)==0)
        {
            printf("Exit the Deadline Database! Hope you have already conquered all deadlines!\n");
            break;
        }
    }
    system("pause");
    return 0;
}
