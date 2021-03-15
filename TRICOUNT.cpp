#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long int lld;
#define si(x)				 scanf("%d",&(x))
#define sl(x)                            scanf("%llu",&(x))
int main()
{
	int t;
	si(t);
	while(t--)
	{
		unsigned long long int n;
		sl(n);
		printf("%llu\n",(n*(n+2)*(2*n+1))/8);
	}
	return 0;
}
