#include<iostream>
#include<climits>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>

using namespace std;

int N, M;

int MAP[1000][1000] = { 0, };
bool visit[1000][1000] = { 0, };

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int result = 0;

bool isRange(int y, int x) { return (y >= 0 && y < N) && (x >= 0 && x < M); }

void init() {

}

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}

void checkBlock(int y, int x, int length, int cost) {
	if (length >= 4) {
		if (cost > result) {
			result = cost;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ty = y + dir[i][0];
		int tx = x + dir[i][1];

		if (!isRange(ty, tx) || visit[ty][tx])continue;

		visit[ty][tx] = true;
		checkBlock(ty, tx, length + 1, cost + MAP[ty][tx]);
		visit[ty][tx] = false;
	}
}

int checkShape1(int y, int x) {
	if (!isRange(y, x - 1) || !isRange(y, x + 1) || !isRange(y + 1, x))return 0;
	return MAP[y][x] + MAP[y][x - 1] + MAP[y][x + 1] + MAP[y + 1][x];
}

int checkShape2(int y, int x) {
	if (!isRange(y - 1, x) || !isRange(y + 1, x) || !isRange(y, x + 1))return 0;
	return MAP[y][x] + MAP[y - 1][x] + MAP[y + 1][x] + MAP[y][x + 1];
}

int checkShape3(int y, int x) {
	if (!isRange(y, x - 1) || !isRange(y, x + 1) || !isRange(y - 1, x))return 0;
	return MAP[y][x] + MAP[y][x - 1] + MAP[y][x + 1] + MAP[y - 1][x];
}

int checkShape4(int y, int x) {
	if (!isRange(y - 1, x) || !isRange(y + 1, x) || !isRange(y, x - 1))return 0;
	return MAP[y][x] + MAP[y - 1][x] + MAP[y + 1][x] + MAP[y][x - 1];
}

int solution() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			checkBlock(i, j, 1, MAP[i][j]);
			visit[i][j] = false;

			int temp = checkShape1(i, j);
			if (temp > result) {
				result = temp;
			}

			temp = checkShape2(i, j);
			if (temp > result) {
				result = temp;
			}

			temp = checkShape3(i, j);
			if (temp > result) {
				result = temp;
			}

			temp = checkShape4(i, j);
			if (temp > result) {
				result = temp;
			}
		}
	}

	return result;
}

int main(int argc, char** argv)
{
	/*int T;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{*/
	init();
	input();
	cout << /*"#" << i << " " <<*/ solution() << endl;
	//}

	return 0;
}
