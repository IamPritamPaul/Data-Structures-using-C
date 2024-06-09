#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s1;
    s1.push(10);
    s1.push(23);
    s1.push(19);
    s1.push(15);
    s1.push(13);
    s1.push(12);
    while (!s1.empty())
    {
        cout << s1.top() << "  ";
        s1.pop();
    }
    cout << endl;
    return 0;
}