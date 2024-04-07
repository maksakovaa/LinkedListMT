#include "Node.h"
#include <iostream>
#include <atomic>

class FineGrainedQueue
{
public:
	FineGrainedQueue();
	~FineGrainedQueue();
	void push_back(int value);
	void show();
	void insertIntoMiddle(int value, int pos);
	size_t size();
	void clear();
private:
	Node* begin;
	Node* end;
	std::atomic<size_t> qSize;
	std::mutex* queue_mutex;
};