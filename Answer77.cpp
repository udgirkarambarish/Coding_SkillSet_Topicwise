// q77) Delete middle element in stack.

#include <iostream>
#include <stack>

using namespace std;

void deleteMiddle(stack<int>& s, int n, int current = 0) {
    if (s.empty() || current == n)
        return;

    int temp = s.top();
    s.pop();

    // If this is not the middle element, push it to the auxiliary stack
    if (current != n / 2)
        deleteMiddle(s, n, current + 1);

    // Push the element back to the original stack
    s.push(temp);
}

int main() {
    stack<int> s;
    int n;
    
    cout << "Enter the number of elements in the stack: ";
    cin >> n;
    
    cout << "Enter the elements of the stack: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        s.push(element);
    }

    cout << "Original Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    // Rebuild the stack
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        s.push(element);
    }

    deleteMiddle(s, n);

    cout << "Stack after deleting middle element: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}
