#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int r,c,k;
int arr[150][150];
int H = 3;
int W = 3;
int tempH = 3;
int tempW = 3;

const int MAX = 100;

void input(){

    cin >> r >> c >> k;

    for(int i = 1 ; i < 4 ; i++){
        for(int j = 1 ; j < 4 ; j++){
            cin >> arr[i][j];
        }
    }
}

void init(){

}

bool compare(pair<int,int>p1 ,pair<int,int> p2){
    if(p1.second == p2.second) return p1.first > p2.first;

    return p1.second > p2.second;
}

void sortH(int idx){
    int count[150] = {0,};
    vector<pair<int,int>> v;

    for(int i = 1 ; i < H+1 ; i++){
        count[arr[i][idx]]++;
    }

    for(int i = 1 ; i <= 100 ; i++){
        if(count[i] == 0) continue;

        v.push_back(make_pair(i,count[i]));
    }

    sort(v.begin(), v.end(), compare);

    int size =  v.size()*2;

    if(size > 100){
        size = 100;
    }

    if(tempH < size){
        tempH = size;
    }
    
    for(int i = 1 ; i < size+1 ; i++){
        arr[i++][idx] = v.back().first;
        arr[i][idx] = v.back().second;
        v.pop_back();
    }
    
    if(size < H){
        for(int i = size + 1 ; i <= H ; i++){
            arr[i][idx] = 0;
        }
    }
}

void sortW(int idx){
    int count[150] = {0,};
    vector<pair<int,int>> v;

    for(int i = 1 ; i < W+1 ; i++){
        count[arr[idx][i]]++;
    }

    for(int i = 1 ; i <= 100 ; i++){
        if(count[i] == 0) continue;

        v.push_back(make_pair(i,count[i]));
    }

    sort(v.begin(), v.end(), compare);

    int size =  v.size()*2;

    if(size > 100){
        size = 100;
    }

    if(tempW < size){
        tempW = size;
    }

    for(int i = 1 ; i < size+1 ; i++){
        arr[idx][i++] = v.back().first;
        arr[idx][i] = v.back().second;
        v.pop_back();
    }

    if(size < W){
        for(int i = size + 1 ; i <= W ; i++){
            arr[idx][i] = 0;
        }
    }
}

void sortArrH(){
    for(int i = 1 ; i < W+1 ; i++){
        sortH(i);
    }
    H = tempH;
}

void sortArrW(){
    for(int i = 1 ; i < H+1 ; i++){
        sortW(i);
    }
    W = tempW;
}

void printArr(){

    cout << "print =========================" << endl;
      
    for(int i = 1 ; i < 20 ; i++){
        for(int j = 1 ; j < 20 ; j++){
            cout << arr[i][j] << " ";
        }
    cout << endl;
    }
}

int solution(){
    
    int result = 0;

    while (arr[r][c] != k)
    {
        tempH = 0;
        tempW = 0;
        if(W > H){
            sortArrH();
        }else{
            sortArrW();
        }
        // printArr();
        result++;

        if(result > 100) return -1;
    }
    
    return result;
}

int main(){
    
    input();
    cout << solution() << endl;
    
    return 0;
}
