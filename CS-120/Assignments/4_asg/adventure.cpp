// Nigel Lee
// CS-120-08
// Assignment 3
// 09/22/2023 
 
  /*  A simple adventure game based on a haunted house.  
 */

/* Extra work:
    *Gave the player a collection of secrets to pick up rather than 1.
    *Added a simple boss fight at the end of the adventure game
    *Made the variables the player updates a class of traits so functions were cleaner. 
    *
 */

#include <iostream>
#include <string>

//Traits class for variables used in majority of rooms.
class Traits {
    public:
        int room = 1; //determines current room
        // 1.Bedroom 2.Ritual Room
        bool room_change[2] = {0, 0}; //Room visited status
        // 1.Living Room 2.Bedroom 3.Bathroom
        bool bandage_local[3] = {0, 0, 0,}; //Bandages collected status
        // 1.Necklace, 2.Knife, 3.Strange Skull, 4.Candle, 5.Dusty Tome
        bool secrets[5] = {0, 0, 0, 0, 0}; // Secrets found status
        int health = 100; // Player health
        int found = 0; // Total secrets found
        int bandage_quant = 0; // Bandages held
        
    
};
//Main Menu Function
void mainMenu(Traits& player) {
    std::cout << "Nun will Survive\n" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Quit" << std::endl;

    int menu_choice;
    std::cin >> menu_choice;

    switch(menu_choice) {
        case 1:
            player.room = 1;
            std::cout << "A glimpse of shadow catches your eye as you feel your limbs go numb." << std::endl;
            std::cout << "Panicking, you resist, but your body has abandoned you." << std::endl;
            std::cout << "As your eyes cloud in the fog of the night, the last image you bare witness"<< std::endl;
            std::cout << "to is a dark form lifting you into its embrace." << std::endl; 
            std::cout << "A searing pain hits your neck, and the world goes black." << std::endl;
            std::cout << "These are the only memories that come to you as regainconciousness." << std::endl;
            break;
        case 2:
            player.room = 0;
    }
}
//Display and Update Found Secrets Function
void displaySecrets(Traits& player){
    player.found += 1;
    std::cout << "You have found " << player.found << "/5 secrets" << std::endl;
    if(player.found == 5)
        std::cout << "You feel you're ready for escape" << std::endl;


}
//Room 1: Living Room Function.
void livingRoom_1(Traits& player) {
    int choice = 0;
    std::cout << "The room returns an oppressives stillness, broken only by the floorboards creeking beneath your feet. " << std::endl; 
    std::cout << "Dim candle-light from the coffee table offers you insight into the surroundings." << std::endl;
    while(player.room == 1) {
        std::cout << "You see this to be a living room." << std::endl;
        std::cout << "Of Interest:\n(1) Musty Couch\n(2) Front Door\n(3) Coffee Table\n" << std::endl;
        if(player.secrets[5]) {
            std::cout << "Exits Available:\n(4) Kitchen\n(5) Bookshelf Passage" << std::endl;
        } else{
            std::cout << "Exits Available:\n(4) Kitchen" << std::endl;
        }
        std::cin >> choice;


        switch(choice) {
            case 1:
                if(!player.bandage_local[1]) {
                    std::cout << "Musty Couch: Reaching into the cushion, you find an old bandage. Could be useful." << std::endl;
                    player.bandage_quant += 1;
                    player.bandage_local[1] = 1;
                } else {
                    std::cout << "You've already searched this" << std::endl;
                }
                break;
            case 2:
                std::cout << "Front Door: The knob turns yet the door remains shut. You won't be escaping through here." << std::endl;
                break;
            case 3:
                if(!player.secrets[4]) {
                    std::cout << "Coffee Table: You take one of the candles. You feel safer against the darkness ahead." << std::endl;
                    player.secrets[4] = 1;
                    displaySecrets(player);
                } else {
                    std::cout << "You already have a candle." << std::endl;
                }
                break;
            case 4:
                std::cout << "You pass through the archway at the back of the room." << std::endl;
                player.room = 2;
                break;
            case 5:
                if(player.secrets[5]) {
                    std::cout << "You slot the dusty tome into the bookshelf, revealing a hidden path. You wander inside." << std::endl;
                    player.room = 6;
                } else {
                    std::cout << "A voice whisphers to you, \"Try checking the bedroom.\"" << std::endl;
                }
                break;
        }
    }
}
//Room 2: Kitchen Room Function.
void kitchen_2(Traits& player) {
    int choice = 0;
    bool description = 0;
    std::cout << "The stench of iron fills your nostrils. The rotting, bloody clothes give it the appearance of a butchery. " << std::endl; 
    std::cout << "Buzzing fluorescents peak through the haze, lighting your path." << std::endl;
    while(player.room == 2) {
        std::cout << "You see this to be a kitchen." << std::endl;
        std::cout << "Of Interest:\n(1) Fridge\n(2) Drawer\n(3) Table\n" << std::endl;
        std::cout << "Exits Available:\n(4) Yard\n(5) Bedroom\n(6) Bathroom\n(7) Living Room" << std::endl;
        std::cin >> choice;


        switch(choice) {
            case 1:
                std::cout << "Fridge: Peaking in, what looks to be a dismembered hand catches your gaze. You quickly shut the fridge." << std::endl;
                break;
            case 2:
                if(!player.secrets[2]) {
                    std::cout << "Drawer: Amongst various tools you find a knife. You slip it into your pocket." << std::endl;
                    player.secrets[2] = 1;
                    displaySecrets(player);
                } else {
                    std::cout << "You've already searched here. Try something else." << std::endl;
                }
                break;
            case 3:
                std::cout << "Table: There are photos of people on the table." << std::endl;
                std::cout << "Glancing at one, writing on the bottom reads, \"7/10, not enough flavor.\"" << std::endl;
                break;
            case 4:
                std::cout << "You pass through the glass doors at the back of the room." << std::endl;
                player.room = 5;
                break;
            case 5:
                std::cout << "You enter the door at the right of the room. " << std::endl;
                player.room = 3;
                break;
            case 6:
                std::cout << "You enter the door at the left of the room." << std::endl;
                player.room = 4;
                break;
            case 7:
                std::cout << "You enter the archway at the front of the room." << std::endl;
                player.room = 1;
                break;
            default:
            choice = 0;
            std::cout << "You're trying to do what?" << std::endl;

        }
    }
}
// Room 3: Bedroom Function
void bedRoom_3(Traits& player) {
    int choice = 0;
    bool description = 0;
    if(!player.room_change[1]) {
        std::cout << "The sense of danger leaves you as you enter. Where you expect blood spatter and rot, warmth greets you." << std::endl;;
        player.room_change[1] = 1;
    } else {
        std::cout << "You have the feeling you're being watched. The cat clock hisses at you. You should leave." << std::endl;
    }
    while(player.room == 3) {
        std::cout << "You see this to be a bedroom." << std::endl;
        std::cout << "Of Interest:\n(1) Bed\n(2) Desk\n(3) Cat Clock\n" << std::endl;
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
        std::cin >> choice;


        switch(choice) {
            case 1:
                if(!player.bandage_local[2]) {
                    std::cout << "Bed: You pull back the covers and find a bandage. Could be useful" << std::endl;
                    player.bandage_quant += 1;
                    player.bandage_local[2] = 1;
                } else {
                    std::cout << "You've already searched this" << std::endl;
                }
                break;
            case 2:
                if(!player.secrets[5]) {
                    std::cout << "Desk: Atop the desk you find a dusty tome. You cannot decipher the words within." << std::endl;
                    player.secrets[5] = 1;
                    displaySecrets(player);

                } else {
                    std::cout << "You've already searched here. Try something else." << std::endl;
                }
            case 3:
                std::cout << "Cat Clock: Kind of cute. Why is this in here?" << std::endl;
                break;
            case 4:
                std::cout << "Kitchen: You exit the bedroom back through the door." << std::endl;
                player.room = 2;
                break;
            default:
            choice = 0;
            std::cout << "You're trying to do what?" << std::endl;

        }
    }
}
//Room 4: Bathroom Function
void bathRoom_4(Traits& player) {
    int choice = 0;
    bool description = 0;
    std::cout << "The walls before you are stained with rust. An ominous noise comes from the toilet " << std::endl; 
    while(player.room == 4) {
        std::cout << "You see this to be a bathroom." << std::endl;
        std::cout << "Of Interest:\n(1) Toilet\n(2) Bathtub" << std::endl;
        if(player.secrets[3]) {
            std::cout << "You place the skull on the alter, causing the floor beneath it to collapse, revealing a hole." << std::endl;
            std::cout << "Exits Available:\n(3) Kitchen\n(4) Hole" << std::endl;
        } else{
            std::cout << "Exits Available:\n(3) Kitchen" << std::endl;
        }

        std::cin >> choice;


        switch(choice) {
            case 1:
                if(player.secrets[3]) {
                    std::cout << "There used to be a toilet here. It's gone now" << std::endl;
                } else {
                    std::cout << "An empty alter sits above a toilet. You don't dare open the lid." << std::endl;
                }
                break;
            case 2:
                if(!player.bandage_local[3]) {
                    std::cout << "Bathtub: Inside of the rusted out tub you find a bandage. Could be useful." << std::endl;
                    player.bandage_quant += 1;
                    player.bandage_local[3] = 1;
                } else {
                    std::cout << "You've already searched this" << std::endl;
                }
                break;
            case 3:
                std::cout << "Kitchen: You exit the bathroom through the door." << std::endl;
                player.room = 2;
                break;
            case 4:
                if(player.found != 5) {
                    std::cout << "You hear whisphers,\"There are still secrets left to find!\" " << std::endl;
                    break;
                }
                std::cout << "You jump down the hole ready to face the dangers ahead." << std::endl;
                player.room = 7;
                break;
            
            default:
            choice = 0;
            std::cout << "You're trying to do what?" << std::endl;

        }
    }
}
//Room 5: Yard function
void backYard_5(Traits& player) {
    bool description = 0;
    int choice = 0;
    if(!player.room_change[2]) {
        std::cout << "Stepping outside, cool air washes across your face. The stars look beautiful tonight." << std::endl;;
        player.room_change[2] = 1;
    } else {
        std::cout << "The stars you once gazed on are gone. Blackness has blotted the sky" << std::endl;
    }
    while(player.room == 5) {
        std::cout << "You see this to be a backyard." << std::endl;
        std::cout << "Of Interest:\n(1) Dirt\n(2) Wall" << std::endl;
        std::cout << "Exits Available: (3) Kitchen" << std::endl;
        
        std::cin >> choice;


        switch(choice) {
            case 1:
                if(!player.secrets[3]) {
                std::cout << "Dirt: You dig in the dirt and find a Strange Skull. You wish you weren't holding this." << std::endl;
                player.secrets[3] = 1;
                displaySecrets(player);
                } else {
                    std::cout << "You've already searched here. Try something else." << std::endl;
                }
                break;
            case 2:
                std::cout << "Wall: The mossy walls are too high to climb. Escape would never be this easy" << std::endl;
                break;
            case 3:
                std::cout << "Kitchen: You return back through the patio doors." << std::endl;
                player.room = 2;
                break;

            default:
            choice = 0;
            std::cout << "You're trying to do what?" << std::endl;

        }
    }
}
// Room 6: Ritual Room Function
void ritualRoom_6(Traits& player) {
    int choice = 0;
    std::cout << "You step into a quaint study, bewildered by the runes etched into the wall and floor." << std::endl;
    std::cout << "A pentgram sits in the center of the floor. What manner of devilry was committed here?" << std::endl;
    while(player.room == 6) {
        std::cout << "You see this to be a ritual room." << std::endl;
        std::cout << "Of Interest:\n(1) Pentagram\n(2) Skeleton" << std::endl;
        std::cout << "Exits Available: (3) Living room" << std::endl;
        
        std::cin >> choice;


        switch(choice) {
            case 1:
                if(!player.secrets[1]) {
                std::cout << "In the center of the penagram sits a strange necklace. You put it on" << std::endl;
                player.secrets[1] = 1;
                displaySecrets(player);
                } else {
                    std::cout << "You've already searched here. Try something else." << std::endl;
                }
                break;
            case 2:
                std::cout << "Skeleton: A skeleton is chained in the corner. A note by his corpse reads: " << std::endl;
                std::cout << "Nun will escape. Get it? Cause I'm trapped and she's going to k-" << std:: endl;
                std::cout << "The note is cut short. What an amusing fella." << std::endl;
                break;
            case 3:
                std::cout << "Living Room: You exit back through the hidden passage." << std::endl;
                player.room = 1;
                break;
                break;

            default:
            choice = 0;
            std::cout << "You're trying to do what?" << std::endl;

        }
    }
}
//Room 7: Boss Room Function
void bossRoom_7(Traits& player) {
    int nun_health = 100;
    bool player_turn = 1;
    int combat_choice = 0;


    std::cout << "The rusted wire floor breaks your fall. Your candle lights up the room around you." << std::endl;
    std::cout << "Amidst wrought iron walls laiden with rust and blood, a woman stands before you." << std::endl;
    std::cout << "Appearing as an innocent nun, she greets you with open arms, promising safety." << std::endl;
    std::cout << "Your necklace glows, dispelling her illusion, revealing her to be a fanged,shadowy beast." << std::endl;
    std::cout << "Realizing this is the creature that abducted you, you lunge with your dagger" << std::endl;

    do {
        if(player_turn) {
            std::cout << "Health: " << player.health << std::endl;
            std::cout << "Bandages: " << player.bandage_quant << std::endl;
            std::cout << "Boss Health: " << nun_health << std::endl;
            std::cout << "Select an option:\n(1) Attack\n(2) Use Bandage" << std::endl;
            std::cin >> combat_choice;
            switch(combat_choice) {
                case 1:
                    std::cout << "Your dagger slashes the shadow beast. It screams in rage." << std::endl;
                    nun_health = nun_health - 20;
                    break;

                case 2:
                   if(player.health == 100) {
                        std::cout << "You're not injured" << std::endl;
                        break;
                    }else if(player.bandage_quant < 1) {
                        std::cout << "You're out of bandages." << std::endl;
                    } else {
                        player.health += std::min(100-player.health, 50);
                        player.bandage_quant -= 1;
                        std::cout << "You bandage your wounds" << std::endl;
                        break;
                    }
                default:
                    std::cout << "You waste a turn in confusion." << std::endl;        
            }
            player_turn = 0;
        } else {
            std::cout << "The shadow beast claws at your skin" << std::endl;
            player.health = player.health - 25;
            player_turn = 1;
        }

    } while(player.health > 0 && nun_health > 0);

    if(player.health <= 0) {
        std::cout << "You collapse, unable to keep fighting. The shadow beast has claimed another victim." << std::endl;

    } else if(nun_health <= 0) {
        std::cout << "You deal the final blow against the shadow beast. A great evil has been slain." << std::endl;
        std::cout << "On the beast you find the key to the front door, and make your escape.\n" << std::endl;
        std::cout << "Congratulations on beating Nun will Escape!" << std::endl;
    }
    player.room = 0;
} 


int main() {
    //create object with the class of traits
    Traits player;
    bool quit = 0;
    mainMenu(player);
    //Main game loop
    while(!quit) {
        switch(player.room) {
            case 0:
                quit = 1;
                break;
            case 1:
                livingRoom_1(player);
                break;
            case 2:
                kitchen_2(player);
                break;
            case 3:
                bedRoom_3(player);
                break;
            case 4:
                bathRoom_4(player);
                break;
            case 5:
                backYard_5(player);
                break;
            case 6:
                ritualRoom_6(player);
                break;
            case 7:
                bossRoom_7(player);
                break;
            
        }
    }
}





