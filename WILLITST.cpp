#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

typedef vector<int> vi;
typedef long long int lld;

#define si(x)				 scanf("%d",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd((x),(y))
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	bool flag = false;
	lld n;
	scanf("%lld",&n);
	while(n>1)
	{
		if(n%2==0)
			n=n/2;
		else
		{
			flag = true;
			break;
		}
	}
	if(flag)
		printf("NIE\n");
	else
		printf("TAK\n");
	return 0;
}
