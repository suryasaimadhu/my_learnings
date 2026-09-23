#include<stdio.h>
int main()
{
int arr[]={4,3,5,6,54,3,2};
int n=7;
int temp;
int j;
for(int i=0;i<n;i++)
{
	j=i;
	while(j>0&&arr[j-1]>arr[j])
	{

		temp=arr[j];
		arr[j]=arr[j-1];
		arr[j-1]=temp;
		j--;
	}
}
for(int i=0;i<n;i++)
{
	printf("%d\n",arr[i]);
}
return 0;
}
