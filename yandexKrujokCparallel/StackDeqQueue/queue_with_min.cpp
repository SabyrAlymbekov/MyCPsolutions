#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#define ll long long

using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    stack<pair<ll, ll> > f, s;
    ll x;
    cin >> x;
    f.push({x, x});
    for (ll i = 1; i < n; i++) {
        cin >> x;
        if (i >= k) {
            if (s.empty()) {
                while (!f.empty()) {
            		ll element = f.top().first;
            		f.pop();
            		ll minima = s.empty() ? element : min(element, s.top().second);
            		s.push({element, minima});
                }
                s.pop();
                f.push({x, x});
            } else {
                s.pop();
                if (!f.empty()) {
                    f.push({x, min(f.top().second, x)});
                } else {
                    f.push({x, x});
                }
            }
        } else {
            f.push({x, min(x, f.top().second)});
        }
        if (i > k - 2) {
            if (f.empty() || s.empty())
            	cout << (f.empty() ? s.top().second : f.top().second) << ' ';
            else
            	cout <<  min(f.top().second, s.top().second) << ' ';
        }
    }

    return 0;
}