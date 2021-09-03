#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int M,N,K;
bool MAP[100][100] = {false,};
bool visit[100][100] = {false,};
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool isRange(int x, int y){
    return(x >= 0 && x < M) && (y >= 0 && y < N);
}

void input(){
    cin >> M >> N >> K;

    for(int i = 0 ; i < K ; i++){
        int x,y;
        cin >> x >> y;
        MAP[y][x] = true;
    }
}

void dfs(int x, int y){

    visit[y][x] = true;

    for(int i = 0 ; i < 4 ; i++){
        int t_x = x + dir[i][0];
        int t_y = y + dir[i][1];

        if(MAP[t_y][t_x] && !visit[t_y][t_x]){
            dfs(t_x,t_y);
        }
    }
}

int solution(){

    int count = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(MAP[i][j] && !visit[i][j]){
                count++;
                dfs(j,i);
            }
        }
    }

    return count;
}

void init(){

    for(int i = 0 ; i < 50 ; i++){
        for(int j = 0 ; j < 50 ; j++){
            MAP[i][j] = false;
            visit[i][j] = false;
        }
    }
}

int main() {

    int tc;
    cin >> tc;

    for(int i = 0 ; i < tc ; i++){
        input();
        cout << solution() << endl;

        // for(int i = 0 ; i < N ; i++){
        //     for(int j = 0 ; j < M ; j++){
        //         cout << MAP[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        // cout << "===================" << endl;

        // for(int i = 0 ; i < N ; i++){
        //     for(int j = 0 ; j < M ; j++){
        //         cout << visit[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        init();
    }
    
	return 0;
}