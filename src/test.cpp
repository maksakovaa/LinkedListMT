#include "test.h"

test::test()
{
    que = new FineGrainedQueue();
    que->show();
    fillQueue();
}

test::~test()
{
    delete que;
}

void test::fillQueue()
{
   	for (size_t i = 0; i < queue_len; i++)
	{
		que->push_back(gen.getNum());
	}
    std::cout << "Filled queue. Now it contains " << que->size() << " elements" << std::endl;
	que->show();
}

void test::setDefValues()
{
    val1 = 1111;
    val2 = 2222;
    val3 = 3333;
    pos1 = 2;
    pos2 = 5;
    pos3 = 90;
}

void test::setUsrValues()
{
    std::cout << "Enter first value to insert:" << std::endl;
	std::cin >> val1;
	std::cout << "Enter pos where insert first value:" << std::endl;
	std::cin >> pos1;

	std::cout << "Enter second value to insert:" << std::endl;
	std::cin >> val2;
	std::cout << "Enter pos where insert second value:" << std::endl;
	std::cin >> pos2;

	std::cout << "Enter third value to insert:" << std::endl;
	std::cin >> val3;
	std::cout << "Enter pos where insert third value:" << std::endl;
	std::cin >> pos3;
}

void test::mt_run()
{

    std::future<void> ins1 = std::async(std::launch::async, &FineGrainedQueue::insertIntoMiddle, que, val1, pos1);
    std::future<void> ins2 = std::async(std::launch::async, &FineGrainedQueue::insertIntoMiddle, que, val2, pos2);
    std::future<void> ins3 = std::async(std::launch::async, &FineGrainedQueue::insertIntoMiddle, que, val3, pos3);
	
	ins1.wait();
	ins2.wait();
	ins3.wait();

    std::cout << "Queue after 3 multithread insert operations. Now it contains " << que->size() << " elements" << std::endl;
	que->show();
}

void test::runDefault()
{
    setDefValues();
    mt_run();
    que->clear();
    std::cout << "Queue after clear. Contain " << que->size() << " elements" << std::endl;
    que->show();
}

void test::runUserParams()
{
    setUsrValues();
    mt_run();
}