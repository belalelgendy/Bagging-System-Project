/*
 * adc.c
 *
 *  Created on: 22 Mar 2020
 *      Author: HP
 */


#include "ADC.h"



void void_INITADC(void)
{
	Set_BIT(ADCSRA,ADEN);             //Enable ACD

	/*------------Select V_Referenece--------------------*/
#if(Vref ==1)
 {
	Set_BIT(ADMUX,REFS0);
 }

#elif (Vref==2)
	 {
	Set_BIT(ADMUX,REFS0);
	Set_BIT(ADMUX,REFS1);
	}
#endif
			/*-----------------Select PRESCALER------------------*/
#if (PRESCALER==1)
	{
	Set_BIT(ADCSRA,ADPS0);
	}
#elif (PRESCALER==2)
	{
	Set_BIT(ADCSRA,ADPS1);
	}
#elif  (PRESCALER==3)
	{
	Set_BIT(ADCSRA,ADPS0);
	Set_BIT(ADCSRA,ADPS1);
#elif  (PRESCALER==4)
	{
	Set_BIT(ADCSRA,ADPS2);
	}
#elif  (PRESCALER==5)
	{
	Set_BIT(ADCSRA,ADPS0);
	Set_BIT(ADCSRA,ADPS2);
	}
#elif  (PRESCALER==6)
	{
	Set_BIT(ADCSRA,ADPS1);
	Set_BIT(ADCSRA,ADPS2);
	}
#elif  (PRESCALER==7)
	{
	Set_BIT(ADCSRA,ADPS0);
	Set_BIT(ADCSRA,ADPS1);
	Set_BIT(ADCSRA,ADPS2);
	}
#endif
		/*--------------Enable Interrupt---------------*/
#if (Enable_Intrrupt == ON)
	{
	Set_BIT(ADCSRA,ADIE);
	}
#elif  (Enable_Intrrupt == OFF)
	}
	Clear_BIT(ADCSRA,ADIE);

#endif
}
/*--------------Start-Conversion---------------*/
u32 void_StartConversion_Readvoltage(void)
{
	u32 ADCOut,Vout;
	ADMUX=ADMUX|(no_channel & 0x0f);
	Set_BIT(ADCSRA,ADSC);               //Start-Conversion
	while ((ADCSRA &(1<<ADIF)) == 0); //End-Conversion
	ADCOut=ADCL|(ADCH<<8);              //Read-data after shifting ADCH
	Vout=(ADCOut*5)/1023;               //Vout=ADC_Reading*(Vref/step_size)

	return Vout;
}


/*------transducing to measuring value --------*/
u32 u32_ConvertAdcDate(void)
{
	u32 measuring_value;
	measuring_value=(Range_sensor*void_StartConversion_Readvoltage())/5;
	return measuring_value;
}
/*---------------------------------------------*/





