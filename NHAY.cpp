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
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
long long int *f;
lld m,pos=-1,curr=0;
vector<lld> vec;
string p;
void print()
{
	lld spaces = max(m+2,lld(9)),used = 0;
	printf("\n-------------Failures---------------\n");
	for(lld i=0;i<=m;i++)
	{
		if(i == 0)
			used = 7,printf("/empty/");
		else
			used = i,cout<<p.substr(0,i);
		for(lld j=0;j<spaces-used;j++)
			printf(" ");
		printf("f[%lld] = %lld\n",i,f[i]);
	}
	printf("----------------End------------------\n\n");
}
void create()
{
	f = new lld[m+1];
	f[0] = 0;
	for(lld len=1;len<=m;len++)
	{
		lld suff=0,c=0;
		for(lld i=1;(i<len && i+c<len);c++)
		{
			if(p[i+c] == p[0+c])
				continue;
			else
				i++,c=-1;
		}
		f[len] = c;
	}
	//print();
}
void expand(char ch)
{
	if(ch == p[curr])
	{
		curr++;
		if(curr == m)
		{
			vec.pb(pos-m+1);
			curr = f[m];
		}
	}
	else
	{
		curr = f[curr];
		while(ch != p[curr] && curr != 0)
			curr = f[curr];
		if(ch == p[curr])
			curr++;
	}
}
int main()
{
	char ch,dummy;
	while(cin>>m)
	{
		if(ch == '2')
			printf("\n");
		cin>>p;
		create();
		scanf("%c\n",&dummy);
		while(ch != '\n')
		{
			scanf("%c",&ch);
			pos++;
			expand(ch);
		}
		for(int i=0;i<vec.size();i++)
			printf("%lld\n",vec[i]);
		curr = 0,pos = -1,ch = '2';
		delete[] f;
		vec.clear();
	}
	return 0;
}
