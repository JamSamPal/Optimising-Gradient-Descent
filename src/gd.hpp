#ifndef B43377C2_D89E_4908_9FD2_97515BEA2A16
#define B43377C2_D89E_4908_9FD2_97515BEA2A16

class Gd {

public:
    Gd(const float &learningRate, float &gradient, float &intercept);
    void Update(const float &xCoord, const float &yCoord);
    void Dump();

private:
    float gradient_;
    float intercept_;
    int iteration_ = 0;
    const float learningRate_;

    float GetError_(const float &xCoord, const float &yCoord);
    float GetGradUpdate_(const float &xCoord, const float &yCoord);
};
#endif /* B43377C2_D89E_4908_9FD2_97515BEA2A16 */
