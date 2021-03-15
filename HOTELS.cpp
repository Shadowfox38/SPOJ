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
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int n,m,v[300010],s=0,e=0;
	lld curr=0,res=-1;
	si(n),si(m);
	for(int i=0;i<n;i++)
		si(v[i]);
	while(s<n)
	{
		while(e<n && curr+v[e] <= 1LL*m)
		{
			curr += v[e];
			e++;
		}
		if(curr > res)
			res = curr;
		curr = curr - v[s];
		s++;
		if(s >= e)
			e = s,curr = 0;
	}
	printf("%lld\n",res);
	return 0;
}
