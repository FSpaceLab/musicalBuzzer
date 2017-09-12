int buzzer = 9;
int button = 2;

// ноти та їх частоти
int frq[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 
             554, 587, 622, 659, 698, 740, 0, 247, 233, 220, 208, 196, 185, 174};

int fa0=frq[26], fa_dies0=frq[25],
    sol0=frq[24], sol_dies0=frq[23],
    la0=frq[22], la_dies0=frq[21],
    si0=frq[20],
    doo=frq[0], do_dies=frq[1], 
    re=frq[2], re_dies=frq[3], 
    mi=frq[4], 
    fa=frq[5], fa_dies=frq[6], 
    sol=frq[7], sol_dies=frq[8], 
    la=frq[9], la_dies=frq[10], 
    si=frq[11], 
    doo2=frq[12], doo_dies2=frq[13], 
    re2=frq[14], re_dies2=frq[15], 
    mi2=frq[16], 
    fa2=frq[17], fa_dies2=frq[18], 
    nul=frq[19];

// тривалість нот
int SEMIB  = 700; // semibreve - ціла нота
int HALF = 350;    // half-note - половинна нота
int QUART = 175;   // quarter noet - четвертинна нота

int POINT = 150;   

int PAUSE = 0;

int count = 0;

// мелодії
int sword_areas[] = {doo,SEMIB, doo,SEMIB, doo,HALF, re,HALF, re_dies,HALF, 
                    doo,HALF, re,SEMIB, re,SEMIB, re,SEMIB, re,HALF, re_dies,HALF, 
                    fa,SEMIB, fa,SEMIB, fa,HALF, re_dies,HALF, re,HALF,
                    doo,HALF, re_dies,SEMIB, doo,SEMIB, doo,SEMIB};
                    
int star_wars[] = {sol,SEMIB, sol,SEMIB, sol,SEMIB, re_dies,HALF+POINT, la_dies,QUART, 
                   sol,SEMIB, re_dies,HALF+POINT, la_dies,QUART, sol,SEMIB, nul,PAUSE+SEMIB, 
                   re2,SEMIB, re2,SEMIB, re2,SEMIB, re_dies2,HALF+POINT, la_dies,QUART, 
                   fa_dies,SEMIB, re_dies,HALF+POINT, la_dies,QUART, sol,SEMIB, nul,PAUSE+SEMIB,};

int slaven[] = {mi,SEMIB+POINT, mi,HALF,  mi,HALF,  re,HALF,  mi,HALF,  fa,HALF, sol,SEMIB+POINT, 
                fa,HALF, mi,SEMIB, re,SEMIB, doo,SEMIB, mi,SEMIB, si0,SEMIB, mi,SEMIB,
                la0,HALF, sol_dies0,HALF, la0,HALF, si0,HALF, doo,SEMIB, re,SEMIB,
                mi,SEMIB+POINT, mi,HALF,  mi,HALF,  re,HALF,  mi,HALF,  fa,HALF, sol,SEMIB+POINT, 
                fa,HALF, mi,SEMIB, re,SEMIB, doo,SEMIB, la0,SEMIB, mi,SEMIB, sol_dies0,SEMIB,
                la0,SEMIB+SEMIB, la0,SEMIB};

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  pinMode(button, INPUT);
}

void loop() {
  if (digitalRead(button) == LOW){
    if (count == 0)
      play(slaven, sizeof(sword_areas)/2);
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



