CC=g++
#CFLAGS=-c -g -Wall -pthread -m64 -I/home/mark/Documents/PHD/snoing/install/root-5.34.30/include/
#LDFLAGS=-L/home/mark/Documents/PHD/snoing/install/root-5.34.30/lib -lGui -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic
LDFLAGS=`root-config --glibs`
CFLAGS=-c -g -Wall `root-config --cflags`


main: 
	$(CC) $(CFLAGS) -o randomGen.o randomGen.cpp
	$(CC) $(CFLAGS)  -o centralLimitWithROOT.o  centalLimitWithROOT.cpp
	$(CC) randomGen.o centralLimitWithROOT.o $(LDFLAGS) -o main

clean:
	rm ./main *.o
