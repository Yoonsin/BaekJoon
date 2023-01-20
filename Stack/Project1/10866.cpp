#include <iostream>
#include <string>
using namespace std;

#define MAX_QUEUE_SIZE 10001

class Deque {
	int data[MAX_QUEUE_SIZE];
	int front, rear;
public:
	Deque() {
		this->front = 0;
		this->rear = 0;
	}
	void push_front(int element);
	void push_back(int element);
	int pop_front();
	int pop_back();
	int size();
	bool empty();
	int front_f();
	int back_f();
};

void Deque::push_front(int element) {
	this->data[this->front] = element;
	this->front = (this->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void Deque::push_back(int element) {
	this->rear = (this->rear + 1) % MAX_QUEUE_SIZE;
	this->data[this->rear] = element;
}

int Deque::pop_front() {
	if (empty())
		return -1;
	else {
		this->front = (this->front + 1) % MAX_QUEUE_SIZE;
		return this->data[this->front];
	}
}

int Deque::pop_back() {
	if (empty())
		return -1;
	else {
		int tmp = this->data[this->rear];
		this->rear = (this->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		return tmp;
	}
}

int Deque::size() {
	return (this->rear - this->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

bool Deque::empty() {
	return (this->rear == this->front);
}

int Deque::front_f() {
	if (empty())
		return -1;
	else {
		return this->data[(this->front + 1) % MAX_QUEUE_SIZE ];
	}
}

int Deque::back_f() {
	if (empty())
		return -1;
	else {
		return this->data[this->rear];
	}
}

int main(int argc, char** argv) {
	Deque q;
	string str;

	int n; //test case
	int num; //element
	cin >> n;

	while (n--)
	{
		cin >> str;
		if (str == "push_front") {
			cin >> num;
			q.push_front(num);
		}
		else if (str == "push_back") {
			cin >> num;
			q.push_back(num);
		}
		else if (str == "pop_front") {
			cout << q.pop_front() << endl;
		}
		else if (str == "pop_back") {
			cout << q.pop_back() << endl;
		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "empty") {
			cout << q.empty() << endl; 
		}
		else if (str == "front") {
			cout << q.front_f() << endl;
		}
		else if (str == "back") {
			cout << q.back_f() << endl;
		}
	}
	
	
	return 0;
}