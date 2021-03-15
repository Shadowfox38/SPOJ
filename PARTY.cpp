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
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int m,p,cost[110],fun[110],dp[510][110],curr[510][110];
	si(m),si(p);
	while((m|p) != 0)
	{
		for(int i=1;i<=p;i++)
			si(cost[i]),si(fun[i]);
		for(int i=0;i<=p;i++)
			dp[0][i] = 0,curr[0][i] = 0;
		for(int i=0;i<=m;i++)
			dp[i][0] = 0,curr[i][0] = i;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=p;j++)
			{
				curr[i][j] = curr[i][j-1];
				if(curr[i][j] >= cost[j] && fun[j] > 0)
				{
					dp[i][j] = dp[i][j-1] + fun[j];
					curr[i][j] = curr[i][j] - cost[j];
				}
				else
				{
					if(i < cost[j])
						dp[i][j] = dp[i][j-1];
					else
					{
						dp[i][j] = max(dp[i][j-1], fun[j] + dp[i-cost[j]][j-1]);
						if(fun[j]+dp[i-cost[j]][j-1] == dp[i][j-1])
							curr[i][j] = max(curr[i-cost[j]][j-1],curr[i][j-1]);
						else if(dp[i][j] > dp[i][j-1])
							curr[i][j] = curr[i-cost[j]][j-1];
					}
				}
			}
		}
		printf("%d %d\n",m-curr[m][p],dp[m][p]);
		si(m),si(p);
	}
	return 0;
}
