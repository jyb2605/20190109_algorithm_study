#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int x, y, d, g;
vector<int> v;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	vector<vector<bool>> map(101, vector<bool>(100, false));

	while (N--) {
		
		cin >> x >> y >> d >> g;

		v.push_back(d);
		if(g>=1)
			v.push_back((v.back() + 1)% 4);


		for (int i = 1; i < g; i++) {
			int size = v.size();
			
			vector<int> tmp = v;

			for (int i = 0; i < size / 2; i++)
				tmp.push_back((v[i] + 2) % 4);
			for (int i = size / 2; i < size; i++)
				tmp.push_back(v[i]);

			v = tmp;
		}
		
		if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
			map[x][y] = true;

		for (int i = 0; i < v.size(); i++) {
			switch (v[i]) {
			case 0:
				x++;
				break;
			case 1:
				y--;
				break;
			case 2:
				x--;
				break;
			case 3:
				y++;
				break;
			}

			if(x>=0 && x<=100 && y>=0 && y<=100)
				map[x][y] = true;
		}

		v.clear();
	}

	int cnt = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;

	return 0;
}


