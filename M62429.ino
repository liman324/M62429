#include <M62429.h>

void setup(){
}

void loop(){
audio();
delay(1000);
}

void audio(){
setVolume (11,12,0,0,5); 
setVolume (11,12,0,1,5);
/* pin CLK
   pin DATA
   0 - по одному каналу, 1 - оба вместе
   0 ПК 1 ЛК
   83 ... 0 громкость 83 = -83 дБ */  
}
