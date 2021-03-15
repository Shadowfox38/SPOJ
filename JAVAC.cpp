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
	string str;
	while(cin>>str)
	{
		int c=0,j=0;
		for(int i=0;i<str.length();i++)
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
				j = 1;
			if(str[i] >= 'A' && str[i] <= 'Z' && i == 0)
				c = 1;
			if(str[i] == '_')
				c = 1;
			if(str[i] == '_' && (i == 0 || i == str.length()-1 || str[i-1] == '_'))
				j = 1;
		}
		if(j && c)
			printf("Error!");
		else if(j)
		{
			for(int i=0;i<str.length();i++)
			{
				if(str[i] >= 'A' && str[i] <= 'Z')
					str[i] = str[i] - 'A' + 'a',printf("_");
				printf("%c",str[i]);
			}
		}
		else if(c)
		{
			for(int i=0;i<str.length();i++)
			{
				if(str[i] == '_')
				{
					str[i+1] = str[i+1] - 'a' + 'A';
					continue;
				}
				printf("%c",str[i]);
			}
		}
		else
			cout<<str;
		printf("\n");
	}
	return 0;
}
