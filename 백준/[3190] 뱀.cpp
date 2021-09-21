#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int N,K,L;
int MAP[200][200] = {0,};
int visit[200][200] = {0,};
queue<pair<int,char> > q;

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool isRange(int y, int x){
    return (y >= 0 && y < N) && (x >= 0 && x < N);
}

void input(){
    cin >> N >> K;
    for(int i = 0 ; i < K ; i++){
        int y,x;
        cin >> y >> x;
        MAP[y-1][x-1] = 1;
    }

    cin >> L;

    for(int i = 0 ; i < L ; i++){
        int n;
        char c;
        cin >> n >> c ;
        q.push(make_pair(n,c));
    }
}

void print(){
    cout << "====================================" << endl;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}

int solution(){
    int result = 0;
    deque<pair<int,int> > snake;
    int d = 0;

    snake.push_front(make_pair(0,0));
    MAP[0][0] = 2;

    while(!snake.empty()){
        result ++;

        int y = snake.front().first + dir[d][0];
        int x = snake.front().second + dir[d][1];

        if(!isRange(y,x) || MAP[y][x] == 2) break;

        if(MAP[y][x] == 0){
            MAP[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }

        MAP[y][x] = 2;
        snake.push_front(make_pair(y,x));

        if(!q.empty() && q.front().first == result){
            if(q.front().second == 'D'){
                d = (d+1+4)%4;
            }else if(q.front().second == 'L'){
                d = (d-1+4)%4;
            }
            q.pop();
        }

        //print();
    }

    return result;
}

int main(){

    input();
    cout << solution() << endl;

    return 0;
}