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
#define sl(x)                            scanf("%lld",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define ff                               first
#define ss                               second
#define fill(a,b)                        memset((a),(b),sizeof(a))
pii *tree;
int xx;
void query(int l,int r)
{
	vi vec;
	while(l<r)
	{
		if((l&1) == 0)
		{
			if(l >= xx-1)
				vec.pb(tree[l].ff);
			else
				vec.pb(tree[l].ff),vec.pb(tree[l].ss);
			l++;
		}
		if((r&1) == 1)
		{
			if(r >= xx-1)
				vec.pb(tree[r].ff);
			else
				vec.pb(tree[r].ff),vec.pb(tree[r].ss);
			r--;
		}
		l = (l-1)/2,r = (r-1)/2;
	}
	if(l == r)
		vec.pb(tree[l].ff),vec.pb(tree[l].ss);
	sort(vec.begin(),vec.end(),greater<int>());
	printf("%d\n",vec[0]+vec[1]);
}
void update(int idx,int v)
{
	int c1,c2;
	vi vec;
	tree[idx] = mp(v,v);
	idx = (idx-1)/2;
	c1 = 2*idx + 1,c2 = 2*idx + 2;
	tree[idx] = mp(tree[c1].ff,tree[c2].ff);
	while(idx != 0)
	{
		idx = (idx-1)/2;
		vec.clear();
		c1 = 2*idx + 1,c2 = 2*idx + 2;
		vec.pb(tree[c1].ff),vec.pb(tree[c1].ss);
		vec.pb(tree[c2].ff),vec.pb(tree[c2].ss);
		sort(vec.begin(),vec.end(),greater<int>());
		tree[idx] = mp(vec[0],vec[1]);
	}
}
int main()
{
	int n,q,a,b;
	char ch;
	si(n);
	xx = (1<<int(ceil(log2(n))));
	tree = new pii[2*xx-1];
	for(int i=0;i<n;i++)
	{
		si(a);
		tree[xx-1+i] = mp(a,a);
	}
	for(int i=n;i<xx;i++)
		tree[xx-1+i] = mp(0,0);
	for(int i=xx-2;i>=0;i--)
	{
		int c1 = 2*i + 1;
		int c2 = 2*i + 2;
		if(c1 >= xx-1)
			tree[i] = mp(tree[c1].ff,tree[c2].ff);
		else
		{
			vi vec;
			vec.pb(tree[c1].ff),vec.pb(tree[c1].ss);
			vec.pb(tree[c2].ff),vec.pb(tree[c2].ss);
			sort(vec.begin(),vec.end(),greater<int>());
			tree[i] = mp(vec[0],vec[1]);
		}
	}
	si(q);
	while(q--)
	{
		scanf(" %c",&ch),si(a),si(b);
		ch == 'Q' ? query(xx+a-2,xx+b-2) : update(xx+a-2,b);
	}
}
