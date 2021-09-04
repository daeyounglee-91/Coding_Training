#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N,M;
bool MAP[150][150] = {false,};
int visit[150][150] = {0,};
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool is_Range(int x, int y){
    return (x > 0 && x <= M) && (y > 0 && y <= N);
}

void BFS(int x , int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visit[y][x] = 1;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int t_x = x + dir[i][0];
            int t_y = y + dir[i][1];

            if(!is_Range(t_x,t_y)) continue;

            if(visit[t_y][t_x] == 0 && MAP[t_y][t_x] == 1){
                visit[t_y][t_x] = visit[y][x] + 1;
                q.push(make_pair(t_x,t_y));
            }
        }
    }
    
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

    BFS(1,1);

    // cout << "==============================" << endl;
    // for(int i = 1 ; i <= N ; i++){
    //     for(int j = 1 ; j <= M ; j++){
    //         cout << visit[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << visit[N][M];
    
	return 0;
}