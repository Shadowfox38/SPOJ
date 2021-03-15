#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
#include<set>
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
int digits(int xx)
{
	int d = 10;
	while((1LL*xx) / lld(pow(10.0,double(d))) == 0)
		d--;
	return d+1;
}
int breaker(int xx)
{
	int res=0;
	int d = digits(xx);
	for(int i=1;i<=d;i++)
	{
		int num = xx % 10;
		res += num*num;
		xx = xx/10;
	}
	return res;
}
int main()
{
	int n,res=0,c=0;
	set<int> s;
	si(n);
	s.insert(n);
	while(res != 1 && s.find(res) == s.end())
	{
		if(c != 0)
			s.insert(res);
		res = breaker(n);
		n = res;
		c++;
	}
	if(res == 1)
		printf("%d\n",c);
	else
		printf("-1\n");
}
