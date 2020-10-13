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
float threshold_value = 15;
float weight1 = 10;
float weight2 = -10;

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

float linearFunction(float x) {
    cout << "[:)] Running with Linear Function as Activation Function." << endl;
    return x;

}

float thresholdFunction(float x) {
    float threshold = 0;
    if (x >= 0) {
        threshold = 1;
    } else if (x < 0) {
        threshold = 0;
    }
    cout << "[:)] Running with Threshold Function as Activation Function." << endl;
    return threshold;
}

float sigmoidFunction(float x) {
    float exponential;
    float sigmoid;
    exponential = exp(-x);
    sigmoid = 1 / (1 + exponential);
    cout << "[:)] Running with Sigmoid Function as Activation Function." << endl;
    return sigmoid;
}

void setWeights(float weight_1, float weight_2) {
    weight1 = weight_1;
    weight_2 = weight_2;
}

void setThreshold(float threshold) {
    threshold_value = threshold;
}

int throwActivationFunction(string activeFunc) {
    int switchCase = 0;
    string actFunc = move(activeFunc);
    if (actFunc == "sigmoid" || actFunc.empty()) {
        switchCase = 0;
    } else if (actFunc == "linear") {
        switchCase = 1;
    } else if (actFunc == "threshold") {
        switchCase = 2;
    } else {
        switchCase = 0;
    }
    return switchCase;
}

float notGate(float input, const string &activationFunction) {

    float answer;
    float calc;
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
            break;
        case 1:
            answer = linearFunction(calc);
            break;
        case 2:
            answer = thresholdFunction(calc);
            break;
    }

    cout << "Computing with weights:" << weight1 << " and Threshold Value:" << threshold_value << endl;
    return answer;
}

#endif //BIN_MCCULLOCHPITTS_NEURONMODEL_H