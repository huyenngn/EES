#include "ecrobot_interface.h"
#include "algs.h"
#include <stdlib.h>

void move(int n) {
    int direction = n/abs(n);
    for(int i=0; i<n; i++) {
        nxt_motor_set_speed(LEFT_WHEEL, 70*direction, 1);
        nxt_motor_set_speed(RIGHT_WHEEL, 70*direction, 1);
        systick_wait_ms(50*abs(n));
        lane_assist();
    }
    nxt_motor_set_speed(LEFT_WHEEL, 0, 1);
    nxt_motor_set_speed(RIGHT_WHEEL, 0, 1);
}

void turn(int deg) {
    int direction = deg/abs(deg);

    nxt_motor_set_speed(LEFT_WHEEL, -100*direction, 1);
    nxt_motor_set_speed(RIGHT_WHEEL, 100*direction, 1);

    systick_wait_ms(4*abs(deg));

    nxt_motor_set_speed(LEFT_WHEEL, 0, 1);
    nxt_motor_set_speed(RIGHT_WHEEL, 0, 1);
}

void lane_assist() {
    while(ecrobot_get_light_sensor(LEFT_SENSOR) < 600) {
        turn(10);
    }

    while(ecrobot_get_light_sensor(RIGHT_SENSOR) < 600) {
        turn(-10);
    }
}
