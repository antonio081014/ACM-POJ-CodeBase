#include<stdio.h>
#include<algorithm>
using namespace std;

int ncase=1;

int main()
{
	int n;
	int height[51];
	while(scanf("%d",&n)==1&&n)
	{
		int i;
		int sum=0,
			 count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",height+i);
			sum+=height[i];
		}
		sort(height,height+n);
		i=0;
		sum/=n;
		while(height[i]<sum)
		{
			count+=sum-height[i];
			i++;
		}
		printf("Set #%d\n",ncase);
		printf("The minimum number of moves is %d.\n",count);
		ncase++;
		printf("\n");
	}
	return 0;
}
