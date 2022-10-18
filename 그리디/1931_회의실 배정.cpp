#include <bits/stdc++.h>
using namespace std;

// endTime �������� ��������
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)	return a.first < b.first;
	else
	{
		return a.second < b.second;
	}
}

int N;
int main() {
	cin >> N;

	int answer = 1, idx = 0;

	vector<pair<int, int>> meetings;
	
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		meetings.push_back(make_pair(start, end));
	}

	sort(meetings.begin(), meetings.end(), cmp);
	pair<int, int> curMeeting = meetings[0];
	for (int i = 1; i < N; i++) {
		pair<int, int> nextMeeting = meetings[i];

		// ���� ���� ȸ�� ���� �ð����� ���Ŀ� ȸ�ǰ� �����Ѵٸ�
		// �갡 �� �������� ���� ���� ������ ȸ�����״ϱ�
		// �̰� ����
		if (nextMeeting.first >= curMeeting.second) {
			curMeeting = nextMeeting;
			answer++;
		}
	}

	//while (N > 0) {
	//	// meetings[i][1] �������� �������� ����
	//	sort(meetings.begin(), meetings.end(), cmp);
	//	int endTime = meetings[0].second;

	//	// endTime ���� ���Ŀ� �����ϴ� ȸ�Ǹ� �����
	//	sort(meetings.begin(), meetings.end());
	//	int idx = lower_bound(meetings.begin(), meetings.end(), make_pair(endTime, 0)) - meetings.begin();

	//	for (int i = 0; i < idx; i++) {
	//		meetings.erase(meetings.begin());
	//	}

	//	//for (int i = 0; i < meetings.size(); i++) {
	//	//	cout << meetings[i].first << " " << meetings[i].second << endl;
	//	//}

	//	//cout << endl;

	//	N -= idx;
	//	cout << N << endl;
	//	answer++;
	//}


	return 0;

}