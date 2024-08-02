#include <LedControl.h>
int DIN = 12;
int CS =  11;
int CLK = 10;
LedControl lc=LedControl(DIN,CLK,CS,0);
void setup(){
 lc.shutdown(0,false);       
 lc.setIntensity(0,15);      
}
void loop(){ 
    byte talk[8]={B00000000,B01000010,B11100111,B01000010,B00000000,B00111100,
    B01111110,B00111100};
        printByte(talk);
         delay(1000);
             byte SMILE[8]= {B00000000,B01000010,B11100111,B01000010,B00000000,
             B01100110,B00111100,B00011000};
        printByte(SMILE);
         delay(1000);
 }
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}