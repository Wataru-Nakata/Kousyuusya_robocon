#include "mbed.h"
#include "Servo.h"
#define servomax 90
#define servomin -90
Serial pc (USBTX,USBRX);
DigitalOut myled(LED1);
Servo cam (D3);
int x;
float i = 0;
int main() {
    while(1) {
        x = (pc.getc()/255.0)*640;
        if(x > 320){
            i -=fabs(x-320)/(100.0);
        }else if(x< 320)
        {
            i += fabs(320-x)/(100.0);
        }
        if (i> servomax){
            i = servomax;
        }
        if (i<servomin){
            i = servomin;
        }
        cam.position(i);
        pc.putc(char(((i+90)/180.0)*255));
    }
}
