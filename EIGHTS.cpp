#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

typedef vector<int> vi;
typedef long long int lld;

#define display(v)          for(int i=0;i<v.size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd(x,y)
#define fill(a,b)                        memset(a,b,sizeof(a))
int main()
{
	int t;
	lld k,temp;
	cin>>t;
	while(t--)
	{
		cin>>k;
		if(k>=5)
			cout<<(k-1)/4;
		if(k%4 ==0)
			cout<<"942"<<endl;
		else if(k%4 ==1)
			cout<<"192"<<endl;
		else if(k%4 ==2)
			cout<<"442"<<endl;
		else if(k%4 ==3)
			cout<<"692"<<endl;
	}
}
