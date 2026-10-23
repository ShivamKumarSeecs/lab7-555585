// Shivam Kumar 555585
// BSCS-15-D

#include <iostream>
using namespace std;

class CircularQueue {
private:
	int items[5];
	int head;
	int tail;
public:
	CircularQueue() {
		head = -1;
		tail = -1;
	};

	void Enqueue(int value){
		if ((tail + 1) % 5 == head) {
			cout << "Queue is exceeding capacity" << endl;
			return;
		}
		if (head == -1) {
			head = 0;
			tail = 0;
		}
		else {
			tail = (tail + 1) % 5;
		}
		items[tail] = value;
		return;
	};

	void Dequeue(){
		if (head == -1) {
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "Dequeued: " << items[head] << endl;
		if (head == tail) {
			head = -1;
			tail = -1;
		}
		else {
			head = (head + 1) % 5;
		}
		return;
	};

	int Peek() {
		if (head == -1) {
			cout << "Queue is empty" << endl;
			return -1;
		}
		return items[head];
	};

	bool IsEmpty() {
		return head == -1;
	};

	bool IsFull() {
		return (tail + 1) % 5 == head;
	};

	void Display() {
		if (head == -1) {
			cout << "Queue empty" << endl;
			return;
		}
		cout << "HEAD" << endl;
		int i = head;
		while (true) {
			cout << items[i] << endl;
			if (i == tail) break;
			i = (i + 1) % 5;
		}
		cout << "TAIL" << endl;
	};
};

int main() {
	CircularQueue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Enqueue(40);
	q.Enqueue(50);
	q.Dequeue();
	q.Dequeue();
	q.Enqueue(60);
	q.Enqueue(70);
	q.Display();
	q.Enqueue(80);
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Enqueue(100);
	q.Display();
	return 0;
}
