#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int flag=0;
int find(char substr[1000], char str[1000])
{
	int q=0,p, len = strlen(substr);
	for(p=0;p<strlen(str);)
	{
		if(q==len)
			return 1;
		if(str[p] == substr[q])
		{
			q++;
			p++;
		}
		else
		{
			p=p-q+1;
			q=0;
		}
	}
	if(q==len+1)
		return 1;
	return 0;
}
void permute(char substr[1000],int l,int r, char str[1000])
{
	if(l==r)
	{
		int l1 = find(substr, str);
		if(l1==1)
		{
			flag=1;
			return;
		}
	}
	else
	{
		int i;
		for(i=l;i<=r;i++)
		{
			char ch=substr[i];
			substr[i]=substr[l];
			substr[l]=ch;
			permute(substr,l+1,r,str);
			ch=substr[i];
			substr[i]=substr[l];
			substr[l]=ch;
		}
	}
}
int main()
{
	char substr[1000], str[1000];
	printf("Enter string:");
	scanf("%s",str);
	printf("Enter substring to search:");
	scanf("%s", substr);
	int l=strlen(substr);
	permute(substr,0,l-1,str);
	if(flag==1)
	printf("Answer: True");
	else
	printf("Answer: False");
	return 0;
}
