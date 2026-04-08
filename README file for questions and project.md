# Mars-2026
for mars electronics 2026 tasks

This is Task 1 brief for all the questions,
QUE 1..
We used normal digitals pins as we needed ON/OFF functionality, All 3 leds are running at the same time with different delays and there time period of being ON/OFF
differs as per the question first being the most rapid and third being the least, had to look into millis() because as mentioned multifuction couldn't have been done
with delay()


QUE 2..
Here pwm pins are used to wire the rgb light as we need a continuous range of outputs from the rgb, then map was used to translate input from potentiometer to rgb
output, analog input of potentiometer gets converted to integers ranging 0 to 1023 using ADC


QUE 3..

