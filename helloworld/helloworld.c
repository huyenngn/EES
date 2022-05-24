/* helloworld.c for TOPPERS/ATK(OSEK) */ 
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

/* nxtOSEK hook to be invoked from an ISR in category 2 */
void user_1ms_isr_type2(void){ /* do nothing */ }

TASK(OSEK_Task_Background)
{
	U32 left_wheel = NXT_PORT_B;
	U32 right_wheel = NXT_PORT_A;
	U8 left_sensor = NXT_PORT_S1;
	U8 right_sensor = NXT_PORT_S4;
	
	ecrobot_set_light_sensor_active(left_sensor);
	ecrobot_set_light_sensor_active(right_sensor);
	while(1)
	{
  		if (ecrobot_get_light_sensor(left_sensor) < 500) {
			nxt_motor_set_speed(left_wheel, 0, 1);
			nxt_motor_set_speed(right_wheel, 50, 1);
			systick_wait_ms(500); /* 500msec wait */
  		}
		else if (ecrobot_get_light_sensor(right_sensor) < 500) {
			nxt_motor_set_speed(left_wheel, 50, 1);
			nxt_motor_set_speed(right_wheel, 0, 1);
			systick_wait_ms(500); /* 500msec wait */
  		}
  		nxt_motor_set_speed(left_wheel, 50, 1);
  		nxt_motor_set_speed(right_wheel, 50, 1);
		systick_wait_ms(50); /* 500msec wait */
	}
}
