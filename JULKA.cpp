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
		cout<<vi[i];
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
int main()
{
	int j=10;
	string a,b,x,y;
	while(j--)
	{
		cin>>a>>b;
		int c=0;
		int l1=a.length();
		int l2=b.length();
		l1--,l2--;
		while(l1>=0 && l2>=0)
		{
			a[l1] = a[l1]-'0';
			b[l2] = b[l2]-'0';
			a[l1] = a[l1] + b[l2] + c;
			c = a[l1]/10;
			a[l1] = a[l1] % 10;
			a[l1] = a[l1] +'0';
			b[l2] = b[l2] +'0';
			l1--;
			l2--;
		}
		while(l1>=0 && c!=0)
		{
			a[l1] = a[l1]-'0'+c;
			c = a[l1]/10;
			a[l1] = a[l1]%10;
			a[l1] = a[l1] + '0';
			l1 --;
		}
		if(c!=0)
		{
			a = "0" + a;
			a[0] = c%10;
			a[0] = a[0] +'0';
		}
		c=0;
		for(int i=0;i<a.length();i++)
		{
			a[i] = a[i] -'0';
			if(i==0)
			{
				if(a[i]<2)
					c = a[i];
				else
					x.pb((a[i]/2) +'0');
				c = a[i]%2;
			}
			else
			{
				x.pb(((c*10+a[i])/2) +'0');
				c = (c*10+a[i])%2;
			}
			a[i] = a[i] +'0';
		}
		l1=x.length();
		l2=b.length();
		l1--,l2--;
		c=0;
		while(l1>=0 && l2>=0)
		{
			y = "0" + y;
			x[l1] -= '0';
			b[l2] -= '0';
			y[0] = x[l1] - b[l2] - c;
			if(y[0]<0)
			{
				c = 1;
				y[0] +=10;
			}
			else
				c = 0;
			y[0] +='0';
			x[l1] +='0';
			b[l2] +='0';
			l1--;
			l2--;
		}
		while(l1>=0)
		{
			y = "0" + y;
			x[l1] -= '0';
			y[0] = x[l1] - c;
			if(y[0]<0)
			{
				c=1;
				y[0] +=10;
			}
			else
				c=0;
			x[l1] += '0';
			y[0] += '0';
			l1--;
		}
		cout<<x<<endl;
		int k=0,flag=0;
		while(y[k]=='0')
			k++;
		for(k;k<y.length();k++)
		{
			flag=1;
			cout<<y[k];
		}
		if(flag==0)
			cout<<0;
		cout<<endl;
		k=0;flag=0;
		x.clear();
		y.clear();
	}
}
