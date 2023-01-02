//----------------------------------------------------------------------------------------------
// Penggunaan DMD untuk ESP8266 dengan panel P10
// Diambil dari Library DMD porting ESP8266 yang dirapikan

// Dimodifikasi oleh : Irfan Indra Kurniawan, ST
// GitHub            : https://github.com/IrfanIndraKurniawan
// Sumber            : https://github.com/rweather/arduino-projects/tree/master/libraries/DMD
//----------------------------------------------------------------------------------------------
#ifndef FansElectronics_DM12ESP_h
#define FansElectronics_DM12ESP_h

#include "Bitmap.h"
#include "SPI.h"
//----------------------------------------------------------------------------------------------

class FansElectronics_DM12ESP : public Bitmap
{
public:
  explicit FansElectronics_DM12ESP(int widthPanels = 1, int heightPanels = 1);
  ~FansElectronics_DM12ESP();
  bool doubleBuffer() const { return _doubleBuffer; }
  void setDoubleBuffer(bool doubleBuffer);
  void swapBuffers();
  void swapBuffersAndCopy();
  void begin();
  void update();
  void refresh();
  void setBrightness(uint8_t b);
  static Color fromRGB(uint8_t r, uint8_t g, uint8_t b);

private:
  FansElectronics_DM12ESP(const FansElectronics_DM12ESP &other) : Bitmap(other) {}
  FansElectronics_DM12ESP &operator=(const FansElectronics_DM12ESP &) { return *this; }

  uint8_t brightenss;
  bool _doubleBuffer;
  uint8_t phase;
  uint8_t *fb0;
  uint8_t *fb1;
  uint8_t *displayfb;
  unsigned long lastRefresh;
};

#endif
//----------------------------------------------------------------------------------------------
