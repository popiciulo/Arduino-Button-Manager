#include <ButtonManager.h>

// start editing !!!
// Define your buttons (name, pin, mode, initial status, previous status)
Button buttons[3] = {
    {"button1", 4, INPUT_PULLUP, HIGH, HIGH},
    {"button2", 5, INPUT_PULLUP, HIGH, HIGH},
    {"button3", 6, INPUT_PULLUP, HIGH, HIGH}
};
int totalButtons = 3;

// Initialize the ButtonManager (buttons, totalButtons, 500 ms for long press)
ButtonManager buttonManager(buttons, totalButtons, 500);

// stop editing !!!

void setup() {
  for (int i = 0; i < totalButtons; i++) {
    pinMode(buttons[i].pin, buttons[i].mode);
  }
  Serial.begin(9600); // for debugging
}

void loop() {
  buttonManager.checkButtons(clickHandler);
}

void clickHandler(Button button, String type) {
  Serial.println(button.name + " " + type);
}
