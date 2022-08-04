//File Name: PokerGame
//Author: Raymond Anggono
//Email Address: anggonoraymond@gmail.com
//Assignment Number: 24
//Description: Poker Game With Maximum of 4 Players.
//Last Changed: June 6 ,2019

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const string suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const string value[ 13 ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

void PlayersPlaying(int& NumberOfPlayer);
// Take number of players that is playing
// Ask user to input how many player is playing
// Return the input for the number of players playing

void DealCards(int board[][2],int Player1[][2],int Player2[][2],int Player3[][2],int Player4[][2], int deck[][13],int NumberOfPlayer);
// Takes 6 2D array and the number of players playing as parameters
// 4 of the 2D array is use to hold the players 2 card
// 1 of the 2D array is to hold the board's 5 card
// And another 2D array is the deck of the card
// This function will deal cards to player and the board according to the number stored in the deck

void ShuffleDeck(int deck[][13]);
// Takes a 2D array to hold the cards
// The array is a 4x13 array
// The number 0-12 is to represent the card numbers
// While the number 0-3 is to hold the card suit
// The numbers stored in the array is to represent the order of the card being dealt

void showBoard(int board[][2], int turn);
// Takes the board and the turn as a parameter
// It will output the cards in the board according to the turn

void showHand(int Player1[][2],int Player2[][2],int Player3[][2],int Player4[][2],int CurrentPlayer);
// Takes the 4 2D array that holds the players cards and the player number that the hand wants  to be shown
// It will output the cards of that specific player

void GamePlay(int board[][2],int Player1[][2],int Player2[][2],int Player3[][2],int Player4[][2],int NumberOfPlayer,bool PlayersPlaying[4],int Money[4],int& pot,int turn);
// Takes 5 2D array,2 1D array , the pot money, the turn of the round and the number of players playing as parameters
// 4 of the 2D array is use to hold the players 2 card
// 1 of the 2D array is to hold the board's 5 card
// This function is to keep track of the game's progress and ask user on what they want to do for their turns
// it will return the pot money out of the function

void Sort(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will sort the cards in ascending order

void InsertHandAndBoard(int board[][2],int Player[][2],int hand[][2]);
// Takes 3 2D array as parameters
// It will store both the board cards and the player cards to the hand array

int EvaluateHand(int player[][2],int board[][2]);
// Takes a player and the board array as parameters
// It will check the players card value according to the board
// It will return the value of the player's card

bool CheckForStraight(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains a straight
// If yes return true, if not return false

bool CheckForFlush(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains a flush
// If yes return true, if not return false

bool CheckForPair(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains a pair
// If yes return true, if not return false

bool CheckForTwoPair(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains 2 pair
// If yes return true, if not return false

bool CheckForThreeOfAKind(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains three of the same card
// If yes return true, if not return false

bool CheckForFourOfAKind(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains four of the same card
// If yes return true, if not return false

bool CheckForRoyalFlush(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains a  10 J Q K A all with the same suit
// If yes return true, if not return false

bool CheckForHighStraight(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains 10 J Q K A
// If yes return true, if not return false

bool CheckForStraightFlush(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains a straight and the straight cards all have the same suit
// If yes return true, if not return false

bool CheckForFullHouse(int hand[][2]);
// Takes a 2D array that is a user hand and the baord cards as parameters
// It will check if the hand contains a three of a kind and a pair
// If yes return true, if not return false

void FindWinner(int board[][2],int Player1[][2],int Player2[][2],int Player3[][2],int Player4[][2],bool PlayersPlaying[4],int pot,int Money[4]);
// Takes 5 2D array, 2 1D array and the pot money as parameters
// 4 of the 2D array is use to hold the players 2 card
// 1 of the 2D array is to hold the board's 5 card and the other is to check if they are still playing
// It will check each players card and compare their cards
// The one with the best cards will get the pot money

void BuyIn(int PlayersMoney[],int NumberOfPlayer);
// Takes a 1D array to hold the players money and the number of player playing
// It will ask how much the player wants to play
// The input will be added to the array

char GameEnds(int Money[4],int NumberOfPlayer);
// Takes a 1D array to hold the players money and the number of player playing
// Check if there is only 1 player with money left
// If only one player left return N
// If not return Y

int FindThree(int board[][2], int player[][2]);
// Takes the board and 1 player array as parameters
// This is to find the player's three of a kind card value
// It will return the value of the card that is three of a kind

int FindPair(int board[][2], int player[][2]);
// Takes the board and 1 player array as parameters
// This is to find the player's pair card value
// It will return the value of the card that is a pair

int FindFour(int board[][2], int player[][2]);
// Takes the board and 1 player array as parameters
// This is to find the player's four of a kind card value
// It will return the value of the card that is four of a kind

int FindStraight(int hand[][2]);
// Takes the board and 1 player array as parameters
// This is to find the player's straight
// It will return the the card value highest straight (Ex: Straight to 9, it will return 9)

void FindDoublePair(int board[][2], int player[][2],int& Pair1,int& Pair2);
// Takes the board and 1 player array and the player's first and second pair as parameters
// This is to find the player's double card value
// It will return pair1 and pair2

int FindTheBetterHand(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2,int CardValue);
// Take 3 2D array, the players card value and the player numbers that the card is being comapred
// It will check whose hands is better
// Return the player's number with a better hand
// If it is tied, return -1

int CompareHands(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2,int Player1Card,int Player2Card);
// Take 3 2D array, the players card value and the player numbers that the card is being compared and both players card value
// It will compare both players hand and check whose card is better
// If the card value is the same it will then find whose hand is better
// Return the players number with a better hand
// Their cards may be equal so return -1

int BestHighCard(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2);
// Take 3 2D array, the players card value and the player numbers that the card is being compared
// This will compare the players highest cards until one of their card is higher
// It will return the player number with the higher card
// if equal return -1

void InsertCardCounter(int board[][2],int PlayerHand[][2],int CardCounter[13]);
// This will take the board cards and a player hands card and another 1D array to hold both cards
// This function is to insert the board and player hand cards to the card counter
// This is to check their cards have how many aces deuces threes and so on

int BestPair(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2);
// Take 3 2D array, the players card value and the player numbers that the card is being compared
// This will compare the players pair
// If the pair is the same, it will then check the players highest cards
// It will return the player number with the higher pair or higher card
// if equal return -1

int BestDoublePair(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2);
// Take 3 2D array, the players card value and the player numbers that the card is being compared
// This will compare the players two pairs
// Player with a pair that is higherr than the other pairs is the winner
// It will return the player number with the highest pair
// If both pair is equal, it will then check their highest card
// if equal return -1

int BestThreeOfAKind(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2);
// Take 3 2D array, the players card value and the player numbers that the card is being compared
// This will compare the players triples
// If the triples is the same, it will then check the players highest cards
// It will return the player number with the higher triples and higher card
// if equal return -1

int BestFourOfAKind(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2);
// Take 3 2D array, the players card value and the player numbers that the card is being compared
// This will compare the players quads
// If the quads is the same, it will then check the players highest cards
// It will return the player number with the quads and higher card
// if equal return -1

int BestStraight(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2);
// Take 3 2D array, the players card value and the player numbers that the card is being compared
// This will compare the players straight
// It will return the player number with the higher straight
// if equal return -1

int BestStraightFlush(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2);
// Take 3 2D array, the players card value and the player numbers that the card is being compared
// This will compare the players straight flush
// It will return the player number with the higher straight flush
// if equal return -1

int FindStraightFlush(int hand[][2]);
// Takes a 2D array that consist of the players hand and the board
// It will find the player's straight flush
// It will then return the straight's highest card value

int BestFlush(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2);
// Take 3 2D array, the players card value and the player numbers that the card is being compared
// This will compare the players flush
// It will return the player number with the higher flush
// if equal return -1

int BestFullHouse(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2);
// Take 3 2D array, the players card value and the player numbers that the card is being compared
// This will compare the players full house
// It will return the player number with the higher full house
// if equal return -1

void InitializePlayersPlaying(bool PlayersPlaying[4],int NumberOfPlayers);
// Takes a array that will keep track the players that is still playing and the number of players playing
// It will then initialize the players playing to true from 0-Number of players
// And the rest will be false

bool CheckIfBetCanContinue(int Money[4],bool PlayersPlaying[4]);
// Take the money array and the players that are still playing array as parameters
// It will check if there is more than 1 player left that is still playing and has money
// If true return true
// If only 1 player remaining return false

void OutputWinnerOfTheRound(int Pot,int Money[4],int BetterCard,int PlayersTied,int FirstPlayerTied, int SecondPlayerTied,int ThirdPlayerTied);
// Take the pot, Money array, Better Card , Number of players tied, The first,second and third player number that ties as parameters
// It will output the winner of the round and add the pot money accordingly

char PlayAgain();
// Ask user if they want to play another game of poker
// it will return the user's response

int main()
{
    char AnotherGame('Y');
    while(toupper(AnotherGame) == 'Y')
    {
        char repeat('Y');
        int No_Player;
        int Money[4] = {0};

        PlayersPlaying(No_Player);
        BuyIn(Money,No_Player);

        while(repeat =='Y')
        {
            int board[5][2];
            int Player1[2][2],Player2[2][2],Player3[2][2],Player4[2][2];
            int deck[4][13] = {0};
            bool PlayersStillPlaying[4] = {false,false,false,false};
            int pot(0);

            srand(time(0));
            InitializePlayersPlaying(PlayersStillPlaying,No_Player);
            ShuffleDeck(deck);
            DealCards(board,Player1,Player2,Player3,Player4,deck,No_Player);

            for(int i=0; i<4;i++)
            {
                GamePlay(board,Player1,Player2,Player3,Player4,No_Player,PlayersStillPlaying,Money,pot,i);
            }

            FindWinner(board,Player1,Player2,Player3,Player4,PlayersStillPlaying,pot,Money);
            repeat = GameEnds(Money,No_Player);

        }

        AnotherGame = PlayAgain() ;
    }
    return 0;
}

char PlayAgain()
{
    char answer;

    cout << "\n Do you want to play another game? (press y to repeat)\n";
    cin >> answer;

    return answer;
}
void InitializePlayersPlaying(bool PlayersPlaying[4],int NumberOfPlayers)
{
    for(int i=0; i<NumberOfPlayers;i++)
    {
        PlayersPlaying[i] = true;
    }
}
void PlayersPlaying(int& NumberOfPlayer)
{
    cout << "How many players are playing?(There is a maximum of 4 players and minimum of 2 players)\n";
    cin >> NumberOfPlayer;
    
    while(NumberOfPlayer<2 || NumberOfPlayer>4)
    {
        cout << "Invalid input of players. Please input another number.\n";
        cin >> NumberOfPlayer;
    }
}
void BuyIn(int PlayersMoney[],int NumberOfPlayer)
{
    int money;

    cout << "How much do you want each player starting buy in?\n";
    cin >> money;

    while(money<100 || money >1000)
    {
        cout << "Invalid input. Minimum buy in is 100 and maximum is 1000.\n";
        cin >> money;
    }

    for(int i=0; i<NumberOfPlayer;i++)
    {
        PlayersMoney[i] += money;
    }
}
void ShuffleDeck(int deck[][13])
{
    int row;
    int column;
    
    for ( int card = 1; card <= 52; card++ ) // card represents the number of order the card is going to be dealed
    {
        do
        {
            row = rand() % 4;                // row is to represent the card's suit
            column = rand() % 13;            // column is to represent the card value
        } while( deck[ row ][ column ] != 0 );
        
        
        deck[ row ][ column ] = card;
    }
}
void DealCards(int board[][2],int Player1[][2],int Player2[][2],int Player3[][2],int Player4[][2], int deck[][13],int NumberOfPlayer)
{
    int CardToBeDealed(1); // this is to keep track the next card going to be dealed
    
    for(int turn = 1; turn <= 2; turn++)
    {
        for(int r = 0; r < 4; r++)
        {
            for(int c = 0; c < 13; c++)
            {
                if(deck[r][c] == CardToBeDealed)
                {
                    Player1[turn-1][0] = c;
                    Player1[turn-1][1] = r;
                }
            }
        }
        
        CardToBeDealed++;
        
        for(int r = 0; r < 4; r++)
        {
            for(int c = 0; c < 13; c++)
            {
                if(deck[r][c] == CardToBeDealed)
                {
                    Player2[turn-1][0] = c;
                    Player2[turn-1][1] = r;
                }
            }
        }
        
        CardToBeDealed++;
        
        if(NumberOfPlayer>2)
        {
            for(int r = 0; r < 4; r++)
            {
                for(int c = 0; c < 13; c++)
                {
                    if(deck[r][c] == CardToBeDealed)
                    {
                        Player3[turn-1][0] = c;
                        Player3[turn-1][1] = r;
                    }
                }
            }
            CardToBeDealed++;
        }
        
        if(NumberOfPlayer>3)
        {
            for(int r = 0; r < 4; r++)
            {
                for(int c = 0; c < 13; c++)
                {
                    if(deck[r][c] == CardToBeDealed)
                    {
                        Player4[turn-1][0] = c;
                        Player4[turn-1][1] = r;
                    }
                }
            }
            CardToBeDealed++;
        }
    }
    
    for(int card = 1; card <= 5; card++)
    {
        if((card == 1) || (card == 5) || (card == 8)) // the burn cards will not be dealed
        {
            CardToBeDealed++;
        }
        
        for(int r = 0; r < 4; r++)
        {
            for(int c = 0; c < 13; c++)
            {
                if(deck[r][c] == CardToBeDealed)
                {
                    board[card - 1][0] = c;
                    board[card - 1][1] = r;
                }
            }
        }
        
        CardToBeDealed++;
        
    }
}
void showHand(int Player1[][2],int Player2[][2],int Player3[][2],int Player4[][2],int CurrentPlayer)
{
    int hand[2][2];

    if(CurrentPlayer == 0)
    {
        for ( int i = 0; i <= 1; i++ )
        {
            hand[i][0] = Player1[i][0];
            hand[i][1] = Player1[i][1];
        }
    }
    else if(CurrentPlayer == 1)
    {
        for ( int i = 0; i <= 1; i++ )
        {
            hand[i][0] = Player2[i][0];
            hand[i][1] = Player2[i][1];
        }
    }
    else if(CurrentPlayer == 2)
    {
        for ( int i = 0; i <= 1; i++ )
        {
            hand[i][0] = Player3[i][0];
            hand[i][1] = Player3[i][1];
        }
    }
    else
    {
        for ( int i = 0; i <= 1; i++ )
        {
            hand[i][0] = Player4[i][0];
            hand[i][1] = Player4[i][1];
        }
    }

    for ( int card = 1; card <= 2; card++ )
    {
        cout << value[ hand[card-1][0] ] << " of " << suit[ hand[card-1][1] ] << endl;
    }
}
void showBoard(int board[][2], int turn)
{
    if(turn == 1)
    {
        cout << "\nThe flop is:\n";
        for ( int card = 1; card <= 3; card++ )
        {
            cout << value[ board[card-1][0] ] << " of " << suit[ board[card-1][1] ] << endl;
        }
    }

    if(turn == 2)
    {
        cout << "The flop was:\n";
        for ( int card = 1; card <= 4; card++ )
        {
            if(card == 4)
                cout << "The turn card is :\n";
            cout  << value[ board[card-1][0] ] << " of " << suit[ board[card-1][1] ] << endl;
        }
    }

    if(turn == 3)
    {
        cout << "The flop and the turn was:\n";
        for ( int card = 1; card <= 5; card++ )
        {
            if(card == 5)
                cout << "The river card is :\n";
            cout << value[ board[card-1][0] ] << " of "  << suit[ board[card-1][1] ] << endl;
        }
    }

}
void GamePlay(int board[][2],int Player1[][2],int Player2[][2],int Player3[][2],int Player4[][2],int NumberOfPlayer,bool PlayersPlaying[4],int Money[4],int& pot,int turn)
{
    int answer,BetAmount,RaiseAmount;
    int PlayerBet[4] = {0}; // This is to hold how much money each player has put in this round
    bool RepeatBet(false);
    int BetCounter(0);
    int PlayerRaise;
    int PlayersTurn;
    char ready;

    for(int i=0; i<NumberOfPlayer; i++)
    {
        if(CheckIfBetCanContinue(Money,PlayersPlaying))
        {

            if(PlayersPlaying[i] && Money[i] >0)
            {
                PlayersTurn = i+1;

                if(PlayersTurn == NumberOfPlayer +1)
                    PlayersTurn=1;

                showBoard(board,turn);
                cout << "\nIts player " << PlayersTurn << "'s turn.\n";
                cout << "Pass the device. And press any key to continue.\n";
                cin >> ready;

                cout << "Your card is : \n";
                showHand(Player1,Player2,Player3,Player4,i);
                cout << "\nYou have $" << Money[i] << " worth of chips right now.\n";
                cout << "1. Check\n";
                cout << "2. Bet\n";
                cout << "3. Fold\n";
                cout << "What do you want to do?\n";

                cin >> answer;

                while(answer<1 || answer>3)
                {
                    cout << "Invalid Input. Please input again.\n";
                    cin >> answer;
                }

                if(answer == 1)
                    system("cls");

                if(answer == 2)
                {
                    RepeatBet = true;
                    PlayerRaise = i+1;

                    cout << "How much do you want to bet?\n";
                    cin >> BetAmount;

                    while(BetAmount < 0 || BetAmount > Money[i] )
                    {
                        cout << "Invalid amount. Please input again.\n";
                        cin >> BetAmount;
                    }

                    Money[i] -= BetAmount;
                    PlayerBet[i] += BetAmount;
                    pot+=BetAmount;

                    cout << "You bet $" << BetAmount << " and have $" << Money[i] << "left.\n";
                    system("cls");

                    int j = i+1;

                    while(RepeatBet)
                    {
                        if(j == NumberOfPlayer)
                            j = 0;

                        if(PlayersPlaying[j] && Money[j] >0)
                        {
                            PlayersTurn = j+1;

                            if(PlayersTurn== NumberOfPlayer +1)
                                PlayersTurn=1;

                            showBoard(board,turn);
                            cout << "\nIts player " <<PlayersTurn << "'s turn.\n";

                            cout << "Pass the device. And press any key to continue.\n";
                            cin >> ready;

                            cout << "Your card is : \n";
                            showHand(Player1,Player2,Player3,Player4,j);
                            cout << "Player " << PlayerRaise << "has raised an amount of $" << BetAmount << endl;
                            cout << "\nYou have $" << Money[j] << " worth of chips right now.\n";
                            cout << "1. Call\n";
                            cout << "2. Raise\n";
                            cout << "3. Fold\n";
                            cout << "What do you want to do?\n";
                            cin >> answer;

                            while(answer<1 || answer>3)
                            {
                                cout << "Invalid Input. Please input again.\n";
                                cin >> answer;
                            }

                            if(answer == 1)
                            {
                                Money[j] -= BetAmount;
                                PlayerBet[j] += BetAmount;
                                pot+=BetAmount;
                            }

                            else if(answer == 2)
                            {
                                BetCounter = -1;
                                PlayerRaise = j+1;

                                cout << "How much do you want to raise?\n";
                                cin >> RaiseAmount;

                                while(RaiseAmount < BetAmount || RaiseAmount > Money[i] )
                                {
                                    cout << "Invalid amount. Please input again.\n";
                                    cin >> RaiseAmount;
                                }

                                Money[j] = Money[j] - (RaiseAmount - PlayerBet[j]);
                                pot += (RaiseAmount-PlayerBet[j]);
                            }

                            else if(answer == 3)
                                PlayersPlaying[j] = false;

                            system("cls");
                        }

                        j++;
                        BetCounter++;

                        if(BetCounter == NumberOfPlayer - 1)
                            RepeatBet = false;
                    }
                    break;
                }

                else if(answer == 3)
                    PlayersPlaying[i] = false;
            }
        }
    }
}
bool CheckIfBetCanContinue(int Money[4],bool PlayersPlaying[4])
{
    int NumberOfPlayersInTheRound(0);

    for(int i=0;i<4;i++)
    {
        if(PlayersPlaying[i])
        {
            if(Money[i] > 0)
                NumberOfPlayersInTheRound++;
        }
    }

    if(NumberOfPlayersInTheRound > 1)
        return true;

    return false;
}
void Sort(int hand[][2])
{
    int size = 7;
    int temp;

    for(int j = size - 1; j > 0; j--)
    {
        for(int i = 0; i < j; i++)
        {
            if(hand[i][0] > hand[i+1][0])
            {
                temp = hand[i][0];
                hand[i][0] = hand[i+1][0];
                hand[i+1][0] = temp;

                temp = hand[i][1];
                hand[i][1] = hand[i+1][1];
                hand[i+1][1] = temp;
            }
        }
    }
}
void InsertHandAndBoard(int Board[][2],int Player[][2],int hand[][2])
{
    for(int j = 0; j<7; j++)
    {
        if(j<5)
        {
            hand[j][0] = Board[j][0];
            hand[j][1] = Board[j][1];
        }
        else
        {
            hand[j][0] = Player[j-5][0];
            hand[j][1] = Player[j-5][1];
        }
    }

    Sort(hand);
}
void InsertCardCounter(int hand[][2],int CardCounter[13])
{
    for(int i=0; i<7;i++)
    {
        CardCounter[hand[i][0]]++;
    }
}
int EvaluateHand(int player[][2],int board[][2])
{
    int hand[7][2];

    InsertHandAndBoard(board,player,hand);

    if(CheckForRoyalFlush(hand))
        return 9;
    else if(CheckForStraightFlush(hand))
        return 8;
    else if(CheckForFourOfAKind(hand))
        return 7;
    else if(CheckForFullHouse(hand))
        return 6;
    else if(CheckForFlush(hand))
        return 5;
    else if(CheckForStraight(hand))
        return 4;
    else if(CheckForThreeOfAKind(hand))
        return 3;
    else if(CheckForTwoPair(hand))
        return 2;
    else if(CheckForPair(hand))
        return 1;

    return 0;

}
bool CheckForStraight(int hand[][2])
{
    if(CheckForHighStraight(hand))
        return true;

    for(int i=0;i<3;i++)
    {
        int StraightCounter(0);

        for(int j=i; j<i+4;j++)
        {
            if(hand[j][0] == hand[j+1][0] - 1)
                StraightCounter++;
        }

        if(StraightCounter == 4)
            return true;
    }

    return false;
}
bool CheckForFlush(int hand[][2])
{
    int FlushCounter[4] ={0};

    for(int i=0; i<7; i++)
    {
        FlushCounter[hand[i][1]]++;
    }

    for(int j=0; j<4;j++)
    {
        if(FlushCounter[j] >= 5)
            return true;
    }

    return false;
}
bool CheckForStraightFlush(int hand[][2])
{
    for(int i=0;i<9;i++)
    {
        int StraightCounter(0);
        int flush(-1);

        flush = hand[i][1];

        for(int j=i; j<i+4;j++)
        {
            if(hand[j][1] == flush)
            {
                if(hand[j][0] == hand[j+1][0] - 1)
                    StraightCounter++;
            }
        }

        if( (StraightCounter == 4) && (hand[i+4][0] == flush) )
            return true;
    }

    return false;
}
bool CheckForPair(int hand[][2])
{
    int CardCounter[13]={0};

    for(int i=0; i<7;i++)
    {
        CardCounter[hand[i][0]]++;
    }

    for(int j=0;j<13;j++)
    {
        if(CardCounter[j] == 2)
            return true;
    }

    return false;

}
bool CheckForTwoPair(int hand[][2])
{
    int CardCounter[13]={0};
    int NumberOfPair(0);

    InsertCardCounter(hand,CardCounter);

    for(int i=0; i<13; i++)
    {
        if(CardCounter[i] == 2)
            NumberOfPair++;

        if(NumberOfPair == 2)
            return true;
    }

    return false;

}
bool CheckForThreeOfAKind(int hand[][2])
{
    int CardCounter[13]={0};

    InsertCardCounter(hand,CardCounter);

    for(int j=0;j<13;j++)
    {
        if(CardCounter[j] == 3)
            return true;
    }

    return false;
}
bool CheckForFourOfAKind(int hand[][2])
{
    int CardCounter[13]={0};

    InsertCardCounter(hand,CardCounter);

    for(int j=0;j<13;j++)
    {
        if(CardCounter[j] == 4)
            return true;
    }

    return false;

}
bool CheckForRoyalFlush(int hand[][2])
{
    int flush(-1);

    flush = hand[0][1];
    if(CheckForHighStraight(hand))
    {
        for(int i = 9;i<=12;i++)
        {
            if(hand[i][1] != flush)
                return false;
        }
        return true;
    }

    return false;
}
bool CheckForHighStraight(int hand[][2])
{
    int CardCounter[13]={0};

    InsertCardCounter(hand,CardCounter);

    if(CardCounter[0] >0)
    {
        for(int j=9; j<13;j++)
        {
            if(CardCounter[j] < 1)
                return false;
        }

        return true;
    }

    return false;

}
bool CheckForFullHouse(int hand[][2])
{
    if(CheckForThreeOfAKind(hand) && CheckForPair(hand))
        return true;

    return false;
}
char GameEnds(int Money[4],int NumberOfPlayer)
{
    int NumberOfPlayerBroke(0);
    char repeat('Y');
    char ready;
    int winner(-1);

    for(int i=0; i<NumberOfPlayer;i++)
    {
        if(Money[i] <=0)
        {
            NumberOfPlayerBroke++;
            cout << "Player " << i + 1 << " is no longer playing the game as he has finished his chip count.\n";
        }

        else
        {
            winner = i+1;
        }
    }

    if(NumberOfPlayerBroke == NumberOfPlayer-1)
    {
        repeat = 'N';
        cout << "\nThe winner of the game is player " << winner << endl;
        return repeat;
    }


    cout << "Are you ready for the next round? (Press y to enter)\n";
    cin >> ready;
    system("cls");

    return repeat;
}
void FindWinner(int board[][2],int Player1[][2],int Player2[][2],int Player3[][2],int Player4[][2],bool PlayersPlaying[4],int Pot,int Money[4])
{
    int Player1Card(-1),Player2Card(-1),Player3Card(-1),Player4Card(-1);
    int BetterCard;
    int PlayersTied(0);
    int FirstPlayerTied(-1);
    int SecondPlayerTied(-1);
    int ThirdPlayerTied(-1);


    if(PlayersPlaying[0])
        Player1Card = EvaluateHand(Player1,board);

    if(PlayersPlaying[1])
        Player2Card= EvaluateHand(Player2,board);

    if(PlayersPlaying[2])
        Player3Card= EvaluateHand(Player3,board);

    if(PlayersPlaying[3])
        Player4Card= EvaluateHand(Player4,board);

    BetterCard = CompareHands(board,Player1,Player2,0,1,Player1Card,Player2Card); // Compare Player 1 and Player 2 hands

    if(BetterCard == 0) // if player 1 has a better hand
    {
        BetterCard = CompareHands(board,Player1,Player3,0,2,Player1Card,Player3Card);

        if(BetterCard == 0)
        {
            BetterCard = CompareHands(board,Player1,Player4,0,3,Player1Card,Player4Card);

            if(BetterCard == -1)
            {
                PlayersTied++;
                FirstPlayerTied = 3;
                SecondPlayerTied = 0;
            }
        }

        else if(BetterCard == 2)
        {
            BetterCard = CompareHands(board,Player3,Player4,2,3,Player2Card,Player4Card);

            if(BetterCard == -1)
            {
                PlayersTied++;
                FirstPlayerTied = 3;
                SecondPlayerTied = 2;
            }
        }

        else if(BetterCard == -1)
        {
            PlayersTied++;
            FirstPlayerTied = 2;
            SecondPlayerTied = 0;

            BetterCard = CompareHands(board,Player1,Player4,0,3,Player1Card,Player4Card);

            if(BetterCard == -1)
            {
                PlayersTied++;
                ThirdPlayerTied = 3;
            }
            else
            {
                PlayersTied = 0;
            }
        }
    }

    else if(BetterCard == 1) // if player 2 has a better hand
    {
        BetterCard = CompareHands(board,Player2,Player3,1,2,Player2Card,Player3Card);

        if(BetterCard == 1)
        {
            BetterCard = CompareHands(board,Player2,Player4,1,3,Player2Card,Player4Card);

            if(BetterCard == -1)
            {
                PlayersTied++;
                FirstPlayerTied = 3;
                SecondPlayerTied = 1;
            }
        }

        else if(BetterCard == 2)
        {
            BetterCard = CompareHands(board,Player3,Player4,2,3,Player3Card,Player4Card);

            if(BetterCard == -1)
            {
                PlayersTied++;
                FirstPlayerTied = 3;
                SecondPlayerTied = 2;
            }
        }

        else if(BetterCard == -1)
        {
            PlayersTied++;
            FirstPlayerTied = 2;
            SecondPlayerTied = 1;

            BetterCard = CompareHands(board,Player2,Player4,1,3,Player2Card,Player4Card);
            if(BetterCard == -1)
            {
                PlayersTied++;
                ThirdPlayerTied == 3;
            }
            else
            {
                PlayersTied = 0;
            }
        }
    }

    else if(BetterCard == -1) // if the player has the same hand value
    {
        PlayersTied++;
        FirstPlayerTied = 1;
        SecondPlayerTied = 0;

        BetterCard = CompareHands(board,Player1,Player3,0,2,Player1Card,Player3Card);

        if(BetterCard == 0)
        {
            PlayersTied = 0;
            BetterCard = CompareHands(board,Player1,Player4,0,3,Player1Card,Player4Card);

            if(BetterCard == -1)
            {
                PlayersTied++;
                FirstPlayerTied = 0;
                SecondPlayerTied = 3;
            }
        }

        else if(BetterCard == 2)
        {
            PlayersTied = 0;

            BetterCard = CompareHands(board,Player3,Player4,2,3,Player2Card,Player4Card);

            if(BetterCard == -1)
            {
                PlayersTied++;
                FirstPlayerTied = 0;
                SecondPlayerTied = 3;
            }
        }

        else if(BetterCard == -1)
        {
            PlayersTied++;
            ThirdPlayerTied = 2;
            BetterCard = CompareHands(board,Player1,Player4,0,3,Player1Card,Player4Card);

            if(BetterCard == -1)
                PlayersTied++;
            else
            {
                PlayersTied = 0;
            }
        }
    }

    showBoard(board,3);
    for(int i=0;i<4;i++)
    {
        if(PlayersPlaying[i])
        {
            cout << "\nPlayer " << i+1 << "'s card is: \n";
            showHand(Player1,Player2,Player3,Player4,i);
        }
    }

    OutputWinnerOfTheRound(Pot,Money,BetterCard,PlayersTied,FirstPlayerTied,SecondPlayerTied,ThirdPlayerTied);

}
void OutputWinnerOfTheRound(int Pot,int Money[4],int BetterCard,int PlayersTied,int FirstPlayerTied, int SecondPlayerTied,int ThirdPlayerTied)
{
    if(PlayersTied == 0)
    {
        cout << "The winner of this round is player " << BetterCard + 1 << " and won $" << Pot << endl;
        Money[BetterCard] += Pot;
    }

    else if(PlayersTied == 1)
    {
        Pot = Pot / 2;

        cout << "The winner of this round is player " << FirstPlayerTied + 1 << " and player " << SecondPlayerTied + 1<< " and each won $" << Pot << endl;
        Money[FirstPlayerTied] += Pot;
        Money[SecondPlayerTied] += Pot;
    }

    else if(PlayersTied == 2)
    {
        Pot = Pot / 3;
        cout << "The winner of this round is player " << FirstPlayerTied + 1<< ", player " << SecondPlayerTied + 1<< " and player " << ThirdPlayerTied + 1 << " and each won $" << Pot << endl;
        Money[FirstPlayerTied] += Pot;
        Money[SecondPlayerTied] += Pot;
        Money[ThirdPlayerTied] += Pot;
    }

    else
    {
        Pot = Pot / 4;
        cout << "Everyone has the same hand! No one wins" << endl;

        for(int i=0;i<4;i++)
        {
            Money[i] += Pot;
        }
    }
}
int FindThree(int board[][2], int player[][2])
{
    int hand[7][2];
    int CardCounter[13]={0};
    int ValueOfThree(-1);

    InsertHandAndBoard(board,player,hand);

    for(int i=0; i<7;i++)
    {
        CardCounter[hand[i][0]]++;
    }

    if(CardCounter[0] == 3)
    {
        ValueOfThree = 0;
    }
    else
    {
        for(int j=12; j>=1;j--)
        {
            if(CardCounter[j] == 3)
            {
                ValueOfThree = j;
                break;
            }
        }
    }

    return ValueOfThree;
}
int FindPair(int board[][2], int player[][2])
{
    int hand[7][2];
    int CardCounter[13]={0};
    int ValueOfPair(-1);

    InsertHandAndBoard(board,player,hand);

    for(int i=0; i<7;i++)
    {
        CardCounter[hand[i][0]]++;
    }

    if(CardCounter[0] == 2)
    {
        ValueOfPair = 0;
    }
    else
    {
        for(int j=12; j>=1;j--)
        {
            if(CardCounter[j] == 2)
            {
                ValueOfPair = j;
                break;
            }
        }
    }

    return ValueOfPair;
}
int FindFour(int board[][2], int player[][2])
{
    int hand[7][2];
    int CardCounter[13]={0};
    int ValueOfFour(-1);

    InsertHandAndBoard(board,player,hand);

    for(int i=0; i<7;i++)
    {
        CardCounter[hand[i][0]]++;
    }

    if(CardCounter[0] == 4)
    {
        ValueOfFour = 0;
    }
    else
    {
        for(int j=12; j>=1;j--)
        {
            if(CardCounter[j] == 4)
            {
                ValueOfFour = j;
                break;
            }
        }
    }

    return ValueOfFour;
}
void FindDoublePair(int board[][2], int player[][2],int& Pair1,int& Pair2)
{
    int hand[7][2];
    int CardCounter[13]={0};
    int index(0);

    InsertHandAndBoard(board,player,hand);

    for(int i=0; i<7;i++)
    {
        CardCounter[hand[i][0]]++;
    }

    if(CardCounter[0] == 2)
        Pair1 = 0;

    if(Pair1 == -1)
    {
        for(int i = 12; i>=1 ; i--)
        {
            if(CardCounter[i] == 2)
            {
                switch(index)
                {
                case 0:
                    Pair1 = i;
                    index++;
                    break;
                case 1:
                    Pair2 = i;
                    index++;
                    break;
                }
            }
        }
    }

    else
    {
        for(int i = 12; i>=1 ; i--)
        {
            if(CardCounter[i] == 2)
            {
                Pair2 = i;
                break;
            }
        }
    }
}
int FindStraight(int hand[][2])
{

    for(int i=6;i>3;i--)
    {
        int StraightCounter(0);

        for(int j=i; j>i-4;j--)
        {
            if(hand[j][0] - 1 == hand[j-1][0])
                StraightCounter++;
        }

        if(StraightCounter == 4)
            return i-4;
    }

    return 0;
}
int FindStraightFlush(int hand[][2])
{
    for(int i=12;i>3;i--)
    {
        int StraightCounter(0);
        int flush(-1);

        flush = hand[i][1];

        for(int j=i; j>i-4;j--)
        {
            if(hand[j][1] == flush)
            {
                if(hand[j][0] - 1 == hand[j-1][0])
                    StraightCounter++;
            }
        }

        if( (StraightCounter == 4) && (hand[i-4][0] == flush) )
            return i-4;
    }

    return 0;
}
int CompareHands(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2,int Player1Card,int Player2Card)
{
    int winner;

    if(Player1Card > Player2Card)
    {
        winner = PlayerNumber1;
    }

    else if(Player2Card > Player1Card)
    {
        winner = PlayerNumber2;
    }

    else
    {
        winner = FindTheBetterHand(board,Player1,Player2,PlayerNumber1,PlayerNumber2,Player1Card);
    }

    return winner;
}
int FindTheBetterHand(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2,int CardValue)
{
    int BetterCard;

    switch(CardValue)
    {
    case -1:
        BetterCard = -2;
        break;
    case 0:
        BetterCard = BestHighCard(board,Player1,Player2,PlayerNumber1,PlayerNumber2);
        break;
    case 1:
        BetterCard = BestPair(board,Player1,Player2,PlayerNumber1,PlayerNumber2);
        break;
    case 2:
        BetterCard = BestDoublePair(board,Player1,Player2,PlayerNumber1,PlayerNumber2);
        break;
    case 3:
        BetterCard = BestThreeOfAKind(board,Player1,Player2,PlayerNumber1,PlayerNumber2);
        break;
    case 4:
        BetterCard = BestStraight(board,Player1,Player2,PlayerNumber1,PlayerNumber2);
        break;
    case 5:
        BetterCard = BestFlush(board,Player1,Player2,PlayerNumber1,PlayerNumber2);
        break;
    case 6:
        BetterCard = BestFullHouse(board,Player1,Player2,PlayerNumber1,PlayerNumber2);
        break;
    case 7:
        BetterCard = BestFourOfAKind(board,Player1,Player2,PlayerNumber1,PlayerNumber2);
        break;
    case 8:
        BetterCard = BestStraightFlush(board,Player1,Player2,PlayerNumber1,PlayerNumber2);
        break;
    case 9:
        BetterCard = -1;
        break;
    }

    return BetterCard;
}
int BestHighCard(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2)
{
    int Player1Hand[7][2] = {0};
    int Player2Hand[7][2] = {0};
    int winner = -1;

    InsertHandAndBoard(board,Player1,Player1Hand);
    InsertHandAndBoard(board,Player2,Player2Hand);

    if(Player1Hand[0][0] == 0 && Player2Hand[0][0] != 0)
    {
        winner = PlayerNumber1;
    }

    else if(Player2Hand[0][0] == 0 && Player1Hand[0][0] != 0)
    {
        winner = PlayerNumber2;
    }

    else
    {
        for(int i = 6; i >= 1; i--)
        {
            if(Player1Hand[i][0] > Player2Hand[i][0])
            {
                winner = PlayerNumber1;
                break;
            }
            else if(Player1Hand[i][0] < Player2Hand[i][0])
            {
                winner = PlayerNumber2;
                break;
            }
        }
    }
    return winner;
}
int BestPair(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2)
{
    int winner = -1;
    int Player1Pair = FindPair(board,Player1);
    int Player2Pair = FindPair(board,Player2);
    int Player1Hand[7][2] = {0};
    int Player2Hand[7][2] = {0};

    InsertHandAndBoard(board,Player1,Player1Hand);
    InsertHandAndBoard(board,Player2,Player2Hand);

    if(Player1Pair == 0 && Player2Pair != 0)
    {
        winner = PlayerNumber1;
    }
    else if(Player2Pair == 0 && Player1Pair != 0)
    {
        winner = PlayerNumber2;
    }

    else if(Player1Pair > Player2Pair)
    {
        winner = PlayerNumber1;
    }
    else if(Player1Pair < Player2Pair)
    {
        winner = PlayerNumber2;
    }
    else
    {
        for(int i = 6; i >= 1; i--)
        {
            if(Player1Hand[i][0] == Player1Pair || Player2Hand[i][0] == Player1Pair)
            {
            }
            else if(Player1Hand[i][0] > Player2Hand[i][0])
            {
                winner = PlayerNumber1;
                break;
            }
            else if(Player1Hand[i][0] < Player2Hand[i][0])
            {
                winner = PlayerNumber2;
                break;
            }
        }

    }
    return winner;
}
int BestDoublePair(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2)
{
    int Player1Pair1,Player1Pair2;
    int Player2Pair1,Player2Pair2;
    int winner(-1);

    FindDoublePair(board,Player1,Player1Pair1,Player1Pair2);
    FindDoublePair(board,Player1,Player2Pair1,Player2Pair2);

    if(Player1Pair1 == 0 && Player2Pair1 != 0)
    {
        winner = PlayerNumber1;
    }
    else if(Player2Pair1 == 0 && Player1Pair1 != 0)
    {
        winner = PlayerNumber2;
    }
    else if(Player1Pair1 > Player2Pair1)
        winner = PlayerNumber1;
    else if(Player1Pair1 < Player2Pair1)
        winner = PlayerNumber2;
    else
    {
        if(Player1Pair2 > Player2Pair2)
            winner = PlayerNumber1;
        else if(Player1Pair2 < Player2Pair2)
            winner = PlayerNumber2;
        else
        {
            for(int i=6; i>=0; i--)
            {
                if(Player1[i][0] == Player1Pair1 || Player2[i][0] == Player2Pair1
                        || Player1[i][0] == Player1Pair2 || Player2[i][0] == Player2Pair2)
                {
                }
                else if(Player1[i][0] == 0 && Player2[i][0] != 0)
                {
                    winner = PlayerNumber1;
                    break;
                }
                else if(Player2[i][0] == 0 && Player1[i][0] != 0)
                {
                    winner = PlayerNumber2;
                    break;
                }
                else if(Player1[i][0] > Player2[i][0])
                {
                    winner = PlayerNumber1;
                    break;
                }
                else if(Player1[i][0] < Player2[i][0])
                {
                    winner = PlayerNumber2;
                    break;
                }
            }
        }
    }

    return winner;
}
int BestThreeOfAKind(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2)
{
    int winner = -1;
    int Player1Three = FindThree(board,Player1);
    int Player2Three = FindThree(board,Player2);


    if(Player1Three > Player2Three)
    {
        winner = PlayerNumber1;
    }
    else if(Player1Three < Player2Three)
    {
        winner = PlayerNumber2;
    }
    else
    {
        int Player1Hand[7][2] = {0};
        int Player2Hand[7][2] = {0};

        InsertHandAndBoard(board,Player1,Player1Hand);
        InsertHandAndBoard(board,Player2,Player2Hand);

        if(Player1Hand[0][0] == 0 && Player2Hand[0][0] != 0)
        {
            winner = PlayerNumber1;
        }
        else if(Player2Hand[0][0] == 0 && Player1Hand[0][0] != 0)
        {
            winner = PlayerNumber2;
        }
        else
        {
            for(int i = 6; i >= 1; i--)
            {
                if(Player1Hand[i][0] == Player1Three || Player2Hand[i][0] == Player1Three)
                {
                }
                else if(Player1Hand[i][0] > Player2Hand[i][0])
                {
                    winner = PlayerNumber1;
                    break;
                }
                else if(Player1Hand[i][0] < Player2Hand[i][0])
                {
                    winner = PlayerNumber2;
                    break;
                }
            }
        }
    }
    return winner;
}
int BestFourOfAKind(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2)
{
    int winner = -1;
    int Player1Four = FindFour(board,Player1);
    int Player2Four = FindFour(board,Player2);


    if(Player1Four > Player2Four)
    {
        winner = PlayerNumber1;
    }
    else if(Player1Four < Player2Four)
    {
        winner = PlayerNumber2;
    }
    else
    {
        int Player1Hand[7][2] = {0};
        int Player2Hand[7][2] = {0};

        InsertHandAndBoard(board,Player1,Player1Hand);
        InsertHandAndBoard(board,Player2,Player2Hand);

        if(Player1Hand[0][0] == 0 && Player2Hand[0][0] != 0)
        {
            winner = PlayerNumber1;
        }
        else if(Player2Hand[0][0] == 0 && Player1Hand[0][0] != 0)
        {
            winner = PlayerNumber2;
        }
        else
        {
            for(int i = 6; i >= 1; i--)
            {
                if(Player1Hand[i][0] == Player1Four || Player2Hand[i][0] == Player1Four)
                {
                }
                else if(Player1Hand[i][0] > Player2Hand[i][0])
                {
                    winner = PlayerNumber1;
                    break;
                }
                else if(Player1Hand[i][0] < Player2Hand[i][0])
                {
                    winner = PlayerNumber2;
                    break;
                }
            }
        }
    }
    return winner;
}
int BestStraight(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2)
{
    int Player1Hand[7][2],Player2Hand[7][2];
    int winner=-1;

    InsertHandAndBoard(board,Player1,Player1Hand);
    InsertHandAndBoard(board,Player2,Player2Hand);

    if( (CheckForHighStraight(Player1Hand)) && !(CheckForHighStraight(Player2Hand)) )
        winner = PlayerNumber1;
    else if( (CheckForHighStraight(Player2Hand)) && !(CheckForHighStraight(Player1Hand)) )
        winner = PlayerNumber2;
    else if( (CheckForHighStraight(Player2Hand)) && (CheckForHighStraight(Player1Hand)) )
        winner = -1;
    else
    {
        int Player1Straight = FindStraight(Player1Hand);
        int Player2Straight = FindStraight(Player2Hand);

        if(Player1Straight > Player2Straight)
            winner = PlayerNumber1;
        else if(Player2Straight > Player1Straight)
            winner = PlayerNumber2;
        else
            winner = -1;
    }

    return winner;
}
int BestStraightFlush(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2)
{
    int Player1Hand[7][2],Player2Hand[7][2];
    int winner=-1;

    InsertHandAndBoard(board,Player1,Player1Hand);
    InsertHandAndBoard(board,Player2,Player2Hand);

    int Player1Straight = FindStraight(Player1Hand);
    int Player2Straight = FindStraight(Player2Hand);

    if(Player1Straight > Player2Straight)
        winner = PlayerNumber1;
    else if(Player2Straight > Player1Straight)
        winner = PlayerNumber2;
    else
        winner = -1;

    return winner;

}
int BestFlush(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2)
{
    int Player1Hand[7][2],Player2Hand[7][2];
    int FlushCounter[4]={0};
    int FlushSuit;
    int winner(-1);
    int Player1HighestCard(-1),Player2HighestCard(-1);

    InsertHandAndBoard(board,Player1,Player1Hand);
    InsertHandAndBoard(board,Player2,Player2Hand);


    for(int i=0; i<7; i++)
    {
        FlushCounter[Player1Hand[i][1]]++;
    }

    for(int j=0; j<4;j++)
    {
        if(FlushCounter[j] >= 5)
            FlushSuit = j;
    }

    if(Player1Hand[0][0] == 0 && Player1Hand[0][1] == FlushSuit)
        winner = PlayerNumber1;
    else if(Player2Hand[0][0] == 0 && Player1Hand[0][1] == FlushSuit)
        winner = PlayerNumber2;
    for(int k=6; k>=1; k--)
    {
        if(Player1Hand[k][1] == FlushSuit)
            Player1HighestCard = Player1Hand[k][0];
        if(Player2Hand[k][1] == FlushSuit)
            Player2HighestCard = Player2Hand[k][0];

        if(Player1HighestCard>Player2HighestCard)
        {
            winner = PlayerNumber1;
            break;
        }
        else if(Player2HighestCard > Player1HighestCard)
        {
            winner = PlayerNumber2;
            break;
        }
    }

    return winner;
}
int BestFullHouse(int board[][2],int Player1[][2],int Player2[][2],int PlayerNumber1,int PlayerNumber2)
{
    int winner = -1;
    int Player1Three = FindThree(board,Player1);
    int Player2Three = FindThree(board,Player2);


    if(Player1Three > Player2Three)
    {
        winner = PlayerNumber1;
    }
    else if(Player1Three < Player2Three)
    {
        winner = PlayerNumber2;
    }
    else
    {
        int winner = -1;
        int Player1Pair = FindPair(board,Player1);
        int Player2Pair = FindPair(board,Player2);


        if(Player1Pair > Player2Pair)
        {
            winner = PlayerNumber1;
        }
        else if(Player1Pair < Player2Pair)
        {
            winner = PlayerNumber2;
        }
        else
        {
            winner = -1;
        }
    }

    return winner;
}

/* Sample Run
How many players are playing?(There is a maximum of 4 players and minimum of 2 players)
4
How much do you want each player starting buy in?
500

Its player 1's turn.
Your card is :
Six of Diamonds
Six of Clubs

You have $500 worth of chips right now.
1. Check
2. Bet
3. Fold
What do you want to do?
2
How much do you want to bet?
200
You bet $200 and have $300left.

Its player 2's turn.
Your card is :
Queen of Spades
Ten of Clubs
Player 1has raised an amount of $200

You have $500 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
1

Its player 3's turn.
Your card is :
Queen of Hearts
King of Spades
Player 1has raised an amount of $200

You have $500 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
1

Its player 4's turn.
Your card is :
Six of Hearts
Three of Diamonds
Player 1has raised an amount of $200

You have $500 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
1

The flop is:
Deuce of Clubs
King of Clubs
Three of Spades

Its player 1's turn.
Your card is :
Six of Diamonds
Six of Clubs

You have $300 worth of chips right now.
1. Check
2. Bet
3. Fold
What do you want to do?
1

Its player 2's turn.
Your card is :
Queen of Spades
Ten of Clubs

You have $300 worth of chips right now.
1. Check
2. Bet
3. Fold
What do you want to do?
1

Its player 3's turn.
Your card is :
Queen of Hearts
King of Spades

You have $300 worth of chips right now.
1. Check
2. Bet
3. Fold
What do you want to do?
1

Its player 4's turn.
Your card is :
Six of Hearts
Three of Diamonds

You have $300 worth of chips right now.
1. Check
2. Bet
3. Fold
What do you want to do?
1
The flop was:
Deuce of Clubs
King of Clubs
Three of Spades
The turn card is :
Seven of Spades

Its player 1's turn.
Your card is :
Six of Diamonds
Six of Clubs

You have $300 worth of chips right now.
1. Check
2. Bet
3. Fold
What do you want to do?
2
How much do you want to bet?
200
You bet $200 and have $100left.

Its player 2's turn.
Your card is :
Queen of Spades
Ten of Clubs
Player 1has raised an amount of $200

You have $300 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
1

Its player 3's turn.
Your card is :
Queen of Hearts
King of Spades
Player 1has raised an amount of $200

You have $300 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
1

Its player 4's turn.
Your card is :
Six of Hearts
Three of Diamonds
Player 1has raised an amount of $200

You have $300 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
1
The flop and the turn was:
Deuce of Clubs
King of Clubs
Three of Spades
Seven of Spades
The river card is :
Nine of Clubs

Its player 1's turn.
Your card is :
Six of Diamonds
Six of Clubs

You have $100 worth of chips right now.
1. Check
2. Bet
3. Fold
What do you want to do?
1

Its player 2's turn.
Your card is :
Queen of Spades
Ten of Clubs

You have $100 worth of chips right now.
1. Check
2. Bet
3. Fold
What do you want to do?
2
How much do you want to bet?
100
You bet $100 and have $0left.

Its player 3's turn.
Your card is :
Queen of Hearts
King of Spades
Player 2has raised an amount of $100

You have $100 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
3

Its player 4's turn.
Your card is :
Six of Hearts
Three of Diamonds
Player 2has raised an amount of $100

You have $100 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
3

Its player 1's turn.
Your card is :
Six of Diamonds
Six of Clubs
Player 2has raised an amount of $100

You have $100 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
1
The winner of this round is player 1 and won $1800
Player 2 is no longer playing the game as he has finished his chip count.
Are you ready for the next round? (Press y to enter)
y

Its player 1's turn.
Your card is :
Jack of Diamonds
Seven of Clubs

You have $1800 worth of chips right now.
1. Check
2. Bet
3. Fold
What do you want to do?
2
How much do you want to bet?
100
You bet $100 and have $1700left.

Its player 3's turn.
Your card is :
King of Clubs
Deuce of Hearts
Player 1has raised an amount of $100

You have $100 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
1

Its player 4's turn.
Your card is :
Five of Clubs
Five of Hearts
Player 1has raised an amount of $100

You have $100 worth of chips right now.
1. Call
2. Raise
3. Fold
What do you want to do?
1

The flop and the turn was:
Eight of Clubs
Four of Hearts
Nine of Hearts
Three of Hearts
The river card is :
Ten of Diamond
The winner of this round is player 1 and won $300
Player 2 is no longer playing the game as he has finished his chip count.
Player 3 is no longer playing the game as he has finished his chip count.
Player 4 is no longer playing the game as he has finished his chip count.

The winner of this game is player 1

*/
