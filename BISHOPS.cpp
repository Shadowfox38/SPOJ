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
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int c=0,res;
	string s,ans;
	while(cin>>s)
	{
		if(s != "1")
		{
			for(int i=s.length()-1;i>=0;i--)
			{
				res = 2*(s[i] - '0') + c;
				c = res/10;
				res = res%10;
				ans = char('0' + res) + ans;
			}
			if(c)
				ans = char('0' + c) + ans;
			if(ans.back() >= '2')
				ans.back() -= 2;
			else
			{
				ans.back() = ans.back() + 8;
				auto it = ans.rbegin() + 1;
				while(*it == '0')
					*it = '9',it++;
				*it -= 1;
				if(*it == '0' && it == ans.rend()-1)
					ans.erase(ans.begin());
			}
		}
		else
			ans = s;
		cout<<ans<<endl;
		ans.clear();
		c = 0;
	}
	return 0;
}
