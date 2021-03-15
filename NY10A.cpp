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
int ans[8];
string str,pat[8] = {"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};
int main()
{
	int t,n;
	si(t);
	while(t--)
	{
		si(n);
		cin>>str;
		fill(ans,0);
		for(int i=0;i<str.length();i++)
		{
			for(int j=0;j<8;j++)
			{
				if(str.substr(i,3) == pat[j])
					ans[j]++;
			}
		}
		printf("%d ",n);
		for(int i=0;i<8;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
