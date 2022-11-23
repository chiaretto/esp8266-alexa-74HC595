#define ESPALEXA_MAXDEVICES 32

#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>

#define wifiLedOn         D3 //On
#define wifiLedOff        D4 //Off
#define wifiLedStatus     D5 //Status
#define TurnOnOffStatus   D6 //Status

#define pinSH_CP D0   //Pino Clock
#define pinST_CP D1   //Pino Latch
#define pinDS    D2   //Pino Data
#define qtdeCI   4    //Qtd CIs

#define ON      0 // Low
#define OFF     1 // High

// CI Digital Write
void ci74HC595Write(byte pino, bool estado);

// prototypes
boolean connectWifi();

//callback functions
void LightChanged1(uint8_t brightness);
void LightChanged2(uint8_t brightness);
void LightChanged3(uint8_t brightness);
void LightChanged4(uint8_t brightness);
void LightChanged5(uint8_t brightness);
void LightChanged6(uint8_t brightness);
void LightChanged7(uint8_t brightness);
void LightChanged8(uint8_t brightness);
void LightChanged9(uint8_t brightness);
void LightChanged10(uint8_t brightness);
void LightChanged11(uint8_t brightness);
void LightChanged12(uint8_t brightness);
void LightChanged13(uint8_t brightness);
void LightChanged14(uint8_t brightness);
void LightChanged15(uint8_t brightness);
void LightChanged16(uint8_t brightness);
void LightChanged17(uint8_t brightness);
void LightChanged18(uint8_t brightness);
void LightChanged19(uint8_t brightness);
void LightChanged20(uint8_t brightness);
void LightChanged21(uint8_t brightness);
void LightChanged22(uint8_t brightness);
void LightChanged23(uint8_t brightness);
void LightChanged24(uint8_t brightness);
void LightChanged25(uint8_t brightness);
void LightChanged26(uint8_t brightness);
void LightChanged27(uint8_t brightness);
void LightChanged28(uint8_t brightness);
void LightChanged29(uint8_t brightness);
void LightChanged30(uint8_t brightness);
void LightChanged31(uint8_t brightness);
void LightChanged32(uint8_t brightness);

// WiFi Credentials
const char* ssid = "NOME REDE WIFI";
const char* password = "SENHA REDE WIFI";

// device names
String DeviceName1  = "S01";
#define RelayPin1     1

String DeviceName2 = "S02";
#define RelayPin2     2

String DeviceName3 = "S03";
#define RelayPin3     3

String DeviceName4 = "S04";
#define RelayPin4     4

String DeviceName5 = "S05";
#define RelayPin5     5

String DeviceName6 = "S06";
#define RelayPin6     6

String DeviceName7 = "S07";
#define RelayPin7     7

String DeviceName8 = "S08";
#define RelayPin8     8

String DeviceName9 = "S09";
#define RelayPin9     9

String DeviceName10  = "S10";
#define RelayPin10     10

String DeviceName11  = "S11";
#define RelayPin11     11

String DeviceName12  = "S12";
#define RelayPin12     12

String DeviceName13  = "S13";
#define RelayPin13     13

String DeviceName14  = "S14";
#define RelayPin14     14

String DeviceName15  = "S15";
#define RelayPin15     15

String DeviceName16 = "S16";
#define RelayPin16     16

String DeviceName17  = "S17";
#define RelayPin17     17

String DeviceName18  = "S18";
#define RelayPin18     18

String DeviceName19  = "S19";
#define RelayPin19     19

String DeviceName20  = "S20";
#define RelayPin20     20

String DeviceName21  = "S21";
#define RelayPin21     21

String DeviceName22  = "S22";
#define RelayPin22     22

String DeviceName23  = "S23";
#define RelayPin23     23

String DeviceName24  = "S24";
#define RelayPin24     24

String DeviceName25 = "S25";
#define RelayPin25     25

String DeviceName26  = "S26";
#define RelayPin26     26

String DeviceName27  = "S27";
#define RelayPin27     27

String DeviceName28  = "S28";
#define RelayPin28     28

String DeviceName29  = "S29";
#define RelayPin29     29

String DeviceName30  = "S30";
#define RelayPin30     30

String DeviceName31  = "S31";
#define RelayPin31     31

String DeviceName32  = "S32";
#define RelayPin32     32

boolean wifiConnected = false;

Espalexa espalexa;

//Callback functions
void LightChanged1(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin1);}else{TurnOff(RelayPin1);}}
void LightChanged2(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin2);}else{TurnOff(RelayPin2);}}
void LightChanged3(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin3);}else{TurnOff(RelayPin3);}}
void LightChanged4(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin4);}else{TurnOff(RelayPin4);}}
void LightChanged5(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin5);}else{TurnOff(RelayPin5);}}
void LightChanged6(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin6);}else{TurnOff(RelayPin6);}}
void LightChanged7(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin7);}else{TurnOff(RelayPin7);}}
void LightChanged8(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin8);}else{TurnOff(RelayPin8);}}
void LightChanged9(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin9);}else{TurnOff(RelayPin9);}}
void LightChanged10(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin10);}else{TurnOff(RelayPin10);}}
void LightChanged11(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin11);}else{TurnOff(RelayPin11);}}
void LightChanged12(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin12);}else{TurnOff(RelayPin12);}}
void LightChanged13(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin13);}else{TurnOff(RelayPin13);}}
void LightChanged14(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin14);}else{TurnOff(RelayPin14);}}
void LightChanged15(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin15);}else{TurnOff(RelayPin15);}}
void LightChanged16(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin16);}else{TurnOff(RelayPin16);}}
void LightChanged17(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin17);}else{TurnOff(RelayPin17);}}
void LightChanged18(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin18);}else{TurnOff(RelayPin18);}}
void LightChanged19(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin19);}else{TurnOff(RelayPin19);}}
void LightChanged20(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin20);}else{TurnOff(RelayPin20);}}
void LightChanged21(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin21);}else{TurnOff(RelayPin21);}}
void LightChanged22(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin22);}else{TurnOff(RelayPin22);}}
void LightChanged23(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin23);}else{TurnOff(RelayPin23);}}
void LightChanged24(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin24);}else{TurnOff(RelayPin24);}}
void LightChanged25(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin25);}else{TurnOff(RelayPin25);}}
void LightChanged26(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin26);}else{TurnOff(RelayPin26);}}
void LightChanged27(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin27);}else{TurnOff(RelayPin27);}}
void LightChanged28(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin28);}else{TurnOff(RelayPin28);}}
void LightChanged29(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin29);}else{TurnOff(RelayPin29);}}
void LightChanged30(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin30);}else{TurnOff(RelayPin30);}}
void LightChanged31(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin31);}else{TurnOff(RelayPin31);}}
void LightChanged32(uint8_t brightness) {if(brightness==255){TurnOn(RelayPin32);}else{TurnOff(RelayPin32);}}

void TurnOn(uint8_t port) {
    digitalWrite(TurnOnOffStatus, ON);
    delay(100);
    digitalWrite(TurnOnOffStatus, OFF);
    port--;
    ci74HC595Write(port, HIGH);
    delay(200);
    ci74HC595Write(port, LOW);
    Serial.print("Device: ");
    Serial.print(port+1);
    Serial.print(" - Port: ");
    Serial.print(port);
    Serial.println(" - ON");
}

void TurnOff(uint8_t port) {
    digitalWrite(TurnOnOffStatus, ON);
    delay(100);
    digitalWrite(TurnOnOffStatus, OFF);
    port--;
    ci74HC595Write(port, HIGH);
    delay(200);
    ci74HC595Write(port, LOW);
    Serial.print("Device: ");
    Serial.print(port+1);
    Serial.print(" - Port: ");
    Serial.print(port);
    Serial.println(" - OFF");
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi()
{
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting... ");
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(wifiLedStatus, OFF);
    delay(500);
    digitalWrite(wifiLedStatus, ON);
    delay(500);
    digitalWrite(wifiLedStatus, OFF);
    Serial.print(".");
    if (i > 20) {
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state) {
    Serial.print("Connected to: ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Connection failed.");
  }
  return state;
}

void addDevices(){
  // Define your devices here.
  espalexa.addDevice(DeviceName1, LightChanged1);
  espalexa.addDevice(DeviceName2, LightChanged2);
  espalexa.addDevice(DeviceName3, LightChanged3);
  espalexa.addDevice(DeviceName4, LightChanged4);
  espalexa.addDevice(DeviceName5, LightChanged5);
  espalexa.addDevice(DeviceName6, LightChanged6);
  espalexa.addDevice(DeviceName7, LightChanged7);
  espalexa.addDevice(DeviceName8, LightChanged8);
  espalexa.addDevice(DeviceName9, LightChanged9);
  espalexa.addDevice(DeviceName10, LightChanged10);
  espalexa.addDevice(DeviceName11, LightChanged11);
  espalexa.addDevice(DeviceName12, LightChanged12);
  espalexa.addDevice(DeviceName13, LightChanged13);
  espalexa.addDevice(DeviceName14, LightChanged14);
  espalexa.addDevice(DeviceName15, LightChanged15);
  espalexa.addDevice(DeviceName16, LightChanged16);
  espalexa.addDevice(DeviceName17, LightChanged17);
  espalexa.addDevice(DeviceName18, LightChanged18);
  espalexa.addDevice(DeviceName19, LightChanged19);
  espalexa.addDevice(DeviceName20, LightChanged20);
  espalexa.addDevice(DeviceName21, LightChanged21);
  espalexa.addDevice(DeviceName22, LightChanged22);
  espalexa.addDevice(DeviceName23, LightChanged23);
  espalexa.addDevice(DeviceName24, LightChanged24);
  espalexa.addDevice(DeviceName25, LightChanged25);
  espalexa.addDevice(DeviceName26, LightChanged26);
  espalexa.addDevice(DeviceName27, LightChanged27);
  espalexa.addDevice(DeviceName28, LightChanged28);
  espalexa.addDevice(DeviceName29, LightChanged29);
  espalexa.addDevice(DeviceName30, LightChanged30);
  espalexa.addDevice(DeviceName31, LightChanged31);
  espalexa.addDevice(DeviceName32, LightChanged32);
  espalexa.begin();
}
void setup()
{
  Serial.begin(115200);
  Serial.println("Alexa Started");
  
  pinMode(pinSH_CP, OUTPUT);
  pinMode(pinST_CP, OUTPUT);
  pinMode(pinDS, OUTPUT);
   
  pinMode(wifiLedOn, OUTPUT);
  pinMode(wifiLedOff, OUTPUT);
  pinMode(wifiLedStatus, OUTPUT);
  pinMode(TurnOnOffStatus, OUTPUT);

  digitalWrite(wifiLedOn, OFF);
  digitalWrite(wifiLedOff, ON);
  digitalWrite(wifiLedStatus, OFF);
  digitalWrite(TurnOnOffStatus, OFF);

  //During Starting all Relays should TURN OFF
  ci74HC595Write(RelayPin1, LOW);
  ci74HC595Write(RelayPin2, LOW);
  ci74HC595Write(RelayPin3, LOW);
  ci74HC595Write(RelayPin4, LOW);
  ci74HC595Write(RelayPin5, LOW);
  ci74HC595Write(RelayPin6, LOW);
  ci74HC595Write(RelayPin7, LOW);
  ci74HC595Write(RelayPin8, LOW);
  ci74HC595Write(RelayPin9, LOW);
  ci74HC595Write(RelayPin10, LOW);
  ci74HC595Write(RelayPin11, LOW);
  ci74HC595Write(RelayPin12, LOW);
  ci74HC595Write(RelayPin13, LOW);
  ci74HC595Write(RelayPin14, LOW);
  ci74HC595Write(RelayPin15, LOW);
  ci74HC595Write(RelayPin16, LOW);
  ci74HC595Write(RelayPin17, LOW);
  ci74HC595Write(RelayPin18, LOW);
  ci74HC595Write(RelayPin19, LOW);
  ci74HC595Write(RelayPin20, LOW);
  ci74HC595Write(RelayPin21, LOW);
  ci74HC595Write(RelayPin22, LOW);
  ci74HC595Write(RelayPin23, LOW);
  ci74HC595Write(RelayPin24, LOW);
  ci74HC595Write(RelayPin25, LOW);
  ci74HC595Write(RelayPin26, LOW);
  ci74HC595Write(RelayPin27, LOW);
  ci74HC595Write(RelayPin28, LOW);
  ci74HC595Write(RelayPin29, LOW);
  ci74HC595Write(RelayPin30, LOW);
  ci74HC595Write(RelayPin31, LOW);
  ci74HC595Write(RelayPin32, LOW);

  // Initialise wifi connection
  wifiConnected = connectWifi();

  if (wifiConnected)
  {
    addDevices();
  }
  else
  {
    Serial.println("Cannot connect to WiFi. So in Manual Mode");
    delay(10000);
  }
}

void loop()
{
   if (WiFi.status() != WL_CONNECTED) {
    Serial.print("WiFi Not Connected ");
    Serial.println(wifiConnected);
    digitalWrite(wifiLedOn, OFF);
    digitalWrite(wifiLedOff, ON);
       
    delay(50000);
  } else {
    digitalWrite(wifiLedOn, ON);
    digitalWrite(wifiLedOff, OFF);

    //WiFi Control
    if (wifiConnected){
      espalexa.loop();
      delay(100);
    } else {
      wifiConnected = connectWifi(); // Initialise wifi connection
      if(wifiConnected){
        addDevices();
      }
    }
  }
}


void ci74HC595Write(byte pino, bool estado) {
  static byte ciBuffer[qtdeCI];

  bitWrite(ciBuffer[pino / 8], pino % 8, estado);
  
  digitalWrite(pinST_CP, LOW); //Start transmission
  
  digitalWrite(pinDS, LOW);    //Clear all to prepare transmission
  digitalWrite(pinSH_CP, LOW);
  
  for (int nC = qtdeCI-1; nC >= 0; nC--) {
      for (int nB = 7; nB >= 0; nB--) {
  
          digitalWrite(pinSH_CP, LOW);  //Set clock down
          
          digitalWrite(pinDS,  bitRead(ciBuffer[nC], nB) );     //Write BIT
          
          digitalWrite(pinSH_CP, HIGH); //Set clock up
          digitalWrite(pinDS, LOW);     //Set data to prevent leak
      }  
  }
  
  digitalWrite(pinST_CP, HIGH);  //Finish Transmission
}
