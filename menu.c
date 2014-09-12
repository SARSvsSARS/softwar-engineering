/**************************************************************************************************/
/* Copyright (C)             ZK@USTC, 2014-2015                                                   */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  ZhangKun                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/10                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by ZhangKun, 2014/09/10
 *
 */


#include <stdio.h>
#include <stdlib.h>

#define DESC_LEN    1024
#define CMD_MAX_LEN    128
#define CMD_LEN    10

void Init();
void SelectCmd(char * cmd);

typedef struct DataNode
{
    char    cmd_num[CMD_LEN];
    char    cmd_sig[CMD_LEN];
    char    desc[DESC_LEN];
    struct  DataNode *next;
} tDataNode;

char * list_num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
char * list_sig[10]={"zero","first","second","third","fourth","fifth","sixth","seventh","eighth","ninth"};
tDataNode *head = NULL; 
tDataNode * p = NULL;

int main()
{   
    Init();
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd string > ");
        scanf("%s", cmd);
        SelectCmd(cmd);
    }
}

void Init()
{ 
    /* Init cmd list */
    int i;
    for (i=0; i<CMD_LEN; i++)
    {
        printf("%s\t",list_num[i]);
        p = (tDataNode*)malloc(sizeof(tDataNode));
        snprintf(p->cmd_num, CMD_LEN, "%s", list_num[i]);
        snprintf(p->desc, DESC_LEN, "This is %s cmd!", list_sig[i]);
        p->next = head;
        head = p;
    }
    printf("\nMenu List:\n");
    p = head;
    while(p != NULL)
    {
        printf("%s\t:    %s\n", p->cmd_num, p->desc);
        p = p->next;
    }
}

void SelectCmd(char * cmd)
{
    /* Select cmd string */
    p = head;
    while(p != NULL)
    {
        if(strcmp(p->cmd_num,cmd)==0)
        {
            printf("%s\t:    %s\n", p->cmd_num, p->desc);
            break;
        }
        p = p->next;
    }
    if(!p)
    {
        printf("This is a wrong cmd string!\n ");
    }
}

