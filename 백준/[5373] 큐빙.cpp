#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;
int n;
char cube[6][3][3];
vector<pair<char, char>> rotates;
string color = "wryogb";

void printU() {
	//cout << "=================U================" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[0][i][j];
		}
		cout << endl;
	}
}

void printD() {
	cout << "=================D================" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[2][i][j];
		}
		cout << endl;
	}
}

void printF() {
	cout << "=================F================" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[1][i][j];
		}
		cout << endl;
	}
}

void printB() {
	cout << "=================B================" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[3][i][j];
		}
		cout << endl;
	}
}

void printL() {
	cout << "=================L================" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[4][i][j];
		}
		cout << endl;
	}
}

void printR() {
	cout << "=================R================" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[5][i][j];
		}
		cout << endl;
	}
}

void printAll() {
	printU();
	printD();
	printF();
	printB();
	printR();
	printL();
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c1, c2;
		cin >> c1 >> c2;
		rotates.push_back(make_pair(c1, c2));
	}
}

void init() {
	for (int i = 0; i < 6; i++) {
        int num = 0;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = /*'0'+num;*/color[i];
                num++;
			}
		}
	}
	rotates.clear();
}


void rotateClockwiseU() {
	char t_cube[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			t_cube[i][j] = cube[0][i][j];
		}
	}

	cube[0][0][0] = t_cube[2][0];
	cube[0][0][1] = t_cube[1][0];
	cube[0][0][2] = t_cube[0][0];
	cube[0][1][0] = t_cube[2][1];
	cube[0][1][2] = t_cube[0][1];
	cube[0][2][0] = t_cube[2][2];
	cube[0][2][1] = t_cube[1][2];
	cube[0][2][2] = t_cube[0][2];

	char Tmp1, Tmp2, Tmp3;
	Tmp1 = cube[1][0][0];
	Tmp2 = cube[1][0][1];
	Tmp3 = cube[1][0][2];

	cube[1][0][0] = cube[5][0][0];
	cube[1][0][1] = cube[5][0][1];
	cube[1][0][2] = cube[5][0][2];

	cube[5][0][0] = cube[3][0][0];
	cube[5][0][1] = cube[3][0][1];
	cube[5][0][2] = cube[3][0][2];

	cube[3][0][0] = cube[4][0][0];
	cube[3][0][1] = cube[4][0][1];
	cube[3][0][2] = cube[4][0][2];

	cube[4][0][0] = Tmp1;
	cube[4][0][1] = Tmp2;
	cube[4][0][2] = Tmp3;
}

void rotateCountClockwiseU() {
	for (int i = 0; i < 3; i++) {
		rotateClockwiseU();
	}
}

void rotateClockwiseF() {
	char t_cube[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			t_cube[i][j] = cube[1][i][j];
		}
	}

	cube[1][0][0] = t_cube[2][0];
	cube[1][0][1] = t_cube[1][0];
	cube[1][0][2] = t_cube[0][0];
	cube[1][1][0] = t_cube[2][1];
	cube[1][1][2] = t_cube[0][1];
	cube[1][2][0] = t_cube[2][2];
	cube[1][2][1] = t_cube[1][2];
	cube[1][2][2] = t_cube[0][2];

	char Tmp1, Tmp2, Tmp3;
	Tmp1 = cube[0][2][0];
	Tmp2 = cube[0][2][1];
	Tmp3 = cube[0][2][2];

	cube[0][2][0] = cube[4][2][2];
	cube[0][2][1] = cube[4][1][2];
	cube[0][2][2] = cube[4][0][2];

	cube[4][0][2] = cube[2][0][0];
	cube[4][1][2] = cube[2][0][1];
	cube[4][2][2] = cube[2][0][2];

	cube[2][0][0] = cube[5][2][0];
	cube[2][0][1] = cube[5][1][0];
	cube[2][0][2] = cube[5][0][0];

	cube[5][0][0] = Tmp1;
	cube[5][1][0] = Tmp2;
	cube[5][2][0] = Tmp3;
}

void rotateCountClockwiseF() {
	for (int i = 0; i < 3; i++) {
		rotateClockwiseF();
	}
}

void rotateClockwiseD() {
	char t_cube[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			t_cube[i][j] = cube[2][i][j];
		}
	}

	cube[2][0][0] = t_cube[2][0];
	cube[2][0][1] = t_cube[1][0];
	cube[2][0][2] = t_cube[0][0];
	cube[2][1][0] = t_cube[2][1];
	cube[2][1][2] = t_cube[0][1];
	cube[2][2][0] = t_cube[2][2];
	cube[2][2][1] = t_cube[1][2];
	cube[2][2][2] = t_cube[0][2];

	char Tmp1, Tmp2, Tmp3;
	Tmp1 = cube[1][2][0];
	Tmp2 = cube[1][2][1];
	Tmp3 = cube[1][2][2];

	cube[1][2][0] = cube[4][2][0];
	cube[1][2][1] = cube[4][2][1];
	cube[1][2][2] = cube[4][2][2];

	cube[4][2][0] = cube[3][2][0];
	cube[4][2][1] = cube[3][2][1];
	cube[4][2][2] = cube[3][2][2];

	cube[3][2][0] = cube[5][2][0];
	cube[3][2][1] = cube[5][2][1];
	cube[3][2][2] = cube[5][2][2];

	cube[5][2][0] = Tmp1;
	cube[5][2][1] = Tmp2;
	cube[5][2][2] = Tmp3;
}

void rotateCountClockwiseD() {
	for (int i = 0; i < 3; i++) {
		rotateClockwiseD();
	}
}

void rotateClockwiseB() {
	char t_cube[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			t_cube[i][j] = cube[3][i][j];
		}
	}

	cube[3][0][0] = t_cube[2][0];
	cube[3][0][1] = t_cube[1][0];
	cube[3][0][2] = t_cube[0][0];
	cube[3][1][0] = t_cube[2][1];
	cube[3][1][2] = t_cube[0][1];
	cube[3][2][0] = t_cube[2][2];
	cube[3][2][1] = t_cube[1][2];
	cube[3][2][2] = t_cube[0][2];

	char Tmp1, Tmp2, Tmp3;
	Tmp1 = cube[0][0][0];
	Tmp2 = cube[0][0][1];
	Tmp3 = cube[0][0][2];

	cube[0][0][0] = cube[5][0][2];
	cube[0][0][1] = cube[5][1][2];
	cube[0][0][2] = cube[5][2][2];

	cube[5][0][2] = cube[2][2][2];
	cube[5][1][2] = cube[2][2][1];
	cube[5][2][2] = cube[2][2][0];

	cube[2][2][2] = cube[4][2][0];
	cube[2][2][1] = cube[4][1][0];
	cube[2][2][0] = cube[4][0][0];

	cube[4][2][0] = Tmp1;
	cube[4][1][0] = Tmp2;
	cube[4][0][0] = Tmp3;
}

void rotateCountClockwiseB() {
	for (int i = 0; i < 3; i++) {
		rotateClockwiseB();
	}
}

void rotateClockwiseL() {
	char t_cube[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			t_cube[i][j] = cube[4][i][j];
		}
	}

	cube[4][0][0] = t_cube[2][0];
	cube[4][0][1] = t_cube[1][0];
	cube[4][0][2] = t_cube[0][0];
	cube[4][1][0] = t_cube[2][1];
	cube[4][1][2] = t_cube[0][1];
	cube[4][2][0] = t_cube[2][2];
	cube[4][2][1] = t_cube[1][2];
	cube[4][2][2] = t_cube[0][2];

	char Tmp1, Tmp2, Tmp3;
	Tmp1 = cube[1][0][0];
	Tmp2 = cube[1][1][0];
	Tmp3 = cube[1][2][0];

	cube[1][0][0] = cube[0][0][0];
	cube[1][1][0] = cube[0][1][0];
	cube[1][2][0] = cube[0][2][0];

	cube[0][0][0] = cube[3][2][2];
	cube[0][1][0] = cube[3][1][2];
	cube[0][2][0] = cube[3][0][2];

	cube[3][2][2] = cube[2][0][0];
	cube[3][1][2] = cube[2][1][0];
	cube[3][0][2] = cube[2][2][0];

	cube[2][0][0] = Tmp1;
	cube[2][1][0] = Tmp2;
	cube[2][2][0] = Tmp3;
}

void rotateCountClockwiseL() {
	for (int i = 0; i < 3; i++) {
		rotateClockwiseL();
	}
}

void rotateClockwiseR() {
	char t_cube[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			t_cube[i][j] = cube[5][i][j];
		}
	}

	cube[5][0][0] = t_cube[2][0];
	cube[5][0][1] = t_cube[1][0];
	cube[5][0][2] = t_cube[0][0];
	cube[5][1][0] = t_cube[2][1];
	cube[5][1][2] = t_cube[0][1];
	cube[5][2][0] = t_cube[2][2];
	cube[5][2][1] = t_cube[1][2];
	cube[5][2][2] = t_cube[0][2];

	char Tmp1, Tmp2, Tmp3;
	Tmp1 = cube[0][0][2];
	Tmp2 = cube[0][1][2];
	Tmp3 = cube[0][2][2];

	cube[0][0][2] = cube[1][0][2];
	cube[0][1][2] = cube[1][1][2];
	cube[0][2][2] = cube[1][2][2];

	cube[1][0][2] = cube[2][0][2];
	cube[1][1][2] = cube[2][1][2];
	cube[1][2][2] = cube[2][2][2];

	cube[2][0][2] = cube[3][2][0];
	cube[2][1][2] = cube[3][1][0];
	cube[2][2][2] = cube[3][0][0];

	cube[3][2][0] = Tmp1;
	cube[3][1][0] = Tmp2;
	cube[3][0][0] = Tmp3;
}

void rotateCountClockwiseR() {
	for (int i = 0; i < 3; i++) {
		rotateClockwiseR();
	}
}

void solution() {
	for (int i = 0; i < rotates.size(); i++) {
		if (rotates[i].first == 'U') {
			if (rotates[i].second == '+') {
				rotateClockwiseU();
			}
			else {
				rotateCountClockwiseU();
			}
		}
		else if (rotates[i].first == 'F') {
			if (rotates[i].second == '+') {
				rotateClockwiseF();
			}
			else {
				rotateCountClockwiseF();
			}
		}
		else if (rotates[i].first == 'D') {
			if (rotates[i].second == '+') {
				rotateClockwiseD();
			}
			else {
				rotateCountClockwiseD();
			}
		}
		else if (rotates[i].first == 'B') {
			if (rotates[i].second == '+') {
				rotateClockwiseB();
			}
			else {
				rotateCountClockwiseB();
			}
		}
		else if (rotates[i].first == 'L') {
			if (rotates[i].second == '+') {
				rotateClockwiseL();
			}
			else {
				rotateCountClockwiseL();
			}
		}
		else if (rotates[i].first == 'R') {
			if (rotates[i].second == '+') {
				rotateClockwiseR();
			}
			else {
				rotateCountClockwiseR();
			}
		}

	//printAll();
	}
}

int main() {

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		init();
		input();
		solution();
		printU();
	}

	return 0;
}

S