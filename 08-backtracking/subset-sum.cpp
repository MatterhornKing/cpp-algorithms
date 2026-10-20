#include <iostream>

using namespace std;

const int N = 100;
int mypack[N] = {0};
int answer[N] = {0};
int n;
int num;
void find(int uno,int sum,int step)
{
	if(uno == 1)
	answer[step-1] = 1;
	if(uno == 0)
	answer[step-1] = 0;
	if(sum == num)
	{
		for(int i = 0; i < n;i++)
		{
			if(answer[i] == 1)
			cout<<mypack[i]<<" ";
		}
		cout<<endl;
		return;
	}
	
	if(step == 9 || sum > num)
	return;
	
	find(1,sum+mypack[step],step+1);
	find(0,sum,step+1);
}
int main()
{
	
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>mypack[i];
	}
	
	cin>>num;
	find(2,0,0);
	
	return 0;	 
}
