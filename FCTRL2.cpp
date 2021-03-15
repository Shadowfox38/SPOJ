#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void display(vector<int> vi)
{
	for(int i=vi.size()-1;i>=0;i--)
	{
		cout<<vi[i];
	}
	cout<<endl;
}
vector<int> v1,v2,v3;
int a[200]={0};
void copy()
{
	int i;
	v1.clear();
	for(i=199;i>=0;i--)
	{
		if(a[i]!=0)
		{
			break;
		}
	}
	for(int j=0;j<=i;j++)
	{
		v1.push_back(a[j]);
	}
	for(i=0;i<200;i++)
	{
		a[i]=0;
	}

}
void add()
{
	int s3=v3.size(),c=0,j;
	for(int i=0;i<s3;i++)
	{
		a[i]=a[i]+v3[i]+c;
		c=a[i]/10;
		a[i]=a[i]%10;
		if(i==s3-1)
		{
			j=i;
			j++;
			for(int k=j;k<200;k++)
			{
				a[k]=a[k]+c;
				c=a[k]/10;
				a[k]=a[k]%10;
			}
		}
	}
}
int digits(int n)
{
	int i=1;
	while(n/10!=0)
	{
		i++;
		n=n/10;
	}
	return i;
}
void init (int n,int m)
{
	int d = digits(n),temp;
	v2.clear();
	for(int i=0;i<d;i++)
	{
		if(m==2)
			v2.push_back(n%10);
		if(m==1)
			v1.push_back(n%10);
		n=n/10;
	}
}
void multiply()
{
	int s1=v1.size(),s2=v2.size(),temp,c=0;
	for(int i=0;i<s2;i++)
	{
		for(int k=0;k<i;k++)
		{
			v3.push_back(0);
		}
		c=0;
		for(int j=0;j<s1;j++)
		{
			temp=(v2[i]*v1[j])+c;
			c=temp/10;
			v3.push_back(temp%10);
			if(j==s1-1)
				v3.push_back(c);
		}
		add();
		v3.clear();
	}
}
int main()
{
	v1.reserve(200);
	v3.reserve(200);
	int t,p,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		p=n-1;
		init(n,1);
		while(p>1)
		{
			init(p,2);
			multiply();
			copy();
			p--;
		}
		display(v1);
		v1.clear();
	}
	return 0;
}
