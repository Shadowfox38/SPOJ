#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
#include<unordered_map>
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
unordered_map<int,vi> graph;
int gen[2010],vis[2010],flag=0;
void assign(int xx,int gender)
{
	vis[xx] = 1;
	gen[xx] = gender;
	for(int i=0;i<graph[xx].size();i++)
	{
		if(vis[graph[xx][i]] == 0)
			assign(graph[xx][i],gender^1);
	}
}
void test(int xx)
{
	if(flag == 0)
	{
		vis[xx] = 1;
		for(int i=0;i<graph[xx].size();i++)
		{
			if(gen[xx] == gen[graph[xx][i]])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			for(int i=0;i<graph[xx].size();i++)
			{
				if(vis[graph[xx][i]] == 0)
					test(graph[xx][i]);
			}
		}
	}
}
int main()
{
	int t,n,b,x,y;
	si(t);
	for(int s=1;s<=t;s++)
	{
		si(b),si(n);
		fill(gen,0);
		fill(vis,0);
		for(int i=0;i<n;i++)
		{
			si(x),si(y);
			graph[x].pb(y);
			graph[y].pb(x);
		}
		for(int i=1;i<=b;i++)
		{
			if(vis[i] == 0)
				assign(i,0);
		}
		fill(vis,0);
		for(int i=1;i<=b;i++)
		{
			if(vis[i] == 0 && flag == 0)
				test(i);
		}
		printf("Scenario #%d:\n",s);
		if(flag == 0)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
		graph.clear(),flag = 0;
	}
	return 0;
}
