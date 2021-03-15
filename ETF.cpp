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
	int t,n,f=0;
	double ans;
	si(t);
	while(t--)
	{
		si(n);
		ans = n;
		for(int p=2;p<=sqrt(n);p++)
		{
			if(n%p == 0)
			{
				for(int i=2;i<=sqrt(p);i++)
				{
					if(p%i == 0)
					{
						f = 1;
						break;
					}
				}
				if(f == 1)
					f = 0;
				else
				{
					ans = ans * (1.0 - (1.0/double(p)));
					while(n%p == 0)
						n = n/p;
				}
			}
		}
		if(n > 1)
			ans = ans * (1.0 - (1.0/double(n)));
		printf("%d\n",int(ans));
	}
	return 0;
}
