#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
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
int counter(int num)
{
	int digits=0;
	while(num!=0)
	{
		digits++;
		num=num/10;
	}
	return digits;
}
int rev(int x,int d)
{
	int y=0;
	int t=0;
	do {
		if(t!=0)
			x=x/10;
		y=y+((x%10)*((int)pow(10.0,d-t-1)));
		t++;
	}while(x/10!=0);
	return y;
}
int main()
{
	int t,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		a=rev(a,counter(a));
		b=rev(b,counter(b));
		c=a+b;
		c=rev(c,counter(c));
		cout<<c<<endl;
	}
	return 0;
}
