#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, minValue;
vector<vector<int>> map;
vector<pair<int, int>> camPos;

int idx;
//→ ←  ↑ ↓
void func() {

	if (idx >= camPos.size()) {
		int cnt = 0;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < M + 1; j++) {
				if (map[i][j] == 0)
					cnt++;
			}
		}
		minValue = min(minValue, cnt);
		return;
	}

	int x = camPos[idx].first,
		y = camPos[idx].second;
	int type = map[x][y];
	int tmpX, tmpY, _tmpX, _tmpY;

	

	idx++;
	switch (type) {
	case 1: {
		// type 1

		//		↑
		_tmpX = x - 1;
		while (map[_tmpX][y] != 6) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] -= type;
			_tmpX--;
		}

		func();

		while (_tmpX != x) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] += type;
			_tmpX++;
		}

		//		→
		tmpY = y + 1;
		while (map[x][tmpY] != 6) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] -= type;
			tmpY++;
		}

		func();

		while (tmpY != y) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] += type;
			tmpY--;
		}

		//		↓
		tmpX = x + 1;
		while (map[tmpX][y] != 6) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] -= type;
			tmpX++;
		}

		func();

		while (tmpX != x) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] += type;
			tmpX--;
		}


		//		←
		_tmpY = y - 1;
		while (map[x][_tmpY] != 6) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] -= type;
			_tmpY--;
		}

		func();

		while (_tmpY != y) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] += type;
			_tmpY++;
		}
		break;
	}
	case 2: {
		// type 2
		//		↑↓
		tmpX = x + 1;
		_tmpX = x - 1;
		while (map[tmpX][y] != 6) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] -= type;
			tmpX++;
		}
		while (map[_tmpX][y] != 6) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] -= type;
			_tmpX--;
		}

		func();
	
		while (tmpX != x) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] += type;
			tmpX--;
		}
		while (_tmpX != x) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] += type;
			_tmpX++;
		}

		//		←→
		tmpY = y + 1;
		_tmpY = y - 1;

		while (map[x][tmpY] != 6) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] -= type;
			tmpY++;
		}
		while (map[x][_tmpY] != 6) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] -= type;
			_tmpY--;
		}

		func();

		while (tmpY != y) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] += type;
			tmpY--;
		}
		while (_tmpY != y) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] += type;
			_tmpY++;
		}

		break;
	}
	case 3: {
		// type 3

		//		↑→
		_tmpX = x - 1;
		tmpY = y + 1;
		while (map[_tmpX][y] != 6) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] -= type;
			_tmpX--;
		}
		while (map[x][tmpY] != 6) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] -= type;
			tmpY++;
		}

		func();

		while (_tmpX != x) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] += type;
			_tmpX++;
		}
		while (tmpY != y) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] += type;
			tmpY--;
		}

		//		↓→
		tmpX = x + 1;
		tmpY = y + 1;
		while (map[tmpX][y] != 6) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] -= type;
			tmpX++;
		}
		while (map[x][tmpY] != 6) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] -= type;
			tmpY++;
		}

		func();

		while (tmpX != x) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] += type;
			tmpX--;
		}
		while (tmpY != y) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] += type;
			tmpY--;
		}

		//		←↓
		tmpX = x + 1;
		_tmpY = y - 1;
		while (map[tmpX][y] != 6) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] -= type;
			tmpX++;
		}
		while (map[x][_tmpY] != 6) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] -= type;
			_tmpY--;
		}

		func();

		while (tmpX != x) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] += type;
			tmpX--;
		}
		while (_tmpY != y) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] += type;
			_tmpY++;
		}

		//		←↑
		_tmpX = x - 1;
		_tmpY = y - 1;
		while (map[_tmpX][y] != 6) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] -= type;
			_tmpX--;
		}
		while (map[x][_tmpY] != 6) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] -= type;
			_tmpY--;
		}

		func();

		while (_tmpX != x) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] += type;
			_tmpX++;
		}
		while (_tmpY != y) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] += type;
			_tmpY++;
		}

		break;
	}
	case 4: {
		//	type 4
		
		//		←↑→

		_tmpX = x - 1;
		tmpY = y + 1;
		_tmpY = y - 1;


		while (map[_tmpX][y] != 6) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] -= type;
			_tmpX--;
		}
		while (map[x][tmpY] != 6) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] -= type;
			tmpY++;
		}
		while (map[x][_tmpY] != 6) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] -= type;
			_tmpY--;
		}

		func();

		while (_tmpX != x) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] += type;
			_tmpX++;
		}
		while (tmpY != y) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] += type;
			tmpY--;
		}
		while (_tmpY != y) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] += type;
			_tmpY++;
		}

		//		↑→↓

		tmpX = x + 1;
		_tmpX = x - 1;
		tmpY = y + 1;

		while (map[tmpX][y] != 6) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] -= type;
			tmpX++;
		}
		while (map[_tmpX][y] != 6) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] -= type;
			_tmpX--;
		}
		while (map[x][tmpY] != 6) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] -= type;
			tmpY++;
		}

		func();

		while (tmpX != x) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] += type;
			tmpX--;
		}
		while (_tmpX != x) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] += type;
			_tmpX++;
		}
		while (tmpY != y) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] += type;
			tmpY--;
		}

		//		←↓→

		tmpX = x + 1;
		tmpY = y + 1;
		_tmpY = y - 1;

		while (map[tmpX][y] != 6) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] -= type;
			tmpX++;
		}
		while (map[x][tmpY] != 6) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] -= type;
			tmpY++;
		}
		while (map[x][_tmpY] != 6) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] -= type;
			_tmpY--;
		}

		func();

		while (tmpX != x) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] += type;
			tmpX--;
		}
		while (tmpY != y) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] += type;
			tmpY--;
		}
		while (_tmpY != y) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] += type;
			_tmpY++;
		}

		//		↑↓←

		tmpX = x + 1;
		_tmpX = x - 1;
		_tmpY = y - 1;

		while (map[tmpX][y] != 6) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] -= type;
			tmpX++;
		}
		while (map[_tmpX][y] != 6) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] -= type;
			_tmpX--;
		}
		while (map[x][_tmpY] != 6) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] -= type;
			_tmpY--;
		}

		func();

		while (tmpX != x) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] += type;
			tmpX--;
		}
		while (_tmpX != x) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] += type;
			_tmpX++;
		}
		while (_tmpY != y) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] += type;
			_tmpY++;
		}

		break;
	}
	case 5: {
		//	type 5
		//		↑→↓←

		tmpX = x + 1;
		_tmpX = x - 1;
		tmpY = y + 1;
		_tmpY = y - 1;

		while (map[tmpX][y] != 6) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] -= type;
			tmpX++;
		}
		while (map[_tmpX][y] != 6) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] -= type;
			_tmpX--;
		}
		while (map[x][tmpY] != 6) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] -= type;
			tmpY++;
		}
		while (map[x][_tmpY] != 6) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] -= type;
			_tmpY--;
		}

		func();

		while (tmpX != x) {
			if (map[tmpX][y] <= 0)
				map[tmpX][y] += type;
			tmpX--;
		}
		while (_tmpX != x) {
			if (map[_tmpX][y] <= 0)
				map[_tmpX][y] += type;
			_tmpX++;
		}
		while (tmpY != y) {
			if (map[x][tmpY] <= 0)
				map[x][tmpY] += type;
			tmpY--;
		}
		while (_tmpY != y) {
			if (map[x][_tmpY] <= 0)
				map[x][_tmpY] += type;
			_tmpY++;
		}

		break;
	}
	}

	idx--;
	return;
}

int main() {

	cin >> N >> M;

	map = vector<vector<int>>(N + 2, vector<int>(M + 2, 6));

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
				camPos.push_back(make_pair(i, j));
		}
	}

	idx = 0;
	minValue = 1e9;

	func();

	cout << minValue << endl;

	return 0;
}


