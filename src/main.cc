#include "gd.hpp"
#include <fstream>
#include <iostream>

int main() {
    float learningRate = 0.005;
    float gradient = 0.5;
    float intercept = 0.0;
    Gd Gd(learningRate, gradient, intercept);
    float xCoord;
    float yCoord;
    std::ifstream xin("x.bin", std::ios::binary);
    std::ifstream yin("y.bin", std::ios::binary);
    while (xin.read(reinterpret_cast<char *>(&xCoord), sizeof(float)) && yin.read(reinterpret_cast<char *>(&yCoord), sizeof(float))) {
        Gd.Update(xCoord, yCoord);
        Gd.Dump();
    }
    return 0;
}