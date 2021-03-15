#include<iostream>
using namespace std;

typedef long long int lld;

#define si(x)				 scanf("%lld",&(x))
int a[10][5] = { {0},{0},{4,6,2,4,8},{4,1,3,9,7},{2,6,4},{0},{0},{4,1,7,9,3},{4,6,8,4,2},{2,1,9}  };
int main()
{
	lld t,x,y,m,r,ans;
	string str;
	si(t);
	while(t--)
	{
		cin>>str;
		si(y);
		x = str.back() - '0';
		m = a[x][0];
		ans = x;
		if(m)
			r = y%m,ans = a[x][1+r];
		if(!y)
			ans = 1;
		printf("%lld\n",ans);
	}
	return 0;
}
