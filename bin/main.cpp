#include <iostream>
#include "McCullochPitts_NeuronModel.h"
using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    setWeights(-15,-15);
    cout<< notGate(0,"linear");
    return 0;
}