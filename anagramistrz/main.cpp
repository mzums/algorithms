#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
string str1, str2;
int arr1[MAXN], arr2[MAXN];
int score;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> str1 >> str2;
    for (int i = 0; i < str1.length(); i++)
        arr1[str1[i]-'a']++;
    for (int i = 0; i < str2.length(); i++)
        arr2[str2[i]-'a']++;
        
    for (int i = 0; i < 30; i++) {
        arr1[i] = arr2[i] = min(arr1[i], arr2[i]);
        score += arr1[i];
    }
    if (score == 0) {
        cout << "BRAK";
        return 0;
    }
    cout << score << "\n";
    for (int i = 0; i < str1.length(); i++)
        if (arr1[str1[i]-97] > 0) {
            cout << str1[i];
            arr1[str1[i]-97]--;
        }
    cout << "\n" << score << "\n";
    for (int i = 0; i < str2.length(); i++)
        if (arr2[str2[i]-97] > 0) {
            cout << str2[i];
            arr2[str2[i]-97]--;
        }
}