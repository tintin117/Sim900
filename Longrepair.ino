#include<SoftwareSerial.h>
#include"my_sim900.h"

void setup()
{
  pinMode(LED1,OUTPUT);
  Serial.begin(9600);
  SIM900.begin(9600);
  do{
    SIM900.println("AT");
    text = Response();
  } while(text != "OK");
  do{
    SIM900.println("ATE0");
    text = Response();
  } while(text != "OK");
  do{
    SIM900.println("AT+CNMI=1,2,0,0,0");
    text = Response();
  } while(text != "OK");
  i=0;
  j=0;
  //delay(3000);
}

void loop()
{
  if(SIM900.available()>0) {
    while (SIM900.available()) {                               // Doi den khi co du lieu nhan ve
    // get the new byte:
    char inChar;
    inChar = SIM900.read();                  // Doc mot byte du lieu vua nhan ve
    RxBuff += inChar;    
    }     
    Serial.println(RxBuff);
    String texter;
    texter = findtexter(RxBuff);        //đọc số điện thoại người gửi tin
    if(texter == acceptNumber) {                //nếu là số điện thoại chủ nhà
      String syntax;
      syntax = findsyntax(RxBuff);        //tìm cú pháp "a", "b", "c", "d"
      Serial.println(syntax);
       String user;
      user = finduser(RxBuff);    //số điện thoại người đk, đã chuyển sang dạng +84
      Serial.println(user);
      boolean check;
      check = checkifuser(user);    //kiểm tra xem số điện thoại đk này là để cập nhật số lần hay là số mới hoàn toàn chưa có trong danh sách
      Serial.println(check);
      if(check == 0) {                            //nếu đây là số mới hoàn toàn
      Serial.println("This is completely new number");
      a[i] = user;
      Serial.println(a[i]);
      Serial.println(i);
      li = startpoint(syntax);
      Serial.println(li);
      Serial.println(l[i]);
      i++;
      Serial.println(i);
      } else {                                            //nếu đây là số điện thoại đk để cập nhật số lần
      timeLeft = checkTimeLeft(user);
      Serial.println(timeLeft);
        }                                                   
    } else {                                              //nếu ko phải số điện thoại chủ nhà
      String syntax;
      syntax = findMessage1(RxBuff);                     //đọc nguyên nội dung tin nhắn
      Serial.println(syntax);
    }
   }
  SIM900.print("AT+CMGD=1,4");
  RxBuff= "";
 delay(3000);      
}

