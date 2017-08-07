// Message class
#include <string>
using namespace std;

class Message
{
public:
	Message(const string &type, bool bubbles = false, bool cancelable = false) :
		type(type), bubbles(bubbles), cancelable(cancelable)
	{
	}
	const string type;
	const bool bubbles;
	const bool cancelable;
	/*
	const void* target;
	const unsigned int messagePhase;
	const void* currentTarget;
	*/

};
// Message function callback pointer type
typedef void(*messageFunctionPtr)(const Message &);