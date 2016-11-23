/*
  This code accompanies the textbook:
 
  Digital Audio Effects: Theory, Implementation and Application
  Joshua D. Reiss and Andrew P. McPherson
 
  ---
 
  Empty: template for an effect; passes input to output unmodified
  See textbook Chapter 13: Building Audio Effect Plug-Ins
 
  Code by Andrew McPherson, Brecht De Man and Joshua Reiss
 
  ---

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
EmptyAudioProcessorEditor::EmptyAudioProcessorEditor (EmptyAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter),
      trebLabel_("", "Trebel:"),
	  midLabel_("", "Middle:"),
	  bassLabel_("", "Bass:")
{
    // This is where our plugin's editor size is set.
    // setSize(170, 80);
    
    // Set up the sliders
    addAndMakeVisible(&trebSlider_);
	trebSlider_.setSliderStyle(Slider::Rotary);
	trebSlider_.addListener(this);
	trebSlider_.setRange(0.0, 1, 0.05);

	addAndMakeVisible(&midSlider_);
	midSlider_.setSliderStyle(Slider::Rotary);
	midSlider_.addListener(this);
	midSlider_.setRange(0.0, 1, 0.05);


	addAndMakeVisible(&bassSlider_);
	bassSlider_.setSliderStyle(Slider::Rotary);
	bassSlider_.addListener(this);
	bassSlider_.setRange(0.0, 1, 0.05);
    
    trebLabel_.attachToComponent(&trebSlider_, false);
	trebLabel_.setFont(Font (11.0f));

	midLabel_.attachToComponent(&midSlider_, false);
	midLabel_.setFont(Font(11.0f));

	bassLabel_.attachToComponent(&bassSlider_, false);
	bassLabel_.setFont(Font(11.0f));
    
    // add the triangular resizer component for the bottom-right of the UI
    addAndMakeVisible(resizer_ = new ResizableCornerComponent (this, &resizeLimits_));
    resizeLimits_.setSizeLimits(550, 100, 550, 160);
    
    // set our component's initial size to be the last one that was stored in the filter's settings
    setSize(ownerFilter->lastUIWidth_,
            ownerFilter->lastUIHeight_);
    
    startTimer(50);
}

EmptyAudioProcessorEditor::~EmptyAudioProcessorEditor()
{
}

//==============================================================================
void EmptyAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::grey);
}

void EmptyAudioProcessorEditor::resized()
{
    trebSlider_.setBounds(20, 20, 150, 40);
	midSlider_.setBounds(100, 20, 150, 40);
	bassSlider_.setBounds(180, 20, 150, 40);
    
    resizer_->setBounds(getWidth() - 16, getHeight() - 16, 16, 16);
    
    getProcessor()->lastUIWidth_ = getWidth();
    getProcessor()->lastUIHeight_ = getHeight();
}

//==============================================================================
// This timer periodically checks whether any of the filter's parameters have changed...
void EmptyAudioProcessorEditor::timerCallback()
{
    EmptyAudioProcessor* ourProcessor = getProcessor();
    
    trebSlider_.setValue(ourProcessor->volume_, dontSendNotification);
	midSlider_.setValue(ourProcessor->volume_, dontSendNotification);
	bassSlider_.setValue(ourProcessor->volume_, dontSendNotification);
}

// This is our Slider::Listener callback, when the user drags a slider.
void EmptyAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    if (slider == &trebSlider_)
    {
        // It's vital to use setParameterNotifyingHost to change any parameters that are automatable
        // by the host, rather than just modifying them directly, otherwise the host won't know
        // that they've changed.
        getProcessor()->setParameterNotifyingHost (EmptyAudioProcessor::kTrebParam,
                                                   (float)trebSlider_.getValue());
    }
	else if (slider == &midSlider_)
	{
		// It's vital to use setParameterNotifyingHost to change any parameters that are automatable
		// by the host, rather than just modifying them directly, otherwise the host won't know
		// that they've changed.
		getProcessor()->setParameterNotifyingHost(EmptyAudioProcessor::kMidParam,
			(float)midSlider_.getValue());
	}
	else if (slider == &bassSlider_)
	{
		// It's vital to use setParameterNotifyingHost to change any parameters that are automatable
		// by the host, rather than just modifying them directly, otherwise the host won't know
		// that they've changed.
		getProcessor()->setParameterNotifyingHost(EmptyAudioProcessor::kBassParam,
			(float)bassSlider_.getValue());
	}
}