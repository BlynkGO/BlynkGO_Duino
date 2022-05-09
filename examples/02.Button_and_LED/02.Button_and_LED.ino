#include <BlynkGO_Duino.h>

#define BUTTON_PIN    8
#define LED_PIN       13

HWButton button(BUTTON_PIN);
GTimerDuino timer;

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println("-------------------------");
  Serial.println("BlynkGO Duino");
  Serial.println("-------------------------");

  pinMode(LED_PIN, OUTPUT);
  
  button.onPressed([](HWButton* btn){
    static bool is_blinking;
    Serial.println("Pressed");

    // หากยังไม่ได้ กระพริบ ให้ ตั้งเวลาทำ LED กระพริบ
    if( is_blinking == false) {
      is_blinking = true;
      timer.setInterval(500,[](){               // ตั้ง timer ทำงานทุกๆ 500ms
        static bool state;
        digitalWrite(LED_PIN, state = !state);  // สลับการกระพริบ
      });
    }else{
    // หากกระพริบอยู่ ให้ยกเลิก ตัวตั้งเวลาที่ทำ LED กระพริบ
      is_blinking = false;
      timer.del();                              // ลบ timer
      digitalWrite(LED_PIN, LOW);
    }
    
  }); // button.onPressed(..)
}


void loop() {
  button.run();
  timer.run();
}
