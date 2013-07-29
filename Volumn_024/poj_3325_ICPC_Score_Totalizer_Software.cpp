//Sun 31 Jan 2010 02:27:56 PM CST 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	while((cin >> N) && (N != 0))
	{
		int mmax = 0;
		int mmin = 1000;
		int sum = 0;
		vector<int> v(N, 0);
		for(int i=0; i<N; i++)
		{
			cin >> v[i];
			sum += v[i];
			mmax = max(mmax, v[i]);
			mmin = min(mmin, v[i]);
		}
		int ret = (sum - mmax - mmin) / (N - 2);
		cout << ret << endl;
	}
	return 0;
}
