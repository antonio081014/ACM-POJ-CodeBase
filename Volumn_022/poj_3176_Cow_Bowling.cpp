//Sat 30 Jan 2010 09:57:32 PM CST 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int> > v;
	for(int i=0; i<N; i++)
	{
		vector<int> temp (i+1);
		for(int j=0; j<=i; j++)
		{
			cin >> temp[j];
		}
		v.push_back(temp);
	}
	for(int i=1; i<N; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(j==0) v[i][j] += v[i-1][j];
			else if(j==i) v[i][j] += v[i-1][j-1];
			else v[i][j] += max(v[i-1][j-1], v[i-1][j]);
		}
	}
	int mmax = 0;
	for(int i=0; i<N; i++)
		mmax = max(mmax, v[N-1][i]);
	cout << mmax << endl;
	return 0;
}
