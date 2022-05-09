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
    static bool state;

    state = !state;
    digitalWrite(LED1,  state);
    digitalWrite(LED2, !state);
  });

  // ตั้งเวลาทำงานทุกๆ 300ms ให้ LED3 กระพริบ
  timer_led3.setInterval(300,[](){
    static bool state;
    digitalWrite(LED3,  state = !state);
  });

}

void loop(){
  timer_led1_led2.run();
  timer_led3.run();
}

