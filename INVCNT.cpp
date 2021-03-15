#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<utility>
#include<set>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long int lld;

#define mp(a,b)                          make_pair((a),(b))
#define stack_clear(s)      while(!(s).empty()){(s).pop;}
#define si(x)				 scanf("%d",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd((x),(y))
#define fill(a,b)                        memset((a),(b),sizeof(a))
lld c=0;
void merge(int *a,int low,int mid,int high)
{
	int n1 = mid-low+1,n2 = high-mid;
	int l[n1],r[n2],x=0,y=0;
	for(int i=0;i<n1;i++)
		l[i] = a[low+i];
	for(int i=0;i<n2;i++)
		r[i] = a[mid+1+i];
	while(x<n1 && y<n2)
	{
		if(l[x]<=r[y])
		{
			a[low] = l[x];
			x++;
		}
		else
		{
			a[low] = r[y];
			y++;
			c = c + 1LL*(n1-x);
		}
		low++;
	}
	while(x<n1)
	{
		a[low] = l[x];
		x++;
		low++;
	}
	while(y<n2)
	{
		a[low] = r[y];
		y++;
		low++;
	}
}
void split(int *a,int low,int high)
{
	if(low!=high)
	{
		int mid = (low+high)/2;
		split(a,low,mid);
		split(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int t,n,*a;
	string blank;
	si(t);
	while(t--)
	{
		si(n);
		a = new int[n];
		for(int i=0;i<n;i++)
			si(a[i]);
		cin.ignore();
		getline(cin,blank);
		split(a,0,n-1);
		printf("%lld\n",c);
		c = 0;
		delete[] a;
	}
	return 0;
}
