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
	int n,h1=0,h2=0,h3=0,ans;
	string str;
	si(n);
	for(int i=0;i<n;i++)
	{
		cin>>str;
		if(str == "1/4")
			h1++;
		if(str == "3/4")
			h2++;
		if(str == "1/2")
			h3++;
	}
	ans = 1 + h2 + h3/2;
	h1 = h1 - h2;
	if(h3%2)
		h1 = h1-2,ans++;
	if(h1 > 0)
	{
		ans += h1/4;
		if(h1%4)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
