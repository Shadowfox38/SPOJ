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
	int n,a[100010],f=0;
	si(n);
	while(n!=0)
	{
		f = 0;
		for(int i=1;i<=n;i++)
			si(a[i]);
		for(int i=1;i<=n;i++)
		{
			if(i == a[i])
				continue;
			else
				swap(a[i],a[a[i]]);
			if(i == a[i])
				continue;
			else
			{
				f = 1;
				break;
			}
		}
		if(f == 0)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
		si(n);
		f = 0;
	}
	return 0;
}
