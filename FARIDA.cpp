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
int main()
{
	int t,n,m[10010];
	lld dp[10010];
	si(t);
	for(int c=1;c<=t;c++)
	{
		si(n);
		for(int i=0;i<n;i++)
			si(m[i]);
		dp[0] = m[0];
		dp[1] = max(m[0],m[1]);
		if(n == 0)
			printf("Case %d: %d\n",c,0);
		else
		{
			for(int i=2;i<n;i++)
			{
				dp[i] = max(dp[i-1],dp[i-2] + m[i]);
			}
			printf("Case %d: %lld\n",c,dp[n-1]);
		}
	}
	return 0;
}
