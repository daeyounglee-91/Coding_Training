#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<math.h>
#include<limits.h>

using namespace std;

int N,M,start;
vector<int> v[1500];
bool visit_dfs[1500] = {false,};

void dfs(int num){

    visit_dfs[num] = true;
    cout << num << " ";

    for(int i = 0 ; i < v[num].size() ; i++){
        if(visit_dfs[v[num][i]])continue;

        dfs(v[num][i]);
    }
}

void bfs(int s){
    bool visit[1500] = {false,};
    queue<int> q;

    q.push(s);
    visit[s] = true;

    while(!q.empty()){
        int num = q.front();
        q.pop();
        cout << num << " ";

        for(int i = 0 ; i < v[num].size() ; i++){
            int t = v[num][i];
            
            if(visit[t])continue;

            q.push(t);
            visit[t] = true;
        }
    }
}

int main() {

    cin >> N >> M >> start;

    for(int i = 0 ; i < M ; i++){
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = N ; i >= 0 ; i--){
        sort(v[i].begin(),v[i].end());
    }

    dfs(start);
    cout << endl;
    bfs(start);

	return 0;
}