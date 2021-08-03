#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int M,N;
int bin[10] = {0,};

void back_tracking(int length){

    if(length == M){
        for(int i = 0 ; i < M ; i++){
            printf("%d ", bin[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1 ; i <= N ; i++){
        bin[length] = i; 
        back_tracking(length+1);
    }
}

int main() {

    scanf("%d %d", &N, &M);

    back_tracking(0);

	return 0;
}