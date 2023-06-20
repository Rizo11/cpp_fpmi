// Mukhammadrizo Maribjonov DS-AI 4

#include <iostream>
#include  <bits/stdc++.h>

using namespace std;

template<typename T>

class Node {
public:
    T value;
    Node* next;

    Node(T data) {
        this->value = data;
        this->next = nullptr;
    }
};

template<typename T>
class QUEUE {

private:
    Node<T> * front;
    Node<T> * rear;
    int volume;
public:
    QUEUE() {
        volume = 0;
        front = nullptr;
        rear = nullptr;
    }

    /**add e to the rear of the queue*/
    void offer(T value) {
        Node<T>* newNodePrt = new Node(value);

        if (rear == nullptr) {
            front = rear = newNodePrt;
            return;
        }

        rear->next = newNodePrt;
        rear = newNodePrt;
        ++volume;
    }

    /**remove (extract) the first (front) item from the queue*/
    T pool() {

        if (front == nullptr) {
            throw out_of_range("QUEUE IS EMPTY");
        }

        Node<T>* tmpNode = front;
        front = front->next;
        --volume;

        if (front == nullptr) {
            rear = nullptr;
        }

        T returnValue = tmpNode->value;
        delete(tmpNode);
        return returnValue;
    }

    /**return (without removing) the first item of the queue*/
    T peek() {
        if (front == nullptr) {
            return nullptr;
        }

        return front;
    }

    int size() {
        return volume;
    }

    bool isEmpty() {
        return front == nullptr && rear == nullptr;
    }
};

template<typename T>

class STACK {
public:
    Node<T> *top;
    int size;
    STACK(){
        top = NULL;
        size = 0;
    }

    /**add e on top of the stack*/
    void push(T value){
        Node<T> *newNode = new Node(value);

        // Check if stack (heap) is full.
        // Then inserting an element would
        // lead to stack overflow
        if (!newNode) {
            cout << "\nStack Overflow";
            exit(1);
        }

        newNode->value = value;
        newNode->next = top;
        top = newNode;

        ++size;
    }

    T pop(){
        if (isEmpty()) {
            throw out_of_range("STACK IS EMPTY");
        }
        Node<T> *popNode = top;
        top = top->next;
        T popValue = popNode->value;
        --size;
        delete(popNode);
        return popValue;
    }

    T peek() {
        if (isEmpty()) {
            throw out_of_range("STACK IS EMPTY");
        }
        return top->value;
    }

    int stackSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};

QUEUE<string> splitstr(string str, string deli = " ")
{
    int start = 0;
    int end = str.find(deli);
    QUEUE<string> strings;
    while (end != -1) {
        strings.offer(str.substr(start, end - start));
        start = end + deli.size();
        end = str.find(deli, start);
    }

    strings.offer(str.substr(start, end - start));

    return strings;
}

int isOperator(string exp) {
    string operators[9] = {")", "min", "max", "*", "/", "+", "-", "(", ","};

    for (int i = 0; i < 9; ++i) {
        if (exp == operators[i]) {
            return i;
        }
    }

    return -1;
}

void expression (string opr, STACK<string>& output) {
    if (opr == "+") {
        int ex1 = stoi(output.pop());
        int ex2 = stoi(output.pop());
        ex1 = ex1 + ex2;
        string newCalc = to_string(ex1);
        output.push(newCalc);
    } else if (opr == "-") {
        int ex1 = stoi(output.pop());
        int ex2 = stoi(output.pop());
        ex2 = ex2 - ex1;
        output.push(to_string(ex2));
    } else if (opr == "*") {
        int ex1 = stoi(output.pop());
        int ex2 = stoi(output.pop());
        ex2 = ex2 * ex1;
        output.push(to_string(ex2));
    } else if (opr == "/") {
        int ex1 = stoi(output.pop());
        int ex2 = stoi(output.pop());
        ex2 = ex2 / ex1;
        output.push(to_string(ex2));
    } else if (opr == "max") {
        int ex1 = stoi(output.pop());
        int ex2 = stoi(output.pop());
        ex2 = ex1 > ex2 ? ex1 : ex2;
        output.push(to_string(ex2));
    } else if (opr == "min") {
        int ex1 = stoi(output.pop());
        int ex2 = stoi(output.pop());
        ex2 = ex1 < ex2 ? ex1 : ex2;
        output.push(to_string(ex2));
    }
}
int main() {
    char line[1000000];
    cin.getline(line, 1000000);
    QUEUE<string> input = splitstr(line, " ");

    STACK<string> operators;
    STACK<string> output;
    STACK<int> evaluation;

    while (!input.isEmpty()) {
        string current_input = input.pool();
        int isOper = isOperator(current_input);
        string opr;

        if (isOper == 0) { // )
            while (operators.peek() != "(") {
                expression(operators.pop(), output);
            }
            operators.pop();

            if ( operators.isEmpty()) {
                continue;
            }
            if (operators.peek() == "min" || operators.peek() == "max") {
                expression(operators.pop(), output);
            }
        } else if (isOper == 1 || isOper == 2) {  // min && max
            if (operators.isEmpty()) {
                operators.push(current_input);
                continue;
            }

            operators.push(current_input);

        } else if (isOper == 3 || isOper == 4) { // *
            if (operators.isEmpty()) {
                operators.push(current_input);
                continue;
            }
            if (operators.peek() == "/" || operators.peek() == "*") {
                expression(operators.pop(), output);
            }
            operators.push(current_input);
        } else if (isOper == 5 || isOper == 6) { // +
            if (operators.isEmpty()) {
                operators.push(current_input);
                continue;
            }
            while (operators.peek() == "/" || operators.peek() == "*" || operators.peek() == "-" || operators.peek() == "+") {
                expression(operators.pop(), output);
                if (operators.isEmpty()) {
                    break;
                }
            }
            operators.push(current_input);
        } else if (isOper == 7) { // (
            operators.push(current_input);
        } else if (isOper == 8) { // ,
            while (operators.peek() != "(") {
                expression(operators.pop(), output);
            }
        } else if (isOper == -1) {
            output.push(current_input);
        }
    }
    while (!operators.isEmpty()) {
        expression(operators.pop(), output);
    }

    while (!output.isEmpty()) {
        cout << output.pop() << " ";
    }

    return 0;
}