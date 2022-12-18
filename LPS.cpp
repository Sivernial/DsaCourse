
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int lps(char *Subsequence, int i, int j)
{

    if (i == j)
        return 1;

    if (Subsequence[i] == Subsequence[j] && i + 1 == j)
        return 2;

    if (Subsequence[i] == Subsequence[j])
        return lps(Subsequence, i + 1, j - 1) + 2;

    return max(lps(Subsequence, i, j - 1), lps(Subsequence, i + 1, j));
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    char seq[n];
    for (int i = 0; i < s.length(); i++)
    {
        seq[i] = s[i];
    }

    cout << lps(seq, 0, n - 1);
    return 0;
}
