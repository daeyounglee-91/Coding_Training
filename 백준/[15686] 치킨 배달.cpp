#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;

int N, M;
vector<pair<int, int>> h;
vector<pair<int, int>> s;

int result = INT_MAX;
bool selectStore[20];

int calcDist(int hNum, int sNum) {
	return abs(h[hNum].first - s[sNum].first) + abs(h[hNum].second - s[sNum].second);
}

int calcChickDist() {
	int dist = 0;

	for (int i = 0; i < h.size(); i++) {
		int min = INT_MAX;
		for (int j = 0; j < s.size(); j++) {
			if (!selectStore[j]) continue;
			int temp = calcDist(i, j);
			if (min > temp) {
				min = temp;
			}
		}
		dist += min;
	}

	return dist;
}

void toSelect(int length, int count) {
	if (length >= s.size()) {
		if (count != M) return;

		int temp = calcChickDist();
		if (result > temp) {
			result = temp;
		}

		return;
	}

	selectStore[length] = true;
	toSelect(length + 1, count + 1);
	selectStore[length] = false;
	toSelect(length + 1, count);
}

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				h.push_back(make_pair(i, j));
			}
			else if (num == 2) {
				s.push_back(make_pair(i, j));
			}
		}
	}

	toSelect(0, 0);

	cout << result;
}