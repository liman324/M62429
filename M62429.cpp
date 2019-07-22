//rcl-radio.ru
// liman324@yandex.ru
// библиотека создана на основе https://soltau.ru/index.php/arduino/item/497-kak-podklyuchit-regulyator-gromkosti-m62429-k-arduino

#include <Arduino.h>

void setVolume (int clk, int data, int canal, int k, int att){
  pinMode(data, OUTPUT);
  pinMode(clk, OUTPUT);
  digitalWrite(data, HIGH);
  digitalWrite(clk, LOW);
  
  
   int att1[21][5] = {
  {1, 0, 1, 0, 1}, //-0db
  {0, 0, 1, 0, 1}, //-4db
  {1, 1, 0, 0, 1}, //-8db
  {0, 1, 0, 0, 1}, //-12db
  {1, 0, 0, 0, 1}, //-16db
  {0, 0, 0, 0, 1}, //-20db
  {1, 1, 1, 1, 0}, //-24db
  {0, 1, 1, 1, 0}, //-28db
  {1, 0, 1, 1, 0}, //-32db
  {0, 0, 1, 1, 0}, //-36db
  {1, 1, 0, 1, 0}, //-40db
  {0, 1, 0, 1, 0}, //-44db
  {1, 0, 0, 1, 0}, //-48db
  {0, 0, 0, 1, 0}, //-52db
  {1, 1, 1, 0, 0}, //-56db
  {0, 1, 1, 0, 0}, //-60db
  {1, 0, 1, 0, 0}, //-64db
  {0, 0, 1, 0, 0}, //-68db
  {1, 1, 0, 0, 0}, //-72db
  {0, 1, 0, 0, 0}, //-76db
  {1, 0, 0, 0, 0}  //-80db
};

// Коды громкости аттенюатора 2
int att2[4][2] = {
  {1, 1}, //-0db
  {0, 1}, //-1db
  {1, 0}, //-2db
  {0 ,0}  //-3db
};   
int att1index = floor(abs(att) / 4);
  int att2index = abs(att) % 4;
  
  // Задаём в пакете канал:
  digitalWrite(data, (bool)canal);
  digitalWrite(clk, HIGH);
  digitalWrite(data, LOW);
  digitalWrite(clk, LOW);

  // Задаём одновременное или независимое управление каналами:
  digitalWrite(data, k);
  digitalWrite(clk, HIGH);
  digitalWrite(data, LOW);
  digitalWrite(clk, LOW);

  // Задаём значение 1-го аттенюатора D2..D6:
  for (int i=0; i<5; i++) {
    digitalWrite(data, (bool)att1[att1index][i]);
    digitalWrite(clk, HIGH);
    digitalWrite(data, LOW);
    digitalWrite(clk, LOW);
  }
  
  // Задаём значение 2-го аттенюатора D7..D8:
  for (int i=0; i<2; i++) {
    digitalWrite(data, (bool)att2[att2index][i]);
    digitalWrite(clk, HIGH);
    digitalWrite(data, LOW);
    digitalWrite(clk, LOW);
  }

  // Два последних бита пакета – две единицы:
  digitalWrite(data, HIGH);
  digitalWrite(clk, HIGH);
  delayMicroseconds(2);
  digitalWrite(data, LOW);
  digitalWrite(clk, LOW);
  delayMicroseconds(2);

  digitalWrite(data, HIGH);
  digitalWrite(clk, HIGH);
  delayMicroseconds(2);
  digitalWrite(clk, LOW);
  digitalWrite(data, LOW);
  delayMicroseconds(2);

}
