////////////////////////////////////////
//  pwmout.c
//      generates pwm on a pin to glow an LED
//  Author:  Sean J. Miller
//  Wiring: Jumper P9.14 to an LED through a 220ohm resistor to ground
//
// See: https://www.element14.com/community/community/designcenter/single-board-computers/next-genbeaglebone/blog/2019/10/27/beagleboard-ai-brick-recovery-procedure
////////////////////////////////////////
#include <stdio.h>
#include <unistd.h>

void setupPWM() {
    FILE *period, *pwm;
    pwm = fopen("/sys/class/pwm/pwm-0:0/enable", "w");
    fseek(pwm,0,SEEK_SET);
    fprintf(pwm,"%d",1);
    fflush(pwm);
    fclose(pwm);
    
    printf("Period...!\n");
    period = fopen("/sys/class/pwm/pwm-0:0/period", "w");
    fseek(period,0,SEEK_SET);
    fprintf(period,"%d",20000000);//20ms
    fflush(period);
    fclose(period);
    
}
void pwm_duty(int the_duty_multiplier)
{
    FILE *duty;
    duty = fopen("/sys/class/pwm/pwm-0:0/duty_cycle", "w");
    fseek(duty,0,SEEK_SET);
    fprintf(duty,"%d",1000000*(the_duty_multiplier/2));//1ms
    fflush(duty);
    fclose(duty);
}

int main() {
     int ii=0;int up=0;
     printf("Setting up\n");
     setupPWM();
     
     while(1) {
        printf("Changing Servo %d\n",ii);
         if (up==1) ii++; else ii--;
         if ((ii)>3) {
             up=0;
         }
         if (ii<0) {
             up=1;
         }
         pwm_duty(ii);
         usleep(2500000);
      }
}