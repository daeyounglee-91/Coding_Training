#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M;
bool MAP[1500][1500] = {0,};
int visit[1500][1500][2] = {0,};
int result = -1;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool is_Range(int x, int y){
    return (x > 0 && x <= M) && (y > 0 && y <= N);
}

int BFS(){

    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(1,1),0));
    visit[1][1][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int block = q.front().second;
        q.pop();

        if(x == M && y == N){
            return visit[y][x][block];
        }
        
        for(int i = 0 ; i < 4 ; i++){
            int t_x = x + dir[i][0];
            int t_y = y + dir[i][1];

            if(!is_Range(t_x,t_y)) continue;

            if(block == 0 && MAP[t_y][t_x] == 1){
                visit[t_y][t_x][block+1] = visit[y][x][block] + 1;
                q.push(make_pair(make_pair(t_x,t_y),block+1));

            }
            if(visit[t_y][t_x][block] == 0 && MAP[t_y][t_x] == 0){
                visit[t_y][t_x][block] = visit[y][x][block] + 1;
                q.push(make_pair(make_pair(t_x,t_y),block));
            }
        }
    }
 
    return -1;
}

int main() {

    cin >> N >> M;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            char c;
            cin >> c;
            MAP[i][j] = c - '0';
        }
    }

    cout << BFS();

	return 0;
}