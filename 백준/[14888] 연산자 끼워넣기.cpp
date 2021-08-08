#include<iostream>
#include<climits>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>

using namespace std;

int N;
vector<int> nums;
int sym[4] = { 0, };
int selectSym[20] = { 0, };

int MAX = -100000001;
int MIN = 100000001;

void init() {

}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	for (int i = 0; i < 4; i++) {
		cin >> sym[i];
	}
}

int calc() {
	int num = nums[0];

	for (int i = 1; i < N; i++) {
		if (selectSym[i - 1] == 0) {
			num += nums[i];
		}
		else if (selectSym[i - 1] == 1) {
			num -= nums[i];
		}
		else if (selectSym[i - 1] == 2) {
			num *= nums[i];
		}
		else {
			num /= nums[i];
		}
	}
	return num;
}

void toSelect(int length) {
	if (length == N - 1) {
		int temp = calc();

		if (temp > MAX) {
			MAX = temp;
		}

		if (temp < MIN) {
			MIN = temp;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (sym[i] == 0) continue;

		sym[i]--;
		selectSym[length] = i;
		toSelect(length + 1);
		sym[i]++;
	}
}

void solution() {
	toSelect(0);
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
	cout << MAX << endl;
	cout << MIN << endl;
	//}

	return 0;
}
