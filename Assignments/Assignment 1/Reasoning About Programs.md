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
   
   Using an interpreted language, you can quickly say whatever it is you want, pass it off to the interpreter, and have it translate sentence-by-sentence what it is you want, when you want it. This interpreter understands perfectly well how to communicate what you said into a higher IQ language like 4th century Chinese, but since it's translating on the fly, it's slow. If it isn't storing the translation, it's going to need to re-translate every time you ask for something. If you want to pass your instructions to someone else, they need their own Chinese interpreter who yet again has to retranslate what you've done.
  
  Using a compiled language, you won't be given an instant translation. It doesn't do sentence-by-sentence. The translator will take its time converting your words in their entirety, and if it's a good translator, will point out the critical mistakes you've made. While this process will take time, the end result will be instructions any 4th century Chinese peasant could read. Nobody but you needed a translator in this case, and that translator only needed to do its job once.
  
  If all you need is a tool for organizing the psychological profiles of your friends, performance isn't really an issue, and you'd rather not go through the compiling process repeatedly just to bugfix. However, if you're developing a game based on stereotypes of your friends that you want them to play, it's probably better you have it compiled first. Your friends can't be trusted to install a Chinese translator and one of them is going to (rightfully) scream if the text-based RPG you made is causing their 2006 CPU to catch fire from all the fluid simulations.
  
5. Machine code can best be thought of as a Morse code for computers. We can convey a substantial amount of information using only 8 blinking lamps, and even spell out enough "words" to form instructions. However, much like how we wouldn't want to read War and Peace in Morse Code, we wouldn't want to write complex software in machine code. A computer has no issue understanding thousands of these signals is seconds, but humans do.
   
   However, if we condense it and abstract it, we can create an assembly language that humans can understand. Using Morse code again as example, we can take instructions we'd commonly use like "... -. . . -.. .----. ... / .- -. -.. / ..-. . . -.. / -.--. ..-. --- .-. -- . .-. .-.. -.-- / -.-. .... ..- -.-. -.- .----. ... -.--.-" and say "SSaF : FC" instead. A human can recognize it as symbols for a set of instructions, and a computer can translate it back into instructions just fine. It's not perfect for human usability, but it's sufficient enough to deliver humanity Roller Coaster Tycoon. 
   
   Still, "SSaF : FC" isn't very human friendly. It's nice the computer can easily translate it, but humans aren't going to be making Crisis in it. If we abstract it further and condense more common instructions into simple words, the human end becomes a hell of a lot easier. We can use this to form a higher level language, and reach the source code most people today are familiar with. The computer will need instructions on how to de-condense the garbage you're feeding it, but that's what computers are for. It's up to the human to organize this easy to understand garbage into something useful.
  
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
