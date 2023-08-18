#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<priority_queue<int, vector<int>, greater<int>>> arrays(n);
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int num;
                cin >> num;
                arrays[i].push(num);
            }
        }

        long long initialBeauty = 0;
        priority_queue<int, vector<int>, greater<int>> minValues;

        for (int i = 0; i < n; ++i) {
            initialBeauty += arrays[i].top();
            minValues.push(arrays[i].top());
            arrays[i].pop();
        }

        long long finalBeauty = initialBeauty;

        while (!minValues.empty()) {
            int minVal = minValues.top();
            minValues.pop();

            for (int i = 0; i < n; ++i) {
                if (!arrays[i].empty()) {
                    int newVal = arrays[i].top();
                    if (newVal < minVal) {
                        finalBeauty += newVal - minVal;
                        minValues.push(newVal);
                        arrays[i].pop();
                    }
                }
            }
        }

        cout << finalBeauty << endl;
    }

    return 0;
}