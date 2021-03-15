#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long int lld;

#define M                                1000000007
#define mp(a,b)                          make_pair((a),(b))
#define stack_clear(s)      while(!(s).empty()){(s).pop();}
#define si(x)				 scanf("%d",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<a[v[i]]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int n,k,a[100010],s,e;
	deque<int> q;
	si(n);
	for(int i=0;i<n;i++)
		si(a[i]);
	si(k);
	for(int i=0;i<k;i++)
	{
		while(q.size() != 0 && a[q.back()] < a[i])
			q.pop_back();
		q.pb(i);
	}
	printf("%d ",a[q[0]]);
	s = 1,e = k;
	while(e < n)
	{
		if(s > q[0])
			q.pop_front();
		while(q.size() != 0 && a[q.back()] < a[e])
			q.pop_back();
		q.pb(e);
		printf("%d ",a[q[0]]);
		s++,e++;
	}
	printf("\n");
	return 0;
}
