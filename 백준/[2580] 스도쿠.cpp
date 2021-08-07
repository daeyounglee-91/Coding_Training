#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

int MAP[15][15] = {0,};
vector<pair<int,int>> v;
bool is_end = false;

bool is_possible(int x, int y){

    for(int i = 0 ; i < 10 ; i++){  //가로
        if(x == i) continue;
        if(MAP[y][i] == MAP[y][x]){
            return false;
        }
    }

    for(int i = 0 ; i < 10 ; i++){  //세로
        if(y == i) continue;
        if(MAP[i][x] == MAP[y][x]){
            return false;
        }
    }

    int t_x = (x/3)*3;
    int t_y = (y/3)*3;
    for(int i = t_y ; i < t_y+3 ; i++){  //네모
        for(int j = t_x ; j < t_x+3 ; j++){  //네모
            if(y == i && x == j) continue;
            if(MAP[i][j] == MAP[y][x]){
                return false;
            }
        }
    }
    
    return true;
}

void solution(int length){

    if(is_end) return;
    
    if(length == v.size()){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                cout << MAP[i][j] << " ";
            }
            cout << endl;
        }
        is_end = true;
        return;
    }

    for(int i = 1 ; i < 10 ; i++){
        MAP[v[length].second][v[length].first] = i;
        if(is_possible(v[length].first, v[length].second)){
            solution(length + 1);
            if(is_end) return;
        }
        MAP[v[length].second][v[length].first] = 0;
    }
}

int main() {

    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 0){
                v.push_back(make_pair(j,i));
            }
        }
    }

    solution(0);

	return 0;
}