//----------------------------------------------------------------------
// Example Writer : Irfan Indra Kurniawan, ST
// GitHub         : https://github.com/IrfanIndraKurniawan
// Library        : https://github.com/IrfanIndraKurniawan/FansElectronics_DM12ESP
//----------------------------------------------------------------------
#include <FansElectronics_DM12ESP.h>
#include <fonts/System6x7.h>
#include <fonts/SystemFont5x7.h>

#define DISPLAYS_WIDE 6  // Kolom Panel 64 pixel
#define DISPLAYS_HIGH 1  // Baris Panel 16 pixel

FansElectronics_DM12ESP dmd(DISPLAYS_WIDE, DISPLAYS_HIGH);

//----------------------------------------------------------------------
// SETUP
void setup() {
  dmd.begin();             // Begin Setup
  dmd.setBrightness(255);  // Tingkat kecerahan
}

//----------------------------------------------------------------------
// LOOP
void loop() {
  dmd.setFont(System6x7);
  dmd.drawText(7, 0, "DM12ESP");
  dmd.setFont(SystemFont5x7);
  bool next = runningText(8, 30, "DMD12ESP P10 ESP8266 by FansElectronics ");
  dmd.update();
}
//----------------------------------------------------------------------
// Running Text
bool runningText(int y, uint8_t speed, String text) {
  static uint32_t spd;
  static uint32_t hold_run;
  static bool waiting = false;
  static int x;
  if (text == "") {
    x = 0;
    waiting = false;
    return true;
  }
  int fullScroll = dmd.textWidth(text) + dmd.width();
  char buff[text.length() + 1];
  text.toCharArray(buff, text.length() + 1);
  if ((millis() - spd) > speed && !waiting) {
    spd = millis();
    if (x < fullScroll) {
      x++;
    } else {
      hold_run = millis();
      waiting = true;
    }
    dmd.drawText(dmd.width() - x, y, buff);
  }
  if (millis() - hold_run > 1000 && waiting) {
    x = 0;
    waiting = false;
    return true;
  }
  return false;
}