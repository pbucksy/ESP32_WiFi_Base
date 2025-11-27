#include "dpWiFiManager.h"



//Some stuff so that it shows it changed...

static const BaseType_t core_0 = 0;
static const BaseType_t core_1 = 1;

int networkConnStatus = 0;

WiFiClient tcpClient;

unsigned long tcpClientTimeoutTimer = 0;
bool toggleBool = false;


String telnetMsg = "";
unsigned long battInfoTimer = 0;
unsigned long statusTimer = 0;
unsigned long checkUpdateTimer = 0;
bool isInit = true;



void setup() {  
  
  

  Serial.begin(115200);  

  //delay(1000);
  EEPROM.begin(EEPROMConfigSize); 
  debugln("In da beginning!");

  Wire.begin();
  Wire.setClock(400000);

  SPI.begin();

  
  networkConnStatus = setupNetwork();

    
}


void loop()
{
  wifiWebServer.handleClient();

  if(millis() - checkUpdateTimer > 10000)
  {
    checkUpdateTimer = millis();
    searchForUpdate();          
  }        
}

