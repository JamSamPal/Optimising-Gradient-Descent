#include "gd.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

Gd::Gd(const float &learningRate, float &gradient, float &intercept) : learningRate_(learningRate), gradient_(gradient), intercept_(intercept) {};

void Gd::Update(const float &xCoord, const float &yCoord) {
    float error = GetError_(xCoord, yCoord);
    float gradCorrection = GetGradUpdate_(xCoord, error);
    float interceptCorrection = -2 * error;
    gradient_ -= learningRate_ * gradCorrection;
    intercept_ -= learningRate_ * interceptCorrection;

    if (iteration_ % 20 == 0) {
        std::cout << "Iteration " << iteration_ << " Error: " << error << std::endl;
        std::cout << "Iteration " << iteration_ << " gradient: " << gradient_ << std::endl;
        std::cout << "Iteration " << iteration_ << " gradient: " << intercept_ << std::endl;
    }
    iteration_ += 1;
}

float Gd::GetError_(const float &xCoord, const float &yCoord) { return yCoord - (gradient_ * xCoord + intercept_); }

float Gd::GetGradUpdate_(const float &xCoord, const float &error) { return -2 * xCoord * error; }

void Gd::Dump() {

    std::ofstream gradfile("gradients.csv", std::ios::out | std::ios::app);
    if (gradfile.is_open()) {
        gradfile << gradient_ << "\n";
        gradfile.close();
    }

    std::ofstream interceptfile("intercepts.csv", std::ios::out | std::ios::app);
    if (interceptfile.is_open()) {
        interceptfile << intercept_ << "\n";
        interceptfile.close();
    }
}