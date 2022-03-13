#include<iostream>
#include<queue>
#include<vector>

using namespace std;

enum DIR{
    UP = 1,
    DOWN,
    RIGHT,
    LEFT
};

class FISH
{
private:
    int s;
    int d;
    int z;
public:
    FISH(){
        this->s = 0;
        this->d = 0;
        this->z = 0;
    }

    FISH(int s, int d, int z){
        this->s = s;
        this->d = d;
        this->z = z;
    }

    int getS(){return s;}
    int getD(){return d;}
    int getZ(){return z;}

    void setD(int d){
        this->d = d;
    }
};

FISH MAP[200][200][2];
int R,C;
int M;
int result = 0;
int map_z = 0;

bool isRange(int x, int y){
    return (x > 0 && x <= C)&&(y > 0 && y <= R);
}

void input(){
    cin >> R >> C >> M;

    for(int i = 0 ; i < M ; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        FISH f(s,d,z);
        MAP[r][c][map_z] = f;
    }
}

void output(){
    cout << "=================" << endl;
    for(int i = 1 ; i <= R ; i++){
        for(int j = 1 ; j <= C ; j++){
            cout << MAP[i][j][map_z].getZ() << " ";
        }
        cout << endl;
    }
}

void remove_fish(int x, int y){
    FISH f;
    MAP[y][x][map_z] = f;
}

void catch_fish(int idx){
    for(int i = 1 ; i <= R ; i++){
        if(MAP[i][idx][map_z].getZ() != 0){
            result += MAP[i][idx][map_z].getZ();
            remove_fish(idx, i);
            return;
        }
    }
}

DIR reverse(DIR d){
    if(d == UP){
        d = DOWN;
    }else if(d == DOWN){
        d = UP;
    }else if(d == RIGHT){
        d = LEFT;
    }else{
        d = RIGHT;
    }

    return d;
}

void move_fish_one(int x, int y){
    int s = MAP[y][x][map_z].getS();
    DIR d = (DIR)MAP[y][x][map_z].getD();
    int z = (DIR)MAP[y][x][map_z].getZ();
    int t_x = x, t_y = y;

    if (d == UP || d == DOWN) {
        s = s % ((R-1) * 2);
    }else{
        s = s % ((C-1) * 2);
    }

    for(int i = 0 ; i < s; i++){
        if(d == UP){
            if(isRange(t_x,t_y-1)){
                t_y--;
            }else{
                d = reverse(d);
                t_y++;
            }
        }else if(d == DOWN){
            if(isRange(t_x,t_y+1)){
                t_y++;
            }else{
                d = reverse(d);
                t_y--;
            }
        }else if(d == RIGHT){
            if(isRange(t_x+1,t_y)){
                t_x++;
            }else{
                d = reverse(d);
                t_x--;
            }
        }else{
            if(isRange(t_x-1,t_y)){
                t_x--;
            }else{
                d = reverse(d);
                t_x++;
            }
        }
    }

    int temp_z = (map_z+1)%2;
    if(MAP[t_y][t_x][temp_z].getZ() != 0){
        if(MAP[t_y][t_x][temp_z].getZ() < z){
            FISH f(s,d,z);
            MAP[t_y][t_x][temp_z] = f;
        }
    }else{
        FISH f(s,d,z);
        MAP[t_y][t_x][temp_z] = f;
    }
    remove_fish(x,y);
}

void move_fish(){
    for(int i = 1 ; i <= R ; i++){
        for(int j = 1 ; j <= C ; j++){
            if(MAP[i][j][map_z].getZ() == 0) continue;

            move_fish_one(j,i);
        }
    }
    map_z = (map_z+1)%2;
}

int solution(){
    for(int i = 1 ; i <= C ; i++){
        catch_fish(i);
        move_fish();
        //output();
    }
}

int main() {

    input();
    //output();
    solution();
    cout << result;

    return 0;
}