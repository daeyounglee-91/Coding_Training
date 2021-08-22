#include<iostream>

using namespace std;

int arr[1500000] ={0,};
int N;

int main(){
	

	arr[0] = 1;
	arr[1] = 1;
	cin >> N;

	if(N > 1){
		for(int i = 2 ; i <= N ; i++){
			arr[i] = (arr[i-2] + arr[i-1])%15746;
		}
	}
	cout << arr[N];
	return 0;
}