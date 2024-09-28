#include <espnow_ROBOT.h>

ESPNOW_ROBOT ROBOT;

struct receive_JoyData {
  boolean move[4] = { 0, 1, 0, 1 };
  boolean attack[4] = { 1, 1, 1, 0 };
};
receive_JoyData Data;
 
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&Data, incomingData, sizeof(Data));
  Serial.print("move ");
    for (int i = 0; i < 4; ++i) {
      Serial.print(Data.move[i]);
      Serial.print(" ");
    }

    Serial.print(" attack ");
    for (int i = 0; i < 4; ++i) {
      Serial.print(Data.attack[i]);
      Serial.print(" ");
    }
}
 
void setup() {
  ROBOT.Setup_receive_ESPNOW();
  // Register callback function
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {
 
}