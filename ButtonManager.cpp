#include "ButtonManager.h"

ButtonManager::ButtonManager(Button *buttons, int totalButtons, unsigned int longPress) {
    _buttons = buttons;
    _totalButtons = totalButtons;
    _longPress = longPress;
}

void ButtonManager::checkButtons(void (*clickHandler)(Button, String)) {

    for (int i = 0; i < _totalButtons; i++) {
        _buttons[i].status = digitalRead(_buttons[i].pin);

        if(_buttons[i].status == LOW && _buttons[i].prevStatus == HIGH) { // button pressed

          _buttons[i].timePressed = millis();
          _buttons[i].prevStatus = LOW;     

        } else if (_buttons[i].status == HIGH && _buttons[i].prevStatus == LOW) { // button released

          int totalPressed = millis() - _buttons[i].timePressed;

          if(totalPressed > 50 && totalPressed < _longPress) {
            clickHandler(_buttons[i], "short");
          } else if (totalPressed > _longPress) {
            clickHandler(_buttons[i], "long");
          }     
          
          _buttons[i].prevStatus = HIGH;
        }
      }
}