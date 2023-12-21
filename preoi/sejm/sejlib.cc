#include <bits/stdc++.h>
using namespace std;

inline int rand_range(int a, int b) { return (rand() % (b - a + 1)) + a; }

int libN;
vector<int> libKlamcy;
vector<int> libPrawdziweDlugosci;
int libIle;
int init(){
    cin>>libN;
    libKlamcy.resize(libN+1);
    libPrawdziweDlugosci.resize(libN+1);
    for (int i = 1; i <= libN; i++) cin>>libKlamcy[i];
    for (int i = 1; i <= libN; i++) cin>>libPrawdziweDlugosci[i];
    return libN;
}
int wywiad(int a, int b){
    libIle++;
    if (libKlamcy[a] == 0){
        return libPrawdziweDlugosci[b];
    }else{
        int x = rand_range(1,1000000000);
        while (x == libPrawdziweDlugosci[b]) x = rand_range(1,1000000000);
        libPrawdziweDlugosci[a] += rand_range(1,100);
        return x;
    }
}
void odpowiedz(vector<int> arr){
    vector<int> klamcy;
    for (int i = 1; i <= libN; i++) if (libKlamcy[i]) klamcy.push_back(i);
    if (klamcy.size() != arr.size()){
        cout<<"ZŁA ODPOWIEDŹ\n";
        return;
    }
    for (int i = 0; i < (int)arr.size(); i++){
        if (klamcy[i] != arr[i]){
            cout<<"ZŁA ODPOWIEDŹ\n";
            return;
        }
    }
    cout<<"OK\n";
    cout<<"ilość zapytań: "<<libIle<<"\n";
}