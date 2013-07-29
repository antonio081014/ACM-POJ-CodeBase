#include<stdio.h>
int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int n,h,t[26],f[26],d[26],u[26][26];
	while(scanf("%d",&n)==1&&n!=0)
	{
		scanf("%d",&h);
		h*=12;
		int i,j;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=n;j++)
				u[i][j]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&d[i]);
		}
		t[0]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d",&t[i]);
		}
		int T=0;
		for(i=1;i<=n;i++)
		{
			T+=t[i-1];
			int s=h-T;
			if(s<=0) break;
			while(s>0)
			{
				int max=0,pos;
				for(j=1;j<=i;j++)
				{
					int m=f[j]-d[j]*u[i][j];
					if(m<0) continue;
					if(max<m)
					{
						max=m;
						pos=j;
					}
				}
				if(max==0) 
				{
					u[i][1]+=s;
					break;
				}
				u[i][pos]++;
				u[i][0]+=max;
				s--;
			}
		}
		int max=u[1][0],pos=1;
		for(i=2;i<=n;i++)
		{
			if(max<u[i][0]) 
			{
				max=u[i][0];
				pos=i;
			}
			else if(max==u[i][0])
			{
				if(u[pos][1]<u[i][1])
					pos=i;
			}
		}
		for(i=1;i<n;i++)
		{
			printf("%d, ",u[pos][i]*5);
		}
		printf("%d\n",u[pos][n]*5);
		printf("Number of fish expected: %d\n\n",u[pos][0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

