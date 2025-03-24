# BowlingUnit
Bowling game app

1. Introduction
1.1 Purpose
    The purpose of this software is to calculate the total score of a single player in a bowling game. The program will allow users to input the number of pins knocked down on each roll, calculate the score based on the rules of bowling, and output the total score at the end of the game.

1.2 Scope
    This software will support the calculation of a single-player bowling game, which consists of 10 frames. The user can input the number of pins knocked down in each roll, and the program will calculate the score according to the rules of bowling (strikes, spares, and regular frames).

1.3 Definitions, Acronyms, and Abbreviations
    •	Strike: A roll where all 10 pins are knocked down on the first try in a frame.
    •	Spare: A frame where all 10 pins are knocked down with two rolls.
    •	Frame: A round in bowling, consisting of two rolls, except for the 10th frame, which can have a third roll if a strike or spare is scored.

2. System Overview
    The system is a console-based application in C++ that allows the user to input the pins knocked down during each roll of a bowling game. It will calculate and display the total score based on the rules of bowling.

3. Functional Requirements

    3.1 Input Requirements
        •	The system should accept up to 21 rolls for a 10-frame game (including extra rolls for strikes/spares in the 10th frame).
        •	The user will be prompted to enter the number of pins knocked down for each roll.

    3.2 Calculation Requirements
        •	Strike: If the first roll of a frame is a strike (i.e., 10 pins), the system should add 10 plus the number of pins knocked down in the next two rolls.
        •	Spare: If the sum of the first two rolls of a frame is 10 pins, the system should add 10 plus the number of pins knocked down in the next roll.
        •	Normal Frame: If no strike or spare occurs, the system should add the sum of the two rolls in the frame.
        •	The system should correctly handle the 10th frame, which may require 3 rolls in case of a strike or spare.

    3.3 Output Requirements
        •	The system should display the total score after all rolls are entered and calculated.

    3.4 Error Handling
        •	The system should validate input to ensure that the number of pins knocked down in each roll is between 0 and 10.
        •	The program should handle cases where the user enters an invalid number of pins, such as more than 10 pins for a single roll.

4. Test Cases

    4.1 Valid Input Test Cases

    •	Test Case 1:
        o	Input: 1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4,10,2,8,6 (from task)
        o	Expected Output: The total score is 133.

    •	Test Case 2:
        o	Input: 8, 1, 6, 4, 8, 2, 4, 0, 10, 6, 3, 8, 2, 7, 2,2,0,5,4
        o	Expected Output: The total score is 110.

    •	Test Case 3:
        o	Input: 10, 10, 7, 3, 8, 1, 10, 4, 2, 5, 4, 7, 3, 9, 0,10,10,7
        o	Expected Output: The total score is 160.

    4.2 Invalid Input Test Cases

    •	Test Case 1:
        o	Input: 11 (invalid, since a roll can't exceed 10 pins).
        o	Expected Output: Error message or input validation to re-enter the roll.

5. Assumptions and Constraints
    •	The program assumes that the user will enter valid integers for the number of pins knocked down.
    •	The system will not handle multiple players in this version.
    •	This system assumes the game is for a single player and handles 10 frames, as per standard bowling rules.


