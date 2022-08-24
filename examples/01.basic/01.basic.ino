#include <BlynkGO_Duino.h>

HWButton button(8);
GTimerDuino timer;

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println("-------------------------");
  Serial.println("BlynkGO Duino");
  Serial.println("-------------------------");

  button.onPressed([](HWButton* btn){
    Serial.println("Pressed");

    // อีก 2 วินาทีถัดไปให้ทำอะไรๆ
    // ใช้แทน delay(2000) แต่จะไม่ทำให้ MCU ค้างระหว่างรอทำงาน
    timer.setOnce(2000,[](){  
      Serial.println("Hello");
    });
  });

}


void loop() {
  button.loop();
  timer.loop();
}

