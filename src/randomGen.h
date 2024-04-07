#include <random>

class RandomGen
{
public:
    RandomGen()
    {
        r_gen.seed(rd());
    }
    ~RandomGen() {}
    int getNum()
    {
 		std::uniform_int_distribution<int> range(0, 800);
		range(r_gen);
        return range(r_gen);
    }
private:
	std::random_device rd;
	std::mt19937 r_gen;
};