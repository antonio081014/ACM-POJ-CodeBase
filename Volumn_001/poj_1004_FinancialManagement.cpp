#include<stdio.h>
int main()
{
	double sum=0.0;
	double m;
	int count=1,t=12;
	while(t--)
	{
		scanf("%lf",&m);
		sum+=m;
	}
	printf("$%.2lf\n",sum/12);
	return 0;
}