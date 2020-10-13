#include <iostream>
#include "McCullochPitts_NeuronModel.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    setWeights(1, -1);
    setThreshold(1.5);
    cout << "Not Gate Output:" << notGate(1, "linear");
    return 0;
}