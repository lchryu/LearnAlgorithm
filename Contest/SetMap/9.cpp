#include<bits/stdc++.h>
using namespace std;
int main()
{
    set <int> se;
    int n,m;
    cin >> n >> m;
    int s = n + m;
    for(int i=0 ; i<s ; i++)
    {
        int x; cin >> x;
        se.insert(x);
    }
    for(auto it = se.rbegin() ; it != se.rend() ; it++)
    {
        cout << *it << " ";
    }
}