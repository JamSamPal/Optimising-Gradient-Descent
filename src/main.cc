#include "gd.hpp"
#include <fstream>
#include <iostream>

int main() {
    float learningRate = 0.1;
    Gd Gd(learningRate);
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