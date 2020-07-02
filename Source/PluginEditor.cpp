/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainTestProcessorEditor::GainTestProcessorEditor (GainTestProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    //gainslider test
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    gainSlider.setRange(0.0f, 1.0f, 0.01f);
    gainSlider.setValue(0.5f);
    addAndMakeVisible(gainSlider);
    gainSlider.addListener(this);


    setSize (200, 300);
}

GainTestProcessorEditor::~GainTestProcessorEditor()
{
}

//==============================================================================
void GainTestProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::steelblue);

    //g.setColour (juce::Colours::darkviolet);
    g.setFont (15.0f);
    g.drawFittedText ("Gain Test", getLocalBounds(), juce::Justification::centredTop, 1);

}

void GainTestProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}


void GainTestProcessorEditor::sliderValueChanged (juce::Slider *slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.gainFloat = gainSlider.getValue();
    }
}