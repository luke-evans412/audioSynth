/*
  ==============================================================================

    OscEffect.h
    Created: 14 Apr 2023 1:04:50am
    Author:  Luke Evans

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OscEffect : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay (juce::dsp::ProcessSpec& spec);
    void setWaveType (const int choice);
    void setFreq (const int midiNoteNumber);
    void getNextAudioBlock (juce::dsp::AudioBlock<float>& block);
    void updateFm (const float freq, const float depth);
    
private:
    void processFmOsc (juce::dsp::AudioBlock<float>& block);
    
    juce::dsp::Oscillator<float> fmOsc { [](float x) { return std::sin (x); } };
    float fmMod { 0.0f };
    float fmDepth { 0.0f };
    int lastMidiNote { 0 };
};
