#include <BlynkGO_Duino.h>

#define LED1    11
#define LED2    12
#define LED3    13


GTimerDuino timer_led1_led2;
GTimerDuino timer_led3;

void setup(){
  Serial.begin(115200); Serial.println();
  Serial.println("-------------------------");
  Serial.println("BlynkGO Duino");
  Serial.println("-------------------------");

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // ตั้งเวลาทำงานทุกๆ 1 วินาที ให้ LED1 & LED2 ติด-ดับ สลับกัน
  timer_led1_led2.setInterval(1000,[](){
    digitalWrite(LED1, !digitalRead(LED1));  // กลับสถานะเดิมของ LED1
    digitalWrite(LED2, !digitalRead(LED1));  // LED2 ให้สถานะตรงข้ามกับสถานะ LED1 ปัจจุบัน ทำให้ LED1 & LED2 กระพริบสลับกันไป
  });

  // ตั้งเวลาทำงานทุกๆ 300ms ให้ LED3 กระพริบ
  timer_led3.setInterval(300,[](){
    digitalWrite(LED3, !digitalRead(LED3)); // กลับสถานะเดิมของ LED3
  });

}

void loop(){
  timer_led1_led2.loop();
  timer_led3.loop();
}

