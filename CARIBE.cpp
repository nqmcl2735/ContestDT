//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo LLONG_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 50
#define MOD
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "CARIBE"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
int n;
ll k;
pair <ll, ll> a;
void Trau()
{
    cin >> n >> k;
    ll res = -oo;
    for (ll i = 0; i < n; i ++) cin >> a[i] >> b[i];
    for (ll x = 0; x < (1ll << n); x ++)
    {
        ll sum = 0;
        ll sumgt = 0;
        for (ll i = 0; i < n; i ++)
        if ((x >> i) & 1ll)
        {
            sum += a[i];
            sumgt += b[i];
        }
        if (sum <= k) res = max(res, sumgt);
    }
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
//    Trau();
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    cin >> a[i].F >> a[i].S;
    int m = n/2;
    for (int x = 0; x < (1 << m); x ++)
    {

    }


}
