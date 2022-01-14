#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<math.h>
#include<limits.h>

using namespace std;

int main(){

	int arr[2][50] = {0,};
	int T;

	cin >> T;

	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;

	for(int i = 2 ; i < 45 ; i++){
		arr[0][i] = arr[0][i-1] + arr[0][i-2];
		arr[1][i] = arr[1][i-1] + arr[1][i-2];
	}

	for(int i = 0 ; i < T ; i++){

		int N;
		cin >> N;

		cout << arr[0][N] << " " << arr[1][N] << endl;
	}

	return 0;
}