/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthCodeAudioProcessorEditor::SynthCodeAudioProcessorEditor (SynthCodeAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    
    
    setSize (400, 300);
    
    bgImage = juce::ImageCache::getFromMemory(BinaryData::background_png,BinaryData::background_pngSize);
    
    
   
    
    
    slider1.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    slider1.setBounds(25,25,100,100);
    slider1.setRange(0,12,0.1);
    slider1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 0, 0);
    slider1.setLookAndFeel(&lookAndFeel3);
    addAndMakeVisible(slider1);
    
}

SynthCodeAudioProcessorEditor::~SynthCodeAudioProcessorEditor()
{
}

//==============================================================================
void SynthCodeAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.drawImageAt(bgImage,0,0);
    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("", getLocalBounds(), juce::Justification::centred, 1);
}

void SynthCodeAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void SynthCodeAudioProcessorEditor::sliderValueChanged(juce::Slider * slider)
{
    auto value = slider->getValue();
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

