#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

struct DRAGONCURVE{
    int y,x;
    int d,g;
};

int N;
vector<DRAGONCURVE> v_dragoncurve;
int MAP[150][150] = {0,};

int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

bool isRange(int y, int x){
    return (y >= 0 && y <= 100) && (x >= 0 && x <= 100);
}

void input(){
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        DRAGONCURVE d;
        cin >> d.x >> d.y >> d.d >> d.g;
        v_dragoncurve.push_back(d);

        MAP[d.y][d.x] = 1;
    }
}

void makeCurve(int idx){

    vector<int> vd;
    int y = v_dragoncurve[idx].y;
    int x = v_dragoncurve[idx].x;
    int g = v_dragoncurve[idx].g;

    vd.push_back(v_dragoncurve[idx].d);

    for(int i = 0 ; i < g ; i++){
        int size = vd.size();
        for(int j = size - 1 ; j >= 0 ; j--){
            int d = (vd[j]+1)%4;
            vd.push_back(d);
        }
    }

    for(int i = 0 ; i < vd.size() ; i++){

        y += dir[vd[i]][0];
        x += dir[vd[i]][1];

        if(!isRange(y,x)) continue;

        MAP[y][x] = 1;
    }
}

int checkRect(){
    int result = 0;

    for(int i = 0 ; i <= 100 ; i++){
        for(int j = 0 ; j <= 100 ; j++){
            if(MAP[i][j] == 1 && MAP[i][j+1] == 1 && MAP[i+1][j] == 1 && MAP[i+1][j+1] == 1){
                result++;
            }
        }
    }
    return result;
}

int solution(){
    int result = 0;
    
    for(int i = 0 ; i < N ; i++){
        makeCurve(i);
    }
    result = checkRect();

    return result;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solution() << endl;

    return 0;
}