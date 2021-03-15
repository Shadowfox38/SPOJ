#include<iostream>
#include<cmath>
using namespace std;
int find(int a)
{
	int digit,temp=-1,i=1;
	digit= a%10;
	while(temp!=digit)
	{
		i++;
		temp=pow((float)a,i);
		temp=temp%10;
	}
	return i-1;
}
int main()
{
	int t,a,b,c,ans;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		c = find(a);
		if(c>b)
		{
			ans=pow((float)a,b);
			ans= ans%10;
			cout<<ans<<endl;
		}
		else
		{
			int temp,power;
			if(b%c==0)
				temp=(b/c)-1;
			else
				temp=b/c;
			power=b-((c*temp)+1) + 1;
			ans=pow((float)a,power);
			ans=ans%10;
			cout<<ans<<endl;
		}
	}
}
