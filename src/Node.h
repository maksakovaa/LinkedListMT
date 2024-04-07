#include <mutex>

struct Node
{
	Node(int _value) : value(_value), next(nullptr) { node_mutex = new std::mutex; }
	~Node(){ delete node_mutex; }
	int value;
	Node* next;
	std::mutex* node_mutex;
};