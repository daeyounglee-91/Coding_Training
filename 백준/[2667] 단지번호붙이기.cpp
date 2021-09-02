#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;
bool MAP[50][50];
bool visit[50][50] = {false,};
int b_count = 0;
vector<int> v;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool isRange(int x, int y){
    return (x >= 0 && N > x)&&(y >= 0 && N > y);
}

int bfs(int x, int y){
    int count = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visit[y][x] = true;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int t_x = x + dir[i][0];
            int t_y = y + dir[i][1];

            if(!isRange(t_x,t_y)) continue;

            if(visit[t_y][t_x] == false && MAP[t_y][t_x] == 1){
                visit[t_y][t_x] = true;
                count++;
                q.push(make_pair(t_x,t_y));
            }
        }
    }
    return count;
}

int main() {

    cin >> N;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            char c;
            cin >> c;
            MAP[i][j] = c - '0'; 
            //cin >> MAP[i][j];
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(MAP[i][j] == 1 && visit[i][j] == 0){
                b_count++;
                v.push_back(bfs(j,i));
            }
        }
    }

    sort(v.begin(),v.end());

    cout << b_count << endl;
    for(int i = 0 ; i < v.size(); i++){
        cout << v[i] << endl;
    }

    
	return 0;
}