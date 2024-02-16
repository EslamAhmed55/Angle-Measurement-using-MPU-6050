#include <Wire.h>    //Include wire library 
#include <MPU6050_light.h>  //Include library for MPU communication
#include <LiquidCrystal_I2C.h>  //Library for LCD Display

MPU6050 mpu(Wire);   //Create object mpu
LiquidCrystal_I2C lcd(0x27, 16, 2);     //Define LCD address and dimension

unsigned long timer = 0;    

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello ");
  lcd.setCursor(2,1);
  lcd.print("We will start");
   lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
   //lcd.setCursor(2,3);
  //lcd.print("Power By Ec-yuan!");

  Serial.begin(9600);    //Start serial communication

  lcd.begin(16,2);     //Start LCD Display
  lcd.backlight();    

  Wire.begin();     
  mpu.begin();     
  Serial.print(F("MPU6050 status: "));
  Serial.println(F("Calculating offsets, do not move MPU6050"));   
  delay(1000);
  mpu.calcGyroOffsets();     //Calibrate gyroscope
  Serial.println("Done!\n");

}
void loop() {
  mpu.update();    //Get values from MPU

  if ((millis() - timer) > 100) { // print data every 100ms
    timer = millis();
    lcd.clear();
    lcd.print(" Angle = ");
    lcd.print(int(mpu.getAngleZ()));     //Print Z angle value on LCD 
    delay(10);
  }
}
