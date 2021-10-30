#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int N, M, H;
int MAP[50][20];
int result = 4;

void input(){
    cin >> N >> M >> H;

    for(int i = 0 ; i < M ; i++){
        int r,c;
        cin >> r >> c;
        MAP[r][c] = 1;
    }
}

bool check(){

    for(int i = 1 ; i <= N ; i++){
        int n = i;
        for(int j = 0 ; j <= H ; j++){
            if(MAP[j][n] != 0){
                n++;
            }else if(n-1 >= 0 && MAP[j][n-1] != 0)
            {
                n--;
            }
        }
        if(n != i) return false;
    }
    return true;
}

void DFS(int y, int x, int count){

    if(count > 3) return;
    if(count >= result) return;
    if(check()){
        result = count;
        return;
    }


    for(int i = y ; i <= H ; i++){
        for(int j = x ; j < N ; j++){
            if(MAP[i][j] != 0 || (j-1 > 0 && MAP[i][j-1] != 0) || MAP[i][j+1] != 0)continue;

            MAP[i][j] = 2;
            DFS(i,j,count+1);
            MAP[i][j] = 0;
        }
        x = 1;
    }
}

int solution(){
   // int result = 0;

    DFS(1,1,0);
    return result == 4 ? -1 : result;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solution() << endl;

    return 0;
}