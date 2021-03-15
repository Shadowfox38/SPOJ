#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

typedef vector<int> vi;
typedef long long int lld;

#define stack_clear(s)      while(!(s).empty()){(s).pop;}
#define si(x)				 scanf("%d",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define gcd(x,y)                         __gcd((x),(y))
#define fill(a,b)                        memset((a),(b),sizeof(a))
int check(string s)
{
	int l = s.length();
	l--;
	while(l--)
	{
		if(s[l] == 'm')
			return 1;
	}
	return 0;
}
int main()
{
	int t,num[3],flag[3]={0,0,0};
	si(t);
	string a,b,c,d,e;
	while(t--)
	{
		cin>>a>>d>>b>>e>>c;
		flag[0] = check(a);
		flag[1] = check(b);
		flag[2] = check(c);
		if(flag[0])
		{
			num[1] = stoi(b),num[2] = stoi(c);
			num[0] = num[2] - num[1];
		}
		if(flag[1])
		{
			num[0] = stoi(a),num[2] = stoi(c);
			num[1] = num[2] - num[0];
		}
		if(flag[2])
		{
			num[0] = stoi(a),num[1] = stoi(b);
			num[2] = num[1] + num[0];
		}
		printf("%d + %d = %d\n",num[0],num[1],num[2]);
		flag[0] = 0,flag[1] = 0,flag[2] = 0;
	}
	return 0;
}
