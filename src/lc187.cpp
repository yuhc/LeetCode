/* LC ID :  #187
 * Type  :  Bit Manipulation + Hash
 * Author:  Hangchen Yu
 * Date  :  09/28/2015
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
#include <climits>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL),
    next(NULL) {}
};

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

//copy the Solution class here
class Solution {
public:
    int convert(char x) {
        int t;
        switch (x) {
            case 'A': t = 0; break;
            case 'C': t = 1; break;
            case 'G': t = 2; break;
            case 'T': t = 3;
        }
        return t;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.length() < 11) return ans;
        map<int, int> hash;
        
        int t = 0;
        for (int i = 0; i < 10; i++) t = (t<<2) | convert(s[i]);
        hash.insert({t,0});
        for (int i = 10; i < s.length(); i++) {
            t &= 0x3FFFF;
            t <<= 2;
            t |= convert(s[i]);
            auto it = hash.find(t);
            if (it != hash.end() && it->second >= 0) {
                ans.push_back(s.substr(it->second, 10));
                it->second = -1;
            }
            else
                hash.insert({t,i-9});
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
