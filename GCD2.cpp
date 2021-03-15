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
#define si(x)				 scanf("%d",&(x))
#define sl(x)                            scanf("%lld",&(x))
#define pb          			 push_back
string megamod(string a,string b)
{
	if(a.length() <= 17 && b.length() <= 17)
	{
		lld x = stol(a);
		lld y = stol(b);
		return to_string(x%y);
	}
	else if(b.length() > 17)
		return a;
	else
	{
		lld res = 0;
		for(int i=0;i<a.length();i++)
			res = (res*10 + (a[i]-'0'))%stol(b);
		return to_string(res);
	}
}
string gcd(string a,string b)
{
	if(b == "0")
		return a;
	else
		return gcd(b,megamod(a,b));

}
int main()
{
	int t;
	string a,b;
	si(t);
	while(t--)
	{
		cin>>a>>b;
		cout<<gcd(a,b)<<endl;
	}
	return 0;
}
