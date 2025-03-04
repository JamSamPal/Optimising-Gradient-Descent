#include "gd.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

Gd::Gd(const float &learningRate) : learningRate_(learningRate) {};

void Gd::Update(const float &xCoord, const float &yCoord) {
    float error = GetError_(xCoord, yCoord);
    float gradCorrection = GetGradUpdate_(xCoord, error);
    float interceptCorrection = -2 * error;
    gradient_ -= learningRate_ * gradCorrection;
    intercept_ -= learningRate_ * interceptCorrection;
}

float Gd::GetError_(const float &xCoord, const float &yCoord) { return yCoord - (gradient_ * xCoord + intercept_); }

float Gd::GetGradUpdate_(const float &xCoord, const float &error) { return -2 * xCoord * error; }

void Gd::Dump() {

    std::ofstream gradfile("gradients.bin", std::ios::binary | std::ios::app);
    if (gradfile.is_open()) {
        gradfile.write(reinterpret_cast<char *>(&gradient_), sizeof(gradient_));
        gradfile.close();
    }

    std::ofstream interceptfile("intercepts.bin", std::ios::binary | std::ios::app);
    if (interceptfile.is_open()) {
        interceptfile.write(reinterpret_cast<char *>(&intercept_), sizeof(intercept_));
        interceptfile.close();
    }
}