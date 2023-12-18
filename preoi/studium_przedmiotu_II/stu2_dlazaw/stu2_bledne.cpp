/*
 Przykładowe (błędne) rozwiązanie zadania Studium przedmiotu II
*/

#include <bits/stdc++.h>
#include "stu2lib.h"
using namespace std;
vector<int> tablica;
void inicjuj(vector<int> arr){
    tablica = arr;
}
void zamien(int a, int b){
    tablica[a-1] = tablica[b-1];
    tablica[b-1] = tablica[a-1];
}
int odpowiedz(int a, int b){
    return tablica[0]; 
}
