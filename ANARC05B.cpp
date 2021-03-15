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
int l1,l2;
vi v1,v2;
vector<pii> idx;
bool input()
{
	int xx;
	v1.clear(),v2.clear(),idx.clear();
	si(l1);
	for(int i=0;i<l1;i++)
		si(xx),v1.pb(xx);
	if(l1 != 0)
	{
		si(l2);
		for(int i=0;i<l2;i++)
			si(xx),v2.pb(xx);
		return 1;
	}
	return 0;
}
int search(int l,int r,int num)
{
	if(l > r)
		return -1;
	int mid = (l+r)/2;
	if(v2[mid] == num)
		return mid;
	if(v2[mid] < num)
		return search(mid+1,r,num);
	else
		return search(l,mid-1,num);
}
int main()
{
	int ans = 0;
	while(input())
	{
		idx.pb(mp(-1,-1));
		for(int i=0;i<l1;i++)
		{
			int xx = search(0,l2-1,v1[i]);
			if(xx != -1)
				idx.pb(mp(i,xx));
		}
		idx.pb(mp(l1-1,l2-1));
		for(int i=1;i<idx.size();i++)
		{
			int r1 = 0,r2 = 0;
			for(int j=idx[i-1].first+1;j<=idx[i].first;j++)
				r1 += v1[j];
			for(int j=idx[i-1].second+1;j<=idx[i].second;j++)
				r2 += v2[j];
			ans += max(r1,r2);
		}
		printf("%d\n",ans);
		ans = 0;
	}
	return 0;
}
