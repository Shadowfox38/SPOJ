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
lld *tree,*lazy,*len;
int n;
/*
void printtree(int xx)
{
	int l=1,c;
	c = l;
	if(xx == 0)
	{
		for(int i=0;i<2*n-1;i++)
		{
			printf("tree[%d] = %lld    ",i,tree[i]);
			c--;
			if(c == 0)
				printf("\n"),l = 2*l, c = l;
		}
	}
	else
	{
		for(int i=0;i<2*n-1;i++)
		{
			printf("lazy[%d] = %lld    ",i,lazy[i]);
			c--;
			if(c == 0)
				printf("\n"),l = 2*l, c = l;
		}
	}
}
*/
void update(int xx,lld v)
{
	xx = (xx-1)/2;
	while(xx != 0)
	{
		tree[xx] += v;
		//printf("updated tree[%d] by %lld\n",xx,v); //debug
		xx = (xx-1)/2;
	}
	tree[xx] += v;
	//printf("updated tree[%d] by %lld\n",xx,v); //debug
}
void propogate(int xx)
{
	if(xx <= n-2)
	{
		lazy[2*xx + 1] += lazy[xx];
		lazy[2*xx + 2] += lazy[xx];
	}
	tree[xx] += len[xx]*lazy[xx];
	lazy[xx] = 0;
}
void freefall(int xx)
{
	vi parents;
	while(xx != 0)
	{
		parents.pb(xx);
		xx = (xx-1)/2;
	}
	parents.pb(xx);
	for(int i=parents.size()-1;i>=0;i--)
	{
		if(lazy[parents[i]])
			propogate(parents[i]);
	}
}
void add(int x,int y,int v,int n)
{
	//printf("------------Adding-----------\n"); //debug
	for(x+=n-2,y+=n-2;x<=y;x = (x-1)/2,y = (y-1)/2)
	{
		if(x == y)
		{
			tree[x] += len[x]*v;
			update(x,len[x]*v);
			if(x <= n-2)
			{
				lazy[2*x + 1] += v;
				lazy[2*x + 2] += v;
				propogate(x);
			}
			break;
		}
		if((x&1) == 0)
		{
			tree[x] += len[x]*v;
			update(x,len[x]*v);
			if(x <= n-2)
			{
				lazy[2*x + 1] += v;
				lazy[2*x + 2] += v;
				propogate(x);
			}
			x++;
		}
		if((y&1) == 1)
		{
			tree[y] += len[y]*v;
			update(y,len[y]*v);
			if(y <= n-2)
			{
				lazy[2*y + 1] += v;
				lazy[2*y + 2] += v;
				propogate(y);
			}
			y--;
		}
	}
	//printtree(0); //debug
	//printtree(1); //debug
	//printf("-------------End-------------\n\n"); //debug
}
void print(int x,int y,int n)
{
	lld res = 0;
	//printf("------------Printing-------------\n"); //debug
	for(x+=n-2,y+=n-2;x<=y;x = (x-1)/2,y = (y-1)/2)
	{
		if(x == y)
		{
			freefall(x);
			//printf("adding tree[%d] = %lld to res\n",x,tree[x]); //debug
			res += tree[x];
			break;
		}
		if((x&1) == 0)
		{
			freefall(x);
			//printf("adding tree[%d] = %lld to res\n",x,tree[x]); //debug
			res += tree[x];
			x++;
		}
		if((y&1) == 1)
		{
			freefall(y);
			//printf("adding tree[%d] = %lld to res\n",y,tree[y]); //debug
			res += tree[y];
			y--;
		}
	}
	printf("%lld\n",res);
	//printf("----------------End---------------\n\n"); //debug
}
int main()
{
	int t,c,x,y,v,m;
	double p;
	string q;
	si(t);
	while(t--)
	{
		si(n),si(c);
		p = log2(double(n));
		if(p - floor(p) != double(0))
			p = ceil(p);
		n = 1<<int(p);
		tree = new lld[2*n - 1]();
		lazy = new lld[2*n - 1]();
		len = new lld[2*n - 1]();
		for(int i=2*n-2;i>=0;i--)
		{
			if(i > n-2)
				len[i] = 1;
			else
				len[i] = 2*len[2*i + 1];
		}
		while(c--)
		{
			si(m);
			if(m == 0)
			{
				si(x),si(y),si(v);
				add(x,y,v,n);
			}
			else
			{
				si(x),si(y);
				print(x,y,n);
			}
		}
		delete[] tree;
		delete[] lazy;
		delete[] len;
	}
	return 0;
}
