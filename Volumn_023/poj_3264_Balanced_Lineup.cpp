//Sun 31 Jan 2010 02:44:40 PM CST 
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

//int main()
//{
//	int N, Q;
//	cin >> N >> Q;
//	vector<int> v(N, 0);
//	for(int i=0; i<N; i++)
//		cin >> v[i];
//	for(int i=0; i<Q; i++)
//	{
//		int A, B;
//		cin >> A >> B;
//		int mmax = v[A-1];
//		int mmin = v[A-1];
//		for(int i=A-1; i<B; i++)
//		{
//			mmax = max(mmax, v[i]);
//			mmin = min(mmin, v[i]);
//		}
//		cout << mmax - mmin << endl;
//	}
//	return 0;
//}
//Sparse Table (ST) algorithm
//http://www.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor#Introduction
int mmax[50001][16];
int mmin[50001][16];

int main()
{
	int N, Q;
	cin >> N >> Q;
	vector<int> v(N, 0);
	for(int i=0; i<N; i++)
		cin >> v[i];
	//Initialize the table.
	for(int i=0; i<N; i++)
	{
		mmin[i][0] = v[i];
		mmax[i][0] = v[i];
	}
	//build the table.O(NlogN);
	for(int j=1; 1<<j<=N; j++)
	{
		for(int i=0; i+(1<<j)-1<N; i++)
		{
			if(mmin[i][j-1] < mmin[i+(1<<(j-1))][j-1])
				mmin[i][j] = mmin[i][j-1];
			else
				mmin[i][j] = mmin[i+(1<<(j-1))][j-1];
			if(mmax[i][j-1] > mmax[i+(1<<(j-1))][j-1])
				mmax[i][j] = mmax[i][j-1];
			else 
				mmax[i][j] = mmax[i+(1<<(j-1))][j-1];
		}
	}
	for(int k=0; k<Q; k++)
	{
		int A, B;
		cin >> A >> B;
		A--; B--;
		int sz = int (log(1.0*B - 1.0*A + 1.0) / log(2.0));
		int ma = mmax[A][sz];
		int mi = mmin[A][sz];
		A += (1<<sz);
//		cout << ma << ", " << mi << endl;
//		for(int i=A+(1<<sz); i<=B; i++)
//		{
//			ma = max(ma, v[i]);
//			mi = min(mi, v[i]);
////			cout << "v[i]:" << v[i] << endl;
//		}
//Even this will cost tons of time.
//So the following log(N) will save a lot.
//I also changed the indices to the value. Probably this will be more effecient.
		while(A < B)
		{
			sz = (int) (log(1.0*B - 1.0*A + 1.0) / log(2.0));
			ma = max(ma, mmax[A][sz]);
			mi = min(mi, mmin[A][sz]);
			A += (1<<sz);
		}
		ma = max(ma, v[B]);
		mi = min(mi, v[B]);
//		cout << ma << ", " << mi << endl;
		cout << ma - mi << endl;
	}
	return 0;
}
