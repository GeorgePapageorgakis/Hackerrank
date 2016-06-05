#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>

#include <utility>
#include <chrono>
#include <random>
using namespace std;


int main(){
	pair<int, int> timeRange;
	timeRange.first = 1374037200;
	timeRange.second = 1374037300;


	// mt19937 is a standard mersenne_twister_engine
	std::mt19937 MTEgenerator(timeRange.first);   
	std::cout << "MTE seed produced: " << std::endl;
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << MTEgenerator() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;


	//default_random_engine is a standard linear_congruential_engine
	std::default_random_engine defrand(timeRange.first);
	std::cout << "default_random_engine seed produced: " << std::endl;
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << defrand() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;


	// minstd_rand is a standard linear_congruential_engine
	std::minstd_rand LCEgenerator(timeRange.first);
	std::cout << "LCE seed produced: " << std::endl;
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << LCEgenerator() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;

	// minstd_rand0 is a standard linear_congruential_engine
	std::minstd_rand0 LCEgenerator0(timeRange.first);
	std::cout << "LCE0 seed produced: " << std::endl;
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << LCEgenerator0() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;


	// discard_block_engine is a standard linear_congruential_engine
	std::ranlux24  discard_block_engine24(timeRange.first);
	std::cout << "ranlux24 seed produced: " << std::endl;
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << discard_block_engine24() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;
	std::ranlux48  discard_block_engine48(timeRange.first);
	std::cout << "ranlux48 seed produced: " << std::endl;
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << discard_block_engine48() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;


	//subtract_with_carry_engine example
	std::subtract_with_carry_engine<unsigned, 24, 10, 24> SubwithCarryEng24(timeRange.first);
	std::cout << "SwCE ranlux24_base seed produced: " << std::endl;
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << SubwithCarryEng24() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;


	// shuffle_order_engine constructor example
	std::knuth_b knuth(timeRange.first);
	std::cout << "knuth_b standard shuffle_order_engine seed produced: " << std::endl;
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << knuth() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;


	// random device example
	std::random_device rd;
	std::cout << "random device produced: " << std::endl;
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << rd() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;

	
	//standard
	std::cout << "srand seed produced: " << std::endl;
	srand(timeRange.first);
	for (int i = timeRange.first; i<timeRange.second; ++i) {
		cout << rand() % 1000 << " ";
	}
	std::cout << std::endl << std::endl;


	//seed seq generator
	std::cout << "seed_seq produced: " << std::endl;
	vector<unsigned> v;
	v.resize(timeRange.second - timeRange.first + 1);
	std::seed_seq sedSeq = { 1374037200 };
	sedSeq.generate(v.begin(), v.end());
	for (unsigned x : v) { std::cout << x%1000 << " "; }
	std::cout << std::endl;
	
	// generate canonical
	std::default_random_engine canonical(timeRange.first);


	system("pause");
	return 0;
}
