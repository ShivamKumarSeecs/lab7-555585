// Shivam Kumar 555585
// BSCS-15-D

#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class LinkedDeque {
private:
	node* front;
	node* rear;
public:
	LinkedDeque() {
		// start at empty deque
		front = nullptr;
		rear = nullptr;
	};

	void InsertFront(int value){
		node* newNode = new node;
		newNode->data = value;
		newNode->next = front;
		newNode->prev = nullptr;

		if (front == nullptr) { //if empty
			front = newNode;
			rear = newNode;
		}
		else {
			front->prev = newNode;
			front = newNode;
		}
		return;
	};

	void InsertRear(int value){
		node* newNode = new node;
		newNode->data = value;
		newNode->next = nullptr;
		newNode->prev = rear;

		if (front == nullptr) { //if empty
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		return;
	};

	void DeleteFront(){
		if (front == nullptr) { //if empty
			cout << "Deque is empty" << endl;
			return;
		}
		node* toDelete = front;
		cout << "Deleted from front: " << front->data << endl;
		front = front->next;

		if (front == nullptr) { //make deque empty
			rear = nullptr;
		}
		else {
			front->prev = nullptr;
		}
		delete toDelete;
		return;
	};

	void DeleteRear(){
		if (front == nullptr) { //if empty
			cout << "Deque is empty" << endl;
			return;
		}
		node* toDelete = rear;
		cout << "Deleted from rear: " << rear->data << endl;
		rear = rear->prev;

		if (rear == nullptr) { //make deque empty
			front = nullptr;
		}
		else {
			rear->next = nullptr;
		}
		delete toDelete;
		return;
	};

	bool IsEmpty() {
		return front == nullptr;
	};

	void Display() {
		if (front == nullptr) {
			cout << "Deque empty" << endl;
			return;
		}
		cout << "FRONT" << endl;
		for (node* i = front; i != nullptr; i = i->next) {
			cout << i->data << endl;
		}
		cout << "REAR" << endl;
	};

	void ClearDeque() {
		if (front == nullptr) {
			cout << "Deque Empty" << endl;
			return;
		}
		while (front != nullptr) {
			node* temp = front;
			front = front->next;
			delete temp;
		}
		rear = nullptr;
	}
};

int main() {
	LinkedDeque dq;

	int choice;
	int val;
	do {
		cout << endl << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nChoice: ";
		if (!(cin >> choice)) {
			cout << "Invalid input" << endl;
			break;
		}
		switch (choice) {
		case 1:
			cout << "Enter value: ";
			cin >> val;
			dq.InsertFront(val);
			break;
		case 2:
			cout << "Enter value: ";
			cin >> val;
			dq.InsertRear(val);
			break;
		case 3:
			dq.DeleteFront();
			break;
		case 4:
			dq.DeleteRear();
			break;
		case 5:
			dq.Display();
			break;
		case 6:
			dq.ClearDeque();
			cout << "Exiting.." << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 6);

	return 0;
}
