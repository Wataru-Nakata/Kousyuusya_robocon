#include "mbed.h"
#include "Servo.h"
#define servomax 90
#define servomin 0
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
        if (i> servomax){
            i = servomax;
        }
        if (i<servomin){
            i = servomin;
        }
        cam.position(i);
        pc.putc(char((i/90.0)*255));
    }
}
