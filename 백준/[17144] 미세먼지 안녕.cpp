#include<iostream>
#include<climits>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>

using namespace std;

int R, C, T;
int MAP[100][100];
int ay[2];

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

bool isRange(int y, int x) { return (y >= 0 && y < R) && (x >= 0 && x < C); }

void init() {
}

void input() {

	cin >> R >> C >> T;

	int n = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == -1) {
				ay[n] = i;
				n++;
			}
		}
	}
}

void print() {
	cout << "=====================" << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void diffuse() {
	queue<pair<int, pair<int, int>>> q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] > 0) {
				q.push(make_pair(MAP[i][j], make_pair(i, j)));
				MAP[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int num = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		int count = 0;
		for (int i = 0; i < 4; i++) {
			int dy = y + dir[i][0];
			int dx = x + dir[i][1];

			if (!isRange(dy, dx) || MAP[dy][dx] == -1) continue;

			count++;
			MAP[dy][dx] += num / 5;
		}
		MAP[y][x] += num - (num / 5 * count);
	}
}

void doAir() {
	for (int i = ay[0]-2; i >= 0; i--) {
		MAP[i + 1][0] = MAP[i][0];
	}
	for (int i = 1; i < C; i++) {
		MAP[0][i-1] = MAP[0][i];
	}
	for (int i = 0; i <= ay[0]; i++) {
		MAP[i - 1][C - 1] = MAP[i][C - 1];
	}
	for (int i = C-2; i > 0; i--) {
		MAP[ay[0]][i + 1] = MAP[ay[0]][i];
	}
	MAP[ay[0]][1] = 0;


	for (int i = ay[1]+2; i < R; i++) {
		MAP[i - 1][0] = MAP[i][0];
	}
	for (int i = 1; i < C; i++) {
		MAP[R - 1][i - 1] = MAP[R-1][i];
	}
	for (int i = R - 2; i >= ay[1]; i--) {
		MAP[i + 1][C - 1] = MAP[i][C - 1];
	}
	for (int i = C - 2; i > 0; i--) {
		MAP[ay[1]][i + 1] = MAP[ay[1]][i];
	}
	MAP[ay[1]][1] = 0;
}

int countDust() {
	int count = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] > 0) count += MAP[i][j];
		}
	}

	return count;
}

int solution() {
	int result = 0;

	for (int i = 0; i < T; i++) {
		diffuse();
		doAir();
	}

	result = countDust();

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
	cout << solution() << endl;
	//}

	return 0;
}
