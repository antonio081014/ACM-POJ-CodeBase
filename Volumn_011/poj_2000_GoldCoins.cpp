#include <stdio.h>
int fun(int x)
{
    int n;
    for(n=1;;n++)
    if(2*x<=(n*(n+1)))
    {
        int r;
        n--;
        r=n*(n+1)*(2*n+1)/6+(x-n*(n+1)/2)*(n+1); //¹«Ê½!!
        return r;
    }
}
int main()
{
  int n,res;
  while(scanf("%d",&n)==1&&n)
  {
    res=fun(n);
    printf("%d %d\n",n,res);        
  }    
}