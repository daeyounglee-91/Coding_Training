#include<iostream>
#include<climits>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>

using namespace std;

int N;
int MAP[150][150] = { 0, };
int selectTeam[150] = { 0, };
int result = INT_MAX;

void init() {
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

int calc() {
	int t[2] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;

			if (selectTeam[i] == selectTeam[j]) {
				t[selectTeam[i]] += MAP[i][j];
			}
		}
	}
	return abs(t[0] - t[1]);
}

void toSelect(int length, int count) {
	if (length == N) {
		if (count == N / 2) {
			int temp = calc();
			if (temp < result) {
				result = temp;
			}
		}
		return;
	}

	selectTeam[length] = 0;
	toSelect(length + 1, count + 1);
	selectTeam[length] = 1;
	toSelect(length + 1, count);
}

int solution() {
	toSelect(0, 0);
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
	solution();
	cout << solution() << endl;
	//}

	return 0;
}
