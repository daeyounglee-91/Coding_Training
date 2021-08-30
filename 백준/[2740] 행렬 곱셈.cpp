#include<iostream>

using namespace std;

int arr[3][150][150];
int N, M, K;

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[0][i][j];
		}
	}

	cin >> M >> K;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> arr[1][i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				arr[2][i][j] += (arr[0][i][k] * arr[1][k][j]);
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << arr[2][i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}