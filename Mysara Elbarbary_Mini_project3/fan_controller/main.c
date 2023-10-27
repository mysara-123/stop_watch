#include"std_types.h"
#include"ADC.h"
#include"lcd.h"
#include"LM35.h"
#include"DC_Motor.h"
#include <util/delay.h>


int main(void){
	ADC_ConfigType ADC_Config={INTERNAL_VOLTAGE,F_CPU_8 };
	ADC_init(&ADC_Config);
	LCD_init();
	LCD_displayString("FAN IS OFF");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp= ");
	DcMotor_init();
	uint8 temp;
	while(1)
	{
		_delay_ms(5);
		temp=LM35_getTemp();
		LCD_moveCursor(1,9);
		if(temp >=100)
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter('C');
		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
			LCD_displayCharacter('C');
		}

		if(temp <30)
		{
			LCD_moveCursor(0,0);
			LCD_displayString("FAN IS OFF");
			DcMotor_Rotate(STOP,0);
		}
		else if (temp<60)
		{
			LCD_moveCursor(0,0);
			LCD_displayString("FAN IS ON ");
			DcMotor_Rotate(CW,25);
		}
		else if (temp<90)
		{
			LCD_moveCursor(0,0);
			LCD_displayString("FAN IS ON ");
			DcMotor_Rotate(CW,50);
		}
		else if (temp<120)
		{
			LCD_moveCursor(0,0);
			LCD_displayString("FAN IS ON ");
			DcMotor_Rotate(CW,75);
		}
		else if (temp>=120 && temp<=150)
		{
			LCD_moveCursor(0,0);
			LCD_displayString("FAN IS ON ");
			DcMotor_Rotate(CW,100);
		}
	} 
	return 0;
}
