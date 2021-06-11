const int FIRST_FINGER = 2;
const int SECOND_FINGER = 3;
const int THIRD_FINGER = 4;
const int FOURTH_FINGER = 5;
const int G_STRING = 6;
const int D_STRING = 7;
const int A_STRING = 8;
const int E_STRING = 9;
const int inputs[] = {
  FIRST_FINGER,
  SECOND_FINGER,
  THIRD_FINGER,
  FOURTH_FINGER,
  G_STRING,
  D_STRING,
  A_STRING,
  E_STRING};
void setup() {
  Serial.begin(19200);
  for (int i = 2; i < 9; i++){
    pinMode(i, INPUT);
  }
}

void loop() {
  int finger_midi_inc = 0 ;
  int string_midi_base = 0;
  for(int i = 0; i < 2500; i++){
    if (digitalRead(FIRST_FINGER)){
      finger_midi_inc = 2;
    } else if (digitalRead(SECOND_FINGER)) {
      finger_midi_inc = 4;
    } else if (digitalRead(THIRD_FINGER)) {
      finger_midi_inc = 5;
    } else if (digitalRead(FOURTH_FINGER)) {
      finger_midi_inc = 7;
    }
    
    if (digitalRead(G_STRING)) {
      string_midi_base = 55;
    } else if(digitalRead(D_STRING)) {
      string_midi_base = 62;
    } else if(digitalRead(A_STRING)) {
      string_midi_base = 69;
    } else if(digitalRead(E_STRING)) {
      string_midi_base = 76;
    }
    if(string_midi_base && finger_midi_inc){
      break;
    }
  }
  
  
  if (string_midi_base) {
    if (string_midi_base > 62 && finger_midi_inc == 4){
      finger_midi_inc = 3;
    }
    Serial.write(string_midi_base + finger_midi_inc);
  } else {
    Serial.write(0);
  }
}
