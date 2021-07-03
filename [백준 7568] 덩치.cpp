#include<iostream>
#include<vector>

using namespace std;

int main() {

    int N;
    vector<pair<int, int>> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int w, h;
        cin >> w >> h;
        v.push_back(make_pair(w, h));
    }

    for (int i = 0; i < N; i++) {
        int num = 1;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (v[i].first < v[j].first && v[i].second < v[j].second) {
                num++;
            }
        }
        printf("%d ", num);
    }

    return 0;
}