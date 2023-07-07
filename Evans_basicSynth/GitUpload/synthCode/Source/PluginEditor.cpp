

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================


//==============================================================================
SynthCodeAudioProcessorEditor::SynthCodeAudioProcessorEditor (SynthCodeAudioProcessor& p)
: AudioProcessorEditor (&p)
, audioProcessor (p)
, osc (audioProcessor.apvts, "OSC1WAVETYPE", "OSC1FMFREQ", "OSC1FMDEPTH")
, adsr ("ADSR Envelope", audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE")
{
    setSize (620, 275);
    bgImage= juce::ImageCache::getFromMemory(BinaryData::background_png,BinaryData::background_pngSize);
    addAndMakeVisible (osc);
    addAndMakeVisible (adsr);
    
}

SynthCodeAudioProcessorEditor::~SynthCodeAudioProcessorEditor()
{
}

//==============================================================================
void SynthCodeAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.drawImageAt(bgImage,0,0);
}

void SynthCodeAudioProcessorEditor::resized()
{
    const auto paddingX = 5;
    const auto paddingY = 35;
    
    osc.setBounds (paddingX, paddingY, 300, 200);
    adsr.setBounds (osc.getRight(), paddingY, 300, 200);
}




