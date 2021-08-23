//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 100005
#define MOD
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "POWER"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
ll n, m;
ll x, g;
ll sol(ll a, ll b)
{
    if (b == 1) return a;
    if (b % 2 == 0) return sol((a * a) % g, b/2);
    return (sol((a * a) % g, b/2) * a) % g;
}
void sub3()
{
    g = (x - 1)* m;
    ll res = sol(x, n + 1);
    res --;
    if (res < 0) res = g - 1;
    res = res/(x - 1);
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> x >> n >> m;
    sub3();
}
