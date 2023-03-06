const int NUMBER_OF_LEDS = 10;

int leds[NUMBER_OF_LEDS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
    for (int i = 0; i < NUMBER_OF_LEDS; i++)
        pinMode(leds[i], OUTPUT);
}

//stinge <nrLeds> led-uri la pinii <leds[]>
void turnOffLeds(int leds[], int nrLeds, int delayTime = 100) {
    for (int i = 0; i < nrLeds; i++)
        digitalWrite(leds[i], LOW);
    delay(delayTime);
}

//aprinde <nrLeds> led-uri la pinii <leds[]>
void turnOnLeds(int leds[], int nrLeds) {
    for (int i = 0; i < nrLeds; i++)
        digitalWrite(leds[i], HIGH);    
}

//aprinde <nrLeds> led-uri la pinii <leds[]> de la stanga la dreapta pe rand cu dealy-ul <delayTime>
void lftToRgt(int leds[], int nrLeds, int delayTime = 100) {
    for (int i = 0; i < nrLeds; i++) {
        digitalWrite(leds[i], HIGH);
        delay(delayTime);    
    }
    turnOffLeds(leds, nrLeds);
}

//aprinde <nrLeds> led-uri la pinii <leds[]> de la dreapta la stange pe rand cu dealy-ul <dealyTime>
void rgtToLft(int leds[], int nrLeds, int delayTime = 100) {
    for (int i = nrLeds - 1; i >= 0; i--) {
        digitalWrite(leds[i], HIGH);
        delay(delayTime);      
    }
    turnOffLeds(leds, nrLeds);
}

//<nrLeds> led-uri la pinii <leds> se aprind si se sting de <nrBlinks> ori cu delay-ul <delayTime>
void blk(int leds[], int nrLeds, int nrBlinks, int delayTime = 100) {
    for (int i = 0; i < nrBlinks; i++) {
        turnOnLeds(leds, nrLeds);
        delay(delayTime);
        turnOffLeds(leds, nrLeds);
    }
}

//numara de la 0 la <nrMax> si afiseaza numerele in reprezentare binara pe <nrLeds> led-uri la pinii <leds[]> 
//cu delay-ul <delayTime>
void binaryCount(int leds[], int nrLeds, int nrMax, int delayTime = 100) {
    bool state[nrLeds] = {0};
    int x = 0;
    while (x <= nrMax) {
        int aux = x;
        int k = nrLeds - 1;
        while (aux) {
            state[k] = aux & 1;
            aux = aux >> 1;        
            k--;
        }
        for (int i = 0; i < nrLeds; i++)
            digitalWrite(leds[i], state[i]);
        x++;    
        delay(delayTime);
    }
    turnOffLeds(leds, nrLeds);
}

//aprinde <nrLeds> led-uri la pinii <leds[]> din exterion inspre interior cu delay-ul <dealyTime>
void outToIn(int leds[], int nrLeds, int delayTime = 100) {
    for (int i = 0, j = nrLeds - 1; i <= nrLeds / 2, j >= nrLeds / 2; i++, j--) {
        digitalWrite(leds[i], HIGH);
        digitalWrite(leds[j], HIGH);
        delay(delayTime);    
    }    
    turnOffLeds(leds, nrLeds);
}

//aprinde <nrLeds> led-uri la pinii <leds[]> din intrior inspre exterior cu delay-ul <delayTime>
void inToOut(int leds[], int nrLeds, int delayTime = 100) {
    for (int i = nrLeds / 2 - 1, j = nrLeds / 2; i >= 0, j < nrLeds; i--, j++) {
        digitalWrite(leds[i], HIGH);
        digitalWrite(leds[j], HIGH);
        delay(delayTime);    
    }  
    turnOffLeds(leds, nrLeds);
}

//aprinde alternativ <nrLeds> led-uri la pinii <leds[]> mai intati led-urile de pe pozitii pare, apoi
//cele pe pozitii impare de <nrBlinks> ori cu delay-ul <delayTime>
void altBlk(int leds[], int nrLeds, int nrBlinks, int delayTime = 100) {
    for (int i = 0; i < nrBlinks; i++) {
        for (int j = 0; j < nrLeds; j += 2) 
            digitalWrite(leds[j], HIGH);
        delay(delayTime);    
        turnOffLeds(leds, nrLeds);
        for (int j = 1; j < nrLeds; j += 2) 
            digitalWrite(leds[j], HIGH);   
        delay(delayTime);
        turnOffLeds(leds, nrLeds);
    }    
}

//led-urile "se misca" de la stanga la drepata cu delay-ul <delayTime> si se afiseaza pe 
//<nrLeds> led-uri la pinii <leds[]>
void shiftRight(int leds[], int nrLeds, int delayTime = 100) {
    for (int i = 0; i < nrLeds * 2; i++) {
        for (int j = i; j >= i - nrLeds; j--)
            if (j >= 0 && j < nrLeds)
                digitalWrite(leds[j], HIGH);          
        delay(delayTime);
        for (int j = i; j >= i - nrLeds; j--)
            if (j >= 0 && j < nrLeds)
                digitalWrite(leds[j], LOW);    
        
    }
    turnOffLeds(leds, nrLeds);        
}

//led-urile "se misca" de la dreapta la stanga cu delay-ul <delayTime> si se afiseaza pe 
//<nrLeds> led-uri la pinii <leds[]>
void shiftLeft(int leds[], int nrLeds, int delayTime = 100) {
    for (int i = nrLeds - 1; i > -nrLeds; i--) {
        for (int j = i; j < i + nrLeds; j++)
            if (j >= 0 && j < nrLeds)
                digitalWrite(leds[j], HIGH);
        delay(delayTime);
        for (int j = i; j < i + nrLeds; j++)
            if (j >= 0 && j < nrLeds)
                digitalWrite(leds[j], LOW);
    }
    turnOffLeds(leds, nrLeds);    
}

//led-urile "se misca" alternativ de la stanga la drepata cu delay-ul <delayTime> si se afiseaza pe 
//<nrLeds> led-uri la pinii <leds[]>
void altShiftRight(int leds[], int nrLeds, int delayTime = 100) {
    for (int i = 0; i < nrLeds * 2; i++) {
        for (int j = i; j >= i - nrLeds; j -= 2)
            if (j >= 0 && j < nrLeds)
                digitalWrite(leds[j], HIGH);          
        delay(delayTime);
        for (int j = i; j >= i - nrLeds; j -= 2)
            if (j >= 0 && j < nrLeds)
                digitalWrite(leds[j], LOW);    
        
    }
    turnOffLeds(leds, nrLeds);        
}

//led-urile "se misca" alrenativ de la dreapta la stanga cu delay-ul <delayTime> si se afiseaza pe 
//<nrLeds> led-uri la pinii <leds[]>
void altShiftLeft(int leds[], int nrLeds, int delayTime = 100) {
    for (int i = nrLeds - 1; i > -nrLeds; i--) {
        for (int j = i; j < i + nrLeds; j += 2)
            if (j >= 0 && j < nrLeds)
                digitalWrite(leds[j], HIGH);
        delay(delayTime);
        for (int j = i; j < i + nrLeds; j += 2)
            if (j >= 0 && j < nrLeds)
                digitalWrite(leds[j], LOW);
    }
    turnOffLeds(leds, nrLeds);    
}

void loop() {
    lftToRgt(leds, NUMBER_OF_LEDS, 50);
    rgtToLft(leds, NUMBER_OF_LEDS, 50);
    blk(leds, NUMBER_OF_LEDS, 3);
    altShiftRight(leds, NUMBER_OF_LEDS, 200);
    altShiftLeft(leds, NUMBER_OF_LEDS, 200);
    blk(leds, NUMBER_OF_LEDS, 2);
    outToIn(leds, NUMBER_OF_LEDS);
    inToOut(leds, NUMBER_OF_LEDS);
    altBlk(leds, NUMBER_OF_LEDS, 6);
    shiftRight(leds, NUMBER_OF_LEDS);
    shiftLeft(leds, NUMBER_OF_LEDS);
    altBlk(leds, NUMBER_OF_LEDS, 6);
    lftToRgt(leds, NUMBER_OF_LEDS, 50);
    rgtToLft(leds, NUMBER_OF_LEDS, 50);
    binaryCount(leds, NUMBER_OF_LEDS, 1023, 10);
}
