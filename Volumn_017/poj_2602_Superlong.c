#include<stdio.h>
int sum[1000000];
int main()
{
    int n;
        scanf("%d",&n);
	        int i;
		    int aa,bb;
			for(i=0;i<n;i++)
			{
			    scanf("%d%d",&aa,&bb);
			    sum[i] = aa + bb;
			}
			int flag=0;
			for(i=n-1;i>=0;i--)
			{
				sum[i] += flag;
				if(sum[i] > 9) flag = 1;
				else flag = 0 ;
				sum[i]%=10;
			}
			for(i=0;i<n;i++)
			{
			    printf("%d",sum[i]);
			}
			printf("\n");
		return 0;
}

