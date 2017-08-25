#define redPin 7
#define greenPin 6
#define bluePin 5

void setup() 
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() 
{
  setColor(250, 0, 0); // Red Color
  delay(500);
  setColor(0, 255, 0); // Green Color
  delay(500);
  setColor(0, 0, 255); // Blue Color
  delay(500);
  setColor(255, 255, 255); // White Color
  delay(500);
  setColor(170, 0, 255); // Purple Color
  delay(500);
  setColor(128,128,0); // Purple Color
  delay(500);
}

void setColor(int redValue, int greenValue, int blueValue) 
{
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

/* Cores (R,G,B)
  
  Black	#000000	(0,0,0)
 	White	#FFFFFF	(255,255,255)
 	Red	#FF0000	(255,0,0)
 	Lime	#00FF00	(0,255,0)
 	Blue	#0000FF	(0,0,255)
 	Yellow	#FFFF00	(255,255,0)
 	Silver	#C0C0C0	(192,192,192)
 	Gray	#808080	(128,128,128)
 	Maroon	#800000	(128,0,0)
 	Olive	#808000	(128,128,0)
 	Green	#008000	(0,128,0)
 	Purple	#800080	(128,0,128)
 	Teal	#008080	(0,128,128)
 	Navy	#000080	(0,0,128)
 	Cyan    #00FFFF (0,255,255)
 	Magenta #FF00FF (255,0,255)
 
 */