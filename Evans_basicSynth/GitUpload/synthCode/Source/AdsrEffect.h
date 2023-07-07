/*
  ==============================================================================

    AdsrEffect.h
    Created: 14 Apr 2023 12:52:48am
    Author:  Luke Evans

  ==============================================================================
*/

#pragma once

#pragma once

#include <JuceHeader.h>

class AdsrEffect : public juce::ADSR
{
public:
    void update (const float attack, const float decay, const float sustain, const float release);
    
    
private:
    juce::ADSR::Parameters adsrParams;
};
