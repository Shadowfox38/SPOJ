#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

typedef vector<int> vi;
typedef long long int lld;

#define stack_clear(s)      while(!(s).empty()){(s).pop;}
#define si(x)				 scanf("%d",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd((x),(y))
#define fill(a,b)                        memset((a),(b),sizeof(a))
int *v;
vi *graph;
void DFS(int n)
{
	v[n-1] = 1;
	for(int i=0;i<graph[n].size();i++)
	{
		if(v[graph[n][i]-1] !=1)
			DFS(graph[n][i]);
	}
}
int main()
{
	int n,e,x,y,res=1;
	si(n),si(e);
	graph = new vi[n+1];
	v = new int[n]();
	for(int i=0;i<e;i++)
	{
		si(x),si(y);
		graph[x].pb(y);
		graph[y].pb(x);
	}
	if(e == n-1)
	{
		DFS(1);
		for(int i=0;i<n;i++)
		{
			if(v[i] == 0)
			{
				res = 0;
				break;
			}
		}
		if(res == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
		printf("NO\n");
	res = 1;
	delete[] v;
	delete[] graph;
}
