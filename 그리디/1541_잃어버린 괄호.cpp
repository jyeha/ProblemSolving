#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	bool isMinus = false;
	cin >> s;

	int answer = 0;

	string tmp = "";
	for (int i = 0; i < s.length();i++) {
		if (s[i] == '-') {
			isMinus = true;
			answer += stoi(tmp);
			tmp = "-";
		}
		else if (s[i] == '+') {
			answer += stoi(tmp);
			if (isMinus) {
				// 전에 -를 만났다면 다음에 나올 숫자 음수 처리
				tmp = "-";
			}
			else {
				tmp = "";
			}
		}
		else {
			tmp.push_back(s[i]);
		}

		if (i == s.length() - 1) {
			answer += stoi(tmp);
		}
	}
	cout << answer << endl;


	return 0;
}