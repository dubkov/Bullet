#include "Bullet.h"

#define SENR A3
#define SENL A1
#define CTRL_THRD 150
#define SENL_LTHRD 60
#define SENL_HTHRD 400
#define SENR_LTHRD 60
#define SENR_HTHRD 390
#define FWD_THRD 20
#define HSPEED 220
#define LSPEED 180

bullet bullet(5,6,10,11);
boolean  needToSteer; 

void setup(){}

void loop(){
	senr=analogRead(SENR);
	senl=analogRead(SENL);
	control=senr-senl;
	
	if(abs(control) > CTRL_THRD)
  {
    if(senl > SENL_HTHRD && senr < SENR_LTHRD){//поворот влево
      bullet.steer(LEFT);
      needToSteer=true;
      bullet.drive(FWD,LSPEED);
    }  
    else if (senl <SENL_LTHRD && senr > SENR_HTHRD){//поворот вправо
      bullet.steer(RIGHT);
      needToSteer=true;
      bullet.drive(FWD,LSPEED);
    }
  }
  else if (!needToSteer){
	bullet.steer(STOP);
  }
  else if (control <FWD_THRD){
    bullet.drive(FWD,HSPEED);
  }  
  if (senl>SENL_HTHRD && senr>SENR_HTHRD && control<CTRL_THRD) {
     needToSteer=false;
  }
}
