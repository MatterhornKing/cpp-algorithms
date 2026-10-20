#include <iostream>
using namespace std;

int daba(int n,int result)
{
	if(n==1)
	{
		if (result<11&&result>=0)
		{
			return 1; 
		}
		else return 0;
	}
	
	else return daba(n-1,result-0)+daba(n-1,result-1)+daba(n-1,result-2)
	+daba(n-1,result-3)+daba(n-1,result-4)+daba(n-1,result-5)
	+daba(n-1,result-6)+daba(n-1,result-7)+daba(n-1,result-8)
	+daba(n-1,result-9)+daba(n-1,result-10);
}
int main ()
{
	cout<<daba(6,45);
} 
