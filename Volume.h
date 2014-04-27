/*
    Volume.h - Library for HC-SR04 & Calculating Volumes of Containers
    Author: Brian D. Arpie
    Date Created: 4/18/2014
    Date Updated: 4/21/2014
*/

#ifndef Volume_h
#define Volume_h

#include "Arduino.h"

class Volume
{
  public:
    Volume( int _trigPin, int _echoPin ); // constructor
    void setTrigPin(int trigPin);
    void setEchoPin(int echoPin);
    void setBox( double length, double width, double height );
    void setCylinder( double radius, double height );
    void setCone( double radius, double height );
    double getVolume();
    double getHeight();
    double getDuration();
    bool checkShape();
      
  private:
    String shape;
    int trigPin;
    int echoPin;
    double volume;
    double length;
    double width;
    double height;
    double radius;
    double distance;
    double duration;
};

#endif