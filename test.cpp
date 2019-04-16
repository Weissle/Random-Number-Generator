
#include<iostream>
#include<random>
#include<time.h>
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
	
	return 0;
}
