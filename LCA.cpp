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
int st[1010][16],pp[1010],lev[1010];
vector<vi> tree;
void dfs(int idx,int d)
{
	lev[idx] = d;
	for(int i=0;i<tree[idx].size();i++)
		dfs(tree[idx][i],d+1);
}
void build(int n)
{
	for(int i=0;i<n;i++)
	{
		if(pp[i] == -1)
		{
			dfs(i,0);
			break;
		}
	}
	for(int i=0;i<n;i++)
		st[i][0] = pp[i];
	for(int j=1;(1<<j) < n;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(st[i][j-1] != -1)
				st[i][j] = st[st[i][j-1]][j-1];
		}
	}
}
/*
void print(int n)
{
	printf("---------BEGIN---------\n\n");
	for(int i=0;i<8;i++)
		printf("%d ",i);
	printf("\n");
	for(int i=0;i<8;i++)
		printf("--");
	printf("\n");

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<8;j++)
			printf("%d ",st[i][j]);
		printf("\n");
	}
	printf("\n----------END----------\n");
}
*/
int solve(int a,int b)
{
	if(lev[a] < lev[b])
		swap(a,b);
	int dist = lev[a] - lev[b];
	while(dist > 0)
	{
		int xx = log2(dist);
		a = st[a][xx];
		dist = dist - (1<<xx);
	}
	if(a == b)
		return a;
	for(int j=15;j>=0;j--)
	{
		if(st[a][j] != -1 && st[a][j] != st[b][j])
		{
			a = st[a][j];
			b = st[b][j];
		}
	}
	return pp[a];
}
int main()
{
	int t,n,m,xx,cc=0,q,a,b;
	si(t);
	while(cc++ < t)
	{
		si(n);
		fill(pp,-1),fill(st,-1);
		for(int i=0;i<n;i++)
		{
			si(m);
			vi vec;
			for(int j=0;j<m;j++)
			{
				si(xx);
				pp[xx-1] = i;
				vec.pb(xx-1);
			}
			tree.pb(vec);
		}
		build(n);
		si(q);
		printf("Case %d:\n",cc);
		while(q--)
		{
			si(a),si(b);
			printf("%d\n",solve(a-1,b-1) + 1);
		}
		tree.clear();
	}
	return 0;
}
