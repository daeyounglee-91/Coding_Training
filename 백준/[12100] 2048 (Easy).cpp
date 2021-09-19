#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int N;
int MAP[50][50] = { 0, };
int org_MAP[50][50] = { 0, };
int n_select[10] = { 0, };
int result = 0;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            org_MAP[i][j] = MAP[i][j];
        }
    }
}

int max() {
    int temp = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp < MAP[i][j]) {
                temp = MAP[i][j];
            }
        }
    }
    return temp;
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            MAP[i][j] = org_MAP[i][j];
        }
    }
}


void up() {

    queue<int> q;
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {
            if (MAP[j][i] == 0) continue;

            q.push(MAP[j][i]);
            MAP[j][i] = 0;
        }

        int idx = 0;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            if (MAP[idx][i] == 0) {
                MAP[idx][i] = temp;
            }
            else if (MAP[idx][i] == temp) {
                MAP[idx][i] = temp * 2;
                idx++;
            }
            else {
                MAP[++idx][i] = temp;
            }
        }
    }
}

void down() {

    queue<int> q;
    for (int i = 0; i < N; i++) {

        for (int j = N - 1; j >= 0; j--) {
            if (MAP[j][i] == 0) continue;

            q.push(MAP[j][i]);
            MAP[j][i] = 0;
        }

        int idx = N - 1;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            if (MAP[idx][i] == 0) {
                MAP[idx][i] = temp;
            }
            else if (MAP[idx][i] == temp) {
                MAP[idx][i] = temp * 2;
                idx--;
            }
            else {
                MAP[--idx][i] = temp;
            }
        }
    }
}

void left() {

    queue<int> q;
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {
            if (MAP[i][j] == 0) continue;

            q.push(MAP[i][j]);
            MAP[i][j] = 0;
        }

        int idx = 0;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            if (MAP[i][idx] == 0) {
                MAP[i][idx] = temp;
            }
            else if (MAP[i][idx] == temp) {
                MAP[i][idx] = temp * 2;
                idx++;
            }
            else {
                MAP[i][++idx] = temp;
            }
        }
    }
}

void right() {

    queue<int> q;
    for (int i = 0; i < N; i++) {

        for (int j = N - 1; j >= 0; j--) {
            if (MAP[i][j] == 0) continue;

            q.push(MAP[i][j]);
            MAP[i][j] = 0;
        }

        int idx = N - 1;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            if (MAP[i][idx] == 0) {
                MAP[i][idx] = temp;
            }
            else if (MAP[i][idx] == temp) {
                MAP[i][idx] = temp * 2;
                idx--;
            }
            else {
                MAP[i][--idx] = temp;
            }
        }
    }
}

void move(int dir) {
    if (dir == 0) {
        up();
    }
    else if (dir == 1) {
        down();
    }
    else if (dir == 2) {
        left();
    }
    else if (dir == 3) {
        right();
    }
}
void print() {
    cout << "===============================" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}

void toSelect(int length) {
    if (length == 5) {

        init();

        // for(int i = 0 ; i < 5 ; i++){
        //     cout << select[i] << " ";
        // }
        // cout << endl;

        for (int i = 0; i < 5; i++) {
            move(n_select[i]);
            // print();
        }

        int temp = max();
        if (temp > result) {
            result = temp;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
       // if (length != 0 && n_select[length - 1] == i) continue;
        n_select[length] = i;
        toSelect(length + 1);
    }
}


int solution() {
    // int result = 0;

    toSelect(0);

    return result;
}

int main() {

    input();
    cout << solution() << endl;

    return 0;
}