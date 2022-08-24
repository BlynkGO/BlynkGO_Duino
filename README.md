# BlynkGO_Duino
 BlynkGO Duino เป็น ไลบรารี่ สำหรับการเขียน code แบบ NONE-BLOCKING  
ทำให้ อุปกรณ์รอบข้าง เมื่อเพิ่มขึ้นเรื่อยๆ ก็ยังทำงานร่วมกันได้โดยไม่ถูก BLOCK กัน  
  
การโคดแบบ NONE-BLOCKING ให้ยกเลิก หรือหลีกเลี่ยงการใช้ คำสั่ง delay(...) ให้หมดเท่าที่ทำได้  
ซึ่งจะทำให้ โคดไม่ถูก BLOCK โดยอุปกรณ์รอบข้างเพียงชนิดเดียวที่ยึดเวลาไป   
อุปกรณ์รอบข้างอื่นๆ ยังสามารถสลับมาทำงานต่อไปได้  
  
ไลบรารี่นี้ใช้ได้ทุกตระกูล MCU

# License
สามารถใช้ในทั้งไม่การค้า และ การค้า  
โดยห้ามมีการแก้ไขดัดแปลงใดๆ และ ห้ามใช้แยกไฟล์ไปใช้
นอกจาก การเรียกใช้ด้วย 

#include <BlynkGO_Duino.h>

