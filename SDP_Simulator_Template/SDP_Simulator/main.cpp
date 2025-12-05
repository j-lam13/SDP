#include "FEHLCD.h"
#include "FEHImages.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"
#include "FEHRandom.h"

int buzzerWinner = 0;
int p1Score = 0;
int p2Score = 0;
bool questionAnswered[5][6] = {false};
int QuestionsLeft = 30;
int p1Wins = 0;
int p2Wins = 0;
int ties = 0;
int HighScore = 0;
bool gameStarted = false;

// creates a class for each category of questions
void DrawQuestionBoard();

class Math
{
private:
    std::string answer;
    int Value;
    int playerAnswer;

public:
    void MathQuestion200();
    void MathQuestion400();
    void MathQuestion600();
    void MathQuestion800();
    void MathQuestion1000();
};

class Physics
{
private:
    std::string answer;
    int Value;

public:
    void PhysicsQuestion200();
    void PhysicsQuestion400();
    void PhysicsQuestion600();
    void PhysicsQuestion800();
    void PhysicsQuestion1000();
};

class Chemistry
{
private:
    std::string answer;
    int Value;

public:
    void ChemistryQuestion200();
    void ChemistryQuestion400();
    void ChemistryQuestion600();
    void ChemistryQuestion800();
    void ChemistryQuestion1000();
};

class English
{
private:
    std::string answer;
    int Value;

public:
    void EnglishQuestion200();
    void EnglishQuestion400();
    void EnglishQuestion600();
    void EnglishQuestion800();
    void EnglishQuestion1000();
};

class History
{
private:
    std::string answer;
    int Value;

public:
    void HistoryQuestion200();
    void HistoryQuestion400();
    void HistoryQuestion600();
    void HistoryQuestion800();
    void HistoryQuestion1000();
};

class OSU
{
private:
    std::string answer;
    int Value;

public:
    void OSUQuestion200();
    void OSUQuestion400();
    void OSUQuestion600();
    void OSUQuestion800();
    void OSUQuestion1000();
};

void Math::MathQuestion200()
{
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    Value = 200;
    questionAnswered[0][0] = true; 
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;

    // creates a timer bar at the top of the screen
    int x = 319;
    while (x >= 0)
    {


        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What is 12 squared(12^2)?", 80, 100);


        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
           


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 1
            LCD.WriteAt("A) 144", 30, 125);  // Answer 1
            LCD.WriteAt("B) 24", 210, 125);  // Answer 2
            LCD.WriteAt("C) 169", 30, 185); // Answer 3
            LCD.WriteAt("D) 140", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_A})) //Correct Answer --> Displays correct and adds value to score
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$200", 130, 130);
                p1Score += Value;
                Sleep(2000);
                return;
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
           


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 1
            LCD.WriteAt("A) 144", 30, 125);  // Answer 1
            LCD.WriteAt("B) 24", 210, 125);  // Answer 2
            LCD.WriteAt("C) 169", 30, 185); // Answer 3
            LCD.WriteAt("D) 140", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_A})) //Correct Answer --> Displays correct and adds value to score
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$200", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was 144", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }

}
void Math::MathQuestion400()
{
    
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[1][0] = true;
    Value = 400;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;

    while (x >= 0)
    {

        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);

        LCD.SetFontColor(WHITE);
        LCD.WriteAt("If a coin is flipped 4 times, what is", 40, 100);
        LCD.WriteAt("the probability of getting heads all 4 times?", 40, 120);
        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);

        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }

        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1)
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 1
            LCD.WriteAt("A) 1/4", 30, 125);  // Answer 1
            LCD.WriteAt("B) 1/8", 210, 125);  // Answer 2
            LCD.WriteAt("C) 1/16", 30, 185); // Answer 3
            LCD.WriteAt("D) 1/32", 210, 185); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_C}))
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$400", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B}))
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A}))
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D}))
            {
                playerAnswer = 4;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
        }
    }
    else if (buzzerWinner == 2)
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
           

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 1
            LCD.WriteAt("A) 1/4", 30, 125);  // Answer 1
            LCD.WriteAt("B) 1/8", 210, 125);  // Answer 2
            LCD.WriteAt("C) 1/16", 30, 185); // Answer 3
            LCD.WriteAt("D) 1/32", 210, 185); // Answer 4


            LCD.Update();

            if (Keyboard.isPressed({KEY_C}))
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$400", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B}))
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A}))
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D}))
            {
                playerAnswer = 4;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
        }
    }
    else
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was 1/16", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
    
}
void Math::MathQuestion600()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[2][0] = true;
    Value = 600;
        QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
       
    while (x >= 0)
    {

        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);

        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What is the value of 6 factorial?", 40, 100);
        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);

        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }

        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1)
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 4
            LCD.WriteAt("A) 120", 70, 125);  // Answer 1
            LCD.WriteAt("B) 18", 210, 125);  // Answer 2
            LCD.WriteAt("C) 680", 70, 185); // Answer 3
            LCD.WriteAt("D) 720", 210, 185); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_D}))
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$600", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B}))
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A}))
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C}))
            {
                playerAnswer = 4;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
        }
    }
    else if (buzzerWinner == 2)
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
           

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 4
            LCD.WriteAt("A) 120", 70, 125);  // Answer 1
            LCD.WriteAt("B) 18", 210, 125);  // Answer 2
            LCD.WriteAt("C) 680", 70, 185); // Answer 3
            LCD.WriteAt("D) 720", 210, 185); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_D}))
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$600", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B}))
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A}))
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C}))
            {
                playerAnswer = 4;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
        }
    }
    else
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was 720", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
   
}
void Math::MathQuestion800()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[3][0] = true;
    Value = 800;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;

      
    while (x >= 0)
    {

        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);

        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What is the derivative of 5x^2+9x+12?", 40, 100);
        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);

        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }

        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1)
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            LCD.SetFontColor(BLUE);

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 2
            LCD.WriteAt("A) 26", 70, 125);  // Answer 1
            LCD.WriteAt("B) 10x^2+9", 210, 125);  // Answer 2
            LCD.WriteAt("C) 25x^2+9x", 70, 185); // Answer 3
            LCD.WriteAt("D) 9x^2", 210, 185); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_B}))
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$800", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D}))
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A}))
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C}))
            {
                playerAnswer = 4;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
        }
    }
    else if (buzzerWinner == 2)
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 2
            LCD.WriteAt("A) 26", 70, 125);  // Answer 1
            LCD.WriteAt("B) 10x^2+9", 210, 125);  // Answer 2
            LCD.WriteAt("C) 25x^2+9x", 70, 185); // Answer 3
            LCD.WriteAt("D) 9x^2", 210, 185); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_B}))
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$800", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C}))
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A}))
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D}))
            {
                playerAnswer = 4;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
        }
    }
    else
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        LCD.WriteAt("The correct answer was 10x^2+9", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
   

}
void Math::MathQuestion1000()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[4][0] = true;
    Value = 1000;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;

 while (x >= 0)
    {

        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);

        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What is the Taylor series expansion", 80, 100);
        LCD.WriteAt("of e^x centered at x=0?", 80, 120);

        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);

        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }

        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            

             LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 3
            LCD.WriteAt("A) 1-x+x^2/2!-x^3/3!...", 30, 150);  // Answer 1
            LCD.WriteAt("B) 1+x+x^2+x^3...", 170, 150);  // Answer 2
            LCD.WriteAt("C) 1+x+x^2/2!+x^3/3!...", 30, 200); // Answer 3
            LCD.WriteAt("D) 1+x+x^2/2+x^3/3...", 170, 200); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$1000", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);


             LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 3
            LCD.WriteAt("A) 1-x+x^2/2!-x^3/3!...", 30, 150);  // Answer 1
            LCD.WriteAt("B) 1+x+x^2+x^3...", 170, 150);  // Answer 2
            LCD.WriteAt("C) 1+x+x^2/2!+x^3/3!...", 30, 200); // Answer 3
            LCD.WriteAt("D) 1+x+x^2/2+x^3/3...", 170, 200); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
                playerAnswer = 1;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$1000", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 3;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                playerAnswer = 2;
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was 1+x+x^2/2!+x^3/3!...", 30, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }

}

void Physics::PhysicsQuestion200()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[0][1] = true;
    Value = 200;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {

        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);

        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What force attracts objects towards the center", 30, 100);
        LCD.WriteAt("of the Earth?", 30, 120);

        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);

        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }

        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 1
            LCD.WriteAt("A) Gravity", 70, 145);  // Answer 1
            LCD.WriteAt("B) Drag", 210, 145);  // Answer 2
            LCD.WriteAt("C) Friction", 70, 205); // Answer 3
            LCD.WriteAt("D) Resistence", 210, 205); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_A})) //Correct Answer --> Displays correct and adds value to score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$200", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 1
            LCD.WriteAt("A) Gravity", 70, 145);  // Answer 1
            LCD.WriteAt("B) Drag", 210, 145);  // Answer 2
            LCD.WriteAt("C) Friction", 70, 205); // Answer 3
            LCD.WriteAt("D) Resistence", 210, 205); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_A})) //Correct Answer --> Displays correct and adds value to score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$200", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Gravity", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }

}
void Physics::PhysicsQuestion400()
{

    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[1][1] = true;
    Value = 400;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;    
     while (x >= 0)
    {

        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);

        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What law is associated with the equation F=ma?", 30, 100);

        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);

        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }

        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 3
            LCD.WriteAt("A) Bragg's Law", 70, 145);  // Answer 1
            LCD.WriteAt("B) Newton's 3rd law", 200, 145);  // Answer 2
            LCD.WriteAt("C) Newton's 2nd law", 70, 205); // Answer 3
            LCD.WriteAt("D) Hooke's Law", 200, 205); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$400", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS 3
            LCD.WriteAt("A) Bragg's Law", 70, 145);  // Answer 1
            LCD.WriteAt("B) Newton's 3rd law", 200, 145);  // Answer 2
            LCD.WriteAt("C) Newton's 2nd law", 70, 205); // Answer 3
            LCD.WriteAt("D) Hooke's Law", 200, 205); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$400", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
                
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Newton's 2nd law", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }

}
void Physics::PhysicsQuestion600()
{

    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[2][1] = true;
    Value = 600;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
       while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What type of energy is stored due", 40, 100);
        LCD.WriteAt("to an objects position?", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Potential Energy", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS A
            LCD.WriteAt("A) Potential Energy", 30, 125);  // Answer 1
            LCD.WriteAt("B) Thermal Energy", 210, 125);  // Answer 2
            LCD.WriteAt("C) Kinetic Energy", 30, 185); // Answer 3
            LCD.WriteAt("D) Nuclear energy", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_A})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void Physics::PhysicsQuestion800()
{

    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[3][1] = true;
    Value = 800;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What phenomenon occurs when light bends as", 40, 100);
        LCD.WriteAt("it passes from one medium to another.", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Refraction", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Reflection", 30, 125);  // Answer 1
            LCD.WriteAt("B) Diffraction", 210, 125);  // Answer 2
            LCD.WriteAt("C) Refraction", 30, 185); // Answer 3
            LCD.WriteAt("D) Dispersion", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void Physics::PhysicsQuestion1000()
{

    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[4][1] = true;
    Value = 1000;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" Who's considered the father", 40, 100);
        LCD.WriteAt(" of thermodynamics?", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Sadi Carnot", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) James Maxwell", 30, 125);  // Answer 1
            LCD.WriteAt("B) Rudolf Clausius", 210, 125);  // Answer 2
            LCD.WriteAt("C) Sadi Carnot", 30, 185); // Answer 3
            LCD.WriteAt("D) Lord Kelvin", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}

void Chemistry::ChemistryQuestion200()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[0][2] = true;
    Value = 200;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
     while (x >= 0)
    {


        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What is the common name of H2O?", 60, 100);

        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS D
            LCD.WriteAt("A) Carbon Dioxide", 70, 125);  // Answer 1
            LCD.WriteAt("B) Hydrogen", 210, 125);  // Answer 2
            LCD.WriteAt("C) Hydronium", 70, 185); // Answer 3
            LCD.WriteAt("D) Water", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_D})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$200", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS ___
            LCD.WriteAt("A) Carbin Dioxide", 70, 125);  // Answer 1
            LCD.WriteAt("B) Hydrogen", 210, 125);  // Answer 2
            LCD.WriteAt("C) Hydronium", 70, 185); // Answer 3
            LCD.WriteAt("D) Water", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_D})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$200", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Water", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }


}
void Chemistry::ChemistryQuestion400()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[1][2] = true;
    Value = 400;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;    
     while (x >= 0)
    {


        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What particle has a negative charge", 60, 100);
        LCD.WriteAt("and occupies orbitals around the nucleus?", 60, 120);


        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS B
            LCD.WriteAt("A) Proton", 70, 125);  // Answer 1
            LCD.WriteAt("B) Electron", 210, 125);  // Answer 2
            LCD.WriteAt("C) Neutron", 70, 185); // Answer 3
            LCD.WriteAt("D) Positron", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_B})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$400", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
           


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS B
            LCD.WriteAt("A) Proton", 70, 125);  // Answer 1
            LCD.WriteAt("B) Electron", 210, 125);  // Answer 2
            LCD.WriteAt("C) Neutron", 70, 185); // Answer 3
            LCD.WriteAt("D) Positron", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_B})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$400", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$400", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Electron", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }


}
void Chemistry::ChemistryQuestion600()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[2][2] = true;
    Value = 600;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
     while (x >= 0)
    {


        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What Law is this: PV = nRT", 60, 100);

        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS A
            LCD.WriteAt("A) Ideal Gas Law", 70, 145);  // Answer 1
            LCD.WriteAt("B) Boyle's Law", 210, 145);  // Answer 2
            LCD.WriteAt("C) Charles's Law", 70, 205); // Answer 3
            LCD.WriteAt("D) Avegadro's Law", 210, 205); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_A})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$600", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS ___
            LCD.WriteAt("A) Ideal Gas Law", 70, 125);  // Answer 1
            LCD.WriteAt("B) Boyle's Law", 210, 125);  // Answer 2
            LCD.WriteAt("C) Charle's Law", 70, 185); // Answer 3
            LCD.WriteAt("D) Avegadro's Law", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_A})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$600", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$600", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Ideal Gas Law", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }


}
void Chemistry::ChemistryQuestion800()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[3][2] = true;
    Value = 800;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;    
     while (x >= 0)
    {


        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What is the tendancy of an atom to", 60, 100);
        LCD.WriteAt("attract electrons in a chemical bond?", 60, 120);


        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
           


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Ionization Energy", 70, 125);  // Answer 1
            LCD.WriteAt("B) Atomic Raidus", 210, 125);  // Answer 2
            LCD.WriteAt("C) Electronegativity", 70, 185); // Answer 3
            LCD.WriteAt("D) Electron Affinity", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$800", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 7);
            


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Ionization Energy", 70, 125);  // Answer 1
            LCD.WriteAt("B) Atomic Raidus", 210, 125);  // Answer 2
            LCD.WriteAt("C) Electronegativity", 70, 185); // Answer 3
            LCD.WriteAt("D) Electron Affinity", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$800", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$800", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Electronegativity", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }


}
void Chemistry::ChemistryQuestion1000()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[4][2] = true;
    Value = 1000;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
     while (x >= 0)
    {


        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt("This bond forms when one atom transfers ", 20, 100);
        LCD.WriteAt("electrons to another, creating oppositely ", 60, 120);
        LCD.WriteAt("charged ions that attract. ", 60, 140);



        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
           


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Covalent Bond", 70, 125);  // Answer 1
            LCD.WriteAt("B) AMetallic Bond", 210, 125);  // Answer 2
            LCD.WriteAt("C) Ionic Bond", 70, 185); // Answer 3
            LCD.WriteAt("D) Hydrogen Bond", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$1000", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Covalent Bond", 70, 125);  // Answer 1
            LCD.WriteAt("B) Metallic Bond", 210, 125);  // Answer 2
            LCD.WriteAt("C) Ionic Bond", 70, 185); // Answer 3
            LCD.WriteAt("D) Hydrogen bond", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$1000", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$1000", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Ionic Bond", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }


}

void History::HistoryQuestion200()
{

    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[0][4] = true;
    Value = 200;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
     while (x >= 0)
    {


        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt("The Ancient Egyptians built these structures", 20, 100);
        LCD.WriteAt("as tombs for pharaohs.", 40, 120);


        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
           


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS B
            LCD.WriteAt("A) Ziggurats", 70, 125);  // Answer 1
            LCD.WriteAt("B) Pyramids", 210, 125);  // Answer 2
            LCD.WriteAt("C) Temples", 70, 185); // Answer 3
            LCD.WriteAt("D) Obelisks", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_B})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$200", 130, 130);
                p1Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p1Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
        while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS ___
            LCD.WriteAt("A) Ziggurats", 70, 125);  // Answer 1
            LCD.WriteAt("B) Pyramids", 210, 125);  // Answer 2
            LCD.WriteAt("C) Temples", 70, 185); // Answer 3
            LCD.WriteAt("D) Obelisks", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_B})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$200", 130, 130);
                p2Score += Value;
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$200", 130, 130);
                p2Score -= Value;
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }
    }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Pyramids", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }



}
void History::HistoryQuestion400()
{

    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[1][4] = true;
    Value = 400;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
       while (x >= 0)
    {


        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Who is credited for", 60, 100);
        LCD.WriteAt("discovering the Americas?", 60, 120);


        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Christopher Columbus", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);
            


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Ferdinand Magellan", 30, 125);  // Answer 1
            LCD.WriteAt("B) Marco Polo", 210, 125);  // Answer 2
            LCD.WriteAt("C) Christopher Columbus", 30, 185); // Answer 3
            LCD.WriteAt("D) Vasco da Gama", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }

}
void History::HistoryQuestion600()
{

    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[2][4] = true;
    Value = 600;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;    
    while (x >= 0)
    {


        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Who wrote the ", 40, 100);
        LCD.WriteAt("Declaration of Independence?", 40, 120);


        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);

        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }

        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);

        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Thoamas Jefferson", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);


            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Benjamin Franklin", 30, 125);  // Answer 1
            LCD.WriteAt("B) John Adams", 210, 125);  // Answer 2
            LCD.WriteAt("C) Thomas Jefferson", 30, 185); // Answer 3
            LCD.WriteAt("D) James Madison", 210, 185); // Answer 4




            LCD.Update();




            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }

}
void History::HistoryQuestion800()
{

    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[3][4] = true;
    Value = 800;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What Chinese Dynasty was known for ", 40, 100);
        LCD.WriteAt(" building the Great Wall of China? ", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Qin Dynasty", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);

            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS D
            LCD.WriteAt("A) Han Dynasty", 30, 125);  // Answer 1
            LCD.WriteAt("B) Tang Dynasty", 210, 125);  // Answer 2
            LCD.WriteAt("C) Ming Dynasty", 30, 185); // Answer 3
            LCD.WriteAt("D) Qin Dynasty", 210, 185); // Answer 4

            LCD.Update();

            if (Keyboard.isPressed({KEY_D})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void History::HistoryQuestion1000()
{

    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[4][4] = true;
    Value = 1000;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {

        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);


        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What global conflict began after", 40, 100);
        LCD.WriteAt(" The Assassination of Archduke", 40, 120);
        LCD.WriteAt(" Franz Ferdinand", 40, 140);


        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was World War I", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS B
            LCD.WriteAt("A) The Franco-Prussian War", 30, 125);  // Answer 1
            LCD.WriteAt("B) World War I", 210, 125);  // Answer 2
            LCD.WriteAt("C) World War II", 30, 185); // Answer 3
            LCD.WriteAt("D) The Cold War", 210, 185); // Answer 4

            LCD.Update();


            if (Keyboard.isPressed({KEY_B})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}

void English::EnglishQuestion200()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[0][3] = true;
    Value = 200;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What part of speech describes", 40, 100);
        LCD.WriteAt(" an action, state, or occurance?", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Verb", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS B
            LCD.WriteAt("A) Noun", 30, 125);  // Answer 1
            LCD.WriteAt("B) Verb", 210, 125);  // Answer 2
            LCD.WriteAt("C) Adjective", 30, 185); // Answer 3
            LCD.WriteAt("D) Adverb", 210, 185); // Answer 4

            LCD.Update();


            if (Keyboard.isPressed({KEY_B})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void English::EnglishQuestion400()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[1][3] = true;
    Value = 400;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;    
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What is the 'central idea' or", 40, 100);
        LCD.WriteAt(" underlying message of a literary work?", 40, 120);


        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Theme", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS D
            LCD.WriteAt("A) Theme", 30, 125);  // Answer 1
            LCD.WriteAt("B) Setting", 210, 125);  // Answer 2
            LCD.WriteAt("C) Plot", 30, 185); // Answer 3
            LCD.WriteAt("D) Conflict", 210, 185); // Answer 4


            LCD.Update();

            if (Keyboard.isPressed({KEY_D})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void English::EnglishQuestion600()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[2][3] = true;
    Value = 600;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What figure of speech compares two unlike", 40, 100);
        LCD.WriteAt(" things using words 'like' or 'as'?", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Simile", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS D
            LCD.WriteAt("A) Metaphor", 30, 125);  // Answer 1
            LCD.WriteAt("B) Alliteration", 210, 125);  // Answer 2
            LCD.WriteAt("C) Personification", 30, 185); // Answer 3
            LCD.WriteAt("D) Simile", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_D})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void English::EnglishQuestion800()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[3][3] = true;
    Value = 800;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What person is a story told from the 'I' point of ", 40, 100);
        LCD.WriteAt("view written in?.", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was First Person", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS ____
            LCD.WriteAt("A) First Person", 30, 125);  // Answer 1
            LCD.WriteAt("B) Third Person Limited", 210, 125);  // Answer 2
            LCD.WriteAt("C) Third Person", 30, 185); // Answer 3
            LCD.WriteAt("D) Second Person", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_A})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void English::EnglishQuestion1000()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[4][3] = true;
    Value = 1000;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" In poetry, what term refers to repetition", 40, 100);
        LCD.WriteAt("of constant sounds at the beginning of words?", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Alliteration", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Assonance", 30, 125);  // Answer 1
            LCD.WriteAt("B) Anomatopoeia", 210, 125);  // Answer 2
            LCD.WriteAt("C) Alliteration", 30, 185); // Answer 3
            LCD.WriteAt("D) Consonance", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}

void OSU::OSUQuestion200()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[0][5] = true;
    Value = 200;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What is the mascot of ", 40, 100);
        LCD.WriteAt(" The Ohio State University?", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Brutus Buckeye", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Bucky Badger", 30, 125);  // Answer 1
            LCD.WriteAt("B) Willie Wildcat", 210, 125);  // Answer 2
            LCD.WriteAt("C) Brutus Buckeye", 30, 185); // Answer 3
            LCD.WriteAt("D) Sparty", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void OSU::OSUQuestion400()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[1][5] = true;
    Value = 400;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What is the nickname of Ohio State's ", 40, 100);
        LCD.WriteAt(" football stadium? ", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was The Horseshoe", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS ____
            LCD.WriteAt("A) The Horseshoe", 30, 125);  // Answer 1
            LCD.WriteAt("B) The Big House", 210, 125);  // Answer 2
            LCD.WriteAt("C) The Rose Bowl", 30, 185); // Answer 3
            LCD.WriteAt("D) The Dome", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_A})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }



}
void OSU::OSUQuestion600()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[2][5] = true;
    Value = 600;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt(" What was the score of the most recent", 40, 100);
        LCD.WriteAt(" OSU vs. Xichigan football game?", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was 27-9", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS D
            LCD.WriteAt("A) 21-14", 30, 125);  // Answer 1
            LCD.WriteAt("B) 34-10", 210, 125);  // Answer 2
            LCD.WriteAt("C) 27-6", 30, 185); // Answer 3
            LCD.WriteAt("D) 27-9", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_D})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_C})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void OSU::OSUQuestion800()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[3][5] = true;
    Value = 800;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What year was OSU was founded", 40, 100);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was 1870", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) 1885", 30, 125);  // Answer 1
            LCD.WriteAt("B) 1855", 210, 125);  // Answer 2
            LCD.WriteAt("C) 1870", 30, 185); // Answer 3
            LCD.WriteAt("D) 1901", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }




}
void OSU::OSUQuestion1000()
{
    int x = 319;
    //Variables: Value = point value of question; questionAnswered = marks question as answered
    questionAnswered[4][5] = true;
    Value = 1000;
    QuestionsLeft--;
    //prevents issue of keeping previous buzzer winner 
    buzzerWinner = 0;
    while (x >= 0)
    {




        LCD.SetFontColor(BLUE);
        LCD.DrawRectangle(0, 0, 319, 239);
        LCD.FillRectangle(0, 0, 319, 239);




        LCD.SetFontColor(WHITE);
        LCD.WriteAt("What was the first building constructed", 40, 100);
        LCD.WriteAt("on OSU's campus?", 40, 120);




        // Timer bar
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);


        // Buzzer Check
        if (Keyboard.isPressed({KEY_S}))
        {
            buzzerWinner = 1;
            break;
        }
        else if (Keyboard.isPressed({KEY_K}))
        {
            buzzerWinner = 2;
            break;
        }


        x -= 11;
        Sleep(230);
        LCD.Update();
    }
    LCD.Clear();
    if (buzzerWinner == 1) //if statement for player 1 buzzing in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 1 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);




        LCD.Update();
            }
    else if (buzzerWinner == 2) //if statement for player 2 buzzing in
    {
         LCD.SetFontColor(WHITE);
        LCD.WriteAt("Player 2 Buzzed In!", 80, 50);
        LCD.Update();
        Sleep(2000);


        LCD.Update();
            }
    else //Nobody buzzed in
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Time's Up!", 80, 100);
        //Gives the answer
        LCD.WriteAt("The correct answer was Hayes Hall", 60, 130);
        LCD.Update();
        Sleep(2000);
        DrawQuestionBoard();
        LCD.Update();
    }
while (1)
        {
            // Draw four boxes on the screen for answer choices
            LCD.WriteAt("Enter answer A, B, C, or D:", 80, 75);




            LCD.SetFontColor(WHITE);         // CORERCT ANSWER IS C
            LCD.WriteAt("A) Thompson Library", 30, 125);  // Answer 1
            LCD.WriteAt("B) Otron Hall", 210, 125);  // Answer 2
            LCD.WriteAt("C) Hayes Hall", 30, 185); // Answer 3
            LCD.WriteAt("D) Morrill Hall", 210, 185); // Answer 4


            LCD.Update();


            if (Keyboard.isPressed({KEY_C})) //Correct Answer --> Displays correct and adds value to score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Correct!", 130, 100);
                LCD.WriteAt("+$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score += Value;
                }
                else if (buzzerWinner == 2){
                p2Score += Value;
                }
                Sleep(2000);
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_B})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_A})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Incorrect!", 130, 100);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
            else if (Keyboard.isPressed({KEY_D})) //Incorrect Answer --> Displays incorrect and subtracts value from score
            {
               
                LCD.Clear();
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("-$", 130, 130);
                LCD.WriteAt(Value, 144, 130);
                if (buzzerWinner == 1){
                p1Score -= Value;
                }
                else if (buzzerWinner == 2){
                p2Score -= Value;
                }
                Sleep(2000);
                LCD.Update();
                DrawQuestionBoard();
                LCD.Update();
                break;
            }
           
        }



}

void DrawQuestionBoard()
{
    // Color the background black
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);

    // Draw the question board grid
    LCD.SetFontColor(BLUE);
    // Row 1 of rectangles: CATEGORIES
    // x coordiante 5 +52  y corrdinate 2
    // Width 50 Height 34
    LCD.DrawRectangle(5, 2, 50, 34);
    LCD.FillRectangle(5, 2, 50, 34);
    // Write Math in first rectancle

    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("Math", 15, 15);

    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(57, 2, 50, 34);
    LCD.FillRectangle(57, 2, 50, 34);
    // Write Physics in second rectancle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Physics", 60, 15);

    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(109, 2, 50, 34);
    LCD.FillRectangle(109, 2, 50, 34);
    // Write Chemistry in third rectancle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Chem", 121, 15);

    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(161, 2, 50, 34);
    LCD.FillRectangle(161, 2, 50, 34);
    // Write English in fourth rectancle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("English", 164, 15);

    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(213, 2, 50, 34);
    LCD.FillRectangle(213, 2, 50, 34);
    // Draw History in fifth rectancle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("History", 218, 15);

    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(265, 2, 50, 34);
    LCD.FillRectangle(265, 2, 50, 34);
    // Write OSU trivia in sixth rectancle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("OSU!", 280, 15);

    // Row 2 of rectangles: $200
    // x coordiante 5 +52  y corrdinate 38
    // Width 50 Height 34
    if(questionAnswered[0][0] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(5, 38, 50, 34); //Draw and fill in Box
    LCD.FillRectangle(5, 38, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("$200", 15, 50); //Draw Money value into it
    LCD.SetFontColor(BLUE);
    }
    else{ //If question has been answered, draw black rectangle over it
        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(5, 38, 50, 34);
        LCD.FillRectangle(5, 38, 50, 34);
        LCD.SetFontColor(BLUE);
    }

if(questionAnswered[0][1] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(57, 38, 50, 34); //Draw and fill in Box
    LCD.FillRectangle(57, 38, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("$200", 67, 50); //Draw Money value into it
    LCD.SetFontColor(BLUE);
    }
    else{//If question has been answered, draw black rectangle over it
        LCD.SetFontColor(BLACK); 
        LCD.DrawRectangle(57, 38, 50, 34);
        LCD.FillRectangle(57, 38, 50, 34);
        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[0][2] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(109, 38, 50, 34); // Draw and fill in Box
    LCD.FillRectangle(109, 38, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("$200", 119, 50); //Draw Money value into it
    LCD.SetFontColor(BLUE);
    }
    else{ //If question has been answered, draw black rectangle over it
        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(109, 38, 50, 34);
    LCD.FillRectangle(109, 38, 50, 34);
        LCD.SetFontColor(BLUE);
    }
    
if(questionAnswered[0][3] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(161, 38, 50, 34); //Draw and fill in Box
    LCD.FillRectangle(161, 38, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("$200", 171, 50); //Draw Money value into it
    LCD.SetFontColor(BLUE);
    }
    else{ //If question has been answered, draw black rectangle over it
        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(161, 38, 50, 34);
    LCD.FillRectangle(161, 38, 50, 34);
        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[0][4] == false){  //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(213, 38, 50, 34); //Draw and fill in Box
    LCD.FillRectangle(213, 38, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("$200", 223, 50); //Draw Money value into it
    LCD.SetFontColor(BLUE);
    }
    else{ //If question has been answered, draw black rectangle over it
        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(213, 38, 50, 34);
    LCD.FillRectangle(213, 38, 50, 34);
        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[0][5] == false){  //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(265, 38, 50, 34); //Draw and fill in Box
    LCD.FillRectangle(265, 38, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("$200", 275, 50); //Draw Money value into it
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(265, 38, 50, 34);
    LCD.FillRectangle(265, 38, 50, 34);
        LCD.SetFontColor(BLUE);
    }
    

    // Row 3 of rectangles: $400
    // x coordiante 5 +52  y corrdinate 74
    // Width 50 Height 34
    if(questionAnswered[1][0] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(5, 74, 50, 34); //Draw and fill in Box
    LCD.FillRectangle(5, 74, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("$400", 15, 86); //Draw Money value into it
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(5, 74, 50, 34);
        LCD.FillRectangle(5, 74, 50, 34);
        LCD.SetFontColor(BLUE);
    }
    
if(questionAnswered[1][1] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(57, 74, 50, 34);
    LCD.FillRectangle(57, 74, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$400", 67, 86);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(57, 74, 50, 34);
    LCD.FillRectangle(57, 74, 50, 34);
        LCD.SetFontColor(BLUE);
    }
    
    if(questionAnswered[1][2] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(109, 74, 50, 34);
    LCD.FillRectangle(109, 74, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$400", 119, 86);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(109, 74, 50, 34);
    LCD.FillRectangle(109, 74, 50, 34);
        LCD.SetFontColor(BLUE);
    }
    
    if(questionAnswered[1][3] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(161, 74, 50, 34);
    LCD.FillRectangle(161, 74, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$400", 171, 86);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(161, 74, 50, 34);
    LCD.FillRectangle(161, 74, 50, 34);
        LCD.SetFontColor(BLUE);
    }
    
    if(questionAnswered[1][4] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(213, 74, 50, 34);
    LCD.FillRectangle(213, 74, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$400", 223, 86);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(213, 74, 50, 34);
    LCD.FillRectangle(213, 74, 50, 34);
        LCD.SetFontColor(BLUE);
    }

   if(questionAnswered[1][5] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(265, 74, 50, 34);
    LCD.FillRectangle(265, 74, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$400", 275, 86);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(265, 74, 50, 34);
    LCD.FillRectangle(265, 74, 50, 34);
        LCD.SetFontColor(BLUE);
    }


    

    // Row 4 of rectangles: $600
    // x coordiante 5 +52  y corrdinate 110
    // Width 50 Height 34
    
    if(questionAnswered[2][0] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(5, 110, 50, 34);
    LCD.FillRectangle(5, 110, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$600", 15, 122);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(5, 110, 50, 34);
    LCD.FillRectangle(5, 110, 50, 34);
        LCD.SetFontColor(BLUE);
    }
    
    if(questionAnswered[2][1] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(57, 110, 50, 34);
    LCD.FillRectangle(57, 110, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$600", 67, 122);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(57, 110, 50, 34);
    LCD.FillRectangle(57, 110, 50, 34);
        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[2][2] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(109, 110, 50, 34);
    LCD.FillRectangle(109, 110, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$600", 119, 122);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(109, 110, 50, 34);
    LCD.FillRectangle(109, 110, 50, 34);
        LCD.SetFontColor(BLUE);
    }
    
if(questionAnswered[2][3] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(161, 110, 50, 34);
    LCD.FillRectangle(161, 110, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$600", 171, 122);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(161, 110, 50, 34);
    LCD.FillRectangle(161, 110, 50, 34);
        LCD.SetFontColor(BLUE);
    }
    
    if(questionAnswered[2][4] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(213, 110, 50, 34);
    LCD.FillRectangle(213, 110, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$600", 223, 122);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(213, 110, 50, 34);
    LCD.FillRectangle(213, 110, 50, 34);
        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[2][5] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(265, 110, 50, 34);
    LCD.FillRectangle(265, 110, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$600", 275, 122);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(265, 110, 50, 34);
    LCD.FillRectangle(265, 110, 50, 34);
        LCD.SetFontColor(BLUE);
    }


    // Row 5 of rectangles: $800
    // x coordiante 5 +52  y corrdinate 146
    // Width 50 Height 34

    if(questionAnswered[3][0] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(5, 146, 50, 34);
    LCD.FillRectangle(5, 146, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$800", 15, 158);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(5, 146, 50, 34);
    LCD.FillRectangle(5, 146, 50, 34);
        LCD.SetFontColor(BLUE);
    }

   if(questionAnswered[3][1] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(57, 146, 50, 34);
    LCD.FillRectangle(57, 146, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$800", 67, 158);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(57, 146, 50, 34);
    LCD.FillRectangle(57, 146, 50, 34);

        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[3][2] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(109, 146, 50, 34);
    LCD.FillRectangle(109, 146, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$800", 119, 158);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
        LCD.DrawRectangle(109, 146, 50, 34);
    LCD.FillRectangle(109, 146, 50, 34);

        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[3][3] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(161, 146, 50, 34);
    LCD.FillRectangle(161, 146, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$800", 171, 158);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
    LCD.DrawRectangle(161, 146, 50, 34);
    LCD.FillRectangle(161, 146, 50, 34);

        LCD.SetFontColor(BLUE);
    }

   if(questionAnswered[3][4] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(213, 146, 50, 34);
    LCD.FillRectangle(213, 146, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$800", 223, 158);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
    LCD.DrawRectangle(213, 146, 50, 34);
    LCD.FillRectangle(213, 146, 50, 34);

        LCD.SetFontColor(BLUE);
    }

 if(questionAnswered[3][5] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(265, 146, 50, 34);
    LCD.FillRectangle(265, 146, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$800", 275, 158);
    LCD.SetFontColor(BLUE);
    }
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
    LCD.DrawRectangle(265, 146, 50, 34);
    LCD.FillRectangle(265, 146, 50, 34);

        LCD.SetFontColor(BLUE);
    }

    // Row 6 of rectangles: $1000
    // x coordiante 5 +52  y corrdinate 182
    // Width 50 Height 34

    if(questionAnswered[4][0] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(5, 182, 50, 34);
    LCD.FillRectangle(5, 182, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$1000", 15, 194);
    LCD.SetFontColor(BLUE);
    }
    
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
    LCD.DrawRectangle(5, 182, 50, 34);
    LCD.FillRectangle(5, 182, 50, 34);

        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[4][1] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(57, 182, 50, 34);
    LCD.FillRectangle(57, 182, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$1000", 67, 194);
    LCD.SetFontColor(BLUE);
    }
    
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
    LCD.DrawRectangle(57, 182, 50, 34);
    LCD.FillRectangle(57, 182, 50, 34);

        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[4][2] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(109, 182, 50, 34);
    LCD.FillRectangle(109, 182, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$1000", 119, 194);
    LCD.SetFontColor(BLUE);
    }
    
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
    LCD.DrawRectangle(109, 182, 50, 34);
    LCD.FillRectangle(109, 182, 50, 34);

        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[4][3] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(161, 182, 50, 34);
    LCD.FillRectangle(161, 182, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$1000", 171, 194);
    LCD.SetFontColor(BLUE);
    }
    
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
    LCD.DrawRectangle(161, 182, 50, 34);
    LCD.FillRectangle(161, 182, 50, 34);

        LCD.SetFontColor(BLUE);
    }

    if(questionAnswered[4][4] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(213, 182, 50, 34);
    LCD.FillRectangle(213, 182, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$1000", 223, 194);
    LCD.SetFontColor(BLUE);
    }
    
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
    LCD.DrawRectangle(213, 182, 50, 34);
    LCD.FillRectangle(213, 182, 50, 34);

        LCD.SetFontColor(BLUE);
    }
    
    if(questionAnswered[4][5] == false){ //Checks if question has been answered --> If not, draw money value over it
    LCD.SetFontColor(BLUE);
    // Draw and fill in Box
    LCD.DrawRectangle(265, 182, 50, 34);
    LCD.FillRectangle(265, 182, 50, 34);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    //Draw Money value into it
    LCD.WriteAt("$1000", 275, 194);
    LCD.SetFontColor(BLUE);
    }
    
    else{
        LCD.SetFontColor(BLACK); //If question has been answered, draw black rectangle over it
    LCD.DrawRectangle(265, 182, 50, 34);
    LCD.FillRectangle(265, 182, 50, 34);

        LCD.SetFontColor(BLUE);
    }


//Display player Scores at the bottom of the screen
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("P1 Score: ", 10, 223);
    LCD.WriteAt(p1Score, 70, 223);
    LCD.WriteAt("P2 Score:", 220, 223);
    LCD.WriteAt(p2Score, 280, 223);

    int x, y;
    // this bool and loopallows clicks that do not correspond to a button to be ignored (a click on empty space will not softlock the user)
    bool buttonPressed = false;
    while (!buttonPressed)
    {
        while (!LCD.Touch(&x, &y))
            ;
        // waits for touch input before proceeding
        while (LCD.Touch(&x, &y))
            ;
        if (x > 5 && x < 56 && y > 38 && y < 73)
        {
            Math math200;
            math200.MathQuestion200();
            buttonPressed = true;
        }

        if (x > 5 && x < 56 && y > 74 && y < 110)
        {
            Math math400;
            math400.MathQuestion400();
            buttonPressed = true;
        }

        if (x > 5 && x < 56 && y > 111 && y < 146)
        {
            Math math600;
            math600.MathQuestion600();
            buttonPressed = true;
        }

        if (x > 5 && x < 56 && y > 147 && y < 182)
        {
            Math math800;
            math800.MathQuestion800();
            buttonPressed = true;
        }

        if (x > 5 && x < 56 && y > 183 && y < 219)
        {
            Math math1000;
            math1000.MathQuestion1000();
            buttonPressed = true;
        }
        if (x > 57 && x < 108 && y > 38 && y < 73)
        {
            Physics physics200;
            physics200.PhysicsQuestion200();
            buttonPressed = true;
        }
        if (x > 57 && x < 108 && y > 74 && y < 110)
        {
            Physics physics400;
            physics400.PhysicsQuestion400();
            buttonPressed = true;
        }
        if (x > 57 && x < 108 && y > 111 && y < 146)
        {
            Physics physics600;
            physics600.PhysicsQuestion600();
            buttonPressed = true;
        }
        if (x > 57 && x < 108 && y > 147 && y < 182)
        {
            Physics physics800;
            physics800.PhysicsQuestion800();
            buttonPressed = true;
        }
        if (x > 57 && x < 108 && y > 183 && y < 219)
        {
            Physics physics1000;
            physics1000.PhysicsQuestion1000();
            buttonPressed = true;
        }
        if (x > 109 && x < 160 && y > 38 && y < 73)
        {
            Chemistry chemistry200;
            chemistry200.ChemistryQuestion200();
            buttonPressed = true;
        }
        if (x > 109 && x < 160 && y > 74 && y < 110)
        {
            Chemistry chemistry400;
            chemistry400.ChemistryQuestion400();
            buttonPressed = true;
        }
        if (x > 109 && x < 160 && y > 111 && y < 146)
        {
            Chemistry chemistry600;
            chemistry600.ChemistryQuestion600();
            buttonPressed = true;
        }
        if (x > 109 && x < 160 && y > 147 && y < 182)
        {
            Chemistry chemistry800;
            chemistry800.ChemistryQuestion800();
            buttonPressed = true;
        }
        if (x > 109 && x < 160 && y > 183 && y < 219)
        {
            Chemistry chemistry1000;
            chemistry1000.ChemistryQuestion1000();
            buttonPressed = true;
        }
        if (x > 161 && x < 212 && y > 38 && y < 73)
        {
            English english200;
            english200.EnglishQuestion200();
            buttonPressed = true;
        }
        if (x > 161 && x < 212 && y > 74 && y < 110)
        {
            English english400;
            english400.EnglishQuestion400();
            buttonPressed = true;
        }
        if (x > 161 && x < 212 && y > 111 && y < 146)
        {
            English english600;
            english600.EnglishQuestion600();
            buttonPressed = true;
        }
        if (x > 161 && x < 212 && y > 147 && y < 182)
        {
            English english800;
            english800.EnglishQuestion800();
            buttonPressed = true;
        }
        if (x > 161 && x < 212 && y > 183 && y < 219)
        {
            English english1000;
            english1000.EnglishQuestion1000();
            buttonPressed = true;
        }
        if (x > 213 && x < 264 && y > 38 && y < 73)
        {
            History history200;
            history200.HistoryQuestion200();
            buttonPressed = true;
        }
        if (x > 213 && x < 264 && y > 74 && y < 110)
        {
            History history400;
            history400.HistoryQuestion400();
            buttonPressed = true;
        }
        if (x > 213 && x < 264 && y > 111 && y < 146)
        {
            History history600;
            history600.HistoryQuestion600();
            buttonPressed = true;
        }
        if (x > 213 && x < 264 && y > 147 && y < 182)
        {
            History history800;
            history800.HistoryQuestion800();
            buttonPressed = true;
        }
        if (x > 213 && x < 264 && y > 183 && y < 219)
        {
            History history1000;
            history1000.HistoryQuestion1000();
            buttonPressed = true;
        }
        if (x > 265 && x < 316 && y > 38 && y < 73)
        {
            OSU osu200;
            osu200.OSUQuestion200();
            buttonPressed = true;
        }
        if (x > 265 && x < 316 && y > 74 && y < 110)
        {
            OSU osu400;
            osu400.OSUQuestion400();
            buttonPressed = true;
        }
        if (x > 265 && x < 316 && y > 111 && y < 146)
        {
            OSU osu600;
            osu600.OSUQuestion600();
            buttonPressed = true;
        }
        if (x > 265 && x < 316 && y > 147 && y < 182)
        {
            OSU osu800;
            osu800.OSUQuestion800();
            buttonPressed = true;
        }
        if (x > 265 && x < 316 && y > 183 && y < 219)
        {
            OSU osu1000;
            osu1000.OSUQuestion1000();
            buttonPressed = true;
        }
    }
    if(QuestionsLeft == 0){ //If all the questions have been answered, display the results
        
    LCD.Clear();
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Game Over!", 120, 50);
    LCD.WriteAt("Player 1 Score: $" + std::to_string(p1Score), 80, 100);
    LCD.WriteAt("Player 2 Score: $" + std::to_string(p2Score), 80, 140);
//compares scores and displays winner or tie
    if (p1Score > p2Score)
    {
        LCD.WriteAt("Player 1 Wins!", 120, 180);
        p1Wins++;
    if (p1Score > HighScore){
        p1Score = HighScore; //Tracks high score
    }
}
    else if (p2Score > p1Score)
    {
        LCD.WriteAt("Player 2 Wins!", 120, 180);
        p2Wins++;
        if (p2Score > HighScore){
        p2Score = HighScore; //Tracks high score    
    }
}
    else
    {
        LCD.WriteAt("It's a Tie!", 130, 180);
        ties++;
        if (p1Score > HighScore){
        p1Score = HighScore; //Tracks high score
        }
    }

    //Resets scores for next game
p1Score=0; 
p2Score=0;

    LCD.Update();
    LCD.WriteAt("Press ESC to exit to main menu", 80, 200);
    LCD.WriteAt("Press SPACE to play again", 80, 230);
    //runs a loop to allow user to exit to main menu or restart game
    bool buttonPressed = false;
    while (!buttonPressed)
    {
    if (Keyboard.isPressed({KEY_ESCAPE}))
    {
        return; //This will bring the user back to the main menu
        buttonPressed = true;
    }
    else if (Keyboard.isPressed({KEY_SPACE}))
    {
        DrawQuestionBoard(); // This will allow the calling function to restart the game
        buttonPressed = true;
    }
    }
}
}

void mainMenu()
{
    int x, y;
    // Color the whole background of the main menu as dark blue
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);

    // Title
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(40, 5, 240, 40);
    LCD.WriteAt("Jeopardy Battle!", 65, 18);

    // Play game button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(40, 65, 240, 35);
    LCD.WriteAt("Play Game Here", 80, 70);

    // stats button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(40, 110, 240, 35);
    LCD.WriteAt("Statistics", 100, 115);

    // instructions button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(40, 155, 240, 35);
    LCD.WriteAt("Instructions", 90, 160);

    // credits button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(40, 200, 240, 35);
    LCD.WriteAt("Credits", 115, 205);

    // Variable to track if a button has been pressed and allows for mulitple clicks
    bool buttonPressed = false;
    while (!buttonPressed)
    {

        // Wait for touch input
        while (!LCD.Touch(&x, &y))
            ;
        // initiates code after touch
        while (LCD.Touch(&x, &y))
            ;
        if (x > 40 && x < 280)
        {
            if (y > 65 && y < 100)
            {
                // play game button pressed
        
                DrawQuestionBoard();
                buttonPressed = true;
                gameStarted = true;
            }
            else if (y > 110 && y < 145)
            {
                // stats button pressed
                LCD.SetFontColor(BLUE);
                LCD.DrawRectangle(0, 0, 319, 239);
                LCD.FillRectangle(0, 0, 319, 239);
                buttonPressed = true;
                // Write stats text in white
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Statistics:", 100, 5);
                LCD.WriteAt("High Score: ", 100, 60);
                LCD.WriteAt(HighScore, 100, 90);
                LCD.WriteAt("Player 1 Wins: ", 100, 120);
                LCD.WriteAt(p1Wins, 100, 150);
                LCD.WriteAt("Player 2 Wins: ", 100, 180);
                LCD.WriteAt(p2Wins, 100, 210);

                // back button to return to main menu
                LCD.SetFontColor(WHITE);
                LCD.DrawRectangle(5, 200, 60, 30);
                LCD.WriteAt("Back", 10, 205);
                // While loop to go back to main menu
                while (!LCD.Touch(&x, &y))
                    ;
                while (LCD.Touch(&x, &y))
                    ;

                if (x > 5 && x < 65 && y > 200 && y < 230)
                {
                    return;
                }
            }
            else if (y > 155 && y < 190)
            {
                // instructions button pressed
                LCD.SetFontColor(BLUE);
                LCD.DrawRectangle(0, 0, 319, 239);
                LCD.FillRectangle(0, 0, 319, 239);
                buttonPressed = true;
                // display instructions
                LCD.SetFontColor(WHITE);
                LCD.SetFontScale(.5);
                LCD.WriteAt("Instructions:", 100, 10);
                LCD.WriteAt("1. This is a two-player game.", 10, 25);
                LCD.WriteAt("2. Players take turns selecting questions,", 10, 40);
                LCD.WriteAt("   the player that selects first is random.", 10, 55);
                LCD.WriteAt("3. The first player to hit their buzzer answers.", 10, 70);
                LCD.WriteAt("4. Answer correctly to earn points, ", 10, 85);
                LCD.WriteAt("   incorrect answers lose points.", 10, 100);
                LCD.WriteAt("5. Only the first person to buzz can answer.", 10, 115);
                LCD.WriteAt("6. The question disappears after someone buzzes.", 10, 130);
                LCD.WriteAt("7. Multiple answer choices appear after a buzz in.", 10, 145);
                LCD.WriteAt("8. There is a time limit for each question", 10, 160);
                LCD.WriteAt("   and answer, represented with a red bar.", 10, 175);
                LCD.WriteAt("9. The player with the most points at the end wins!", 10, 190);

                // back button to return to main menu
                LCD.SetFontColor(WHITE);
                LCD.SetFontScale(1.0); // increase font scale for back button
                LCD.DrawRectangle(5, 200, 60, 30);
                LCD.WriteAt("Back", 10, 205);

                // While loop to go back to main menu
                while (!LCD.Touch(&x, &y))
                    ;
                while (LCD.Touch(&x, &y))
                    ;

                if (x > 5 && x < 65 && y > 200 && y < 230)
                {
                    LCD.SetFontScale(1.0); // reset font scale
                    return;
                }
            }
            else if (y > 200 && y < 235)
            {
                // credits button pressed
                LCD.SetFontColor(BLUE);
                LCD.DrawRectangle(0, 0, 319, 239);
                LCD.FillRectangle(0, 0, 319, 239);
                buttonPressed = true;
                // Write credits text in white
                LCD.SetFontColor(WHITE);
                LCD.WriteAt("Credits:", 100, 5);
                LCD.WriteAt("Developers:", 80, 50);
                LCD.WriteAt("Matthew Bloom", 80, 80);
                LCD.WriteAt("Joshua Lam", 80, 110);
                LCD.WriteAt("Inspired by", 80, 140);
                LCD.WriteAt("Jeopardy!", 90, 170);

                // Create a back button that when pressed, calls the mainMenu function
                LCD.SetFontColor(WHITE);
                LCD.DrawRectangle(5, 200, 60, 30);
                LCD.WriteAt("Back", 10, 205);

                // While loop to go back to main menu

                while (!LCD.Touch(&x, &y))
                    ;
                while (LCD.Touch(&x, &y))
                    ;

                if (x > 5 && x < 65 && y > 200 && y < 230)
                {
                    return;
                }
            }
        }
    }
}

int main()
{

    while (1)
    {
       
        // allows return to work instead of using mainMenu() repeatedly
        while (!gameStarted){
        mainMenu();
    }
         if (QuestionsLeft !=0){
            DrawQuestionBoard();
        }
        LCD.Update();
    }
}


