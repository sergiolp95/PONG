#include "raylib.h"
#define PUNTMULTIPLICADOR 999
int main()
{
    // Inicializar variables
    //--------------------------------------------------------------------------------------
    int screenWidth = 1700;
    int screenHeight = 900;
    
    Rectangle rectangulo1;
    rectangulo1.x = 0;
    rectangulo1.y = 350;
    rectangulo1.height = 200;
    rectangulo1.width = 20;
    
    Rectangle rectangulo2;
    rectangulo2.x = 1680;
    rectangulo2.y = 350;
    rectangulo2.height = 200;
    rectangulo2.width = 20;
    
    
    
    int puntuacion = 00000000;
    int puntuacionmax = 00000000;
    int lives = 3;
    int puntuacion2 = 00000000;
    int puntuacionmax2 = 00000000;
    int lives2 = 3;
    int radio = 20;
    
    int min = -12;
    int max = 12;
    
    
    
    
    double velocidady = GetRandomValue(min,max);
    double velocidadx = GetRandomValue(min,max);
    
    InitWindow(screenWidth, screenHeight, "Juego Sergio López PONG");
    
    Texture2D textura = LoadTexture("resources/cara.png");
    textura.height = 40;
    textura.width = 40;
    
    Texture2D textura2 = LoadTexture("resources/fondo.png");
    textura2.height = 50 ;
    textura2.width = 150;
    
    Texture2D textura3 = LoadTexture("resources/fondo2.png");
    textura3.height = 600;
    textura3.width = 600;
    
    Texture2D texturagoku = LoadTexture("resources/player1.png");
    texturagoku.height = 450;
    texturagoku.width = 250;
    
    Texture2D texturagoku2 = LoadTexture("resources/player2.png");
    texturagoku2.height = 400;
    texturagoku2.width = 280;
    
    Texture2D texturaciudad = LoadTexture("resources/ciudad.png");
    texturaciudad.height = 500;
    texturaciudad.width = 1800;
    
    Texture2D texturacalavera = LoadTexture("resources/calavera.png");
    texturacalavera.height = 180;
    texturacalavera.width = 140;
    
    Texture2D texturaVS = LoadTexture("resources/vs.png");
    texturaVS.height = 200;
    texturaVS.width = 150;
    
    Texture2D texturaFirma = LoadTexture("resources/firma.png");
    texturaFirma.height = 80;
    texturaFirma.width = 90;
    
    Texture2D texturaBocadillo1 = LoadTexture("resources/bocadillo1.png");
    texturaBocadillo1.height = 80;
    texturaBocadillo1.width = 110;
    
    Texture2D texturaBocadillo2 = LoadTexture("resources/bocadillo2.png");
    texturaBocadillo2.height = 90;
    texturaBocadillo2.width = 130;
    
    Texture2D texturaRectangulo = LoadTexture("resources/rectangulo.png");
    texturaRectangulo.height = 215;
    texturaRectangulo.width = 20;
    
    
    
    
    
    //Texture2D texturaplayer1
   

    Vector2 ballPosition = { screenWidth/2, screenHeight/2 };

    SetTargetFPS(60);       // Set target frames-per-second
    //--------------------------------------------------------------------------------------
    while ((!IsKeyDown(KEY_ENTER)) && (!WindowShouldClose()))
    {
        BeginDrawing();
        
            ClearBackground(WHITE);
            
            DrawTexture(texturaciudad, 0,380, WHITE);
            DrawTexture(texturagoku, 100,220, WHITE);
            DrawTexture(texturagoku2, 1350 ,220, WHITE);
            DrawTexture(texturacalavera, 160 ,20, WHITE);
            DrawTexture(texturaVS, 750 ,220, WHITE);
            DrawTexture(texturaFirma, 1510 ,740, WHITE);
            DrawTexture(texturaBocadillo1, 40 ,240, WHITE);
            DrawText("¡¿Quieres pelea?!",50, 265, 10, BLACK);
            DrawTexture(texturaBocadillo2, 1510 ,200, WHITE);
            DrawText("¡¡Te voy a machacar!!",1522, 235, 10, BLACK);
            
            DrawText("Juego PONG de Sergio López",300, 50, 70, BLACK);
            DrawText("Press ENTER to START GAME",screenWidth/3, 150, 30, GRAY);
            DrawLine(280, 130, 1360, 130, BLACK);
            DrawText("Copyright © 2015-2016/Sergio López", 5, 885, 10, BLACK);
           
        EndDrawing();
    }
           
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        //----------------------------------------------------------------------------------
        if (IsKeyDown('W') && rectangulo1.y > 0) rectangulo1.y -= 10;//Si se pulsa la tecla W, el rectangulo1 se desplaza en y=-8
        
        if (IsKeyDown('S') && rectangulo1.y + 200 < screenHeight) rectangulo1.y += 10;//Si se pulsa la tecla S, el rectangulo1 se desplaza en y=+8
        
        if (IsKeyPressed('P') && lives>0 && lives2>0){
            velocidadx = 0;
            velocidady = 0;
            
            
        }
        
        if (IsKeyDown(KEY_UP) && rectangulo2.y > 0) rectangulo2.y -= 10;//Si se pulsa la tecla (BOTON ARRIBA), el rectangulo1 se desplaza en y=-8
        
        if (IsKeyDown(KEY_DOWN) && rectangulo2.y + 200 < screenHeight) rectangulo2.y += 10;//Si se pulsa la tecla (BOTON ABAJO), el rectangulo2 se desplaza en y=+8
        ballPosition.x=ballPosition.x + velocidadx;
        ballPosition.y=ballPosition.y + velocidady;
        if(ballPosition.x+radio>screenWidth)//Genera oposiciones de velocidad al tocar cada ancho de la pantalla y resta vidas
        {
        velocidadx=-velocidadx;
        lives2--;}
        else if(ballPosition.x-radio < 0)
        {
        velocidadx=-velocidadx;
        lives--;
        }
        if(ballPosition.y+radio>screenHeight|| ballPosition.y-radio < 0)//Genera oposiciones de velocidad al tocar cada alto y bajo de la pantalla
        {velocidady=-velocidady;
        }
        if(CheckCollisionCircleRec(ballPosition, radio, rectangulo1)){//Detecta dolisiones del circulo con el rectangulo1, invierte velocidad y añade +1 a puntuacion
            velocidadx=-velocidadx;
            puntuacion++;
            puntuacion=puntuacion+PUNTMULTIPLICADOR;
            if((ballPosition.x , ballPosition.y) == (rectangulo1.width/2 , (ballPosition.x , ballPosition.y) <= rectangulo1.height)){
                velocidady = -velocidady;
            }
            
            
        }
        if(CheckCollisionCircleRec(ballPosition, radio, rectangulo2)){//Detecta colisiones del circulo con el rectangulo2, invierte velocidad y añade +1 puntuacion2
            velocidadx=-velocidadx;
            puntuacion2++;
            puntuacion2=puntuacion2+PUNTMULTIPLICADOR;
        }
       
        if(lives2<=0 || lives<=0){//Cuando vidas de los jugadores es <=0; Si puntuacion es > que hiscore, hiscore=puntuacion
            if(puntuacion2>puntuacionmax2 || puntuacion>puntuacionmax){
            puntuacionmax2=puntuacion2;
            puntuacionmax=puntuacion; 
            }
        }
        if(lives<=0){//Cuando pierde el player 1, haz...
        DrawText("Game Over Player 1",5, screenHeight/3, 50, RED);
        DrawText("¡Winner Player 2!",1190, screenHeight/3, 60, GREEN);
        //DrawText("Press ENTER to restart Game",775, 215, 15, LIGHTGRAY);
        //DrawText("Press ESC to End Game",780, 230, 15, LIGHTGRAY);
        velocidadx=0;
        velocidady=0;
        ballPosition.x=screenWidth/2;
        ballPosition.y=screenHeight/2;
            if (IsKeyDown('W') && rectangulo1.y > 0){ rectangulo1.y -= 0;}
            if (IsKeyDown('S') && rectangulo1.y + 200 < screenHeight){ rectangulo1.y += 0;}
            /*if (IsKeyDown(KEY_ENTER)){
                rectangulo1.x = 0;
                rectangulo1.y = 350;
                rectangulo2.x = 1680;
                rectangulo2.y = 350;
                puntuacion = 00000000;
                puntuacion2 = 00000000;
                lives = 3;
                lives2 = 3;
                velocidadx = 9;
                velocidady = 9;
            }*/
        }
        if(lives2<=0){//Cuando pierde el player 2, haz...
        DrawText("¡Winner Player 1!",5, screenHeight/3, 60, GREEN);
        DrawText("Game Over Player 2",1190, screenHeight/3, 50, RED);
        //DrawText("Press ENTER to Restart Game",775, 215, 15, LIGHTGRAY);
        //DrawText("Press ESC to End Game",780, 230, 15, LIGHTGRAY);
        velocidadx=0;
        velocidady=0;
        ballPosition.x=screenWidth/2;
        ballPosition.y=screenHeight/2;
            if (IsKeyDown(KEY_UP) && rectangulo2.y > 0){ rectangulo2.y -= 0;}
            if (IsKeyDown(KEY_DOWN) && rectangulo2.y + 200 < screenHeight){ rectangulo2.y += 0;}
            
        }

        if (IsKeyDown(KEY_ENTER)){//Si se pulsa la tecla enter en la ejecucion de este while, resetear posicion bola, velocidad, vidas y puntuacion.
                rectangulo1.x = 0;
                rectangulo1.y = 350;
                rectangulo2.x = 1680;
                rectangulo2.y = 350;
                puntuacion = 00000000;
                puntuacion2 = 00000000;
                lives = 3;
                lives2 = 3;
                velocidadx = GetRandomValue(min,max);
                velocidady = GetRandomValue(min,max);
                ballPosition.x = screenWidth/2;
                ballPosition.y = screenHeight/2;
                
                if(velocidadx==0 || velocidady==0){//Control errores si el valor aleatorio sale en 0 para velocidadx o para velocidady
                    velocidadx = GetRandomValue(min,max);
                    velocidady = GetRandomValue(min,max);
                }
            }
            
            
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(BLACK);
            
           
            DrawTexture(textura2, 1550 ,850, WHITE);
            DrawTexture(textura3, screenWidth/3, screenHeight/4, WHITE);            
            DrawTexture(textura, ballPosition.x - textura.width/2,
            ballPosition.y - textura.height/2, WHITE);//El ultimo porque pasa por posiciones de otras texturas, y asi esta se superpone al resto
            
            
            
            
            DrawText("¡Bienvenido al PONG!", (screenWidth/3+25), 20, 55, GREEN);
            
            DrawLine(580, 80, 1140, 80, GREEN);
            
            DrawText("Press ENTER to Restart Game", screenWidth/3, 100, 15, GRAY);
            DrawText("Press P to Pause Ball and Reset rectangles positions", screenWidth/3, 120, 15, GRAY);
            
            DrawCircleGradient(ballPosition.x, ballPosition.y, radio, YELLOW, RED);
            
            /*DrawCircleV(ballPosition, radio, MAROON);*/

            //DrawRectangleRec(rectangulo1, SKYBLUE);
            //DrawRectangleRec(rectangulo2, SKYBLUE);
            
            //DrawRectangleGradient(rectangulo1.x, rectangulo1.y, rectangulo1.width, rectangulo1.height, DARKBLUE, SKYBLUE);
            DrawTexture(texturaRectangulo, (rectangulo1.x+5), (rectangulo1.y-5), WHITE);
            //DrawRectangleGradient(rectangulo2.x, rectangulo2.y, rectangulo2.width, rectangulo2.height, SKYBLUE, DARKBLUE);
            DrawTexture(texturaRectangulo, (rectangulo2.x-5), (rectangulo2.y-5), WHITE);
            
            //rectangulo1.x = 15;
            //rectangulo1.y = 350;
            //rectangulo1.height = 200;
            //rectangulo1.width = 20;
            
            DrawRectangleLines(5,5,300,135,GOLD);
            
            DrawText("Player 1:", 30, 5, 35, GOLD);
            
            DrawText(FormatText("Vidas: %02i", lives), 10, 60, 20, RED);
            
            DrawText(FormatText("Puntuación: %08i", puntuacion), 10, 90, 20, BLUE);

            DrawText(FormatText("Puntuación máxima: %08i", puntuacionmax), 10, 120, 20, PURPLE);
            
            DrawRectangleLines(1395,5,300,135,GOLD);
            
            DrawText("Player 2:", 1420, 5, 35, GOLD);

            DrawText(FormatText("Vidas: %02i", lives2), 1400, 60, 20, RED);
            
            DrawText(FormatText("Puntuación: %08i", puntuacion2), 1400, 90, 20, BLUE);

            DrawText(FormatText("Puntuación máxima: %08i", puntuacionmax2), 1400, 120, 20, PURPLE);

            

            DrawText(FormatText("%02.02f ms", GetFrameTime()*1000), 1650, 840, 10, YELLOW);
            
            DrawText(FormatText("%.0f FPS /",GetFPS()),1600,840,10,YELLOW);
            
            DrawText("Copyright © 2015-2016/Sergio López", 5, 885, 10, GREEN);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}