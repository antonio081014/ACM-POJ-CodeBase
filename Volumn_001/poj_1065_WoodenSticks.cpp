#include<stdio.h>
#include<algorithm>
using namespace std;
struct tt
{
	int l,w;
}cx[5001];
bool cmp1(tt p, tt q)   //升序排列
{
	if(p.l!=q.l)
	     return p.l<q.l;
	else
		return p.w<q.w;
}
int TempArray[5001];   //用于保存权重
/*********************************************
bool cmp2(tt p, tt q)
{
	return (p.w>q.w)||(p.w==q.w&&p.l>q.l);
}
*********************************************/
int GetTheMinTime(int n)
{
	int i,j;
	int logic;
	int MinT=0,index;
	for(i=1;i<=n;++i)
	{
		logic=-1;
		for(j=0;j<MinT;++j)
		{
			if(cx[i].w>=TempArray[j]&&logic<TempArray[j])
			{
				logic=TempArray[j];
				index=j;
			}
		}
		if(logic==-1)
			TempArray[MinT++]=cx[i].w;
		else
			TempArray[index]=cx[i].w;
	}
	return MinT;
}
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)	
		{
			scanf("%d %d",&cx[i].l,&cx[i].w);
		}
		sort(cx,cx+n+1,cmp1);
		printf("%d\n",GetTheMinTime(n));
	}	
	return 0;
}