#include "FEHLCD.h"
#include "FEHImages.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"
#include "FEHRandom.h"

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
//stops code until there is a touch
    while (!LCD.Touch(&x, &y)); 
    //initiates code after touch
while (LCD.Touch(&x, &y));
        if (x > 40 && x < 280)
        {
            if (y > 65 && y < 100)
            {
                // play game button pressed
                LCD.SetFontColor(BLUE);
                LCD.DrawRectangle(0, 0, 319, 239);
                LCD.FillRectangle(0, 0, 319, 239);
                
            }
            else if (y > 110 && y < 145)
            {
                // stats button pressed
                LCD.SetFontColor(BLUE);
                LCD.DrawRectangle(0, 0, 319, 239);
                LCD.FillRectangle(0, 0, 319, 239);
                //Write stats text in white


                
                //back button to return to main menu
                LCD.SetFontColor(WHITE);
                LCD.DrawRectangle(5, 200, 60, 30);
                LCD.WriteAt("Back", 10, 205);
                // While loop to go back to main menu
                 while(!LCD.Touch(&x, &y));
                while(LCD.Touch(&x, &y));
                
                    if (x > 5 && x < 65 && y > 200 && y < 230)
                    {
                        mainMenu();
                    }
            }
            else if (y > 155 && y < 190)
            {
                // instructions button pressed
                LCD.SetFontColor(BLUE);
                LCD.DrawRectangle(0, 0, 319, 239);
                LCD.FillRectangle(0, 0, 319, 239);

            
                //back button to return to main menu
                LCD.SetFontColor(WHITE);
                LCD.DrawRectangle(5, 200, 60, 30);
                LCD.WriteAt("Back", 10, 205);
                // While loop to go back to main menu
                 while(!LCD.Touch(&x, &y));
                while(LCD.Touch(&x, &y));
                
                    if (x > 5 && x < 65 && y > 200 && y < 230)
                    {
                        mainMenu();
                    }
            }
            else if (y > 200 && y < 235)
            {
                // credits button pressed
                LCD.SetFontColor(BLUE);
                LCD.DrawRectangle(0, 0, 319, 239);
                LCD.FillRectangle(0, 0, 319, 239);

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
            
                while(!LCD.Touch(&x, &y));
                while(LCD.Touch(&x, &y));
                
                    if (x > 5 && x < 65 && y > 200 && y < 230)
                    {
                        mainMenu();
                    }
                
            }
        }
    }


int main()
{

    mainMenu();

    while (1)
    {
        LCD.Update();
    }
}