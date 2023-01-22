// this code does not include the song, timing, etc. is done on a separate .txt file

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream> 

typedef struct
{
    float Lifetime;
}Timer;

// start or restart a timer with a specific lifetime
void StartTimer(Timer* timer, float lifetime)
{
    if (timer != NULL)
        timer->Lifetime = lifetime;
}

// update a timer with the current frame time

// check if a timer is done.
bool TimerDone(Timer* timer)
{
    if (timer != NULL)
        return timer->Lifetime <= 0;

	return false;
}

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING, SCORE } GameScreen;
GameScreen currentScreen = LOGO;
  int framesCounter = 0;

int main()
{
    int windowWidth = 800, windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "Cirno Fever");
    SetTargetFPS(60);

    InitAudioDevice();

    Music music1 = LoadMusicStream("cirno.mp3");
    float volume = 0.5f;

    Sound sound1 = LoadSound("clap.wav");

    Texture texture = LoadTexture("cirno bg 2.png");
    Texture texture2 = LoadTexture("cirno game bg.png");
    Texture texture3 = LoadTexture("cirno score bg.png");

    //score
    int score = 0;
    float grade;

    //timer for song
    Timer songTimer = {0};
    Timer noteTimer = {0};
    Timer noteTimerf = {0};
    Timer noteTimerj = {0};
    Timer noteTimerk = {0};
    Timer noteTimerdl = {0};
    Timer noteTimerfl = {0};
    Timer noteTimerjl = {0};
    Timer noteTimerkl = {0};

    //lifetime for song
    float songLife = 59.0f;
    float noteLife = 3.0f;
    float noteLifef = 3.0f;
    float noteLifej = 3.0f;
    float noteLifek = 3.0f;
    float noteLifedl = 3.0f;
    float noteLifefl = 3.0f;
    float noteLifejl = 3.0f;
    float noteLifekl = 3.0f;

    //importing notes variables
    int d = 0;
    int f = 0;
    int j = 0;
    int k = 0;
    int arr[100];
    int arrf[100];
    int arrj[100];
    int arrk[100];

    int dl = 0;
    int fl = 0;
    int jl = 0;
    int kl = 0;
    int arrdl[100];
    int arrfl[100];
    int arrjl[100];
    int arrkl[100];

    using namespace std;

    std::ifstream file1("dtimestamps.txt");
    std::ifstream file2("ftimestamps.txt");
    std::ifstream file3("jtimestamps.txt");
    std::ifstream file4("ktimestamps.txt");

    std::ifstream file5("dlong.txt");
    std::ifstream file6("flong.txt");
    std::ifstream file7("jlong.txt");
    std::ifstream file8("klong.txt");

    //importing single notes

    if(file1.is_open())
    {

        for(int d = 0; d < 100; ++d)
        {
            file1 >> arr[d];
        }
    }



    if(file2.is_open())
    {

        for(int f = 0; f < 100; ++f)
        {
            file2 >> arrf[f];
        }
    }

    if(file3.is_open())
    {

        for(int j = 0; j < 100; ++j)
        {
            file3 >> arrj[j];
        }
    }

    if(file4.is_open())
    {

        for(int k = 0; k < 100; ++k)
        {
            file4 >> arrk[k];
        }
    }

    if(file5.is_open())
    {

        for(int dl = 0; dl < 100; ++dl)
        {
            file5 >> arrdl[dl];
        }
    }



    if(file6.is_open())
    {

        for(int fl = 0; fl < 100; ++fl)
        {
            file6 >> arrfl[fl];
        }
    }

    if(file7.is_open())
    {

        for(int jl = 0; jl < 100; ++jl)
        {
            file7 >> arrjl[jl];
        }
    }

    if(file8.is_open())
    {

        for(int kl = 0; kl < 100; ++kl)
        {
            file8 >> arrkl[kl];
        }
    }

    //rectangles
    //rectangles
    float boxAy = -20;
    Rectangle boxA = { 250, boxAy, 75, 20 };
    float boxFy = -20;
    Rectangle boxF = { 325, boxFy, 75, 20 };
    float boxJy = -20;
    Rectangle boxJ = { 400, boxJy, 75, 20 };
    float boxKy = -20;
    Rectangle boxK = { 475, boxKy, 75, 20 };
    
    float boxA1y = -20;
    Rectangle boxA1 = { 252, boxA1y, 72, 100 };
    float boxA2y = -20;
    Rectangle boxA2 = { 327, boxA2y, 72, 100 };
    float boxA3y = -20;   
    Rectangle boxA3 = { 402, boxA3y, 72, 100 };
    float boxA4y = -20;
    Rectangle boxA4 = { 477, boxA4y, 72, 100 };




    // Box B: Mouse moved box
    Rectangle boxB = { 250, 580, 300, 40 };

    Rectangle boxCollision = { 0 }; // Collision rectangle

    int screenUpperLimit = 40;      // Top menu limits

    bool pause = false;             // Movement pause
    bool collision = false;         // Collision detection
    bool collision1 = false;
    bool collision2 = false;
    bool collision3 = false;
    bool collision4 = false;
    bool collision5 = false;
    bool collision6 = false;
    bool collision7 = false;




    while (!WindowShouldClose())
    {

        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 2)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) )
                {
                    currentScreen = GAMEPLAY;
                }
                if (IsKeyPressed(KEY_O)){
                    currentScreen = ENDING;
                }
            } break;
            case GAMEPLAY:
            {
                // TODO: Update GAMEPLAY screen variables here
                if (songLife <= 0.0f)
                {
                    currentScreen = SCORE;
                }
            } break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = TITLE;
                }
            } break;
            case SCORE:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = GAMEPLAY;
                }
            }
            default: break;
        }

        
      

        // Make sure Box B does not go out of move area limits
        if ((boxB.x + boxB.width) >= GetScreenWidth()) boxB.x = GetScreenWidth() - boxB.width;
        else if (boxB.x <= 0) boxB.x = 0;

        if ((boxB.y + boxB.height) >= GetScreenHeight()) boxB.y = GetScreenHeight() - boxB.height;
        else if (boxB.y <= screenUpperLimit) boxB.y = (float)screenUpperLimit;

        // Check boxes collision
        collision = CheckCollisionRecs(boxA, boxB);
        collision1 = CheckCollisionRecs(boxF, boxB);
        collision2 = CheckCollisionRecs(boxJ, boxB);
        collision3 = CheckCollisionRecs(boxK, boxB);
        collision4 = CheckCollisionRecs(boxA1, boxB);
        collision5 = CheckCollisionRecs(boxA2, boxB);
        collision6 = CheckCollisionRecs(boxA3, boxB);
        collision7 = CheckCollisionRecs(boxA4, boxB);




        // Get collision rectangle (only on collision)
        if (collision) boxCollision = GetCollisionRec(boxA, boxB);

        // Pause Box A movement
        
        if (IsKeyPressed(KEY_ONE))
        {
                PlayMusicStream(music1);
                StartTimer(&songTimer, songLife);
        }


        if (!TimerDone(&songTimer))
        {
            // tick our timer
            songLife -= GetFrameTime();
            std::cout<<songLife;

        }


        if (IsMusicStreamPlaying(music1))
        {
            UpdateMusicStream(music1); 
           
        }

     

        if (songLife <= 0){
            StopMusicStream(music1);
        }
        

        //displaying score
        stringstream str_s;
        str_s << score;

        string score_string;
        str_s>> score_string;
        const char *c = score_string.c_str();

        BeginDrawing();

        ClearBackground(WHITE);

        switch(currentScreen)
        {

        case LOGO:
                {
                    // TODO: Draw LOGO screen here!
                   
                    DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                    DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);
                    

                } break;

                 case TITLE:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
                    DrawTexture(texture, 0, 0, WHITE);
                    DrawText("CIRNO FEVER", 20, 20, 40, BLUE);
                    DrawText("PRESS ENTER TO PLAY OR O FOR OPTIONS", 50, 220, 20, BLACK);

                } break;

        case GAMEPLAY:
        {

        //Background
        DrawTexture(texture2, 0, 0, WHITE);
//----------------------spawning rectangle
       if ((arr[d] + 4) > songLife){

            if (songLife > (arr[d] + 3)){
                StartTimer(&noteTimer, noteLife);
               
            }
        }

        //moving it to the next timestamp
         if ((arr[d] + 1) > songLife){

            if (songLife > (arr[d] - 1)){
            
                d += 1;
            }
        }
        //moving notes
        if (!TimerDone(&noteTimer)){
            boxA.y += (180 * GetFrameTime());
            noteLife -= GetFrameTime();            
        }

       
        //reepositioning notes
        if (TimerDone(&noteTimer)){
            boxA.y = -20;
            noteLife = 3.0f;
        }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if ((arrf[f] + 4) > songLife){

            if (songLife > (arrf[f] + 3)){
                StartTimer(&noteTimerf, noteLifef);
                
            }
        }

        //moving it to the next timestamp
         if ((arrf[f] + 1) > songLife){

            if (songLife > (arrf[f] - 1)){
               
                f += 1;
            }
        }
        //moving notes
        if (!TimerDone(&noteTimerf)){
            boxF.y += (180 * GetFrameTime());
            noteLifef -= GetFrameTime();            
        }

       
        //reepositioning notes
        if (TimerDone(&noteTimerf)){
            boxF.y = -20;
            noteLifef = 3.0f;
        }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if ((arrj[j] + 4) > songLife){

            if (songLife > (arrj[j] + 3)){
                StartTimer(&noteTimerj, noteLifej);
             
            }
        }

        //moving it to the next timestamp
         if ((arrj[j] + 1) > songLife){

            if (songLife > (arrj[j] - 1)){
    
                j += 1;
            }
        }
        //moving notes
        if (!TimerDone(&noteTimerj)){
            boxJ.y += (180 * GetFrameTime());
            noteLifej -= GetFrameTime();            
        }

       
        //reepositioning notes
        if (TimerDone(&noteTimerj)){
            boxJ.y = -20;
            noteLifej = 3.0f;
        }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if ((arrk[k] + 4) > songLife){

            if (songLife > (arrk[k] + 3)){
                StartTimer(&noteTimerk, noteLifek);
           
            }
        }

        //moving it to the next timestamp
         if ((arrk[k] + 1) > songLife){

            if (songLife > (arrk[k] - 1)){
                k += 1;
            }
        }
        //moving notes
        if (!TimerDone(&noteTimerk)){
            boxK.y += (180 * GetFrameTime());
            noteLifek -= GetFrameTime();            
        }

       
        //reepositioning notes
        if (TimerDone(&noteTimerk)){
            boxK.y = -20;
            noteLifek = 3.0f;
        }

//----------------------spawning rectangle LONG
       if ((arrdl[dl] + 4) > songLife){

            if (songLife > (arrdl[dl] + 3)){
                StartTimer(&noteTimerdl, noteLifedl);
                

                dl += 1 ;
            }
        }

        //moving it to the next timestamp
         if ((arrdl[dl] + 1) > songLife){

            if (songLife > (arrdl[dl] - 1)){
               
            }
        }
        //moving notes
        if (!TimerDone(&noteTimerdl)){
            boxA1.y += (180 * GetFrameTime());
            noteLifedl -= GetFrameTime();            
        }

       
        //reepositioning notes
        if (TimerDone(&noteTimerdl)){
            boxA1.y = -100;
            noteLifedl = 3.0f;
        }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if ((arrfl[fl] + 4) > songLife){

            if (songLife > (arrfl[fl] + 3)){
                StartTimer(&noteTimerfl, noteLifefl);
               

                fl += 1 ;

            }
        }

        //moving it to the next timestamp
         if ((arrfl[fl] + 1) > songLife){

            if (songLife > (arrfl[fl] - 1)){
                
            }
        }
        //moving notes
        if (!TimerDone(&noteTimerfl)){
            boxA2.y += (180 * GetFrameTime());
            noteLifefl -= GetFrameTime();            
        }

       
        //reepositioning notes
        if (TimerDone(&noteTimerfl)){
            boxA2.y = -100;
            noteLifefl = 3.0f;
        }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if ((arrjl[jl] + 4) > songLife){

            if (songLife > (arrjl[jl] + 3)){
                StartTimer(&noteTimerjl, noteLifejl);
               
                jl += 1 ;
                
            }
        }

        //moving notes
        if (!TimerDone(&noteTimerjl)){
            boxA3.y += (180 * GetFrameTime());
            noteLifejl -= GetFrameTime();            
        }

       
        //reepositioning notes
        if (TimerDone(&noteTimerjl)){
            boxA3.y = -100;
            noteLifejl = 3.0f;
        }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if ((arrkl[kl] + 4) > songLife){

            if (songLife > (arrkl[kl] + 3)){
                StartTimer(&noteTimerkl, noteLifekl);

                kl += 1;
            }
        }

 
        //moving notes
        if (!TimerDone(&noteTimerkl)){
            boxA4.y += (180 * GetFrameTime());
            noteLifekl -= GetFrameTime();            
        }

       
        //reepositioning notes
        if (TimerDone(&noteTimerk)){
            boxA4.y = -100;
            noteLifekl = 3.0f;
        }


        //--------------------

         std::cout << songLife << "|||||||||||||||" << noteLife << std::endl;

        if (pause){
            DrawText("GAME PAUSED", 290, 220, 30, RED);
        }

        DrawText(c, 20, 450, 50, BLUE);
        DrawText("Score", 20, 420, 20, BLUE);

        if (songLife >= 57) {
             DrawText("Press 1 to start", 20, 200, 40, BLUE);
        }
       

        DrawRectangle(250, 0, 1.5, GetScreenHeight(), BLACK);
        DrawRectangle(325, 0, 1.5, GetScreenHeight(), BLACK);

        DrawRectangle(325, 0, 1.5, GetScreenHeight(), BLACK);
        DrawRectangle(400, 0, 1.5, GetScreenHeight(), BLACK);

        DrawRectangle(400, 0, 1.5, GetScreenHeight(), BLACK);
        DrawRectangle(475, 0, 1.5, GetScreenHeight(), BLACK);

        DrawRectangle(475, 0, 1.5, GetScreenHeight(), BLACK);
        DrawRectangle(550, 0, 1.5, GetScreenHeight(), BLACK);

        DrawRectangle(250, 580, 300, 50, BLACK);



        //drawing the board
        DrawRectangleRec(boxB, BLACK);
        DrawRectangleRec(boxA, GOLD);
        DrawRectangleRec(boxF, GOLD);
        DrawRectangleRec(boxJ, GOLD);
        DrawRectangleRec(boxK, GOLD);
        DrawRectangleRec(boxA1, GOLD);
        DrawRectangleRec(boxA2, GOLD);
        DrawRectangleRec(boxA3, GOLD);
        DrawRectangleRec(boxA4, GOLD);


        DrawText("D", 287.5, 580, 20, WHITE);
        DrawText("F", 362.5, 580, 20, WHITE);
        DrawText("J", 437.5, 580, 20, WHITE);
        DrawText("K", 512.5, 580, 20, WHITE);


            if (collision && IsKeyPressed(KEY_D))
            {
                
                score += 15;
                boxA.y = 10000;
                PlaySound(sound1);

            }

            if (collision1 && IsKeyPressed(KEY_F))
            {
                
                score += 15;
                boxF.y = 10000;
                PlaySound(sound1);

            }

            if (collision2 && IsKeyPressed(KEY_J))
            {
                
                score += 15;
                boxJ.y = 10000;
                PlaySound(sound1);

            }

            if (collision3 && IsKeyPressed(KEY_K))
            {
                
                score += 15;
                boxK.y = 10000;
                PlaySound(sound1);

            }

        //--------- for long buttons
            if (collision4 && IsKeyDown(KEY_D))
            {
                
                PlaySound(sound1);
                score += 1;

            }

             if (collision5 && IsKeyDown(KEY_F))
            {
                
                score += 1;
                PlaySound(sound1);

            }

             if (collision6 && IsKeyDown(KEY_J))
            {
                
                PlaySound(sound1);
                
                score += 1;

            }

             if (collision7 && IsKeyDown(KEY_K))
            {
                PlaySound(sound1);
                
                score += 1;

            }

            DrawFPS(10, 10);        
                } break;

                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);
                    DrawText("OPTIONS", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                     if (IsKeyPressed(KEY_DOWN) && volume != 0.0f) {
                    volume = volume -0.25f;
                    SetMusicVolume(music1, volume);                 // Set volume for music (1.0 is max level)
                    }

                    if (IsKeyPressed(KEY_DOWN) && volume == 0.0f) {
                    volume = 0.0f;
                    SetMusicVolume(music1, volume);                 // Set volume for music (1.0 is max level)
                    }

                    if (IsKeyPressed(KEY_UP) && volume != 1.0f) {
                    volume = volume +0.25f;
                    SetMusicVolume(music1, volume);                 // Set volume for music (1.0 is max level)
                    }

                    if (IsKeyPressed(KEY_UP) && volume == 1.0f) {
                    volume = 1.0f;
                    SetMusicVolume(music1, volume);                 // Set volume for music (1.0 is max level)
                    }

                    if (volume == 0.25f){
                        DrawRectangle(360, 520, 18, 18, GREEN);
                    }

                    if (volume == 0.5f){
                        DrawRectangle(360, 520, 18, 18, GREEN);
                        DrawRectangle(380, 520, 18, 18, YELLOW);
                    }
                    
                    if (volume == 0.75f){
                        DrawRectangle(360, 520, 18, 18, GREEN);
                        DrawRectangle(380, 520, 18, 18, YELLOW);
                        DrawRectangle(400, 520, 18, 18, ORANGE);
                    }

                    if (volume == 1.0f){
                        DrawRectangle(360, 520, 18, 18, GREEN);
                        DrawRectangle(380, 520, 18, 18, YELLOW);
                        DrawRectangle(400, 520, 18, 18, ORANGE);
                        DrawRectangle(420, 520, 18, 18, RED);
                    }

                    DrawText("Up for volume up, Down for volume down", 10, 520, 18, DARKBLUE);
                    DrawText("Right/Left for audio panning right/left", 10, 550, 18, DARKBLUE);



                } break;

                case SCORE:
                {
                    // TODO: Draw Score
                    DrawTexture(texture3, 0, 0, WHITE);

                    if (score >= 700){
                        DrawText("S", 300, 166, 220, GOLD);
                    }

                    if (699 >= score){
                        if (score >= 500){
                            DrawText("A", 300, 166, 220, GREEN);
                        }
                    }

                    if (499 >= score){
                        if (score >= 300){
                            DrawText("B", 300, 166, 220, BLUE);
                        }
                    }
                    
                    if (299 >= score){
                        if(score >= 200)
                        {
                            DrawText("C", 300, 166, 220, ORANGE);
                        }
                    }

                    if (199 >= score){
                        DrawText("D", 300, 166, 220, RED);
                    }

                    DrawText("SLAY YOU GOT", 120, 126, 40, LIGHTGRAY);
                    DrawText(c, 120, 166, 110, LIGHTGRAY);

             
                }
                break;
                default: break;   } 



        EndDrawing();
    }
    
    UnloadMusicStream(music1);

    UnloadSound(sound1);

    UnloadTexture(texture);
    UnloadTexture(texture2);


    CloseAudioDevice();

    CloseWindow();

    return 0;
}

