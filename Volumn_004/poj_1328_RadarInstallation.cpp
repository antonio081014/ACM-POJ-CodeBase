#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int ncase=0;
struct mm
{
	double x1;
}cx[1001];
bool cmp(const mm &p,const mm &q)
{
	if(p.x1<q.x1)
		return true;
	return false;
}
int main()
{
	int n,d;
	while(scanf("%d%d",&n,&d)==2&&(n+d!=0))
	{
		ncase++;
		int a,b,flag=0;
		int i,j;
		int count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(d*d-b*b<0) 
				flag=1;
			cx[i].x1=a*1.0+sqrt((d*d-b*b)*1.0);
		}
		if(d<=0) goto l;
		sort(cx,cx+n,cmp);
		i=0;//贪心部分代码；
		while(i<n)
		{
			count++;
			for(j=i+1;j<n;j++)
			{
				if(cx[j].x1<=cx[i].x1+d*2)
					continue;	
				//i=j+1;
			    break;
			}
			i=j;
		}
		if(flag) count=0;
l:		if(count==0) 
			printf("Case %d: -1\n",ncase);
		else 
			printf("Case %d: %d\n",ncase,count);
	}
	return 0;
}
//贪心；可能是排序部分有问题；