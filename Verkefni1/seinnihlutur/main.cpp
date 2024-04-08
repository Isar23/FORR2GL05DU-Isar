/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Moving Forward (mm)                                       */
/*                                                                            */
/*    This Program drives the robot forward for 150 millimeters.              */
/*                                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 3, D
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration.
  vexcodeInit();

  // Set the stopping mode of the drivetrain to hold
  Drivetrain.setStopping(hold);

  // Loop for the distances (0.5, 1, 1.5, 2, 2.5 meters)
  for (float distance = 0.5; distance <= 2.5; distance += 0.5) {
    
    // Move forward
    Drivetrain.driveFor(forward, distance * 1000, mm);  // Convert distance from meters to millimeters

    // Sleep For 250 milliseconds
    vex::task::sleep(350);

    // Move backward
    Drivetrain.driveFor(reverse, distance * 1000, mm);  // Convert distance from meters to millimeters

    // Sleep For 250 milliseconds
    vex::task::sleep(350);
  }


  // Stop the drivetrain
  Drivetrain.stop();

  return 0;
}
