#include<iostream>
#include<string>
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
string str;
void copy(int s,int e)
{
	for(int i=0;i<=e/2;i++)
	{
		str[e-i]=str[s+i];
	}
	cout<<str<<endl;
}
int main()
{
	int t,s=0,e,idx;
	bool flag1=1;
	bool flag2=0;
	cin>>t;
	while(t--)
	{
		cin>>str;
		e=str.size()-1;
		for(int i=0;i<=e;i++)
		{
			if(str[i]!='9')
			{
				flag1=0;
				break;
			}
		}
		if(flag1==1)
		{
			cout<<1;
			for(int i=1;i<=e;i++)
				cout<<0;
			cout<<1<<endl;
		}
		else
		{
			idx=e/2;
			if(e%2==0)                   //odd
				idx--;
			while(str[s+idx]>=str[e-idx] && idx>=0)
			{
				if(str[s+idx]>str[e-idx])
				{
					copy(s,e);
					flag2=1;
					break;
				}
				idx--;
			}
			if(flag2==0)
			{
				int idx1=e/2;
				if(e%2==0)            //odd
					idx1--;
				while(str[s+idx1]=='9' && idx1>=idx)
				{
					idx1--;
				}
				if(e%2!=0)
				{
					str[s+idx1]++;
					str[e-idx1]=str[s+idx1];
					if(idx1!=e/2)
					{
						for(int i=1;i<=e/2-idx1;i++)
						{
							str[s+idx1+i]='0';
							str[e-idx1-i]='0';
						}
						copy(s,e);
					}
					else
						copy(s,e);
				}
				else
				{
					if(str[s+e/2]!='9')
					{
						str[s+e/2]++;
						copy(s,e);
					}
					else
					{
						str[e/2]='0';
						str[s+idx1]++;
						str[e-idx1]=str[s+idx1];
						for(int i=1;i<e/2-idx1;i++)
						{
							str[s+idx1+i]='0';
							str[e-idx1-i]='0';
						}
						copy(s,e);
					}
				}
			}
			flag2=0;
			flag1=1;
		}
	}
}
