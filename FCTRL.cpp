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
int main()
{
	int t,n,x,y,temp,power;
	cin>>t;
	while(t--)
	{
		x=0,y=0,temp=1,power=1;
		cin>>n;
		while(temp!=0)
		{
			temp=n/((int)pow(2.0,power));
			power++;
			x=x+temp;
		}
		temp=1;
		power=1;
		while(temp!=0)
		{
			temp=n/((int)pow(5.0,power));
			power++;
			y=y+temp;
		}
		cout<<min(x,y)<<endl;

	}
}
