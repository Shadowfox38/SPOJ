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
int dp[2010][2010],v[2010];
int solve(int x,int y,int a)
{
	if(dp[x][y] != -1)
		return dp[x][y];
	if(x == y)
		return a*v[x];
	if(x < 0 || y < 0)
		return 0;
	int r1 = a*v[x] + solve(x+1,y,a+1);
	int r2 = a*v[y] + solve(x,y-1,a+1);
	dp[x][y] = max(r1,r2);
	return dp[x][y];
}
int main()
{
	int n;
	si(n);
	fill(dp,-1);
	for(int i=0;i<n;i++)
		si(v[i]);
	printf("%d\n",solve(0,n-1,1));
	return 0;
}
