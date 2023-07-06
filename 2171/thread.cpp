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

#define NUM_THREADS 2

struct ThreadData {
    int x;
    int i;
};

void *calculate(void *arg) {
    ThreadData *data = static_cast<ThreadData *>(arg);
    int x = data->x;
    int i = 0;

    for (int j = 1; i + j <= x; j++) {
        i += j;
    }

    data->i = i;

    pthread_exit(nullptr);
}

int main() {

#ifndef ONLINE_JUDGE
    FIN
//    FOUT
#endif

    auto start = high_resolution_clock::now();

    int x;

    while (cin >> x && x) {
        ThreadData threadData[NUM_THREADS];
        pthread_t threads[NUM_THREADS];

        int remainingThreads = NUM_THREADS;
        int chunkSize = x / NUM_THREADS;
        int startIndex = 0;

        for (int t = 0; t < NUM_THREADS; t++) {
            threadData[t].x = (t == NUM_THREADS - 1) ? x - startIndex : chunkSize;
            threadData[t].i = 0;

            pthread_create(&threads[t], nullptr, calculate, &threadData[t]);

            startIndex += chunkSize;
        }

        for (int t = 0; t < NUM_THREADS; t++) {
            pthread_join(threads[t], nullptr);
        }

        int i = 0;
        for (int t = 0; t < NUM_THREADS; t++) {
            i += threadData[t].i;
        }

        cout << i << ' ' << x - i << '\n';
    }


    auto stop = high_resolution_clock::now();
    cout << "Tempo de execucao: " << duration_cast<microseconds>(stop - start).count() << " microseconds" << endl;

    return 0;
}
