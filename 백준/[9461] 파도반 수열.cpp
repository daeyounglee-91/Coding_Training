#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {

    int TC;
    long long int arr[200];

    scanf("%d",&TC);

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;

    for(int i = 6 ; i < 101 ; i++){
        arr[i] = arr[i-1] + arr[i-5];
    }

    for(int i = 0 ; i < TC ; i++){
        int N;
        scanf("%d",&N);
        printf("%lld\n",arr[N]);
    }

    return 0;
}