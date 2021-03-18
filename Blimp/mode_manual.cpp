#include "Blimp.h"
/*
 * Init and run calls for stabilize flight mode
 */

// manual_run - runs the main manual controller
// should be called at 100hz or more
void ModeManual::run()
{
    // convert pilot input to lean angles
    // float target_right, target_front;
    // get_pilot_desired_accelerations(target_right, target_front);

    motors->right_out = channel_right->get_control_in();
    motors->front_out = channel_front->get_control_in();
    motors->yaw_out = channel_yaw->get_control_in();
    motors->down_out = channel_down->get_control_in();

    if (!motors->armed()) {
        // Motors should be Stopped
        motors->set_desired_spool_state(Fins::DesiredSpoolState::SHUT_DOWN);
    } else {
        motors->set_desired_spool_state(Fins::DesiredSpoolState::THROTTLE_UNLIMITED);
    }



    // motors->output(); //MIR need to add sending direction & throttle commands.
}
