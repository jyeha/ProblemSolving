#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, cnt=0;
	cin >> a >> b;

	while (b > 0) {
		if (a == b) {
			cout << cnt+1;
			return 0;
		}

		if (b % 2 == 0) {
			b /= 2;
			cnt++;
		}
		// ���ڸ��� 1�϶��� 1�� �ڸ� ���� ������ �� ����
		else if(b % 10 == 1) {
			b /= 10;
			cnt++;
		}
		// �� �ܿ��� �� �̻� ������ �Ұ����ϹǷ� -1 ���
		else {
			break;
		}
	}

	cout << "-1";

	return 0;
}