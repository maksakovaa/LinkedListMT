#include <iostream>
#include <future>
#include "randomGen.h"
#include "FineGrainedQueue.h"

class test
{
private:
    int val1, val2, val3, pos1, pos2, pos3;
    RandomGen gen;
    FineGrainedQueue* que;
    size_t queue_len = 10;
    void fillQueue();
    void setUsrValues();
    void mt_run();
    void setDefValues();
public:
    test();
    ~test();
    void runDefault();
    void runUserParams();
};