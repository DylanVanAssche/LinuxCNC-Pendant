/*
   ******************************************
   *                                        *
   *                                        *
   *----------> LINUXCNC PENDANT <----------*
   *                                        *
   *             V 1.1 RELEASE              *
   ******************************************
   THIS IS A RELEASE! I'm never resposibly for any damage to your stuff! This version is completely tested.
   This pendant works only with EMC/LinuxCNC and not with other CNC control programs! 
   
   (c) Dylan Van Assche (2014).
*/


#include <Keypad.h>

// Keypad library setup for a 4x5 keypad.
const byte ROWS = 5;  // 5 rows.
const byte COLS = 4;  // 4 columns.

char key = 0;

// Keys
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', 'A', 'B', 'C'},
  {'D', 'E', 'F', 'G'},
  {'H', 'I', 'J', 'K'}
};

byte rowPins[ROWS] = {10, 16, 14, 15, A0};
byte colPins[COLS] = {2, 3, 4, 5};
Keypad LinuxCNCKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
int axis = 1; // X-axis select at start up.

void setup() {
  // Start Arduino keyboard
  Keyboard.begin();
}

void loop() {
  key = LinuxCNCKeypad.getKey();
  if (key)
  {
    switch (key) {
      case '1':
        Keyboard.write(194); // E-STOP
        break;

      case '2':
        Keyboard.write(195); // POWER
        break;

      case '3':
        Keyboard.write(177); // ABORD
        break;

      case '4':
        Keyboard.write(202); // SPINDLE ON/OFF
        break;

      case '5':
        Keyboard.write(210); // HOME
        break;

      case '6':
        Keyboard.press(218); // Y+
        break;

      case '7':
        Keyboard.write(213); // TOUCH OFF
        break;

      case '8':
        Keyboard.press(211); // Z+
        break;

      case '9':
        Keyboard.press(216); // X-
        break;

      case 'A':
        switch (axis) // AXIS SELECT
        { case 1:
            Keyboard.write('x');
            axis = 2;
            break;

          case 2:
            Keyboard.write('y');
            axis = 3;
            break;

          case 3:
            Keyboard.write('w');
            axis = 1;
            break;
        }
        break;

      case 'B':
        Keyboard.press(215); // X+
        break;

      case 'C':
        Keyboard.press(214); // Z-
        break;

      case 'D':
        Keyboard.write('c'); // JOG CONTINOUS MODE
        break;

      case 'E':
        Keyboard.press(217); // Y-
        break;

      case 'F':
        Keyboard.write('i'); // JOG STEP MODE
        break;

      case 'G':
        Keyboard.write(176); // OK
        break;

      case 'H':
        Keyboard.write('r'); // START PROGRAM
        break;

      case 'I':
        Keyboard.write('p'); // PAUSE PROGRAM
        break;

      case 'J':
        Keyboard.write('s'); // RESUME PROGRAM
        break;

      case 'K':
        Keyboard.press(132); // CLEAR LIVE PLOT
        delay(25);
        Keyboard.write('k');
        delay(25);
        Keyboard.release(132);
        delay(25);
        break;
    }
  }
  else
  {
    Keyboard.releaseAll();
  }
}
