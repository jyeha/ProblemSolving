#include <bits/stdc++.h>
using namespace std;

/*
2022-10-18
Ǯ�� ����

1. �̵�Ƚ���� ������ ��, �Ʒ�, ����, ���������� 4��
2. �̵�Ƚ���� �ִ� 5ȸ
-> 1, 2�� ����� �������� �ߺ������� ���� �̵��ϴ� ����� ���� ����

3. ��, �Ʒ�, ����, ������ ������ ��쿡 ���� ���尡 � ����� ����� ������ ������ �Լ��� �����
4. DFS�� ���� �̵��� ����� ���� ���ߴٸ�, �ش� ����� �����̸� � ����� ���� ������ calculate_maximum�� ���� ����
5. �ִ� ��� �� ����

- �ð��ʰ��� ���ñ� �����ߴµ� N�� �ִ� 20�̾ ������ �ð��ʰ��� ������ �ʾҴ�
- �ٸ������ Ǯ��: move_up, down, left, right�� ť�� ���� ����
- �迭�� ���� ����ϴ� �ͺ��� �ξ� ȿ������ �� �ִٴ� ����

*/

int N, answer = 0;
vector<vector<int>> board;
int dir[4] = { 0, 1, 2, 3 }; // 0: ��, 1: �Ʒ�, 2: ����, 3: ������

auto move_up(vector<vector<int>> b) {
	vector<vector<int>> up(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < N;j++) {
			bool find = false;
			if (b[j][i] != 0) {
				for (int k = j+1; k < N;k++) {
					if (b[k][i] == 0) continue;
					if (b[k][i] != b[j][i])	break;
					
					if(b[j][i] == b[k][i]) {
						v.push_back(2 * b[k][i]);
						find = true;
						j = k;
						break;
					}
				}
				if (!find) {
					v.push_back(b[j][i]);
				}
			}
		}
		
		for (int j = 0; j < v.size(); j++) {
			up[j][i] = v[j];
		}

	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << up[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return up;
}
auto move_down(vector<vector<int>> b) {
	vector<vector<int>> up(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = N-1; j >= 0; j--) {
			bool find = false;
			if (b[j][i] != 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (b[k][i] == 0) continue;
					if (b[k][i] != b[j][i])	break;

					if (b[j][i] == b[k][i]) {
						v.push_back(2 * b[k][i]);
						find = true;
						j = k;
						break;
					}
				}
				if (!find) {
					v.push_back(b[j][i]);
				}
			}
		}

		for (int j = 0; j < v.size(); j++) {
			up[N-1-j][i] = v[j];
		}

	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << up[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return up;
}
auto move_left(vector<vector<int>> b) {
	vector<vector<int>> up(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			bool find = false;
			if (b[i][j] != 0) {
				for (int k = j + 1; k < N; k++) {
					if (b[i][k] == 0) continue;
					if (b[i][k] != b[i][j])	break;

					if (b[i][k] == b[i][j]) {
						v.push_back(2 * b[i][j]);
						find = true;
						j = k;
						break;
					}
				}
				if (!find) {
					v.push_back(b[i][j]);
				}
			}
		}

		for (int j = 0; j < v.size(); j++) {
			up[i][j] = v[j];
		}

	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << up[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return up;
}
auto move_right(vector<vector<int>> b) {
	vector<vector<int>> up(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = N - 1; j >= 0; j--) {
			bool find = false;
			if (b[i][j] != 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (b[i][k] == 0) continue;
					if (b[i][k] != b[i][j])	break;

					if (b[i][k] == b[i][j]) {
						v.push_back(2 * b[i][k]);
						find = true;
						j = k;
						break;
					}
				}
				if (!find) {
					v.push_back(b[i][j]);
				}
			}
		}

		for (int j = 0; j < v.size(); j++) {
			up[i][N - 1 - j] = v[j];
		}

	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << up[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return up;
}

int calculate_maximum(vector<int> movement) {
	int max_val = 0;
	vector<vector<int>> newboard = board;
	for (int i = 0; i < 5; i++) {
		if (movement[i] == 0) newboard = move_up(newboard);
		else if (movement[i] == 1)	newboard = move_down(newboard);
		else if (movement[i] == 2)	newboard = move_left(newboard);
		else if (movement[i] == 3)	newboard = move_right(newboard);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cout << newboard[i][j] << " ";
			if (newboard[i][j] > max_val)	max_val = newboard[i][j];
		}
		// cout << endl;
	}

	return max_val;
}

// �ߺ� ����
void dfs(int cnt, vector<int> movement) {
	if (cnt == 5) {
		// �ִ밪 ���
		int result = calculate_maximum(movement);
		answer = max(answer, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		movement.push_back(dir[i]);
		dfs(cnt+1, movement);
		movement.pop_back();
	}
}


int main() {
	vector<int> movement;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		board.push_back(v);
	}

	//N = 4;
	//vector<vector<int>> t =
	//{
	//	{2, 4, 8, 2},
	//	{2, 4, 0, 0},
	//	{2, 0, 0, 0},
	//	{2, 0, 2, 0}
	//};

	//move_up(t);
	//move_down(t);
	//move_left(t);
	//move_right(t);

	dfs(0, movement);
	cout << answer;

	return 0;
}