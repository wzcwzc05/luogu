#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        vec.push_back(i);
    do
    {
        for (int i = 0; i < n; ++i)
            printf("%5d", vec[i]);
        printf("\n");
    } while (next_permutation(vec.begin(), vec.end()));
    for (auto &i : vec)
        cout << i << " ";
    cout << "\n";
    return 0;
}