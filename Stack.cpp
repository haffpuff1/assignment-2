#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
template <class T>
class Stack
{
private:
    vector<T> array;
public:
    void push(T k);
    bool pop();
    T top();
    bool empty();
    T size();
    Stack<T> operator+(Stack<T> stack2);
};
template <class T>
bool Stack<T>::empty()
{
    return array.size() == 0;
}
template <class T>
void Stack<T>::push(T k)
{
    array.push_back(k);
}
template <class T>
Stack<T> Stack<T>::operator+(Stack<T> stack2)
{
    vector<T> temporary;
    Stack<T> newStack;
    int s2 = stack2.size();
    int s = Stack<T>::size();
    for (int i = 0; i < s2; i++)
    {

        temporary.push_back(stack2.top());
        stack2.pop();
    }
    for (int i = 0; i < s; i++)
    {
        temporary.push_back(Stack<T>::top());
        Stack<T>::pop();
    }
    int size = temporary.size();
    for (int i = 0; i < size; i++)
    {
        newStack.push(temporary.back());
    std:
        temporary.pop_back();
    }
    return newStack;
}
template <class T>
bool Stack<T>::pop()
{
    if (empty() == true)
        return false;
    array.pop_back();
    return true;
}

template <class T>
T Stack<T>::size()
{
    return array.size();
}template <class T>
T Stack<T>::top()
{
    return array[array.size() - 1];
}
int main()
{
    Stack<int> s1;
    Stack<int> s2;

    s1.push(10);
    s1.push(9);
    s2.push(7);
    s2.push(5);
    std::cout << s1.top();
    std::cout << "\n";
    s1.pop();
    std::cout << s1.top();
    std::cout << "\n";
    Stack<int> a = s1 + s2;
    a.pop();
    std::cout << a.top();
    return 0;
}