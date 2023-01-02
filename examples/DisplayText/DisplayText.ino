//----------------------------------------------------------------------
// Example Writer : Irfan Indra Kurniawan, ST
// GitHub         : https://github.com/IrfanIndraKurniawan
// Library        : https://github.com/IrfanIndraKurniawan/FansElectronics_DM12ESP
//----------------------------------------------------------------------
#include <FansElectronics_DM12ESP.h>
#include <fonts/System6x7.h>

#define DISPLAYS_WIDE 2  // Kolom Panel
#define DISPLAYS_HIGH 1  // Baris Panel

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
  dmd.drawText(0, 0, "DM12ESP");
  dmd.drawText(0, 8, "P10 LED");
  dmd.update();
}
