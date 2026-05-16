#include <Wire.h>

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128

#define SCREEN_HEIGHT 64


#define PIN_JALAN 34

#define PIN_BERHENTI 35

#define BUZZER_PIN 12


#define LED_MERAH 4

#define LED_KUNING 0

#define LED_HIJAU 2


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


unsigned long previousMillis = 0;

unsigned int timerSeconds = 0;


int currentMode = 0; 

int lastMode = 0; 


void setup() {

Serial.begin(115200);


pinMode(PIN_JALAN, INPUT);

pinMode(PIN_BERHENTI, INPUT);

pinMode(BUZZER_PIN, OUTPUT);

pinMode(LED_MERAH, OUTPUT);

pinMode(LED_KUNING, OUTPUT);

pinMode(LED_HIJAU, OUTPUT);


digitalWrite(BUZZER_PIN, LOW);

digitalWrite(LED_MERAH, LOW);

digitalWrite(LED_KUNING, LOW);

digitalWrite(LED_HIJAU, LOW);


if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 

Serial.println(F("SSD1306 allocation failed"));

for(;;);

}

display.clearDisplay();

display.setTextSize(2); 

display.setTextColor(WHITE);

display.setCursor(15, 15);

display.println("Selamat");

display.setCursor(25, 35);

display.println("Datang");

display.display();

delay(3000); 

display.clearDisplay();

}


void loop() {

int stateJalan = digitalRead(PIN_JALAN);

int stateBerhenti = digitalRead(PIN_BERHENTI);

if (stateJalan == HIGH) {

currentMode = 1; 

} else if (stateBerhenti == HIGH) {

currentMode = 2; 

}



if (currentMode != lastMode && lastMode != 0) {

digitalWrite(LED_MERAH, LOW);

digitalWrite(LED_KUNING, LOW);

digitalWrite(LED_HIJAU, LOW);

digitalWrite(BUZZER_PIN, LOW);


display.clearDisplay();

display.setTextSize(2);

display.setCursor(15, 25);

display.println("LOADING..");

display.display();

delay(500); 

timerSeconds = 0;

previousMillis = millis(); 

lastMode = currentMode;

} else if (currentMode != 0 && lastMode == 0) {

lastMode = currentMode; 

}


if (currentMode == 1) {

timerSeconds = 0; 

digitalWrite(BUZZER_PIN, LOW); 

previousMillis = millis(); 

} 

else if (currentMode == 2) {

if (millis() - previousMillis >= 1000) { 

previousMillis = millis();

timerSeconds++;

}

if (timerSeconds >= 10) {

digitalWrite(BUZZER_PIN, HIGH);

} else {

digitalWrite(BUZZER_PIN, LOW);

}

}


if (timerSeconds >= 10) {

digitalWrite(LED_MERAH, HIGH);

digitalWrite(LED_KUNING, LOW);

digitalWrite(LED_HIJAU, LOW);

} 

else if (timerSeconds >= 5 && timerSeconds <= 9) {

digitalWrite(LED_MERAH, LOW);

digitalWrite(LED_KUNING, HIGH);

digitalWrite(LED_HIJAU, LOW);

} 

else {

digitalWrite(LED_MERAH, LOW);

digitalWrite(LED_KUNING, LOW);

digitalWrite(LED_HIJAU, HIGH);

}


display.clearDisplay();

display.setTextSize(1);

display.setCursor(0, 0);

if (currentMode == 1) {

display.println("Status: POSISI JALAN");

} else if (currentMode == 2) {

if (timerSeconds >= 10) {

display.println("Status: WAKTU HABIS!");

} else {

display.println("Status: GPS ON (DIAM)");

}

} else {

display.println("Status: MENUNGGU..");

}


display.setTextSize(3); 

display.setCursor(20, 25);

int minutes = timerSeconds / 60;

int seconds = timerSeconds % 60;

char timeString[6];

sprintf(timeString, "%02d:%02d", minutes, seconds);

display.println(timeString);


display.display();

}

#include <Wire.h>

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128

#define SCREEN_HEIGHT 64


#define PIN_JALAN 34

#define PIN_BERHENTI 35

#define BUZZER_PIN 12


#define LED_MERAH 4

#define LED_KUNING 0

#define LED_HIJAU 2


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


unsigned long previousMillis = 0;

unsigned int timerSeconds = 0;


int currentMode = 0; 

int lastMode = 0; 


void setup() {

Serial.begin(115200);


pinMode(PIN_JALAN, INPUT);

pinMode(PIN_BERHENTI, INPUT);

pinMode(BUZZER_PIN, OUTPUT);

pinMode(LED_MERAH, OUTPUT);

pinMode(LED_KUNING, OUTPUT);

pinMode(LED_HIJAU, OUTPUT);


digitalWrite(BUZZER_PIN, LOW);

digitalWrite(LED_MERAH, LOW);

digitalWrite(LED_KUNING, LOW);

digitalWrite(LED_HIJAU, LOW);


if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 

Serial.println(F("SSD1306 allocation failed"));

for(;;);

}

display.clearDisplay();

display.setTextSize(2); 

display.setTextColor(WHITE);

display.setCursor(15, 15);

display.println("Selamat");

display.setCursor(25, 35);

display.println("Datang");

display.display();

delay(3000); 

display.clearDisplay();

}


void loop() {

int stateJalan = digitalRead(PIN_JALAN);

int stateBerhenti = digitalRead(PIN_BERHENTI);

if (stateJalan == HIGH) {

currentMode = 1; 

} else if (stateBerhenti == HIGH) {

currentMode = 2; 

}



if (currentMode != lastMode && lastMode != 0) {

digitalWrite(LED_MERAH, LOW);

digitalWrite(LED_KUNING, LOW);

digitalWrite(LED_HIJAU, LOW);

digitalWrite(BUZZER_PIN, LOW);


display.clearDisplay();

display.setTextSize(2);

display.setCursor(15, 25);

display.println("LOADING..");

display.display();

delay(500); 

timerSeconds = 0;

previousMillis = millis(); 

lastMode = currentMode;

} else if (currentMode != 0 && lastMode == 0) {

lastMode = currentMode; 

}


if (currentMode == 1) {

timerSeconds = 0; 

digitalWrite(BUZZER_PIN, LOW); 

previousMillis = millis(); 

} 

else if (currentMode == 2) {

if (millis() - previousMillis >= 1000) { 

previousMillis = millis();

timerSeconds++;

}

if (timerSeconds >= 10) {

digitalWrite(BUZZER_PIN, HIGH);

} else {

digitalWrite(BUZZER_PIN, LOW);

}

}


if (timerSeconds >= 10) {

digitalWrite(LED_MERAH, HIGH);

digitalWrite(LED_KUNING, LOW);

digitalWrite(LED_HIJAU, LOW);

} 

else if (timerSeconds >= 5 && timerSeconds <= 9) {

digitalWrite(LED_MERAH, LOW);

digitalWrite(LED_KUNING, HIGH);

digitalWrite(LED_HIJAU, LOW);

} 

else {

digitalWrite(LED_MERAH, LOW);

digitalWrite(LED_KUNING, LOW);

digitalWrite(LED_HIJAU, HIGH);

}


display.clearDisplay();

display.setTextSize(1);

display.setCursor(0, 0);

if (currentMode == 1) {

display.println("Status: POSISI JALAN");

} else if (currentMode == 2) {

if (timerSeconds >= 10) {

display.println("Status: WAKTU HABIS!");

} else {

display.println("Status: GPS ON (DIAM)");

}

} else {

display.println("Status: MENUNGGU..");

}


display.setTextSize(3); 

display.setCursor(20, 25);

int minutes = timerSeconds / 60;

int seconds = timerSeconds % 60;

char timeString[6];

sprintf(timeString, "%02d:%02d", minutes, seconds);

display.println(timeString);


display.display();

}


