#include<iostream>
#include<climits>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>

using namespace std;

int N,M;
int MAP[15][15];
vector<pair<int, int>> v;
int result = 0;

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

bool isRange(int y, int x) {
	return (y >= 0 && y < N) && (x >= 0 && x < M);
}

void init() {

}

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}
}

int moveVirus() {
	int count = 0;
	int t_MAP[15][15] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			t_MAP[i][j] = MAP[i][j];
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
	}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = y + dir[i][0];
			int tx = x + dir[i][1];

			if (!isRange(ty, tx) || t_MAP[ty][tx] != 0) continue;

			t_MAP[ty][tx] = 2;
			q.push(make_pair(ty,tx));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (t_MAP[i][j] == 0) count++;
		}
	}

	/*if(count < result)
		return count;*/

	//cout << "===========================" << endl;
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << t_MAP[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	return count;
}

void dfs(int y, int x, int count) {
	if (count == 3) {
		/*cout << "===========================" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << MAP[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		int temp = moveVirus();
		if (result < temp) {
			result = temp;
		}
		return;
	}

	for (int i = y; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (y == i && j < x) continue;
			if (MAP[i][j] != 0) continue;

			MAP[i][j] = 1;
			dfs(i, j, count + 1);
			MAP[i][j] = 0;
		}
	}
}

int solution() {

	dfs(0, 0, 0);

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
