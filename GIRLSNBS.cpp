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
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int g,b;
	float ans;
	si(g),si(b);
	while(g != -1)
	{
		if(b<g)
			swap(b,g);
		ans = ceil(float(b)/float(g+1));
		printf("%.0f\n",ans);
		si(g),si(b);
	}
	return 0;
}
