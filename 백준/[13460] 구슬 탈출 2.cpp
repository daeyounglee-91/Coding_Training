#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int N, M;
int MAP[20][20];
int result = INT_MAX;

pair<int, int> rb;
pair<int, int> bb;

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

enum MAP_INFO {
	BLANK = 0,
	BLOCK,
	RED,
	BLUE,
	HOLE
};



void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;

			if (c == '#') {
				MAP[i][j] = BLOCK;
			}
			else if (c == 'R') {
				MAP[i][j] = RED;
				rb = make_pair(i, j);
			}
			else if (c == 'B') {
				MAP[i][j] = BLUE;
				bb = make_pair(i, j);
			}
			else if (c == 'O') {
				MAP[i][j] = HOLE;
			}
			else {
				MAP[i][j] = BLANK;
			}
		}
	}
}

int reverse(int d) {
	if (d == 0) {
		return 1;
	}
	else if (d == 1) {
		return 0;
	}
	else if (d == 2) {
		return 3;
	}
	else {
		return 2;
	}
}

void move(pair<int, int> r, pair<int, int> b, int d, int count) {

	if (count > 10 || count > result) return;

	bool r_flag = false;
	bool b_flag = false;

	int ry = r.first;
	int rx = r.second;
	int by = b.first;
	int bx = b.second;

	while (true) {

		ry += dir[d][0];
		rx += dir[d][1];


		if (MAP[ry][rx] == HOLE) {
			r_flag = true;
			break;
		}

		if (MAP[ry][rx] == BLOCK)
		{
			ry -= dir[d][0];
			rx -= dir[d][1];
			break;
		}
	}

	while (true) {

		by += dir[d][0];
		bx += dir[d][1];


		if (MAP[by][bx] == HOLE) {
			b_flag = true;
			break;
		}

		if (MAP[by][bx] == BLOCK)
		{
			by -= dir[d][0];
			bx -= dir[d][1];
			break;
		}
	}

	if (b_flag == 1) return;

	if (r_flag == 1) {
		if (count < result) {
			result = count;
		}
		return;
	}

	if (ry == by && rx == bx) {
		int rd = abs(r.first - ry) + abs(r.second - rx);
		int bd = abs(b.first - by) + abs(b.second - bx);

		if (rd > bd) {
			ry -= dir[d][0];
			rx -= dir[d][1];
		}
		else {
			by -= dir[d][0];
			bx -= dir[d][1];
		}
	}

	r = make_pair(ry, rx);
	b = make_pair(by, bx);

	// cout <<count << ":" << d << " " << r.first << ", " << r.second << " // " << b.first << ", " << b.second << endl;

	for (int i = 0; i < 4; i++) {
		if (i == d || i == reverse(d)) continue;
		move(r, b, i, count + 1);
	}
}

int soilution() {


	for (int i = 0; i < 4; i++) {
		move(rb, bb, i, 1);
	}

	return (result == INT_MAX || result > 10) ? -1: result;
}

int main()
{

	input();
	cout << soilution() << endl;

	return 0;
}
