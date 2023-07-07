/*
  ==============================================================================

    SynthSound.h
    Created: 1 Mar 2023 6:48:57pm
    Author:  Luke Evans

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound

{
public:
    bool appliesToNote (int midiNoteNumber) override { return true; }
    bool appliesToChannel (int midiChannel) override { return true; }
};
