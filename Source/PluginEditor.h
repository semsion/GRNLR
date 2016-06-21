/*
 ==============================================================================
 
 This file was auto-generated by the Introjucer!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "WaveformView.h"

//==============================================================================
/**
 */
class Grnlr_kleinAudioProcessorEditor : public  AudioProcessorEditor,
                                        public Thread,
                                        private Slider::Listener,
                                        Button::Listener,
                                        ChangeListener
{
public:
    Grnlr_kleinAudioProcessorEditor (Grnlr_kleinAudioProcessor&);
    ~Grnlr_kleinAudioProcessorEditor();
    
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void buttonClicked(Button* button) override;
    void sliderValueChanged(Slider* slider) override;
    void changeListenerCallback (ChangeBroadcaster* source) override;
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Grnlr_kleinAudioProcessor& processor;
    
    class ParameterSlider;
    
    void openButtonClicked();
    void checkForBuffersToFree();
    void checkForPathToOpen();
    
    void run() override;
    
    ReferenceCountedArray<ReferenceCountedBuffer> buffers;
    
    AudioFormatManager formatManager;
    
    TextButton openButton;
    String chosenPath;
    
    Label fillLabel;
    Label durationLabel;
    ScopedPointer<ParameterSlider> positionSlider;
    ScopedPointer<ParameterSlider> fillSlider;
    ScopedPointer<ParameterSlider> durationSlider;
    
    Label envCenterLabel;
    Label envSustainLabel;
    ScopedPointer<ParameterSlider> envCenterSlider;
    ScopedPointer<ParameterSlider> envSustainSlider;
    
    ScopedPointer<WaveformView> waveform;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Grnlr_kleinAudioProcessorEditor)
};

#endif  // PLUGINEDITOR_H_INCLUDED
