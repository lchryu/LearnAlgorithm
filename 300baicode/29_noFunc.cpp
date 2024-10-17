#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool flag = true;
    if (n < 2) flag = false;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                flag = false;
                break;
            }
        }
    }

    if (flag) cout << "Yes";
    else cout << "No";
}