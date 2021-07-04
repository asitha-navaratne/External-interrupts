# External-interrupts

<p align="justify">The ATmega32A is capable of triggering External Interrupts using the INT0, INT1 and INT2 pins located at PD2, PD3 and PB2 respectively.</p>

<p align="justify">Interrupts are triggered by the processor when a certain event or condition occurs. When said interrupt condition occurs, the normal execution of the program 
is "interrupted" i.e. paused temporarily, and the processor begins to execute a special function within the program called an <em>Interrupt Service Routine</em> or ISR. Once the 
code within the ISR has been completely executed, the program returns to the normal flow of execution and continues from where it stopped.</p>

<p align="justify">Interrupts are very important for low-level programming. They allow certain code to be executed only if a certain event occurs, and allow the code to be 
executed repeatedly as long as the program is running and the interrupt conditions occur. Interrupts are used for many Operating System tasks, most notably for communicating with 
peripherals and devices. For example, old keyboards and mice which used the PS/2 connector for interfacing with the motherboard used interrupts to register events such as key
presses and mouse clicks. Since they use interrupts, they are believed to be faster and more responsive than USB keyboards and mice, which did not use interrupts, and are 
therefore still used by professional gamers (though this belief is actually incorrect; USB devices, though not using interrupts, are just as fast as, and sometimes even faster than PS/2 devices).</p>

<p align="justify">The ATmega32A has many different kinds of interrupts that occur due to different events or conditions; ADC interrupts, USART interrupts, timer/counter interrupts etc. One
such type of interrupts are External Interrupts, which occurs if there is a logic change at certain specified pins of the microcontroller, specifically INT0, INT1 or INT2.</p>

<p align="justify">First, external interrupts have to be enabled by setting the relevant bits of the MCUCR and GICR registers. Next, the ISR for external interrupts has to be specified with the relevant Interrupt Vector. An Interrupt Vector is used to link an ISR to the type of interrupt that should call it. For external interrupts at INT0 pin, the interrupt vector would be <em>INT0_vect</em>. Finally, global interrupts have to be enabled in the microcontroller using the inbuilt <em>sei()</em> function. Without enabling global interrupts, the microcontroller will not handle any interrupts that occur. Now, whenever there is a rising edge at the INT0 pin, the code in the ISR will be executed. This is useful, for example, to interface push buttons as switches with the microcontroller.</p>
