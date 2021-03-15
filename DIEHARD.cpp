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
#define sl(x)                            scanf("%lld",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int dp[1010][1010];
int solve(int h,int a)
{
	if(h <= 0 || a <= 0)
		return 0;
	if(dp[h][a] != -1)
		return dp[h][a];
	int r1 = solve(h-2,a-8);
	int r2 = solve(h-17,a+7);
	dp[h][a] = max(r1,r2) + 1;
	return dp[h][a];
}
int main()
{
	int t,h,a;
	si(t);
	fill(dp,-1);
	while(t--)
	{
		si(h),si(a);
		printf("%d\n",2*solve(h,a) - 1);
	}
	return 0;
}
