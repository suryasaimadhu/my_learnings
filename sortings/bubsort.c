#include<stdio.h>
int main()
{
int arr[]={3,2,8,5,78,45};
int n=6;
int temp;
for(int i=0;i<n;i++)
{
	for(int j=i;j<n;j++)
	{
		if(arr[i]>arr[j])
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
}
for(int i=0;i<n;i++)
{
	printf("%d\n",arr[i]);
}
return 0;
}
