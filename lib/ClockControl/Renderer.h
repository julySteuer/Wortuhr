#include "Adafruit_NeoPixel.h"
#include "Data.h"

#define NUMPIXELS 50
#define PIN 6
#define BRIGHTNESS 10

namespace Rendering { // The side effect stuff begins here
    Adafruit_NeoPixel board(NUMPIXELS, PIN, NEO_RGBW + NEO_KHZ800);

    void initBoard() {
        board.begin();
        board.setBrightness(BRIGHTNESS); 
    }

    void renderWord(Data::t_Word word) {
        for (int i = word.begin; i <= word.end;i++) {
            board.setPixelColor(i, board.Color(255,255,255));
        }
    }

    void renderTime(ClockControl::t_TimeProperty time) {
        board.clear();
        Data::t_Word minutes = Data::getMinute(time.preNum);
        renderWord(minutes);
        if (time.delim != ClockControl::Deliminator::None) {
            Data::t_Word delim = Data::getDelim(time.delim);
            renderWord(delim);
        }
        Data::t_Word hour = Data::getHour(time.hour);
        renderWord(hour);
        board.show();
    }
}