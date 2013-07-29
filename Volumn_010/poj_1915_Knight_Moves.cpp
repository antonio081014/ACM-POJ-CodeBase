//Fri Apr  8 18:53:31 CDT 2011
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Square {
public:
	int x;
	int y;
	int cost;
	bool visited;
};

int xx[] = { -2, +2, -1, +1, +1, -1, +2, -2 };
int yy[] = { -1, +1, -2, +2, -2, +2, -1, +1 };
int dir[8][2] = { { -1, -2 }, { 1, -2 }, { -2, -1 }, { 2, -1 }, { -2, 1 }, { 2,
		1 }, { -1, 2 }, { 1, 2 } };

Square chess[300][300];
queue<Square> q;

void init(int N) {
	while (q.empty() == false)
		q.pop();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			chess[i][j].x = i;
			chess[i][j].y = j;
			chess[i][j].cost = 0;
			chess[i][j].visited = false;
		}
	}
	//	for (int i = 0; i < 8; i++)
	//		for (int j = 0; j < 8; j++)
	//			cout << "Chess at " << chess[i][j].x << chess[i][j].y << ": "
	//					<< chess[i][j].cost << ", visited: "
	//					<< (chess[i][j].visited == true ? 1 : 0) << endl;
}

bool checkBound(int x, int y, int N) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	return false;
}

int bfs(int a, int b, int c, int d, int N) {
	int x = a;
	int y = b;
	q.push(chess[x][y]);
	while (q.empty() == false) {
		Square tmp = q.front();
		q.pop();
		x = tmp.x;
		y = tmp.y;
		if (x == c && y == d)
			return chess[x][y].cost;
		if (chess[x][y].visited == false) {
			chess[x][y].visited = true;
			for (int i = 0; i < 8; i++) {
				int x1 = x + dir[i][0];
				int y1 = y + dir[i][1];
				if (checkBound(x1, y1, N)) {
					chess[x1][y1].cost = 1 + chess[x][y].cost;
					q.push(chess[x1][y1]);
				}
			}
		}
	}
	return 0;
}

int main(int argc, const char* argv[]) {
	//freopen("input.in", "r", stdin);
	int T;
	scanf("%d", &T);
	int a, b;
	int c, d;
	int N;
	while (T--) {
		scanf("%d%d%d%d%d", &N, &a, &b, &c, &d);
		//cin >> N;
		//cin >> a >> b;
		//cin >> c >> d;
		init(N);
		printf("%d\n", bfs(a, b, c, d, N));
	}
	//fclose(stdin);
	return 0;
}

