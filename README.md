# Texas Hold'em Poker Card Game

## About the Game

This is a card game dealt from a deck of 52 playing cards that consists of 4 pairs of Ace,Jack,Queen,King and 2-10. The minimum number of players is two and maximum is nine players. At the beginning of the game, players are given chips (in this case credit) that represents their currency in the game. At the beginning of each round, players are given two cards each and players can start placing their bets before the flop (the first three card everyone shares) comes. After everyone placed their bets, the turn card ( the fourth card dealt by dealer) is dealt and betting phase continues. The river card ( the fifth or last card dealt) will be dealt and players will have the chance to place another bet. When the betting phase are completed, all players that were still placing bets will have a showdown and see whose cards are stronger. The ranking of the card combinatons will be determine in this [guide](https://www.telegraph.co.uk/betting/casino-guides/poker/hand-rankings-chart-cheat-sheet/).

## How To Run

### Running On VS Code

#### Install C++ extension

1. Go to extensions (Ctrl+shift+x)
2. Search for C/C++ made by microsoft.
3. Select install button.

#### Install Compiler

1. Check if you have a compiler installed.
2. Run either of these command on terminal (g++ --version, clang --version)
3. If both give an error, install a compiler (possibly MinGW)

#### Running the Game

1. Open the repository with VS Code.
2. Go to terminal and select run build task. (Ctrl+Shift+B)
3. Select a compiler of your choice with MinGW on the directory.
4. A main.exe file will appear in your project directory.
5. On your terminal run the command ".\main"

## How To Play

1. After running the program, user will be prompt to enter how many players will be participating.
2. User have to enter the buy in amount.
3. Once the players and buy in amount are entered, game will start.
4. Player will have to take the device and enter a key to continue.
5. Player will be given their card information,current chip amount, current board information,previous players actions and action menu.
6. Player will have to do an action from an action menu given.
7. Once an action is done, all the information from current player will be erased and device shall be passed to the next player.
8. The next player will be given the same options as previous player. (Jump to 3-7)
9. Once betting phased is cleared, players who are still on the bet will go to a showdown.
10. The winner of that round will be announced and players with 0 chip count will be eliminated.
11. Winner of the game will be the player who accumulates all buy in amount.
