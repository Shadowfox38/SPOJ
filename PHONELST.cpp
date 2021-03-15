#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
#include<unordered_map>
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
unordered_map<string,int> map;
int main()
{
	int t,n,f=0;
	string str[10010];
	si(t);
	while(t--)
	{
		si(n);
		for(int i=0;i<n;i++)
			cin>>str[i];
		for(int i=0;i<n;i++)
		{
			string hash;
			for(int j=0;j<str[i].length();j++)
			{
				hash = hash + str[i][j];
				map[hash]++;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(map[str[i]] > 1)
			{
				f = 1;
				break;
			}
		}
		if(f)
			printf("NO\n");
		else
			printf("YES\n");
		f = 0,map.clear();
	}
	return 0;
}
