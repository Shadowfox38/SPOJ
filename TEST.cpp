#include<iostream>
#include<cstdio>
using namespace std;
#define reset   "\033[0m"
#define black   "\033[30m"      /* Black */
#define red     "\033[31m"      /* Red */
#define green   "\033[32m"      /* Green */
#define yellow  "\033[33m"      /* Yellow */
#define blue    "\033[34m"      /* Blue */
#define magenta "\033[35m"      /* Magenta */
#define cyan    "\033[36m"      /* Cyan */
#define white   "\033[37m"      /* White */
#define bold_black   "\033[1m\033[30m"      /* Bold Black */
#define bold_red     "\033[1m\033[31m"      /* Bold Red */
#define bold_green   "\033[1m\033[32m"      /* Bold Green */
#define bold_yellow  "\033[1m\033[33m"      /* Bold Yellow */
#define bold_blue    "\033[1m\033[34m"      /* Bold Blue */
#define bold_magenta "\033[1m\033[35m"      /* Bold Magenta */
#define bold_cyan    "\033[1m\033[36m"      /* Bold Cyan */
#define bold_white   "\033[1m\033[37m"      /* Bold White */
int main()
{
	int n=0,flag=0;
	while(cin>>n,n!=EOF)
	{
		if(n==42)
			flag=1;
		if(!flag)
			cout<<n<<endl;

	}
	return 0;
}
