#include "librobot.h"

void init_button_sensor(void){
	/* --------------- Begin Answer to Task 1a Here ------------ */
    DDRD |= (0<<PD7) | (1<<PD5);
    PORTD |= (1<<PD7) | (0<<PD5);;
	/* --------------- End Answer to Task 1a Here -------------- */
    return;
}

int read_button_sensor(void){
	int pressed;
	/* --------------- Begin Answer to Task 1b Here ------------ */
        if(PIND & 0b10000000)
        {
            pressed = 1;
        }
        else
        {
            pressed = 0;
        }
	/* --------------- End Answer to Task 1b Here -------------- */
	return pressed;
}

float read_knob_sensor(int knob){
	float reading = 0; /* Sensor reading, normalised
						  (i.e., scaled) to be between 
						  zero and one. */
	/* --------------- Begin Answer to Task 2 Here ------------ */
    DDRC = 0x00;

    if (knob == 0) {
        ADMUX &= ~(1<<MUX0);
        }
    else if (knob == 1) {
        ADMUX |= (1<<MUX0);
        }
    ADCSRA |= (1<<ADSC);
    while(ADCSRA & (1<<ADSC))
    ;
    reading = (float)ADCH/255;
	/* --------------- End Answer to Task 2 Here -------------- */
	return reading;
}


void init_arm_motors(void) {
	/* --------------- Begin Answer to Task 3 Here ------------ */
    DDRB |= (1<<PB1) | (1<<PB2);
    PORTB = 0x00;
    TCCR1A = (1<<COM1A1) | (1<<COM1B1);
    
    TCCR1A |= (0<<WGM10) | (1<<WGM11);
    TCCR1B = (1<<WGM12) | (1<<WGM13);
    TCCR1B |= (1<<CS11);
    ICR1 = 40000;
    
	/* --------------- End Answer to Task 3 Here -------------- */
	return;
}
