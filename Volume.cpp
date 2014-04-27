/*
	Volume.cpp - Library for HC-SR04 & Calculating Volumes of Containers
	Author: Brian D. Arpie
	Date Created: 4/18/2014
	Date Updated: 4/21/2014
*/

#include "Volume.h"

#define PI 3.14159265359    

/**
*   constructor of Volume
*   initalize variables and do setup
**/
Volume::Volume(int _trigPin, int _echoPin) {
  trigPin = _trigPin;
  echoPin = _echoPin;
  pinMode( _trigPin, INPUT );
  pinMode( _echoPin, OUTPUT );
}

/** 
* void setTrigPin(int _pin)
* set trig pin on HC-SR04
**/
void Volume::setTrigPin(int _trigPin) {
  trigPin = _trigPin;
  pinMode( _trigPin, INPUT );
}

/** 
* void setEchoPin(int _pin)
* set echo pin on HC-SR04
**/
void Volume::setEchoPin(int _echoPin) {
   echoPin = _echoPin;
   pinMode( _echoPin, OUTPUT );
}

/**
*	void box()
*	set container shape as box
**/
void Volume::setBox( double _length, double _width, double _height ) {
  length = _length,
    width = _width,
    height = _height,
    volume = length * width * height,
    shape = "box";
}

/**
*	void cylinder()
*	set container shape as cylinder
**/
void Volume::setCylinder( double _radius, double _height ) {
  radius = _radius,
    height = _height,
    volume = PI * radius * radius * height,
    shape = "cylinder";
}

/**
*	void cone()
*	set container shape as cone
**/
void Volume::setCone( double _radius, double _height ) {
  radius = _radius,
    height = _height,
    volume = ( 1 / 3 ) * PI * radius * radius * height,
    shape = "cone";
}

/**
*	double getVolume()
*	get the volume of the liquid in the container
**/
double Volume::getVolume() {
  if( checkShape() ) {
    if( shape == "box" ) {
    return ( volume - ( length * width * getHeight() ) );
    } else if( shape == "cylinder" ) {
    return ( volume - ( PI * radius * radius * getHeight() ) );
    } else if( shape == "cone" ) {
     return ( 1 / 3 ) * ( ( PI * radius * radius * height ) - ( PI * radius * radius * getHeight() ) );
   } 
  }
}

/**
*	double getHeight()
*	call for duration then calculate distance (height)
**/
double Volume::getHeight() {
  duration = getDuration();
  distance = ( duration / 58.2 ); //Calculate the distance (in m) based on the speed of sound.
  Serial.print("the distance in meters is..");
  Serial.println(distance);
  return distance;
}

/**
* double getDuration()
* get duration from sensor
**/
double Volume::getDuration() {
  digitalWrite( echoPin, LOW ); 
  delayMicroseconds(5); // why 2 us?
  digitalWrite( echoPin, HIGH );
  delayMicroseconds(5); // why 10 us?
  digitalWrite( echoPin, LOW );
  return pulseIn( trigPin, HIGH );
}

/**
*	bool checkShape()
*	make sure shape is set before getting volume
**/
bool Volume::checkShape() {
  if ( shape == "box" || shape == "cylinder" || shape == "cone" ) {
    return true;
  } else {
    return false;
  }
}