/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

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
    
    void sliderValueChanged(juce::Slider * slider);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthCodeAudioProcessor& audioProcessor;
    
    juce::Image bgImage;
    
    juce:: Slider slider1;
    
    juce::LookAndFeel_V3 lookAndFeel3;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthCodeAudioProcessorEditor)
};
