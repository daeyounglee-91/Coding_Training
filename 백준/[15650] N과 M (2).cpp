#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int M,N;
bool num[10] = {false,};
int bin[10] = {0,};

void back_tracking(int length){

    if(length == M){
        for(int i = 0 ; i < M ; i++){
            printf("%d ", bin[i]);
        }
        printf("\n");
        return;
    }

    int temp;
    if(length == 0){
        temp = 1;
    }else{
        temp = bin[length - 1] + 1;
    }

    for(int i = temp ; i <= N ; i++){
        if(num[i]) continue;

        num[i] = true;
        bin[length] = i; 
        back_tracking(length+1);
        num[i] = false;
    }
}

int main() {

    scanf("%d %d", &N, &M);

    back_tracking(0);

	return 0;
}