#include <vector>

namespace Statistics
{
    // define the Stats structure here. See the tests to infer its properties
    struct Stats
    {
        float average;
        float max;
        float min;
    };

    Stats ComputeStatistics(const std::vector<float> &);
}
class IAlerter
{
public:
    virtual void sendAlert() = 0;
}

class EmailAlert::public IAlerter
{
public:
    bool emailSent = false;

public:
    virtual void sendAlert() override;
}

class LEDAlert::public IAlerter
{
public:
    bool ledGlows = false;

public:
    virtual void sendAlert() override;
}

class StatsAlerter
{
public:
    float maxThreshold;
    std::vector<IAlerter> alerters;

public:
    StatsAlerter(float maxThreshold, std::vector<IAlerter> alerters) : maxThreshold(maxThreshold), alerters(alerters) {}
    void checkAndAlert(std::vector<float> &dataVector);
}
