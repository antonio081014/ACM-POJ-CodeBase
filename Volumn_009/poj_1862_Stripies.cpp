#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int xx[100],n;
	while(scanf("%d",&n)==1)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&xx[i]);
		}
		sort(xx,xx+n);
		double sum=(double)xx[n-1];
		for(i=n-2;i>=0;i--)
			sum=2*sqrt(sum*xx[i]);
		printf("%.3lf\n",sum);
	}
	return 0;
}
//sort,from the greatest to the smallest, 两两相加！