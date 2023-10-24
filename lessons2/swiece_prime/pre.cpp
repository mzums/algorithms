#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("raw.txt");
    ofstream fout("list.txt");

    string first, second;
    fout << "{2";

    while (fin >> first >> second) {
        fout << ", " << second;
    }
    fout << "}";
    fin.close();    
    fout.close();
}

