/* LC ID :  #133
 * Type  :  DFS
 * Author:  Hangchen Yu
 * Date  :  09/22/2015
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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        return dfs(node, hash);
    }

    UndirectedGraphNode* dfs(UndirectedGraphNode *t, map<UndirectedGraphNode*, UndirectedGraphNode*>& hash) {
        auto it = hash.find(t);
        UndirectedGraphNode *node = NULL;
        if (it == hash.end()) {
            node = new UndirectedGraphNode(t->label);
            hash.insert({t, node});
            for (int i = 0; i < t->neighbors.size(); i++) {
                node->neighbors.push_back(dfs(t->neighbors[i], hash));
            }
        }
        else
            node = it->second;

        return node;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
