#include <toneAC.h>
unsigned long newTime;

int Buzzer = 11;
int Buttons[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13};

void setup() {
  Serial.begin(9600);
  newTime = millis();
  pinMode(Buzzer, OUTPUT);
  pinMode(Buttons[0], INPUT_PULLUP);
  pinMode(Buttons[1], INPUT_PULLUP);
  pinMode(Buttons[2], INPUT_PULLUP);
  pinMode(Buttons[3], INPUT_PULLUP);
  pinMode(Buttons[4], INPUT_PULLUP);
  pinMode(Buttons[5], INPUT_PULLUP);
  pinMode(Buttons[6], INPUT_PULLUP);
  pinMode(Buttons[7], INPUT_PULLUP);
  pinMode(Buttons[8], INPUT_PULLUP);
  pinMode(Buttons[9], INPUT_PULLUP);
  pinMode(Buttons[10], INPUT_PULLUP);
  pinMode(Buttons[11], INPUT_PULLUP);
}

void loop() {
  if(digitalRead(Boton0) == LOW){
    Serial.println('Do');
    newBizz(130.813, 131.313);
  }

  if(digitalRead(Boton5) == LOW){
    Serial.println('Do#');
    newBizz(138.591, 139.091);
  }

  if(digitalRead(Boton1) == LOW){
    Serial.println('Re');
    newBizz(146.832, 147.332);
  }

  if(digitalRead(Boton6) == LOW){
    Serial.println('Re#');
    newBizz(155.563, 156.063);
  }

  if(digitalRead(Boton2) == LOW){
    Serial.println('Mi');
    newBizz(164.814, 165.314);
  }

  if(digitalRead(Boton3) == LOW){
   Serial.println('Fa');
    newBizz(174.614, 175.114);
  }

  if(digitalRead(Boton7) == LOW){
    Serial.println('Fa#');
    newBizz(184.997, 185.497);
  }

  if(digitalRead(Boton4) == LOW){
    Serial.println('Sol');
    newBizz(195.998, 196.498);
  }

  if(digitalRead(Boton8) == LOW){
    Serial.println('Sol#');
    newBizz(207.652, 208.152);
  }

  if(digitalRead(Boton9) == LOW){
    Serial.println('La');
    newBizz(220.000, 220.500);
  }

  if(digitalRead(Boton10) == LOW){
    Serial.println('La#');
    newBizz(233.082, 233.582);
  }

  if(digitalRead(Boton11) == LOW){
    Serial.println('Si');
    newBizz(246.942, 247.442);
  }

  if(digitalRead(Boton12) == LOW){
    Serial.println('Do4');
    newBizz(261.626, 262.126);
  }
  delay(100);
}

void newBizz(float Sound1, float Sound2){
  unsigned long TimeNow;
  unsigned long longerTime;
  longerTime = millis();
  longerTime = TimeNow - newTime;
  if(longerTime >= 1000){{
    for(float i = Sound1; i <= Sound2; i+=0.001){
      toneAC(Buzzer, i, 100);
      delay(3000000);
    }
    for(float i = Sound2; i <= Sound1; i-=0.001){
      toneAC(Buzzer, i, 100);
      delay(3000000);
    }}
  } else {
    toneAC(Buzzer, Sound1, 100);
  }
}