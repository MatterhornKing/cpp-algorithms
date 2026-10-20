#include <stdio.h>


int main()
{
	int n;
	scanf("%d",&n);
	int sum=1;
	for(int i=n/2;i>1;i--)
	{
		if(n%i==0)
		{
			sum=sum+i;
		}
	}
	if(sum==n)
	printf("YES");
	else
	printf("NO");
	
	return 0;
 } 
