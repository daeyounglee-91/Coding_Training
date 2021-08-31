#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<math.h>
#include<limits.h>

using namespace std;

int N,M;
vector<int> v[150];
bool visit[150] = {false,};
int c = 0;

void dfs(int num){
    visit[num] = true;

    for(int i = 0 ; i < v[num].size() ; i++){
        if(visit[v[num][i]]) continue;

        c++;
        dfs(v[num][i]);
    }
}

int main() {

    cin >> N;
    cin >> M;

    for(int i = 0 ; i < M ; i++){
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    cout << c;
	return 0;
}