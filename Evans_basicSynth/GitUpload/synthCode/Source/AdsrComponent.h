/*
  ==============================================================================

    AdsrComponent.h
    Created: 20 Apr 2023 12:52:16am
    Author:  Luke Evans

  ==============================================================================
*/

#include <JuceHeader.h>


class AdsrComponent  : public juce::Component
{
public:
    AdsrComponent (juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId);
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    void setSliderWithLabel (juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& attachment);
    
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;
    
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;
    
    juce::Label attackLabel { "Attack", "Attack" };
    juce::Label decayLabel { "Decay", "Decay" };
    juce::Label sustainLabel { "Sustain", "Sustain" };
    juce::Label releaseLabel { "Release", "Release" };
    
    juce::String componentName {""};
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};