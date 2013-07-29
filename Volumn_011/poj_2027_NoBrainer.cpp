#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		while(n--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(a>=b)
				printf("MMM BRAINS\n");
			else
				printf("NO BRAINS\n");
		}
	}
	return 0;
}