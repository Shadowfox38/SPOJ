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
#define ff                               first
#define ss                               second
#define si(x)				 scanf("%d",&(x))
#define sl(x)                            scanf("%lld",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
char a[100][100];
int dp[100][100],n=1,m=1;
vector<pii> valid(int x,int y,char ch)
{
	vector<pii> v;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			if(i == 0 && j == 0)
				continue;
			if(x+i>=0 && x+i<n && y+j>=0 && y+j<m && a[x+i][y+j] == ch + 1)
				v.pb(mp(x+i,y+j));
		}
	}
	return v;
}
int dfs(int x,int y)
{
	if(dp[x][y] != -1)
		return dp[x][y];
	vector<pii> v = valid(x,y,a[x][y]);
	int res = 0;
	for(int i=0;i<v.size();i++)
	{
		int curr = dfs(v[i].ff,v[i].ss);
		if(curr > res)
			res = curr;
	}
	dp[x][y] = res+1;
	return res+1;
}
int main()
{
	int res = 0;
	vector<pii> idxs;
	si(n),si(m);
	for(int c=1;n && m;c++)
	{
		fill(dp,-1);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf(" %c",&a[i][j]);
				if(a[i][j] == 'A')
					idxs.pb(mp(i,j));
			}
		}
		for(int i=0;i<idxs.size();i++)
		{
			int curr = dfs(idxs[i].ff,idxs[i].ss);
			if(curr > res)
				res = curr;
		}
		printf("Case %d: %d\n",c,res);
		res = 0,idxs.clear();
		si(n),si(m);
	}
	return 0;
}
