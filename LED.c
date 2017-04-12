#define F_CPU 1000000

#include <avr/io.h>
#include <avr/delay.h>

unsigned char vhod, rdeca, modra, zelena, vijola, rumena, cyan, bela, off, BarvaBlink;
int Barva, stevc, D, B, vhod2, klik, pavza;


void BLINKAJ(void)
{
	while(1)
	{
		PORTA = BarvaBlink;
		_delay_ms(500);
		if((PINA&(1<<PA0)!=0));
		else
		{
			_delay_ms(100);
			break;
		}
		PORTA = off;
		_delay_ms(500);
		if((PINA&(1<<PA0)!=0));
		else
		{
			_delay_ms(100);
			break;
		}
	}	
}


void SVETI(void)
{
	while(1)
	{
		if(Barva == 1)
		{
			PORTA =rdeca;
			BarvaBlink =rdeca;
		}
		else if(Barva == 2)
		{
			PORTA =zelena;
			BarvaBlink =zelena;
		}
		else if(Barva == 3)
		{
			PORTA =modra;
			BarvaBlink =modra;
		}
		else if(Barva == 4)
		{
			PORTA =rumena;
			BarvaBlink =rumena;
		}
		else if(Barva == 5)
		{
			PORTA =vijola;
			BarvaBlink=vijola;
		}
		else if(Barva == 6)
		{
			PORTA =cyan;
			BarvaBlink =cyan;
		}
		else if(Barva == 7)
		{
			PORTA =bela;
			BarvaBlink =bela;
		}
		else if(Barva > 7)
		Barva = 1;

		if((PINA&(1<<PA0)!=0));
		else
		{
			Barva +=1;
			if(Barva > 7)
			Barva = 1;
			_delay_ms(500);
			if((PINA&(1<<PA0)!=0));
			else
			{
				Barva = Barva-2;
				_delay_ms(300);
				//break;
				BLINKAJ();
			}
		}
	}
}

int main(void)
{
	DDRA = 0b11100000;
	DDRB = 0b00000000;
	PORTA = (1<<PA7)|(1<<PA6)|(1<<PA5)|(1<<PA0);
	rdeca =  0b10000000;
	modra =  0b01000000;
	zelena = 0b00100000;
	vijola = 0b11000000;
	rumena = 0b10100000;
	cyan =   0b01100000;
	bela =   0b11100000;
	off =    0b00000000;
	Barva = 1;
	stevc = 0;
	klik = 0;
	D = 0;
	pavza=100;
	vhod2 = PINA & 0x01;
	_delay_ms(500);
	PORTA = (0<<PA7)|(0<<PA6)|(0<<PA5);
	
	while(1)
	{
		_delay_ms(100);
		if((PINA&(1<<PA0)!=0))
		{
			//Barva=1;
			SVETI();
		}
		else
		{
			BLINKAJ();
		}
		
		
		
	}
}
