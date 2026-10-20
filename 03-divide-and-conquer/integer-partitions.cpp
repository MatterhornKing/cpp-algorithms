#include <iostream>
using namespace std;

int devide (int n,int max);
int main()
{
	int n;
	cin>>n;
	cout<<devide(n,n)<<endl;
	return 0; 
 } 
 
int devide (int n,int max)
{
	if(n==1||max==1)
	return 1;
	else if(n==max) return devide(n,max-1)+1;
	else if(n>max)return devide(n,max-1)+devide(n-max,max);
	else return devide(n,n);
			
}


