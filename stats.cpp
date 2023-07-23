#include "stats.h"
#include "numeric"
#include "algorithm"

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float> &dataVector)
{
    Statistics::Stats statsObj;

    if (dataVector.empty())
    {
        statsObj.average = NAN;
        statsObj.max = NAN;
        statsObj.min = NAN;
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