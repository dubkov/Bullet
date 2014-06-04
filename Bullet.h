#ifndef bullet_h
#define bullet_h

#include "Arduino.h"

#define LEFT 	1
#define RIGHT 	2
#define FWD		1
#define BACK	2
#define STOP	0


class bullet
{
	public:
		bullet(int in1, int in2, int in3, int in4);
		void steer(int _strdir);
		void drive(int _drvdir);
		void drive(int _drvdir, int _drvspd);
    
	private:
		int _in1;
		int _in2;
		int _in3;
		int _in4;
    		int _strdir;
    		int _drvdir;
    		int _drvspd;
		void steerStop();
		void steerLeft();
		void steerRight();
		void driveForward(int spid);
		void driveBackward(int spid);
		void driveStop();

};

#endif
