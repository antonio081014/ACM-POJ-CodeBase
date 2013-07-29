//Sun 31 Jan 2010 04:43:48 PM CST 
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int B, N;
	cin >> B >> N;
	while(B + N != 0)
	{
		int ret = (int) pow(B, 1.0/N);
		int res1 = (int) pow(ret, 1.0*N);
		int res2 = (int) pow(ret+1, 1.0*N);
		if(res1+res2 > 2*B) cout << ret << endl;
		else cout << ret+1 << endl;
		cin >> B >> N;
	}
	return 0;
}
