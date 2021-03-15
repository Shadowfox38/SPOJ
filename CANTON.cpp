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
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int t,n,p,temp,xx,x,d;
	si(t);
	while(t--)
	{
		si(n);
		temp = sqrt(1+8*n);
		temp = temp + temp%2 + 1;
		xx = (temp - 1)/2;
		x = xx - 1;
		d = n - (x*xx)/2;
		if(d == 0)
			x--,d++;
		x++,d--;
		if(xx%2 != 0)
			printf("TERM %d IS %d/%d\n",n,x-d,1+d);
		else
			printf("TERM %d IS %d/%d\n",n,1+d,x-d);
	}
	return 0;
}
