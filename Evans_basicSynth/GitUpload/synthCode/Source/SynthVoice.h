/*
  ==============================================================================

    SynthVoice.h
    Created: 1 Mar 2023 6:48:27pm
    Author:  Student User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice {
    
public:
    bool canPlaySound (juce::SynthesiserSound* sound) override;
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) override;
    void stopNote (float Velocty, bool allowTailOff) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    void renderNextBlock (juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override;
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    void pitchWheelMoved (int newPitchWheelValue) override;
    
    
private:
    
    
    //sine wave
    //juce::dsp::Oscillator<float> osc { [](float x) { return std::sin (x); }};
    
    //saw wave
    //juce::dsp::Oscillator<float> osc { [](float x) { return x / juce::MathConstants<float>::pi; }};
    
    //square wave
    juce::ADSR adsr;
    juce::ADSR::Parameters adsrParams;
    
    juce::dsp::Oscillator<float> osc { [](float x) { return x < 0.0f ? -1.0f : 1.0f; }};
    
    juce::dsp::Gain<float> gain;
    bool isPrepared { false };
    
    
};
