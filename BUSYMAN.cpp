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
#define s                                first
#define e                                second
#define mp(a,b)                          make_pair((a),(b))
#define stack_clear(s)      while(!(s).empty()){(s).pop();}
#define si(x)				 scanf("%d",&(x))
#define sl(x)                            scanf("%lld",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
bool mysort(pii &p1,pii &p2){return (p1.e < p2. e);}
int main()
{
	int t,n,x,y,c,ans;
	vector<pii> vec;
	si(t);
	while(t--)
	{
		si(n);
		for(int i=0;i<n;i++)
		{
			si(x),si(y);
			vec.pb(mp(x,y));
		}
		sort(vec.begin(),vec.end(),mysort);
		c = vec[0].e,ans = 1;
		for(int i=1;i<n;i++)
		{
			if(vec[i].s >= c)
				c = vec[i].e,ans++;
		}
		printf("%d\n",ans);
		vec.clear();
	}
	return 0;
}
