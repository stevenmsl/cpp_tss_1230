#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol1230;
using namespace std;

/*takeaways
  - handle 0 head case separately to make the code easier to read
  - for the dp part, here is the transition equation
    - dp[i][j] = dp[i-1][j-1] * probs[i-1] + dp[i-1][j] * (1-probs[i-1])
    - dp is 1-based, and the probability of tossing a head in the ith toss
      is probs[i-1]
    - so if the prvious i-1 tosses yields j-1 head, the chance of this toss
      is also a head is dp[i-1][j-1] * probs[i-1]
    - plus the prvious i-1 tosses yields j head, the chance of this toss
      is a tail is dp[i-1][j] * (1-probs[i-1])
  - let's use prob = [0.4, 0.4], target = 1 as an example
  - there are 4 possible outcomes
    - TT, HT, TH, HH
    - we only care about HT and TH as target is 1
    - HT
      - Prob(H) * Prob(1-H) = 0.4x0.6 = 0.24
    - TH
      - Prob(H) * Prob(1-H) = 0.4x0.6 = 0.24
    - since both HT and TH will yield one head
      so in total 0.24 + 0.24 = 0.48
*/

double Solution::prob(vector<double> &probs, int target)
{
  const int n = probs.size();

  auto dp = vector<vector<double>>(n + 1, vector<double>(target + 1, 0));
  /* so that it will work for the very first toss*/
  dp[0][0] = 1;

  for (auto i = 1; i <= n; i++)
  {
    /*I don't know how many times I have been haunted by this
      - we change the dp to be 1-based, but the current
        probability is in probs[i-1] !
    */
    auto cur = probs[i - 1];
    /*handle zero head case separately to make the code easier to read */
    dp[i][0] = dp[i - 1][0] * (1 - cur);

    for (auto j = 1; j <= target; j++)
      dp[i][j] =
          /*previous i-1 tosses yields j-1 heads, and this toss yield the ith head*/
          dp[i - 1][j - 1] * cur +
          /* previous i-1 tosses yields j heads, and this toss doesn't*/
          dp[i - 1][j] * (1 - cur);
  }
  return dp[n][target];
}