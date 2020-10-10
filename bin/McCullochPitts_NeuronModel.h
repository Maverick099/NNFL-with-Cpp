//
// Created by Adithya aka Maverick099 on 09-10-2020.
//

/// This is a simple neural model based on the McCulloch and Pits model 1943
/// This model is used to implement simple gates such as logical and, or and not

#ifndef BIN_MCCULLOCHPITTS_NEURONMODEL_H
#define BIN_MCCULLOCHPITTS_NEURONMODEL_H

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <utility>

using namespace std;

// Default weight and threshold values
unsigned int threshold_value = 15;
unsigned int weight1 = -10;
unsigned int weight2 = 10;
string activationFunc;

string transformToLowerCase(string text) {
    string returnText;
    int len = text.length();
    for (int i = 0; i < len; i++) {
        returnText[i] = tolower(text[i]);
    }
    cout << returnText << endl;
    return returnText;
}


/// Different Activation function
// 0) Linear Activation function
// 1) Threshold Activation function
// 2) Sigmoid Activation function
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

void setWeights(unsigned int weight_1, unsigned int weight_2) {
    weight1 = weight_1;
    weight_2 = weight_2;
}


int throwActivationFunction(string activeFunc) {
    int switchCase = 0;
    string actFunc = move(activeFunc);
    if (actFunc == "sigmoid" || actFunc.empty()) {
        switchCase = 0;
        cout << "[:)] Running with Sigmoid Function as Activation Function." << endl;
    } else if (actFunc == "linear") {
        switchCase = 1;
        cout << "[:)] Running with Linear Function as Activation Function." << endl;
    } else if (actFunc == "threshold") {
        switchCase = 2;
        cout << "[:)] Running with Threshold Function as Activation Function." << endl;
    }

    return switchCase;
}

int notGate(int input, const string &activationFunction) {

    int answer;
    unsigned calc;
    const string &actFunc = activationFunction;
    try {
        if (input == 1 || input == 0) {

        } else {
            throw 101;
        }
    }
    catch (int err) {
        cout << "[!] Error: Input for not gate should be Binary, either 1 or 0." << endl << "Exited with error code:"
             << err << endl;
    }

    calc = (weight1 * input) - threshold_value;

    switch (throwActivationFunction(actFunc)) {
        case 0:
            answer = sigmoidFunction(calc);
        case 1:
            answer = linearFunction(calc);
        case 2:
            answer = thresholdFunction(calc);
    }

    return answer;
}


int andGate(int input1, int input2) {

    return 0;
}


#endif //BIN_MCCULLOCHPITTS_NEURONMODEL_H