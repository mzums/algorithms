#include <iostream>
using namespace std;

string str;
int n;
int arr[7];

bool pal(int start, int finish) {
    while (start != finish && start < finish) {
        if (tolower(str[start]) != tolower(str[finish])) return false;
        start++;
        finish--;
    }
	return true;
}

int solve(int type) {
	int score = 0;
	switch (type) {
		case 1: {
			for (char c : str)
				if (c == ' ') score++;
			break;
		}
		case 2: {
		    for (size_t i = 0; i < str.length(); i++)
                if (isdigit(str[i]) && (!(isdigit(str[i+1])) || i == str.length()-1))
                    score++;
			break;
		}
		case 3: {
			for (size_t i = 0; i < str.length(); i++)
                if (isalpha(str[i]) && (!(isalpha(str[i+1])) || i == str.length()-1))
                    score++;
			break;
		}
		case 4: {
			bool dobre = false;
			for (char c : str) {
				if (c == '.' && dobre) {
					score++;
					dobre = false;
				}
				else if (isalpha(c)) dobre = true;
				else if (c == '.') dobre = 0;
			}
			break;
		}
		case 5: {
			for (size_t i = 0; i < str.length(); i++) {
                while (!isalpha(str[i])) i++;
                int start = i;
                while (isalpha(str[i])) i++;
                int finish = i-1;
                if (pal(start, finish)) score++;
            }
			break;
		}
	}
	return score;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
        cin >> arr[i];
	cin >> ws;
	getline(cin, str);

	for (int i = 0; i < n; i++)
		cout << solve(arr[i]) << " ";
}
