#include "MessageDispatcher.hpp"
#include <iostream>
using namespace std;

class myMessage:public Message
{
public:
	myMessage():Message("sendMsg")
	{
	}
};

class A
{
public:
	MessageDispatcher *m_dispatcher;
public:
	A();
	A(MessageDispatcher *dispatcher);
	~A();
	void send();

private:

};

A::A()
{
}

A::A(MessageDispatcher *dispatcher)
{
	m_dispatcher = dispatcher;
}

A::~A()
{
}

void A::send()
{
	myMessage mymsg;
	m_dispatcher->dispatchMessage(mymsg);
}

class B
{
public:
	MessageDispatcher *m_dispatcher;
public:
	B();
	B(MessageDispatcher *dispatcher);
	~B();

	static void mymsgCallback(const Message& msg);

private:

};

B::B()
{
}

B::B(MessageDispatcher *dispatcher)
{
	myMessage mymsg;
	m_dispatcher = dispatcher;
	dispatcher->addMessageListener(mymsg.type, mymsgCallback);
}

B::~B()
{
}

void B::mymsgCallback(const Message& msg)
{
	cout << "void B::mymsgCallback(const Message& msg)";
}

int main()
{
	MessageDispatcher dispatcher;
	A a(&dispatcher);
	B b(&dispatcher);
	a.send();
	
}