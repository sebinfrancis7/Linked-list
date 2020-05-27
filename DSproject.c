//PATIENT RECORD SYSTEM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct node
{
    int num;
    char name[30];
    char disease[50];
    struct node* next;
}node;

typedef struct
{
    node* start;
}LL;

void insertEnd(LL *l,int pnum,char pname[30],char pdisease[50])
{	node *newrec,*p;
	newrec=(node*)malloc(sizeof(node));
	newrec->num=pnum;
	strcpy(newrec->name,pname);
	strcpy(newrec->disease,pdisease);
	newrec->next=NULL;

	if(l->start==NULL)
	l->start=newrec;

	else
	{
		p=l->start;
		while(p->next!=NULL)
		p=p->next;

		p->next=newrec;
	}
}

void display(LL *l)
{
	node *p;
	int i=0;
	if(l->start==NULL)
	{
		printf("RECORD IS EMPTY\n");
		return;
	}
	p=l->start;

	while(p!=NULL)
	{
	        i++;
	        printf("|| NUMBER: %d ||\t",i);
		printf("\t\t||* PATIENT ID : %d *||\n",p->num);
		printf("\t\t\t\t||* PATIENT NAME : %s *||\n",p->name);
		printf("\t\t\t\t||* DISEASE: %s *||\n\n\n",p->disease);
		p=p->next;
	}
	printf("\n");
}


void search(LL *l,char pname[30])
{
	node *p;
	p=l->start;

	while(p!=NULL)
	{
		if(strcmp(pname,p->name)==0)
		{printf("||PATIENT ID : %d ||\t",p->num);
		printf("||PATIENT NAME : %s ||\t",p->name);
		printf("||DISEASE: %s ||\n",p->disease);
		break;
		}
		else
		{p=p->next;
		}
	}
	if(p==NULL)
        printf("%s RECORD NOT FOUND",pname);

}

int count(LL *l)
{
	node *p;
	int c=0;
	p=l->start;

	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}

void deleteElement(LL *l,char pname[30])
{	node *p,*q;
	if(l->start==NULL)
	{
		printf(" RECORD LIST IS EMPTY\n");
		return ;
	}
	if(strcmp(l->start->name,pname)==0)
	{
		p=l->start;
		l->start=l->start->next;
		p->next=NULL;
		return;
	}
	q=l->start;
	while(q->next!=NULL)
	{
		if(strcmp(pname,q->next->name)==0)
		break;
		else
		q=q->next;
	}
	p=q->next;
	if(p==NULL)
	{
		printf("THE RECORD FOR %s IS NOT FOUND\n",pname);
	}
	else
	{q->next=p->next;
	p->next=NULL;
	}
}


int main()
{
	LL l1;
	int ch,pnum;
	char pname[30],pdisease[50],d,c;
    l1.start=NULL;
    printf("*****************************************************************************\n***************************||WELLNESS --- HEALTHCARE||***********************\n*****************************************************************************\n");
	menu :
	while(1)
	{
        printf("\nPATIENT RECORD DATABASE:\n");
		printf("\n1:INSERT RECORD\n");
		printf("2:DELETE RECORD\n");
		printf("3:SEARCH RECORD\n");
		printf("4:TOTAL PATIENTS\n5:DISPLAY RECORDS\n6:EXIT\n");

		printf("PLEASE ENTER CHOICE\n");
		scanf("%d",&ch);
		if(ch==6)
        {
            printf("PRESS Y TO CONFIRM\nPRESS N TO RETURN TO MAIN MENU\n");
            scanf("%c");
            scanf("%c",&c);
            if(c=='Y'||c=='y')
                break;
            else if(c=='n'||c=='N') goto menu;

        }
		switch(ch)
		{
		case 1:printf(" ENTER PATIENT ID: \n");
		        scanf("%d",&pnum);
		        scanf("%c",&d);
		        printf("ENTER PATIENT NAME:\n");
		        gets(pname);
		        printf("ENTER PATIENT DISEASE:\n ");
		        gets(pdisease);
		        insertEnd(&l1,pnum,pname,pdisease);
		        printf("\n  LIST UPDATED \n ");
		         break;

        case 2: printf(" ENTER NAME TO DELETE\n ");
        		scanf("%c");
		        gets(pname);
		        deleteElement(&l1,pname);
		         printf("\n LIST UPDATED \n ");
                 break;
		case 3: printf(" ENTER NAME TO SEARCH\n");
			scanf("%c");
		        gets(pname);
		        search(&l1,pname);
		        break;
		case 4:printf(" TOTAL NUMBER OF PATIENTS = %d\n",count(&l1));break;
		case 5:display(&l1);break;
		default:printf("INVALID CHOICE !!!\n");
		}
	}

	return 0;
}

