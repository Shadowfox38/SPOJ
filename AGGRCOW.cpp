#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

typedef vector<int> vi;
typedef long long int lld;

#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd((x),(y))
#define fill(a,b)                        memset((a),(b),sizeof(a))
int c,n;
int x[100010];
int search(int l,int h)
{
	int d = l + ((h-l+1)/2)+((h-l+1)%2) - 1;
	int k=1,s1=0,s2=1;
	while(s2<n && k<c)
	{
		if(x[s2] - x[s1] >=d && s2<n)
		{
			k++;
			s1=s2;
			s2++;
		}
		while(x[s2] - x[s1] <d && s2<n)
			s2++;
	}
	if(k>=c)
	{
		if(h==l)
			return h;
		else
			return(max(d,search(d+1,h)));
	}
	else
	{
		if(h==l)
			return -1;
		else
			return(search(l,d-1));
	}
}
int main()
{
	int t,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
		}
		sort(&x[0],&x[n]);
		d=x[n-1] - x[0];
		printf("%d\n",search(1,d));
	}
	return 0;
}
