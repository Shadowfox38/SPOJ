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
#define ff                               first
#define ss                               second
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i].first<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int t,n,m,a[1010],b[1010],s1,s2,ans;
	vector<pii> vec;
	si(t);
	while(t--)
	{
		si(n);
		for(int i=0;i<n;i++)
			si(a[i]);
		si(m);
		for(int i=0;i<m;i++)
			si(b[i]);
		sort(a,a+n),sort(b,b+m);
		s1 = 0,s2 = 0;
		while(s1 < n && s2 < m)
		{
			if(a[s1] < b[s2])
			{
				vec.pb(mp(a[s1],1));
				s1++;
			}
			else
			{
				vec.pb(mp(b[s2],2));
				s2++;
			}
		}
		while(s1 < n)
		{
			vec.pb(mp(a[s1],1));
			s1++;
		}
		while(s2 < m)
		{
			vec.pb(mp(b[s2],2));
			s2++;
		}
		ans = -1;
		for(int i=1;i<vec.size();i++)
		{
			if(vec[i].ss == vec[i-1].ss)
				continue;
			if(ans == -1 || ans > vec[i].ff - vec[i-1].ff)
				ans = vec[i].ff - vec[i-1].ff;
		}
		printf("%d\n",ans);
		vec.clear();
	}
	return 0;
}
