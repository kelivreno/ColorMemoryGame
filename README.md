# Color Memory Game

A Simon-style color memory game built with an Arduino Uno. The game generates a sequence of colors using four LEDs, and the player must repeat the sequence using the corresponding buttons.

Each successful round increases the sequence length, making the game progressively harder.

## How It Works

1. The Arduino generates a random color sequence.
2. The LEDs display the sequence to the player.
3. The player repeats the sequence using the four buttons.
4. The game checks each input against the generated sequence.
5. If the sequence is correct, the player advances to the next level.
6. If the player presses the wrong button, the game ends.

## Hardware

* Arduino Uno R3
* 4 LEDs
* 4 push buttons
* 220Ω resistors
* Passive buzzer
* Breadboard
* Jumper wires

## Pin Configuration

| Component | Arduino Pin |
| --------- | ----------: |
| Button 1  |           2 |
| Button 2  |           3 |
| Button 3  |           4 |
| Button 4  |           5 |
| LED 1     |           6 |
| LED 2     |           7 |
| LED 3     |           8 |
| LED 4     |           9 |
| Buzzer    |          11 |

The buttons use Arduino's internal `INPUT_PULLUP` resistors, so a pressed button reads `LOW`.

## Game Logic

The game stores the generated pattern inside an array:

```cpp
int sequence[100];
```

The current difficulty is tracked using:

```cpp
int level = 1;
```

As the player progresses, the game displays more elements from the sequence and requires the player to reproduce them correctly.

The project uses concepts including:

* Arrays
* `for` and `while` loops
* Functions
* Boolean values
* Random number generation
* Digital input and output
* `INPUT_PULLUP`
* Button state detection
* Passive buzzer tones
* Game state management

## Running the Project

1. Connect the components according to the pin configuration above.
2. Open the `.ino` file in the Arduino IDE.
3. Select the correct Arduino Uno board and port.
4. Compile and upload the sketch.
5. Follow the LED sequence and repeat it using the buttons.

## Project Goals

I built this project as part of learning embedded programming and electronics with Arduino.

The main goal was to move beyond controlling individual LEDs and buttons and combine multiple hardware components with program logic to create a complete interactive system.

## Future Improvements

Possible additions include:

* LCD display for level and game status
* High-score tracking
* Different difficulty modes
* Improved sound feedback
* Start/restart button
* Enclosure or PCB version

## Built With

* Arduino Uno R3
* C/C++
* Arduino IDE
