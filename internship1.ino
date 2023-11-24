#define lm35_pin A0
void ms_delay (unsigned int time);
void setup()
{
Serial.begin(9600);
pinMode(LED_BUILTIN,OUTPUT);
}
void ms_delay(unsigned int time)
{
unsigned int i;
unsigned int j;
for(i=0;i<time;i++)
{
  for(j=0;j<165;j++);
}
}
void loop()
{
int temp_adc_val;
float adc_eqv_voltage;
float temp_val;
temp_adc_val=analogRead(lm35_pin); //Read temperature from lm35 adc value
adc_eqv_voltage=(temp_adc_val * 0.00488); //Convert adc value to equivalent voltage by multiplying with (5.0/1024)
temp_val=(adc_eqv_voltage * 100);// Convert voltage into temperature (lm35 gives op as 10mV/degree Celsius)
Serial.println(temp_val);
if(temp_val<30)
{
digitalWrite(LED_BUILTIN, HIGH);
ms_delay(250);
digitalWrite(LED_BUILTIN, LOW);
ms_delay(250);
}
else
{
digitalWrite(LED_BUILTIN, HIGH);
ms_delay(500);
digitalWrite(LED_BUILTIN, LOW);
ms_delay(500);
}
}