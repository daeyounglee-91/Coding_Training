#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
vector<int> v[500];
int MAX = 0;

int compare(int num1, int num2){
    if(num1 > num2){
        return num1;
    }else{
        return num2;
    }
}

int main() {

    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            int num;
            cin >> num;
            if(i == 0){
                v[i].push_back(num);
                MAX = num;
                continue;
            }
            
            int pre;
            if(j-1 >= 0 && j < i){
                pre = compare(v[i-1][j-1], v[i-1][j]);
            }else if(j-1 < 0){
                pre = v[i-1][j];
            }else if(j == i){
                pre = v[i-1][j-1];
            }
            num = num + pre;
            v[i].push_back(num);
            if(MAX < num){
                MAX = num;
            }
        }
    }

    printf("%d", MAX);

    return 0;
}