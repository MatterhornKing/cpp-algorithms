#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	int i=100;
	int a,b,c;
	while(i<=999)
	{
		a=pow((i/100),3);
		b=pow((i%10),3);
		c=pow(((i%100)/10),3);
		if(a+b+c==i)
		cout<<i<<endl;
		i++;
	}
	return 0;
}
