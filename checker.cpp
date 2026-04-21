//checker ptr Polygon
#include "testlib.h"

int main(int argc, char* argv[]) {

        //initializez checker environment
        registerTestlibCmd(argc, argv);

        //programul a sortat bine doar daca primesc ok
        //altfel primesc RE
        quitf(_ok, "Ai sortat bine!");
}