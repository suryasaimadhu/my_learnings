#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int value;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *temp=NULL;
struct node *newnode=NULL;
int main()
{
	int n;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		newnode=malloc(sizeof(*newnode));
		printf("Enter the node value for %d \n",i+1);
		scanf("%d",&newnode->value);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else
		{
			tail->next=newnode;
			tail=newnode;
		}
	}
	printf("Lined list\n");
	temp=head;
	while(temp!=NULL)
	{
		printf("The value is %d\n",temp->value);
		temp=temp->next;
	}
	printf("insert ele at begin\n");
	newnode=malloc(sizeof(*newnode));
	scanf("%d",&newnode->value);
	newnode->next=head;
	head=newnode;

	printf("Lined list\n");
	temp=head;
	while(temp!=NULL)
	{
		printf("The value is %d\n",temp->value);
		temp=temp->next;
	}
	printf("insert ele at end\n");
	newnode=malloc(sizeof(*newnode));
	scanf("%d",&newnode->value);
	newnode->next=NULL;
	tail->next=newnode;
	tail=newnode;

	printf("Lined list\n");
	temp=head;
	while(temp!=NULL)
	{
		printf("The value is %d\n",temp->value);
		temp=temp->next;
	}
	printf("insert ele at a particular postion\n");
	int pos;
	printf("Enter the postion where we want to place element\n");
	scanf("%d",&pos);
	newnode=malloc(sizeof(*newnode));
	scanf("%d",&newnode->value);
	temp=head;
	if(pos<1)
		printf("invalid postion\n");
	if(pos==1)
	{
		newnode->next=head;
		head=newnode;
		if(tail==NULL)
			tail=newnode;
	}
	else
	{
		temp=head;
		for(int i=1;i<pos-1&& temp!=NULL;i++)
		{
			temp=temp->next;
		}
		if(temp==NULL)
			printf("Invalid\n");
		else
		{
			newnode->next=temp->next;
			temp->next=newnode;

			if(newnode->next=NULL)
				tail=newnode;
		}
	}

		printf("Lined list at pos\n");
		temp=head;
		while(temp!=NULL)
		{
			printf("The value is %d\n",temp->value);
			temp=temp->next;
		}
	}
