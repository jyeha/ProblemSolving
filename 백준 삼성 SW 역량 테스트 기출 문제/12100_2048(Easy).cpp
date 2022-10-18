#include <bits/stdc++.h>
using namespace std;

/*
2022-10-18
풀이 과정

1. 이동횟수의 종류는 위, 아래, 왼쪽, 오른쪽으로 4개
2. 이동횟수는 최대 5회
-> 1, 2의 사실을 바탕으로 중복순열을 통해 이동하는 경우의 수를 구함

3. 위, 아래, 왼쪽, 오른쪽 각각의 경우에 대해 보드가 어떤 결과를 출력할 것인지 나누어 함수를 만들기
4. DFS를 통해 이동의 경우의 수를 구했다면, 해당 경우대로 움직이면 어떤 결과가 나올 것인지 calculate_maximum을 통해 구현
5. 최댓값 계산 및 갱신

- 시간초과가 나올까 걱정했는데 N이 최대 20이어서 다행히 시간초과가 나지는 않았다
- 다른사람의 풀이: move_up, down, left, right를 큐를 통해 구현
- 배열을 통해 계산하는 것보다 훨씬 효율적일 수 있다는 생각

*/

int N, answer = 0;
vector<vector<int>> board;
int dir[4] = { 0, 1, 2, 3 }; // 0: 위, 1: 아래, 2: 왼쪽, 3: 오른쪽

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

// 중복 순열
void dfs(int cnt, vector<int> movement) {
	if (cnt == 5) {
		// 최대값 계산
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