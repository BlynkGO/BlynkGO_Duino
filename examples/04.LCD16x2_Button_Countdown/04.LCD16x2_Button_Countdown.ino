#include <BlynkGO_Duino.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3f, 16, 2);
HWButton    button[3]    = {   3,   4,   5};  // กำหนดขา pin GPIO ของปุ่มกด  ปุ่มให้ต่อแบบ INPUT_PULLUP
int         countdown[3] = { 120, 180, 240};  // เวลาที่จะให้นับถอยหลัง (secs) ของแต่ละปุ่ม

GTimerDuino timer;

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println("Button & CountDown");

  // จอ เริ่มทำงาน
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("MM:SS");
  
  for(uint8_t i=0; i< 3; i++){
    button[i].onPressed([](HWButton*btn){     // เมื่อปุ่มแต่ละตัว ถูกกด
      uint8_t i= btn - &button[0];            // คำนวณว่า ปุ่มที่กดมาเป็น ปุ่มลำดับ i ไหน ( 0,1,2 ) ใน array ปุ่ม

      static int secs;
      secs = countdown[i];                    // วินาทีสำหรับ countdown เริ่มต้น

      Serial.println("[Start]");
      timer.setInterval(1000,[secs](){        // ตั้งเวลาทำงานทุกๆวินาที      
        int m = secs/60, s = secs%60;
        lcd   .setCursor(6, 1);
        lcd   .println( String( m<10? "0":"" )+ String(m) + ":" + String(s<10? "0":"")+String(s) );
        Serial.println( String( m<10? "0":"" )+ String(m) + ":" + String(s<10? "0":"")+String(s) );

        if(secs>0) {
          secs--;                             // ลดค่า countdown ลง ที่ละ 1 วินาที
        }else{
          Serial.println("[Stop]");
          timer.del();                        // หาก countdown นับหมดแล้วให้ยกเลิกตัวตั้งเวลาทิ้ง
        }

      }); // timer.setInterval(...)
    }); // button[i].onClicked(...)
  }  // for(...)
}

void loop() {
  for(int i=0; i< 3; i++){
    button[i].loop();
  }
  timer .loop();
}

