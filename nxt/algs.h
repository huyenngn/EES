#ifndef _ALGS_H_
#define _ALGS_H_

/* Ports */
#define LEFT_WHEEL NXT_PORT_B
#define RIGHT_WHEEL NXT_PORT_A
#define LEFT_SENSOR NXT_PORT_S2
#define RIGHT_SENSOR NXT_PORT_S4

void move(int n);

void turn(int deg);

void lane_assist();

#endif
