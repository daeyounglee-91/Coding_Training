#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int N;
int MAP[30][30] = {0,};

int dir[4][2] = {{1,-1},{1,1},{-1,1},{-1,-1}};

bool isRange(int y, int x){
    return (y >= 0 && y < N) && (x >= 0 && x < N);
}

void input(){
    cin >> N;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> MAP[i][j];
        }
    }    
}

int calc(int x, int y, int d1, int d2){
    int result = INT_MAX;
    vector<int> sum(5,0);
    int visit[30][30] = {0,};

    //if(!isRange(y,x)||!isRange(y-d1,x-d1)||!isRange(y+d2,x+d2)||!isRange(y+d1+d2, x+d1-d2)) return INT_MAX;

/*
    1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
    2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
    3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
    4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
*/  
    for(int i = 1 ; i <= N ; i++){  
        for(int j = 1 ; j <= N ; j++){
            if (i < x + d1 && j <= y && !(i >= x && j >= y - (i - x))) {
				sum[0] += MAP[i][j];
                visit[i][j] = 0;
			}
			//2번 선거구
			else if (i <= x + d2 && j > y && !(i >= x && j <= y + (i - x))) {
				sum[1] += MAP[i][j];
                visit[i][j] = 1;
			}
			//3번 선거구
			else if (i >= x + d1 && j < y - d1 + d2 && !(i <= x + d1 + d2 && j >= (y - d1 + d2 - (x + d1 + d2 - i)))) {
				sum[2] += MAP[i][j];
                visit[i][j] = 2;
			}
			//4번 선거구
			else if (i > x + d2 && j >= y - d1 + d2 && !(i <= x + d1 + d2 && j <= (y - d1 + d2 + (x + d1 + d2 - i)))) {
				sum[3] += MAP[i][j];
                visit[i][j] = 3;
			}
			//5번 선거구
			else {
				sum[4] += MAP[i][j];
                visit[i][j] = 4;
			}
        }
    }

// cout << "===============================" << y << ", " << x << ", " << d1 << ", " << d2 << endl;
//     for(int i = 0 ; i < N ; i++){  
//         for(int j = 0 ; j < N ; j++){
//             cout << visit[i][j] << " ";
//         }
//         cout << endl;
//     }

    sort(sum.begin(), sum.end());
    return sum[4] - sum[0];
}

int divlength(int x, int y){
    int result = INT_MAX;
    for(int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++){  
        for(int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++){
            int a = calc(x,y,d1,d2);
            if(result > a){
                result = a;
            }
        }
    }
    return result;
}

int solution(){
    int result = INT_MAX;

	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
            int a = divlength(x,y);
            if(result > a){
                result = a;
            }
        }
    }

    return result;
}

int main(){

    input();
    cout << solution() << endl;

    return 0;
}