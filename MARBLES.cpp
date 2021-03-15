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
lld comb(lld n,lld r)
{
	r = min(r,n-r);
	lld p=1,k=1,m;
	while(r)
	{
		p *= n,k *= r;
		m = __gcd(p,k);
		p = p/m,k = k/m;
		n--,r--;
	}
	return p;
}
int main()
{
	lld t,n,k,ans;
	sl(t);
	while(t--)
	{
		sl(n),sl(k);
		ans = comb(n-1,k-1);
		printf("%lld\n",ans);
	}
	return 0;
}
