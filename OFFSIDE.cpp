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
#define si(x)				 scanf("%d",&(x))
#define display(v)          for(int i=0;i<(v).size();i++){cout<<v[i];}cout<<endl
#define pb          			 push_back
#define abs(x)                           ((x)<0 ? -(x) : (x))
#define INF                              INT32_MAX
#define fill(a,b)                        memset((a),(b),sizeof(a))
int main()
{
	int a,d,att[11],def[11];
	si(a),si(d);
	while((a | d) != 0)
	{
		for(int i=0;i<a;i++)
			si(att[i]);
		for(int i=0;i<d;i++)
			si(def[i]);
		sort(att,att+a),sort(def,def+d);
		if(att[0] >= def[1])
			printf("N\n");
		else
			printf("Y\n");
		si(a),si(d);
	}
	return 0;
}
