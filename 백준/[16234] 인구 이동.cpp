#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int N, L, R;
int MAP[100][100] = { 0, };
int visit[100][100] = { 0, };
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
vector<int> sum;
vector<int> c_count;

bool isRange(int y, int x) {
    return (y >= 0 && y < N) && (x >= 0 && x < N);
}

void input() {
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
}

void checkMAP(int y, int x, int num) {

    visit[y][x] = num;
    
    for (int i = 0; i < 4; i++) {
        int ty = y + dir[i][0];
        int tx = x + dir[i][1];

        if (!isRange(ty, tx) || visit[ty][tx] != 0) continue;

        int dif = abs(MAP[y][x] - MAP[ty][tx]);
        if (dif >= L && dif <= R) {
            checkMAP(ty, tx, num);
        }
    }
}

void calcMAP(int num) {

    sum.clear();
    c_count.clear();

    sum.resize(num+1, 0);
    c_count.resize(num+1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c_count[visit[i][j]]++;
            sum[visit[i][j]] += MAP[i][j];
        }
    }
}

void changeMAP() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            MAP[i][j] = sum[visit[i][j]] / c_count[visit[i][j]];
            visit[i][j] = 0;
        }
    }
}

void print() {
    cout << "============================" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}

int solution() {
    int result = 0;

    while (true)
    {
        int temp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visit[i][j] != 0) continue;
                temp++;
                checkMAP(i, j, temp);
            }
        }

        if (temp >= N * N) {
           break;
        }
        else {
            result++;
        }

        calcMAP(temp);
        changeMAP();

      //  print();

    }

    return result;
}

int main() {

    input();
    cout << solution() << endl;

    return 0;
}