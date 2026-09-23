#include<stdio.h>
#include<string.h>
void mystrrev(char *str)
{
	int l;
	int i;
	int start=0,end;
	l=strlen(str);
	int x=l-1;
	for(int i=0;i<x;i++,x--)
	{
		char t=str[i];
		str[i]=str[x];
		str[x]=t;
	}
	for(int i=0;i<=l;i++)
	{
		if(str[i]==' '||str[i]=='\0')
		{
			end=i-1;
			while(start<end)
			{
				char t=str[start];
				str[start]=str[end];
				str[end]=t;
				start++;
				end--;
			}
			start=i+1;


		}

	}
}

int main()
{
	char str[50];
	printf("Enter the string \n");
	scanf("%49[^\n]",str);
	mystrrev(&str);
	printf("%s\n",str);
	return 0;
}

