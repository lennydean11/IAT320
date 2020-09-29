#include <Adafruit_CircuitPlayground.h>

//creating color presets
int presets [2][2][3] = {
  {{0,0,255},{0,255,0}},
  {{255,0,0},{0,255,0}}
};

int preset = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  //Accelerometer to detect motion
  float acc = abs(CircuitPlayground.motionX()) + abs(CircuitPlayground.motionY()) + abs(CircuitPlayground.motionZ());
  if (acc > 25) {
    preset = rand() % 3;
  }

  
  //using LEDs to light up the board
  for (int i=0; i<10; i++){
    CircuitPlayground.setPixelColor(i, presets[preset][i%2][0], presets[preset][i%2][1], presets[preset][i%2][2]);
  }


}
