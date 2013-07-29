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
/*  ���ⱨ�棡��

���ȶ����X(xm) = {x1,x2,x3,...xm};Y(yn) = {y1,y2,y3,...yn};������������Ŀ��

Ҫ��õ����ֵ������M{...}����Ӧ�����ֵ��f(m,n);
****************************************************
��xm != yn��ʱ��
****************************************************
������˼��һЩ����:
1.
�������M{...}һ����
....xm
...._
�������²����Ű�,�ͳ���ΪP(xm,_);
����
...._
....yn
�������²����Ű�,�ͳ���ΪP(_,yn);
����
....xm
....yn
�������²����Ű�,�ͳ���ΪP(xm,yn);
�����е�һ��.��Ϊxm,yn�ֱ���X,Y���������Ԫ�أ���������е���������������Ҳ��

Ȼ������"��_"Ԫ��.

2.
������ֵf(m,n)����P(xm,_)��������ʽ��,��ô���ǿ��Կ������ʱ���yn�����Ǵ�

ʡ�Ժ������Ҳ����˵�Ǵ�ʡ�Ժ���������������X(xm-1) = {x1,x2,x3,...xm-1};Y

(yn) = {y1,y2,y3,...yn}��һ�ְ�����ĿҪ�������,�������ǳ����������ϵ�������

�õ���ֵ��w(m-1,n),ͬʱ����t(xm,_)��"xm��_"���Ӧ��ֵ.��ô����f(m,n) = w(m-

1,n)+t(xm,_)��������֤��w(m-1,n)��X(xm-1),Y(yn)�������е����ֵ:f(m-1,n).
�����������һ��w'(m-1,n) > w(m-1,n)��ôw'(m-1,n)+t(xm,_) > w(m-1,n)+t(xm,_) 

= f(m,n).Ҳ����˵����һ����f(m,n)�����ֵ,ì��.
����w(m-1,n)�����ֵf(m-1,n)

3.
ͬ������֤��������ֵf(m,n)����P(_,yn)��������ʽ��,��ôǰ��ʡ�Ժ����õ���ֵ

w(m,n-1)Ҳ��Ȼ�����ֵf(m,n-1)

4.
������ֵ����P(xm,yn)��β��,��ô����֪��ǰ��ʡ�Ժ����õ���ֵw(m-1,n-1)Ҳ��Ȼ

�����ֵf(m-1,n-1).

�����漸�����ۿ�����,���ǾͿ���֪����xm != ynʱ
f(m,n)һ����
f(m-1,n)+t(xm,_)
f(m,n-1)+t(xm,_)
f(m-1,n-1)+t(xm,yn)
�е�����һ��.

****************************************************************************
��xm == yn ʱ��
****************************************************************************
���ʱ��ܼ򵥣��϶���
f(m,n) = f(m-1,n-1) + t(xm,yn);

�ۺ��������еĶ���,���Ǿ������Ϊ��̬�滮�ṩ�ӽṹ�Ĺ���(����˵�ǲ�������

��??),ʣ�¾���LCS�ı�д������.

����,�е�Ҫ����һ��,���ǳ�ʼ��ʱ��,����f(m,0)����f(0,n)���ǲ��Ǻܼ򵥵��ó�0

��,����������һ�����ǿռ�
����������f(m,0) = f(m-1,0)+t(m,_)     f(0,n) = f(0,n-1)+ t(_,n)
ֻ��f(0,0) = 0.���������������ǿռ���.
С�ܾ�������WA��.-_-|||

��Ц��...
*/