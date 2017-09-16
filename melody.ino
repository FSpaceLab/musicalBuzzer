int buzzer = 9;
int button = 2;

// ноти та їх частоти
int frq[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 
             554, 587, 622, 659, 698, 740, 0, 247, 233, 220, 208, 196, 185, 174};

int f0=frq[26], f_dies0=frq[25],
    g0=frq[24], g_dies0=frq[23],
    a0=frq[22], a_dies0=frq[21],
    h0=frq[20],
    c=frq[0], c_dies=frq[1], 
    d=frq[2], d_dies=frq[3], 
    e=frq[4], 
    f=frq[5], f_dies=frq[6], 
    g=frq[7], g_dies=frq[8], 
    a=frq[9], a_dies=frq[10], 
    h=frq[11], 
    c2=frq[12], c_dies2=frq[13], 
    d2=frq[14], d_dies2=frq[15], 
    e2=frq[16], 
    f2=frq[17], f_dies2=frq[18], 
    nul=frq[19];

// тривалість нот
int SEMIB  = 700; // semibreve - ціла нота
int HALF = 350;    // half-note - половинна нота
int QUART = 175;   // quarter note - четвертинна нота

int POINT = 150;   

int PAUSE = 0;

int count = 0;

// мелодії
int sword_areas[] = {c,SEMIB, c,SEMIB, c,HALF, d,HALF, d_dies,HALF, 
                    c,HALF, d,SEMIB, d,SEMIB, d,SEMIB, d,HALF, d_dies,HALF, 
                    f,SEMIB, f,SEMIB, f,HALF, d_dies,HALF, d,HALF,
                    c,HALF, d_dies,SEMIB, c,SEMIB, c,SEMIB};
                    
int star_wars[] = {g,SEMIB, g,SEMIB, g,SEMIB, d_dies,HALF+POINT, a_dies,QUART, 
                   g,SEMIB, d_dies,HALF+POINT, a_dies,QUART, g,SEMIB, nul,PAUSE+SEMIB, 
                   d2,SEMIB, d2,SEMIB, d2,SEMIB, d_dies2,HALF+POINT, a_dies,QUART, 
                   f_dies,SEMIB, d_dies,HALF+POINT, a_dies,QUART, g,SEMIB, nul,PAUSE+SEMIB,};

int slaven[] = {e,SEMIB+POINT, e,HALF,  e,HALF,  d,HALF,  e,HALF,  f,HALF, g,SEMIB+POINT, 
                f,HALF, e,SEMIB, d,SEMIB, c,SEMIB, e,SEMIB, h0,SEMIB, e,SEMIB,
                a0,HALF, g_dies0,HALF, a0,HALF, h0,HALF, c,SEMIB, d,SEMIB,
                e,SEMIB+POINT, e,HALF,  e,HALF,  d,HALF,  e,HALF,  f,HALF, g,SEMIB+POINT, 
                f,HALF, e,SEMIB, d,SEMIB, c,SEMIB, a0,SEMIB, e,SEMIB, g_dies0,SEMIB,
                a0,SEMIB+SEMIB, a0,SEMIB};

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  pinMode(button, INPUT);
}

void loop() {
  if (digitalRead(button) == LOW){
    if (count == 0)
      play(slaven, sizeof(slaven)/2);
    else if (count == 1)
      play(sword_areas, sizeof(sword_areas)/2); 
    else if (count == 2)
      play(star_wars, sizeof(star_wars)/2); 
    count++;
  }
    
}

void play(int*melody, int len){
  delay(750);
  for (int i = 0; i < len; i++){
    tone(buzzer, melody[i]);
    delay(melody[++i]);
    noTone(buzzer);
    delay(75);
    if (digitalRead(button) == LOW) 
      break;
  }
}



