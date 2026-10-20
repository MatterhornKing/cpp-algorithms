#include<iostream>
using namespace std;
#define N 100

int find(int a[],int b[],int n);

int main()
{
	int n;
	int a[N],b[N]={0};
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans;
	ans=find(a,b,n);
	
	cout<<ans<<endl;

	
	return 0;
 } 
 
int find(int a[],int b[],int n)
{
	
	int flag,ans;
	for(int i =0;i<n;i++)
	{
		if(a[i]>0)
		{
			ans=a[i];
			b[i]=a[i];
			flag=i;
			break;
		}
	}

	for(int i=flag+1;i<n;i++)
	{
		//if(b[i-1]+a[i]>0&&b[i-1]+a[i]>b[i-1]&&b[i-1]+a[i]>a[i])
		//{
		//	b[i]=b[i-1]+a[i];
		//	if(b[i]>=ans)
		//	ans=b[i];
		//}
		if(b[i-1]+a[i]>0)
		{
			b[i]=b[i-1]+a[i];
			if(b[i]>=ans)
			ans=b[i];
		}
		//else if(b[i-1]+a[i]>0)
		//{
		//	b[i]=a[i];
		//}
		//else
		//b[i]=b[i-1];
	}
	
	return ans;
}
 

