/* FireAlarmSystem
 * Author: MAHAM, AYESHA
 * Creation date: 11/25/2024
 */
MACHINE FireAlarmSystem

SETS
    STATE = {OFF, ON, TEST} /* OFF: Alarm is inactive, ON: Alarm is active, TEST: Alarm in test mode */

VARIABLES
    alarm_state, sensor_status, test_mode_enabled

INVARIANT
    alarm_state : STATE & 
    sensor_status : BOOL &
    test_mode_enabled : BOOL &
    (alarm_state = ON => sensor_status = TRUE) & 
    (alarm_state = TEST => test_mode_enabled = TRUE) &
    (alarm_state /= TEST => test_mode_enabled = FALSE)

INITIALISATION
    alarm_state := OFF || sensor_status := FALSE || test_mode_enabled := FALSE

OPERATIONS

/* Activate the alarm when fire is detected */
ActivateAlarm =
    PRE
        alarm_state = OFF & sensor_status = TRUE & test_mode_enabled = FALSE
    THEN
        alarm_state := ON || test_mode_enabled := FALSE
    END;

/* Deactivate the alarm manually */
DeactivateAlarm =
    PRE
        alarm_state = ON
    THEN
        alarm_state := OFF || sensor_status := FALSE || test_mode_enabled := FALSE
    END;

/* Update the sensor status (fire detected or resolved) */
UpdateSensorStatus(new_status) =
    PRE
        new_status : BOOL
    THEN
        sensor_status := new_status ||
        IF new_status = TRUE THEN 
            alarm_state := ON || test_mode_enabled := FALSE
        ELSE
            alarm_state := OFF || test_mode_enabled := FALSE
        END
    END;

/* Enter test mode for maintenance */
EnterTestMode =
    PRE
        alarm_state = OFF & test_mode_enabled = FALSE
    THEN
        alarm_state := TEST || test_mode_enabled := TRUE
    END;

/* Exit test mode and return to normal state */
ExitTestMode =
    PRE
        alarm_state = TEST & test_mode_enabled = TRUE
    THEN
        alarm_state := OFF || test_mode_enabled := FALSE
    END

END
