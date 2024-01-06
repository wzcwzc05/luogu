#include <chrono>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string st;
    cin >> st;
    string exe = "./" + st + " < ./input.in > ./output.out";
    cout << exe << "\n";
    auto start = chrono::high_resolution_clock::now();
    system(exe.c_str());
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "************************************\n";
    cout << "Time: " << duration << "ms\n";
    return 0;
}
