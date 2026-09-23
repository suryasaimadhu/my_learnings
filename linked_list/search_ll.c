//search elememt in linked list
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
	temp=head;
	printf("Search element\n");
	int s;
	int position=1;
	int found=0;
	printf("enter the element ,searching for\n");
	scanf("%d",&s);
	while(temp!=NULL)
	{
		if(s==temp->value)
		{
			found=1;
			printf("Element was found at %d\n",position);
			break;
		}
		temp=temp->next;
		position++;
	}
		if(found==0)
		{
			printf("Element was not in list\n");
		}

	}




