#include<stdio.h>
bool self[9994];
int main()
{
	int i,sum;
	for(i=1;i<9994;i++)
		self[i]=true;
	for(i=1;i<9994;i++)
	{
		if(i>=1000)
			sum=i+i%10+(i/10)%10+(i/100)%10+(i/1000)%10;
		else if(i>=100)
			sum=i+(i/100)%10+(i/10)%10+i%10;
		else if(i>=10)
			sum=i+(i/10)%10+i%10;
		else
			sum=i+i;                   
		self[sum]=false;
	}
    for(i=1;i<9994;i++)
	{
		if(self[i]==true)
			printf("%d\n",i);
    }
	return 0;
}
//ö��1λ����2λ����3λ����4Ϊ������������Ƽ�ö�١�