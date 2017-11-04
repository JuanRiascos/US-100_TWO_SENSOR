#include <SoftwareSerial.h>

// define the digital pins to use as RX and TX for two
// software serial connections
int Ec = 12;
int Tr = 13;


// create SoftwareSerial objects
SoftwareSerial puertoUS100(12, 13);
SoftwareSerial puertoUS2(10, 11);
float MSByteDist = 0;
float LSByteDist = 0;
float mmDist = 0;
boolean pendejo = false;



void setup() {
  Serial.begin(9600);




}

void loop() {
  Serial.println("Uno");
  us100(puertoUS100);
  delay (500);
  Serial.println("Dos");
  us100(puertoUS2);
//   delay(500);
//  puertoUS2.begin(9600);
//  puertoUS2.listen();
//  if (puertoUS2.isListening()) {
//    puertoUS2.flush();
//    puertoUS2.write(0x55);
//    if (puertoUS2.available() >= 2) {
//      MSByteDist = puertoUS2.read(); // lectura de ambos bytes
//      LSByteDist  = puertoUS2.read();
//      mmDist  = MSByteDist * 256 + LSByteDist;
//      float k = mmDist / 10;
//      Serial.println(k - 2);
//      Serial.println("dos");
//      puertoUS2.end();
//    }
    
  }

void us100(SoftwareSerial puerto){
  puerto.begin(9600);
  puerto.listen();

  if (puerto.isListening()) {
    puerto.flush();
    //.END PARA FINALIZAR
    puerto.write(0x55);
    delay(500);
    if (puerto.available() >= 2) {
      MSByteDist = puerto.read(); // lectura de ambos bytes
      LSByteDist  = puerto.read();
      mmDist  = MSByteDist * 256 + LSByteDist;
      float k = mmDist / 10;
      Serial.println(k - 2);
      
      //puerto.end();
    }
    delay(500);
    
  }
  }
static int Ale() {
  return 5 * 4;
}
static int Lectura(SoftwareSerial x) {
  x.flush();
  x.write(0x55);
  delay(500);
  if (x.available() >= 2) {
    MSByteDist = x.read(); // lectura de ambos bytes
    LSByteDist  = x.read();
    mmDist  = MSByteDist * 256 + LSByteDist;
    int k = mmDist / 10;
    return k - 2;
  }
}



