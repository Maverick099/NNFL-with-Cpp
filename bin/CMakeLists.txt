cmake_minimum_required(VERSION 3.17)
project(bin)

set(CMAKE_CXX_STANDARD 14)

add_executable(bin main.cpp McCullochPitts_NeuronModel.h PerceptronLearning.h)