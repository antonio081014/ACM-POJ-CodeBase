//DIM, 
//notice the part of sort :cmp!!
//and the iniatiation of flag!!
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int ncase=1;
struct mm
{
    double x1,x2;
}cx[1001];
bool cmp(mm p,mm q)
{
    return p.x2<q.x2;
}
int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d)==2&&(n+d!=0))
    {
        int a,b,flag=0;
        int i,j;
        int count=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            if(d*d-b*b<0) 
                flag=1;
            cx[i].x1=a*1.0-sqrt((d*d-b*b)*1.0);
            cx[i].x2=a*1.0+sqrt((d*d-b*b)*1.0);
        }
        if(d<=0||flag==1) goto l;
        sort(cx,cx+n,cmp);
        i=0;
        while(i<n)
        {
            count++;
            for(j=i+1;j<n;j++)
            {
                if(cx[j].x1<=cx[i].x2)
                    continue;    
                //i=j+1;
                else
                    break;
            }
            i=j;
        }
        if(flag==1) count=0;
l:        if(count==0) 
            printf("Case %d: -1\n",ncase);
        else 
            printf("Case %d: %d\n",ncase,count);
        ncase++;
    }
    return 0;
}