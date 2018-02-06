#define N 5
#define VELOCITY 100
int states[N] = {LOW,LOW,LOW,LOW,LOW};
int transits[N]  = {LOW,LOW,LOW,LOW,LOW}; 
int leds[N] = {3,4,5,6,7};
int switches[N] = {8,9,10,11,12};
int notes[N] = {64,68,72,76,80};
int reading;


// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(31250);
  
  for (int i=0 ;i<N ;i++)
  {
    pinMode(leds[i], OUTPUT);    
    pinMode(switches[i],INPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  
  
 
  
  for (int i=0;i<N;i++)
  {
     reading = digitalRead(switches[i]);
     if (reading != transits[i])
     {
       transits[i] = reading;
       
       if(!reading)
       {
           states[i] = !states[i];
           if (states[i]) 
           {
              noteOn(0x90, notes[i], VELOCITY);
           }
           else
           {
             noteOn(0x90, notes[i], 0);
           }     
           digitalWrite(leds[i], states[i]);
       }
       
     }
        
  }
  
  delay(50);              
 
}

void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
