#define RX 2
#define TX 3
SoftwareSerial SIM900(RX,TX);

int first;
int second;
int last;
int messageLength;
String message;
//String syntax;
//String texter;                //số điện thoại người gửi tin nhắn
//String user;              //số điện thoại người đăng kí
String acceptNumber="+841692146377";   //Số điện thoại chủ nhà
String const commandText[4]={ "a", "b", "c","d" };     //Lệnh đk hợp lệ
String commandText2="Giat";    //Lệnh giặt hợp lệ
String a[100];                    //mảng chứa số điện thoại đã đk
int l[10];                       //mảng chứa số lần giặt còn lại của các số điện thoại
int timeLeft;                     //biến cập nhật số lần giặt còn lại sau khi giạt xong
int i,j,pos,li;
String RxBuff;
String text;

const int LED1 = 9;
