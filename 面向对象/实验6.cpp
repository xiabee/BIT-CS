#include<iostream>
using namespace std;
class Stack {
	struct Link {
		void* data;
		Link* next;
		Link(void* dat, Link* nxt);
		~Link();
	}*head;
public:
	Stack();
	~Stack();
	void push(void* dat);
	void* peek();
	void* pop();
	void require(bool a, const char* b)
	{
		if (a == true)
			cout << b << endl;
	}
};
Stack::Link::Link(void* dat, Link* nxt) {
	cout << "Link Constructor" << endl;
	data = dat;
	next = nxt;
}//Link构造函数

//-----------------Link析构函数-----------------------------------
Stack::Link::~Link()
{
	data = NULL;
	next = NULL;
	cout << "Link Destructor" << endl;
}
//-------------------------------------------------------------------

Stack::Stack()
{
	cout << "Stack Constructor" << endl;
	head = 0;
}//Stack构造函数

//---------------Stack析构函数--------------------------------------
Stack::~Stack() {
	require(head != 0, "Stack not empty");
	while (head)
		pop();
	cout << "Stack Destructor" << endl;
}
//-------------------------------------------------------------------

void Stack::push(void* dat) {
	head = new Link(dat, head);
}

void* Stack::peek() {
	require(head != 0, "Stack empty");
	return head->data;
}

void* Stack::pop() {
	if (head == 0) return 0;
	void* result = head->data;
	Link* oldHead = head;
	head = head->next;
	delete oldHead;
	return result;
}


int main() {
	Stack s;
	void* x = (void*)'sss';
	s.push(x);
	cout << s.peek() << endl;
	return 0;
}

// output:
// Stack Constructor
// Link Constructor
// Stack empty
// 0000000000737373
// Stack not empty
// Link Destructor
// Stack Destructor