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
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	char ch;
	lld t,x,y;
	si(t);
	while(t--)
	{
		si(x);
		scanf(" %c",&ch);
		while(ch != '=')
		{
			si(y);
			if(ch == '+')
				x = x + y;
			if(ch == '-')
				x = x - y;
			if(ch == '*')
				x = x * y;
			if(ch == '/')
				x = x / y;
			scanf(" %c",&ch);
		}
		printf("%lld\n",x);
	}
	return 0;
}
