//Wed 03 Feb 2010 08:10:01 PM CST 
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
	memset(dp, -5001, sizeof(dp));
	for(int i=1; i<=F; i++)
	{
		for(int j=1; j<=V; j++)
		{
			cin >> A[i][j];
		}
	}
	
	//Initialize: no flowers in each number of vases.
	for(int i=0; i<=V; i++)
		dp[0][i] = 0;
	for(int i=1; i<=F; i++)
	{
		dp[i][i] = dp[i-1][i-1] + A[i][i]; //This one made the greatest change.
		for(int j=i+1; j<=V; j++)
		{
			dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+A[i][j]);
//			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+A[i][j]);
		}
	}
	cout << dp[F][V] << endl;
	return 0;
}
