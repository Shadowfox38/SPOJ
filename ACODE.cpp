#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
void display(vector<auto> vi)
{
	for(int i=0;i<vi.size();i++)
	{
		cout<<vi[i]<<" ";
	}
	cout<<endl;
}
#define pb           push_back
#define reset        "\033[0m"
#define black        "\033[30m"
#define red          "\033[31m"
#define green        "\033[32m"
#define yellow       "\033[33m"
#define blue         "\033[34m"
#define magenta      "\033[35m"
#define cyan         "\033[36m"
#define white        "\033[37m"
#define bold_black   "\033[1m\033[30m"
#define bold_red     "\033[1m\033[31m"
#define bold_green   "\033[1m\033[32m"
#define bold_yellow  "\033[1m\033[33m"
#define bold_blue    "\033[1m\033[34m"
#define bold_magenta "\033[1m\033[35m"
#define bold_cyan    "\033[1m\033[36m"
#define bold_white   "\033[1m\033[37m"
long long int fib(int x)
{
	long long int t=0;
	if(x==1 || x==0)
		return 1;
	else
		t = fib(x-1) + fib(x-2);
	return t;
}
int main()
{
	long long int ans=0;
	string str;
	vector<int> vi;
	vi.reserve(5000);
	while(cin>>str && str[0]!='0')
	{
		int p=0,c=0;
		for(int i=0;i<str.length()-1;i++)
		{
			if(str[i] =='0')
			{
				if(c>=2)
				{
					p-=2;
					c-=2;
				}
				else
					p--;
				if(c>=2)
					vi.pb(c);
				c=0;
				continue;
			}
			if((str[i] -'0')*10 +str[i+1] -'0' <=26)
			{
				p++;
				c++;
			}
			else
			{
				if(c>=2)
					vi.pb(c);
				c=0;
			}
		}
		if(str[str.length()-1]=='0')
		{
			if(c>=2)
			{
				p-=2;
				c-=2;
			}
			else
				p--;
			if(c>=2)
				vi.pb(c);
			c=0;
	
		}
		if(c>=2)
			vi.push_back(c);
		c=0;
		for(int i=0;i<vi.size();i++)
		{
			p = p - vi[i];
		}
		ans=int(pow(2.0,p));
		for(int i=0;i<vi.size();i++)
		{
			ans = ans * fib(vi[i]+1);
		}
		cout<<ans<<endl;
		vi.clear();
	}
	return 0;
}
