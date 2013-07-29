#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i,j,k;
		int max=0,corridor[201]={0};
		int p,q;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p,&q);
			p=(p+1)/2;
			q=(q+1)/2;
			if(p>=q)
			{
				for(j=q;j<=p;j++)
				{
					corridor[j]++;
					if(max<corridor[j]) 
						max=corridor[j];
				}
			}
			else
			{
				for(j=p;j<=q;j++)
				{
					corridor[j]++;
					if(max<corridor[j]) 
						max=corridor[j];
				}
			}
		}
		printf("%d\n",max*10);
	}
	return 0;
}