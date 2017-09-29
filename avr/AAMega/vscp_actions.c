/* This is an modification of the demo_vscp_node_can128, credits to Akhe
 * see original header below this file
 * more information about VSCP: http://www.vscp.org
 *---------------------------------------------------------------------------
*/


#include "vscp_compiler.h"
#include "vscp_projdefs.h"
#include "vscp_class.h"
#include "vscp_type.h"
#include "vscp_actions.h"
#include "vscp_registers.h"


///////////////////////////////////////////////////////////////////////////////
void doActionToggleOut( unsigned char port, unsigned char dmflags, unsigned char arg )
{
#ifdef PRINT_DM_EVENTS
uart_puts( "debug doActionToggleOut\n" );
#endif

	unsigned char i;
	
	for ( i=0; i<8; i++ ) 
	{
		// If the relay should not be handled just move on
		if ( !( arg & ( 1 << i ) ) ) continue;
		
		// Check if zone should match and if so if it match
		if ( dmflags & VSCP_DM_FLAG_CHECK_ZONE ) 
		{
			if ( vscp_imsg.data[ 1 ] != readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_ZONE + i + ((port-1) * 8)) ) 
				{
				continue;
				}
		}

		// Check if subzone should match and if so if it match
		if ( dmflags & VSCP_DM_FLAG_CHECK_SUBZONE ) 
		{
			if ( vscp_imsg.data[ 2 ] != readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_SUBZONE + i + ((port-1) * 8)) ) 
				{
				continue;
				}
		}
			
		if (port == 1) outputport1 ^= _BV(i);
		if (port == 2) outputport2 ^= _BV(portflip(i));
		if (port == 3) outputport3 ^= _BV(i);
		if (port == 4) outputport4 ^= _BV(i);

		
	}								
}

///////////////////////////////////////////////////////////////////////////////
// doActionON
void doActionOnOut( unsigned char port, unsigned char dmflags, unsigned char arg )
{
#ifdef PRINT_DM_EVENTS
uart_puts( "debug doActionOnOut\n" );
#endif
	unsigned char i;
	
	for ( i=0; i<8; i++ ) 
	{
		#ifdef PRINT_DM_EVENTS
		uart_puts( "debug doActionOnOut i" );
		#endif
		// If the rely should not be handled just move on
		if ( !( arg & ( 1 << i ) ) ) continue;
		
		// Check if zone should match and if so if it match
		if ( dmflags & VSCP_DM_FLAG_CHECK_ZONE ) 
		{
			if ( vscp_imsg.data[ 1 ] != readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_ZONE + i + ((port-1) * 8) ) ) 
				{
				continue;
				}
		}

		// Check if subzone should match and if so if it match
		if ( dmflags & VSCP_DM_FLAG_CHECK_SUBZONE ) 
		{
			if ( vscp_imsg.data[ 2 ] != readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_SUBZONE + i  + ((port-1) * 8)) ) 
				{
				continue;
				}
		}			
		if (port == 1) outputport1 &= ~ _BV(i);
		if (port == 2) outputport2 &= ~ _BV(portflip(i));
		if (port == 3) outputport3 &= ~ _BV(i);
		if (port == 4) outputport4 &= ~ _BV(i);

	}	
}



///////////////////////////////////////////////////////////////////////////////
// doActionOFF
void doActionOffOut( unsigned char port, unsigned char dmflags, unsigned char arg )
{
#ifdef PRINT_DM_EVENTS
uart_puts( "debug doActionOffOut\n" );
#endif
	unsigned char i;
	
	for ( i=0; i<8; i++ ) 
	{
		#ifdef PRINT_DM_EVENTS
		uart_puts( "debug doActionOffOut i" );
		#endif
		// If the rely should not be handled just move on
		if ( !( arg & ( 1 << i ) ) ) continue;
		
		// Check if zone should match and if so if it match
		if ( dmflags & VSCP_DM_FLAG_CHECK_ZONE ) 
		{
			if ( vscp_imsg.data[ 1 ] != readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_ZONE + i  + ((port-1) * 8)) ) 
				{
				continue;
				}
		}

		// Check if subzone should match and if so if it match
		if ( dmflags & VSCP_DM_FLAG_CHECK_SUBZONE ) 
		{
			if ( vscp_imsg.data[ 2 ] != readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_SUBZONE + i  + ((port-1) * 8)) ) 
				{
				continue;
				}
		}		
		if (port == 1) outputport1 |= _BV(i);
		if (port == 2) outputport2 |= _BV(portflip(i));
		if (port == 3) outputport3 |= _BV(i);
		if (port == 4) outputport4 |= _BV(i);

	}						
}

///////////////////////////////////////////////////////////////////////////////
void doActionToggleDM( unsigned char dmflags, unsigned char arg )
{
	#ifdef PRINT_DM_EVENTS
	uart_puts( "debug doActionToggleDM\n" );
	#endif

	unsigned char i;
	uint8_t dmToggleflags;
	//unsigned char val;
	
	for ( i=0; i<8; i++ )
	{
		// If the line should not be handled just move on
		if ( !( arg & ( 1 << i ) ) ) continue;
		
		// Check if subzone should match and if so if it match
		if ( dmflags & VSCP_DM_FLAG_CHECK_SUBZONE )
		{
			if ( vscp_imsg.data[ 2 ] != readEEPROM( VSCP_EEPROM_REGISTER + REG_SUBZONE  ) )
			{
				continue;
			}
			#ifdef PRINT_DM_EVENTS
			else uart_puts( "ToggleDM subzone match\n" );
			#endif
		}
		
		dmToggleflags = readEEPROM( VSCP_EEPROM_REGISTER + REG_DM_START  + VSCP_DM_POS_FLAGS + ( VSCP_SIZE_STD_DM_ROW * i ) );
		writeEEPROM(( VSCP_EEPROM_REGISTER + REG_DM_START  + VSCP_DM_POS_FLAGS + ( VSCP_SIZE_STD_DM_ROW * i )),dmToggleflags^VSCP_DM_FLAG_ENABLED );		


	}
}

///////////////////////////////////////////////////////////////////////////////
// doActionON DM
void doActionOnDM( unsigned char dmflags, unsigned char arg )
{
	#ifdef PRINT_DM_EVENTS
	uart_puts( "debug doActionOnDM\n" );
	#endif
	unsigned char i;
	uint8_t dmToggleflags;
	
	for ( i=0; i<8; i++ )
	{
		#ifdef PRINT_DM_EVENTS
		uart_puts( "debug doActionOnDM i" );
		#endif
		// If the rely should not be handled just move on
		if ( !( arg & ( 1 << i ) ) ) continue;
		
		// Check if subzone should match and if so if it match
		if ( dmflags & VSCP_DM_FLAG_CHECK_SUBZONE )
		{
			if ( vscp_imsg.data[ 2 ] != readEEPROM( VSCP_EEPROM_REGISTER + REG_SUBZONE ) )
			{
				continue;
			}
		}
		
		dmToggleflags = readEEPROM( VSCP_EEPROM_REGISTER + REG_DM_START  + VSCP_DM_POS_FLAGS + ( VSCP_SIZE_STD_DM_ROW * i ) );
		writeEEPROM(( VSCP_EEPROM_REGISTER + REG_DM_START  + VSCP_DM_POS_FLAGS + ( VSCP_SIZE_STD_DM_ROW * i )),dmToggleflags |VSCP_DM_FLAG_ENABLED );
		
		//outputport &= ~ _BV(i);


	}
}



///////////////////////////////////////////////////////////////////////////////
// doActionOFF DM
void doActionOffDM( unsigned char dmflags, unsigned char arg )
{
	#ifdef PRINT_DM_EVENTS
	uart_puts( "debug doActionOffDM\n" );
	#endif
	unsigned char i;
	uint8_t dmToggleflags;
	
	for ( i=0; i<8; i++ )
	{
		#ifdef PRINT_DM_EVENTS
		uart_puts( "debug doActionOffDM i" );
		#endif
		// If the rely should not be handled just move on
		if ( !( arg & ( 1 << i ) ) ) continue;
		
				// Check if subzone should match and if so if it match
		if ( dmflags & VSCP_DM_FLAG_CHECK_SUBZONE )
		{
			if ( vscp_imsg.data[ 2 ] != readEEPROM( VSCP_EEPROM_REGISTER + REG_SUBZONE) )
			{
				continue;
			}
		}
		
		dmToggleflags = readEEPROM( VSCP_EEPROM_REGISTER + REG_DM_START  + VSCP_DM_POS_FLAGS + ( VSCP_SIZE_STD_DM_ROW * i ) );
		writeEEPROM(( VSCP_EEPROM_REGISTER + REG_DM_START  + VSCP_DM_POS_FLAGS + ( VSCP_SIZE_STD_DM_ROW * i )),dmToggleflags & ~(VSCP_DM_FLAG_ENABLED) );
				
		//outputport |= _BV(i);


	}
}

///////////////////////////////////////////////////////////////////////////////
// doActionSetTimer
void doActionSetTimer(unsigned char select_timer, unsigned char dmflags, unsigned char arg)
{
	#ifdef PRINT_DM_EVENTS
	uart_puts( "debug doActionSetTimer\n" );
	#endif
	unsigned char i;
	i = select_timer-1;

	#ifdef PRINT_TIMER_EVENTS
	char buf[50];
	sprintf(buf, "doActionSetTimer:%i",	select_timer);
	uart_puts(buf);
	uart_puts( "doActionSetTimer check zone" );
	//sprintf(buf, "doActionSetTimer check zone in reg: %i, %i",vscp_imsg.data[ 1 ],readEEPROM( VSCP_EEPROM_REGISTER + REG_TIMER1_ZONE ));
	//uart_puts(buf);
	#endif
			
		// Check if zone should match and if so if it match
			
		if ((!( dmflags & VSCP_DM_FLAG_CHECK_ZONE ))|(( dmflags & VSCP_DM_FLAG_CHECK_ZONE ) &&(vscp_imsg.data[ 1 ] == readEEPROM( VSCP_EEPROM_REGISTER + REG_TIMER1_ZONE +i*12))))
			{
			#ifdef PRINT_TIMER_EVENTS
			uart_puts( "doActionSetTimer check zone OK" );
			#endif
			if((!( dmflags & VSCP_DM_FLAG_CHECK_SUBZONE ))|(( dmflags & VSCP_DM_FLAG_CHECK_SUBZONE ) &&(vscp_imsg.data[ 2 ] == readEEPROM( VSCP_EEPROM_REGISTER + REG_TIMER1_SUBZONE +i*12))))
				{
				#ifdef PRINT_TIMER_EVENTS
				uart_puts( "doActionSetTimer check SUBzone MATCH or not necessary)" );
				#endif
				VSCP_USER_TIMER[select_timer] = arg;

				}
				
			}
				
}



#ifdef PRINT_CAN_EVENTS
///////////////////////////////////////////////////////////////////////////////
// doActionHelloWorld
//
void doActionHelloWorld( unsigned char dmflags, unsigned char arg )
{
uart_puts( "HelloWorld!\n" );
}
#endif




void vscp_outputevent(unsigned char board,unsigned int current,unsigned int previous)
{
	unsigned int change=0,i=0,j=1;
	uint16_t vscp_sendtimer=vscp_timer; 
	
	change = current^previous; //only changed bits are left
	#ifdef PRINT_IO_EVENTS
		uart_puts( "OUTPUT change detected!\n" );
   		char buf[40];
		sprintf(buf, "board/current/previous: %04x/%04x/%04x/",board, current, previous);
		uart_puts(buf);
	#endif
	if (board==0)
	{
		for (i=0; i<16; i++)
		{
			if ((change>>i)&0x01)
			{
				//wait at least 1 msec for next message to be sent
				//prevent overflow of bus or receiver
				//100�sec should be sufficient, but requires separate timer
				while (vscp_timer < vscp_sendtimer+2) ;
				if ((j & current) == j)
					{
						SendInformationEventExtended
							(7,(readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_ZONE + i ))
							,(readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_SUBZONE + i ))
							,0 , VSCP_CLASS1_INFORMATION, VSCP_TYPE_INFORMATION_OFF );
						// save when last event is sent out
						vscp_sendtimer = vscp_timer;
					}

				if (!(j & current)) 
					{
						SendInformationEventExtended
							(7,(readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_ZONE + i ))
							,(readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT1_SUBZONE + i ))
							,0 , VSCP_CLASS1_INFORMATION, VSCP_TYPE_INFORMATION_ON );
						// save when last event is sent out
						vscp_sendtimer = vscp_timer;
					}
			}
			j = j*2;
		}
	}
	else if (board==1)
	{
		for (i=0; i<16; i++)
		{
			//wait at least 1 msec for next message to be sent
			//prevent overflow of bus or receiver
			//100�sec should be sufficient, but requires separate timer
			while (vscp_timer < vscp_sendtimer+2) ;
			if ((change>>i)&0x01)
			{
				if ((j & current) == j)
				{
					SendInformationEventExtended
					(7,(readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT17_ZONE + i ))
					,(readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT17_SUBZONE + i ))
					,0 , VSCP_CLASS1_INFORMATION, VSCP_TYPE_INFORMATION_OFF );
					// save when last event is sent out
						vscp_sendtimer = vscp_timer;
				}
				if (!(j & current))
				{
					SendInformationEventExtended
					(7,(readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT17_ZONE + i ))
					,(readEEPROM( VSCP_EEPROM_REGISTER + REG_OUTPUT17_SUBZONE + i ))
					,0 , VSCP_CLASS1_INFORMATION, VSCP_TYPE_INFORMATION_ON );
					// save when last event is sent out
						vscp_sendtimer = vscp_timer;
				}
			}
			j = j*2;
		}
	}
}

//flip over portpin value --> 8 becomes 1, 7 becomes 2 ,...
//only for 1 bit 
unsigned char portflip(unsigned char old_val)
{
	unsigned char i,reverse =7;

	for (i = 0; i!= old_val; i++)
	{
		reverse--;
	}
    return(reverse); 
}

// flip over complete byte (lsb becomes msb)
unsigned char bitflip(unsigned char old_val) 
{ 
   unsigned char new_val = 0; 
   if (old_val & 0x01) new_val |= 0x80; 
   if (old_val & 0x02) new_val |= 0x40; 
   if (old_val & 0x04) new_val |= 0x20; 
   if (old_val & 0x08) new_val |= 0x10; 
   if (old_val & 0x10) new_val |= 0x08; 
   if (old_val & 0x20) new_val |= 0x04; 
   if (old_val & 0x40) new_val |= 0x02; 
   if (old_val & 0x80) new_val |= 0x01; 
   return(new_val); 
} 






/* original header******************************************************************
 * 	VSCP (Very Simple Control Protocol) 
 * 	http://www.vscp.org
 *
 * 	2006-04-21
 * 	akhe@eurosource.se
 *
 *  Copyright (C) 2006-2009 Ake Hedman, eurosource
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 * 
 *	This file is part of VSCP - Very Simple Control Protocol 	
 *	http://www.vscp.org
 *
 * ******************************************************************************
*/
