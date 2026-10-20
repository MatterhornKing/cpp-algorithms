#include <iostream>

using namespace std;

const int N = 20;
int mypack[N] = {0};
int answer[N] = {0};
int w[N]={92,4,43,83,84,68,92,82,6,44,
	32,18,56,83,25,96,70,48,14,58};
int v[N]={44,46,90,72,91,40,75,35,8,
	54,78,40,77,15,61,17,75,29,75,63};
int full = 878;
int mymax = 0;

void mvalue(int uno,int i,int value,int weight)
{
	if(uno == 1)
	{
		if((weight + w[i])>full)
		{
			//cout << weight<<endl;
			//cout<<value<<endl;
			return ;
		}
		
		else if(i<N)
		{
			weight += w[i];
			value += v[i];
			
			
			if(i == N-1)
			{
				if(value > mymax)
				{
					mymax = value; 
					for(int k = 0;k < N; k++)
					{
						answer[k] = mypack[k];
					}
				}
				return;
			}
			else
			{
				mvalue(1,i+1,value,weight);
				mvalue(0,i+1,value,weight);
			}
			
		}
		
	}
	if(uno == 0)
	{
		mypack[i] = 0;
		if(i == N-1)
		{
			if(value > mymax)
			{
				mymax = value; 
				for(int k = 0;k < N; k++)
				{
					answer[k] = mypack[k];
				}
				
			}
			return;
		}
		else
		{
			mvalue(1,i+1,value,weight);
			mvalue(0,i+1,value,weight);	
		}
	}
	
}

int main()
{
	mvalue(1,0,0,0);
	mvalue(0,0,0,0);
	
	cout<<"The most value is "<<mymax<<endl;
	for (int i = 0;i < N;i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}
