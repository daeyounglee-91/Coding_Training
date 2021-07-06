#include<iostream>

using namespace std;

int check(int num) {
    int temp = num;
    int sum = num;
    while (temp)
    {
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}

int main() {

    int N;

    cin >> N;

    for (int i = 0; i < 1000000; i++) {
        if (N == check(i)) {
            printf("%d", i);
            return 0;
        }
    }

    printf("0");

    return 0;
}