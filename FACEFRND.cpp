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
#define sl(x)                            scanf("%lld",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int bob[10000];
int main()
{
	int n,m,xx,ans = 0;
	vi id;
	si(n);
	fill(bob,-1);
	for(int i=0;i<n;i++)
	{
		si(xx);
		bob[xx] = 1;
		si(m);
		for(int j=0;j<m;j++)
		{
			si(xx);
			id.pb(xx);
		}
	}
	for(int i=0;i<id.size();i++)
	{
		if(bob[id[i]] == -1)
			bob[id[i]] = 1,ans++;
	}
	printf("%d\n",ans);
	return 0;
}
