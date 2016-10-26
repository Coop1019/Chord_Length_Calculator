/*
 * Raisbeck Aviation High School Wind Team
 * All Rights Reserved (c)2016
 *
 * Code Written by Cooper LeComp
 *
 * Last Updated 10/26/16
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <string>
#include "chordCalc.h"

using namespace std;

/*
 * UNITS:
 *  Radius: cm
 *  RMP: rotations per minute
 *  Wind Speed Velocity: m/s
 *
 */

void createBlankFiles(){
    ofstream windSpeedFile("windSpeed.value");
    windSpeedFile << "10" << endl;
    windSpeedFile.close();
    ofstream rpmFile("rpm.value");
    rpmFile << "1000" << endl;
    rpmFile.close();
    ofstream radiusFile("radius.value");
    radiusFile << "22.5" << endl;
    radiusFile.close();
    ofstream bladesFile("blades.value");
    bladesFile << "3" << endl;
    bladesFile.close();
    ofstream cfFile("cf.value");
    cfFile << "1.2" << endl;
    cfFile.close();
}
double getRPM(){
    double rpm = 0;
    ifstream rpmFile("rpm.value");
    if (rpmFile.is_open())
    {
        string line;
        getline(rpmFile,line);
        rpm = stod(line);
    }
    return rpm;
}
double getRadius(){
    double radius = 0;
    ifstream radiusFile("radius.value");
    if (radiusFile.is_open())
    {
        string line;
        getline(radiusFile,line);
        radius = stod(line);
    }
    return radius;
}
int getBlades(){
    int blades = 0;
    ifstream bladeFile("blades.value");
    if (bladeFile.is_open())
    {
        string line;
        getline(bladeFile,line);
        blades = stoi(line);
    }
    return blades;
}
double getCFLift(){
    double cfLift = 0;
    ifstream cfFile("cf.value");
    if (cfFile.is_open())
    {
        string line;
        getline(cfFile,line);
        cfLift = stod(line);
    }
    return cfLift;
}
double getRadianPoint(){
    double radianPoint;
    cout << "Radian Point: " << endl;
    cin >> radianPoint;
    cout << endl;
    if (radianPoint){return radianPoint;}
    else {return 0;}
}
double getWind(){
    double windSpeed = 0;
    ifstream windSpeedFile("windSpeed.value");
    if (windSpeedFile.is_open())
    {
        string line;
        getline(windSpeedFile,line);
        windSpeed = stod(line);
    }
    return windSpeed;
}

double getBladeTipVelocity(double radius, double rpm){
    double pi = 3.14159265358979323846264338327950288419716939937510582;
    double bladeTipVelocity = 2*radius*pi*rpm/60/100;
    //cout << "Blade Tip Velocity: " << bladeTipVelocity << endl;
    return bladeTipVelocity;
}

double calculateChord(double radianPoint){
    //get Radius
    //Get Blades
    //Get Cl
    //Get Radius Points
    //Calculate Velocity
    double rpm = getRPM();
    double radius = getRadius();
    int bladeCount = getBlades();
    double coefficientLift = getCFLift();
    //double radianPoint = getRadianPoint();
    double bladeTipVelocity = getBladeTipVelocity(radius, rpm);
    double windVelocity = getWind();

    double chord = ((5.6*(radius*radius))/(bladeCount*coefficientLift*radianPoint*((bladeTipVelocity/windVelocity)*(bladeTipVelocity/windVelocity))));

    cout << "Chord: " << chord << endl;

}

void runCalculator(){
    double radius = getRadius();
    for (double i=0; i<=radius; i=i+(radius/256)){

        cout << "I: " << i << endl;
        calculateChord(i);
    }


}