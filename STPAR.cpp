#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

typedef vector<int> vi;
typedef long long int lld;

#define stack_clear(s)      while(!(s).empty()){(s).pop();}
#define si(x)				 scanf("%d",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd((x),(y))
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int n,a[1000],flag=0,c=1;
	stack<int> s;
	while(si(n) && n!=0)
	{
		for(int i=0;i<n;i++)
			si(a[i]);
		for(int i=0;i<n;i++)
		{
			if(a[i] != c)
			{
				if(s.empty())
					s.push(a[i]);
				else
				{
					if(s.top() == c)
					{
						s.pop();
						c++;
						i--;
					}
					else
					{
						if(s.top()>a[i])
							s.push(a[i]);
						else
						{
							printf("no\n");
							flag = 1;
							break;
						}
					}
				}
			}
			else
				c++;
		}
		if(flag == 0)
			printf("yes\n");
		flag = 0;
		stack_clear(s);
		c = 1;
	}
	return 0;
}
