#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
#include<bitset>
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
string solve(int n)
{
	//printf("recieved %d\n",n);
	if(n == 0)
		return "0";
	if(n == 1)
		return "poop";
	if(n == 2)
		return "2";
	bitset<32> b(n);
	string str,temp;
	for(int i=31;i>=0;i--)
	{
		if(b[i] == 1)
		{
			str += "2(";
			temp = solve(i);
			if(temp == "poop")
				str.pop_back(),str.pb('+');
			else
				str = str + temp + ")+";
		}
	}
	str.pop_back();
	return str;
}
int main()
{
	int t,n;
	t = 7;
	while(t--)
	{
		si(n);
		string str = solve(n);
		cout<<n<<"="<<str<<endl;
	}
	return 0;
}
