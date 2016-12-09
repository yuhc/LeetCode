/* LC ID :  #149
 * Type  :  Hash, enumerate
 * Author:  Hangchen Yu
 * Date  :  12/08/2016
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
#include <unordered_map>

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

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<double, int> hash;
        int n = points.size();
        if (n <= 1) return n;

        int max = 2;

        for (int i = 0; i < n - 1; ++i) {
            int duplicate = 0;
            int vertical = 1;
            int online = 1;
            hash.clear();
            for (int j = i + 1; j < n; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                    continue;
                }
                if (points[j].x == points[i].x) {
                    vertical++;
                    continue;
                }
                double k = (double)(points[j].y - points[i].y) /
                        (points[j].x - points[i].x) ;
                hash[k] == 0 ? hash[k] = 2 : hash[k]++;

                if (online < hash[k]) online = hash[k];
            }
            if (duplicate + vertical > max) max = duplicate + vertical;
            if (duplicate + online > max) max = duplicate + online;
        }

        return max;
    }
};

int main() {
    Solution sol;
    

    return 0;
}
