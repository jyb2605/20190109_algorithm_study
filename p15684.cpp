#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, H;
int a, b, cnt, minVal;
vector<vector<int>> ladder;

int result(int number) {
	int cur = number;

	for (int i = 1; i < H + 1; i++) {
		if (ladder[cur][i] ==1) 
			cur = cur + 1;
		else if(ladder[cur][i] == -1)
			cur = cur - 1;
	}

	return (cur == number);
}

bool put(int a, int b) {
	cnt++;

	if (cnt > 3) {
		cnt--;
		return false;
	}

	if (ladder[b][a] != 0 || ladder[b+1][a] != 0) {
		cnt--;
		return false;
	}

	ladder[b][a] = 1;
	ladder[b + 1][a] = -1;

	bool flag = true;
	int idx = 1;



	while (flag) {
		if (idx > N)
			break;
		flag *= result(idx);
		idx++;
	}

	if (flag) {
		minVal = min(minVal, cnt);
	}

	for(int i = a; i < H +1; i++) {
		for (int j = 1; j < N; j++) {
			if (i == a && j == 1) {
				j = b + 1;
			}

			if (ladder[j][i] == 0 && ladder[j + 1][i] == 0) {
				put(i, j);
			}
		}
	}

	
	ladder[b][a] = 0;
	ladder[b + 1][a] = 0;

	cnt--;
}

int main() {

	cin >> N >> M >> H;

	ladder = vector<vector<int>>(N + 2, vector<int>(H + 2, 0));

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		ladder[b][a] = 1;
		ladder[b + 1][a] = -1;
	}

	cnt = 0;
	minVal = 5;

	bool flag = true;

	for (int i = 1; i < N + 1; i++) {
		flag *= result(i);
	}

	if (flag) {
		minVal = min(minVal, cnt);
	}

	for (int i = 1; i < H + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			put(i, j);
		}
	}

	if (minVal != 5)
		cout << minVal << endl;
	else
		cout << -1 << endl;

	return 0;
}
