// Preprocessor Directive
#include <iostream> 
#include <ctime>

void PrintIntroduction( int Difficulty)
{
    std::cout << "\n\nExploring the ancient ruins of anubis in egypt on level " << Difficulty; 
    std::cout << " you have touched the forbidden treasure! The room is quickly filling up with sand! \nYou need to enter a code to open the large golden door in order to escape...\n\n";
}
bool PlayGame(int Difficulty)
{
     PrintIntroduction(Difficulty);
    
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Expression Statements, Prints sum and product to terminal
    std::cout << "* There are 3 numbers in the code";
    std::cout << "\n* The codes add up to: " << CodeSum;
    std::cout << "\n* The code returns a product of: " << CodeProduct <<std::endl;
   
    // Store Player Guess
   int GuessA, GuessB, GuessC;
   std::cin >> GuessA >> GuessB >> GuessC;

   int GuessSum = GuessA + GuessB + GuessC;
   int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
   if (GuessSum == CodeSum && GuessProduct == CodeProduct)
   {
       std::cout << "\nThe locks clink and clank! You push the door with all your might and it opens...you made it out alive to the next level";
       return true;
   } 
   else 
   {
       std::cout << "\nOh no! That code was incorrect the door locks and the room goes dark...you died but Anubis favors you so try again!";
       return false;
   }

}

int main() 
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)
    {
      bool bLevelComplete = PlayGame(LevelDifficulty); 
      std::cin.clear();
      std::cin.ignore(); 

      if (bLevelComplete)
      {
        ++ LevelDifficulty;
      }
      
    }
    std::cout << "\n\nLight shines upon your face. Anubis smiles another lucky enough to leave alive. You are carried out into the desert and proped on your camel and onward to the journey home!";
    return 0;
}

// complie with cl lotf.cpp then run lotf, right click to change all occurences of names