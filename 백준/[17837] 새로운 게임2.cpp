#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

struct UNIT
{
    int y, x;
    int d;
};

int N, K;
vector<UNIT> units;
int MAP[20][20] = { 0, };
vector<int> UMAP[20][20];
int dir[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };

bool isRange(int y, int x) {
    return (y >= 1 && y <= N) && (x >= 1 && x <= N);
}

void print() {
    cout << "=============================================" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << UMAP[i][j].size() << " ";
        }
        cout << endl;
    }
}

void input() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        UNIT u;
        cin >> u.y >> u.x >> u.d;
        units.push_back(u);
        UMAP[u.y][u.x].push_back(i);
    }
}

int changeDir(int d) {
    if (d == 1) return 2;
    if (d == 2) return 1;
    if (d == 3) return 4;
    if (d == 4) return 3;
}

bool moveUnit(int idx) {
    bool result = false;

    int y = units[idx].y;
    int x = units[idx].x;
    int ny = units[idx].y + dir[units[idx].d][0];
    int nx = units[idx].x + dir[units[idx].d][1];

    if (!isRange(ny, nx) || MAP[ny][nx] == 2) {
        units[idx].d = changeDir(units[idx].d);
        ny = y + dir[units[idx].d][0];
        nx = x + dir[units[idx].d][1];

        if (!isRange(ny, nx) || MAP[ny][nx] == 2) return result;
    }

    if (MAP[ny][nx] == 0) {
        bool flag = false;
        int n = 0;
        for (int i = 0; i < UMAP[y][x].size(); i++) {
            if (UMAP[y][x][i] == idx) flag = true;

            if (flag) {
                n++;
                units[UMAP[y][x][i]].y = ny;
                units[UMAP[y][x][i]].x = nx;
                UMAP[ny][nx].push_back(UMAP[y][x][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            UMAP[y][x].pop_back();
        }
    }
    else if (MAP[ny][nx] == 1) {
        bool flag = false;
        int n = 0;

        for (int i = 0; i < UMAP[y][x].size(); i++) {
            if (UMAP[y][x][i] == idx) flag = true;

            if (flag) {
                n++;
                units[UMAP[y][x][i]].y = ny;
                units[UMAP[y][x][i]].x = nx;
            }
        }

        for (int i = 0; i < n; i++) {
            UMAP[ny][nx].push_back(UMAP[y][x].back());
            UMAP[y][x].pop_back();
        }
    }

    if (UMAP[ny][nx].size() >= 4) {
        result = true;
    }

    return result;
}

bool move() {
    bool result = false;
    for (int i = 0; i < units.size(); i++) {
        result = moveUnit(i);
        if (result) break;
    }
    //print();
    return result;
}

int solution() {
    int result = 0;
   // print();

    while (result <= 1000) {
        result++;
        if (move()) break;

    }

    return result > 1000 ? -1 : result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solution() << endl;

    return 0;
}

