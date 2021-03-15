#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<string.h>
#include<utility>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long int lld;

#define M                                1000000007
#define mp(a,b)                          make_pair((a),(b))
#define stack_clear(s)      while(!(s).empty()){(s).pop();}
#define ff                               first
#define ss                               second
#define si(x)				 scanf("%d",&(x))
#define sl(x)                            scanf("%lld",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i]<<" ";}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
void print(int xx)
{
	for(int i=0;i<xx;i++)
		printf("\t|");
	printf(" ");
}
string add(string s1,string s2)
{
	int c = 0;
	if(s1.length() < s2.length())
		swap(s1,s2);
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	for(int i=0;i<s1.length();i++)
	{
		if(i >= s2.length())
			s1[i] = s1[i] - '0' + c;
		else
			s1[i] = s1[i] - '0' + s2[i] - '0' + c;
		c = s1[i]/10;
		s1[i] = s1[i]%10 + '0';
	}
	if(c)
	{
		c = c + '0';
		s1.pb(c);
	}
	reverse(s1.begin(),s1.end());
	return s1;
}
string subtract(string s1,string s2)
{
	int c = 0;
	if(s1.length() < s2.length())
		swap(s1,s2);
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	for(int i=0;i<s1.length();i++)
	{
		if(i >= s2.length())
			s1[i] = (s1[i] - '0') - c;
		else
			s1[i] = (s1[i] - '0') - (s2[i] - '0') - c;
		s1[i] < 0 ? c = 1, s1[i] += 10 : c = 0;
		s1[i] = s1[i] + '0';
	}
	if(c)
		printf("ERR!\n");
	reverse(s1.begin(),s1.end());
	return s1;
}
string kasturba(string x,string y,int num)
{
	int m;
	string xh,xl,yh,yl,a,d,e;
	if(x.length() < 2 && y.length() < 2)
		return to_string(stol(x)*stol(y));
	
	if(x.length() < y.length())
	{
		reverse(x.begin(),x.end());
		while(x.length() < y.length())
			x.pb('0');
		reverse(x.begin(),x.end());
	}
	if(y.length() < x.length())
	{
		reverse(y.begin(),y.end());
		while(y.length() < x.length())
			y.pb('0');
		reverse(y.begin(),y.end());
	}
	
	m = floor(double(x.length())/2);
	xh = x.substr(0,m),yh = y.substr(0,m);
	xl = x.substr(m),yl = y.substr(m);
	m = ceil(double(x.length())/2);
	print(num); //debug
	printf("m = %d\n",m); //debug
	print(num); //debug
	printf("a = "); //debug
	cout<<"( "<<xh<<" x "<<yh<<" )"<<endl; //debug

	a = kasturba(xh,yh,num+1);

	print(num); //debug
	cout<<"a = "<<a<<endl; //debug
	print(num); //debug
	printf("d = "); //debug
	cout<<"( "<<xl<<" x "<<yl<<" )"<<endl; //debug

	d = kasturba(xl,yl,num+1);

	print(num); //debug
	cout<<"d = "<<d<<endl; //debug
	print(num); //debug
	printf("e = "); //debug
	cout<<"( "<<add(xh,xl)<<" x "<<add(yh,yl)<<" ) - "<<add(a,d)<<endl; //debug

	e = subtract(kasturba(add(xh,xl),add(yh,yl),num+1),add(a,d));

	print(num); //debug
	cout<<"e = "<<e<<endl; //debug
	
	for(int i=0;i<2*m;i++)
		a.pb('0');
	for(int i=0;i<m;i++)
		e.pb('0');

	print(num); //debug
	cout<<"fin = "<<a<<" + "<<e<<" + "<<d<<endl; //debug
	
	string xx = add(add(a,e),d);
	reverse(xx.begin(),xx.end());
	while(xx.back() == '0' && xx.length() > 1)
		xx.pop_back();
	reverse(xx.begin(),xx.end());
	
	print(num); //debug
	cout<<"ret : "<<xx<<endl; //debug

	return xx;
}
int main()
{
	int t;
	string s1,s2;
	si(t);
	while(t--)
	{
		cin>>s1>>s2;
		cout<<"( "<<s1<<" x "<<s2<<" )"<<endl; //debug
		cout<<kasturba(s1,s2,1)<<endl;
	}
	return 0;
}
