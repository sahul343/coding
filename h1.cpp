#include <bits/stdc++.h>

using namespace std;
int dp[1000005];
/*
 * Complete the downToZero function below.
 */
int downToZero(int n) {
    return dp[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    dp[0] = 0;
    for (int i = 1; i <= 1000000; i++) {
            int ans = dp[i - 1] + 1;
            for (int j = 2; j*j <= i; j++) {
                if (i % j == 0) {
                    ans = min(ans, dp[i / j] + 1);
                }
            }
            dp[i] = ans;
    }
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = downToZero(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
