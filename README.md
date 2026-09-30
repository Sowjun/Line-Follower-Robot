# 2-IR Line Following Robot 🤖

A simple **Arduino UNO based line-following robot** using two IR sensors and an L293D motor driver.

## Hardware

* Arduino UNO
* L293D Motor Driver
* 2 × DC Gear Motors
* 2 × IR Line Sensors
* 9V Battery
* Robot Chassis & Wheels

## ⚙️ Pin Configuration

| Component       | Arduino Pin |
| --------------- | ----------- |
| Left IR Sensor  | D2          |
| Right IR Sensor | D3          |
| L293D ENA       | D5          |
| L293D ENB       | D6          |
| L293D IN1       | D7          |
| L293D IN2       | D8          |
| L293D IN3       | D9          |
| L293D IN4       | D10         |

**Sensor Logic:** Black = LOW, White = HIGH

##  Features

* 2-IR sensor line detection
* Automatic left/right correction
* PWM motor speed control
* Serial Monitor status output
* Tinkercad simulation ready

##  Files

* `line_follower.ino` — Arduino code
* `circuit.png` — Circuit diagram
* `line_follower.brd` — Board/design file

##  Usage

1. Open the `.ino` file in Arduino IDE or Tinkercad.
2. Upload the code to Arduino UNO.
3. Verify the wiring using the circuit diagram.
4. Open Serial Monitor at **9600 baud**.
5. Place the robot on a black line over a white surface.

##  Serial Output

```text
LEFT=1  RIGHT=1  | WHITE + WHITE -> FORWARD
LEFT=0  RIGHT=1  | BLACK + WHITE -> TURN LEFT
LEFT=1  RIGHT=0  | WHITE + BLACK -> TURN RIGHT
LEFT=0  RIGHT=0  | JUNCTION / STOP
```

## 📄 License

Open for educational and non-commercial use.
