#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cmath>
#include<algorithm>

using namespace std;

int N;
int MAP[40][40];

int s;
int c;
int sy,sx;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

bool isRange(int y, int x) { return (y >= 0 && y < N) && (x >= 0 && x < N); }

bool comp(pair<int, pair<int, int>> v1, pair<int, pair<int, int>> v2) {
	if (v1.first < v2.first) return true;
	else if (v1.first > v2.first) return false;

	if (v1.second.first < v2.second.first) return true;
	else if (v1.second.first > v2.second.first) return false;

	if (v1.second.second < v2.second.second) return true;
	else return false;
}

int eatFish() {
	int visit[40][40] = {0,};
	queue<pair<int, int>> q;
	vector<pair<int,pair<int, int>>> v;
	q.push(make_pair(sy, sx));
	//visit[sy][sx] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = y + dir[i][0];
			int tx = x + dir[i][1];

			if (!isRange(ty, tx) || MAP[ty][tx] > s || visit[ty][tx] != 0 || MAP[ty][tx] == 9) continue;

			visit[ty][tx] = visit[y][x] + 1;
			q.push(make_pair(ty, tx));
			if (MAP[ty][tx] != 0 && MAP[ty][tx] < s) {
				v.push_back(make_pair(visit[ty][tx],make_pair(ty, tx)));
			}
		}
	}

	if (v.empty()) return -1;

	sort(v.begin(), v.end(), comp);

	MAP[sy][sx] = 0;
	sy = v[0].second.first;
	sx = v[0].second.second;
	MAP[sy][sx] = 9;


	//cout << "=============================" << endl;
	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i].first << ", " << v[i].second.first << ", " << v[i].second.second << endl;
	//}

	//cout << "=============================" << endl;
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << visit[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	//cout << "=============================" << endl;
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << MAP[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	return v[0].first;
}

int simulation() {
	int time = 0;

	while (true) {
		int temp = eatFish();
		if (temp == -1) break;
		time += temp;
		c++;
		if (c == s) {
			s++;
			c = 0;
		}
	}


	return time;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 9) {
				sy = i;
				sx = j;
			}
		}
	}

	s = 2;
	c = 0;

	int result = simulation();

	cout << result;
}