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
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i].idx<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
struct node{int csum,lsum,rsum,msum,idx;};
int xx;
node tree[131100];
node merge(node n1,node n2)
{
	node n;
	n.csum = n1.csum + n2.csum;
	n.lsum = max(n1.lsum,n1.csum + n2.lsum);
	n.rsum = max(n2.rsum,n1.rsum + n2.csum);
	n.msum = max(n1.msum,max(n2.msum,n1.rsum + n2.lsum));
	return n;
}
void find(int x1,int x2)
{
	vector<node> left;
	vector<node> right;
	node ans;
	while(x1 < x2)
	{
		if((x1&1) == 0)
			left.pb(tree[x1]),x1++;
		if((x2&1) == 1)
			right.pb(tree[x2]),x2--;
		x1 = (x1-1)/2;
		x2 = (x2-1)/2;
	}
	if(x1 == x2)
		left.pb(tree[x1]);
	reverse(right.begin(),right.end());
	for(int i=0;i<right.size();i++)
		left.pb(right[i]);
	ans = left[0];
	for(int i=1;i<left.size();i++)
		ans = merge(ans,left[i]);
	printf("%d\n",ans.msum);
}
void print()
{
	int idx = 0;
	int c = 1;
	printf("------------------Printing-------------------\n");
	while(idx < 2*xx - 1)
	{
		for(int j=0;j<c;j++,idx++)
			printf("%d ",tree[idx].msum);
		printf("\n");
		c = 2*c;
	}
	printf("---------------------end---------------------\n");
}
int main()
{
	int n,q,temp,idx,x,y;
	si(n);
	xx = int(pow(2.0,ceil(log2(n))));
	for(int i=0;i<n;i++)
	{
		si(temp);
		idx = xx-1+i;
		tree[idx].msum = tree[idx].csum = tree[idx].lsum = tree[idx].rsum = temp;
		tree[idx].idx = idx;
	}
	for(int i=n;i<xx;i++)
	{
		idx = xx-1+i;
		tree[idx].msum = tree[idx].csum = tree[idx].lsum = tree[idx].rsum = -15010;
		tree[idx].idx = idx;
	}
	for(int i=xx-2;i>=0;i--)
	{
		int c1 = 2*i + 1;
		int c2 = 2*i + 2;
		tree[i].csum = tree[c1].csum + tree[c2].csum;
		tree[i].msum = max(tree[c1].msum,max(tree[c2].msum,tree[c1].rsum + tree[c2].lsum));
		tree[i].lsum = max(tree[c1].lsum,tree[c1].csum + tree[c2].lsum);
		tree[i].rsum = max(tree[c2].rsum,tree[c1].rsum + tree[c2].csum);
		tree[i].idx = i;
	}
	si(q);
	for(int i=0;i<q;i++)
	{
		si(x),si(y);
		find(xx-1 + x-1,xx-1 + y-1);
	}
	return 0;
}
