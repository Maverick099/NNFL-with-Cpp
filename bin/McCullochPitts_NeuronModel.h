//
// Created by Adithya aka Maverick099 on 09-10-2020.
//

/// This is a simple neural model based on the McCulloch and Pits model 1943
/// This model is used to implement simple gates such as logical and, or and not

#ifndef BIN_MCCULLOCHPITTS_NEURONMODEL_H
#define BIN_MCCULLOCHPITTS_NEURONMODEL_H

#include <cassert>
#include <iostream>
#include <math.h>

using namespace std;

int notGate(int input) {
    assert(input == 1 || input == 0);
    cout << "[!] Input is not equal to 1 or 0" << endl;


    return 0;

}


int andGate(int input1, int input2) {


}

/// Different Activation function
// 1) Linear Activation function
// 2) Threshold Activation function
// 3) Sigmoid Activation function
// the default activation function is kept as sigmoid function.

unsigned linearFunction(unsigned x) {
    return x;
}


int thresholdFunction(unsigned x) {
    int threshold = 0;
    if (x >= 0) {
        threshold = 1;
    } else if (x < 0) {
        threshold = 0;
    }
    return threshold;
}

float sigmoidFunction(float x) {
    float exponential;
    float sigmoid;

    exponential = exp(-x);
    sigmoid = 1 / (1 + exponential);

    return sigmoid;
}

#endif //BIN_MCCULLOCHPITTS_NEURONMODEL_H