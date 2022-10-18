/* ���� ���� : �ùķ��̼� */
/* 14719�� ���� */
/* 2���� ���迡 ����� �׿��ִ�. �� ���� ��� ���̿� ������ ���δ�. */
/* ��� ����� ���� �´�. ���̴� ������ �ѷ��� ���ϱ�? */

/* �Է� */
/* ù ��° �ٿ��� 2���� ������ ���� ���� H�� 2���� ������ ���� ���� W�� �־�����. (1 �� H, W �� 500)
�� ��° �ٿ��� ����� ���� ���̸� �ǹ��ϴ� 0�̻� H������ ������ 2���� ������ �� ���� ��ġ���� ���ʴ�� W�� �־�����.
���� ��� ������ �� ������ ���� �� ����. �� 2���� ������ �ٴ��� �׻� �����ִٰ� �����Ͽ��� ����. */

/* ��� */
/* 2���� ���迡���� �� ĭ�� �뷮�� 1�̴�. ���̴� ������ �ѷ��� ����Ͽ���.
������ ���� ������ ���� ��� 0�� ����Ͽ���.*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// �ٸ� ����� Ǯ��
// �Է� ���� �Ϳ��� �ڽ��� �������� ���ʿ��� ���� ū���� �����ʿ��� ���� ū�� �� ���� ������ �ڽ��� ���� ���� �ڽ� ��ġ���� ���� �� �ִ� ������ ���� ��
// min(max(left), max(right)) - �ڽ�

int main() {
	int W, H;
	cin >> H >> W;

	int sum = 0;

	/* ���� Ǯ��
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

