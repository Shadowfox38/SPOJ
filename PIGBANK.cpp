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
	int t,e,f,w,n,wc[600],vc[600],dp[10010];
	si(t);
	while(t--)
	{
		si(e),si(f);
		w = f - e;
		si(n);
		for(int i=0;i<n;i++)
			si(vc[i]),si(wc[i]);
		dp[0] = 0;
		for(int i=1;i<=w;i++)
		{
			dp[i] = -1;
			for(int j=0;j<n;j++)
			{
				if(i-wc[j] < 0 || dp[i-wc[j]] == -1)
					continue;
				int curr = dp[i-wc[j]] + vc[j];
				if(curr < dp[i] || dp[i] == -1)
					dp[i] = curr;
			}
		}
		if(dp[w] == -1)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
	}
	return 0;
}
