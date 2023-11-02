#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e8 + 10;
//bool prime[N];
bitset<N> prime;
void isPrime(int right)
{
    for (int i = 2; i <= sqrt(right); i++)
    {
        if (prime[i] == 0)
        {
            for (int j = 2 * i; j <= right; j += i)
                prime[j] = 1;
        }
    }
}
// 判断回文数
bool isPalindrome(int x)
{
    int temp = x;
    int y = 0;
    while (x > 0)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y == temp;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll left, right;
    cin >> left >> right;
    isPrime(right);

    if (left % 2==0)
        left++;

    for (int i = left; i <= right; i+=2)
    {
        if (prime[i] == 0 && isPalindrome(i))
            cout << i << "\n";
    }
    return 0;
}