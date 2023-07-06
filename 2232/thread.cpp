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


#define NUM_THREADS 16

long long int pasc(int n) {
    return pow(2, n) - 1;
}

struct ThreadData {
    int n;
    long long int *result;
};

void *calculate_pasc(void *arg) {
    struct ThreadData *data = (struct ThreadData *) arg;
    *(data->result) = pasc(data->n);
    pthread_exit(NULL);
}

int main() {

#ifndef ONLINE_JUDGE
    FIN
//    FOUT
#endif

    auto startTime = high_resolution_clock::now();

    int teste, n;
    long long int resp;

    cin >> teste;

    while (teste--) {
        cin >> n;

        pthread_t threads[NUM_THREADS];
        struct ThreadData thread_data[NUM_THREADS];
        long long int results[NUM_THREADS];

        int chunk_size = n / NUM_THREADS;
        int remaining = n % NUM_THREADS;
        int start = 0;

        for (int i = 0; i < NUM_THREADS; i++) {
            int thread_size = chunk_size + (i < remaining ? 1 : 0);

            thread_data[i].n = thread_size;
            thread_data[i].result = &results[i];

            pthread_create(&threads[i], NULL, calculate_pasc, (void *) &thread_data[i]);

            start += thread_size;
        }

        for (int i = 0; i < NUM_THREADS; i++) {
            pthread_join(threads[i], NULL);
            cout << results[i] << "\n";
        }

    }


    auto stop = high_resolution_clock::now();
    cout << "Tempo de execucao: " << duration_cast<milliseconds>(stop - startTime).count() << " milissegundos" << endl;

    return 0;
}
