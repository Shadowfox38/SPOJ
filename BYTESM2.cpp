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
#define fill(a,b)                        memset((a),(b),sizeof(a))
int h,w,a[110][110],dp[110][110];
int solve(int x,int y)
{
	if(dp[x][y] != -1)
		return dp[x][y];
	if(x == h)
		return a[x][y];
	int r1 = a[x][y] + solve(x+1,max(y-1,1));
	int r2 = a[x][y] + solve(x+1,y);
	int r3 = a[x][y] + solve(x+1,min(y+1,w));
	dp[x][y] = max(r1,max(r2,r3));
	return dp[x][y];
}
int main()
{
	int t,ans=-1,curr;
	si(t);
	while(t--)
	{
		si(h),si(w);
		fill(dp,-1);
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				si(a[i][j]);
		for(int i=1;i<=w;i++)
		{
			curr = solve(1,i);
			if(curr > ans)
				ans = curr;
		}
		printf("%d\n",ans);
		ans = -1;
	}
	return 0;
}
