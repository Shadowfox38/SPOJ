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
class edge
{
	public:
		int x,y,c;
		edge(int xx,int yy,int cc){x = xx,y = yy,c = cc;}
};
bool mycmp(edge &e1,edge &e2){return (e1.c < e2.c);}
vector<edge> graph;
vi parent,rnk;
int find(int xx)
{
	if(parent[xx] == xx)
		return xx;
	parent[xx] = find(parent[xx]);
	return parent[xx];
}
void merge(int x,int y)
{
	x = find(x),y = find(y);
	if(rnk[x] < rnk[y])
		parent[x] = y;
	else
		parent[y] = x;
	if(rnk[x] == rnk[y])
		rnk[x]++;
}
int solve(int n)
{
	int ans = 0;
	sort(graph.begin(),graph.end(),mycmp);
	for(int i=0;i<n;i++)
		rnk.pb(0),parent.pb(i);
	for(int i=0;i<graph.size();i++)
	{
		int x = graph[i].x;
		int y = graph[i].y;
		if(find(x) != find(y))
		{
			merge(x,y);
			ans += graph[i].c;
		}
	}
	return ans;
}
int main()
{
	int t,n,e,p,x,y,z;
	si(t);
	while(t--)
	{
		si(p),si(n),si(e);
		for(int i=0;i<e;i++)
		{
			si(x),si(y),si(z);
			edge temp(x-1,y-1,z);
			graph.pb(temp);
		}
		int ans = solve(n);
		printf("%d\n",ans*p);
		parent.clear(),rnk.clear(),graph.clear();
	}
	return 0;
}
