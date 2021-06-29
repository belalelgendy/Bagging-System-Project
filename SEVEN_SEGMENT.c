/*
 * SEVEN_SEGMENT.c
 *
 *  Created on: 16 Feb 2020
 *      Author: HP
 */


#include "SEVEN_SEGEMET.h"

void Seven_Segment_Mapping(u8 num)
{
	switch (num)
	{
	    case 0:
		   {
			   port=0x40;
			  break;
		   }
	     case 1:
	       {
				port=0x4f;
				break;
	       }
	     case 2:
			{
				port=0x24;
				break;
			}
	     case 3:
	     		{
	     			port=0x30;
	     			break;
	     		}
	     case 4:
	     		{
	     			port=0x19;
	     			break;
	     		}
	     case 5:
	     		{
	     			port=0x12;
	     			break;
	     		}
	     case 6:
	     		{
	     			port=0x02;
	     			break;
	     		}
	     case 7:
	     		{
	     			port=0x38;
	     			break;
	     		}
	     case 8:
	     		{
	     			port=0x00;
	     			break;
	     		}
	     case 9:
	     		{
	     			port=0x10;
	     			break;
	     		}
	     case 'A':
	     	    {
	     	     	port=0x08;
	     	     	break;
	     	    }
	     case 'B':
	    	     {
	    	     	port=0x00;
	    	     	break;
	    	     }
	     case 'C':
	    	     {
	    	     	 port=0x46;
	    	     	 break;
	    	     }
	     case 'F':
	    	      {
	    	     	  port=0x0E;
	    	     	  break;
	    	      }

	     default:
				   port=0x06;
					break;


	}
}
