#include "../headers/functions.h"
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> szamitDP(const vector<vector<int>> &e, int n, int m)
{
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
  for (int j = 1; j <= m - n + 1; ++j)
    dp[1][j] = e[1][j];
  for (int i = 2; i <= n; ++i)
    for (int j = i; j <= m - (n - i); ++j)
      for (int k = i - 1; k < j; ++k)
        if (dp[i - 1][k] != INT_MIN)
          dp[i][j] = max(dp[i][j], dp[i - 1][k] + e[i][j]);
  return dp;
}

int maxEsztetika(const vector<vector<int>> &dp, int n, int m)
{
  int maxErtek = INT_MIN;
  for (int j = n; j <= m; ++j)
    maxErtek = max(maxErtek, dp[n][j]);
  return maxErtek;
}

vector<int> visszavezetes(const vector<vector<int>> &dp, const vector<vector<int>> &e, int n, int m)
{
  vector<int> elhelyezes(n + 1, 0);
  int maxErtek = INT_MIN;
  for (int j = n; j <= m; ++j)
  {
    if (dp[n][j] > maxErtek)
    {
      maxErtek = dp[n][j];
      elhelyezes[n] = j;
    }
  }
  for (int i = n - 1; i >= 1; --i)
  {
    int j_next = elhelyezes[i + 1];
    int bestK = -1;
    int bestVal = INT_MIN;
    for (int k = i; k < j_next; ++k)
    {
      if (dp[i][k] != INT_MIN && dp[i][k] + e[i + 1][j_next] == dp[i + 1][j_next])
      {
        if (dp[i][k] > bestVal)
        {
          bestVal = dp[i][k];
          bestK = k;
        }
      }
    }
    elhelyezes[i] = bestK;
  }
  return elhelyezes;
}

void kiir(const vector<int> &elhelyezes, int maxErtek)
{
  cout << maxErtek << "\n";
  for (int i = 1; i < (int)elhelyezes.size(); ++i)
    cout << i << " -> " << elhelyezes[i] << "\n";
}