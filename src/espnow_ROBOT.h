#ifndef espnow_ROBOT
#define espnow_ROBOT

#define ESPNOW

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>


class ESPNOW_ROBOT {
public:
  esp_now_peer_info_t peerInfo;
  uint8_t broadcastAddress[6];

  ESPNOW_ROBOT(){

  }
  
  ESPNOW_ROBOT(const uint8_t broadAddress[]){
    broadcastAddress[0] = broadAddress[0];
    broadcastAddress[1] = broadAddress[1];
    broadcastAddress[2] = broadAddress[2];
    broadcastAddress[3] = broadAddress[3];
    broadcastAddress[4] = broadAddress[4];
    broadcastAddress[5] = broadAddress[5];
  }

  void MAC_Address_ESPNOW();
  void Setup_send_ESPNOW();
  void Sendvalue_ESPNOW(uint8_t* data, size_t len);
  
  void Setup_receive_ESPNOW();
};


#endif