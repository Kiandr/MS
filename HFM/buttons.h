

#include <stdbool.h>
#include <stdint.h>
#include "boards.h"
#include "bsp.h"
#include "app_timer.h"
#include "nordic_common.h"
#include "nrf_error.h"

#define NRF_LOG_MODULE_NAME "APP"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"

#define APP_TIMER_PRESCALER      0                           /**< Value of the RTC1 PRESCALER register. */
#define APP_TIMER_OP_QUEUE_SIZE  2                           /**< Size of timer operation queues. */

#define BUTTON_PREV_ID           0                           /**< Button used to switch the state. */
#define BUTTON_NEXT_ID           1                           /**< Button used to switch the state. */

static bsp_indication_t actual_state =  BSP_INDICATE_FIRST;         /**< Currently indicated state. */

static const char * indications_list[] = BSP_INDICATIONS_LIST;

/**@brief Function for handling bsp events.
 */void bsp_evt_handler(bsp_event_t evt)
{
		switch (evt)
		{
    		case BSP_EVENT_KEY_0: //On Button 1 press
				LEDS_INVERT(BSP_LED_0_MASK); //Changes the current state of LED_1
				break;

			case BSP_EVENT_KEY_1: //On Button 2 press
				LEDS_INVERT(BSP_LED_1_MASK); //Changes the current state of LED_2
				break;

    		case BSP_EVENT_KEY_2: //On Button 3 press
				LEDS_INVERT(BSP_LED_2_MASK); //Changes the current state of LED_3
				break;

			case BSP_EVENT_KEY_3:	//On Button 4 press				
				LEDS_INVERT(BSP_LED_3_MASK); //Changes the current state of LED_4
				break;

    		default:
        		return; // no implementation needed
		}
		uint32_t err_code = NRF_SUCCESS;
		APP_ERROR_CHECK(err_code);
	}
/*
void bsp_evt_handler(bsp_event_t evt)
{
    uint32_t err_code;
    switch (evt)
    {
        case BSP_EVENT_KEY_0:
            if (actual_state != BSP_INDICATE_FIRST)
                actual_state--;
            else
                actual_state = BSP_INDICATE_LAST;
            break;

        case BSP_EVENT_KEY_1:

            if (actual_state != BSP_INDICATE_LAST)
                actual_state++;
            else
                actual_state = BSP_INDICATE_FIRST;
            break;

        default:
            return; // no implementation needed
    }
    err_code = bsp_indication_set(actual_state);
    NRF_LOG_INFO("%s\r\n", (uint32_t)indications_list[actual_state]);
    APP_ERROR_CHECK(err_code);
}
*/

/**@brief Function for initializing low frequency clock.
 */
void clock_initialization()
{
    NRF_CLOCK->LFCLKSRC            = (CLOCK_LFCLKSRC_SRC_Xtal << CLOCK_LFCLKSRC_SRC_Pos);
    NRF_CLOCK->EVENTS_LFCLKSTARTED = 0;
    NRF_CLOCK->TASKS_LFCLKSTART    = 1;

    while (NRF_CLOCK->EVENTS_LFCLKSTARTED == 0)
    {
        // Do nothing.
    }
}


/**@brief Function for initializing bsp module.
 */
void bsp_configuration()
{
    uint32_t err_code;

    err_code = bsp_init(BSP_INIT_LED | BSP_INIT_BUTTONS,
                        APP_TIMER_TICKS(100, APP_TIMER_PRESCALER),
                        bsp_evt_handler);
    APP_ERROR_CHECK(err_code);
}


/**
 * @brief Function for application main entry.
 */
void kianButton(void)
{
    clock_initialization();
    APP_TIMER_INIT(APP_TIMER_PRESCALER, APP_TIMER_OP_QUEUE_SIZE, NULL);
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));

    NRF_LOG_INFO("BSP example started.\r\n");
    bsp_configuration();

 //   while (true)
    {
        NRF_LOG_FLUSH();
     //   __SEV();
      //  __WFE();
       // __WFE();
        // no implementation needed
    }
}


/** @} */
