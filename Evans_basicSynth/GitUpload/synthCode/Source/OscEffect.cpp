/*
  ==============================================================================

    OscEffect.cpp
    Created: 14 Apr 2023 1:04:50am
    Author:  Luke Evans

  ==============================================================================
*/


#include "OscEffect.h"

void OscEffect::prepareToPlay (juce::dsp::ProcessSpec& spec)
{
    prepare (spec);
    fmOsc.prepare (spec);
}

void OscEffect::setWaveType (const int choice)
{
    switch (choice)
    {
        case 0:
            // Sine
            initialise ([](float x) { return std::sin (x); });
            break;
            
        case 1:
            // Saw wave
            initialise ([](float x) { return x / juce::MathConstants<float>::pi; });
            break;
            
        case 2:
            // Square wave
            initialise ([](float x) { return x < 0.0f ? -1.0f : 1.0f; });
            break;
            
        default:
            jassertfalse;   // You're not supposed to be here!
            break;
    }
}

void OscEffect::setFreq (const int midiNoteNumber)
{
    setFrequency (juce::MidiMessage::getMidiNoteInHertz (midiNoteNumber) + fmMod);
    lastMidiNote = midiNoteNumber;
}

void OscEffect::getNextAudioBlock (juce::dsp::AudioBlock<float>& block)
{
    processFmOsc (block);
    process (juce::dsp::ProcessContextReplacing<float> (block));
}

void OscEffect::processFmOsc (juce::dsp::AudioBlock<float>& block)
{
    for (int ch = 0; ch < block.getNumChannels(); ++ch)
    {
        for (int s = 0; s < block.getNumSamples(); ++s)
        {
            fmMod = fmOsc.processSample (block.getSample (ch, s)) * fmDepth;
        }
    }
}

void OscEffect::updateFm (const float freq, const float depth)
{
    fmOsc.setFrequency (freq);
    fmDepth = depth;
    auto currentFreq = juce::MidiMessage::getMidiNoteInHertz (lastMidiNote) + fmMod;
    setFrequency (currentFreq >= 0 ? currentFreq : currentFreq * -1.0f);
}

