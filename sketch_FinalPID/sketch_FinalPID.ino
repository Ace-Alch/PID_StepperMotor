/* =============================================================================
  PID-Controlled Stepper Motor with Live Tuning via 4 Potentiometers
  ------------------------------------------------------------------------------
  Author      : Mehdi Moallemkolaei (GitHub: https://github.com/ACE-ALCH)
  Description : Real-time stepper motor position control using PID algorithm.
                Kp, Ki, and Kd values are tuned live with potentiometers.
                Serial output supports real-time plotting and debugging.
  Last Edit   : 2025-06-30
  License     : MIT License
  Version     : 1.4
============================================================================= */

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

#define POT_POS A0  // position control
#define POT_KP  A1  // Kp tuning
#define POT_KI  A2  // Ki tuning
#define POT_KD  A3  // Kd tuning

const int stepsPerRev = 400; // can be adjusted for min-max rotation
int currentPosition = 0;

// PID state
float Kp = 0, Ki = 0, Kd = 0;
float error = 0, lastError = 0;
float integral = 0, derivative = 0;
unsigned long lastPidTime = 0;

const int stepSeq[8][4] = {
  {1,0,0,0},
  {1,0,1,0},
  {0,0,1,0},
  {0,1,1,0},
  {0,1,0,0},
  {0,1,0,1},
  {0,0,0,1},
  {1,0,0,1}
};

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  lastPidTime = millis(); //timer for PID
}

void loop() {
  // === read potentiometers ===
  int rawKp = analogRead(POT_KP);
  int rawKi = analogRead(POT_KI);
  int rawKd = analogRead(POT_KD);
  
  // all the ranges below are set experimentally, and can be changed in different use cases 
  Kp = rawKp / 100.0;    // 0–10
  Ki = rawKi / 1000.0;   // 0–1
  Kd = rawKd / 100.0;    // 0–10

  int potVal = analogRead(POT_POS);
  int targetPosition = map(potVal, 0, 1023, 0, stepsPerRev);

  // === PID timing ===
  unsigned long now = millis();
  float dt = (now - lastPidTime) / 1000.0;
  if (dt <= 0) dt = 0.001;

  // === PID calculation ===
  error = targetPosition - currentPosition;
  integral += error * dt;
  derivative = (error - lastError) / dt;
  float output = Kp * error + Ki * integral + Kd * derivative;
  lastError = error;
  lastPidTime = now;

  // === stepper control ===
  if (abs(error) > 1) {
    int stepsToMove = round(constrain(output, -1000, 1000));  // anti-jitter clamp
    int direction = (stepsToMove > 0) ? 1 : -1;
    int stepDelay = 2000;  // micro-second per step

    for (int i = 0; i < abs(stepsToMove); i++) {
      currentPosition += direction;
      doStep(currentPosition);
      delayMicroseconds(stepDelay);
    }
  }

  // === serial debug ===
  float angle = (currentPosition % stepsPerRev) * (360.0 / stepsPerRev);
  //Serial.print(Kp); Serial.print(",");
  //Serial.print(Ki); Serial.print(",");
  //Serial.print(Kd); Serial.print(",");
  Serial.print(targetPosition); Serial.print(","); // not commented to be seen visually in serial plotter
  Serial.print(currentPosition); Serial.print(",");// not commented to be seen visually in serial plotter
  //Serial.print(angle); Serial.print(",");
  //Serial.print(error); Serial.print(",");
  //Serial.println(output);
  Serial.println("Kp,Ki,Kd,Target,Current,Angle,Error,Output");

  delay(10);
}

void doStep(int stepNum) {
  int idx = (stepNum % 8 + 8) % 8;
  digitalWrite(IN1, stepSeq[idx][0]);
  digitalWrite(IN2, stepSeq[idx][1]);
  digitalWrite(IN3, stepSeq[idx][2]);
  digitalWrite(IN4, stepSeq[idx][3]);
}
