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
int a[200];
unordered_map<int,int> sum;
int main()
{
	int n,xx,x,y,z,w,ans = 0;
	si(n);
	for(int i=0;i<n;i++)
		si(a[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			xx = a[i] + a[j];
			if(sum.count(xx))
				sum[xx]++;
			else
				sum[xx] = 1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<n;l++)
				{
					x = a[i],y = a[j],z = a[k],w = a[l];
					if(w == 0 || (x*y + z)%w != 0)
						continue;
					xx = (x*y + z)/w;
					if(sum.count(xx))
						ans = ans + sum[xx];
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
