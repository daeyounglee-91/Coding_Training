#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int N;
int dp[30] = {0,};
int T[30] = {0,};
int P[30] = {0,};

int result = 0;

int MAX(int a, int b){
    return a > b ? a : b;
}

void input(){
    cin >> N;
    
    for(int i = 0 ; i  < N ; i++){
        cin >> T[i] >> P[i];
    }
}


int solution(){
    int result = 0;

    for(int i = N - 1 ; i >= 0 ; i--){
        int next = i + T[i];
        if(next > N){
            dp[i] = dp[i+1];
        }else {
            dp[i] = MAX(dp[i + 1],dp[next] + P[i]);
        }
    }

    return dp[0];
}

int main(){

    input();
    cout << solution() << endl;

    return 0;
}