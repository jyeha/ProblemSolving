/* 문제 종류 : 시뮬레이션 */
/* 14719번 빗물 */
/* 2차원 세계에 블록이 쌓여있다. 비가 오면 블록 사이에 빗물이 고인다. */
/* 비는 충분히 많이 온다. 고이는 빗물의 총량은 얼마일까? */

/* 입력 */
/* 첫 번째 줄에는 2차원 세계의 세로 길이 H과 2차원 세계의 가로 길이 W가 주어진다. (1 ≤ H, W ≤ 500)
두 번째 줄에는 블록이 쌓인 높이를 의미하는 0이상 H이하의 정수가 2차원 세계의 맨 왼쪽 위치부터 차례대로 W개 주어진다.
따라서 블록 내부의 빈 공간이 생길 수 없다. 또 2차원 세계의 바닥은 항상 막혀있다고 가정하여도 좋다. */

/* 출력 */
/* 2차원 세계에서는 한 칸의 용량은 1이다. 고이는 빗물의 총량을 출력하여라.
빗물이 전혀 고이지 않을 경우 0을 출력하여라.*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// 다른 사람의 풀이
// 입력 받은 것에서 자신을 기준으로 왼쪽에서 제일 큰값과 오른쪽에서 제일 큰값 중 작은 값에서 자신의 값을 빼면 자신 위치에서 받을 수 있는 빗물의 양이 됨
// min(max(left), max(right)) - 자신

int main() {
	int W, H;
	cin >> H >> W;

	int sum = 0;

	/* 나의 풀이
	vector<vector<int>> blocks(H, vector<int>(W, 0));

	for (int i = 0; i < W; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			blocks[H-1-j][i] = 1;
		}
	}

	for (int i = 0; i < H; i++) {
		int cnt = 0;
		bool flag = false;
		for (int j = 0; j < W; j++) {
			if (blocks[i][j] == 0) {
				if(flag == true)
					cnt++;
			}
			else {
				flag = true;
				sum += cnt;
				cnt = 0;
			}
		}
	}
	*/

	vector<int> blocks(W);

	for (int i = 0; i < W; i++) {
		cin >> blocks[i];
	}

	for (int i = 0; i < W; i++) {
		int left_max = 0, right_max = 0;
		for (int j = 0; j < i;j++)	left_max = max(left_max, blocks[j]);
		for (int j = i + 1; j < W; j++)	right_max = max(right_max, blocks[j]);

		int rain = min(left_max, right_max) - blocks[i];

		if(rain > 0)		sum += rain;
	}

	cout << sum;

}

