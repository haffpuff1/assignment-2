#include <iostream>

#include <stack>
using namespace std;
class Stack
{
private:
    stack<int> s;
public:
    void push(int x)
    {
       s.push(x);
    }
    void pop()
    {
        s.pop();
    }
    int top()
    {
        return s.top();
    }
    bool empty()
    {
        return s.empty();
    }
    // implement the + operator here
    Stack operator+(Stack &b)
    {
        Stack temp;
        while (!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        while (!b.empty())
        {
            temp.push(b.top());
            b.pop();
        }
        return temp;
    }
};

int main()
{
    Stack a, b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Stack c = a + b;
    // the contents of c should now be 1, 2, 3, 4 (in that order)
    while (!c.empty())
    {
        cout << c.top() << endl;
        c.pop();
    }
    return 0;
}
