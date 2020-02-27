#include <iostream>
#include <string>

using namespace std;

class Queue {
    class Node {
    public:

        string data;
        Node *next;

        Node(string data = "empty") {
            this->data = data;
            this->next = nullptr;
        }

        void print_data() {
            cout << this->data << endl;
        }

        string get_data() {
            return this->data;
        }


    };


    void remove_element() {
        if (this->head != nullptr) {
            Node *tmp = this->head;
            this->head = this->head->next;
            delete tmp;
        } else {
            cout << "queue is empty" << endl;
        }
        this->size--;
    }


    int size;

public:
    Node *head;

    friend ostream &operator<<(ostream &os, const Node &nd);

    friend ostream &operator<<(ostream &os, const Queue &nd);

    friend istream &operator>>(istream &is, Queue::Node &ns);


    Queue() {
        this->size = 0;
        this->head = nullptr;

    }

    void push_back(string data) {
        if (this->head == nullptr) {
            this->head = new Node(data);
        } else {
            Node *current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(data);
        }
        this->size++;
    }


    int get_size() {

        return this->size;
    }


    void remove_elements(int quantity = 1) {
        for (int i = 0; i < quantity; ++i) {
            remove_element();

        }

    }


    ~Queue() {
        Node *tmp;
        while (this->head) {
            tmp = this->head->next;
            delete this->head;
            this->head = tmp;
            this->size--;
        }
    };


};

ostream &operator<<(ostream &os, const Queue::Node &nd) {
    os << nd.data;
    return os;
}

ostream &operator<<(ostream &os, const Queue &nd) {
    Queue::Node *current = nd.head;

    while (current) {
        os << *current << endl;
        current = current->next;

    }
    return os;
}

istream &operator>>(istream &is, Queue::Node &ns) {
    is >> ns.data;
    return is;
}


int main() {
    Queue test;
    test.push_back("a");
    test.push_back("b");
    test.push_back("c");
    test.push_back("d");
    test.push_back("e");
    cin >> *test.head;
    cout << endl << endl;
    cout << test << endl;


    return 0;
}
