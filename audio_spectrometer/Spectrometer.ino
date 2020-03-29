#include <arduinoFFT.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define sampletakes 64            
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW   
#define MAX_DEVICES  4   
#define CLK_PIN   13  
#define DATA_PIN  11 
#define CS_PIN    10  
#define  xr 32    
#define  yr 8      


int defaultpat[]={0, 1, 3, 7, 15, 31, 63, 127, 255}; 


 
double realval[sampletakes];
double imaginaryval[sampletakes];
char datavg[xr];

int yvalue;
int displaycolumn , displayvalue;
int peak[xr];

   


MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);   
arduinoFFT FFT = arduinoFFT();                                    
 


void setup() {
    
    ADCSRA = 0b11100101;      
    ADMUX = 0b00000000;       
    mx.begin();           
    delay(50);            
}
 
void loop() {
   // ++ Sampling
   for(int i=0; i<sampletakes; i++)
    {
      while(!(ADCSRA & 0x10));        
      ADCSRA = 0b11110101 ;               
      int value = ADC - 512 ;                 
      realval[i]= value/8;                      
      imaginaryval[i] = 0;                         
    }

    FFT.Windowing(realval, sampletakes, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(realval, imaginaryval, sampletakes, FFT_FORWARD);
    FFT.ComplexToMagnitude(realval, imaginaryval, sampletakes);

    int step = (sampletakes/2)/xr; 
    int c=0;
    for(int i=0; i<(sampletakes/2); i+=step)  
    {
      datavg[c] = 0;
      for (int k=0 ; k< step ; k++) {
          datavg[c] = datavg[c] + realval[i+k];
      }
      datavg[c] = datavg[c]/step; 
      c++;
    }
    

    
    
    for(int i=0; i<xr; i++)
    {
      datavg[i] = constrain(datavg[i],0,80);            
      datavg[i] = map(datavg[i], 0, 80, 0, yr);        
      yvalue=datavg[i];

      peak[i] = peak[i]-1;    
      if (yvalue > peak[i]) 
          peak[i] = yvalue ;
      yvalue = peak[i];    
      displayvalue=defaultpat[yvalue];
      displaycolumn=31-i;
      mx.setColumn(displaycolumn, displayvalue);              
     }
     
     

} 
