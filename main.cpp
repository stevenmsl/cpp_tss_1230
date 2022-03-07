#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1230;

/*
Example 1:
Input: prob = [0.4], target = 1
Output: 0.40000
*/
tuple<vector<double>, int, double>
testFixture1()
{
  return make_tuple(vector<double>{0.4}, 1, 0.40000);
}

/*
Example 2:
Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
Output: 0.03125
*/
tuple<vector<double>, int, double>
testFixture2()
{
  return make_tuple(vector<double>{0.5, 0.5, 0.5, 0.5, 0.5}, 0, 0.03125);
}
void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::prob(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::prob(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}