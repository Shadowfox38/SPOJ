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
	int t,a,b,g,ans;
	si(t);
	while(t--)
	{
		si(a),si(b);
		g = __gcd(a,b);
		ans = 0;
		for(int i=1;i<=sqrt(g);i++)
		{
			if(g%i == 0)
				ans += 2;
			if(double(i) == sqrt(g))
				ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
