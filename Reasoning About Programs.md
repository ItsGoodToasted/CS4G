1.  Given two numbers, 47 and 18, separate the values into their components. 47 is 40 and 7, 18 is 10 and 8. The sum of 40 and 10 is 50. The sum of 7 and 8 is 15. 50 and 15 are easily added together to make 65.
   
```
a = number1
b = number2
Sum1 = [a - (a % 10)] + [b - (b % 10)]
Sum2 = [(a % 10) + (b % 10)]
Sum = Sum1 + Sum2
Return Sum
```

2. **Ninja:**
   name (string):
   age (number):
   skills (string):
   clan (string):
   has.weapon (Boolean):
   
   **Pirate:** 
   name (string):
   age (number):
   skills (string):
   has.OnePiece (Boolean):
   has.weapon (Boolean):

3. **Bananas:**
   color (string):
   weight (number):
   ripe (Boolean):
   price (number)
   
   **Banana Trees:** 
   height (number):
   age (number):
   has.bananas (Boolean):
   location (string):
   
4. Let's say a computer understands a 4th century variation of Chinese you can't read. 
   
   Using an interpreted language, you can quickly write whatever it is you want, pass it off to the interpreter, and have it translate line-by-line what it is you want, when you want it. This interpreter understands perfectly well how to communicate what you wrote into a higher IQ language like 4th century Chinese, but since it's translating on the fly, it's slow. If it isn't storing the translation, it's going to need to re-translate every time you ask for something. If you want to pass your instructions to someone else, they need their own Chinese interpreter who yet again has to retranslate what you've done.
  
  Using a compiled language, you won't be given an instant translation. The translator will take its time converting your instructions in their entirety, regardless of if you need all of it right now. The end result however will be instructions any 4th century Chinese peasant could read. Nobody but you needed a translator in this case, and that translator only needed to do its job once.
  
  If all you need is a tool for organizing the psychological profiles of your friends, performance isn't really an issue, and you'd rather not go through the compiling process repeatedly just to bugfix. However, if you're developing a game based on stereotypes of your friends that you want them to play, it's probably better you have it compiled first. Your friends can't be trusted to install a Chinese translator and one of them is going to (rightfully) scream if the text-based RPG you made is causing their 2006 CPU to catch fire from all the fluid simulations.
  
5. All three are different forms of computer communication, but because humans are involved, not all are adequate.
   
   A computer thinks in flurry of on/off pulses that to a human may as well be complete garbage. The speed at which a computer can execute these makes any attempt at machine code communication with humans worthless. No human being is going to be able to read or write it in a way that is practical for modern computing.
   
   Using assembly, we can organize the pulses of a computer's brain into operations humans understand. It's not exactly human friendly, but the computer can understand well enough what is being asked meaning its efficient. The computer doesn't feel like you've handed it garbage.
   
   Organizing further, we can create a language which humans understand fairly well. To the computer, this language is trash. It could translate "mov" and "push" reasonably into not dumbass speak, but source code is just too much. With enough levels of translation it will eventually understand, but that's going to take time, effort, and a shitload of on/off pulses to work out.

6. 
```
Take both the current date and birthday in a day, month format:
	current date = (31, 5)
	birth date = (1, 21)
Assign each month a number of days : [31, 28, 31, 30, 31, 30, 31, 31, 30, 31 30, 31]
Count the months between the current day and birthday until they are equal, refreshing the months after 12:
	months until = (5, 6, 7, 8, 9, 10, 11, 12, 1)
Subtract the current day from the days in the first month of months until:
	days remaining = 31 - 31
Sum the days from the months inbetween the first and last months counted:
	(6, 7, 8, 9, 10, 11, 12) -> (30 + 31 + 31 + 30 + 31 + 30 + 31)
Add the days days remaining, summed month days, and days of birthday:
	(0) + (30 + 31 + 31 + 30 + 31 + 30 + 31) + (21)
Check for leap years:
	Is the current year or next year a leap year?
		If current, check if current date is after February
		If next, check if birthday is before February 29
		If either isn't true, add a day to the sum.
Return the sum: 235 days

```

7. For Fahrenheit:

```
Get Temperature and assign to Temp 
Celsius = (Temp * (9 / 5)) + 32
Return Celsius
```

   For Celsius:
   
```
Get Temperature and assign to Temp
Fahrenheit = (Temp - 32) * (5 / 9)
Return Fahrenheit
```
