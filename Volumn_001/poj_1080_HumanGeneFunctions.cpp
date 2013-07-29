#include<stdio.h>
#include<memory.h>
int cost[120][120];
int ax[5][5];
int lena,lenb;
char a[120],b[120];
int max(int a,int b,int c)
{
	int max=a;
	if(b>max) max=b;
	if(c>max) max=c;
	return max;
}
int get(char c){
	if(c=='A')return 0;
	else if(c=='C')return 1;
	else if(c=='G')return 2;
	else if(c=='T')return 3;
	else return 4;
}
void init()
{
	int i;
	//The initiation of Matrix!
	ax[0][0]=5;ax[1][1]=5;ax[2][2]=5;ax[3][3]=5;
	ax[0][1]=ax[1][0]=-1;ax[0][2]=ax[2][0]=-2;ax[0][3]=ax[3][0]=-1;ax[0][4]=ax[4][0]=-3;
	ax[1][2]=ax[2][1]=-3;ax[1][3]=ax[3][1]=-2;ax[1][4]=ax[4][1]=-4;
	ax[2][3]=ax[3][2]=-2;ax[2][4]=ax[4][2]=-2;
	ax[3][4]=ax[4][3]=-1;
	ax[4][4]=0;
	memset(cost,0,sizeof(cost));
	//Only cost[0][0]=0;
	//others are not.
	for(i=1;i<=lenb;i++)
	{
		int sum=0;
		for(int j=0;j<i;j++)
			sum+=ax[4][get(b[j])];
		cost[0][i]=sum;
	}
	for(i=1;i<=lena;i++)
	{
		int sum=0;
		for(int j=0;j<i;j++)
			sum+=ax[get(a[j])][4];
		cost[i][0]=sum;
	}
}
int cal(int lena,int lenb) //LCS!!
{
	if(cost[lena][lenb]!=0)
		return cost[lena][lenb];
	if(lena==0||lenb==0)
		return cost[lena][lenb];
	else
	{
		int tmp1=ax[get(a[lena-1])][get(b[lenb-1])]+cal(lena-1,lenb-1);
		int tmp2=ax[4][get(b[lenb-1])]+cal(lena,lenb-1);
		int tmp3=ax[get(a[lena-1])][4]+cal(lena-1,lenb);
		int maxsum=max(tmp1,tmp2,tmp3);
		cost[lena][lenb]=maxsum;
		return maxsum;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&lena,a);
		scanf("%d%s",&lenb,b);
		init();
		printf("%d\n",cal(lena,lenb));
	}
	return 0;
}
/*  解题报告！！

首先定义对X(xm) = {x1,x2,x3,...xm};Y(yn) = {y1,y2,y3,...yn};这两个按照题目的

要求得到最大值的排列M{...}所对应的最大值是f(m,n);
****************************************************
当xm != yn的时候
****************************************************
现在来思考一些结论:
1.
最大排列M{...}一定是
....xm
...._
由于以下不好排版,就程它为P(xm,_);
或者
...._
....yn
由于以下不好排版,就程它为P(_,yn);
或者
....xm
....yn
由于以下不好排版,就程它为P(xm,yn);
这样中的一种.因为xm,yn分别是X,Y的最后两个元素，在最大排列的上下两行中它们也必

然是最后的"非_"元素.

2.
如果最大值f(m,n)是以P(xm,_)这样的形式的,那么我们可以看到这个时候的yn是在那串

省略号里面的也就是说那串省略号是这样两个集合X(xm-1) = {x1,x2,x3,...xm-1};Y

(yn) = {y1,y2,y3,...yn}的一种按照题目要求的排列,现在我们称这两个集合的排列所

得到的值是w(m-1,n),同时定义t(xm,_)是"xm与_"相对应的值.那么就有f(m,n) = w(m-

1,n)+t(xm,_)我们现在证明w(m-1,n)是X(xm-1),Y(yn)集合排列的最大值:f(m-1,n).
由于如果存在一个w'(m-1,n) > w(m-1,n)那么w'(m-1,n)+t(xm,_) > w(m-1,n)+t(xm,_) 

= f(m,n).也就是说存在一个比f(m,n)更大的值,矛盾.
所以w(m-1,n)是最大值f(m-1,n)

3.
同样可以证明如果最大值f(m,n)是以P(_,yn)这样的形式的,那么前面省略号所得到的值

w(m,n-1)也必然是最大值f(m,n-1)

4.
如果最大值是以P(xm,yn)结尾的,那么可以知道前面省略号所得到的值w(m-1,n-1)也必然

是最大值f(m-1,n-1).

从上面几个结论看过来,我们就可以知道当xm != yn时
f(m,n)一定是
f(m-1,n)+t(xm,_)
f(m,n-1)+t(xm,_)
f(m-1,n-1)+t(xm,yn)
中的最大的一个.

****************************************************************************
当xm == yn 时候
****************************************************************************
这个时候很简单，肯定是
f(m,n) = f(m-1,n-1) + t(xm,yn);

综合上面所有的东西,我们就完成了为动态规划提供子结构的过程(这样说是不是有语

病??),剩下就是LCS的编写工作了.

不过,有点要提醒一下,就是初始的时候,比如f(m,0)或者f(0,n)它们不是很简单的置成0

的,它们其中有一个不是空集
而是这样的f(m,0) = f(m-1,0)+t(m,_)     f(0,n) = f(0,n-1)+ t(_,n)
只有f(0,0) = 0.就是上下两个都是空集嘛.
小弟就是这里WA了.-_-|||

怡笑大方...
*/