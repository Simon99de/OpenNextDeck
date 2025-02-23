#ifndef HID_MODULE_H
#define HID_MODULE_H

void initHID();
void pollHID();
void HIDKeyboardPress(const char* keys);

#endif // HID_MODULE_H
