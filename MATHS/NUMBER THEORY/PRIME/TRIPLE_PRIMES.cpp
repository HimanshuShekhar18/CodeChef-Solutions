#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;

        if (n < 38) {
            cout << "NO" << endl;
            continue;
        }

        long long tofind = n - 4;
        
        long long b = int (sqrt(n));

        vector < int > primecheck( b+1, 1);

        primecheck[0] = primecheck[1] = 0;

        for (int i = 2; i <= b; i++) {

            if (primecheck[i]) {
                for (int j = i * 2; j <= b; j = j + i) {
                    primecheck[j] = 0;
                }
            }
        }

        bool flag = true;

        for (int i = 3; i <= b; i++) {
            if (primecheck[i]) {
                if ((n - 4 - i * 1LL * i) >= 0) {
                    if (primecheck[sqrt(n - 4 - i * 1LL * i)]) {
                        
                        long long a  = n - 4 - i * 1LL * i;
                        long long p = sqrt(n - 4 - i * 1LL * i);
                        
                        if (p != i && p*p==a) {
                            cout << "YES" << endl;
                            flag = false;
                            break;
                        }
                        
                    }
                }
            }
        }

        if (flag) cout << "NO" << endl;
    }

}
