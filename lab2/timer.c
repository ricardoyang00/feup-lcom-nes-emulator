#include <lcom/lcf.h>
#include <lcom/timer.h>

#include <stdint.h>

#include "i8254.h"
#include "timer_utils.h"

static int timer_hook_id = 0;
static int counter = 0;

int (timer_set_frequency)(uint8_t timer, uint32_t freq) {
  if(timer > 2 || timer < 0) return -1;
  if (freq > TIMER_FREQ || freq < 19) return -1;

  uint8_t st;
  timer_get_conf(timer, &st);

  st = (st & 0x0F) | TIMER_LSB_MSB; 

  uint32_t val = TIMER_FREQ / freq;

  uint8_t MSB, LSB;
  util_get_MSB(val, &MSB);
  util_get_LSB(val, &LSB);

  uint8_t selectedTimer = TIMER_0 + timer;  

  switch (timer)
  {
  case 0:
    st |= TIMER_SEL0;
    break;
  case 1:
    st |= TIMER_SEL1;
    break;
  case 2:
    st |= TIMER_SEL2;
    break;
  
  default:
    break;
  }

  sys_outb(TIMER_CTRL, st);

  if (sys_outb(selectedTimer, LSB) != 0) return 1;
  if (sys_outb(selectedTimer, MSB) != 0) return 1;

  return 0;
}

int (timer_subscribe_int)(uint8_t *bit_no) {
  if(bit_no == NULL) return 1; 
  *bit_no = BIT(timer_hook_id);       

  return sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, &timer_hook_id);
}

int (timer_unsubscribe_int)() {
  return sys_irqrmpolicy(&timer_hook_id);
}

void (timer_int_handler)() {
  counter++;
}

int timer_get_counter(){
  return counter;
}
void timer_reset_counter(){
  counter = 0;
}

int (timer_get_conf)(uint8_t timer, uint8_t *st) {
  if (st == NULL) return 1;
  
  uint8_t rb_command = TIMER_RB_CMD | TIMER_RB_COUNT_ | TIMER_RB_SEL(timer);

  if(sys_outb(TIMER_CTRL,rb_command) != 0) return 1;

  if(util_sys_inb(TIMER_0 + timer, st) != 0) return 1;

  return 0;
}

int (timer_display_conf)(uint8_t timer, uint8_t st, enum timer_status_field field) {
  union timer_status_field_val val;

  switch (field) {
    case tsf_all: 
      val.byte = st; 
      break;

    case tsf_initial:                                       
      st = (st >> 4) & 0x03;
      val.in_mode = st;
      break;

    case tsf_mode:
      st = (st >> 1) & (BIT(0) | BIT(1) | BIT(2));
      val.count_mode = st;
      break;
    
    case tsf_base:
      val.bcd = st & BIT(0);
      break;        

    default:
      return 1;
  }

  if (timer_print_config(timer, field, val) != 0) return 1;
  return 0;
}