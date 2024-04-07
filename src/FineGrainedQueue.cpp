#include "FineGrainedQueue.h"

FineGrainedQueue::FineGrainedQueue()
{
	begin = nullptr;
	end = nullptr;
	qSize = 0;
	queue_mutex = new std::mutex;
}
FineGrainedQueue::~FineGrainedQueue()
{
	clear();
	delete queue_mutex;
}

void FineGrainedQueue::push_back(int value)
{
	Node* newNode = new Node(value);
	queue_mutex->lock();
	if (begin == nullptr)
	{
		begin = newNode;
		end = newNode;
		queue_mutex->unlock();
		qSize++;
		return;
	}
	else
	{
		end->next = newNode;
		end = newNode;
		queue_mutex->unlock();
		qSize++;
		return;
	}
}

void FineGrainedQueue::show()
{
	if (qSize == 0)
	{
		std::cout << "Queue is empty" << std::endl;
	}
	else
	{
		Node* cur = begin;
		int i = 1;
		while (cur)
		{
			std::cout << "For node #" << i << " value is " << cur->value << std::endl;
			i++;
			cur = cur->next;
		}
	}
}

void FineGrainedQueue::insertIntoMiddle(int value, int pos)
{
	if (pos > qSize)
	{
		this->push_back(value);
		return;
	}

	Node* newNode = new Node(value);
	Node *cur, *prev;
	int curPos = 2;

	queue_mutex->lock();

	prev = begin;
	cur = begin->next;

	prev->node_mutex->lock();
	if (cur)
	{
		cur->node_mutex->lock();
	}	
	queue_mutex->unlock();

	while (curPos < pos && cur->next != nullptr)
	{
		Node* old = prev;
		prev = cur;
		old->node_mutex->unlock();
		cur = cur->next;
		if (cur)
		{
			cur->node_mutex->lock();
		}
		curPos++;
	}

	prev->next = newNode;
	newNode->next = cur;
	prev->node_mutex->unlock();
	cur->node_mutex->unlock();
	qSize++;
}

size_t FineGrainedQueue::size()
{
	return qSize;
}

void FineGrainedQueue::clear()
{
	queue_mutex->lock();
	Node* current = nullptr;
	while (begin != nullptr)
	{
		current = begin;
		begin = begin->next;
		delete current;
		qSize--;
	}
	queue_mutex->unlock();
}