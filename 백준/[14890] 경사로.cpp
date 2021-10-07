#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int N,L;
int MAP[150][150] = {0,};

void input(){
    cin >> N >> L;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> MAP[i][j];
        }
    }
}

bool checkW(int idx){
    bool visit[150] = {0,};
    for(int i = 1 ; i < N ; i++){
        if(abs(MAP[idx][i-1] - MAP[idx][i]) > 1) return false;
        if(MAP[idx][i-1] == MAP[idx][i]) continue;

        if(MAP[idx][i-1] - MAP[idx][i] == 1){
            for(int j = i ; j < i+L ; j++){
                if(visit[j]) return false;
                if(MAP[idx][i-1] - MAP[idx][j] != 1) return false;

                visit[j] = true;
            }
            i += L - 1;
        }else if(MAP[idx][i-1] - MAP[idx][i] == -1){
            for(int j = i-1 ; j >= i-L ; j--){
                if(visit[j]) return false;
                if(MAP[idx][i] - MAP[idx][j] != 1) return false;

                visit[j] = true;
            }
        }

    }
    return true;
}

bool checkH(int idx){
    bool visit[150] = {0,};
    for(int i = 1 ; i < N ; i++){
        if(abs(MAP[i-1][idx] - MAP[i][idx]) > 1) return false;
        if(MAP[i-1][idx] == MAP[i][idx]) continue;

        if(MAP[i-1][idx] - MAP[i][idx] == 1){
            for(int j = i ; j < i+L ; j++){
                if(visit[j]) return false;
                if(MAP[i-1][idx] - MAP[j][idx] != 1) return false;

                visit[j] = true;
            }
            i += L - 1;
        }else if(MAP[i-1][idx] - MAP[i][idx] == -1){
            for(int j = i-1 ; j >= i-L ; j--){
                if(visit[j]) return false;
                if(MAP[i][idx] - MAP[j][idx] != 1) return false;

                visit[j] = true;
            }
        }

    }
    return true;
}

int solution(){
    int result = 0;

    for(int i = 0 ; i < N ; i++){
        if(checkW(i)){
            result++;
        }
    }

    for(int i = 0 ; i < N ; i++){
        if(checkH(i)){
            result++;
        }
    }

    return result;
}

int main(){

    input();
    cout << solution() << endl;

    return 0;
}