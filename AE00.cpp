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
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=sqrt(n);i++)
	{
		sum = sum + (n/i) - (i-1);
	}
	cout<<sum<<endl;
	return 0;
}
