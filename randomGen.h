//Header file for class to generate random numbers between set limits
class randomGen{
    public:
        randomGen(int seed);

        int getSeed();

        void setSeed(int newSeed);

        double getRandom(double, double);

   private:
        int seed;

        unsigned int lastRandom;

        int multiplier;

        int constant;

        int modulo;



};
