/*
  ==============================================================================

    AdsrEffect.cpp
    Created: 14 Apr 2023 12:52:48am
    Author:  Luke Evans

  ==============================================================================
*/

#include "AdsrEffect.h"
void AdsrEffect::update (const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;
    setParameters(adsrParams);
}
