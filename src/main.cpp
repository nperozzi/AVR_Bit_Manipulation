                                                         /* Cylon Eyes */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include <stdlib.h>

#define ROW_PORT PORTB
#define COL_PORT PORTD
#define DELAY   44


// ------ Prototypes ------ //
void activateColumn(uint8_t col);
void activateColGoRight(uint8_t time);
void deactivateColGoRight(uint8_t time);
void activateColGoLeft(uint8_t time);
void deactivateColGoLeft(uint8_t time);
void toggleRandomCol(uint8_t time);
void toggleRandomLed(uint8_t time);

// ------ Main ------ //
int main(void) {

  // -------- Inits --------- //
  DDRB = 0xff;
  DDRD = 0xff;

  // ------ Event loop ------ //
  while (1) 
  {
    toggleRandomLed(DELAY);
  }    
  return 0;
}

// ------ Function Def. ------ //
void activateColumn(uint8_t col)
{
  ROW_PORT = 0b00000000;
  _delay_ms(2);
  COL_PORT = 0b00000010;
  _delay_ms(2);
}

void activateColGoRight(uint8_t time)
{
  for(uint8_t i = 0; i < 8; i++)
  {
    COL_PORT |= (1 << i);
    _delay_ms(time);
  }
}

void deactivateColGoRight(uint8_t time)
{
  for(uint8_t i = 0; i < 8; i++)
  {
    COL_PORT &= ~(1 << i);
    _delay_ms(time);
  }
}

void activateColGoLeft(uint8_t time)
{
  for(uint8_t i = 7; i < 255; i--)
  {
    COL_PORT |= (1 << i);
    _delay_ms(time);
  }
}

void deactivateColGoLeft(uint8_t time)
{
  for(uint8_t i = 7; i < 255; i--)
  {
    COL_PORT &= ~(1 << i);
    _delay_ms(time);
  }
}

void toggleRandomCol(uint8_t time)
{
  //seed the random number function
  srand(42);

  while(1)
  {
  uint8_t randomNum = rand();

  //Select the column
  uint8_t ledCol = randomNum & 0x07;   //Keep the last 3 bin digits of randomNum

  //Toggle column
  COL_PORT ^= (1 << ledCol);
  _delay_ms(time);
  }
}

void toggleRandomLed(uint8_t time)
{
  //seed the random number function
  srand(42);

  while (1)
  {
    uint8_t randomCol = rand();
    uint8_t randomRow = rand();

    //Select column and row
    uint8_t ledCol = randomCol & 0x07;
    uint8_t ledRow = randomRow & 0x07;
    
    uint32_t t = 0;
    while(t < time)
    {
      ROW_PORT = ~(1 << ledRow);
      _delay_us(20);
      COL_PORT ^= (1 << ledCol);      
      _delay_us(20);
      t++;
    }
    ROW_PORT = 0x00;
    _delay_us(20);
  }
}