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
int a[5000];
vi res;
void precompute()
{
	fill(a,0);
	for(int i=2;i<5000;i++)
	{
		if(a[i] == 0)
		{
			int xx = 2;
			while(i*xx < 5000)
			{
				a[i*xx]++;
				xx++;
			}
		}
		if(a[i] >= 3)
			res.pb(i);
	}
}
int main()
{
	int t,n;
	precompute();
	si(t);
	while(t--)
	{
		si(n);
		printf("%d\n",res[n-1]);
	}
	return 0;
}
