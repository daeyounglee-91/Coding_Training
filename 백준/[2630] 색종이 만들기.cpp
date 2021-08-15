#includeiostream

using namespace std;

int w = 0, b = 0;
int N;
bool arr[200][200];

void solution(int size, int s_y, int s_x) {

	bool color = arr[s_y][s_x];
	
	for (int i = s_y; i  s_y + size; i++) {
		for (int j = s_x; j  s_x + size; j++) {
			if (color == arr[i][j]) continue;
			solution(size  2, s_y, s_x);
			solution(size  2, s_y + size  2, s_x);
			solution(size  2, s_y, s_x + size 2);
			solution(size  2, s_y + size  2, s_x + size  2);
			return;
		}
	}

	if (color) {
		b++;
	}
	else {
		w++;
	}
}

int main() {

	cin  N;

	for (int i = 0; i  N; i++) {
		for (int j = 0; j  N; j++) {
			cin  arr[i][j];
		}
	}

	solution(N,0,0);

	cout  w  endl  b  endl;

	return 0;
}