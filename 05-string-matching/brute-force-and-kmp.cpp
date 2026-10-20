#include <iostream>
#include <cstring>
using namespace std;
#define MAXLEN 100

typedef struct
{
	char ch[MAXLEN];
	int length;
}String;

void get_nextval(String t,int nextval[]);
int BF(String s,String t,int pos);
int KMP(String s,String t, int pos);

int main()
{
	String s,t;
	s.length=17; t.length=5;
	strcpy(s.ch,"ababcabccabcacbab");
	strcpy(t.ch,"abcac");
	
	int ans1,ans2;
	ans1=BF(s,t,0);
	ans2=KMP(s,t,0);
	
	if(ans2)
	cout<<"Match successfully from "<<ans2<<" by KMP"<<endl;
	
	return 0;
}

int BF(String s,String t,int pos)
{
	int i=pos;
	int j=0;
	
	while(i<s.length&&j<t.length)
	{
		if(s.ch[i]==t.ch[j])
		{
			j++;i++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=t.length) return i-t.length;
		else return 0;
}

int KMP(String s,String t, int pos)
{
	int nextval[t.length];
	get_nextval(t,nextval);
	
	int i=pos;//从pos处开始匹配
	int j=0;
	while(i<s.length&&j<t.length)
	{
		if(j==-1||s.ch[i]==t.ch[j])
		{
			i++;j++;
		}
		else
		j=nextval[j];
	}
	if(j>=t.length) return i-t.length;
	else return 0; 
}

void get_nextval(String t,int nextval[])
{
	int i=0,j=-1;
	nextval[0]=-1;
	while(i<t.length)
	{
		if(j==-1||t.ch[i]==t.ch[j])// i处字符匹配 或者i前无 成功匹 
		{
			i++;j++;//指针后移到i+1处 
			if(t.ch[i]!=t.ch[j])nextval[i]=j;// i+1处字符不匹配， 
			else nextval[i]=nextval[j]; //i+1处字符匹配 ，i+1处字符nextval值与 
		}
		else j=nextval[j];//
	}
}


