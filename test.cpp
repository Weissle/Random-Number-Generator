
#include<iostream>
#include<random>
#include<time.h>
#include <assert.h>
#include"RandomGenerator.h"

using namespace std;
using namespace rg;

void randomModelTest(RandomGenerator &rg, const int testTimes) {
	for (int i = 0; i < testTimes; ++i) {
		cout << rg.getOne() << " ";
	}
	cout << endl;
	return;
}

int main(int argc,char *argv[])
{
	srand((unsigned int)time(NULL));
	NormalRandomGenerator nrg(50, 30);
	randomModelTest(nrg, 20);
	
	MeanlyRandomGenerator mrg(10, 20);
	randomModelTest(mrg, 20);

	NoRepeatIntRandomGenerator nrirg(20);
	randomModelTest(nrirg, 20);

	ProbilityRandomGenerator prg;
	randomModelTest(prg, 20);

	// operator >> test
	double opTest[3];
	nrg >> opTest[0] >> opTest[1] >> opTest[2];
	for (auto temp : opTest) cout << temp << " ";
	cout << endl;
	
	auto norepeatint = NoRepeatIntRandomGenerator(10);
	int opTest2[10];
	for (auto &temp : opTest2)  norepeatint >> temp;
	for (auto temp : opTest2) cout << temp << " ";
	cout << endl;

	// Uncertain Random Model while coding
	RandomGenerator *ranGen;
	cout << "please choose" << endl << "Normal Distribution Model : 1" << endl << "Probility Random Model : 2" << endl;
	int choose;
	cin >> choose;
	assert((choose == 1 || choose == 2) && "you should type in 1 or 2");
	
	if (choose == 1) ranGen = new NormalRandomGenerator(20, 10);
	else if (choose == 2) ranGen = new ProbilityRandomGenerator();

	randomModelTest(*ranGen, 10);
	

	

	return 0;
}
