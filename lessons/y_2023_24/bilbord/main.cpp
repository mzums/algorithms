#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAXN = 1e6+7;
int kmp[MAXN];
vector<int> cnt[128];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str1, str2;
	cin >> str1 >> str2;
	str1 = ' ' + str1;
	int n = str1.size();
	int m = str2.size();
	int k = 0;

	for (int i = 2; i < n; ++i) {
		while (k && str1[k+1] != str1[i]) k = kmp[k];
		if (str1[k+1] == str1[i]) ++k;
		kmp[i] = k;
	}
	string rest = str1.substr(kmp[n-1]+1, n-1);
	for (int i = 1; i < n; ++i) {
		cnt[int(str1[i])].push_back(i);
	}
	for (int i = 0; i < m; ++i)
		if (cnt[int(str2[i])].size() == 0) {
			cout << "INF\n";
			return 0;
		}
	int last = 0, i = 0, res = 0, curr_indx = 0, last_val = 0;
	for (i = 0; i < m; ++i) {
		vector<int> curr = cnt[int(str2[i])];
		curr_indx = upper_bound(curr.begin(), curr.end(), last_val) - curr.begin();
		if (curr[curr_indx] <= last_val) {
			++res;
			break;
		}
		last_val = curr[curr_indx];
	}
	for (int i = 0; i < 128; ++i) {
		cnt[i].clear();
	}
	for (int i = 0; i < rest.size(); ++i) {
		cnt[int(rest[i])].push_back(i);
	}

	last = 0, curr_indx = 0, last_val = -1;
	for (i; i < m; ++i) {
		vector<int> curr = cnt[int(str2[i])];
		curr_indx = upper_bound(curr.begin(), curr.end(), last_val) - curr.begin();
		if (curr[curr_indx] >= rest.size() || curr[curr_indx] <= last_val) {
			++res;
			last_val = -1;
			curr_indx = -1;
			--i;
			continue;
		}
		last_val = curr[curr_indx];
	}
	cout << res << "\n";
}
