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
	int n,h[100010],pop[100010],xx;
	lld ans[100010],r;
	vi idx;
	si(n);
	while(n!=0)
	{
		for(int i=0;i<n;i++)
			si(h[i]);
		for(int i=0;i<n;i++)
		{
			ans[i] = 0,pop[i] = 0;
			idx.empty() ?: xx = idx.back();
			while(!idx.empty() && h[idx.back()] > h[i])
			{
				ans[idx.back()] += 1LL*h[idx.back()]*(xx-idx.back()+1);
				pop[i] += pop[idx.back()] + 1;
				idx.pop_back();
			}
			ans[i] += 1LL*h[i]*pop[i];
			idx.pb(i);
		}
		xx = idx.back();
		while(!idx.empty())
		{
			ans[idx.back()] += 1LL*h[idx.back()]*(xx-idx.back()+1);
			idx.pop_back();
		}
		for(int i=0;i<n;i++)
			(i == 0 || r < ans[i]) ? r = ans[i] : 1;
		printf("%lld\n",r);
		si(n);
	}
	return 0;
}
