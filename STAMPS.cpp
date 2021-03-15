#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

typedef vector<int> vi;
typedef long long int lld;

#define stack_clear(s)      while(!(s).empty()){(s).pop;}
#define si(x)				 scanf("%d",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd((x),(y))
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int t,c = 1,a[1000];
	si(t);
	while(t--)
	{
		int n,f,j=0,sum=0;
		si(n),si(f);
		for(int i=0;i<f;i++)
		{
			si(a[i]);
		}
		sort(a,a+f,greater<int>());
		for(int i=0;i<f;i++)
		{
			if(sum<n)
			{
				sum += a[i];
				j++;
			}
			else
				break;
		}
		printf("Scenario #%d:\n",c);
		if(sum>=n)
			printf("%d\n\n",j);
		else
			printf("impossible\n\n");
		c++;
	}
	return 0;
}
