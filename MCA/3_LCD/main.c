#include <lpc214x.h>
#include "../pll/pll.h"
#include "../timer/timer.h"

#define bit(x) (1 << x)

unsigned int i;

void lcd_int(void);
void dat(unsigned char);
void cmd(unsigned char);
void string(unsigned char *);

unsigned int adc(int no,int ch)
{
    switch(no)                                    //select adc
    {
        case 0: AD0CR=0x00200600|(1<<ch);       //select channel
                AD0CR|=(1<<24);                 //start conversion
                while((AD0GDR& (1<<31))==0);
                val=AD0GDR;
                break;
        case 1: AD1CR=0x00200600|(1<<ch);       //select channel
                AD1CR|=(1<<24);                 //start conversion
                while((AD1GDR&(1<<31))==0);
                val=AD1GDR;
                break;
    }
    val=(val >> 6) & 0x03FF;                   // bit 6:15 is 10 bit AD value
    return val;
}
int main()
{
    int shift = 0;
    PLL_Init_60MHz();
    IO0DIR |= 0XFFF;
    lcd_int();
    cmd(0x80);
    string("          MSIS MANIPAL");
    while (1)
    {
        if (shift < 20)
        {
            cmd(0x18);
            delay_ms_timer0(100);
            shift++;
        }
        else
        {
            string("  MSIS MANIPAL");
            shift = 0;
        }
    }
}

void lcd_int()
{
    cmd(0x30);
    cmd(0x0c);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}

void cmd(unsigned char a)
{
    IO0PIN &= 0x00;
    IO0PIN |= (a << 0);
    IO0CLR |= bit(8);  // rs=0
    IO0CLR |= bit(9);  // rw=0
    IO0SET |= bit(10); // en=1
    delay_us_timer0(100);
    IO0CLR |= bit(10); // en=0
}

void dat(unsigned char b)
{
    IO0PIN &= 0x00;
    IO0PIN |= (b << 0);
    IO0SET |= bit(8);  // rs=1
    IO0CLR |= bit(9);  // rw=0
    IO0SET |= bit(10); // en=1
    delay_us_timer0(100);
    IO0CLR |= bit(10); // en=0
}

void string(unsigned char *p)
{
    while (*p != '\0')
    {
        dat(*p++);
    }
}
