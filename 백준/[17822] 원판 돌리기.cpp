#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

struct ROTATE
{
    int x,d,k;
};

int N, M, T;
deque<int> MAP[100];
vector<ROTATE> rotates;
int sum = 0;
int amount = 0;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool isRange(int y, int x){
    return (y >= 1 && y <= N) && (x >= 0 && x < M);
}

void print(){
    cout << "============================================" << endl;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j < MAP[i].size() ; j++){
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}

void input(){
   cin >> N >> M >> T;

   for(int i = 1 ; i <= N ; i++){
       for(int j = 1 ; j <= M ; j++){
           int num;
           cin >> num;
           MAP[i].push_back(num);

           sum += num;
           amount++;
       }
   }

   for(int i = 0 ; i < T ; i++){
       ROTATE r;
       cin >> r.x >> r.d >> r.k;
       rotates.push_back(r);
   }
}

void rotateCircle(int d, int k, int idx){

    for(int i = 0 ; i < k ; i++){
        if(d == 0){
            int num = MAP[idx].back();
            MAP[idx].push_front(num);
            MAP[idx].pop_back();
        }else{
            int num = MAP[idx].front();
            MAP[idx].push_back(num);
            MAP[idx].pop_front();
        }
    }
}

void rotateMAP(ROTATE r){

    for (int i = r.x; i <= N; i+=r.x)
    {
        rotateCircle(r.d, r.k, i);
    }
}

bool changeMAP(int y, int x, int v){

    bool result = false;

    queue<pair<int,int> > q;
    q.push(make_pair(y,x));

    while (!q.empty())
    {
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = ty + dir[i][0];
            int nx = tx + dir[i][1];

            if(nx < 0){
                nx = M-1;
            }

            if(nx >= M){
                nx = 0;
            }

            if(!isRange(ny,nx)) continue;

            if(MAP[ny][nx] == v){
                amount--;
                sum -= v;

                if(MAP[ty][tx] != 0){
                    amount--;
                    sum -= v;
                }

                MAP[ny][nx] = 0;
                MAP[ty][tx] = 0;
                q.push(make_pair(ny,nx));
                result = true;
            }
        }
    }
    return result;
}

void checkMAP(){
    
    bool result = false;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j < MAP[i].size() ; j++){
            if(MAP[i][j] != 0){
                bool temp = changeMAP(i,j,MAP[i][j]);

                if(!result){
                    result = temp;
                }
            }
        }
    }

    if(!result){
       // float avr = (float)sum/amount;
        // printf("%d/%d %f\n", sum,amount,avr);

        int n = 0, c = 0;
        for(int i = 1 ; i <= N ; i++){
            for(int j = 0 ; j < MAP[i].size() ; j++){
                if(MAP[i][j] == 0)continue;

                n += MAP[i][j];
                c++;
            }
        }

        float avr = (float)n/c;

        for(int i = 1 ; i <= N ; i++){
            for(int j = 0 ; j < MAP[i].size() ; j++){
                if(MAP[i][j] == 0)continue;

                if(MAP[i][j] > avr){
                    MAP[i][j]--;
                }else if(MAP[i][j] < avr){
                    MAP[i][j]++;
                }
            }
        }
    }
}

int sumMAP(){
    int result = 0;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j < MAP[i].size() ; j++){
            result += MAP[i][j];
        }
    }

    return result;
}

int solution(){
    int result = 0;

    for(int i = 0 ; i < T ; i++){
        rotateMAP(rotates[i]);
      //  print();
        checkMAP();
      //  print();
    }

    result = sumMAP();

    return result;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solution() << endl;

    return 0;
}