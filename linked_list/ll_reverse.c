//reverse list
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int value;
	struct node *next;
};
int main()
{
	struct node *head=NULL;
	struct node *tail=NULL;
	struct node *newnode=NULL;
	struct node *temp=NULL;
	int n;
	printf("Enter the number of nodes required\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		newnode=malloc(sizeof(*newnode));
		if(newnode==NULL)
			return 1;
		printf("Node %d\n",i+1);
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
	printf("The elements in linked list \n");
	temp=head;
	while(temp!=NULL)
	{
		printf("values in linked list follows : %d\n",temp->value);
		temp=temp->next;

	}
	printf("Reverse the linked list\n");
	temp=head;
	struct node *prev=NULL;
	struct node * front=NULL;
	while(temp!=NULL)
	{
		front=temp->next;
		temp->next=prev;
		prev=temp;
		temp=front;
	}
	tail=head;
	head=prev;
	temp=head;
	while(temp!=NULL)
	{
		printf("values in linked list follows : %d\n",temp->value);
		temp=temp->next;
	}
}



