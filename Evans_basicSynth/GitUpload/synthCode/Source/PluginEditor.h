/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AdsrComponent.h"
#include "OscComponent.h"


//==============================================================================
/**
*/
class SynthCodeAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SynthCodeAudioProcessorEditor (SynthCodeAudioProcessor&);
    ~SynthCodeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SynthCodeAudioProcessor& audioProcessor;
    OscComponent osc;
    AdsrComponent adsr;
    juce::Image bgImage;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthCodeAudioProcessorEditor)
};
