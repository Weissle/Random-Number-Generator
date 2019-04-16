#pragma once
#include<random>

namespace rg {

	//PROBILITY is form 0 to 1 ,meanly
	enum RANDOMMODEL { NORMAL = 1, MEANLY = 2, PROBILITY = 3, NOREPEATINT = 4 };
	class RandomGenerator
	{
		RANDOMMODEL RM;
		std::normal_distribution<double> normalDistribution;
	public:
		RANDOMMODEL getRandomModelType();
		virtual double getOne();
		virtual RandomGenerator& operator >> (double &num);
		virtual RandomGenerator& operator >> (int &num);
		RandomGenerator(RANDOMMODEL _RM);
		RandomGenerator() {};
		~RandomGenerator() {};
	};
	class NormalRandomGenerator :public RandomGenerator {

		double mean, variance;
		std::normal_distribution<double> normalDistribution;
		std::default_random_engine generator;
	public:
		NormalRandomGenerator(double _mean, double _variance, bool seed = true);
		NormalRandomGenerator() :RandomGenerator(RANDOMMODEL::NORMAL) {};
		~NormalRandomGenerator() {};
		double getOne();
	};
	class MeanlyRandomGenerator :public RandomGenerator {
		double min, max, dis;
	public:
		double getOne();
		MeanlyRandomGenerator(double _min, double _max);
		MeanlyRandomGenerator() :RandomGenerator(RANDOMMODEL::MEANLY) {};
		~MeanlyRandomGenerator() {};
	};
	class ProbilityRandomGenerator :public RandomGenerator {
	public:
		double getOne();
		ProbilityRandomGenerator() :RandomGenerator(RANDOMMODEL::PROBILITY) {};
		~ProbilityRandomGenerator() {};
	};
	class NoRepeatIntRandomGenerator : public RandomGenerator {
		int top = 0;
		int *p;
	public:
		NoRepeatIntRandomGenerator() :RandomGenerator(RANDOMMODEL::PROBILITY) {};
		~NoRepeatIntRandomGenerator() {
			delete []p;
		};
		NoRepeatIntRandomGenerator(int max);
		double getOne();
	};

}
