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
		// 끝자리가 1일때만 1의 자리 수를 제거할 수 있음
		else if(b % 10 == 1) {
			b /= 10;
			cnt++;
		}
		// 그 외에는 더 이상 연산이 불가능하므로 -1 출력
		else {
			break;
		}
	}

	cout << "-1";

	return 0;
}