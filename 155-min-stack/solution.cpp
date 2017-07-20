#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (m_stack.empty()) {
            m_stack.push(make_pair(x, x));
        } else {
            int prev_min = m_stack.top().second;
            if (prev_min < x) {
                m_stack.push(make_pair(x, prev_min));
            } else {
                m_stack.push(make_pair(x, x));
            }
        }
    }

    void pop() {
        m_stack.pop();
    }

    int top() {
        return m_stack.top().first;
    }

    int getMin() {
        return m_stack.top().second;
    }

private:
    stack<pair<int, int> > m_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
}
