void sendSMS(String texter, String message){
  Serial.println("Set SMS text mode");
  SIM900.println("AT+CMGF=1");
  Serial.println("Sending SMS..");
  SIM900.println("AT+CMGS=\"+841223802230\"");
  delay(500);
    SIM900.println("Hello");
    delay(500);
    SIM900.write(26);
    SIM900.write(13);
    SIM900.write(10);
}

String Response()
{
  int count = 0;
  Serial.println();
  while(1)
  {
    if(SIM900.available())
    {
      char data =SIM900.read();
      if(data == 'K'){Serial.println("OK");return "OK";}
      if(data == 'R'){Serial.println("GSM Not Working");return "GSM Not Working";}
    }
    count++;
    delay(10);
    if(count == 1000){Serial.println("GSM not Found");return "GSM not found";}
  }
  
}
