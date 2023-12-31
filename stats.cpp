#include "stats.h"
#include "numeric"
#include "algorithm"
#include <limits>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float> &dataVector)
{
    Statistics::Stats statsObj;

    if (dataVector.empty())
    {
        statsObj.average = std::numeric_limits<double>::quiet_NaN();
        statsObj.max = std::numeric_limits<double>::quiet_NaN();
        statsObj.min = std::numeric_limits<double>::quiet_NaN();
    }
    else
    {
        statsObj.average = std::accumulate(dataVector.begin(), dataVector.end(), 0.0) / dataVector.size();
        statsObj.max = *(std::max_element(dataVector.begin(), dataVector.end()));
        statsObj.min = *(std::min_element(dataVector.begin(), dataVector.end()));
    }

    return statsObj;
}

void EmailAlert::sendAlert()
{
    emailSent = true;
}

void LEDAlert::sendAlert()
{
    ledGlows = true;
}

void StatsAlerter::checkAndAlert(std::vector<float> dataVector)
{
    for (float value : dataVector)
    {
        if (value > maxThreshold)
        {
            for (IAlerter *alerter : alerters)
            {
                alerter->sendAlert();
            }
            break;
        }
    }
}