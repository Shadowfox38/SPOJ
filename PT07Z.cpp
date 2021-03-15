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
#define fill(a,b)                        memset((a),(b),sizeof(a))
unordered_map<int,vi> map;
int d = 0;
int DFS(int xx,int p)
{
	int mx = 0,smx = 0;
	for(int i=0;i<map[xx].size();i++)
	{
		if(map[xx][i] == p)
			continue;
		int len = DFS(map[xx][i],xx) + 1;
		if(len >= mx)
			smx = mx, mx = len;
		else if(len > smx)
			smx = len;
	}
	d = max(d,mx+smx);
	return mx;
}
int main()
{
	int n,x,y,gbg;
	si(n);
	for(int i=0;i<n-1;i++)
	{
		si(x),si(y);
		map[x].pb(y);
		map[y].pb(x);
	}
	gbg = DFS(1,-1);
	printf("%d\n",d);
	return 0;
}
