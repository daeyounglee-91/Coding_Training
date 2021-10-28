#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int N,M;
int y,x,d;
int MAP[100][100] = {0,};
int visit[100][100] = {0,};

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    int result = 0;

void input(){
    cin >> N >> M;
    cin >> y >> x >> d;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> MAP[i][j];
        }
    }
}

bool checkleft(){
    // cout << "checkleft" << endl;
    int t_y = y + dir[d][0];
    int t_x = x + dir[d][1];

    if(MAP[t_y][t_x] == 1) return false;

    if(visit[t_y][t_x] != 0) return false;

    return true;
}

bool move_back(){
    // cout << "move_back" << endl;
    int t_y = y + dir[(d+2)%4][0];
    int t_x = x + dir[(d+2)%4][1];

    if(MAP[t_y][t_x] == 1) return false;

    y = t_y;
    x = t_x;
    return true;
}

bool move(){
// cout << "move : " << d<< endl;
    if(visit[y][x] == 0){
        visit[y][x] = ++result;
    }

    int temp_d = d;

    for(int i = 0 ; i < 4 ; i++){
        d = (4+d-1)%4;
        if(checkleft()) {
            y += dir[d][0];
            x += dir[d][1];
            return true;
        }
    }

    if(temp_d == d){
        if(move_back()) return true;
        return false;
    }
    return true;
}

int solution(){
    

    while (true)
    {
        // cout << result << endl;
        if(!move()) break;

        
        // cout << "=======================================" << endl;
        // for(int i = 0 ; i < N ; i++){
        //     for(int j = 0 ; j < M ; j++){
        //         cout << visit[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // //  if(result == 20) break;
    }
    
    // cout << "=======================================" <<endl;
    // for(int i = 0 ; i < N ; i++){
    //     for(int j = 0 ; j < M ; j++){
    //         cout << visit[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    return result;
}

int main(){

    input();
    cout << solution() << endl;

    return 0;
}