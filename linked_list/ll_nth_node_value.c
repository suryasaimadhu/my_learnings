//nth elememnt
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
	printf("Middle node in  linked list\n");
	int ne;
	printf("Enter the node\n");
	scanf("%d",&ne);
	struct node *first=NULL;
	struct node *second=NULL;
	first=head;
	second=head;
	for(int i=0;i<ne;i++)
	{
		first=first->next;
	}
	while(first!=NULL)
	{
		first=first->next;
		second=second->next;
	}
	printf("nth node value is %d\n",second->value);


}



