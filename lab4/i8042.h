#ifndef _LCOM_I8042_H_
#define _LCOM_I8042_H_

#include <lcom/lcf.h>

// KEYBOARD RELATED
#define KBD_IRQ                     1

#define KBD_STAT_REG                0x64
#define KBD_IN_BUF                  0x64
#define KBD_OUT_BUF                 0x60

#define KBC_READ_CMD                0x20
#define KBC_WRITE_CMD               0x60

#define KBD_PARITY_ERR              BIT(7)
#define KBD_TIMEOUT_ERR             BIT(6)
#define KBD_INHIBIT_FLAG            BIT(4)
#define KBD_IN_BUF_FULL             BIT(1)
#define KBD_OUT_BUF_FULL            BIT(0)

#define KBD_ESC_BREAK_CODE          0x81
#define KBD_MAKE_CODE               BIT(7)    //1 if make
#define KBD_TWO_BYTE                0xE0



// MOUSE RELATED
#define MOUSE_IRQ 12

#define MOUSE_LB                    BIT(0)
#define MOUSE_RB                    BIT(1)
#define MOUSE_MB                    BIT(2)
#define MOUSE_FIRST_BYTE            BIT(3)
#define MOUSE_X_SIGNAL              BIT(4)
#define MOUSE_Y_SIGNAL              BIT(5)
#define MOUSE_X_OVERFLOW            BIT(6)
#define MOUSE_Y_OVERFLOW            BIT(7)

#define MOUSE_DISABLE_DATA_REPORT   0xF5
#define MOUSE_ENABLE_DATA_REPORT    0xF4
#define MOUSE_ENABLE_STREAM_MODE    0xEA
#define MOUSE_READ_DATA             0xEB
#define MOUSE_WRITE_BYTE            0xD4

// GENERAL
#define MAX_ATTEMPS 10
#define DELAY 10000     // 10 ms

#endif
