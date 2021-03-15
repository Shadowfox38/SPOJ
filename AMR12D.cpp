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
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int t,f=0,len;
	string str;
	si(t);
	while(t--)
	{
		cin>>str;
		len = str.length();
		for(int i=0;i<len/2;i++)
		{
			if(str[i] != str[len-1-i])
			{
				f = 1;
				break;
			}
		}
		if(f)
			printf("NO\n");
		else
			printf("YES\n");
		f = 0;
	}
	return 0;
}
