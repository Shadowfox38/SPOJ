#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long int lld;

#define M                                1000000007
#define mp(a,b)                          make_pair((a),(b))
#define stack_clear(s)      while(!(s).empty()){(s).pop();}
#define si(x)				 scanf("%d",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int LCS(string s1)
{
	int **dp,len,xx;
	string s2;
	len = s1.length();
	s2 = s1;
	reverse(s2.begin(),s2.end());
	dp = new int*[len];
	for(int i=0;i<len;i++)
		dp[i] = new int[len]();
	if(s2[0] == s1[0])
		dp[0][0] = 1;
	for(int i=1;i<len;i++)
	{
		if(dp[i-1][0] != 1)
		{
			if(s2[0] == s1[i])
				dp[i][0] = 1;
		}
		else
			dp[i][0] = 1;
	}
	for(int j=1;j<len;j++)
	{
		if(dp[0][j-1] != 1)
		{
			if(s1[0] == s2[j])
				dp[0][j] = 1;
		}
		else
			dp[0][j] = 1;
	}
	for(int i=1;i<len;i++)
	{
		for(int j=1;j<len;j++)
		{
			if(s1[i] == s2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	xx = dp[len-1][len-1];
	for(int i=0;i<len;i++)
		delete[] dp[i];
	delete[] dp;
	return xx;
}
int main()
{
	int t,ans,len;
	string str;
	si(t);
	while(t--)
	{
		cin>>str;
		ans = str.length() - LCS(str);
		printf("%d\n",ans);
	}
	return 0;
}
