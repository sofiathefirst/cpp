#include "Message.hpp"
#include <list>
#include <map>
#include <iostream>
using namespace std;

class MessageDispatcher
{
private:
	map<const string, map<int, list<messageFunctionPtr> > > messageHandlerList;
public:
	void addMessageListener(const string &type, messageFunctionPtr listener, bool useCapture = false, int priority = 0, bool useWeakReference = false)
	{
		// Simply add the message listener to the list of listeners for the selected priority
		messageHandlerList[type][priority].push_back(listener);
	}
	bool hasMessageListener(const string &type)
	{
		return (messageHandlerList.find(type) != messageHandlerList.end());
	}
	void dispatchMessage(const Message &message)
	{
		// Leave if no message registered
		if (!hasMessageListener(message.type))
			return;
		// A reference to keep code clean
		map<int, list<messageFunctionPtr> > &allFunctions = messageHandlerList[message.type];
		// Iterate through all functions in the message, from high proproty to low
		for (map<int, list<messageFunctionPtr> >::reverse_iterator i = allFunctions.rbegin(); i != allFunctions.rend(); ++i) {
			list<messageFunctionPtr> &funcList = i->second;
			// Execute callbacks
			for (list<messageFunctionPtr>::iterator f = funcList.begin(); f != funcList.end(); ++f)
				(*f)(message);
		}
	}
	void removeMessageListener(const string &type, messageFunctionPtr listener, bool useCapture = false)
	{
		// Leave if no message registered
		if (!hasMessageListener(type))
			return;
		// Reference to keep the code clean
		map<int, list<messageFunctionPtr> > &allFunctions = messageHandlerList[type];
		// Since we don't know the function's priority, we'll search for it
		for (map<int, list<messageFunctionPtr> >::iterator i = allFunctions.begin(); i != allFunctions.end(); ++i) {
			// Saving a branch here: instead of checking if the callback exists let remove() do it for us
			i->second.remove(listener);
			// Remove object from the map if list gone empty to eliminate false positives
			if (i->second.empty())
				allFunctions.erase(i);
		}
		// Remove map to eliminate false positives
		if (allFunctions.empty())
			messageHandlerList.erase(type);
	}
};
