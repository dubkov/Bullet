#include "stdlib.h"
#include "Bullet.h"


bullet::bullet(int in1, int in2, int in3, int in4)
{
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	_in1 = in1;
	_in2 = in2;
	_in3 = in3;
	_in4 = in4;
}

void bullet::driveForward(int spid){
  digitalWrite(_in1, LOW);
  analogWrite(_in2, spid);
}

void bullet::driveBackward(int spid){
  digitalWrite(_in2, LOW);
  analogWrite(_in1, spid);
}

void bullet::driveStop(){
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, LOW); 
}  

void bullet::steerLeft(){
  digitalWrite(_in4, LOW);
  digitalWrite(_in3, HIGH);  
}
void bullet::steerRight(){
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
}

void bullet::steerStop(){
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, LOW); 
}  

void bullet::steer(int _strdir){
	if ( _strdir == 0 ){ steerStop(); }
	else if ( _strdir == 1 ){ steerLeft();}
	else if ( _strdir == 2 ) { steerRight();}
}

void bullet::drive(int _drvdir){
	if ( _drvdir == 0 ){ driveStop(); }
}
	
void bullet::drive(int _drvdir, int _drvspd){
	
	if ( _drvdir == 1 ){ driveForward(_drvspd); }
	else if ( _drvdir == 2 ) { driveBackward(_drvspd); }
}

