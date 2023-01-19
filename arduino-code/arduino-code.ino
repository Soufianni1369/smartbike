#include <FastLED.h>

#define trigPin 3
#define echoPin 2

#define trigPin2 6
#define echoPin2 7



#define LED_PIN 5
#define NUM_LEDS 5
CRGB leds[NUM_LEDS];


long tijd;
int afstand;
int afstand2;


void setup() {

FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
pinMode(8, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
Serial.begin(9600);
}



void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

tijd = pulseIn(echoPin, HIGH);

afstand = tijd * 0.034 / 2;

Serial.print("Afstand op dit moment ");

Serial.print(afstand);
Serial.println(" cm");
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);

digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);

tijd = pulseIn(echoPin2, HIGH);

afstand2 = tijd * 0.034 / 2;

Serial.print("Afstand2 op dit moment ");
Serial.print(afstand2);
Serial.println(" cm");


if (afstand <= 100)

{
digitalWrite(13, HIGH);
Serial.println("o nee je gaat zo dood");
leds[0] = CRGB(100, 0, 0);
FastLED.show();
leds[1] = CRGB(100, 0, 0);
FastLED.show();
leds[2] = CRGB(100, 0, 0);
FastLED.show();
leds[3] = CRGB(100, 0, 0);
FastLED.show();
leds[4] = CRGB(100, 0, 0);
FastLED.show();
delay(2500);
}


else if (afstand2 <= 500) {
Serial.println("o nee je gaat zo dood");
digitalWrite(13, HIGH);
leds[0] = CRGB(0, 0, 0);
FastLED.show();
leds[1] = CRGB(0, 0, 0);
FastLED.show();
leds[2] = CRGB(100, 64, 0);
FastLED.show();
leds[3] = CRGB(0, 0, 0);
FastLED.show();
leds[4] = CRGB(0, 0, 0);
FastLED.show();
}


else if (afstand2 >= 500) {
digitalWrite(13, HIGH);
leds[0] = CRGB(0, 50, 0);
FastLED.show();
leds[1] = CRGB(0, 50, 0);
FastLED.show();
leds[2] = CRGB(0, 50, 0);
FastLED.show();
leds[3] = CRGB(0, 50, 0);
FastLED.show();
leds[4] = CRGB(0, 50, 0);
FastLED.show();
}
}