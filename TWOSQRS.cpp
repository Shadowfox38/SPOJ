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
typedef vector<long long int> vi;
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
	int t,f=0;
	lld n,c,d;
	vi vec;
	si(t);
	for(lld i=0;i<=1000000;i++)
		vec.pb(i*i);
	while(t--)
	{
		sl(n);
		c = lld(sqrt(n));
		for(lld i=0;i<=c;i++)
		{
			if(binary_search(vec.begin(),vec.end(),n-i*i))
			{
				f = 1;
				break;
			}
		}
		f == 1 ? printf("Yes\n") : printf("No\n");
		f = 0;
	}
	return 0;
}
