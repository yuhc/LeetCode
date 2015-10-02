/* LC ID :  #225
 * Type  :  Queue + Stack
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
class Stack {
public:
    vector<int> s;

    // Push element x onto stack.
    void push(int x) {
        s.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!s.empty()) s.pop_back();
    }

    // Get the top element.
    int top() {
        if (!s.empty()) return s.back();
        else return 0;
    }

    // Return whether the stack is empty.
    bool empty() {
        return s.empty();
    }
};

int main() {
    Stack s;
    cout << s.top() << endl;
    cout << s.empty() << endl;
    s.push(1); s.push(2);
    cout << s.top() << " " << s.empty() << endl;
    s.pop();
    cout << s.top() << endl;

    return 0;
}
