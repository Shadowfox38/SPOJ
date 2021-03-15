#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
#include<unordered_map>
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
struct node
{
	int l,r;
	int idx;
	int ans = 0;
};
int a[30010],n,q;
node mo[200010];
bool mosort(node &n1,node &n2)
{
	int a = int(double(n1.l)/sqrt(n));
	int b = int(double(n2.l)/sqrt(n));
	if(a != b)
		return (a < b);
	return (n1.r < n2.r);
}
bool antimosort(node &n1,node &n2){return (n1.idx < n2.idx);}
void calculate()
{
	int cx=mo[0].l,cy=mo[0].r;
	unordered_map<int,int> map;
	for(int i=cx;i<=cy;i++)
	{
		if(map.count(a[i]))
			map[a[i]]++;
		else
			map[a[i]] = 1;
	}
	mo[0].ans = map.size();
	for(int i=1;i<q;i++)
	{
		while(cx < mo[i].l)
		{
			if(map.count(a[cx]))
				map[a[cx]] == 1 ? map.erase(a[cx]) : map[a[cx]]--;
			cx++;
		}
		while(cx > mo[i].l)
		{
			cx--;
			map.count(a[cx]) ? map[a[cx]]++ : map[a[cx]] = 1;
		}
		if(cy < mo[i].l)
			cy = mo[i].l - 1;
		while(cy < mo[i].r)
		{
			cy++;
			map.count(a[cy]) ? map[a[cy]]++ : map[a[cy]] = 1;
		}
		while(cy > mo[i].r)
		{
			if(map.count(a[cy]))
				map[a[cy]] == 1 ? map.erase(a[cy]) : map[a[cy]]--;
			cy--;
		}
		mo[i].ans = map.size();
	}
}
int main()
{
	int xx,yy;
	si(n);
	for(int i=0;i<n;i++)
		si(a[i]);
	si(q);
	for(int i=0;i<q;i++)
	{
		mo[i].idx = i;
		si(xx),si(yy);
		mo[i].l = xx-1;
		mo[i].r = yy-1;
	}
	sort(mo,mo+q,mosort);
	calculate();
	sort(mo,mo+q,antimosort);
	for(int i=0;i<q;i++)
		printf("%d\n",mo[i].ans);
	return 0;
}
