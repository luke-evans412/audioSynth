/*
  ==============================================================================

    OscComponent.h
    Created: 20 Apr 2023 1:05:04am
    Author:  Luke Evans

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class OscComponent : public juce::Slider
{

public:
    OscComponent (juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId, juce::String fmFreqId, juce::String fmDepthId);
    ~OscComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox oscWaveSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscWaveSelectorAttachment;
    
    juce::Slider fmFreqSlider;
    juce::Slider fmDepthSlider;

    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    std::unique_ptr<Attachment> fmFreqAttachment;
    std::unique_ptr<Attachment> fmDepthAttachment;
    
    juce::Label waveSelectorLabel { "Wave Type", "Waveform" };
    juce::Label fmFreqLabel { "FM Freq", "Frequency" };
    juce::Label fmDepthLabel { "FM Depth", "Depth" };
    
    void setSliderWithLabel (juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& attachment);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscComponent)
};
