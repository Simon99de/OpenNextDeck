#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>  // Jetzt ist der Typ String bekannt

void initDisplay();
void pollDisplay();

// Grid-Funktionen
void loadDefaultGridConfig();
void loadProfileGridConfig(const String &profileName);
void drawGrid();

// Globale Grid-Konfigurationsvariablen – deklariert als extern, damit sie in anderen Dateien sichtbar sind.
extern int gridRows;
extern int gridCols;
extern uint16_t backgroundColor;  // statt extern int backgroundColor;
extern int buttonSpacing;
extern bool swipeEnabled;
extern bool autoPageSave;
extern bool iconScaling;

#endif // DISPLAY_H
