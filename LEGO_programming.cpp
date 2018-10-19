/*************************************
Using C++ to control Lego Mindstorm
EV3.This method is only recommend for 
intermediate to advance user.This code 
will show you basic commands to read
sensors and output motor speed and 
direction to follow the wall at certain 
distance. For more infomation, you can
look at c4ev3.h api 
**************************************/

#include<ev3.h>

using namespace std;

//initialize LEGO ev3 and sensors. 
void setup(){
	InitEV3();
//this command has up to 4 arguments for 4 input ports, IN1,IN2,IN3,IN4. For this
//example, we will initialize sonar sensor readings from port IN1
	setAllSensorsMode(US_DIST_MM); 
	
}

int main(){
//run setup code once. 
	setup();
//infinite loop
	while(true){
		int sensorVal = readSensor(IN_1);	//read sonar sensor values
		int distance = 20; 	//set desire wall reading values UNITS:milimeters. 
		//Steer right
		if(sensorVal > distance){
			OnFwdReg(OUT_A,100);
			OnFwdRed(OUT_B,50);
		//Steer left 	
		}else if(sensorVal < distance){
			OnFwdReg(OUT_A,50);
			OnFwdReg(OUT_B,100);
		//drive forward
		}else{
			OnFwdSync(OUT_AB,100);
		}
	//We have to incorporate a delay in our feedback loop system for sampling frequency
	//Read more on Delays in Control Systems written by University of Texus. 			
	wait(MS_1);
	}
	
	return 0;
}