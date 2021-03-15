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
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int t,n,k,h[20010],ans;
	si(t);
	while(t--)
	{
		si(n),si(k);
		for(int i=0;i<n;i++)
			si(h[i]);
		sort(h,h+n);
		ans = h[k-1] - h[0];
		for(int s=1,e=k;e<n;e++,s++)
			h[e]-h[s] < ans ? ans = h[e] - h[s] : 0;
		printf("%d\n",ans);
	}
	return 0;
}
