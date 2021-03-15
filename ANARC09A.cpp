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
	int otc=0,cto=0;
	string str,s;
	for(lld c=1;;c++)
	{
		cin>>str;
		if(str[0] == '-')
			break;
		for(int i=0;i<str.length()-1;i += 2)
		{
			s = str.substr(i,2);
			if(s == "{}")
				continue;
			else if(s == "}}")
			{
				if(otc != 0)
					otc--;
				else
					cto++;
			}
			else if(s == "{{")
				otc++;
			else if(s == "}{")
			{
				if(otc != 0)
					otc--;
				else
					cto++;
				otc++;
			}
		}
		cout<<c<<". "<<otc+cto<<endl;
		otc = 0,cto = 0;
	}
	return 0;
}
