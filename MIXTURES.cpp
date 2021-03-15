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
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int a[200],c[200];
lld dp[200][200];
void cumsum(int n)
{
	c[0] = a[0];
	for(int i=1;i<n;i++)
		c[i] = c[i-1] + a[i];
}
int color(int l,int r)
{
	if(l == 0)
		return c[r]%100;
	else
		return ((c[r] - c[l-1])%100);
}
lld smoke(int s,int e)
{
	if(dp[s][e] != -1)
		return dp[s][e];
	for(int i=s+1;i<=e;i++)
	{
		dp[s][i] = (1LL*a[i] * 1LL*color(s,i-1)) + dp[s][i-1];
		for(int len=1;len<i-s;len++)
		{
			int val1 = color(i-len,i);
			int val2 = color(s,i-len-1);
			lld curr = val1 * val2;
			curr += smoke(i-len,i);
			curr += smoke(s,i-len-1);
			if(curr < dp[s][i])
				dp[s][i] = curr;
		}
	}
	return dp[s][e];
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			si(a[i]);
		cumsum(n);
		fill(dp,-1);
		for(int i=0;i<200;i++)
			dp[i][i] = 0;
		printf("%lld\n",smoke(0,n-1));
	}
	return 0;
}
