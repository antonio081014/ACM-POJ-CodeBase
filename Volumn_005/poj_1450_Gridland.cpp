#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	int ncase=1;
	while(ncase<=t)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		int a=m*n;
		printf("Scenario #%d:\n",ncase);
		if(a%2==0)
			printf("%d.00\n\n",a);
		else
			printf("%d.41\n\n",a);
		ncase++;
	}
	return 0;
}