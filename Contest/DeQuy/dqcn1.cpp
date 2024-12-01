#include <bits/stdc++.h>
using ll = long long;
using namespace std;
map<int, ll>Dict;
ll n;
ll f(ll n)
{
	if (n < 3) return n;
	map<int, ll>::iterator it = Dict.find(n);
	if (it != Dict.end()) return it->second;

	ll k = n / 3;
	ll res = f(2 * k);
	if (n % 3 > 0) res += f(2 * k + 1);
	if (n % 3 > 1) res += f(2 * k + 2);
	Dict[n] = res;
	return res;
}
int main()
{
	cout << "Nhap n = "; cin >> n;
	cout << "f(" << n << ") = " << f(n);
}
