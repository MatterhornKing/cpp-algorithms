#include<iostream>
#include<cstring>
using namespace std;
#define N 100
string a="abcbdb",b="acbbabdbb";
void myprint(int i,int j,int dp[][10]);

int main()
{
	string a="abcbdb",b="acbbabdbb";
	//int n1=strlen(a),n2=strlen(b);
	int n1=a.length();
	int n2=b.length();

	int s[n1+1][10];
	int dp[n1+1][10];

	for(int i=0;i<=n1;i++)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=n2;i++)
	{
		dp[0][i]=0;
	}
	
	for( int i=1; i<=n1; i++ ){
    	for( int j=1; j<=n2; j++ ){
            if( a[i]==b[j] ){
                dp[i][j] = dp[i-1][j-1]+1;
                s[i][j] = 1;
            }
            else if ( dp[i-1][j] >= dp[i][j-1] ){
                dp[i][j] = dp[i-1][j];
                s[i][j] = 2;
            }
            else {
                dp[i][j] = dp[i][j-1];
                s[i][j] = 3;
            }
        }
    }
	
	myprint(n1,n2,s);
	cout<<"The maximum length is "<<dp[n1][n2]<<endl;
	return 0;
	
 } 
 
 void myprint(int i,int j,int dp[7][10])
{
	if(i==0||j==0)
	return ;
	
	if(dp[i][j]==1)
	{
		myprint(i-1,j-1,dp);
		cout<<a[i-1]<<" ";
	}
	else if(dp[i][j]==2)
	myprint(i-1,j,dp);
	else
	myprint(i,j-1,dp); 
}
