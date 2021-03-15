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
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd((x),(y))
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int t,n1,n2,a;
	vi v1,v2;
	si(t);
	while(t--)
	{
		si(n1),si(n2);
		for(int i=0;i<n1;i++)
		{
			si(a);
			v1.pb(a);
		}
		for(int i=0;i<n2;i++)
		{
			si(a);
			v2.pb(a);
		}
		sort(v1.begin(),v1.begin()+v1.size(),greater<int>()),sort(v2.begin(),v2.begin()+v2.size(),greater<int>());
		while(v1.size()!=0 && v2.size()!=0)
		{
			if(v1.back()<v2.back())
				v1.pop_back();
			else
				v2.pop_back();
		}
		if(v2.size()==0)
			printf("Godzilla\n");
		if(v1.size()==0)
			printf("MechaGodzilla\n");
		v1.clear(),v2.clear();
	}
	return 0;
}
