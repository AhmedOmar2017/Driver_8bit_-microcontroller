/*
 * main.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Ahmed_Omar
 */


#include "App.h"

#include <avr/io.h>
#include <util/delay.h>


int main(){
	LCD_INIT();
	LCD_Print("hello");
}
