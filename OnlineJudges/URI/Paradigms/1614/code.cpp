#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, t;

int main() {
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        vector < pair < int, int > > attractions;
        vector < int > dists;

        scanf("%d %d %d", &n, &m, &k);

        int x, y;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            attractions.push_back(make_pair(x,y));
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            for (int j = 0; j < n; j++) {
                int dist = abs(x - attractions[j].first) + abs(y - attractions[j].second);
                dists.push_back(dist);
            }
        }

        sort(dists.begin(), dists.end());

        long long total = 0;
        for(int i = 0; i < k; i++) {
            total += dists[i];
        }

        printf("%llu\n", total);
    }

    return 0;
}
