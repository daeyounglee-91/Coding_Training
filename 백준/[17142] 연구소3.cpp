#include<iostream>
#include<climits>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>

using namespace std;

int N, M;
int MAP[100][100];
vector<pair<int, int>> vir;
bool selectVir[20];
int result = INT_MAX;

int dir[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };

bool isRange(int y, int x) { return (y >= 0 && y < N) && (x >= 0 && x < N); }

void init() {
}

void input() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				vir.push_back(make_pair(i,j));
			}
		}
	}
}

int moveVir() {
	int visit[100][100] = { 0, };
	queue<pair<int, int>> q;

	for (int i = 0; i < vir.size(); i++) {
		if (selectVir[i]) {
			q.push(vir[i]);
			visit[vir[i].first][vir[i].second] = 1;
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[i][0];
			int dx = x + dir[i][1];

			if (!isRange(dy, dx) || visit[dy][dx] != 0 || MAP[dy][dx] == 1) continue;

			
			visit[dy][dx] = visit[y][x] + 1;
			q.push(make_pair(dy,dx));
		}
	}
	 
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0 && MAP[i][j] == 0) {
				return INT_MAX;
			}
			else if (visit[i][j] != 0 && MAP[i][j] == 2) {
				visit[i][j] = 1;
			}
			if (result < visit[i][j]) {
				result = visit[i][j];
			}
		}
	}

	return result - 1;
}

void toSelect(int length, int count) {
	if (length == vir.size()) {
		if (count != M) return;

		int temp = moveVir();

		if (temp < result) {
			result = temp;
		}

		return;
	}

	selectVir[length] = true;
	toSelect(length + 1, count+1);
	selectVir[length] = false;
	toSelect(length + 1,count);
}

int solution() {
	
	toSelect(0,0);
	
	return result == INT_MAX ? -1 : result;
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
