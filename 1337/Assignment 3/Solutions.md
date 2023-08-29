**Problem 1:**
A basic chain of if statements that checks for negative/positive. The test for zero assumes the user entered a number and not garbage. Will give false positives for zeroes because of this.

**Problem 2:**
Another chain that makes a basic comparison. Could have asked the user to enter two numbers at the same time, but this was easier.

**Problem 3:**
A simple for loop that counts up and multiples the user value with each cycle of the loop.

**Problem 4:**
The bulk of the code is testing whether or not the number is in the Fibonacci sequence. Obviously not my own original idea to use the perfect square of 5N^2+4. The rest just progresses through making a Fibonacci sequence.

**Problem 5:**
Uses a for loop to create a factorial. Using an unsigned long long because factorials get big real fucking fast. Values of greater than !65 are too fucking big for even that to handle which is why the if statement is there to catch it. Very sloppy.

**Problem 6:**
Uses the std::reverse function to flip a copy of the user's input. The additional for loop is only there to make sure something stupid like "Racecar: Not a palindrome" doesn't happen. 

**Problem 7:**
Uses the modulo operator to get the right most digit and adds it to the sum. That same digit is then removed from the number using division by 10 and the ensuing truncation. Feels like a dirty solution and I'm sure there is some problem that occurs from doing this. The if statement is there only to make the entered number positive to avoid fuckery.

**Problem 8:**
I'm assuming it's not cheating to use cstdlib. The solution seeds a random number, cuts into down to some single/double digit value with module 100, and throws a 1 one it to go from what I assume is 0-99 to 1-100. After that, it's a simple input check with a bonus guess counter for fun.

**Problem 9:**
Uses a for loop to scan for any spaces and breaks in those spaces. When a break occurs, it counts as a word. If it isn't a break, it continues seeing the same word until a new break occurs.

