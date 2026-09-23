#include<stdio.h>
int main()
{
	int min=0;
	int n=6;
	int arr[]={6,1,5,4,9,99};
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i;j<n;j++)
		{
			if(arr[min]>arr[j])
			{
				int temp=arr[i];
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
