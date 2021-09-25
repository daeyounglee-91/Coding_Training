#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int N,M;
int x,y,K;
int MAP[40][40] = {0,};
int d[1500] = {0,};

int dir[5][2] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};

int dice[6] = {0,0,0,0,0,0};


bool isRange(int ty, int tx){
    return (ty >= 0 && ty < N) &&  (tx >= 0 && tx < M);
}

void input(){
    cin >> N >> M >> y >> x >> K;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> MAP[i][j];
        }
    }

    for(int i = 0 ; i < K ; i++){
        cin >> d[i];
    }
}

void rollDice(int n){

    int t_d[6] = {0,};

    for(int i = 0 ; i < 6 ; i++){
        t_d[i] = dice[i];
    }

    if(n == 1){
        dice[0] = t_d[3];
        dice[2] = t_d[0];
        dice[3] = t_d[5];
        dice[5] = t_d[2];
    }else if(n == 2){
        dice[0] = t_d[2];
        dice[2] = t_d[5];
        dice[3] = t_d[0];
        dice[5] = t_d[3];
    }else if(n == 3){
        dice[1] = t_d[0];
        dice[0] = t_d[4];
        dice[4] = t_d[5];
        dice[5] = t_d[1];
    }else if(n == 4){
        dice[1] = t_d[5];
        dice[0] = t_d[1];
        dice[4] = t_d[0];
        dice[5] = t_d[4];
    }
}

void solution(){
    int result = 0;

    for(int i = 0 ; i < K ; i++){
        int ny = y + dir[d[i]][0];
        int nx = x + dir[d[i]][1];

        if(!isRange(ny,nx)) continue;

        rollDice(d[i]);

        if(MAP[ny][nx] == 0){
            MAP[ny][nx] = dice[5];
        }else{
            dice[5] = MAP[ny][nx];
            MAP[ny][nx] = 0;
        }

        y = ny;
        x = nx;

        cout << dice[0] << endl;
    }
  
   // return result;
}

int main(){

    input();
    solution();
  //  cout << solution() << endl;

    return 0;
}