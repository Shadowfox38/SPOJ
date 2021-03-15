#include<iostream>
#include<cmath>
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
void brute(int p)
{
	int f=0;
	for(int i=2;i<=sqrt(p);i++)
	{
		if(p%i==0)
		{
			f=1;
			break;
		}
	}
	if(!f)
		cout<<p<<endl;
	f=0;
}
int main()
{
	int t,m,n,p1,p2,p;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>m>>n;
		p1=m/6;
		p2=n/6;
		p2++;
		for(int k=p1;k<=p2;k++)
		{
			p=6*k-1;
			if(p>=m && p<=n)
				brute(p);
			if(k!=0)
				p=p+2;
			if(p>=m && p<=n)
				brute(p);
			if(2>=m && 2<=n && k==0)
				cout<<2<<endl;
			if(3>=m && 3<=n && k==0)
				cout<<3<<endl;
		}
		cout<<endl;
	}
	return 0;
}
