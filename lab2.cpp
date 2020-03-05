#include <iostream>
#include <string>

using namespace std;

class Queue {
    int size;

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



public:
    Node *head;

    Queue(const Queue &that){

        Node *current = that.head;
        this->size=0;

        while (current) {
            this->push_back(current->get_data());
            current = current->next;
            this->size++;

        }

    }


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

    void print_whole() {
        Node *current = this->head;
        current->print_data();
        while (current->next != nullptr) {
            current = current->next;
            current->print_data();


        }
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


int main() {
    Queue test;
    test.push_back("a");
    test.push_back("b");
    test.push_back("c");
    test.push_back("d");
    test.push_back("e");


    Queue q(test);
    q.print_whole();
//
//    test.print_whole();
//    cout << endl << endl;
//
//
//    test.get_size();
//
//    test.remove_elements(2);
//
//    test.get_size();


//    cout << endl << endl;
//    test.print_whole();


    return 0;
}
