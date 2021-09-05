#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N,M;
int MAP[1500][1500] = {false,};
int visit[1500][1500] = {0,};
vector<pair<int,int>> v;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool is_Range(int x, int y){
    return (x >= 0 && x < M) && (y >= 0 && y < N);
}

void BFS(){
    int x, y;
    queue<pair<int,int>> q;
    for(int i = 0 ; i < v.size() ; i++){
        x = v[i].first;
        y = v[i].second;

        q.push(make_pair(x,y));
        visit[y][x] = 1;
    }

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int t_x = x + dir[i][0];
            int t_y = y + dir[i][1];

            if(!is_Range(t_x,t_y)) continue;

            if(visit[t_y][t_x] == 0 && MAP[t_y][t_x] == 0){
                visit[t_y][t_x] = visit[y][x] + 1;
                q.push(make_pair(t_x,t_y));
            }
        }
    }
    
}

int solution(){

    int result = 0;
    BFS();

    // cout << "==========================" << endl;
    //    for(int i = 0 ; i < N ; i++){
    //     for(int j = 0 ; j < M ; j++){
    //         cout << visit[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(MAP[i][j] == 0 && visit[i][j] == 0) return -1;

            if(visit[i][j] > result){
                result = visit[i][j];
            }
        }
    }

    return result - 1;
}

int main() {

    cin >> M >> N;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 1){
                v.push_back(make_pair(j,i));
            }
        }
    }

//  cout << "==========================" << endl;
//        for(int i = 0 ; i < N ; i++){
//         for(int j = 0 ; j < M ; j++){
//             cout << MAP[i][j] << " ";
//         }
//         cout << endl;
//     }

    cout << solution();
    
	return 0;
}