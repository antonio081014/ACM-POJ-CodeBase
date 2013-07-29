#include<stdio.h>
#include<algorithm>
using namespace std;

struct tt 
{
	int left,right;
	bool valid;		//Need to be satisfied or not;
}inter[10001];
bool cmp(tt p,tt q)
{
	if(p.left<q.left||(p.left==q.left&&p.right>q.right))
		return true;
	return false;
}

void init(int n)
{
	int i;
	int a,b;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		inter[i].valid=true;
		inter[i].left=a;
		inter[i].right=b;
	}
}

void Cal(int n)
{
	int count=2;
	int i,j;
	sort(inter,inter+n,cmp);
	//try to reduce the one that has larger extension,leave the small one be covered.
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(inter[j].left<=inter[i].left&&inter[j].right>=inter[i].right)
				inter[j].valid=false;
		}
	}
	//*********************************************************
	//for(i=0;i<n;i++)
	//	printf("%d %d %d\n",inter[i].left,inter[i].right,inter[i].valid);
	//*********************************************************
	int p,q;
	//Greedy part;
	//Find the first value of p and q which is valid;
	for(i=0;i<n;i++)
	{
		if(inter[i].valid==false)
			continue;
		p=inter[i].right;
		q=inter[i].right-1;
		break;
	}
	for(;i<n;i++)
	{
		//printf("%d %d\n",q,p);
		//p,q is the share part of the coheresive sets;
		if(q>=inter[i].left||inter[i].valid==false)   
			continue;
		//p is ,but q is not;
		else if(p>=inter[i].left)
		{
			count++;
			q=p;
			p=inter[i].right;
			continue;
		}
		//Neither of p and q is the share part of two sets;
		else
		{
			count+=2;
			p=inter[i].right;
			q=inter[i].right-1;
		}
	}
	printf("%d\n",count);
}

int main()
{
	int n;
	scanf("%d",&n);
	init(n);
	Cal(n);
	return 0;
}
