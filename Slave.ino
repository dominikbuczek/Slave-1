/****************************************************************************************************
 File Name:  Slave
 Author:     Carlos Guillen
 Date:       Oct 19 , 2019
 Modified:   None
 Fanshawe College, 2019
                
 Desc:      Use salve arduino to receive signals sent by the master to turn ON and OFF 2 LEDs,
            to test and get familiarized with serial communication between arduinos.
*****************************************************************************************************/
int ledPin = 12; // This is our first LED
int ledPin2 = 11; // This is our second LED
int Pin7 = 7; //This pin will be used to enable the RX terminal in the MAX285 chip

void setup() 
{
  Serial.begin(9600); //setup the baud rate
  pinMode(ledPin, OUTPUT); // set pin 12 as an output to use as an LED
  pinMode(ledPin2, OUTPUT); // set pin 11 as an output to use as an LED
  pinMode(Pin7, OUTPUT); // set pin 7 as an output
  digitalWrite(Pin7, LOW); // set pin 7 as a low state for second MAX485 to be enabled as an RX
}

void loop() {
  handleSerial(); // call handle serial function to main
}

// Function created to read incoming data from the master
void handleSerial()
{
  while(Serial.available() > 0) // loop will run everytime it detects data incoming
  {
    char incomingCharacter = Serial.read(); // The data incoming is assigned to a variable
    Serial.println(incomingCharacter); // The data received is printed in the serial monittor to check it was correctly received
    switch(incomingCharacter) // switch statement to handle the received dat
    {
      case '+': // when it receives the + character it performs this action
        digitalWrite(ledPin,HIGH); // LED turns on
        digitalWrite(ledPin2,LOW); // LED turns off
      break;
      case '-': // when it receives the - character it performs this action
        digitalWrite(ledPin,LOW); // LED turns off
        digitalWrite(ledPin2,HIGH); // LED turns on
      break;
    }
  }
}
