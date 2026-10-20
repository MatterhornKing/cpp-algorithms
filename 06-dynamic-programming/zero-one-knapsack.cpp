#include<iostream>

using namespace std;
#define N 20
int bag(int w[],int v[],int m);

int main()
{
	int w[N]={92,4,43,83,84,68,92,82,6,44,
	32,18,56,83,25,96,70,48,14,58};
	int v[N]={44,46,90,72,91,40,75,35,8,
	54,78,40,77,15,61,17,75,29,75,63};
	int m=878;
	int ans;
	ans=bag(w,v,m);
	cout<<ans<<endl;
	return 0;
 } 
 
int bag(int w[],int v[],int m)
{
	int dp[N][m];
	
	for(int i=0;i<m;i++)
	{
		if(i>=w[0])
		{
			dp[0][i]=v[0];//初始化 
		}
		else
		dp[0][i]=0;
	}
	
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<m;j++)//j表示背包重量 
		{
			if(j<w[i])
			dp[i][j]=dp[i-1][j]; 
		
			else if(dp[i-1][j]>dp[i-1][j-w[i]]+v[i])
			dp[i][j]=dp[i-1][j]; 
		
			else
			dp[i][j]=dp[i-1][j-w[i]]+v[i];
		}
	}
	
	return dp[N-1][m-1];
}
