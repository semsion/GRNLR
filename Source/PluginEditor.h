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
class Grnlr_kleinAudioProcessorEditor : public AudioProcessorEditor,
                                        public Thread,
                                        private Slider::Listener,
                                        private Button::Listener,
                                        private ChangeListener
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

    String chosenPath;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Grnlr_kleinAudioProcessor& processor;

    class ParameterSlider;
    class ParameterButton;

    void openButtonClicked();
    void checkForBuffersToFree();
    void checkForPathToOpen();

    void run() override;

    ReferenceCountedArray<ReferenceCountedBuffer> buffers;

    AudioFormatManager formatManager;

    // GUI:
    TextButton openButton;
    ScopedPointer<ParameterButton> holdButton;

    Label fillLabel;
    Label randFillLabel;
    Label durationLabel;
    Label randDurLabel;
    Label randPosLabel;
    Label transLabel;
    Label randTransLabel;
    Label volumeLabel;
    Label randVolLabel;
    
    ScopedPointer<ParameterSlider> positionSlider;
    ScopedPointer<ParameterSlider> fillSlider;
    ScopedPointer<ParameterSlider> durationSlider;
    ScopedPointer<ParameterSlider> randPosSlider;
    ScopedPointer<ParameterSlider> randFillSlider;
    ScopedPointer<ParameterSlider> randDurSlider;
    ScopedPointer<ParameterSlider> transSlider;
    ScopedPointer<ParameterSlider> randTransSlider;
    ScopedPointer<ParameterSlider> volumeSlider;
    ScopedPointer<ParameterSlider> randVolSlider;

    Label envCenterLabel;
    Label envSustainLabel;
    Label envCurveLabel;
    ScopedPointer<ParameterSlider> envCenterSlider;
    ScopedPointer<ParameterSlider> envSustainSlider;
    ScopedPointer<ParameterSlider> envCurveSlider;

    ScopedPointer<WaveformView> waveform;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Grnlr_kleinAudioProcessorEditor)
};

#endif  // PLUGINEDITOR_H_INCLUDED
