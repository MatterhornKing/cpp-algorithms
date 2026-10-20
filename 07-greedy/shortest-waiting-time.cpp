#include <iostream>
using namespace std;

int main ()
{
	int cos[10]={8,13,6,9,7,4,22,3,12,15};
	int flag = 1000;
	int flag2 = 0;int sum = 0;

	for(int i=0;i<10;i++)
	{
		flag = 100;
		for(int j = 0;j < 10;j++)
		{
			if(cos[j]<flag && cos[j] > flag2)
			{
				flag = cos[j];
			}
		}
		cout<<flag<<endl;
		flag2 = flag;
		sum = sum + flag*(9-i);
	}
	cout<<endl; 
	 cout<<sum<<endl;
 return 0;
 } 

