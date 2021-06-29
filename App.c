/*
 * App.c
 *
 *  Created on: 12 Mar 2020
 *      Author: HP
 */

#include "Main_Library.h"
int main ()
{
	u8 flag1=0,flag2,flag;
	u8 flag_W=0;     // Weigher Fault
	u8 flag_M=0;     // Metal Fault
	Set_BIT(DDRC,2);Set_BIT(DDRC,3);Set_BIT(DDRC,7);
	Clear_BIT(DDRC,4);Clear_BIT(DDRC,5);Clear_BIT(DDRC,6);
	PORTC=0X70;
	Set_BIT(DDRD,7);
	Clear_BIT(PORTD,7);
/*-------------------Function init--------------------------------------*/
	void_LCD_INIT();
	void_INITADC();
	void_InitDCmotor();
	void_initSteppermotor();
	void_initservomotor();
	void_InitPhotosensor();
	void_InitMetalDetector();
	void_InitHeater();
	EEOpen();
/*----------------Startup-System--------------------------------------------*/
	LCD_String_xy(1,0,"SYS-BAGGING");
	LCD_String_xy(2,3,"Press-Start");
	while (GET_BIT(PINC,4)==1);
  	if (GET_BIT(PINC,4)==0)
	{
		voidClear_LCD();
		LCD_String_xy(2,4,"SYSTEM");
		LCD_String_xy(3,6,"Turn-ON");
		Set_BIT(PORTC,2);
		_delay_ms(150);
	}
	else
	{
		Clear_BIT(PORTC,2);
	}
    while (1)
    {
    	flag_M=0;flag_W=0;
	voidClear_LCD();
	LCD_String_xy(1,0,"SYS-Enable");
	LCD_String_xy(2,0,"--------------");
	LCD_String_xy(3,0,"SW2-Full-Bag");
	LCD_String_xy(4,0,"SW3-Single-Bag");
	while ((GET_BIT(PINC,5)==1) && (GET_BIT(PINC,6)==1));
	_delay_ms(100);
	if ((GET_BIT(PINC,5)==0) && ((GET_BIT(PINC,6)==1)))
	{

		_delay_ms(10);
		voidClear_LCD();
		LCD_String_xy(1,0,"Full-Bag");
		flag1=1;
	}
	else if ((GET_BIT(PINC,5)==1) && ((GET_BIT(PINC,6)==0)))
	{
		_delay_ms(10);
		voidClear_LCD();
		LCD_String_xy(1,0,"Single-Bag");
		flag2=1;
	}
	_delay_ms(100);
	/*-------------------------SYstem-Function----------------------------------*/

    /*------------------------------FFS-Fucnction---------------------------------*/
    		voidClear_LCD();
    		 LCD_String_xy(2,0,"Continuous Draw");
    		void_StartDCmotor('C');
    		void_Photosensor_detect();
    		_delay_ms(100);
    		void_StopDCmotor('C');
    		 _delay_ms(10);
    		 LCD_String_xy(3,0,"Length_Bag=   cm2");
    		 LCD_String_xy(4,4,"Detecting!!!");
    		 _delay_ms(100);
    		 LCD_String_xy(4,4,"Detected>>>>");
    		 _delay_ms(100);
    		 u8Diplay_NUMBERXY(3,11,EEReadByte(0x00));
    		 void_photosensor_notdetect();
    		 _delay_ms(100);
   /*------------------------Corner&Buttom-Sealing--------------------------------*/
    		   voidClear_LCD();
			  LCD_String_xy(2,2," HEATING SYS");
			  void_Photosensor_detect();
			/*       Corner Heating        */
			  LCD_String_xy(3,0,"Corner-TEMP=   C");
			  u8Diplay_NUMBERXY(3,13,EEReadByte(0x05));
			  void_HeaterStart();
			  LCD_String_xy(4,0,"CoolingTime=    s");
			  u8Diplay_NUMBERXY(4,13,EEReadByte(0x04));
			  void_HeaterStop();
			  /*       Bottom Heating        */
			  voidClear_LCD();
			  LCD_String_xy(2,2," HEATING SYS");
			  void_Photosensor_detect();
			  LCD_String_xy(3,0,"Bottom-TEMP=");
			  u8Diplay_NUMBERXY(3,13,EEReadByte(0x06));
			  void_HeaterStart();
			  LCD_String_xy(4,0,"CoolingTime=    s");
			  u8Diplay_NUMBERXY(4,13,EEReadByte(0x07));
			  void_HeaterStop();
			  void_photosensor_notdetect();
			  /*-------------CUTTER-------*/
			  voidClear_LCD();
			  void_Photosensor_detect();
			  LCD_String_xy(2,0,"Cutter>>Turn ON");
			  Set_BIT(PORTD,7);
			  _delay_ms(200);
			  Clear_BIT(PORTD,7);
			  void_photosensor_notdetect();
			  /*----------Gripper1---------------*/
			  voidClear_LCD();
			  LCD_String_xy(1,0,"Gripper-1 Move>>");
			  void_Grippermovement();
			 /*----------Gripper2---------------*/
			  LCD_String_xy(3,0,"Gripper-2 Move>>");
			  void_Grippermovement();
			  _delay_ms(100);
    /*-------------------------Weigher--------------------------- */
			  if (flag1==1)
			  {
				voidClear_LCD();
				void_Photosensor_detect();
				voidClear_LCD();
				LCD_String_xy(1,0,"Weigher-SYS");
				_delay_ms(100);
				void_motorPhase(3);
				LCD_String_xy(2,0,"Coarse flow=   o");
				u8Diplay_NUMBERXY(2,13,EEReadByte(0x02));
				_delay_ms(100);
				void_motorPhase(1);
				LCD_String_xy(3,0,"Fine flow==    o");
				u8Diplay_NUMBERXY(3,12,EEReadByte(0x03));
				_delay_ms(100);
				LCD_String_xy(4,0,"Door-close");
				void_Steppermotorstop();
				_delay_ms(100);
				void_photosensor_notdetect();
			  }
    		 /*----------Gripper3---------------*/
    		voidClear_LCD();
			LCD_String_xy(2,0,"Gripper-3 Move>>");
			void_Grippermovement();
   /*------------------------Top-Sealing--------------------------------*/
				  /*       Top Heating        */
				  voidClear_LCD();
				  LCD_String_xy(2,2," HEATING SYS");
				  void_Photosensor_detect();
				  LCD_String_xy(3,0,"TOP-TEMP=    C");
				  u8Diplay_NUMBERXY(3,10,EEReadByte(0x08));
				  void_HeaterStart();
				  LCD_String_xy(4,0,"CoolingTime=    s");
				  u8Diplay_NUMBERXY(4,13,EEReadByte(0x09));
				  void_HeaterStop();
				  void_photosensor_notdetect();
				  _delay_ms(100);
				  /**---------OutFed Conveyer--------*/
				  voidClear_LCD();
				  LCD_String_xy(2,0,"OutFed Conveyer>");
				  void_Photosensor_detect();
				  void_photosensor_notdetect();
				  _delay_ms(200);
		/*----------------------------Check Weigher--------------------------  */
				  if (flag1==1)
				  	 {
					voidClear_LCD();
					void_Photosensor_detect();
					LCD_String_xy(2,0,"Check-weigher>>");
					LCD_String_xy(3,0,"Bag Weight=");
					u8Diplay_NUMBERXY(3,11,u32_ConvertAdcDate());
					LCD_String_xy(3,13,"KG");
					_delay_ms(300);
					if (u32_ConvertAdcDate()>=25 && u32_ConvertAdcDate()<=26)
						{
							LCD_String_xy(4,0,"correct Weight");
							flag=1;
							_delay_ms(150);
						}
					else
						{
							flag_W=1;
						}
					void_photosensor_notdetect();
		   /*--------------------------Metal Detector-------------------------------------*/
					voidClear_LCD();
					void_Photosensor_detect();
					LCD_String_xy(2,0,"Metal-Detector>>");
					_delay_ms(200);
					if (void_MetalDetecting()==1)
						{
							flag_M=1;
						}
					else
						LCD_String_xy(3,0,"Metal-Detect:OK");
					void_photosensor_notdetect();
			/*------------------Rejection Section-----------------------*/
					_delay_ms(100);
					voidClear_LCD();
					void_Photosensor_detect();
					if (flag_W==1 && flag_M==0 )
					{
						LCD_String_xy(2,0,"incorrect Weight");
						_delay_ms(100);
						void_servomotor_Start(90);
						_delay_ms(200);
						void_servomotor_Stop();
						LCD_String_xy(3,0,"bag rejected");
						_delay_ms(100);
					}
					else if (flag_W==0 && flag_M==1 )
					{
						LCD_String_xy(2,0,"M-Detect-Error");
						_delay_ms(10);
						void_servomotor_Start(90);
						void_servomotor_Stop();
						LCD_String_xy(3,0,"bag rejected");
						_delay_ms(100);
					}
					else if (flag_M==1 && flag_W==1)
					{
						LCD_String_xy(2,0,"incorrect Weight");
						LCD_String_xy(3,0,"M-Detect-Error");
						_delay_ms(10);
						void_servomotor_Start(90);
						void_servomotor_Start(180);
						LCD_String_xy(4,0,"bag rejected");
						_delay_ms(100);
					}

					void_photosensor_notdetect();
			 }
    	/*******************************************************************/
    	         voidClear_LCD();
    	         if (flag2==1)
   			  {
    	        	 LCD_String_xy(1,0,"Single-Bag");
    	        	 LCD_String_xy(2,4,"OK");
    	        	 _delay_ms(150);
   			  }
    	         else
    	         {
    	    		LCD_String_xy(2,0,"FFS-Sequence");
    	    		LCD_String_xy(3,7,"Complete");
    	    	    _delay_ms(150);
    	         }


    	}
}

