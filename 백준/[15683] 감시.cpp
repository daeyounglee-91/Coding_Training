#include<iostream>
#include<climits>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>

using namespace std;

int N, M;
vector<pair<int, int>> cam;
int MAP[20][20];
int selectd[10];

int result = INT_MAX;

int dir[4][2] = { {-1,0},  {0,-1},{1,0}, {0,1} };

bool isRange(int y, int x) { return (y >= 0 && y < N)&& (x >= 0 && x < M); }

void init() {
}

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] > 0 && MAP[i][j] < 6) {
				cam.push_back(make_pair(i, j));
			}
		}
	}
}

int count() {
	bool visit[20][20] = { 0, };
	int temp = 0;

	for (int i = 0; i < cam.size(); i++) {
		int y = cam[i].first;
		int x = cam[i].second;

		int dy = y;
		int dx = x;
		if (MAP[y][x] == 1) {
			
			while (true)
			{
				dy = dy + dir[selectd[i]][0];
				dx = dx + dir[selectd[i]][1];
				
				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}
		}
		else if (MAP[y][x] == 2) {

			while (true)
			{
				dy = dy + dir[selectd[i]][0];
				dx = dx + dir[selectd[i]][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}

			dy = y;
			dx = x;

			while (true)
			{
				dy = dy + dir[(selectd[i] + 2) % 4][0];
				dx = dx + dir[(selectd[i] + 2) % 4][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}
		}
		else if (MAP[y][x] == 3) {

			while (true)
			{
				dy = dy + dir[selectd[i]][0];
				dx = dx + dir[selectd[i]][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}

			dy = y;
			dx = x;

			while (true)
			{
				dy = dy + dir[(selectd[i] + 1) % 4][0];
				dx = dx + dir[(selectd[i] + 1) % 4][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}
		}
		else if (MAP[y][x] == 4) {

			while (true)
			{
				dy = dy + dir[selectd[i]][0];
				dx = dx + dir[selectd[i]][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}

			dy = y;
			dx = x;

			while (true)
			{
				dy = dy + dir[(selectd[i] + 1) % 4][0];
				dx = dx + dir[(selectd[i] + 1) % 4][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}

			dy = y;
			dx = x;

			while (true)
			{
				dy = dy + dir[(selectd[i] + 2) % 4][0];
				dx = dx + dir[(selectd[i] + 2) % 4][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}
		}
		else if (MAP[y][x] == 5) {

			while (true)
			{
				dy = dy + dir[selectd[i]][0];
				dx = dx + dir[selectd[i]][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}

			dy = y;
			dx = x;

			while (true)
			{
				dy = dy + dir[(selectd[i] + 1) % 4][0];
				dx = dx + dir[(selectd[i] + 1) % 4][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}

			dy = y;
			dx = x;

			while (true)
			{
				dy = dy + dir[(selectd[i] + 2) % 4][0];
				dx = dx + dir[(selectd[i] + 2) % 4][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}

			dy = y;
			dx = x;

			while (true)
			{
				dy = dy + dir[(selectd[i] + 3) % 4][0];
				dx = dx + dir[(selectd[i] + 3) % 4][1];

				if (!isRange(dy, dx) || MAP[dy][dx] == 6) break;

				visit[dy][dx] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 0 && !visit[i][j]) {
				temp++;
			}
		}
	}


	return temp;
}

void toSelect(int length) {
	if (length >= cam.size()) {
		int temp = count();

		if (result > temp) {
			result = temp;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		selectd[length] = i;
		toSelect(length + 1);
	}
}

int solution() {

	toSelect(0);

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
