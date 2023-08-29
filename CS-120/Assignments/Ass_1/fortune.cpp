/* The fortune Teller -
 * a simple program introducing some
 * fundamental programming concepts.
 */

/*
	[DELETE BEFORE SUBMISSION]
	ToDo:
	*Change formula for lucky number
	*add further inputs. You can make a quiz
	*Relationship predictor
	*A not simple calculator for the user to select
	*Consider storing art in seperate file
	*That's kind of a dick move though
	[DELETE BEFORE SUBMISSION]
*/
#include<iostream> // include a library

int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
    int disliked;  // create a variable to store the disliked number
	int age;  // create a variable to store the birthday
	int lucky;     // create a variable to store the lucky number
	// ------------- Get user input -------------------------
	std::cout << "Enter your favorite number (no decimals): ";  // output
	std::cin >> favorite;  		// user input
	std::cout << "Enter your age (no decimals): "; // output
	std::cin >> age; // user input
	std::cout << "Enter a number you don't like (no decimals): ";
	std::cin >> disliked;
	lucky = (favorite*disliked*age) % 10;
	std::cout << std::endl << "Your secret, lucky number is: " << lucky << std::endl;
	if(favorite == disliked){ // compares values of "favorite" and "disliked"	
		std::cout << R"(
			                 uuuuuuu
			             uu$$$$$$$$$$$uu
			          uu$$$$$$$$$$$$$$$$$uu
			         u$$$$$$$$$$$$$$$$$$$$$u
			        u$$$$$$$$$$$$$$$$$$$$$$$u
			       u$$$$$$$$$$$$$$$$$$$$$$$$$u
			       u$$$$$$$$$$$$$$$$$$$$$$$$$u
			       u$$$$$$"   "$$$"   "$$$$$$u
			       "$$$$"      u$u       $$$$"
			        $$$u       u$u       u$$$
			        $$$u      u$$$u      u$$$
			         "$$$$uu$$$   $$$uu$$$$"
			          "$$$$$$$"   "$$$$$$$"
			            u$$$$$$$u$$$$$$$u
			             u$"$"$"$"$"$"$u
			  uuu        $$u$ $ $ $ $u$$       uuu
			 u$$$$        $$$$$u$u$u$$$       u$$$$
			  $$$$$uu      "$$$$$$$$$"     uu$$$$$$
			u$$$$$$$$$$$uu    """""    uuuu$$$$$$$$$$
			$$$$"""$$$$$$$$$$uuu   uu$$$$$$$$$"""$$$"
			 """      ""$$$$$$$$$$$uu ""$"""
			           uuuu ""$$$$$$$$$$uuu
			  u$$$uuu$$$$$$$$$uu ""$$$$$$$$$$$uuu$$$
			  $$$$$$$$$$""""           ""$$$$$$$$$$$"
			   "$$$$$"                      ""$$$$""
			     $$$"                         $$$$"
		)" << "\n" << std::endl;
	
		std::cout << "You have angered the machine spirits." << std::endl;
	 
	} else { 

		if(lucky < 0){  // conditional, values less than 0
			std::cout << R"(
						__I__
					.-'"  .  "'-.
				  .'  / . ' . \  '.
				 /_.-..-..-..-..-._\ .---------------------------------.
						  #  _,,_   ( I hear it might rain people today )
						  #/`    `\ /'---------------------------------'
						  / / 6 6\ \
						  \/\  Y /\/       /\-/\
						  #/ `'U` \       /a a  \               _
						, (  \   | \     =\ Y  =/-~~~~~~-,_____/ )
						|\|\_/#  \_/       '^--'          ______/
						\/'.  \  /'\         \           /
						 \    /=\  /         ||  |---'\  \
						 /____)/____)       (_(__|   ((__|
			)" << "\n" << std::endl;
			std::cout << "Try to be less negative." << std::endl;
		}

		if(lucky >= 0 && lucky < 5){ // 0 to 4 inclusive
			std::cout << R"(
				    _---~~(~~-_.
				  _{        )   )
				,   ) -~~- ( ,-' )_
				(  `-,_..`., )-- '_,)
				( ` _)  (  -~( -_ `,  }
				(_-  _  ~_-~~~~`,  ,' )
				 `~ -^(    __;-,((()))
				       ~~~~ {_ -_(())
				        \  }
				        { }
			)" << "\n" << std::endl;
			std::cout << "Think bigger!" << std::endl;
		}

		if(lucky >= 5 && lucky < 9){ // 5 to 8 inclusive
			std::cout << R"(
				.=====================================================.
				||                                                   ||
				||   _       _--""--_                                ||
				||     " --""   |    |   .--.           |    ||      ||
				||   " . _|     |    |  |    |          |    ||      ||
				||   _    |  _--""--_|  |----| |.-  .-i |.-. ||      ||
				||     " --""   |    |  |    | |   |  | |  |         ||
				||   " . _|     |    |  |    | |    `-( |  | ()      ||
				||   _    |  _--""--_|             |  |              ||
				||     " --""                      `--'              ||
				||                                                   ||
				`=====================================================`					
			)"<< std::endl;
			std::cout << "Today you should embrace technology." << std::endl;
		}
		if(lucky == 9){ // exactly 9
			std::cout << R"(
				.'`'.'`'.
			.''.`.  :  .`.''.
			'.    '. .'    .'
			.```  .' '.  ```.
			'..',`  :  `,'..'
				`-'`'-`))
						((    
						 \|
			)" << "\n" << std::endl;
			std::cout << "Today is your lucky day!" << std::endl;
		}
	}
	// ---------- Code to help the program exit "gracefully" -----
	std::cin.ignore();
 	std::cout << "Press enter to quit." << std::endl;
	std::cin.ignore();
	return 0;
}