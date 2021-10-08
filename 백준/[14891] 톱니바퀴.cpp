#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

deque<int> MAGNET[4];
int N;
queue<pair<int,int>> q;
int rot[4];

void input(){
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            char m;
            cin >> m;
            MAGNET[i].push_back(m-'0');
        }
    }

    cin >> N;

    for(int i = 0 ; i < N ; i++){
        int num,r;
        cin >> num >> r;
        q.push(make_pair(num-1,r));
    }
}

void select_rot(int num, int d){
    rot[num] = d;

    for(int i = num + 1 ; i < 4 ; i++){
        if(MAGNET[i-1][2] == MAGNET[i][6]) {
            rot[i] = 0;
        }else{
            rot[i] = rot[i-1] * -1;
        }
    }

    for(int i = num - 1 ; i >= 0 ; i--){ 
        if(MAGNET[i+1][6] == MAGNET[i][2]) {
            rot[i] = 0;
        }else{
            rot[i] = rot[i+1] * -1;
        }
    }
}

void clockwise(int idx){
    int temp = MAGNET[idx].back();
    MAGNET[idx].pop_back();
    MAGNET[idx].push_front(temp);
}

void reverse_clockwise(int idx){
    int temp = MAGNET[idx].front();
    MAGNET[idx].pop_front();
    MAGNET[idx].push_back(temp);
}

void rotate(){

    for(int i = 0 ; i < 4 ; i++){
        if(rot[i] == 0) continue;
        
        if(rot[i] == 1){
            clockwise(i);
        }else if(rot[i] == -1){
            reverse_clockwise(i);
        }
    }
}

int check_score(){
    int result = 0;
    for(int i = 0 ; i < 4 ; i++){
        result += (MAGNET[i][0]*pow(2,i));
    }

    return result;
}

int solution(){
    int result = 0;

    for(int i = 0 ; i < N ; i++){
        int num = q.front().first;
        int d = q.front().second;

        q.pop();
        select_rot(num,d);
        rotate();
    }

    return check_score();
}

int main(){

    input();
    cout << solution() << endl;

    return 0;
}