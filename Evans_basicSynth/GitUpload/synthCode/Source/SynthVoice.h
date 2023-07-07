/*
  ==============================================================================

    SynthVoice.h
    Created: 1 Mar 2023 6:48:27pm
    Author:  Luke Evans

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "OscEffect.h"
#include "AdsrEffect.h"

class SynthVoice : public juce::SynthesiserVoice {
    
public:
    bool canPlaySound (juce::SynthesiserSound* sound) override;
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) override;
    void stopNote (float Velocty, bool allowTailOff) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    void renderNextBlock (juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override;
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    void pitchWheelMoved (int newPitchWheelValue) override;
    
    void reset();
    OscEffect& getOscillator() {
        return osc;
        
    }
    
    AdsrEffect& getAdsr() {
        return adsr;
    
    }

    
    
    
private:
    
    OscEffect osc;
    AdsrEffect adsr;
    juce::AudioBuffer<float> synthBuffer;
    juce::dsp::Gain<float> gain;
    bool isPrepared { false };
    
};
