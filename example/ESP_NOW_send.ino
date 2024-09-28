#include <espnow_ROBOT.h>

uint8_t broadAddress[6] = { 0x08, 0xD1, 0xF9, 0xE9, 0xA2, 0x24 };
ESPNOW_ROBOT joy(broadAddress);

struct ControllerData {
  boolean move[4] = { 0, 1, 0, 1 };
  boolean attack[4] = { 1, 1, 1, 0 };
};
ControllerData Joy;

void setup() {
  joy.Setup_send_ESPNOW();
}

void loop() {
  joy.Sendvalue_ESPNOW((uint8_t*)&Joy, sizeof(Joy));
}
