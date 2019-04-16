# Random-Number-Generator
Randomly generate number in c++
## Four Kinds of Random Model
    Normal Distribution Model // Gaussian Distribution 
    No Repeat Integer Model   // from 0 to n-1 integer
    Meanly Distribution Model // from min to max 
    Probility Random Model    // meanly distribution from 0 to 1 
## API
### Constructor Function
     //Most of time,the third parameter(seed) should be set to true, unless you want a changeless sequence.
    NormalRandomGenerator(double mean, double variance, bool seed = true);
    //Very easy to use
    MeanlyRandomGenerator(double min, double max);
    //No need any parameter. 
    ProbilityRandomGenerator(void);
    //Get no repeat integer number from 0 to n-1 and it's time complexity is O(max) ;
    NoRepeatIntRandomGenerator(int max);
### Get The Random Number
    // Using .getOne() or operator >>  will gain a number. Two functions have no difference.
    // Below RG is one of random model instance ;
```c   
double d = RG.getOne();
RG >> d;
int a, b, c;
RG >> a >> b >> c;
```
### Tips
    //If you are not sure which kinds of random model will be used until the program runs, you can refer the tutorial below.
    //Or the third part of test.cpp 
```c
    RandomModel *ranGen;
    if ( /* use Normal Distribution Model */) ranGen = new NormalRandomGenerator(20, 10);
    else if (/* use Meanly Distuibution Model */ ) ranGen = new MeanlyRandomGenerator(10, 20);
    double temp = ranGen->getOne();
```
## About Pseudo Random
    If you want really random number, you should use a random seed such as srand((unsigned int)time(NULL)); 
    When constructing a Normal Distribution Model ,you will not gain really random number if the third parameter not matter have you used a random seed.
