/* https://arduino.esp8266.com/stable/package_esp8266com_index.json
 * ESP8266 as Web Server using WiFi Access Point (AP) mode
 * 
 * Open browser, visit 192.168.4.1
 */
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <ESP8266WebServer.h>
/* Put your SSID & Password */
const char* userid = "PROJECT B-E3";  // Enter SSID here
const char* password = "BE3PROJECT";  //Enter Password here

ESP8266WebServer server(80);

uint8_t R1 = D0;
uint8_t R2 = D1;
uint8_t R3 = D2;
uint8_t R4 = D3;

int l1, l2, l3, l4;

void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(R1, OUTPUT); 
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT); 

  EEPROM.begin(512);
  
  l1 = EEPROM.read(1);
  l2 = EEPROM.read(2);
  l3 = EEPROM.read(3);
  l4 = EEPROM.read(4);

  Serial.print(l1); Serial.print(" "); 
  Serial.print(l2); Serial.print(" "); 
  Serial.print(l3); Serial.print(" "); 
  Serial.println(l4);

  digitalWrite(R1, l1); 
  digitalWrite(R2, l2); 
  digitalWrite(R3, l3); 
  digitalWrite(R4, l4);

  WiFi.softAP(userid, password);
  IPAddress protocol = WiFi.softAPIP();
  Serial.print("visit: \n");
  Serial.println(protocol);
    
  delay(100);
  
  server.on("/", OnTag);
  server.on("/L1on",  L1on);
  server.on("/L1off", L1off);
  server.on("/L2on",  L2on);
  server.on("/L2off", L2off);
  server.on("/L3on",  L3on);
  server.on("/L3off", L3off);
  server.on("/L4on",  L4on);
  server.on("/L4off", L4off);
  server.onNotFound(Notset);
  
  server.begin();
  Serial.println("Protocol begin");
}
void loop() {
  server.handleClient();

  digitalWrite(R1, l1); 
  digitalWrite(R2, l2); 
  digitalWrite(R3, l3); 
  digitalWrite(R4, l4);

}

void OnTag() {
  server.send(200, "text/html", SendHTML(l1,l2,l3,l4)); 
}

void L1on()  {l1=0;data();}
void L1off() {l1=1;data();}

void L2on()  {l2=0;data();}
void L2off() {l2=1;data();}

void L3on()  {l3=0;data();}
void L3off() {l3=1;data();}

void L4on()  {l4=0;data();}
void L4off() {l4=1;data();}


void data(){
EEPROM.write(1, l1);
EEPROM.write(2, l2);
EEPROM.write(3, l3);
EEPROM.write(4, l4);
EEPROM.commit();
  
server.send(200, "text/html", SendHTML(l1,l2,l3,l4));   
}


void Notset(){
  server.send(404, "text/plain", "Error");
}

String SendHTML(uint8_t l1r1,uint8_t l2r2,uint8_t l3r3,uint8_t l4r4){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Home Automation</title>\n";
  ptr +="<style>html { background-color:skyblue; font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;}\n";
  ptr +=".circle {width: 85px;height: 85px;border-radius: 50px;background: Red;}\n";
  ptr +=".circle1 {width: 85px;height: 85px;border-radius: 50px;background: lightgreen;}\n";
  ptr +="p{font-size:15px; text-align:center;}\n";
  ptr +="div{display:inline-block;margin-left:5px;height:100px;width:100px;border-radius:100px;border:2px solid black;}\n";
  ptr +="a{font-size:32px; color:rgb(50,50,50);text-decoration: none; text-align:center;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h2 style=\"background-color:Lavender\"><marquee  style=\"color:teal\" font-family:\"Times New Roman\">WELCOME TO HOME AUTOMATION</marquee></h2>\n";
  ptr +="<center style=\"color:maroon\"><h1 font-family:\"Times New Roman\">HOME AUTOMATION WITHOUT INTERNET TO RUN ELECTRICAL DEVICES</center></center>\n";
   if(l1r1==0)
  {ptr +="<p>Load1 Status: ON</p><div class=\"circle\"><h1><a class=\"circle\" href=\"/L1off\">OFF</a></h1></div><br><br>\n";}
  else
  {ptr +="<p>Load1 Status: OFF</p><div class=\"circle1\"><h1><a class=\"circle1\" href=\"/L1on\">ON</a></h1></div><br><br>\n";}

  if(l2r2==0)
  {ptr +="<p>Load2 Status: ON</p><div class=\"circle\"><h1><a class=\"circle\" href=\"/L2off\">OFF</a></h1></div><br><br>\n";}
  else
  {ptr +="<p>Load2 Status: OFF</p><div class=\"circle1\"><h1><a class=\"circle1\" href=\"/L2on\">ON</a></h1></div><br><br>\n";}

  if(l3r3==0)
  {ptr +="<p>Load3 Status: ON</p><div class=\"circle\"><h1><a class=\"circle\" href=\"/L3off\">OFF</a></h1></div><br><br>\n";}
  else
  {ptr +="<p>Load3 Status: OFF</p><div class=\"circle1\"><h1><a class=\"circle1\" href=\"/L3on\">ON</a></h1></div><br><br>\n";}

  if(l4r4==0)
  {ptr +="<p>Load4 Status: ON</p><div class=\"circle\"><h1><a class=\"circle\" href=\"/L4off\">OFF</a></h1></div><br><br>\n";}
  else
  {ptr +="<p>Load4 Status: OFF</p><div class=\"circle1\"><h1><a class=\"circle1\" href=\"/L4on\">ON</a></h1></div><br><br>\n";}

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
