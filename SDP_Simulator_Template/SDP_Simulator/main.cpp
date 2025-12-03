#include "FEHLCD.h"
#include "FEHImages.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"
#include "FEHRandom.h"

void mainMenu();
void DrawQuestionBoard();
//creates a class for each category of questions
class Math
{
private:
    std::string answer;
    int Value;

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
    answer = "4";
    Value = 200;

    // creates a timer bar at the top of the screen
    int x = 319;
    while (x >= 0)
    {
        
            LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }

}
void Math::MathQuestion400()
{
    int x = 319;
    while (x >= 0)
    {
        
            LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "8";
    Value = 400;
}
void Math::MathQuestion600()
{
 int x = 319;
    while (x >= 0)
    {
        
            LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "4";
    Value = 600;
}
void Math::MathQuestion800()
{
int x = 319;
    while (x >= 0)
    {
        
            LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "16";
    Value = 800;
}
void Math::MathQuestion1000()
{
    int x = 319;
    while (x >= 0)
    {
        
            LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "0";
    Value = 1000;
}

void Physics::PhysicsQuestion200()
{       
int x = 319;
    while (x >= 0)
    {
        
            LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    Value = 200;
}
void Physics::PhysicsQuestion400()
{
      
int x = 319;
    while (x >= 0)
    {
        
            LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 400;
}
void Physics::PhysicsQuestion600()
{
      
int x = 319;
    while (x >= 0)
    {
        
            LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 600;
}
void Physics::PhysicsQuestion800()
{
      
int x = 319;
    while (x >= 0)
    {
        
            LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    Value = 800;
}
void Physics::PhysicsQuestion1000()
{
 
int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 1000;
}

void Chemistry::ChemistryQuestion200()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 200;
}
void Chemistry::ChemistryQuestion400()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 400;
}
void Chemistry::ChemistryQuestion600()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 600;
}
void Chemistry::ChemistryQuestion800()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 800;
}
void Chemistry::ChemistryQuestion1000()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 1000;
}

void History::HistoryQuestion200()
{

    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 200;
}
void History::HistoryQuestion400()
{

    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 400;
}
void History::HistoryQuestion600()
{

    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 600;
}
void History::HistoryQuestion800()
{

    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 800;
}
void History::HistoryQuestion1000()
{

    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 1000;
}

void English::EnglishQuestion200()
{
        int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 200;
}
void English::EnglishQuestion400()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 400;
}
void English::EnglishQuestion600()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 600;
}
void English::EnglishQuestion800()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 800;
}
void English::EnglishQuestion1000()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(150);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 1000;
}

void OSU::OSUQuestion200()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 200;
}
void OSU::OSUQuestion400()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 400;
}
void OSU::OSUQuestion600()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 600;
}
void OSU::OSUQuestion800()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 800;
}
void OSU::OSUQuestion1000()
{
    int x = 319;
    while (x >= 0)
    {    
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);
 
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Placeholder", 80, 100);
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(0, 0, x, 10);
        LCD.FillRectangle(0, 0, x, 10);
        x -= 11;
        Sleep(230);
        LCD.Update();
        LCD.Clear();
    }
    answer = "Placeholder";
    Value = 1000;
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
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(5, 38, 50, 34);
    LCD.FillRectangle(5, 38, 50, 34);

    LCD.DrawRectangle(57, 38, 50, 34);
    LCD.FillRectangle(57, 38, 50, 34);

    LCD.DrawRectangle(109, 38, 50, 34);
    LCD.FillRectangle(109, 38, 50, 34);

    LCD.DrawRectangle(161, 38, 50, 34);
    LCD.FillRectangle(161, 38, 50, 34);

    LCD.DrawRectangle(213, 38, 50, 34);
    LCD.FillRectangle(213, 38, 50, 34);

    LCD.DrawRectangle(265, 38, 50, 34);
    LCD.FillRectangle(265, 38, 50, 34);

    // Draw $200 in each rectangle
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("$200", 15, 50);
    LCD.WriteAt("$200", 67, 50);
    LCD.WriteAt("$200", 119, 50);
    LCD.WriteAt("$200", 171, 50);
    LCD.WriteAt("$200", 223, 50);
    LCD.WriteAt("$200", 275, 50);

    // Set color back to blue for next rows
    LCD.SetFontColor(BLUE);

    // Row 3 of rectangles: $400
    // x coordiante 5 +52  y corrdinate 74
    // Width 50 Height 34
    LCD.DrawRectangle(5, 74, 50, 34);
    LCD.FillRectangle(5, 74, 50, 34);

    LCD.DrawRectangle(57, 74, 50, 34);
    LCD.FillRectangle(57, 74, 50, 34);

    LCD.DrawRectangle(109, 74, 50, 34);
    LCD.FillRectangle(109, 74, 50, 34);

    LCD.DrawRectangle(161, 74, 50, 34);
    LCD.FillRectangle(161, 74, 50, 34);

    LCD.DrawRectangle(213, 74, 50, 34);
    LCD.FillRectangle(213, 74, 50, 34);

    LCD.DrawRectangle(265, 74, 50, 34);
    LCD.FillRectangle(265, 74, 50, 34);

    // Draw $400 in each rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("$400", 15, 86);
    LCD.WriteAt("$400", 67, 86);
    LCD.WriteAt("$400", 119, 86);
    LCD.WriteAt("$400", 171, 86);
    LCD.WriteAt("$400", 223, 86);
    LCD.WriteAt("$400", 275, 86);

    // Set color back to blue for next rows
    LCD.SetFontColor(BLUE);

    // Row 4 of rectangles: $600
    // x coordiante 5 +52  y corrdinate 110
    // Width 50 Height 34
    LCD.DrawRectangle(5, 110, 50, 34);
    LCD.FillRectangle(5, 110, 50, 34);

    LCD.DrawRectangle(57, 110, 50, 34);
    LCD.FillRectangle(57, 110, 50, 34);

    LCD.DrawRectangle(109, 110, 50, 34);
    LCD.FillRectangle(109, 110, 50, 34);

    LCD.DrawRectangle(161, 110, 50, 34);
    LCD.FillRectangle(161, 110, 50, 34);

    LCD.DrawRectangle(213, 110, 50, 34);
    LCD.FillRectangle(213, 110, 50, 34);

    LCD.DrawRectangle(265, 110, 50, 34);
    LCD.FillRectangle(265, 110, 50, 34);

    // Draw $600 in each rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("$600", 15, 122);
    LCD.WriteAt("$600", 67, 122);
    LCD.WriteAt("$600", 119, 122);
    LCD.WriteAt("$600", 171, 122);
    LCD.WriteAt("$600", 223, 122);
    LCD.WriteAt("$600", 275, 122);

    // Set color back to blue for next rows
    LCD.SetFontColor(BLUE);

    // Row 5 of rectangles: $800
    // x coordiante 5 +52  y corrdinate 146
    // Width 50 Height 34
    LCD.DrawRectangle(5, 146, 50, 34);
    LCD.FillRectangle(5, 146, 50, 34);

    LCD.DrawRectangle(57, 146, 50, 34);
    LCD.FillRectangle(57, 146, 50, 34);

    LCD.DrawRectangle(109, 146, 50, 34);
    LCD.FillRectangle(109, 146, 50, 34);

    LCD.DrawRectangle(161, 146, 50, 34);
    LCD.FillRectangle(161, 146, 50, 34);

    LCD.DrawRectangle(213, 146, 50, 34);
    LCD.FillRectangle(213, 146, 50, 34);

    LCD.DrawRectangle(265, 146, 50, 34);
    LCD.FillRectangle(265, 146, 50, 34);

    // Draw $800 in each rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("$800", 15, 158);
    LCD.WriteAt("$800", 67, 158);
    LCD.WriteAt("$800", 119, 158);
    LCD.WriteAt("$800", 171, 158);
    LCD.WriteAt("$800", 223, 158);
    LCD.WriteAt("$800", 275, 158);

    // Set color back to blue for next rows
    LCD.SetFontColor(BLUE);

    // Row 6 of rectangles: $1000
    // x coordiante 5 +52  y corrdinate 182
    // Width 50 Height 34
    LCD.DrawRectangle(5, 182, 50, 34);
    LCD.FillRectangle(5, 182, 50, 34);

    LCD.DrawRectangle(57, 182, 50, 34);
    LCD.FillRectangle(57, 182, 50, 34);

    LCD.DrawRectangle(109, 182, 50, 34);
    LCD.FillRectangle(109, 182, 50, 34);

    LCD.DrawRectangle(161, 182, 50, 34);
    LCD.FillRectangle(161, 182, 50, 34);

    LCD.DrawRectangle(213, 182, 50, 34);
    LCD.FillRectangle(213, 182, 50, 34);

    LCD.DrawRectangle(265, 182, 50, 34);
    LCD.FillRectangle(265, 182, 50, 34);

    // Draw $1000 in each rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("$1000", 15, 194);
    LCD.WriteAt("$1000", 67, 194);
    LCD.WriteAt("$1000", 119, 194);
    LCD.WriteAt("$1000", 171, 194);
    LCD.WriteAt("$1000", 223, 194);
    LCD.WriteAt("$1000", 275, 194);

    // Display Player 1 and player 2 scores at the bottom of the screen
    int p1Score = 0, p2Score = 0;

    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt("P1 Score: ", 10, 223);
    LCD.WriteAt(p1Score, 70, 223);
    LCD.WriteAt("P2 Score:", 220, 223);
    LCD.WriteAt(p2Score, 280, 223);

    int x, y;
//this bool and loopallows clicks that do not correspond to a button to be ignored (a click on empty space will not softlock the user)
      bool buttonPressed = false;
      while (!buttonPressed)
      {
    while (!LCD.Touch(&x, &y));
    // waits for touch input before proceeding
    while (LCD.Touch(&x, &y));
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
}


void mainMenu()
{
    int x, y;
    // Initialize stats variables
    int highScore = 0.0;
    int player1Wins = 0;
    int player2Wins = 0;

    // Color the whole background of the main menu as dark blue
    LCD.SetFontColor(BLUE);
    LCD.DrawRectangle(0, 0, 319, 239);
    LCD.FillRectangle(0, 0, 319, 239);

    // Title
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(40, 5, 240, 40);
    LCD.WriteAt("Jeopardy! Battle", 65, 18);

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
    while (!LCD.Touch(&x, &y));
    // initiates code after touch
    while (LCD.Touch(&x, &y));
    if (x > 40 && x < 280)
    {
        if (y > 65 && y < 100)
        {
            // play game button pressed
            DrawQuestionBoard();
            buttonPressed = true;
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
            LCD.WriteAt(highScore, 100, 90);
            LCD.WriteAt("Player 1 Wins: ", 100, 120);
            LCD.WriteAt(player1Wins, 100, 150);
            LCD.WriteAt("Player 2 Wins: ", 100, 180);
            LCD.WriteAt(player2Wins, 100, 210);

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
            LCD.SetFontScale(0.5);
            LCD.WriteAt("Instructions:", 100, 20);
            LCD.WriteAt("1. This is a one or two-player game.", 10, 35);
            LCD.WriteAt("2. Players take turns selecting questions.", 10, 60);
            LCD.WriteAt("3. The first player to hit their buzzer answers.", 10, 85);
            LCD.WriteAt("4. Answer questions to earn points, ", 10, 110);
            LCD.WriteAt(" incorrect answers lose points.", 30, 135);
            LCD.WriteAt("5. The red bar at the top is the time limit.", 10, 160);
            LCD.WriteAt("6. The player with the most points at the end wins!", 10, 185);

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
            LCD.WriteAt("Developers:", 100, 60);
            LCD.WriteAt("Matthew Bloom", 100, 90);
            LCD.WriteAt("Joshua Lam", 100, 120);

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
        //allows return to work instead of using mainMenu() repeatedly
           mainMenu();
        LCD.Update();
    }
}
