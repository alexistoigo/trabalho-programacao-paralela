#include <bits/stdc++.h>
#include <pthread.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
//#define MAX int32_t(1e6+10)
//const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
using namespace std::chrono;

ll pasc(int n) {
    return pow(2, n) - 1;
}

int main() {


#ifndef ONLINE_JUDGE
    FIN
//    FOUT
#endif

    time_t t_ini, t_fim;
    auto startTime = high_resolution_clock::now();

    int teste, n;
    long long int resp;

    cin >> teste;

    while (teste--) {

        cin >> n;

        cout << pasc(n) << "\n";
    }

    auto stop = high_resolution_clock::now();
    cout << "Tempo de execucao: " << duration_cast<microseconds>(stop - startTime).count() << " microseconds" << endl;

    return 0;
}
