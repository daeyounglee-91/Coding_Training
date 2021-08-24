#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int N;

int arr[1500][3] = { 0, };
int dp[1500][3] = { 0, };

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
}

int solution() {
    int result = 0;

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (int i = 1; i < N; i++) {
        dp[i][0] = arr[i][0] + (dp[i - 1][1] < dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2]);
        dp[i][1] = arr[i][1] + (dp[i - 1][0] < dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2]);
        dp[i][2] = arr[i][2] + (dp[i - 1][0] < dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1]);
    }

    //return result;
    return (dp[N - 1][0] < dp[N - 1][1]) ? (dp[N - 1][0] < dp[N - 1][2]) ? dp[N - 1][0] : dp[N - 1][2] : (dp[N - 1][1] < dp[N - 1][2]) ? dp[N - 1][1] : dp[N - 1][2];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solution() << endl;

    return 0;
}