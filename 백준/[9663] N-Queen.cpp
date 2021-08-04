#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

int N;
int MAP[20] = {0,};
int result = 0;

bool is_possible(int row){

    if(row == 0) return true;

    for(int i = 0 ; i < row ; i++){
        if(MAP[i] == MAP[row]) return false;        //같은 열
        
        if(abs(i - row) == abs(MAP[i] - MAP[row])) return false;        //대각선
    }

    return true;
}

void N_Queen(int length){

    if(length == N){
        result++;
        return;
    }

    for(int i = 0 ; i < N ; i++){
        MAP[length] = i;
        if(is_possible(length)){
            N_Queen(length+1);
        }
    }
}

int main() {

    cin >> N;

    N_Queen(0);

    cout << result;

	return 0;
}