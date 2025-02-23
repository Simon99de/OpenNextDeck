#ifndef MIDI_MODULE_H
#define MIDI_MODULE_H

void initMIDI();
void pollMIDI();
void sendMIDINote(int note, int velocity);

#endif // MIDI_MODULE_H
