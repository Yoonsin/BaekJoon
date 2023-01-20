//¼±ÇüÅ¥
#include <iostream>
#define MAX_QUEUE_SIZE 10001
using namespace std;

class Queue {
	int front_n;
	int rear;
	int data[MAX_QUEUE_SIZE];
public:
	Queue() {
		this->front_n = -1;
		this->rear = -1;
	}
	void push(int data);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
};



void Queue::push(int data) {
	if (rear == MAX_QUEUE_SIZE - 1) return;
	else {
		this->rear++;
		this->data[this->rear] = data;
	}
}

int Queue::front() {
	if (empty())return -1;
	return this->data[this->front_n + 1];
}

int Queue::back() {
	if (empty())return -1;
	return this->data[this->rear];
}

int Queue::pop() {
	if (empty()) return -1;
	else {
		this->front_n++;
		int item = this->data[this->front_n];
		return item;
	}
}

int Queue::size() {
	return (this->rear - this->front_n);
}

bool Queue::empty() {
	if (this->front_n == this->rear) return 1;
	else return 0;
}


int main(int argc, char** argv) {
	Queue q;
	int t;

	
	
	cin >> t;

	while (t--) {
		string str;
		
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			q.push(n);
		}
		else if (str == "front") {
			cout << q.front() << endl;
		}
		else if (str == "back") {
			cout  << q.back() << endl;
		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "pop") {
			cout << q.pop() << endl;
		}
		else if (str == "empty") {
			cout << q.empty() << endl;
		}
	}
	
	return 0;
}