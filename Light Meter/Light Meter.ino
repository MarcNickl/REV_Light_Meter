#define WINDOW_SIZE 20  // aravageing value

int INDEX = 0;
int VALUE = 0;
int SUM = 0;
int READINGS[WINDOW_SIZE];
int AVERAGED = 0;

#include "MultiMap.h"
#include "MegunoLink.h"
#include "Filter.h"

long FilterWeight = 5;
ExponentialFilter<long> ADCFilter(FilterWeight, 0);


void setup() {
  Serial.begin(9800);
}



void loop() {


// This secion can be cleaned up there are too many multimaps could easyly go from anolog in to EV


  // Lux out
  // out[] holds the output values
  int out[] = { 150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20 };  //enter your own numbers

  // in[] holds the measured analogRead() values
  // note: the in[] array should have increasing values
  int in[] = { 90, 97, 105, 113, 124, 134, 147, 164, 185, 218, 255, 317, 408, 506 };  // enter your own numbers

  int val = analogRead(A0);
  int lux = multiMap(val, in, out, 14);  // replace 14 with your number of data points


  //  EV out
  // out[] holds the output values
  int out1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };  //enter your own numbers

  // Lux in
  // in[] holds the measured analogRead() values
  // note: the in[] array should have increasing values
  int in1[] = { 5, 10, 20, 40, 80, 160, 320, 620, 1280, 2560, 10240, 20480, 40960, 81920 };  // enter your own number

  int val1 = lux;
  int EV = multiMap(val1, in1, out1, 14);  // replace 14 with your number of data points




      //Anolog control wheel

  // EV out
  // out[] holds the output values
  int out3[] = { 150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20 };  //enter your own numbers

// Potentiomitor anolog values in

  // in[] holds the measured analogRead() values
  // note: the in[] array should have increasing values
  int in3[] = { 90, 97, 105, 113, 124, 134, 147, 164, 185, 218, 255, 317, 408, 506 };  // enter your own numbers

  int val3 = analogRead(A1); // make sure its right
  int Pot = multiMap(val, in3, out3, 14);  // replace 14 with your number of data points




    //Aravage section

  SUM = SUM - READINGS[INDEX];        // Remove the oldest entry from the sum
  VALUE = analogRead(A0);             // Read the next sensor value
  READINGS[INDEX] = VALUE;            // Add the newest reading to the window
  SUM = SUM + VALUE;                  // Add the newest reading to the sum
  INDEX = (INDEX + 1) % WINDOW_SIZE;  // Increment the index, and wrap to 0 if it exceeds the window size

  AVERAGED = SUM / WINDOW_SIZE;  // Divide the sum of the window by the window size for the result




  // Final Read out - Not really important for what i want but useful in developemnt

  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.print(sensorValue);
  Serial.print("  ");

  Serial.print(lux);
  Serial.print("  ");

  Serial.println(AVERAGED);
  Serial.print("  ");

  Serial.print(EV);
  Serial.print("  ");

  Serial.print(Pot);
  Serial.print("  ");


  delay(25);
}