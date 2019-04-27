#include <NewPing.h>
// trigger and echo pins for each sensor
#define SONAR 2
#define MAX_DISTANCE 1000 // maximum distance for sensors
#define BUZZER_PIN 25

#define C4 261.6
#define C#4 277.18
#define D4 293.665
#define D#4 311.127
#define E4 329.63
#define F4 349.228
#define F#4 369.994
#define G4 391.995
#define G#4 415.305
#define A4 440
#define A#4 466.164
#define B4 493.883
#define C5 523.251
#define D5 587.330
#define D_5 622.254
#define E5 659.255
#define F5 698.456
#define G5 783.991

NewPing sonar = NewPing(SONAR, SONAR, MAX_DISTANCE);

void setup() {
  ledcSetup(1, 12000, 8);
  ledcAttachPin(BUZZER_PIN, 1);

  Serial.begin(115200);
}

void playPc98() {
  ledcWriteTone(1, 2000);
  delay(100);
  ledcWriteTone(1, 1000);
  delay(100);
  ledcWriteTone(1, 0);
  delay(2000);
}
void playLevelUp() {
  int tempo = 75;
  int interval = 20;
  ledcWriteTone(1, F5);
  delay(tempo);
  ledcWriteTone(1, 0);
  delay(interval * 3);
  ledcWriteTone(1, F5);
  delay(tempo);
  ledcWriteTone(1, 0);
  delay(interval * 3);
  ledcWriteTone(1, F5);
  delay(tempo);
  ledcWriteTone(1, 0);
  delay(interval * 3);
  ledcWriteTone(1, F5);
  delay(tempo);
  ledcWriteTone(1, 0);
  delay(interval * 8);
  ledcWriteTone(1, D_5);
  delay(tempo);
  ledcWriteTone(1, 0);
  delay(interval * 8);
  ledcWriteTone(1, G5);
  delay(tempo);
  ledcWriteTone(1, 0);
  delay(interval * 8);
  ledcWriteTone(1, F5);
  delay(tempo * 3);
  ledcWriteTone(1, 0);
}

int beforeDistance = 0;
void loop() {
  delay(500);

  // print all distances
  int cm = sonar.ping_cm();
  Serial.print("Sonar distance: ");
  Serial.println(cm);
  // 前回測定から3cm以上変わったら再生する
  if (abs(beforeDistance - cm) > 3) {
    //playPc98();
    playLevelUp();
    delay(5000);
    cm = sonar.ping_cm();
    Serial.print("Sonar distance: ");
    Serial.println(cm);
  } else {
    ledcWriteTone(1, 0);
  }
  beforeDistance = cm;
}
