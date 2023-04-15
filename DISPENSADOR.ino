#include <Servo.h>
Servo servomotor;
String estado;

void setup() {
      servomotor.attach(9);//Pin PWM 9 del Arduino para el servo
      servomotor.write(0); // Inicia el servo en una posicion de 0°
      Serial.begin(9600);
}

void loop() {
    delay(25);
    while(Serial.available())
    {
      char c = Serial.read();//Lee el dato entrante y lo almacena en una vaiable tipo char
      estado += c; //Crea una caden tipo String con los datos entrantes
    }
    if(estado.length()>0) //Se verifica que la cadena tipo String tenga un largo mayor a 
    {
      servomotor.write(estado.toInt()); // Manda al servo el dato en forma de entero (int)
      estado = ""; // Limpia la variable para poder leer posteriormente nuevos datos           
    }
          
}
