#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, K;
int MAP[150000] = {0,};
int visit[150000] = {0,};

int bfs(){
    queue<int> q;
    q.push(N);
    visit[N] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == K){
            return visit[x] - 1;
        }

        int t_x = x-1;
        if(t_x >= 0 && t_x <= 100000 && visit[t_x] == 0){
            visit[t_x] = visit[x]+1;
            q.push(t_x);
        }
        
        t_x = x+1;
        if(t_x >= 0 && t_x <= 100000 && visit[t_x] == 0){
            visit[t_x] = visit[x]+1;
            q.push(t_x);
        }
        
        t_x = x*2;
        if(t_x >= 0 && t_x <= 100000 && visit[t_x] == 0){
            visit[t_x] = visit[x]+1;
            q.push(t_x);
        }
    }
    return -1;
}

int main() {

    cin >> N >> K;

    if(K <= N){
        cout << N-K << endl;
        return 0;
    }

    cout << bfs();

	return 0;
}