#include<stdio.h>
#include<stdlib.h>
char a[800];
int n=0,top=0;
void pop(void)
{
	printf("%c",a[top]);
	top--;
	n--;
}
void push(char t)
{
		a[n]=t;
		n++;
		top=n-1;
}
int icp(char x)
{
	if(x=='*'||x=='/')
		return 2;
	else if(x=='+'||x=='-')
		return 1;
	else if(x=='(')
		return 4;
	else if(x=='^')
		return 4;
	else if(x==')')
		return 0;
}
int isp(char x)
{
	if(x=='*'||x=='/')
		return 2;
	else if(x=='+'||x=='-')
		return 1;
	else if(x=='(')
		return 0;
	else if(x=='^')
		return 3;
}
void post(char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		if((str[i]>64 && str[i]<91) || (str[i]>96 && str[i]<123))
		{	printf("%c",str[i]);
			i++;
		}
		else
		{
			if(n==0)
			{
				push(str[i]);
				i++;
			}
			else
			{
				if(icp(str[i])>isp(a[top]) || str[i]==')')
				{
					push(str[i]);
					if(a[top]==')')
					{
						top--;
						n--;
						while(a[top]!='(')
						{
							pop();
						}
						top--;
						n--;
					}
					i++;
				}
				else
				{
					pop();
				}
			}
		}
	}
	while(top!=-1)
	{
		pop();
	}
	printf("\n");
}
int main()
{
	char *str;
	int t;
	str = malloc(400*sizeof(char));
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",str);
		post(str);
	}
	return 0;
}
