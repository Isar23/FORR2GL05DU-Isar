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
// ClawMotor            motor         4               
// ArmMotor             motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool killSwitchActivated = false;

// Declare Contoller event callbacks.
void whenControllerL1Pressed() {
  // Lift the ArmMotor.
  ArmMotor.spin(forward);
  // Wait until L1 is released.
  waitUntil(!Controller1.ButtonL1.pressing());
  // Stop the motor
  ArmMotor.stop();
}
void whenControllerL2Pressed() {
  // Lower the ArmMotor.
  ArmMotor.spin(reverse);
  // Wait until L2 is released.
  waitUntil(!Controller1.ButtonL2.pressing());
  // Stop the motor
  ArmMotor.stop();

}
void whenControllerR1Pressed() {
  // Open the ClawMotor.
  ClawMotor.spin(reverse);
  // Wait until R1 is released.
  waitUntil(!Controller1.ButtonR1.pressing());
  // Stop the motor
  ClawMotor.stop();

}
void whenControllerR2Pressed() {
  // Close the ClawMotor.
  ClawMotor.spin(forward);
  // Wait until R2 is released.
  waitUntil(!Controller1.ButtonR2.pressing());
  // Stop the motor
  ClawMotor.stop();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Initialize the Contoller Events
  Controller1.ButtonL1.pressed(whenControllerL1Pressed);
  Controller1.ButtonL2.pressed(whenControllerL2Pressed);
  Controller1.ButtonR1.pressed(whenControllerR1Pressed);
  Controller1.ButtonR2.pressed(whenControllerR2Pressed);

  // Set the brake mode and velocity of the ArmMotor and ClawMotor
  ClawMotor.setStopping(hold);
  ArmMotor.setStopping(hold);

  ClawMotor.setVelocity(30, percent);
  ClawMotor.setVelocity(60, percent);

  // Use tank drive to control the robot.
 while (true) {
    // Check if kill switch button (Button B) is pressed
    if (Controller1.ButtonB.pressing() || bumberA.pressing()) {
      // Toggle the kill switch state
      killSwitchActivated = !killSwitchActivated;
      
      // If kill switch is activated, stop all motors
      if (killSwitchActivated) {
        LeftMotor.stop();
        RightMotor.stop();
        ClawMotor.stop();
        ArmMotor.stop();
      }
      
      // Wait until Button B is released to prevent multiple toggles
      while (Controller1.ButtonB.pressing() || bumberA.pressing()) {
        wait(10, msec);
      }
    } 
    
    // If kill switch is not activated, control the motors with joystick inputs
    if (!killSwitchActivated) {
      LeftMotor.setVelocity(Controller1.Axis3.position(), percent);
      RightMotor.setVelocity(Controller1.Axis2.position(), percent);
      LeftMotor.spin(forward);
      RightMotor.spin(forward);
    }
    
    wait(25, msec);
  }
}