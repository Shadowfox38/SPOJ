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
int mat[200][200],res[200][200],vis[200][200],n,m;
vector<pii> q;
vi val;
void push(int xx,int yy,int dis)
{
	if(!(vis[xx][yy] == 1 || xx < 0 || xx > n-1 || yy < 0 || yy > m-1 || mat[xx][yy] == 1))
		vis[xx][yy] = 1,val.pb(dis),q.pb(mp(xx,yy));
}
void msbfs()
{
	while(q.size() != 0)
	{
		int x = q[0].first;
		int y = q[0].second;
		res[x][y] = val[0];
		val.erase(val.begin());
		q.erase(q.begin());
		vis[x][y] = 1;
		push(x+1,y,res[x][y] + 1);
		push(x-1,y,res[x][y] + 1);
		push(x,y+1,res[x][y] + 1);
		push(x,y-1,res[x][y] + 1);
	}
}
int main()
{
	int t;
	char ch;
	si(t);
	while(t--)
	{
		si(n),si(m);
		fill(res,-1);
		fill(vis,-1);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf(" %c",&ch);
				mat[i][j] = ch-'0';
				if(ch == '1')
					val.pb(0),q.pb(mp(i,j));
			}
		}
		msbfs();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%d ",res[i][j]);
			printf("\n");
		}
		q.clear();
		val.clear();
	}
	return 0;
}
