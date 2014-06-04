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



/* ------------------ MOSCOW CODE BEGINS -----------------


//-----------------------------------------------------//
//-----------Ilya S. Dubkoff, Semyon D. Egoroff--------//
//-----------------------------------------------------//
//-Rear (drive) motor is connected to IN1 and IN2, ----//
//-front (stearing) motor is connected to IN3 and IN4.-//
//-----------------------------------------------------//
//---------IN1 LOW and IN2 HIGH - drive forward--------//
//--------IN1 HIGH and IN2 LOW - drive backward--------//
//----------IN3 HIGH and IN4 LOW - steer left----------//
//---------IN3 LOW and IN4 HIGH - steer right----------//


#define IN1 5
#define IN2 6
#define IN3 10
#define IN4 11

#define SENR A3
#define SENL A1

#define WHITE_L 50
#define WHITE_R 50
#define THRESHOLD 150
#define WHITE 50//************************

#define SPEED 220

unsigned int senl, senr;


void setup(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(13,OUTPUT);
  delay(300);
//  Serial.begin(9600);
    driveForward(SPEED);
} 

//int senl=0, senr=0;
int control;
boolean SLF, SRF, lastMove, needToSteer; //steer left flag, steer right flag

void loop(){

  senr=analogRead(SENR);
  senl=analogRead(SENL);
  control=senr-senl;
//  driveForward(255-constrain(abs((control-150)),0,170));
  

  if(abs(control) > THRESHOLD)
  {
    if(senl > 400 && senr < 60){//поворот влево
      steerLeft();
      needToSteer=true;
//      digitalWrite(13,HIGH);
      driveForward(SPEED);
    }  
    else if (senl <60 && senr > 390){//поворот вправо
      steerRight();
      needToSteer=true;
//      digitalWrite(13,HIGH);
      driveForward(SPEED);
    }
  }else if (!needToSteer){
   steerStop();
  }else if (control <20){
    driveForward(180);
  }
  
  if (senl>400 && senr>390 && control<THRESHOLD) {
     needToSteer=false;
//     digitalWrite(13,LOW);
  }
//else needToSteer=false;
  
}


//----------------------FUNCTIONS---------------------------//

void driveForward(int spid){
  digitalWrite(IN1, LOW);
  //  digitalWrite(IN2, HIGH);  
  analogWrite(IN2, spid);
}

void driveBackward(int spid){
  digitalWrite(IN2, LOW);
  // digitalWrite(IN1, HIGH);
  analogWrite(IN1, spid);

}

void driveStop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW); 
}  

void steerLeft(){
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);  
}
void steerRight(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void steerStop(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); 
}  

-------------------- MOSCOW CODE ENDS ---------------------*/
