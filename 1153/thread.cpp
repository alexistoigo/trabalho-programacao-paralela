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
#define MAX int32_t(1e6+10)
//const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
using namespace std::chrono;

#define NUM_THREADS 16

typedef struct {
    int a;
    int ans;
} ThreadArgs;

void *soma(void *arg) {
    ThreadArgs *args = (ThreadArgs *) arg;
    for (args->ans = 1; args->a > 1; args->a--)
        args->ans = args->a * args->ans;
    pthread_exit(NULL);
}

int main() {
    IO

#ifndef ONLINE_JUDGE
    FIN
//    FOUT
#endif

    auto start = high_resolution_clock::now();

    pthread_t threads[NUM_THREADS];
    ThreadArgs args[NUM_THREADS];
    int a;
    while (cin >> a) {
        for (int i = 0; i < NUM_THREADS; i++) {
            args[i].a = a;
            pthread_create(&threads[i], NULL, soma, (void *) &args[i]);
        }

        for (int i = 0; i < NUM_THREADS; i++) {
            pthread_join(threads[i], NULL);
            cout << args[i].ans << endl;
        }
    }


    auto stop = high_resolution_clock::now();
    cout << "Tempo de execucao: " << duration_cast<microseconds>(stop - start).count() << " microseconds" << endl;

    return 0;
}
