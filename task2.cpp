// Shivam Kumar 555585
// BSCS-15-D

#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};


class LinkedQueue {
private: 
	node* head;
	node* tail;
public:
	LinkedQueue() { 
		// start at empry queue
		head = nullptr;
		tail = nullptr;
	};

	void Enqueue(int value){
		node* newNode = new node;
		newNode->data = value;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	};

	void Dequeue(){
		if (head == nullptr) { //if empty
			cout << "Queue is empty" << endl;
			return;
		}

		node* toDelete = head;
		cout << "Dequeued: " << head->data << endl;
		head = head->next;
		delete toDelete;

		if (head == nullptr) { //make queue empty
			tail = nullptr;
		}
		return;
	};

	int Peek() {
		if (head == nullptr) {
			cout << "Queue is empty" << endl;
			return -1;
		}
		return head->data;
	};

	bool IsEmpty() {
		return head == nullptr;
	};

	void Display() {
		if (head == nullptr) {
			cout << "Queue empty" << endl;
			return;
		}
		cout << "HEAD" << endl;
		for (node* i = head; i != tail->next; i = i->next) {
			cout << i->data << endl;
		}
		cout << "TAIL" << endl;
	};

	void ClearQueue() {
		if (head == nullptr) {
			cout << "Queue Empty" << endl;
			return;
		}
		while (head != nullptr) {
			node* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
	}
};

int main() {
	LinkedQueue q;

	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);

	q.Dequeue();
	q.Display();

	cout << "Peek: " << q.Peek() << endl;
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Enqueue(70);
	q.Display();

	q.ClearQueue();

	return 0;
}
