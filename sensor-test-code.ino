#define LEFT_IR 2 #define RIGHT_IR 3

void setup() { pinMode(LEFT_IR, INPUT); pinMode(RIGHT_IR, INPUT);

Serial.begin(9600);

Serial.println("================================"); Serial.println(" IR SENSOR TEST"); Serial.println("================================"); }

void loop() {

int left = digitalRead(LEFT_IR); int right = digitalRead(RIGHT_IR);

Serial.print("LEFT D2 = "); Serial.print(left);

Serial.print(" RIGHT D3 = "); Serial.println(right);

delay(200); 
