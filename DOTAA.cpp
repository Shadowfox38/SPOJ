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
int main()
{
	int t,n,m,d,xx,hits=0;
	si(t);
	while(t--)
	{
		si(n),si(m),si(d);
		for(int i=0;i<n;i++)
		{
			si(xx);
			xx%d == 0 ? hits += (xx/d)-1 : hits += xx/d;
		}
		if(hits >= m)
			printf("YES\n");
		else
			printf("NO\n");
		hits = 0;
	}
	return 0;
}
