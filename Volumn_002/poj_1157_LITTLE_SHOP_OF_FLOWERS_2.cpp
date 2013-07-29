//Thu 04 Feb 2010 01:47:19 AM CST 
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int dp[110][110];
int A[110][110];
int main(int argc, char* argv[])
{
	int F, V;
	cin >> F >> V;
	memset(dp, -50001, sizeof(dp));
	for(int i=0; i<F; i++)
	{
		for(int j=0; j<V; j++)
		{
			cin >> A[i][j];
		}
	}
	dp[0][0] = A[0][0];
	for(int j=1; j<V; j++)
		dp[0][j] = max(dp[0][j-1], A[0][j]);
	for(int i=1; i<F; i++)
	{
		dp[i][i] = dp[i-1][i-1] + A[i][i];
		for(int j=i+1; j<V; j++)
		{
			dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+A[i][j]);
		}
	}	
	cout << dp[F-1][V-1] << endl;
	return 0;
}
