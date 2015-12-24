#include "mbed.h"
#include "Servo.h"
Serial pc (USBTX,USBRX);
DigitalOut myled(LED1);
Servo cam (D3);
int x;
float i = 0.5;
int main() {
    while(1) {
        x = (pc.getc()/255.0)*640;
        if(x > 320){
            i -=fabs(x-320)/64000.0*5*2;
        }else if(x< 320)
        {
            i += fabs(320-x)/64000.0*5*2;
        }
        if (i> 1){
            i = 1;
        }
        if (i<0){
            i = 0;
        }
        cam.position(i);
        pc.putc(char(i*255));
    }
}
