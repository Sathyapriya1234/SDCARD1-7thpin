#include <SPI.h>
#include "SD1.h"
#include "SD2.h"

File myFile1;
File myFile2;

  Sd2Card card1;
  Sd2Card card2;
const int cs = 7;
const int cs1 = 4;
void setup(void) {
 Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  //SD Card 1
  // Open serial communications and wait for port to open:
  Serial.print("Initializing SD card1...");
//unsigned cs = 4;
//pinMode(cs, OUTPUT);
//digitalWrite(cs,HIGH);
//SPI.begin(cs);
///digitalWrite(cs,LOW);
/// pinMode(cs, OUTPUT);
///  SPI.begin();
  if (!SD1.begin(cs)) {
    Serial.println("initialization1 failed!");
    //return;
  }
  Serial.println("initialization1 done.");
 //SD.begin(sck,cs);
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile1 = SD1.open("file_one.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile1) {
    Serial.print("Writing to file_one.txt...");
    delay(1500);
    myFile1.println("Hello Welcome to our project");
    // close the file:
    myFile1.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening file_one.txt");
  }
 delay(1000);
  // re-open the file for reading:
  myFile1 = SD1.open("file_one.txt");
  if (myFile1) {
    Serial.println("file_one.txt:");
    int i;
    Serial.println("reading1 start:");
  for(i=0;i<=29;i++){
    // read from the file until there's nothing else in it:
   if (myFile1.available()) {
      Serial.write(myFile1.read());
   }
  }
  Serial.println("reading1 stoped:");
  
    delay(1000);
    // close the file:
    myFile1.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening file_one.txt");
  }
  if (SD1.remove("file_one.txt") == true) {
      Serial.println("Successfully removed file_one.");
    } else {
      Serial.println("Could not removed file_one.");
    }
 digitalWrite(cs,HIGH);
// SPI.endTransaction();   
// SPI.end();
 
  delay(1500);
  //SD Card 2
  // digitalWrite(cs1,HIGH);
//digitalWrite(cs1,LOW);
// pinMode(cs1, OUTPUT);
 //unsigned cs1 = 10;
 //pinMode(cs1, OUTPUT);
 //SPI.begin();
   Serial.print("Initializing SD card2...");
  /////////digitalWrite(chipselect2,LOW);
  if (!SD2.begin(cs1)) {
    Serial.println("initialization2 failed!");
    //return;
  }
  Serial.println("initialization2 done.");
   //SD.begin(sck,cs1);

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile2 = SD2.open("file_two.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile2) {
    Serial.print("Writing to file_two.txt...");
    delay(1500);
    myFile2.println("2222Hello Welcome to our project2");
    // close the file:
    myFile2.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening file_two.txt");
  }
 delay(1000);
  // re-open the file for reading:
  myFile2 = SD2.open("file_two.txt");
  if (myFile2) {
    Serial.println("file_two.txt:");
    int i1;
    Serial.println("reading2 start:");
  for(i1=0;i1<=29;i1++){
    // read from the file until there's nothing else in it:
   if (myFile2.available()) {
      Serial.write(myFile2.read());
   }
  }
  Serial.println("reading2 stoped:");
    delay(1000);
    // close the file:
    myFile2.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening file_two.txt");
  }
  if (SD2.remove("file_two.txt") == true) {
      Serial.println("Successfully removed file_two.");
    } else {
      Serial.println("Could not removed file_two.");
    }
digitalWrite(cs1,HIGH);
    //Serial.end();
    //SPI.endTransaction();
    //SPI.end();
   delay(1000);
  
}

void loop()
{
}
