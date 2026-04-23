/* WARNING if type checker is not performed, translation could contain errors ! */

#include "FireAlarmSystem.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static FireAlarmSystem__STATE FireAlarmSystem__alarm_state;
static bool FireAlarmSystem__sensor_status;
static bool FireAlarmSystem__test_mode_enabled;
/* Clause INITIALISATION */
void FireAlarmSystem__INITIALISATION(void)
{
    
    FireAlarmSystem__alarm_state = FireAlarmSystem__OFF;
    FireAlarmSystem__sensor_status = false;
    FireAlarmSystem__test_mode_enabled = false;
}

/* Clause OPERATIONS */

void FireAlarmSystem__ActivateAlarm(void)
{
    if(((FireAlarmSystem__alarm_state == FireAlarmSystem__OFF) &&
        (FireAlarmSystem__sensor_status == true)) &&
    (FireAlarmSystem__test_mode_enabled == false))
    {
        FireAlarmSystem__alarm_state = FireAlarmSystem__ON;
        FireAlarmSystem__test_mode_enabled = false;
    }
}

void FireAlarmSystem__DeactivateAlarm(void)
{
    if(FireAlarmSystem__alarm_state == FireAlarmSystem__ON)
    {
        FireAlarmSystem__alarm_state = FireAlarmSystem__OFF;
        FireAlarmSystem__sensor_status = false;
        FireAlarmSystem__test_mode_enabled = false;
    }
}

void FireAlarmSystem__UpdateSensorStatus(bool new_status)
{
    if((new_status == true) ||
    (new_status == false))
    {
        FireAlarmSystem__sensor_status = new_status;
        if(new_status == true)
        {
            FireAlarmSystem__alarm_state = FireAlarmSystem__ON;
            FireAlarmSystem__test_mode_enabled = false;
        }
        else
        {
            FireAlarmSystem__alarm_state = FireAlarmSystem__OFF;
            FireAlarmSystem__test_mode_enabled = false;
        }
    }
}

void FireAlarmSystem__EnterTestMode(void)
{
    if((FireAlarmSystem__alarm_state == FireAlarmSystem__OFF) &&
    (FireAlarmSystem__test_mode_enabled == false))
    {
        FireAlarmSystem__alarm_state = FireAlarmSystem__TEST;
        FireAlarmSystem__test_mode_enabled = true;
    }
}

void FireAlarmSystem__ExitTestMode(void)
{
    if((FireAlarmSystem__alarm_state == FireAlarmSystem__TEST) &&
    (FireAlarmSystem__test_mode_enabled == true))
    {
        FireAlarmSystem__alarm_state = FireAlarmSystem__OFF;
        FireAlarmSystem__test_mode_enabled = false;
    }
}

