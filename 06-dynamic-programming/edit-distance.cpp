#include<iostream> 
#include <cstring>       //字符串标准函数库 
#include <algorithm>     //使用min函数 
using namespace std;

int convert_word1(const string s1, const string s2) 
{ 	
    int m = s1.length(); 	
    int n = s2.length();     
    //申请动态内存数组 
    int** dp = new int*[m + 1]; 	
    for (int i = 0; i < m + 1; i++) { 		
        dp[i] = new int[n + 1]; 	
    }    
     //赋予初值 
    for (int i = 0; i < m + 1; i++) { 		
        dp[i][0] = i; 	
    } 	
    for (int j = 0; j < n + 1; j++) { 		
        dp[0][j] = j; 	
     }     
    //数组元素之间的关系 
    for (int i = 1; i < m + 1; i++) { 		
        for (int j = 1; j < n + 1; j++) { 			
            if (s1[i - 1] == s2[j - 1])       //------------------------------1 
	        dp[i][j] = dp[i - 1][j - 1]; 			
            else 
		dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1; 
	} 	
    } 	
    return dp[m][n];
}

int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	
	cout<<convert_word1(s1,s2);
	return 0; 
}
