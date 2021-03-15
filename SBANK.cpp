#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
#include<iomanip>
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
struct acc{int num[6];};
acc a[100010];
bool cmp(acc &x1,acc &x2)
{
	int *ptr1 = &x1.num[0],*ptr2 = &x2.num[0];
	for(int i=0;i<6;i++)
	{
		if(ptr1[i] < ptr2[i])
			return 1;
		if(ptr1[i] > ptr2[i])
			return 0;
	}
	return 1;
}
bool operator==(acc &x1,acc &x2)
{
	int *ptr1 = &x1.num[0],*ptr2 = &x2.num[0];
	for(int i=0;i<6;i++)
	{
		if(ptr1[i] != ptr2[i])
			return 0;
	}
	return 1;
}
int main()
{
	int t,n,xx,*ptr;
	si(t);
	while(t--)
	{
		si(n);
		for(int i=0;i<n;i++)
		{
			ptr = &a[i].num[0];
			for(int j=0;j<6;j++)
				si(xx),ptr[j] = xx;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			int c = 1;
			int j = i+1;
			while(j < n && a[j] == a[i])
				c++,j++;
			i = j-1;
			cout<<setfill('0')<<setw(2)<<a[i].num[0]<<" ";
			cout<<setfill('0')<<setw(8)<<a[i].num[1]<<" ";
			cout<<setfill('0')<<setw(4)<<a[i].num[2]<<" ";
			cout<<setfill('0')<<setw(4)<<a[i].num[3]<<" ";
			cout<<setfill('0')<<setw(4)<<a[i].num[4]<<" ";
			cout<<setfill('0')<<setw(4)<<a[i].num[5]<<" ";
			printf("%d\n",c);
		}
		printf("\n");
	}
	return 0;
}
