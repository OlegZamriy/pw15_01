#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stop.h"

using namespace std;

int main() {
    srand(time(0));

    Stop busStop(10.0, 20.0, false, 15, 5.0);

    for (int i = 0; i < 60; ++i) {
        cout << "========== Time " << i << " minutes ==========" << endl;
        busStop.simulate();
        cout << endl;
    }

    return 0;
}
