#ifndef _FireAlarmSystem_h
#define _FireAlarmSystem_h

#include <stdint.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */
typedef enum
{
    FireAlarmSystem__OFF,
    FireAlarmSystem__ON,
    FireAlarmSystem__TEST
    
} FireAlarmSystem__STATE;
#define FireAlarmSystem__STATE__max 3

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */

/* Clause CONCRETE_VARIABLES */

extern void FireAlarmSystem__INITIALISATION(void);

/* Clause OPERATIONS */

extern void FireAlarmSystem__ActivateAlarm(void);
extern void FireAlarmSystem__DeactivateAlarm(void);
extern void FireAlarmSystem__UpdateSensorStatus(bool new_status);
extern void FireAlarmSystem__EnterTestMode(void);
extern void FireAlarmSystem__ExitTestMode(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _FireAlarmSystem_h */
