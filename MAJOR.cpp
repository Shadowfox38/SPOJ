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
int cc[3000];
int main()
{
	int t,n,xx,res;
	si(t);
	while(t--)
	{
		si(n);
		fill(cc,0),res = -1;
		for(int i=0;i<n;i++)
		{
			si(xx);
			cc[xx+1000]++;
			if(cc[xx+1000] > n/2)
				res = xx;
		}
		if(res == -1)
			printf("NO\n");
		else
			printf("YES %d\n",res);
	}
	return 0;
}
