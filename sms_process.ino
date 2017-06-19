String findtexter(String out){
  String number;
  first = out.indexOf("\"");
  second = out.indexOf("\"",first+1);
  //texter = out.substring(first+1,second);
  number = out.substring(first+1,second);
  //return texter;
  return number;
}

String finduser(String out){
  String number;
  first = out.lastIndexOf("\"");
  second = out.indexOf(",",first+1);
  if(second==-1) {
    //messageLength = out.length();
    //user = out.substring(first+1, messageLength-1);
    //user = user.substring(3,user.length());
    //user = "+84" + user;
    //return user;

    messageLength = out.length();
    number = out.substring(first+1, messageLength-1);
    number = number.substring(3,number.length());
    number = "+84" + number;
    return number;
  }
  //user = out.substring(first+1,second);
  //user = user.substring(3,user.length());
  //user = "+84" + user;
  //return user;

  number = out.substring(first+1,second);
  number = number.substring(3,number.length());
  number = "+84" + number;
  return number;
}

boolean checkifuser(String number){
        //Kiểm tra số điện thoại có đăng kí chưa
    for(j=0;j<=i;j++) {
      if(a[j]==number) {
          return true;
      }
    }
    return false;
}

int checkTimeLeft(String texter){
  for(j=0;j<=i;j++) {
    if(a[j]==texter) {
      return l[j];
    }
  }
  //return -1;
}

String findMessage1(String out){                //find message "giat"
  last = out.lastIndexOf("\"");
  messageLength = out.length() -2;
  message = out.substring(last+1,messageLength);
  return message;
}

String findsyntax(String out){           
  messageLength = out.length();
  //syntax = out.substring(messageLength - 1,messageLength);
  message = out.substring(messageLength - 1,messageLength);
  //return syntax;
  return message;
}

void startWashing(){
  digitalWrite(LED1,HIGH);
  delay(5000);
  digitalWrite(LED1,LOW);
  //start 5 minutes timer
}

int updateTimeLeft(String texter){
  for(j=0;j<=i;j++) {
    if(a[j]==texter) {
      l[j]--;
      return l[j];
    }
  }
  return -1;
}

int startpoint(String out) {            //với từng loại cú pháp đk sẽ có số lần giặt bắt đầu khác nhau
  Serial.println("hello");
  if(out == commandText[0]) {
    l[i] = 5;
    return l[i];
  }
  if(out == commandText[1]) {
    l[i] = 10;
    return l[i];
  }
  if(out == commandText[2]) {
    l[i]=15;
    return l[i];
  }
  if(out == commandText[3]) {
    l[i] = 20;
    return l[i];
  }
  return 0;
}
int updatecount(int li) {
  l[i]=li;
  return l[i];
}
int updateuser(String user) {         //trả về vị trí của 1 số điện thoại trong mảng
  for(j=0;j<=i;j++) {
    if(a[j] == user) {
      return j;
    }
  }
  return -1;
}

