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
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int vis[10010],n1,n2;
vi num,dis;
bool prime(int xx)
{
	for(int i=2;i<=sqrt(xx);i++)
	{
		if(xx%i == 0)
			return 0;
	}
	return 1;
}
vi getnew(int n)
{
	int x1,x2,x3,x4,xx;
	vi next;
	x1 = (n/10)*10;
	x2 = (n%10) + (n/100)*100;
	x3 = (n%100) + (n/1000)*1000;
	x4 = (n%1000);
	for(int i=0;i<10;i++)
	{
		xx = x1 + i;
		if(vis[xx] == -1 && prime(xx))
			vis[xx] = 1,next.pb(xx);
		xx = x2 + 10*i;
		if(vis[xx] == -1 && prime(xx))
			vis[xx] = 1,next.pb(xx);
		xx = x3 + 100*i;
		if(vis[xx] == -1 && prime(xx))
			vis[xx] = 1,next.pb(xx);
		xx = x4 + 1000*i;
		if(i != 0 && vis[xx] == -1 && prime(xx))
			vis[xx] = 1,next.pb(xx);
	}
	return next;
}
int make()
{
	while(num.size() != 0)
	{
		if(num[0] == n2)
			return dis[0];
		int d = dis[0];
		vi next = getnew(num[0]);
		num.erase(num.begin());
		dis.erase(dis.begin());
		for(int i=0;i<next.size();i++)
		{
			num.pb(next[i]);
			dis.pb(d+1);
		}
	}
	return -1;
}
int main()
{
	int t,ans;
	si(t);
	while(t--)
	{
		si(n1),si(n2);
		fill(vis,-1);
		num.pb(n1),dis.pb(0);
		vis[n1] = 1;
		ans = make();
		ans == -1 ? printf("Impossible\n") : printf("%d\n",ans);
		num.clear(),dis.clear();
	}
	return 0;
}
