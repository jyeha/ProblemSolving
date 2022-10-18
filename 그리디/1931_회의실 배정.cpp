#include <bits/stdc++.h>
using namespace std;

// endTime 기준으로 오름차순
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

		// 만약 현재 회의 종료 시간보다 이후에 회의가 시작한다면
		// 얘가 그 다음으로 제일 빨리 끝나는 회의일테니까
		// 이걸 선택
		if (nextMeeting.first >= curMeeting.second) {
			curMeeting = nextMeeting;
			answer++;
		}
	}

	//while (N > 0) {
	//	// meetings[i][1] 기준으로 오름차순 정렬
	//	sort(meetings.begin(), meetings.end(), cmp);
	//	int endTime = meetings[0].second;

	//	// endTime 보다 이후에 시작하는 회의만 남기기
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