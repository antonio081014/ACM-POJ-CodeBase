/*#include<stdio.h>
 int MaxSum(int n,int a[])
 {
 int max1=a[0],max2=a[1];
 int sum=0,i;
 for(i=0;i<n;i++)
 {
 if(sum>0) sum+=a[i];
 else sum=a[i];
 if(sum>max1) max1=sum;
 }
 int flag=0;sum=0;
 for(i=1;i<n;i++)
 {
 if(sum>0) sum+=a[i];
 else sum=a[i];
 if(sum==max1&&flag==0) {flag=1;continue;}
 else if(sum==max1) {max2=sum;continue;}
 if(sum>max2) max2=sum;
 }
 return (max1+max2);
 }
 int main()
 {
 int t;
 scanf("%d",&t);
 while(t--)
 {
 int n,i;
 int a[50000]={0};
 scanf("%d",&n);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 if(n==2)
 {
 printf("%d\n",a[0]+a[1]);
 continue;
 }
 else if(n==1)
 {
 printf("%d\n",a[0]);
 continue;
 }
 int max=MaxSum(n,a);
 printf("%d\n",max);
 }
 return 0;
 }*/
#include <stdio.h>
int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t, n, i, max, sum;
	int a[50000], b[50000], c[50000];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		max = 0;
		sum = 0;
		if (n == 1)
		{
			scanf("%d", &a[0]);
			printf("%d\n", a[0]);
			continue;
		}
		if (n == 2)
		{
			scanf("%d", &a[0]);
			scanf("%d", &a[1]);
			printf("%d\n", a[0] + a[1]);
			continue;
		}
		//b[i] is the max sum from 0 to i.
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			if (sum < 0)
				sum = 0;
			else if (sum > max)
				max = sum;
			b[i] = max;
		}
		//c[i] is the max sum from i to the end.
		max = 0;
		sum = 0;
		for (i = n - 1; i >= 0; i--)
		{
			sum += a[i];
			if (sum < 0)
				sum = 0;
			else if (sum > max)
				max = sum;
			c[i] = max;
		}
		max = 0;
		for (i = 0; i < n - 1; i++)
			if (b[i] + c[i + 1] > max)
				max = b[i] + c[i + 1];
		printf("%d\n", max);
	}

	return (0);
}
