/*
File name: hw4
Created by: xiaojie chong
Created on: 10/18/2019
Synopsis: This program can calculate the input in a certain format. For example, a input like 3 4 + will output 7;
This program use stack which is implemented by linked list to achieve the goal;
*/

#include <iostream>
#include <cstdlib>

using namespace std;

const char SENTINEL = ';';

struct Node {
    int data;
    Node *link;
};

// precondition: c is initialized
// postcondition: returns true if c is '+', '-', '*' or '/'
bool isOperator(char c);

// precondition: o1 and o2 are initialized and op is an operator
// postcondition: returns op(o1, o2), e.g. if op is '-' then returns o1-o2
int calculate(int o1, int o2, char op);

// precondition: c is a digit
// postcondition: returns the integer value of c
int charToInt(char c);

class Stack {

public:
    // default constructor
    // initializes the stack to an empty stack
    Stack();

    // this is a const function, meaning it cannot change any of the member variables
    // returns true if the stack is empty, false otherwise
    bool isEmpty() const;

    // this is a const function, meaning it cannot change any of the member variables
    // returns the value at the top of stack, does not modify the stack, does not check if the stack is empty or not
    int top() const;

    // adds data to the top of stack
    void push(int data);

    // removes the top value of stack, does not return it, does nothing if the stack is empty
    void pop();

private:
    Node *listHead; // pointer to the head of a linked list

};

int main() {
    char in;
    Stack operandStack;
    cout << "Enter a postfix expression (ending with " << SENTINEL << " and press Enter):\n";
    cin >> in ;
    while ( in != SENTINEL) {
        if (isOperator( in )) {
            // pop two numbers from stack
            int n1, n2;
            if (operandStack.isEmpty()) {
                // pring error message
                /*your code here*/
                cout << "Not enough operands entered for operator: " << in <<endl;   //cout the error with the error in
                exit(1);
            }
            n2 = operandStack.top();
            operandStack.pop();

            if (operandStack.isEmpty()) {
                // pring error message
                /*your code here*/
                cout << "Not enough operands entered for operator: " << in <<endl;  //cout the error with the error in
                exit(1);
            }
            n1 = operandStack.top();
            operandStack.pop();
            // push the result of calculation to the top of operandStack 
            /*your code here*/
            operandStack.push(calculate(n1,n2,in));         //push the result into the stack

        } else {
            // push the number to the top of opernadStack
            /*your code here*/
            operandStack.push(charToInt(in)); //push the int input into  the stack

        }
        cin >> in ;
    }

    // pop a number from the top of stack
    int result;
    result = operandStack.top();
    operandStack.pop();

    if (operandStack.isEmpty()) // nothing left in the stack
        cout << "\nThe result is: " << result << endl;
    else // there are still numbers in the stack
    {
        // pring an error message
        /*your code here*/
        cout << "Not enough operators entered!" << endl;

    }

    return 0;
}

Stack::Stack() {
    /*your code here*/
    listHead = NULL;
}

bool Stack::isEmpty() const {
    /*your code here*/
    return listHead == NULL;
}

int Stack::top() const {
    /*your code here*/
    return listHead->data;
}

void Stack::pop() {
    /*your code here*/
    if(!isEmpty()){
        listHead = listHead -> link;
    }
}

void Stack::push(int data) {
    /*your code here*/
    Node *newnode;
    newnode = new Node;
    newnode->data = data;
    newnode->link = listHead;
    listHead = newnode;
}



int calculate(int o1, int o2, char op) {
    /*your code here*/
    if ( op == '+') return o1 + o2;
    if ( op == '-') return o1 - o2;
    if ( op == '*') return o1 * o2;
    if ( op == '/') return o1 / o2;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int charToInt(char c) {
        return (static_cast<int>(c) - static_cast<int>('0'));}