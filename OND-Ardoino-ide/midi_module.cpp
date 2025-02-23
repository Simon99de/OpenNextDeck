#include "midi_module.h"
#include "settings.h"
#include <Arduino.h>

#if MIDI_DRIVER_TYPE == FORTYSEVEN_EFFECTS
  #include <MIDI.h>
  MIDI_CREATE_DEFAULT_INSTANCE();
#elif MIDI_DRIVER_TYPE == BLE_MIDI
  // Hier die BLE MIDI-Bibliothek einbinden, falls benötigt.
#endif

void initMIDI() {
#if MIDI_ENABLED
  #if MIDI_DRIVER_TYPE == FORTYSEVEN_EFFECTS
    if (DEBUG_MODE) Serial.println("[MIDI] Initializing USB MIDI (FortySevenEffects)...");
    MIDI.begin(MIDI_CHANNEL_OMNI);
  #elif MIDI_DRIVER_TYPE == BLE_MIDI
    if (DEBUG_MODE) Serial.println("[MIDI] Initializing BLE MIDI...");
    // BLE MIDI Initialisierung hier
  #else
    if (DEBUG_MODE) Serial.println("[MIDI] Using board default MIDI implementation.");
  #endif
#endif
}

void pollMIDI() {
#if MIDI_ENABLED
  #if MIDI_DRIVER_TYPE == FORTYSEVEN_EFFECTS
    MIDI.read();
  #elif MIDI_DRIVER_TYPE == BLE_MIDI
    // BLE MIDI Polling hier
  #endif
#endif
}

void sendMIDINote(int note, int velocity) {
#if MIDI_ENABLED && MIDI_NOTES_ENABLED
  #if MIDI_DRIVER_TYPE == FORTYSEVEN_EFFECTS
    if (DEBUG_MODE) {
      Serial.print("[MIDI] USB MIDI - Sending note ");
      Serial.print(note);
      Serial.print(" with velocity ");
      Serial.println(velocity);
    }
    MIDI.sendNoteOn(note, velocity, 1);
    delay(100);
    MIDI.sendNoteOff(note, 0, 1);
  #elif MIDI_DRIVER_TYPE == BLE_MIDI
    if (DEBUG_MODE) {
      Serial.print("[MIDI] BLE MIDI - Sending note ");
      Serial.print(note);
      Serial.print(" with velocity ");
      Serial.println(velocity);
    }
    // BLE MIDI Sende-Code hier
  #else
    if (DEBUG_MODE) {
      Serial.print("[MIDI] Board default MIDI - Note ");
      Serial.print(note);
      Serial.print(", Velocity ");
      Serial.println(velocity);
    }
  #endif
#endif
}
