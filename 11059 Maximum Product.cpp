#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int T = 1;
    while (cin >> N) {
        // To remove negative it would be divide by the product_to_pos at this point.
        int first_negative_cum = 0;

        long long best_result = 0;
        long long cum_product = 1;
        for (int i = 0; i < N; ++i) {
            long long num;
            cin >> num;
            best_result = max(best_result, num);

            cum_product *= num;
            best_result = max(best_result, cum_product);

            // TODO -> add a break set, then use lower_bound to detect it!
            if (num == 0) {
                cum_product = 1;
                first_negative_cum = 0;
            }

            if (cum_product < 0) {
                if (first_negative_cum == 0) {
                    first_negative_cum = cum_product;
                } else {
                    best_result = max(best_result, cum_product / first_negative_cum);
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", T++, best_result);
    }
}