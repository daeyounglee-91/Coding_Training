#include<iostream>
#include<climits>

using namespace std;

string WFirst[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW" };

string BFirst[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB" };

string MAP[100];

int Check_Map(int x, int y) {
	int Wresult = 0;
	int Bresult = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (WFirst[i].at(j) != MAP[i + y].at(j + x)) {
				Wresult++;
			}
			if (BFirst[i].at(j) != MAP[i + y].at(j + x)) {
				Bresult++;
			}
		}
	}

	if (Wresult < Bresult) {
		return Wresult;
	}
	else {
		return Bresult;
	}
}

int main() {

	int N, M;
	int result = INT_MAX;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int temp = Check_Map(j, i);
			if (result > temp) {
				result = temp;
			}
		}
	}

	cout << result;

	return 0;
}