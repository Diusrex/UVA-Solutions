#include <iostream>
#include <sstream>

using namespace std;

int basePrice;
int M;
int num[21];
int price[21];

int bestPrice[105];

int Calculate(int k) {
    if (k <= 0) {
        return 0;
    }
    if (bestPrice[k] != -1) {
        return bestPrice[k];
    }
    int p = basePrice * k;
    for (int i = 0; i < M; ++i) {
        p = min(p, price[i] + Calculate(k - num[i]));
    }

    return bestPrice[k] = p;
}

int main() {
    double base_d;
    int T = 0;
    cout.precision(2);
    cout << std::fixed;
    
    int p, d;
    char t;

    while (cin >> p >> t >> d >> M) {
        basePrice = p * 100 + d;
        for (int i = 0; i < M; ++i) {
            cin >> num[i] >> p >> t >> d;
            price[i] = p * 100 + d;
        }

        std::cout << "Case " << ++T << ":\n";
        string line;
        getline(cin, line);
        getline(cin, line);
        std::istringstream iss(line);
        int K;
        while (iss >> K) {
            for (int i = 0; i <= K; ++i) {
                bestPrice[i] = -1;
            }
            int b = Calculate(K);
            double b_d = b / 100.0d;
            std::cout << "Buy " << K << " for $" << b_d << '\n';
        }
    }
}