#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
#include<unordered_map>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long int lld;

#define M                                1000000007
#define mp(a,b)                          make_pair((a),(b))
#define stack_clear(s)      while(!(s).empty()){(s).pop();}
#define si(x)				 scanf("%d",&(x))
#define sl(x)                            scanf("%lld",&(x))
#define ff                               first
#define ss                               second
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
unordered_map<string,int> idx;
vector<vector<pii>> graph;
bool mycomp(pii &p1,pii &p2){return (p1.ss > p2.ss);} //debug
int solve(int n,int s,int e)
{
	vi distance;
	priority_queue<pii,vector<pii>,greater<pii>> cost;
	for(int i=0;i<n;i++)
	{
		i == s ? cost.push(mp(i,0)),distance.pb(0) : distance.pb(-1);
	}
	while(!cost.empty())
	{
		pii xx = cost.top();
		cost.pop();
		for(int i=0;i<graph[xx.ff].size();i++)
		{
			pii c = graph[xx.ff][i];
			if(distance[c.ff] == -1 || distance[c.ff] > distance[xx.ff] + c.ss)
			{
				distance[c.ff] = distance[xx.ff] + c.ss;
				cost.push(mp(c.ff,distance[c.ff]));
			}
		}
	}
	return distance[e];
}
int main()
{
	int t,n,q,xx,a,b;
	string s1,s2;
	si(t);
	while(t--)
	{
		si(n);
		for(int i=0;i<n;i++)
		{
			cin>>s1;
			idx[s1] = i;
			si(xx);
			vector<pii> vec;
			for(int j=0;j<xx;j++)
			{
				si(a),si(b);
				vec.pb(mp(a-1,b));
			}
			graph.pb(vec);
		}
		si(q);
		for(int i=0;i<q;i++)
		{
			cin>>s1>>s2;
			printf("%d\n",solve(n,idx[s1],idx[s2]));
		}
		graph.clear();
		idx.clear();
	}
	return 0;
}
