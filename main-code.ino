// ============================================================ // 2-IR LINE FOLLOWING ROBOT // ============================================================ // Hardware: // Arduino UNO // L293D Motor Driver // 2 DC Motors // 2 IR Line Sensors // // Tinkercad Configuration: // // IR Sensors: // LEFT -> D2 // RIGHT -> D3 // // L293D: // ENA -> D5 // IN1 -> D7 // IN2 -> D8 // // ENB -> D6 // IN3 -> D9 // IN4 -> D10 // // Sensor logic: // BLACK = LOW // WHITE = HIGH // ============================================================

// ============================================================ // IR SENSOR PINS // ============================================================

#define LEFT_IR 2 #define RIGHT_IR 3

// ============================================================ // L293D MOTOR PINS // ============================================================

// LEFT MOTOR #define ENA 5 #define IN1 7 #define IN2 8

// RIGHT MOTOR #define ENB 6 #define IN3 9 #define IN4 10

// ============================================================ // SPEED SETTINGS // ============================================================

int normalSpeed = 170;

int turnSpeed = 180;

int slowMotorSpeed = 50;

// ============================================================ // SETUP // ============================================================

void setup() { // IR sensors pinMode(LEFT_IR, INPUT); pinMode(RIGHT_IR, INPUT);

// L293D motor pins pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);

pinMode(ENB, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);

// Serial Monitor Serial.begin(9600);

// Safety: motors stopped initially stopMotors();

// Startup information Serial.println(); Serial.println("========================================"); Serial.println(" 2-IR LINE FOLLOWING ROBOT"); Serial.println("========================================");

Serial.println("Arduino UNO + L293D"); Serial.println();

Serial.println("IR SENSOR CONNECTION:"); Serial.println("LEFT IR -> D2"); Serial.println("RIGHT IR -> D3");

Serial.println();

Serial.println("MOTOR CONNECTION:"); Serial.println("LEFT MOTOR -> L293D 1Y / 2Y"); Serial.println("RIGHT MOTOR -> L293D 3Y / 4Y");

Serial.println();

Serial.println("SENSOR LOGIC:"); Serial.println("BLACK = LOW"); Serial.println("WHITE = HIGH");

Serial.println("----------------------------------------"); Serial.println("Robot starting..."); Serial.println("----------------------------------------");

delay(1500); }

// ============================================================ // MAIN LOOP // ============================================================

void loop() { // ---------------------------------------------------------- // Read sensors // ----------------------------------------------------------

int leftSensor = digitalRead(LEFT_IR); int rightSensor = digitalRead(RIGHT_IR);

// ---------------------------------------------------------- // Print raw sensor values // ----------------------------------------------------------

Serial.print("LEFT="); Serial.print(leftSensor);

Serial.print(" RIGHT="); Serial.print(rightSensor);

Serial.print(" | ");

// ========================================================== // CONDITION 1 // BOTH WHITE // ========================================================== // // The line is between the two sensors. // // Robot moves straight. //

if (leftSensor == HIGH && rightSensor == HIGH) { Serial.println("WHITE + WHITE -> FORWARD");

moveForward(normalSpeed);
}

// ========================================================== // CONDITION 2 // LEFT BLACK / RIGHT WHITE // ========================================================== // // Line detected on left. // // Slow left motor. // Keep right motor faster. //

else if (leftSensor == LOW && rightSensor == HIGH) { Serial.println("BLACK + WHITE -> TURN LEFT");

turnLeft();
}

// ========================================================== // CONDITION 3 // LEFT WHITE / RIGHT BLACK // ========================================================== // // Line detected on right. // // Keep left motor faster. // Slow right motor. //

else if (leftSensor == HIGH && rightSensor == LOW) { Serial.println("WHITE + BLACK -> TURN RIGHT");

turnRight();
}

// ========================================================== // CONDITION 4 // BOTH BLACK // ========================================================== // // Both sensors detect the black line. // // This can indicate: // - junction // - thick line // - end marker // // For this version we stop. //

else { Serial.println("BLACK + BLACK -> JUNCTION / STOP");

stopMotors();
}

// Small delay for stable Tinkercad simulation delay(40); }

// ============================================================ // MOVE FORWARD // ============================================================

void moveForward(int speedValue) { // ---------------------------------------------------------- // LEFT MOTOR FORWARD // ----------------------------------------------------------

digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);

// ---------------------------------------------------------- // RIGHT MOTOR FORWARD // ----------------------------------------------------------

digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);

// ---------------------------------------------------------- // PWM SPEED // ----------------------------------------------------------

analogWrite(ENA, speedValue); analogWrite(ENB, speedValue); }

// ============================================================ // TURN LEFT // ============================================================

void turnLeft() { // ---------------------------------------------------------- // LEFT MOTOR SLOW // ----------------------------------------------------------

digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);

// ---------------------------------------------------------- // RIGHT MOTOR FAST // ----------------------------------------------------------

digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);

analogWrite(ENA, slowMotorSpeed); analogWrite(ENB, turnSpeed); }

// ============================================================ // TURN RIGHT // ============================================================

void turnRight() { // ---------------------------------------------------------- // LEFT MOTOR FAST // ----------------------------------------------------------

digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);

// ---------------------------------------------------------- // RIGHT MOTOR SLOW // ----------------------------------------------------------

digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);

analogWrite(ENA, turnSpeed); analogWrite(ENB, slowMotorSpeed); }

// ============================================================ // STOP MOTORS // ============================================================

void stopMotors() { // Disable both motors analogWrite(ENA, 0); analogWrite(ENB, 0);

// Stop left motor digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);

// Stop right motor digitalWrite(IN3, LOW); digitalWrite(IN4, LOW); }
