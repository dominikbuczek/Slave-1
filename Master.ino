/****************************************************************************************************
 File Name:  Master
 Author:     Carlos Guillen
 Date:       Oct 19 , 2019
 Modified:   None
 Fanshawe College, 2019
                
 Desc:      Use master arduino to serially communicate to a slave arduino to turn ON and OFF 2 LEDs,
            to test and get familiarized with serial communication between arduinos
*****************************************************************************************************/
int Pin9 = 9; //This pin will be used to enable the TX terminal in the MAX285 chip

void setup() 
{
  // Put your setup code here, to run once:
  Serial1.begin(9600);// Setup the baud rate
  pinMode(Pin9, OUTPUT); // Set the pin as an output and initialize it
  digitalWrite(Pin9, HIGH); // Set the pin as a high to enable the TX terminal in the MAX285
}

void loop() 
{
  Serial1.write('+'); // Send symbol to the slave to turn on the first LED and turn off the second LED
  delay(2000); // Wait 2 seconds before sending the next symbol
  Serial1.write('-'); // Sends a minus symbol to the slave to turn the second LED off and turn the first LED
  delay(2000); // Wait 2 seconds before restarting the loop
}
