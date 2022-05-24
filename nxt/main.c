/* helloworld.c for TOPPERS/ATK(OSEK) */
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "algs.h"

/* OSEK declarations */
DeclareTask(OSEK_Task_Background);

/* hook is invoked when the NXT was turned on. */
void ecrobot_device_initialize() {
    ecrobot_set_light_sensor_active(LEFT_SENSOR);
    ecrobot_set_light_sensor_active(RIGHT_SENSOR);
}

/* hook is invoked when STOP or EXIT button was pressed. */
void ecrobot_device_terminate() {

}

/* nxtOSEK hook to be invoked from an ISR in category 2 */
void user_1ms_isr_type2(void) {
	/* do nothing */
}


TASK(OSEK_Task_Background)
{
	move(1);
	while(1)
	{
	}
}
