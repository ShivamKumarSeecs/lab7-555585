// Shivam Kumar 555585
// BSCS-15-D

#include <iostream>
using namespace std;


class ArrayQueue {
private: 
	int items[5];
	int head;
	int tail;
public:
	ArrayQueue() { 
		// start at empry queue
		head = -1;
		tail = -1;
	};

	void Enqueue(int value){
		if (tail + 1 >= 5) {
			cout << "Queue is exceeding capacity" << endl;
			return;
		}
		if (tail == -1) head = 0; //if empty then modify head
		items[++tail] = value;
		return;
	};

	void Dequeue(){
		if (head == -1) { //if empty
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "Dequeued: " << items[head++] << endl;
		if (head > tail) { //make queue empty
			head = -1;
			tail = -1;
		}
		return;
	};

	int Peek() {
		return items[head];
	};

	bool IsEmpty() {
		return head == -1;
	};

	bool IsFull() {
		return tail >= 4;
	};

	void Display() {
		if (head == -1) {
			cout << "Queue empty" << endl;
			return;
		}
		cout << "HEAD" << endl;
		for (int i = head; i <= tail; i++) {
			cout << items[i] << endl;
		}
		cout << "TAIL" << endl;
	};
};

int main() {
	ArrayQueue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Enqueue(40);
	q.Enqueue(50);
	q.Dequeue();
	q.Dequeue();
	q.Enqueue(60);
	q.Display();
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Enqueue(70);
	return 0;
}
