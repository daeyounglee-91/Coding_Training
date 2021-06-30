#include<iostream>
#include<vector>

using namespace std;

int N, M;
int val = 0;
vector<int> card;
int bin[5];
bool use_card[150000] = { false, };

void tobin(int length) {
    if (length >= 3) {
        int t_val = bin[0] + bin[1] + bin[2];
        // for(int i = 0 ; i < 3 ; i++){
        //     cout << bin[i] << " ";
        // }
        // cout << endl;

        if (t_val > val && t_val <= M) {
            val = t_val;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!use_card[card[i]]) {
            bin[length] = card[i];
            use_card[card[i]] = true;
            tobin(length + 1);
            use_card[card[i]] = false;
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        card.push_back(num);
    }

    tobin(0);

    cout << val;

    return 0;
}