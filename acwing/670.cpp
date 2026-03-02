#include <bits/stdc++.h>
using namespace std;
string str1, str2, str3;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> str1 >> str2 >> str3;
    if (str1 == "vertebrado") {
        if (str2 == "ave") {
            if (str3 == "carnivoro") {
                cout << "aguia\n";
            } else {
                cout << "pomba\n";
            }
        } else {
            if (str3 == "onivoro") {
                cout << "homem\n";
            } else {
                cout << "vaca\n";
            }
        }
    } else {
        if (str2 == "inseto") {
            if (str3 == "hematofago") {
                cout << "pulga\n";
            } else {
                cout << "lagarta\n";
            }
        } else {
            if (str3=="hematofago"){
                cout << "sanguessuga\n";
            }
            else{
                cout << "minhoca\n";
            }
        }
    }
    return 0;
}