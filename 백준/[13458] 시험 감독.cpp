#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int main(){
    
    int N ,B ,C;
    vector<int> A;

    cin >> N;

    for(int i = 0 ; i < N ; i++){
        int a;
        cin >> a;

        A.push_back(a);
    }

    cin >> B >> C;

    long long result = 0;

    for(int i = 0 ; i < N ; i++){
        A[i] -= B;
        result++;

        if(A[i] < 0) continue;

        int m = A[i]/C;
        int n = A[i]%C;

        if(n != 0){
            result += (m + 1);
        }else{
            result += m;
        }
    }

    cout << result << endl;

    return 0;
}