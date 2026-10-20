#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int a[]={2,3,1,2,3,3,2,2,1,1,3,2,1,3,1};
	
	int count1=0,count3=0;
	for(int i=0;i<15;i++)
	{
		if(a[i]==1)
		count1++;
		if(a[i]==3)
		count3++;
	}
	for(int i=0;i<15;i++)
	{
		if (i<count1)
		a[i]=1;
		else if(i>15-count3-1)
		a[i]=3;
		else
		a[i]=2;
		cout<<a[i]<<endl;
	}
	
	return 0;
}
