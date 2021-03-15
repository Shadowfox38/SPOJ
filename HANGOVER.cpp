#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

typedef vector<int> vi;
typedef long long int lld;

#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd((x),(y))
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	double c;
	scanf("%lf",&c);
	while(c!=0.00)
	{
		int i=3;
		double d=0.5;
		while(d<c)
		{
			d = double(d +1.0/i);
			i++;
		}
		printf("%d card(s)\n",i-2);
		scanf("%lf",&c);
	}
	return 0;
}
