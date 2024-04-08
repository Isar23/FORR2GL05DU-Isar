/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Tue Oct 01 2019                                           */
/*    Description:  Clawbot Control                                           */
/*                  This program uses Controller events to drive the arm and  */
/*                  claw of the V5 Clawbot.                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotor            motor         1               
// RightMotor           motor         3              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool killSwitchActivated = false;
bool isTurning = false; // Variable to track whether the robot is currently turning

// Function to drive the robot in a circle with a given radius for a certain duration
void driveCircle(float radius, int duration) {
    // Define the wheel diameter in meters
    float wheelDiameter = 0.1; // Assuming wheel diameter of 10 cm (0.1 meters)
    
    // Calculate the circumference of the wheel
    float wheelCircumference = M_PI * wheelDiameter;
    // Calculate the circumference of the circle with the given radius
    float circleCircumference = 2 * M_PI * radius;
    // Calculate the ratio of the circle circumference to the wheel circumference
    float ratio = circleCircumference / wheelCircumference;

    // Define a constant speed for the inner wheel
    double innerSpeed = 25;
    
    // Define outerSpeed as double the innerSpeed 
    double outerSpeed = innerSpeed * 2;

    // Drive the robot in a circle for the specified duration
    LeftMotor.spin(directionType::fwd, outerSpeed, velocityUnits::pct);
    RightMotor.spin(directionType::fwd, innerSpeed, velocityUnits::pct);

    // Wait for the specified duration
    wait(duration, msec);

    // Stop the motors after the specified duration
    LeftMotor.stop();
    RightMotor.stop();

    // Set isTurning to false to indicate that the robot has stopped turning
    isTurning = false;
}

int main() {
    // Initializing Robot Configuration.
    vexcodeInit();

    // Use tank drive to control the robot.
    while (true) {
        // Check if kill switch button (Button B) is pressed
        if (Controller1.ButtonB.pressing() || bumberA.pressing()) {
            // Toggle the kill switch state
            killSwitchActivated = !killSwitchActivated;

            // If kill switch is activated, stop all motors and reset isTurning
            if (killSwitchActivated) {
                LeftMotor.stop();
                RightMotor.stop();
                isTurning = false;
            }

            // Wait until Button B is released to prevent multiple toggles
            while (Controller1.ButtonB.pressing() || bumberA.pressing()) {
                wait(10, msec);
            }
        } 
        
        // If kill switch is not activated and the robot is not currently turning, drive the robot in a circle
        if (!killSwitchActivated && !isTurning) {
            // Call the function to drive in a circle with the specified radius (e.g., 0.5 meters) for 2 seconds (2000 milliseconds)
            driveCircle(1, 7500); // Here you can change the radius and duration as needed
            // Set isTurning to true to indicate that the robot is currently turning
            isTurning = true;
        }
        
        wait(25, msec);
    }
}
