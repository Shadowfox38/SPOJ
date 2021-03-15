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
#define si(x)				 scanf("%lld",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	lld t,n,d,a,x,y,z;
	si(t);
	while(t--)
	{
		si(x),si(y),si(z);
		n = (2*z)/(x+y);
		d = (y-x)/(n-5);
		a = x - (2*d);
		printf("%lld\n",n);
		for(int i=0;i<n;i++)
		{
			if(i == n-1)
				printf("%lld\n",a + (i*d));
			else
				printf("%lld ",a + (i*d));
		}
	}
	return 0;
}
