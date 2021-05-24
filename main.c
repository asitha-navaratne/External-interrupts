#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_DDR		DDRB					///< DDR of indicator LED.
#define LED_PORT	PORTB					///< Port of indicator LED.
#define LED_PIN		PB0					///< Pin of indicator LED.

void PORT_INIT(void);
void INT_INIT(void);

volatile uint8_t buttonState = 0;

/*!
 *	@brief ISR for INT0 External Interrupt; turns LED on or off depending on the button state. 
 */

ISR(INT0_vect){
	if(!buttonState){
		buttonState = 1;
		LED_PORT |= (1<<LED_PIN);
	}
	else{
		buttonState = 0;
		LED_PORT &= ~(1<<LED_PIN);
	}
}

int main(void){
	PORT_INIT();
	INT_INIT();
	sei();							///< Enable global interrupts.
	
	while(1);
}

/*!
 *	@brief Initialize Ports.
 */

void PORT_INIT(void){
	LED_DDR |= (1<<LED_PIN);
	DDRD &= ~(1<<PD2);					///< Set INT0 pin to input.
}

/*!
 *	@brief Initialize external interrupts.
 */

void INT_INIT(void){
	MCUCR |= (1<<ISC00)|(1<<ISC01);				///< A rising edge at INT0 generates an interrupt request.
	GICR |= (1<<INT0);					///< Enable INT0 external interrupt request.
}
