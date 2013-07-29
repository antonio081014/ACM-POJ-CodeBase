//Sun 31 Jan 2010 02:49:40 AM CST 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int xx[] = {1, 0, -1, 0};
int yy[] = {0, 1, 0, -1};
/*
bool inbound(vector<vector<int> > map, int x, int y)
{
	if(x>=0 && x<map.size() && y>=0 && y<map[0].size()) return true;
	return false;
}

int dfs(vector<vector<int> > map, int x, int y)
{
	int score = 1;
	for(int i=0; i<4; i++)
	{
		int x1 = x+xx[i];
		int y1 = y+yy[i];
		if(inbound(map, x1, y1) && map[x1][y1] < map[x][y])
			score = max(score, 1+dfs(map, x1, y1));
	}
	return score;
}

int main()
{
	int M, N;
	cin >> M >> N;
	vector<vector<int> > v(M, vector<int>(N, 0));
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> v[i][j];
		}
	}
	int mmax = 0;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			mmax = max(mmax, dfs(v, i, j));
		}
	}
	cout << mmax << endl;
	return 0;
}
*/
int x_len,y_len;
int num[100][100];
int flag[100][100];

int access(int x,int y)
{
    int k,temp;
    int mmax=0;
    if(flag[x][y]!=-1) return flag[x][y]; //防止重复 
    for(k=0;k<4;k++)
    {
    	//边界限制 
        if(x+xx[k]>=x_len||x+xx[k]<0) continue;
        if(y+yy[k]>=y_len||y+yy[k]<0) continue;
        if(num[x+xx[k]][y+yy[k]]>=num[x][y]) continue;
        mmax = max(mmax, access(x+xx[k],y+yy[k]));
    }
    flag[x][y]=mmax+1;
    return flag[x][y];
}

int main()
{
    int i,j;
    int mmax=0,t;
    cin>>x_len>>y_len;
    for(i=0;i<x_len;i++)
    {
    	for(j=0;j<y_len;j++)
        {
       		cin >> num[i][j];
            flag[i][j] = -1;
        }
    }
    for(i=0;i<x_len;i++)
    {
    	for(j=0;j<y_len;j++)
        {
             mmax = max(mmax, access(i,j));
        }
    }
    cout<< mmax << endl;
    return 0;
}
