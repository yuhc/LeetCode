/* LC ID :  #204
 * Type  :  Flag
 * Author:  Hangchen Yu
 * Date  :  09/13/2015
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <utility>
#include <cmath>

using namespace std;

//copy the Solution class here
class Solution {
public:
   int countPrimes(int n) {
       bool isPrime[n];
       for (int i = 2; i < n; i++)
          isPrime[i] = true;
       // Loop's ending condition is i * i < n instead of i < sqrt(n)
       // to avoid repeatedly calling an expensive function sqrt().
       for (int i = 2; i * i < n; i++) {
           if (!isPrime[i]) continue;
           for (int j = i * i; j < n; j += i)
           isPrime[j] = false;
       }
       int count = 0;
       for (int i = 2; i < n; i++)
           if (isPrime[i]) count++;
       return count;
   }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.countPrimes(n) << endl;

    return 0;
}
