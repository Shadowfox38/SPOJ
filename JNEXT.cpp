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
	int t,n,a[1000010],m,v,idx,f=0;
	vi vec;
	si(t);
	while(t--)
	{
		si(n);
		for(int i=0;i<n;i++)
			si(a[i]);
		for(int i=n-1;i>=0;i--)
		{
			if(i == n-1 || m <= a[i])
				vec.pb(a[i]),m = a[i];
			else if(m > a[i])
			{
				v = a[i];
				idx = i;
				vec.pb(a[i]);
				break;
			}
			if(i == 0)
				f = 1;
		}
		if(!f)
		{
			sort(vec.begin(),vec.end());
			for(int i=0;i<vec.size();i++)
			{
				if(vec[i] > v)
				{
					a[idx] = vec[i];
					vec.erase(vec.begin()+i);
					idx++;
					break;
				}
			}
			for(int i=0;i<vec.size();i++)
				a[idx+i] = vec[i];
			for(int i=0;i<n;i++)
				printf("%d",a[i]);
			printf("\n");
		}
		else
			printf("-1\n");
		vec.clear(),f = 0;
	}
	return 0;
}
