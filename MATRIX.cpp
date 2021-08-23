////ngqminh.cl2735
//#include <bits/stdc++.h>
//#define PB push_back
//#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
//#define pii pair <int,int>
//#define vi vector <int>
//#define vii vector <pii>
//#define mpa make_pair
//#define oo INT_MAX
//#define F first
//#define S second
//#define reset(x, i) memset(x,i,sizeof(x))
//#define sz(x) int(x.size())
//#define maxn 505
//#define MOD
//#define all(x) x.begin(), x.end()
//#define cosdo(x) cos((x)/180 * Pi)
//#define sindo(x) sin((x)/180 * Pi)
//#define tando(x) tan((x)/180 * Pi)
//#define cotdo(x) 1/tando(x)
//#define Task "MATRIX"
//using namespace std;
//const double Pi = acos(-1);
//typedef long long ll;
//typedef long double ld;
//ll a[maxn][maxn];
//ll suf[maxn][maxn];
//ll f[maxn][maxn];
//ll s[maxn], b[maxn], c[maxn];
//int m, n;
//void sol3()
//{
//    for (int i = 1; i <= m; i ++)
//        for (int j = 1; j <= n; j ++)
//            cin >> a[i][j];
//    for (int i = 1; i <= m; i ++)
//        for (int j = 1; j <= n; j ++) f[i][j] = f[i - 1][j] + a[i][j];
//    ll res = a[1][1];
//    for (int j = 1; j <= m; j ++)
//        for (int i = 1; i <= j; i ++)
//        {
//            s[1] = b[1] = f[j][1] - f[i - 1][1];
//            for (int k = 2; k <= n; k ++)
//            {
//                b[k] = f[j][k] - f[i - 1][k];
//                s[k] = s[k - 1] + b[k];
//                if (s[k] < s[c[k - 1]]) c[k] = k; else c[k] = c[k - 1];
//                res = max(res, s[k] - s[c[k]]);
//            }
//        }
//    cout << res;
//}
//ll get(int x, int y, int u, int v)
//{
//    return suf[x][y] - suf[u - 1][y] - suf[x][v - 1] + suf[u - 1][v - 1];
//}
//int main() {
//    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
//    cin >> m >> n;
//    sol3();
//    if (m >= 100 || n >= 100) sol3();
//    ll res = -oo;
//    for (int i = 1; i <= m; i ++)
//        for (int j = 1; j <= n; j ++) {
//            cin >> a[i][j];
//            suf[i][j] = a[i][j] + suf[i - 1][j] + suf[i][j - 1] - suf[i - 1][j - 1];
//        }
//    for (int i = 1; i <= m; i ++)
//        for (int j = 1; j <= n; j ++)
//            for (int z = 1; z <= i; z ++)
//                for (int r = 1; r <= j; r ++)
//                res = max(res, get(i, j, z, r));
//    cout << res;
//    //
//}
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
#define maxn 505
#define MOD
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "MATRIX"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
ll a[maxn][maxn];
ll suf[maxn][maxn];
int n, m;
ll s[maxn];
ll get(int x, int y, int u, int v)
{
    return suf[x][y] - suf[u - 1][y] - suf[x][v - 1] + suf[u - 1][v - 1];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            suf[i][j] = a[i][j] + suf[i - 1][j] + suf[i][j - 1] - suf[i - 1][j - 1];
    ll res = -oo;
    for (int p = 1; p <= m; p ++)
        for (int j = 1; j <= p; j ++){
            ll mn = oo;
            for (int i = 1; i <= n; i ++)
                s[i] = s[i - 1] + get(p, i, j, i);
            for (int i = 1; i <= n; i ++)
            {
                mn = min(mn, s[i - 1]);
                res = max(res, s[i] - mn);
            }
//            deque <int> dq;
//            for (int i = 0; i <= n; i ++)
//            {
//                while (!dq.empty() && s[i] <= s[dq.back()]) dq.pop_back();
//                if (!dq.empty()) res = max(res, s[i] - s[dq.front()]);
//                dq.PB(i);
//            }
        }
    cout << res;
}

