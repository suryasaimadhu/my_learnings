#include<stdio.h>
int main()
{
	int num=12345;
	//	expected num=54321
	int rev=0;
	int digit;
	while(num!=0)
	{
		digit=num%10;
		rev=rev*10+digit;
		num=num/10;
	}
	printf("the rev num is %d\n",rev);
	return 0;
}
