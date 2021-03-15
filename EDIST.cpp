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
#define fill(a,b)                        memset((a),(b),sizeof(a))
char a[3000],b[3000];
int dp[3000][3000],m,n;
int edit(int i,int j)
{
	if(i == m)
		return n-j;
	if(j == n)
		return m-i;
	if(dp[i][j] != -1)
		return dp[i][j];
	int r1 = edit(i+1,j+1) + (a[i]!=b[j]);
	int r2 = edit(i,j+1) + 1;
	int r3 = edit(i+1,j) + 1;
	dp[i][j] = min(min(r1,r2),r3);
	return dp[i][j];
}
int main()
{
	int t;
	si(t);
	while(t--)
	{
		fill(dp,-1);
		scanf("%s",a);
		scanf("%s",b);
		m = strlen(a);
		n = strlen(b);
		printf("%d\n",edit(0,0));
	}
	return 0;
}
