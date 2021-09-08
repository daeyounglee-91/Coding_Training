#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


class T_POINT
{
private:
    int x;
    int y;
    int z;

public:
    T_POINT(){}
    T_POINT(int t_x, int t_y, int t_z){
        x = t_x;
        y = t_y;
        z = t_z;
    }

    int get_x(){
        return x;
    }
    
    int get_y(){
        return y;
    }
    
    int get_z(){
        return z;
    }
};

int M,N,H;
int MAP[150][150][150] = {0,};
int visit[150][150][150] = {0,};
int dir[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
vector<T_POINT> v;



bool isRange(int x, int y, int z){
    return (x >= 0 && x < M)&&(y >= 0 && y < N)&&(z >= 0 && z < H);
}

void BFS(){
    queue<T_POINT> q;
    for(int i = 0 ; i < v.size() ; i++){
        q.push(v[i]);
        visit[v[i].get_y()][v[i].get_x()][v[i].get_z()] = 1;
    }

    while(!q.empty()){
        int x = q.front().get_x();
        int y = q.front().get_y();
        int z = q.front().get_z();
        q.pop();

        for(int i = 0 ; i < 6 ; i++){
            int t_x = x + dir[i][0];
            int t_y = y + dir[i][1];
            int t_z = z + dir[i][2];

            if(!isRange(t_x,t_y,t_z)) continue;

            if (MAP[t_y][t_x][t_z] == 0 && visit[t_y][t_x][t_z] == 0)
            {
                q.push(T_POINT(t_x,t_y,t_z));
                visit[t_y][t_x][t_z] = visit[y][x][z] + 1;
            }
            
        }
    }
    
}

int Solution(){

    int result = 0;

    BFS();

    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < M ; k++){
                if(MAP[j][k][i] == 0 && visit[j][k][i] == 0) return -1;

                if(MAP[j][k][i] == -1) continue;

                if(result < visit[j][k][i]){
                    result = visit[j][k][i];
                }
            }
        }
    }

    return result-1;
}

int main() {

    cin >> M >> N >> H;

    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < M ; k++){
                cin >> MAP[j][k][i];
                if( MAP[j][k][i] == 1){
                    v.push_back(T_POINT(k,j,i));
                }
            }
        }
    }
    
    cout << Solution();

	return 0;
}