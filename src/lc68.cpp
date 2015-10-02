/* LC ID :  #68
 * Type  :  Greedy + String
 * Author:  Hangchen Yu
 * Date  :  09/11/2015
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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int start, end, len, num, k = 0;
        const char testchar = ' ';

        while (k < words.size()) {
            start = end = k;
            len = -1;
            while (end < words.size() && len+words[end].length()+1 <= maxWidth)
                len += words[end++].length() + 1;
            int num = end - start;
            len -= num-1;

            string s = "";
            if (end != words.size() && num > 1) {
                for (int i = start; i < end; i++) {
                    s += words[i];
                    int avg = (maxWidth-len)/(num-1);
                    if (i < end-1)
                        for (int j = 0; j < ((i<start+maxWidth-len-avg*(num-1))?avg+1:avg); j++)
                            s += testchar;
                }
            }
            else {
                for (int i = start; i < end; i++) {
                    s += words[i];
                    if (i < end-1) s += testchar;
                }
                for (int j = 0; j < maxWidth-len-num+1; j++)
                    s += testchar;
            }
            ans.push_back(s);

            k = end;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> s = {"What","must","be","shall","be."};//= {"This", "is", "an", "example", "of", "justification", "text", "justification", "justification."};
    vector<string> ans = sol.fullJustify(s, 12);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
