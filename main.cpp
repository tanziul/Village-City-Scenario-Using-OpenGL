
//****************************Village And City Scenario***************************///
//****************************Md.Tanziul Haque************************///
///Press 'c' to see the city scenario and Press 'v' to see the village scenario
///For day and Night press 'd' and 'n' for both scenario
///Left Click the the mouse button for speed up the car and boat and Right click to speed down
///press's' to stop the vehicles and boat
//press's' to satrt again
///press 'f' to fly the plane


///*******************************************source code*******************///
#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <math.h>  // GLUT, include glu.h and gl.h
// Village Variables
struct Village {
    GLfloat boat1Position = 0.0f;
    GLfloat boat1Speed = 20.0f;
    GLfloat boat2Position = 0.0f;
    GLfloat boat2Speed = 20.0f;
    bool isMoving = true;
    float _cloud = 0.0f;            // Cloud position
    bool isDay = true;
    float rainPositionY = 6000.0f;  // Rain position
    bool isRaining = false;          // Raining flag
    float rightRiverOffset = 0.0f;   // River offset
} village;

// City Variables
struct City {
    GLfloat busPosition = 0.0f;
    GLfloat carPosition = 0.0f;
    GLfloat busSpeed = 50.0f;
    GLfloat carSpeed = 55.0f;
    bool isMoving = true;
    float _move2 = 5700.0f;  // Plane position
    float _move3 = 0.0f;      // Additional variable
    bool isPlaneMoving = false;
    bool isRaining = false;
    bool isDay = true;
} city;

int currentscene=1;

void setOrtho() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (currentscene == 1) { // Village
        gluOrtho2D(-5000, 5000, -5000, 6000);
    } else if (currentscene == 2) { // City
        gluOrtho2D(-5000, 5700, -5000, 5000); // Adjust as needed for the city
    }
}

void codes() {

        ///----------------------------------
                 ///Hospital
    ///----------------------------------
    glBegin(GL_POLYGON); ///Left
    glColor3ub( 240,230,140);
    glVertex2f(-3000.0, 2000.0);
    glVertex2f(-2500.0, 2000.0);
    glVertex2f(-2500.0, -500.0);
    glVertex2f(-3000.0, -500.0);
    glEnd();
    glBegin(GL_POLYGON); ///LeftBorder
    glColor3ub( 47,79,79);
    glVertex2f(-3000.0, 1680.0);
    glVertex2f(-2500.0, 1680.0);
    glVertex2f(-2500.0, 1600.0);
    glVertex2f(-3000.0, 1600.0);
    glEnd();
    glBegin(GL_POLYGON); ///Right
    glColor3ub( 240,230,140);
    glVertex2f(000.0, 2000.0);
    glVertex2f(500.0, 2000.0);
    glVertex2f(500.0, -500.0);
    glVertex2f(00.0, -500.0);
    glEnd();
    glBegin(GL_POLYGON); ///RighttBorder
    glColor3ub( 47,79,79);
    glVertex2f(00.0, 1679.0);
    glVertex2f(500.0, 1679.0);
    glVertex2f(500.0, 1600.0);
    glVertex2f(00.0, 1599.0);
    glEnd();
    glBegin(GL_POLYGON); ///LEFTMIDDLE
    glColor3ub( 255,239,213);
    glVertex2f(-2500.0, 1400.0);
    glVertex2f(-2500.0, -500.0);
    glVertex2f(-1701.0, -500.0);
    glVertex2f(-1701.0, 1400.0);
    glEnd();
    glBegin(GL_POLYGON); ///RightMIDDLE
    glColor3ub( 255,239,213);
    glVertex2f(-800.0, 1400.0);
    glVertex2f(0.0, 1400.0);
    glVertex2f(0.0, -500.0);
    glVertex2f(-800.0, -500.0);
    glEnd();
    glBegin(GL_POLYGON); ///UpperSquare
    glColor3ub( 240,230,140);
    glVertex2f(-2500.0, 1700.0);
    glVertex2f(0.0, 1700.0);
    glVertex2f(0.0, 1400.0);
    glVertex2f(-2500.0,1400.0);
    glEnd();
    glBegin(GL_POLYGON); /// circle
    float x30 = -1260.0f;
    float y30 =1571.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(240,230,140);
        float r = 500.0f;
        float pi = 3.1416f;
        float a = (i * pi) / 300;
        float x = r * cos(a) + x30;
        float y = r * sin(a) + y30;
        glVertex2f(x, y);
    }
    glEnd();
    ///plusInsideCircle
    glBegin(GL_POLYGON); ///Rectangle1
    glColor3ub( 255,69,0);
    glVertex2f(-1320.0, 2000.0);
    glVertex2f(-1250.0, 2000.0);
    glVertex2f(-1250.0, 1750.0);
    glVertex2f(-1320.0,1750.0);
    glEnd();
        ///plusInside
    glBegin(GL_POLYGON); ///Rectangle2
    glColor3ub( 255,69,0);
    glVertex2f(-1450.0, 1910.0);
    glVertex2f(-1110.0, 1910.0);
    glVertex2f(-1110.0, 1850.0);
    glVertex2f(-1450.0,1850.0);
    glEnd();
    ///windowRight
    glLineWidth(4);
    glBegin(GL_LINES); ///Line1
    glColor3ub(102,0,0);
    glVertex2f(-2500.0, 1400.0);
    glVertex2f(-2500.0, -500.0);
    glVertex2f(-2500.0, 1400.0);
    glVertex2f(-1700.0, 1400.0);
    glVertex2f(-2200.0, 1400.0);
    glVertex2f(-2200.0, -200.0);
    glVertex2f(-1950.0, 1400.0);
    glVertex2f(-1950.0, -200.0);
    glVertex2f(-2500.0, 1001.0);
    glVertex2f(-1700.0, 1000.0);
    glVertex2f(-2500.0, 600.0);
    glVertex2f(-1700.0, 600.0);
    glVertex2f(-2500.0, 200.0);
    glVertex2f(-1701.0, 200.0);
    glVertex2f(-2500.0, -200.0);
    glVertex2f(-1701.0, -200.0);

    glEnd();
       ///Door
    glBegin(GL_POLYGON); ///Rectangle3
    glColor3ub( 105,105,105);
    glVertex2f(-1701.0, 200.0);
    glVertex2f(-800.0, 200.0);
    glVertex2f(-800.0, -500.0);
    glVertex2f(-1701.0,-500.0);
    glEnd();
    ///right side of window
      glBegin(GL_POLYGON);
    glColor3ub( 240,230,140);
    glVertex2f(-1699.0, 1701.0);
    glVertex2f(-1550.0, 1700.0);
    glVertex2f(-1550.0,-500.0);
    glVertex2f(-1699.0, -500.0);
    glEnd();
        ///Left side of window
      glBegin(GL_POLYGON);
    glColor3ub( 240,230,140);
    glVertex2f(-950.0, 1700.0);
    glVertex2f(-809.0, 1700.0);
    glVertex2f(-800.0,-500.0);
    glVertex2f(-950.0, -500.0);
    glEnd();
    ///UpperSideOfdoor
    glBegin(GL_POLYGON);
    glColor3ub( 240,230,140);
    glVertex2f(-1549.50, 200.0);
    glVertex2f(-950.0, 200.0);
    glVertex2f(-950.0, 1700.0);
    glVertex2f(-1549.0,1700.0);
    glEnd();
    ///MiddeleWindow
    glBegin(GL_POLYGON);///window1
    glColor3ub( 255,239,213);
    glVertex2f(-1400.0, 1300.0);
    glVertex2f(-1100.0, 1300.0);
    glVertex2f(-1100.0,500.0);
    glVertex2f(-1400.0, 500.0);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);///window1
    glColor3ub( 102,0,0);
    glVertex2f(-1400.0, 1300.0);
    glVertex2f(-1100.0, 1300.0);
    glVertex2f(-1100.0, 1300.0);
    glVertex2f(-1100.0,500.0);
    glVertex2f(-1100.0,500.0);
    glVertex2f(-1400.0, 500.0);
    glVertex2f(-1400.0, 500.0);
    glVertex2f(-1400.0, 1300.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);///windowMiddleBorder
    glColor3ub( 102,0,0);
    glVertex2f(-1250.0, 1300.0);
    glVertex2f(-1250.0, 500.0);
    glLineWidth(3);
    glBegin(GL_LINES);///windowRight
    glColor3ub( 102,0,0);
    glVertex2f(-1400.0, 1300.0);
    glVertex2f(-1100.0, 1300.0);
    glVertex2f(-1100.0, 1300.0);
    glVertex2f(-1100.0,500.0);
    glVertex2f(-1100.0,500.0);
    glVertex2f(-1400.0, 500.0);
    glVertex2f(-1400.0, 500.0);
    glVertex2f(-1400.0, 1300.0);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES); ///Line2
    glColor3ub( 102,0,0);
    glVertex2f(-800.0,1400.0);
    glVertex2f(0.0,1400.0);
    glVertex2f(-800.0,1000.0);
    glVertex2f(0.0,1000.0);
    glVertex2f(-800.0,600.0);
    glVertex2f(0.0,600.0);
    glVertex2f(-800.0,200.0);
    glVertex2f(0.0,200.0);
    glVertex2f(-800.0,-200.0);
    glVertex2f(0.0,-200.0);
    glVertex2f(-520.0,1400.0);
    glVertex2f(-520.0,-200.0);
    glVertex2f(-240.0,1400.0);
    glVertex2f(-240.0,-200.0);
    glVertex2f(0.0,1400.0);
    glVertex2f(0.0,-500.0);
    glEnd();

        glLineWidth(7);
    glBegin(GL_LINES); ///Line2
    glColor3ub( 102,0,0);
    glVertex2f(-1701.0,-500.0);
    glVertex2f(-1700.0,1400.0);
    glEnd();
    ///windowLeft
      glLineWidth(7);
    glBegin(GL_LINES); ///Line1
    glColor3ub( 102,0,0);
    glVertex2f(-800.0,1400.0);
    glVertex2f(-800.0,-500.0);
    glEnd();
    glBegin(GL_POLYGON);///Bottom Border
    glColor3ub( 0,51,51);
    glVertex2f(500.0, -500.0);
    glVertex2f(600.0, -600.0);
    glVertex2f(-3050.0,-600.0);
    glVertex2f(-3000.0, -500.0);
    glEnd();

    ///------------------------------------
            ///GreenBackGround
    ///------------------------------------
    glBegin(GL_POLYGON);///GreenGrass
    glColor3ub(154,205,50);
    glVertex2f(-5000.0,-600.0);
    glVertex2f(-5000.0,-2000.0);
    glVertex2f(5700.0, -2000.0);
    glVertex2f(5700.0,-600.0);
    glEnd();
    glBegin(GL_POLYGON);///GreenGrass1
    glColor3ub(154,205,50);
    glVertex2f(-5000.0,-4500.0);
    glVertex2f(5700.0,-2000.0);
    glVertex2f(5700.0, -5000.0);
    glVertex2f(-5000.0,-5000.0);
    glEnd();



    ///----------------------------------
                  ///FoodCourt///
    ///----------------------------------
    glBegin(GL_POLYGON);///MainStructureTop
    glColor3ub( 95,158,160);
    glVertex2f(-4000.0, 1900.0);
    glVertex2f(-3150.0, 1900.0);
    glVertex2f(-3150.0,800.0);
    glVertex2f(-4000.0, 800.0);
    glEnd();
    glBegin(GL_POLYGON);///MainStructureTopBorder
    glColor3ub( 0,51,51);
    glVertex2f(-4050.0, 2000.0);
    glVertex2f(-3100.0, 2000.0);
    glVertex2f(-3100.0,1900.0);
    glVertex2f(-4050.0, 1900.0);
    glEnd();
    glBegin(GL_POLYGON);///MainStructureTopBorder1
    glColor3ub( 0,51,51);
    glVertex2f(-4100.0, 2100.0);
    glVertex2f(-3050.0, 2100.0);
    glVertex2f(-3050.0,2000.0);
    glVertex2f(-4100.0, 2000.0);
    glEnd();
    glBegin(GL_POLYGON);///MainStructureTopMiddleWindow
    glColor3ub( 255,239,213);
    glVertex2f(-3900.0, 1800.0);
    glVertex2f(-3250.0, 1800.0);
    glVertex2f(-3250.0,900.0);
    glVertex2f(-3900.0, 900.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);///MainStructureTopMiddleLine
    glColor3ub( 0,51,51);
    glVertex2f(-3700.0, 1800.0);
    glVertex2f(-3700.0, 900.0);
    glVertex2f(-3450.0,1800.0);
    glVertex2f(-3450.0, 900.0);
    glVertex2f(-3250.0, 1800.0);
    glVertex2f(-4100.0, 1800.0);
    glVertex2f(-3250.0, 1700.0);
    glVertex2f(-4100.0, 1700.0);
    glVertex2f(-3250.0, 1000.0);
    glVertex2f(-4000.0, 1000.0);
    glVertex2f(-3250.0, 1800.0);
    glVertex2f(-3250.0, 900.0);
    glVertex2f(-3250.0, 900.0);
    glVertex2f(-3900.0, 900.0);
    glVertex2f(-3900.0, 900.0);
    glVertex2f(-3900.0, 1800.0);
    glEnd();
    glBegin(GL_POLYGON);///MainStructureBottom
    glColor3ub(95,158,160);
    glVertex2f(-4900.0, 800.0);
    glVertex2f(-3150.0, 800.0);
    glVertex2f(-3150.0,-500.0);
    glVertex2f(-4900.0, -500.0);
    glEnd();
    glBegin(GL_POLYGON);///MainStructureLeftWindow
    glColor3ub(255,239,213);
    glVertex2f(-4800.0, 700.0);
    glVertex2f(-4100.0, 700.0);
    glVertex2f(-4100.0,-400.0);
    glVertex2f(-4800.0, -400.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);///WindowLineLeft
    glColor3ub( 0,51,51);
    glVertex2f(-4800.0, 700.0);
    glVertex2f(-4100.0, 700.0);
    glVertex2f(-4100.0, 700.0);
    glVertex2f(-4100.0,-400.0);
    glVertex2f(-4100.0,-400.0);
    glVertex2f(-4800.0, -400.0);
    glVertex2f(-4800.0, -400.0);
    glVertex2f(-4800.0, 700.0);
    glVertex2f(-4800.0, 200.0);
    glVertex2f(-4100.0, 200.0);
    glVertex2f(-4550.0, 700.0);
    glVertex2f(-4550.0, -400.0);
    glVertex2f(-4320.0, 700.0);
    glVertex2f(-4320.0, -400.0);

    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);///wholeHouseBorder
    glColor3ub( 0,51,51);
    glVertex2f(-4000.0, 1900.0);
    glVertex2f(-4000.0, -500.0);
    glVertex2f(-5000.0,800.0);
    glVertex2f(-3150.0,800.0);
    glVertex2f(-3150.0,1900.0);
    glVertex2f(-3150.0,-500.0);
    glVertex2f(-4000.0,1900.0);
    glVertex2f(-3150.0,1900.0);
    glEnd();
    glBegin(GL_POLYGON);///BottomBorder
    glColor3ub(0,51,51);
    glVertex2f(-3140.0, -500.0);
    glVertex2f(-3100.0, -600.0);
    glVertex2f(-4950.0,-600.0);
    glVertex2f(-4900.0, -500.0);
    glEnd();
    ///Door
    glBegin(GL_POLYGON);///DoorSquareLeft
    glColor3ub(255,239,213);
    glVertex2f(-3799.0, -500.0);
    glVertex2f(-3600.0, -500.0);
    glVertex2f(-3600.0,  400.0);
    glVertex2f(-3800.0,  400.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);///LeftdoorBorder
    glColor3ub(0,51,51);
    glVertex2f(-3799.0, -500.0);
    glVertex2f(-3800.0,  400.0);
    glVertex2f(-3800.0,  400.0);
    glVertex2f(-3600.0, 400.0);
    glVertex2f(-3600.0, 400.0);
    glVertex2f(-3600.0,  -500.0);
    glVertex2f(-3799.0, -300.0);
    glVertex2f(-3600.0, -300.0);
    glEnd();
    glBegin(GL_POLYGON);///DoorSquareLeft
    glColor3ub(255,239,213);
    glVertex2f(-3580.0, 400.0);
    glVertex2f(-3400.0,400.0);
    glVertex2f(-3400.0, -500.0);
    glVertex2f(-3580.0, -500.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);///RightdoorBorder
    glColor3ub(0,51,51);
    glVertex2f(-3580.0,  400.0);
    glVertex2f(-3400.0,  400.0);
    glVertex2f(-3400.0,  400.0);
    glVertex2f(-3400.0, -500.0);
    glVertex2f(-3400.0, -500.0);
    glVertex2f(-3580.0, -500.0);
    glVertex2f(-3580.0,  -500.0);
    glVertex2f(-3580.0,  400.0);
    glVertex2f(-3580.0, -300.0);
    glVertex2f(-3400.0, -300.0);
    glVertex2f(-4000.0, 500.0);
    glVertex2f(-3150.0, 500.0);


    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,239,213);
    glVertex2f(-3590.0, -500.0);
    glVertex2f(-3590.0, 400.0);
    glEnd();
    ///roof
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,51,51);
    glVertex2f(-4980.0, 800.0);
    glVertex2f(-4980.0, 1080.0);
    glVertex2f(-4000.0, 1000.0);
    glVertex2f(-4980.0, 1000.0);
    glVertex2f(-4800.0, 700.0);
    glVertex2f(-4800.0, 1080.0);
    glVertex2f(-4600.0, 800.0);
    glVertex2f(-4600.0, 1080.0);
    glVertex2f(-4400.0, 800.0);
    glVertex2f(-4400.0, 1080.0);
    glVertex2f(-4200.0, 800.0);
    glVertex2f(-4200.0, 1080.0);
    glVertex2f(-4980.0, 940.0);
    glVertex2f(-4000.0, 940.0);
    glEnd();
    ///PutThe name Of foodCourt
    glBegin(GL_POLYGON);///upperSideOfDooor
    glColor3ub(205,133,63);
    glVertex2f(-3900.0, 850.0);
    glVertex2f(-3250.0,850.0);
    glVertex2f(-3250.0,600.0);
    glVertex2f(-3900.0, 600.0);
    glEnd();


    ///Lamp
    glBegin(GL_POLYGON);///RightSideLamp
    glColor3ub(105,105,105);
    glVertex2f(-3300.0, -300.0);
    glVertex2f(-3220.0,-300.0);
    glVertex2f(-3220.0,-1000.0);
    glVertex2f(-3300.0, -1000.0);
    glEnd();
glBegin(GL_POLYGON); /// Bulb
    float x31 = -3269.0f;
    float y31 =-203.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255,255,0);
        float r = 90.0f;
        float pi = 3.1416f;
        float a = (i* 2* pi) / 300;
        float x = r * cos(a) + x31;
        float y = r * sin(a) + y31;
        glVertex2f(x, y);
    }
    glEnd();
        ///LampLeft
    glBegin(GL_POLYGON);///RightSideLamp
    glColor3ub(105,105,105);
    glVertex2f(-3920.0, -300.0);
    glVertex2f(-3840.0,-300.0);
    glVertex2f(-3838.0,-1000.0);
    glVertex2f(-3920.0, -1000.0);
    glEnd();
glBegin(GL_POLYGON); /// Bulb
    float x32 = -3879.0f;
    float y32 =-245.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255,255,0);
        float r = 90.0f;
        float pi = 3.1416f;
        float a = (i* 2* pi) / 300;
        float x = r * cos(a) + x32;
        float y = r * sin(a) + y32;
        glVertex2f(x, y);
    }
    glEnd();
        ///--------- Road-----------////
    glBegin(GL_POLYGON);  // MainRoad
    glColor3ub(105, 105, 105);
    glVertex2f(-5000.0, -2000.0);
    glVertex2f(5700.0, -2000.0);
    glVertex2f(5700.0, -4500.0);
    glVertex2f(-5000.0, -4500.0);
    glEnd();

    ///Road strips
    glBegin(GL_POLYGON);  // strip1
    glColor3ub(255, 255, 255);
    glVertex2f(-4000.0, -3200.0);
    glVertex2f(-3000.0, -3200.0);
    glVertex2f(-3000.0, -3350.0);
    glVertex2f(-4000.0, -3350.0);
    glEnd();

    glBegin(GL_POLYGON);  // strip2
    glColor3ub(255, 255, 255);
    glVertex2f(-2400.0, -3200.0);
    glVertex2f(-1400.0, -3200.0);
    glVertex2f(-1400.0, -3350.0);
    glVertex2f(-2400.0, -3350.0);
    glEnd();

    glBegin(GL_POLYGON);  // strip3
    glColor3ub(255, 255, 255);
    glVertex2f(-800.0, -3200.0);
    glVertex2f(200.0, -3200.0);
    glVertex2f(200.0, -3350.0);
    glVertex2f(-800.0, -3350.0);
    glEnd();

    glBegin(GL_POLYGON);  // strip4
    glColor3ub(255, 255, 255);
    glVertex2f(800.0, -3200.0);
    glVertex2f(1800.0, -3200.0);
    glVertex2f(1800.0, -3350.0);
    glVertex2f(800.0, -3350.0);
    glEnd();

    glBegin(GL_POLYGON);  // strip5
    glColor3ub(255, 255, 255);
    glVertex2f(2400.0, -3200.0);
    glVertex2f(3400.0, -3200.0);
    glVertex2f(3400.0, -3360.0);
    glVertex2f(2400.0, -3360.0);
    glEnd();

    glBegin(GL_POLYGON);  // strip6
    glColor3ub(255, 255, 255);
    glVertex2f(4000.0, -3200.0);
    glVertex2f(5000.0, -3200.0);
    glVertex2f(5000.0, -3360.0);
    glVertex2f(4000.0, -3360.0);
    glEnd();
     ///------------------------------
                  ///Hotel//
    ///-----------------------------
    glBegin(GL_POLYGON);///TopHotelWord
    glColor3ub(72,61,139);
    glVertex2f(1600.0, 2100.0);
    glVertex2f(2400.0,2100.0);
    glVertex2f(2400.0,1800.0);
    glVertex2f(1600.0, 1800.0);
    glEnd();
    glBegin(GL_POLYGON);///LeftSideWall
    glColor3ub(70,130,180);
    glVertex2f(800.0, 2000.0);
    glVertex2f(1100.0,2000.0);
    glVertex2f(1100.0,-200.0);
    glVertex2f(800.0, -200.0);
    glEnd();
    ///LeftSideCircle
    glBegin(GL_POLYGON); /// Circle1
    float x33 = 800.0f;
    float y33 =1600.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(70,130,180);
        float r = 250.0f;
        float pi = 3.1416f;
        float a = (i* 2* pi) / 300;
        float x = r * cos(a) + x33;
        float y = r * sin(a) + y33;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_POLYGON); /// Circle2
    float x34 = 800.0f;
    float y34 =1123.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(70,130,180);
        float r = 250.0f;
        float pi = 3.1416f;
        float a = (i* 2* pi) / 300;
        float x = r * cos(a) + x34;
        float y = r * sin(a) + y34;
        glVertex2f(x, y);
    }
    glEnd();
        glBegin(GL_POLYGON); /// Circle3
    float x35 = 800.0f;
    float y35 =629.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(70,130,180);
        float r = 250.0f;
        float pi = 3.1416f;
        float a = (i* 2* pi) / 300;
        float x = r * cos(a) + x35;
        float y = r * sin(a) + y35;
        glVertex2f(x, y);
    }
    glEnd();
            glBegin(GL_POLYGON); /// Circle3
    float x36 = 795.0f;
    float y36 =156.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(70,130,180);
        float r = 250.0f;
        float pi = 3.1416f;
        float a = (i* 2* pi) / 300;
        float x = r * cos(a) + x36;
        float y = r * sin(a) + y36;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_POLYGON);///LeftSideOfLeftWallWindow1
    glColor3ub(204,204,255);
    glVertex2f(900.0, 1700.0);
    glVertex2f(1000.0,1700.0);
    glVertex2f(1000.0,1200.0);
    glVertex2f(900.0, 1200.0);
    glEnd();
    glBegin(GL_POLYGON);///LeftSideOfLeftWallWindow2
    glColor3ub(204,204,255);
    glVertex2f(900.0, 800.0);
    glVertex2f(1000.0,800.0);
    glVertex2f(1000.0,200.0);
    glVertex2f(900.0, 200.0);
    glEnd();
    glBegin(GL_POLYGON);///RightSideOfLeftWall
    glColor3ub(72,61,139);
    glVertex2f(1200.0, 2400.0);
    glVertex2f(1400.0,2400.0);
    glVertex2f(1400.0,-200.0);
    glVertex2f(1100.0, -200.0);
    glVertex2f(1100.0, 2000.0);
    glEnd();
    glBegin(GL_POLYGON);///MainBuilding
    glColor3ub(70,130,180);
    glVertex2f(1400.0, 1800.0);
    glVertex2f(2600.0,1800.0);
    glVertex2f(2600.0,-200.0);
    glVertex2f(1400.0, -200.0);
    glEnd();
    ///Window
    glBegin(GL_POLYGON);///LeftWindow1
    glColor3ub(204,204,255);
    glVertex2f(1600.0, 1650.0);
    glVertex2f(1800.0,1650.0);
    glVertex2f(1800.0,1400.0);
    glVertex2f(1600.0, 1400.0);
    glEnd();
        glBegin(GL_POLYGON);///LeftWindow2
    glColor3ub(204,204,255);
    glVertex2f(1600.0, 1250.0);
    glVertex2f(1800.0,1250.0);
    glVertex2f(1800.0,1000.0);
    glVertex2f(1600.0, 1000.0);
    glEnd();
    glBegin(GL_POLYGON);///LeftWindow3
    glColor3ub(204,204,255);
    glVertex2f(1600.0, 850.0);
    glVertex2f(1800.0,850.0);
    glVertex2f(1800.0,600.0);
    glVertex2f(1600.0, 600.0);
    glEnd();
    glBegin(GL_POLYGON);///LeftWindow4
    glColor3ub(204,204,255);
    glVertex2f(1600.0, 450.0);
    glVertex2f(1800.0,450.0);
    glVertex2f(1800.0,200.0);
    glVertex2f(1600.0, 200.0);
    glEnd();
    glBegin(GL_POLYGON);///RighttWindow5
    glColor3ub(204,204,255);
    glVertex2f(2200.0,1650.0);
    glVertex2f(2400.0,1650.0);
    glVertex2f(2400.0,1400.0);
    glVertex2f(2200.0, 1400.0);
    glEnd();
    glBegin(GL_POLYGON);///RighttWindow6
    glColor3ub(204,204,255);
    glVertex2f(2200.0,1250.0);
    glVertex2f(2400.0,1250.0);
    glVertex2f(2400.0,1000.0);
    glVertex2f(2200.0, 1000.0);
    glEnd();
    glBegin(GL_POLYGON);///RighttWindow7
    glColor3ub(204,204,255);
    glVertex2f(2200.0,850.0);
    glVertex2f(2400.0,850.0);
    glVertex2f(2400.0,600.0);
    glVertex2f(2200.0, 600.0);
    glEnd();
    glBegin(GL_POLYGON);///RighttWindow8
    glColor3ub(204,204,255);
    glVertex2f(2200.0,450.0);
    glVertex2f(2400.0,450.0);
    glVertex2f(2400.0,200.0);
    glVertex2f(2200.0,200.0);
    glEnd();
    ///MiddleWindow
    glBegin(GL_POLYGON);///MiddleWindow1
    glColor3ub(204,204,255);
    glVertex2f(1900.0,1650.0);
    glVertex2f(2100.0,1650.0);
    glVertex2f(2100.0,1000.0);
    glVertex2f(1900.0,1000.0);
    glEnd();
    glBegin(GL_POLYGON);///MiddleWindow2
    glColor3ub(204,204,255);
    glVertex2f(1900.0,850.0);
    glVertex2f(2100.0,850.0);
    glVertex2f(2100.0,200.0);
    glVertex2f(1900.0,200.0);
    glEnd();
    glBegin(GL_POLYGON);///BottomPartMain
    glColor3ub(0,51,51);
    glVertex2f(2900.0, -200.0);
    glVertex2f(2900.0,-600.0);
    glVertex2f(503.0,-600.0);
    glVertex2f(500.0, -200.0);
    glEnd();
    glBegin(GL_POLYGON);///BottomPart1
    glColor3ub(204,204,255);
    glVertex2f(600.0, -300.0);
    glVertex2f(1000.0,-300.0);
    glVertex2f(1000.0,-500.0);
    glVertex2f(600.0, -500.0);
    glEnd();
    glBegin(GL_POLYGON);///BottomPart2
    glColor3ub(204,204,255);
    glVertex2f(1200.0, -300.0);
    glVertex2f(1600.0,-300.0);
    glVertex2f(1600.0,-500.0);
    glVertex2f(1200.0, -500.0);
    glEnd();
    glBegin(GL_POLYGON);///BottomPart3
    glColor3ub(204,204,255);
    glVertex2f(2400.0, -300.0);
    glVertex2f(2800.0,-300.0);
    glVertex2f(2800.0,-500.0);
    glVertex2f(2400.0, -500.0);
    glEnd();
    ///---Door---//
    glBegin(GL_POLYGON);///Square
    glColor3ub(255,229,204);
    glVertex2f(1700.0, -200.0);
    glVertex2f(2300.0,-200.0);
    glVertex2f(2300.0,-600.0);
    glVertex2f(1700.0, -600.0);
    glEnd();

    glBegin(GL_POLYGON); /// DoorUpper
    float x37 = 2000.0f;
    float y37 =-200.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(204,204,255);
        float r = 300.0f;
        float pi = 3.1416f;
        float a = (i* pi) / 300;
        float x = r * cos(a) + x37;
        float y = r * sin(a) + y37;
        glVertex2f(x, y);
    }
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);///Border
    glColor3ub(96,96,96);
    glVertex2f(2000.0, -200.0);
    glVertex2f(2000.0,-600.0);
    glVertex2f(1700.0,-200.0);
    glVertex2f(1700.0, -600.0);
    glVertex2f(2300.0,-200.0);
    glVertex2f(2300.0, -600.0);
    glVertex2f(1700.0, -200.0);
    glVertex2f(2300.0, -200.0);
    glVertex2f(503.0, -600.0);
    glVertex2f(2900.0, -600.0);
    glEnd();


    ///----------------------------------
                  ///Tree
    ///----------------------------------
    ///Tree1Left
    glBegin(GL_POLYGON);///TreeWood
    glColor3ub( 139,69,19);
    glVertex2f(-2800.0,-200.0);
    glVertex2f(-2720.0, -200.0);
    glVertex2f(-2720.0,-1000.0);
    glVertex2f(-2800.0, -1000.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep
    glColor3ub( 0,128,0);
    glVertex2f(-2950.0,-200.0);
    glVertex2f(-2560.0, -200.0);
    glVertex2f(-2480.0,-280.0);
    glVertex2f(-3060.0, -280.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep1
    glColor3ub( 0,128,0);
    glVertex2f(-3050.0,-200.0);
    glVertex2f(-2860.0, -120.0);
    glVertex2f(-2660.0,-120.0);
    glVertex2f(-2520.0, -200.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep2
    glColor3ub( 0,128,0);
    glVertex2f(-2860.0,-60.0);
    glVertex2f(-2660.0, -60.0);
    glVertex2f(-2520.0,-120.0);
    glVertex2f(-3000.0, -120.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep3
    glColor3ub( 0,128,0);
    glVertex2f(-2860.0,0.0);
    glVertex2f(-2660.0, 0.0);
    glVertex2f(-2580.0,-60.0);
    glVertex2f(-2980.0, -60.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep4
    glColor3ub( 0,128,0);
    glVertex2f(-2750.0,120.0);
    glVertex2f(-2600.0, 0.0);
    glVertex2f(-2920.0, 0.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep4
    glColor3ub( 0,128,0);
    glVertex2f(-2750.0,200.0);
    glVertex2f(-2650.0, 50.0);
    glVertex2f(-2890.0, 50.0);
    glEnd();
    ///treeRight
    glBegin(GL_POLYGON);///TreeWood
    glColor3ub( 139,69,19);
    glVertex2f(250.0,-300.0);
    glVertex2f(350.0, -300.0);
    glVertex2f(350.0,-1000.0);
    glVertex2f(250.0, -1000.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep1
    glColor3ub( 0,128,0);
    glVertex2f(300.0,100.0);
    glVertex2f(600.0, -300.0);
    glVertex2f(0.0, -300.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep2
    glColor3ub( 0,128,0);
    glVertex2f(300.0,00.0);
    glVertex2f(600.0, -200.0);
    glVertex2f(0.0, -200.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep3
    glColor3ub( 0,128,0);
    glVertex2f(298.0,61.0);
    glVertex2f(580.0, -140.0);
    glVertex2f(20.0, -140.0);
    glEnd();
    glBegin(GL_POLYGON);///TreeLeep4
    glColor3ub( 0,128,0);
    glVertex2f(300.0,200.0);
    glVertex2f(550.0, -50.0);
    glVertex2f(50.0, -50.0);
    glEnd();
 ///---------------////
        ///School///
 ///---------------------////
    glBegin(GL_POLYGON);///MainBody
    glColor3ub( 205,92,92);
    glVertex2f(2900.0,1400.0);
    glVertex2f(5500.0, 1400.0);
    glVertex2f(5500.0, -500.0);
    glVertex2f(2900.0, -500.0);
    glEnd();
    glBegin(GL_POLYGON);///BottomBorder
    glColor3ub( 0,51,51);
    glVertex2f(2900.0,-500.0);
    glVertex2f(5600.0, -500.0);
    glVertex2f(5600.0, -600.0);
    glVertex2f(2900.0, -600.0);
    glEnd();
    glBegin(GL_POLYGON);///Top
    glColor3ub( 205,92,92);
    glVertex2f(3700.0,1600.0);
    glVertex2f(4700.0, 1600.0);
    glVertex2f(4700.0, 1400.0);
    glVertex2f(3700.0, 1400.0);
    glEnd();
    glBegin(GL_POLYGON);///TopBorder
    glColor3ub( 255,165,0);
    glVertex2f(2850.0,1400.0);
    glVertex2f(5550.0, 1400.0);
    glVertex2f(5550.0, 1300.0);
    glVertex2f(2850.0, 1300.0);
    glEnd();
    glBegin(GL_POLYGON);///TopTriangle
    glColor3ub( 255,165,0);
    glVertex2f(4200.0,2000.0);
    glVertex2f(4800.0, 1600.0);
    glVertex2f(3600.0, 1600.0);
    glEnd();
    glBegin(GL_POLYGON);///DoorUpper
    glColor3ub( 255,165,0);
    glVertex2f(3800.0,400.0);
    glVertex2f(4600.0, 400.0);
    glVertex2f(4600.0, -500.0);
    glVertex2f(3800.0, -500.0);
    glEnd();
    glBegin(GL_POLYGON);///DoorUpperTriangle
    glColor3ub( 255,165,0);
    glVertex2f(4200.0,700.0);
    glVertex2f(4650.0, 400.0);
    glVertex2f(3750., 400.0);
    glEnd();
    ///Put The Name school//
    glBegin(GL_POLYGON);///DoorUpper2
    glColor3ub( 143,188,143);
    glVertex2f(3850.0,300.0);
    glVertex2f(4550.0, 300.0);
    glVertex2f(4550.0, 50.0);
    glVertex2f(3850.0, 50.0);
    glEnd();

    ///Dooor
    glBegin(GL_POLYGON);///Door
    glColor3ub( 112,128,144);
    glVertex2f(3900.0,00.0);
    glVertex2f(4500.0, 00.0);
    glVertex2f(4500.0, -500.0);
    glVertex2f(3900.0, -500.0);
    glEnd();
    ///Window///
    glBegin(GL_POLYGON);///WindowLeft1
    glColor3ub( 25,25,112);
    glVertex2f(3000.0,1200.0);
    glVertex2f(3250.0,1200.0);
    glVertex2f(3250.0, 950.0);
    glVertex2f(3000.0, 950.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft2
    glColor3ub( 25,25,112);
    glVertex2f(3300.0,1200.0);
    glVertex2f(3550.0,1200.0);
    glVertex2f(3550.0, 950.0);
    glVertex2f(3300.0, 950.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft3
    glColor3ub( 25,25,112);
    glVertex2f(3600.0,1200.0);
    glVertex2f(3850.0,1200.0);
    glVertex2f(3850.0, 950.0);
    glVertex2f(3600.0, 950.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft4
    glColor3ub( 25,25,112);
    glVertex2f(3000.0,800.0);
    glVertex2f(3250.0,800.0);
    glVertex2f(3250.0, 550.0);
    glVertex2f(3000.0, 550.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft5
    glColor3ub( 25,25,112);
    glVertex2f(3300.0,800.0);
    glVertex2f(3550.0,800.0);
    glVertex2f(3550.0, 550.0);
    glVertex2f(3300.0, 550.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft6
    glColor3ub( 25,25,112);
    glVertex2f(3600.0,800.0);
    glVertex2f(3850.0,800.0);
    glVertex2f(3850.0, 550.0);
    glVertex2f(3600.0, 550.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft7
    glColor3ub( 25,25,112);
    glVertex2f(3000.0,300.0);
    glVertex2f(3250.0,300.0);
    glVertex2f(3250.0, -150.0);
    glVertex2f(3000.0, -150.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft8
    glColor3ub( 25,25,112);
    glVertex2f(3400.0,300.0);
    glVertex2f(3650.0,300.0);
    glVertex2f(3650.0, -150.0);
    glVertex2f(3400.0, -150.0);
    glEnd();
    glBegin(GL_POLYGON);///BorderUnderWindow
    glColor3ub(  143,188,143);
    glVertex2f(3000.0,-280.0);
    glVertex2f(3720.0,-280.0);
    glVertex2f(3720.0, -400.0);
    glVertex2f(3000.0, -400.0);
    glEnd();
    ///RightSideWindow
    glBegin(GL_POLYGON);///WindowLeft1
    glColor3ub( 25,25,112);
    glVertex2f(4550.0,1200.0);
    glVertex2f(4800.0,1200.0);
    glVertex2f(4800.0,950.0);
    glVertex2f(4550.0, 950.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft2
    glColor3ub( 25,25,112);
    glVertex2f(4850.0,1200.0);
    glVertex2f(5100.0,1200.0);
    glVertex2f(5100.0,950.0);
    glVertex2f(4850.0, 950.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft3
    glColor3ub( 25,25,112);
    glVertex2f(5150.0,1200.0);
    glVertex2f(5400.0,1200.0);
    glVertex2f(5400.0,950.0);
    glVertex2f(5150.0, 950.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft4
    glColor3ub( 25,25,112);
    glVertex2f(5150.0,800.0);
    glVertex2f(5400.0,800.0);
    glVertex2f(5400.0,550.0);
    glVertex2f(5150.0, 550.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft5
    glColor3ub( 25,25,112);
    glVertex2f(4850.0,800.0);
    glVertex2f(5100.0,800.0);
    glVertex2f(5100.0,550.0);
    glVertex2f(4850.0, 550.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft6
    glColor3ub( 25,25,112);
    glVertex2f(4550.0,800.0);
    glVertex2f(4800.0,800.0);
    glVertex2f(4800.0,550.0);
    glVertex2f(4550.0, 550.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft7
    glColor3ub( 25,25,112);
    glVertex2f(4750.0,300.0);
    glVertex2f(5000.0,300.0);
    glVertex2f(5000.0,-150.0);
    glVertex2f(4750.0, -150.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowLeft7
    glColor3ub( 25,25,112);
    glVertex2f(5150.0,300.0);
    glVertex2f(5400.0,300.0);
    glVertex2f(5400.0,-150.0);
    glVertex2f(5150.0, -150.0);
    glEnd();
    glBegin(GL_POLYGON);///BorderUnderWindow2
    glColor3ub(  143,188,143);
    glVertex2f(4680.0,-280.0);
    glVertex2f(5400.0,-280.0);
    glVertex2f(5400.0, -400.0);
    glVertex2f(4680.0, -400.0);
    glEnd();
    ///MiddleWindow
        glBegin(GL_POLYGON);///MiddleWindow
    glColor3ub(  25,25,112);
    glVertex2f(4050.0,1200.0);
    glVertex2f(4400.0,1200.0);
    glVertex2f(4400.0, 800.0);
    glVertex2f(4050.0, 800.0);
    glEnd();

    ///SchoolField
    glBegin(GL_POLYGON);
    glColor3ub( 244,164,96);
    glVertex2f(3000.0,-800.0);
    glVertex2f(5400.0,-800.0);
    glVertex2f(5400.0, -1800.0);
    glVertex2f(3000.0, -1800.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub( 245,255,250);
    glVertex2f(3000.0,-800.0);
    glVertex2f(5400.0,-800.0);
    glVertex2f(5400.0,-800.0);
    glVertex2f(5400.0, -1800.0);
    glVertex2f(5400.0, -1800.0);
    glVertex2f(3000.0, -1800.0);
    glVertex2f(3000.0, -1800.0);
    glVertex2f(3000.0,-800.0);
    glVertex2f(4900.0,-1100.0);
    glVertex2f(5400.0,-1100.0);
    glVertex2f(4900.0,-1100.0);
    glVertex2f(4900.0,-1500.0);
    glVertex2f(4900.0,-1500.0);
    glVertex2f(5400.0,-1500.0);
    glVertex2f(3000.0,-1100.0);
    glVertex2f(3500.0,-1100.0);
    glVertex2f(3500.0,-1100.0);
    glVertex2f(3500.0,-1500.0);
    glVertex2f(3500.0,-1500.0);
    glVertex2f(3000.0,-1500.0);
    glEnd();

    ///CiecleUnderField
    glBegin(GL_LINE_LOOP); /// FieldCiecle
    float x38 = 4254.0f;
    float y38 =-1286.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(245,255,250);
        float r = 300.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x38;
        float y = r * sin(a) + y38;
        glVertex2f(x, y);
    }
    glEnd();

}



void bus() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(city.busPosition, 0.0f, 0.0f);

    /// Bus body
    glBegin(GL_POLYGON);
    glColor3ub(255, 99, 71);
    glVertex2f(-3600.0, -2100.0);
    glVertex2f(-2000.0, -2100.0);
    glVertex2f(-2000.0, -3000.0);
    glVertex2f(-3600.0, -3000.0);
    glEnd();

    /// Bus windows
    glBegin(GL_POLYGON);
    glColor3ub(224, 255, 255);
    glVertex2f(-3550.0, -2150.0);
    glVertex2f(-2050.0, -2150.0);
    glVertex2f(-2050.0, -2500.0);
    glVertex2f(-3550.0, -2500.0);
    glEnd();
    glBegin(GL_POLYGON);///WindowDoor
    glColor3ub(0,0,0);
    glVertex2f(-2580.0, -2150.0);
    glVertex2f(-2580.0,-2500.0);
    glVertex2f(-2370.0,-2500.0);
    glVertex2f(-2370.0,-2150.0);
    glEnd();
     glLineWidth(2);
    glBegin(GL_LINES);///WindowBorder
    glColor3ub(0,0,0);
    glVertex2f(-3550.0, -2150.0);
    glVertex2f(-2050.0,-2150.0);
    glVertex2f(-2050.0,-2150.0);
    glVertex2f(-2050.0,-2500.0);
    glVertex2f(-2050.0,-2500.0);
    glVertex2f(-3550.0,-2500.0);
    glVertex2f(-3550.0,-2500.0);
    glVertex2f(-3550.0, -2150.0);
    glVertex2f(-3350.0, -2150.0);
    glVertex2f(-3350.0, -2500.0);
    glVertex2f(-3150.0, -2150.0);
    glVertex2f(-3150.0, -2500.0);
    glVertex2f(-2950.0, -2150.0);
    glVertex2f(-2950.0, -2500.0);
    glVertex2f(-2750.0, -2150.0);
    glVertex2f(-2750.0, -2500.0);
    glVertex2f(-2580.0, -2150.0);
    glVertex2f(-2580.0, -2500.0);
    glVertex2f(-2370.0, -2150.0);
    glVertex2f(-2370.0, -2500.0);
    glVertex2f(-2200.0, -2150.0);
    glVertex2f(-2200.0, -2500.0);
    glVertex2f(-3600.0, -2700.0);
    glVertex2f(-1950.0, -2700.0);
     glEnd();
    glBegin(GL_POLYGON);///BusDoor
    glColor3ub(224,255,255);
    glVertex2f(-2550.0, -2200.0);
    glVertex2f(-2400.0,-2200.0);
    glVertex2f(-2400.0,-2950.0);
    glVertex2f(-2550.0,-2950.0);
    glEnd();
    glBegin(GL_POLYGON);///busFront
    glColor3ub(255,99,71);
    glVertex2f(-2000.0, -2500.0);
    glVertex2f(-1920.0,-2500.0);
    glVertex2f(-1920.0,-3000.0);
    glVertex2f(-2000.0,-3000.0);
    glEnd();
        glBegin(GL_POLYGON);///busFrontTriangle
    glColor3ub(224,255,255);
    glVertex2f(-2000.0, -2100.0);
    glVertex2f(-1920.0,-2500.0);
    glVertex2f(-2000.0,-2500.0);
    glEnd();

    glBegin(GL_POLYGON); ///ChakaBehind
    float x39 = -3300.0f;
    float y39 =-3000.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,0,0);
        float r = 140.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x39;
        float y = r * sin(a) + y39;
        glVertex2f(x, y);
    }
    glEnd();
         glBegin(GL_POLYGON); ///Chakainside
    float x40 = -3300.0f;
    float y40 =-3000.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(224,255,255);
        float r = 100.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x40;
        float y = r * sin(a) + y40;
        glVertex2f(x, y);
    }
    glEnd();
         glBegin(GL_POLYGON); ///ChakaFront
    float x41 = -2200.0f;
    float y41 =-3000.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,0,0);
        float r = 140.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x41;
        float y = r * sin(a) + y41;
        glVertex2f(x, y);
    }
    glEnd();
         glBegin(GL_POLYGON); ///ChakaInside
    float x42 = -2200.0f;
    float y42 =-3000.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(224,255,255);
        float r = 100.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x42;
        float y = r * sin(a) + y42;
        glVertex2f(x, y);
    }
    glEnd();
    ///-------BUS2--------//

    ///BusRight
    glBegin(GL_POLYGON);///MainBusBody
    glColor3ub(186,85,211);
    glVertex2f(700.0, -2100.0);
    glVertex2f(2300.0,-2100.0);
    glVertex2f(2300.0,-3000.0);
    glVertex2f(700.0,-3000.0);
    glEnd();
    glBegin(GL_POLYGON);///BusFrondUpTriangle
    glColor3ub(224,255,255);
    glVertex2f(2300.0, -2100.0);
    glVertex2f(2400.0,-2500.0);
    glVertex2f(2300.0,-2500.0);
    glEnd();
    glBegin(GL_POLYGON);///BusFrontDown
    glColor3ub(186,85,211);
    glVertex2f(2300.0, -2500.0);
    glVertex2f(2400.0,-2500.0);
    glVertex2f(2400.0,-3000.0);
    glVertex2f(2300.0,-3000.0);
    glEnd();
    glBegin(GL_POLYGON);///BusWindowWhole
    glColor3ub(224,255,255);
    glVertex2f(750.0, -2150.0);
    glVertex2f(2250.0,-2150.0);
    glVertex2f(2250.0,-2500.0);
    glVertex2f(750.0,-2500.0);
    glEnd();
    glLineWidth(2);

    glBegin(GL_LINES);///BusWindowBorder
    glColor3ub(0,0,0);
    glVertex2f(750.0, -2150.0);
    glVertex2f(2250.0,-2150.0);
    glVertex2f(2250.0,-2150.0);
    glVertex2f(2250.0,-2500.0);
    glVertex2f(2250.0,-2500.0);
    glVertex2f(750.0,-2500.0);
    glVertex2f(750.0,-2500.0);
    glVertex2f(750.0,-2150.0);
    glVertex2f(900.0,-2150.0);
    glVertex2f(900.0,-2500.0);
    glVertex2f(1050.0,-2150.0);
    glVertex2f(1050.0,-2500.0);
    glVertex2f(1200.0,-2150.0);
    glVertex2f(1200.0,-2500.0);
    glVertex2f(1350.0,-2150.0);
    glVertex2f(1350.0,-2500.0);
    glVertex2f(1500.0,-2150.0);
    glVertex2f(1500.0,-2500.0);
    glVertex2f(1650.0,-2150.0);
    glVertex2f(1650.0,-2500.0);
    glVertex2f(1950.0,-2150.0);
    glVertex2f(1950.0,-2500.0);
    glVertex2f(2100.0,-2150.0);
    glVertex2f(2100.0,-2500.0);
    glVertex2f(700.0,-2700.0);
    glVertex2f(2400.0,-2700.0);
    glEnd();
    ///BusDoor
    glBegin(GL_POLYGON);///BusWindowWhole
    glColor3ub(0,0,0);
    glVertex2f(1720.0, -2200.0);
    glVertex2f(1880.0,-2200.0);
    glVertex2f(1880.0,-2950.0);
    glVertex2f(1720.0,-2950.0);
    glEnd();
    ///BusCHaka
    glBegin(GL_POLYGON); ///ChakaBack
    float x58= 1000.0f;
    float y58 =-3000.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,0,0);
        float r3 = 140.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x58;
        float y = r3 * sin(a) + y58;
        glVertex2f(x, y);
    }
glEnd();
    glBegin(GL_POLYGON); ///ChakaBackInside
    float x59= 1000.0f;
    float y59 =-3000.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(224,255,255);
        float r3 = 100.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x59;
        float y = r3 * sin(a) + y59;
        glVertex2f(x, y);
    }
glEnd();
    glBegin(GL_POLYGON); ///ChakaFront
    float x60= 2137.0f;
    float y60 =-3000.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,0,0);
        float r3 = 140.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x60;
        float y = r3 * sin(a) + y60;
        glVertex2f(x, y);
    }
glEnd();
    glBegin(GL_POLYGON); ///ChakaBack
    float x61= 2137.0f;
    float y61 =-3000.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(224,255,255);
        float r3 = 100.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x61;
        float y = r3 * sin(a) + y61;
        glVertex2f(x, y);
    }
glEnd();


    glPopMatrix();
}

void car() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef( city.carPosition, 0.0f, 0.0f);

    glBegin(GL_POLYGON);///MainBodyUppper
    glColor3ub(216,191,216);
    glVertex2f(2100.0, -3500.0);
    glVertex2f(3150.0,-3500.0);
    glVertex2f(3350.0,-3800.0);
    glVertex2f(1800.0,-3800.0);
    glEnd();
    glBegin(GL_POLYGON);///window
    glColor3ub(70,130,180);
    glVertex2f(2150.0, -3550.0);
    glVertex2f(2600.0,-3550.0);
    glVertex2f(2600.0,-3750.0);
    glVertex2f(1980.0,-3750.0);
    glEnd();

    glBegin(GL_POLYGON);///window1
    glColor3ub(70,130,180);
    glVertex2f(2650.0, -3550.0);
    glVertex2f(3100.0,-3550.0);
    glVertex2f(3250.0,-3750.0);
    glVertex2f(2650.0,-3750.0);
    glEnd();
    glBegin(GL_POLYGON);///lowerPart
    glColor3ub(216,191,216);
    glVertex2f(1450.0, -3840.0);
    glVertex2f(1800.0,-3800.0);
    glVertex2f(3550.0,-3800.0);
    glVertex2f(3740.0,-4090.0);
    glVertex2f(1250.0,-4100.0);
    glEnd();
    ///blackInsideBody
    glBegin(GL_POLYGON);///blackSuqare
    glColor3ub(0,0,0);
    glVertex2f(1200.0, -4050.0);
    glVertex2f(1350.0,-4050.0);
    glVertex2f(1350.0,-4100.0);
    glVertex2f(1200.0,-4100.0);
    glEnd();
    ///blackInsideBody
    glBegin(GL_POLYGON);///blackSuqareBehind
    glColor3ub(0,0,0);
    glVertex2f(3640.0, -4050.0);
    glVertex2f(3780.0,-4050.0);
    glVertex2f(3780.0,-4090.0);
    glVertex2f(3640.0,-4090.0);
    glEnd();

    glBegin(GL_POLYGON);///borderUndercar
    glColor3ub(70,130,180);
    glVertex2f(1600.0, -3900.0);
    glVertex2f(3500.0,-3900.0);
    glVertex2f(3500.0,-3950.0);
    glVertex2f(1600.0,-3950.0);
    glEnd();
    glBegin(GL_POLYGON);///BackRedLight
    glColor3ub(255,0,0);
    glVertex2f(1410.0, -3900.0);
    glVertex2f(1500.0,-3900.0);
    glVertex2f(1500.0,-3960.0);
    glVertex2f(1361.0,-3960.0);
    glEnd();
        glBegin(GL_POLYGON);///BackRedLight
    glColor3ub(255,0,0);
    glVertex2f(3540.0, -3900.0);
    glVertex2f(3615.0,-3900.0);
    glVertex2f(3655.0,-3960.0);
    glVertex2f(3540.0,-3960.0);
    glEnd();
         glBegin(GL_POLYGON); ///ChakaBehind
    float x43 = 1900.0f;
    float y43 =-4097.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,0,0);
        float r = 135.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x43;
        float y = r * sin(a) + y43;
        glVertex2f(x, y);
    }
    glEnd();
         glBegin(GL_POLYGON); ///Chakainside
    float x44 = 1900.0f;
    float y44 =-4097.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(224,255,255);
        float r = 95.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x44;
        float y = r * sin(a) + y44;
        glVertex2f(x, y);
    }
    glEnd();
         glBegin(GL_POLYGON); ///ChakaFront
    float x45 = 3107.0f;
    float y45 =-4092.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,0,0);
        float r = 135.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x45;
        float y = r * sin(a) + y45;
        glVertex2f(x, y);
    }
    glEnd();
         glBegin(GL_POLYGON); ///ChakaInside
    float x46 = 3107.0f;
    float y46 =-4092.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(224,255,255);
        float r = 95.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x46;
        float y = r * sin(a) + y46;
        glVertex2f(x, y);
    }
    glEnd();
    ///Private Car2
    glBegin(GL_POLYGON);///MainBodyUppper
    glColor3ub(255,165,0);
    glVertex2f(-1800.0, -3600.0);
    glVertex2f(-800.0,-3600.0);
    glVertex2f(-700.0,-3900.0);
    glVertex2f(-2100.0,-3900.0);
    glEnd();
    glBegin(GL_POLYGON);///windowFront
    glColor3ub(100,149,237);
    glVertex2f(-1750.0, -3650.0);
    glVertex2f(-1400.0,-3650.0);
    glVertex2f(-1400.0,-3850.0);
    glVertex2f(-1950.0,-3850.0);
    glEnd();
        glBegin(GL_POLYGON);///windowBack
    glColor3ub(100,149,237);
    glVertex2f(-1300.0, -3650.0);
    glVertex2f(-900.0,-3650.0);
    glVertex2f(-800.0,-3850.0);
    glVertex2f(-1300.0,-3850.0);
    glEnd();
    glBegin(GL_POLYGON);///MainBodyLower
    glColor3ub(255,165,0);
    glVertex2f(-2700.0, -4200.0);
    glVertex2f(-2450.0,-3950.0);
    glVertex2f(-2100.0,-3900.0);
    glVertex2f(-550.0,-3900.0);
    glVertex2f(-400.0,-4200.0);
    glEnd();
    glBegin(GL_POLYGON);///frontRedLight
    glColor3ub(255,0,0);
    glVertex2f(-2500.0, -4000.0);
    glVertex2f(-2440.0,-4000.0);
    glVertex2f(-2440.0,-4080.0);
    glVertex2f(-2580.0,-4080.0);
    glEnd();
    glBegin(GL_POLYGON);///BackRedLight
    glColor3ub(255,0,0);
    glVertex2f(-500.0,-4000.0);
    glVertex2f(-460.0,-4080.0);
    glVertex2f(-600.0,-4080.0);
    glVertex2f(-600.0, -4000.0);
    glEnd();
    glBegin(GL_POLYGON);///BorderInsideLower
    glColor3ub(100,149,237);
    glVertex2f(-2200.0,-4000.0);
    glVertex2f(-750.0,-4000.0);
    glVertex2f(-750.0,-4060.0);
    glVertex2f(-2200.0, -4060.0);
    glEnd();

    ///Chaka
       glBegin(GL_POLYGON); ///ChakaMain
    float x62 = -2200.0f;
    float y62 =-4200.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,0,0);
        float r = 135.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x62;
        float y = r * sin(a) + y62;
        glVertex2f(x, y);
    }
    glEnd();
         glBegin(GL_POLYGON); ///Chakainside
    float x63 = -2200.0f;
    float y63 =-4200.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(224,255,255);
        float r = 95.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x63;
        float y = r * sin(a) + y63;
        glVertex2f(x, y);
    }
    glEnd();
         glBegin(GL_POLYGON); ///ChakaFront
    float x64 = -887.0f;
    float y64 =-4200.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,0,0);
        float r = 135.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x64;
        float y = r * sin(a) + y64;
        glVertex2f(x, y);
    }
    glEnd();
         glBegin(GL_POLYGON); ///ChakaInside
    float x65 = -887.0f;
    float y65 =-4200.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(224,255,255);
        float r = 95.0f;
        float pi = 3.1416f;
        float a = (i* 2*pi) / 300;
        float x = r * cos(a) + x65;
        float y = r * sin(a) + y65;
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();
}
/////megh
void megh(){
     glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(city._move3 , 0.0f, 0.0f);
    glBegin(GL_POLYGON); ///megh1
    float x47 = -2963.0f;
    float y47 = 3204.0f;
    float r1 = 300.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255, 255, 255);
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r1 * cos(a) + x47;
        float y = r1 * sin(a) + y47;
        glVertex2f(x, y);
    }
glEnd();

glBegin(GL_POLYGON); ///megh2
    float x49 = -2787.0f;
    float y49 = 3659.0f;
    float r2 = 300.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255, 255, 255);
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r2 * cos(a) + x49;
        float y = r2 * sin(a) + y49;
        glVertex2f(x, y);
    }
glEnd();

glBegin(GL_POLYGON); ///megh3
    float x50 = -2481.0f;
    float y50 = 3422.0f;
    float r3 = 300.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255, 255, 255);
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x50;
        float y = r3 * sin(a) + y50;
        glVertex2f(x, y);
    }
glEnd();
glBegin(GL_POLYGON); ///megh4
    float x51 = -2400.0f;
    float y51 = 3050.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255, 255, 255);
        float r3 = 300.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x51;
        float y = r3 * sin(a) + y51;
        glVertex2f(x, y);
    }
glEnd();
glBegin(GL_POLYGON); ///megh8
    float x56= 1495.0f;
    float y56 = 4326.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(220,220,220);
        float r3 = 400.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x56;
        float y = r3 * sin(a) + y56;
        glVertex2f(x, y);
    }
glEnd();
glBegin(GL_POLYGON); ///megh5
    float x52 = 1113.0f;
    float y52 = 3722.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255, 255, 255);
        float r3 = 400.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x52;
        float y = r3 * sin(a) + y52;
        glVertex2f(x, y);
    }
glEnd();
glBegin(GL_POLYGON); ///megh6
    float x53 = 1789.0f;
    float y53 = 4026.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255, 255, 255);
        float r3 = 400.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x53;
        float y = r3 * sin(a) + y53;
        glVertex2f(x, y);
    }
glEnd();
glBegin(GL_POLYGON); ///megh7
    float x54= 1187.0f;
    float y54 = 4185.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255, 255, 255);
        float r3 = 400.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x54;
        float y = r3 * sin(a) + y54;
        glVertex2f(x, y);
    }
glEnd();
glBegin(GL_POLYGON); ///megh8
    float x55= 500.0f;
    float y55 = 4000.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255, 255, 255);
        float r3 = 400.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x55;
        float y = r3 * sin(a) + y55;
        glVertex2f(x, y);
    }
glEnd();
glPopMatrix();


}

void palne()

{   glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(city._move2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);///mainBody
    glColor3ub(255,250,250);
    glVertex2f(2800.0, 3200.0);
    glVertex2f(3800.0,3050.0);
    glVertex2f(3950.0,2850.0);
    glVertex2f(2400.0,3000.0);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);///mainBOdyBorder
    glColor3ub(178,34,34);
    glVertex2f(2800.0, 3200.0);
    glVertex2f(3800.0,3050.0);
    glVertex2f(3800.0,3050.0);
    glVertex2f(3950.0,2850.0);
    glVertex2f(3950.0,2850.0);
    glVertex2f(2400.0,3000.0);
    glVertex2f(2400.0,3000.0);
    glVertex2f(2800.0, 3200.0);
    glEnd();
    glBegin(GL_POLYGON);///PakhaBhind
    glColor3ub(188,143,143);
    glVertex2f(3800.0, 3050.0);
    glVertex2f(4200.0,3200.0);
    glVertex2f(3940.0,2860.0);
    glEnd();
    glBegin(GL_POLYGON);///PakhaFront1
    glColor3ub(188,143,143);
    glVertex2f(3380.0, 3380.0);
    glVertex2f(3500.0, 3400.0);
    glVertex2f(3340.0,3120.0);
    glVertex2f(3200.0,3140.0);
    glEnd();
        glBegin(GL_POLYGON);///PakhaFront1
    glColor3ub(188,143,143);
    glVertex2f(3200.0, 2922.0);
    glVertex2f(3337.0, 2914.0);
    glVertex2f(3500.0,2700.0);
    glVertex2f(3360.0,2720.0);
    glEnd();
        glBegin(GL_POLYGON);///PakhaFront1
    glColor3ub(178,34,34);
    glVertex2f(2880.0, 3080.0);
    glVertex2f(3000.0, 3060.0);
    glVertex2f(3000.0,3020.0);
    glVertex2f(2800.0,3040.0);
    glEnd();
        glBegin(GL_POLYGON);///PakhaFront2
    glColor3ub(178,34,34);
    glVertex2f(3100.0, 3050.0);
    glVertex2f(3249.0, 3029.0);
    glVertex2f(3228.0,2990.0);
    glVertex2f(3090.0,3011.0);
    glEnd();
            glBegin(GL_POLYGON);///PakhaFront3
    glColor3ub(178,34,34);
    glVertex2f(3330.0, 3015.0);
    glVertex2f(3510.0, 2990.0);
    glVertex2f(3500.0,2950.0);
    glVertex2f(3320.0,2975.0);
    glEnd();
        glBegin(GL_POLYGON);///PakhaFront4
    glColor3ub(178,34,34);
    glVertex2f(3600.0, 2980.0);
    glVertex2f(3740.0, 2960.0);
    glVertex2f(3740.0,2920.0);
    glVertex2f(3580.0,2940.0);
    glEnd();
    glPopMatrix();
}
void renderDayScene() {

    ///------SkyBackGround-----////
    glBegin(GL_POLYGON);
    glColor3ub( 174,234,252);
    glVertex2f(-5000.0, 5000.0);
    glVertex2f(5700.0, 5000.0);
    glVertex2f(5700.0, -600.0);
    glVertex2f(-5000.0, -600.0);
    glEnd();

    ///------------------------------------
            ///GreenBackGround
    ///------------------------------------
    glBegin(GL_POLYGON);///GreenGrass
    glColor3ub(154,205,50);
    glVertex2f(-5000.0,-600.0);
    glVertex2f(-5000.0,-2000.0);
    glVertex2f(5700.0, -2000.0);
    glVertex2f(5700.0,-600.0);
    glEnd();
    glBegin(GL_POLYGON);///GreenGrass1
    glColor3ub(154,205,50);
    glVertex2f(-5000.0,-4500.0);
    glVertex2f(5700.0,-2000.0);
    glVertex2f(5700.0, -5000.0);
    glVertex2f(-5000.0,-5000.0);
    glEnd();


///sun
glBegin(GL_POLYGON); ///sun
    float x57= -1000.0f;
    float y57 =3300.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255,215,0);
        float r3 = 300.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x57;
        float y = r3 * sin(a) + y57;
        glVertex2f(x, y);
    }
glEnd();



}




// Function to render the night scene
void renderNightScene() {
        ///------SkyBackGround-----////
    glBegin(GL_POLYGON);
    glColor3ub( 0,0,31);
    glVertex2f(-5000.0, 5000.0);
    glVertex2f(5700.0, 5000.0);
    glVertex2f(5700.0, -600.0);
    glVertex2f(-5000.0, -600.0);
    glEnd();

    ///------------------------------------
            ///GreenBackGround
    ///------------------------------------
    glBegin(GL_POLYGON);///GreenGrass
    glColor3ub(0,100,0);
    glVertex2f(-5000.0,-600.0);
    glVertex2f(-5000.0,-2000.0);
    glVertex2f(5700.0, -2000.0);
    glVertex2f(5700.0,-600.0);
    glEnd();
    glBegin(GL_POLYGON);///GreenGrass1
    glColor3ub(0,100,0);
    glVertex2f(-5000.0,-4500.0);
    glVertex2f(5700.0,-2000.0);
    glVertex2f(5700.0, -5000.0);
    glVertex2f(-5000.0,-5000.0);
    glEnd();

    ///sun
glBegin(GL_POLYGON); ///sun
    float x57= -1000.0f;
    float y57 =3300.0f;

    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255,255,255);
        float r3 = 300.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r3 * cos(a) + x57;
        float y = r3 * sin(a) + y57;
        glVertex2f(x, y);
    }
glEnd();
///Star
glPointSize(3.0f);
glBegin(GL_POINTS);
glVertex2f(-4500.0f, 4800.0f);
glVertex2f(5300.0f, 4700.0f);
glVertex2f(-3000.0f, 3500.0f);
glVertex2f(4000.0f, 2900.0f);
glVertex2f(-1000.0f, 4300.0f);
glVertex2f(2000.0f, 4600.0f);
glVertex2f(1500.0f, 3200.0f);
glVertex2f(-3400.0f, 3800.0f);
glVertex2f(4500.0f, 4000.0f);
glVertex2f(-2000.0f, 4900.0f);
glVertex2f(-4700.0f, 4500.0f);
glVertex2f(5200.0f, 4800.0f);
glVertex2f(-4200.0f, 4900.0f);
glVertex2f(5400.0f, 2700.0f);
glVertex2f(3000.0f, 4900.0f);
glVertex2f(-3800.0f, 4600.0f);
glVertex2f(3500.0f, 4000.0f);
glVertex2f(5000.0f, 4800.0f);
glVertex2f(-2500.0f, 3400.0f);
glVertex2f(2400.0f, 2700.0f);
glVertex2f(-3300.0f, 2900.0f);
glVertex2f(1000.0f, 4100.0f);
glVertex2f(-4900.0f, 4800.0f);
glVertex2f(5600.0f, 3500.0f);
glVertex2f(3000.0f, 4600.0f);
glVertex2f(-1500.0f, 4700.0f);
glVertex2f(4800.0f, 4400.0f);
glVertex2f(4100.0f, 2900.0f);
glVertex2f(-3800.0f, 4000.0f);
glVertex2f(-2900.0f, 3000.0f);
glEnd();



}





///---------Village-----------//


void codes2() {


    /// house1
    glBegin(GL_POLYGON); ///rectangle1
    glColor3ub(205, 133, 63);
    glVertex2f(-3250.0, 1000.0);
    glVertex2f(-1800.0, 980.0);
    glVertex2f(-1600.0, 560.0);
    glVertex2f(-3040.0, 560.0);
    glEnd();
    glBegin(GL_POLYGON); ///rectangle2
    glColor3ub(222,184,135);
    glVertex2f(-3040.0, 560.0);
    glVertex2f(-1600.0, 560.0);
    glVertex2f(-1600.0, -280.0);
    glVertex2f(-3040.0, -280.0);
    glEnd();
    glBegin(GL_POLYGON); ///rectangle3
    glColor3ub(205, 133, 63);
    glVertex2f(-3300.0, 1000.0);
    glVertex2f(-3250.0, 1000.0);
    glVertex2f(-3506.0, 640.0);
    glVertex2f(-3580, 640);
    glEnd();
    glBegin(GL_POLYGON); /// rectangle4
    glColor3ub(255,228,181);
    glVertex2f(-3500.0, 650.0);
    glVertex2f(-3040.0, 560.0);
    glVertex2f(-3040.0, -280.0);
    glVertex2f(-3500.0, -100.0);
    glEnd();
    glBegin(GL_POLYGON); ///triangle1
    glColor3ub(255,228,181);
    glVertex2f(-3250.0, 1000.0);
    glVertex2f(-3040.0, 560.0);
    glVertex2f(-3500.0, 650.0);
    glEnd();
    glBegin(GL_POLYGON); ///triangle2
    glColor3ub(205, 133, 63);
    glVertex2f(-3250.0, 1000.0);
    glVertex2f(-3271.0, 970.0);
    glVertex2f(-3235.0, 970.0);
    glEnd();
    glBegin(GL_POLYGON); ///windowLeft
    glColor3ub(205, 133, 63);
    glVertex2f(-3360.0, 300.0);
    glVertex2f(-3200.0, 260.0);
    glVertex2f(-3200.0, 60.0);
    glVertex2f(-3360.0, 100.0);
    glEnd();
    glBegin(GL_POLYGON); ///windowRight
    glColor3ub(205, 133, 63);
    glVertex2f(-2000.0, 250.0);
    glVertex2f(-1800.0, 250.0);
    glVertex2f(-1800.0, 00.0);
    glVertex2f(-2000.0, 00.0);
    glEnd();
    glBegin(GL_POLYGON); ///dooor
    glColor3ub(205, 133, 63);
    glVertex2f(-2600.0, 280.0);
    glVertex2f(-2200.0, 280.0);
    glVertex2f(-2200.0, -280.0);
    glVertex2f(-2600.0, -280.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES); ///dooor
    glColor3ub(105,105,105);
    glVertex2f(-2400.0, 280.0);
    glVertex2f(-2400.0, -280.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(170, 74, 68);
    glVertex2f(-3040.0, -280.0);
    glVertex2f(-1600.0, -280.0);
    glVertex2f(-1541.0, -340.0);
    glVertex2f(-3060.0, -340.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(170, 74, 68);
    glVertex2f(-3040.0, -280.0);
    glVertex2f(-3060.0, -340.0);
    glVertex2f(-3545.0, -145.0);
    glVertex2f(-3500.0, -100.0);
    glEnd();
    ///RoadForHouse1
    glBegin(GL_POLYGON);///Road1
    glColor3ub(192, 147, 114);
    glVertex2f(-2507.0, -340.0);
    glVertex2f(-2362.0, -340.0);
    glVertex2f(-2400.0, -1600.0);
    glVertex2f(-2200.0, -1600.0);
    glEnd();
        glBegin(GL_POLYGON);
    glColor3ub(192, 147, 114);
    glVertex2f(-2400.0, -1600.0);
    glVertex2f(-2200.0, -1600.0);
    glVertex2f(-2806.0, -499800.0);
    glVertex2f(-2587.0, -5052.0);
    glEnd();
    glBegin(GL_POLYGON);///Road2
    glColor3ub(192, 147, 114);
    glVertex2f(-2413.0, -654.0);
    glVertex2f(-609.22, -263.0);
    glVertex2f(-440.0, -307.0);
    glVertex2f(-2400.0, -837.0);
    glEnd();
     ///RoadForHouse2
         glBegin(GL_POLYGON);///Road3
    glColor3ub(192, 147, 114);
    glVertex2f(-1380.0, -56.0);
    glVertex2f(-1189.0, -56.0);
    glVertex2f(1143.0, -616.0);
    glVertex2f(1144.0, -736.0);
    glEnd();


    ///House2Right
    glBegin(GL_POLYGON);///roof
    glColor3ub(184,134,11);
    glVertex2f(-1800.0, 1085.0);
    glVertex2f(-1800.0, 980.0);
    glVertex2f(-1685.0, 739.0);
    glVertex2f(-600.0, 740.0);
    glVertex2f(-965.0, 1085.0);
    glEnd();
    glBegin(GL_POLYGON);///roof
    glColor3ub(184,134,11);
    glVertex2f(-2020.0, 1085.0);
    glVertex2f(-1800.0, 1085.0);
    glVertex2f(-1800.0, 980.0);
    glVertex2f(-1930.0, 981.0);
    glEnd();
    glBegin(GL_POLYGON);///roofTriangle
    glColor3ub(255,239,213);
    glVertex2f(-2020.0, 1085.0);
    glVertex2f(-1930.0, 981.0);
    glVertex2f(-2105.0, 984.0);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES); ///roof
    glColor3ub(184,134,11);
    glVertex2f(-2020.0, 1085.0);
    glVertex2f(-2105.0, 984.0);
    glEnd();
    glBegin(GL_POLYGON);///rectangle1
    glColor3ub(240,230,140);
    glVertex2f(-1685.0, 739.0);
    glVertex2f(-725.0, 740.0);
    glVertex2f(-727.0, 555.0);
    glVertex2f(-1600.0,560.0);
     glEnd();
     glBegin(GL_POLYGON);///rectangle1
    glColor3ub(240,230,140);
    glVertex2f(-1600.0,560.0);
    glVertex2f(-727.0, 555.0);
    glVertex2f(-733.50,0.0);
    glVertex2f(-1600.0, 0.0);
    glEnd();
   glBegin(GL_POLYGON);///window
    glColor3ub(160,82,45);
    glVertex2f(-1000.0,400.0);
    glVertex2f(-800.0, 400.0);
    glVertex2f(-800.0,200.0);
    glVertex2f(-1000.0, 200.0);
    glEnd();
    glBegin(GL_POLYGON);///door
    glColor3ub(160,82,45);
    glVertex2f(-1400.0,400.0);
    glVertex2f(-1100.0, 400.0);
    glVertex2f(-1100.0,00.0);
    glVertex2f(-1400.0, 00.0);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES); ///roof
    glColor3ub(184,134,11);
    glVertex2f(-1250.0, 400.0);
    glVertex2f(-1250.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);///door
    glColor3ub(160,82,45);
    glVertex2f(-1600.0,00.0);
    glVertex2f(-733.0, 00.0);
    glVertex2f(-690.0,-60.0);
    glVertex2f(-1600.0, -55.0);
    glEnd();


///RiversideLeft
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(101,77,5);
    glVertex2f(100.0,800.0);
    glVertex2f(528.0, 346.0);
    glVertex2f(528.0, 346.0);
    glVertex2f(761.0,-532.0);
    glVertex2f(761.0,-532.0);
    glVertex2f(1139.0,-525.0);
    glVertex2f(1139.0,-525.0);
    glVertex2f(1159.0,-875.0);
    glVertex2f(1159.0,-875.0);
    glVertex2f(892.0,-972.0);
    glVertex2f(892.0,-972.0);
    glVertex2f(693.0,-2069.0);
    glVertex2f(693.0,-2069.0);
    glVertex2f(1111.0,-2880.0);
    glVertex2f(1111.0,-2880.0);
    glVertex2f(739.0, -5000.0);
    glEnd();

    ///pala
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex2f(-4600.0,300.0);
    glVertex2f(-3800.0,300.0);
    glVertex2f(-3800.0,-500.0);
    glVertex2f(-4600.0,-500.0);
    glEnd();
    glBegin(GL_POLYGON); /// circleGround
    float x9 = -4205.0f;
    float y9 =347.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(255,215,0);
        float r = 401.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + x9;
        float y = r * sin(a) + y9;
        glVertex2f(x, y);
    }
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);///PalaLathi
    glColor3ub(218,165,32);
    glVertex2f(-4200.0,1000.0);
    glVertex2f(-4199.0,748.0);
    glEnd();
    ///fency
    glLineWidth(2);
    glBegin(GL_LINES);///
    glColor3ub(255,255,0);
    glVertex2f(-5000.0,400.0);
    glVertex2f(-4600.0,400.0);
    glVertex2f(-5000.0,200.0);
    glVertex2f(-4600.0,200.0);
    glVertex2f(-5000.0,0.0);
    glVertex2f(-4600.0,00.0);
    glVertex2f(-4900.0,500.0);
    glVertex2f(-4900.0,-100.0);
    glVertex2f(-4800.0,500.0);
    glVertex2f(-4800.0,-100.0);
    glVertex2f(-4700.0,500.0);
    glVertex2f(-4700.0,-100.0);
    glVertex2f(-3807.0,399.0);
    glVertex2f(-3500.0,400.0);
    glVertex2f(-3800.0,200.0);
    glVertex2f(-3500.0,200.0);
    glVertex2f(-3800.0,00.0);
    glVertex2f(-3500.0,00.0);
    glVertex2f(-3700.0,500.0);
    glVertex2f(-3700.0,-100.0);
    glVertex2f(-3600.0,500.0);
    glVertex2f(-3600.0,-100.0);
    glVertex2f(-728.0,395.0);
    glVertex2f(-75.0,391.0);
    glVertex2f(-726.0,199.0);
    glVertex2f(-79.0,194.0);
    glVertex2f(-733.0,00.0);
    glVertex2f(-215.0,00.0);
    glVertex2f(-600.0,500.0);
    glVertex2f(-600.0,-100.0);
    glVertex2f(-400.0,500.0);
    glVertex2f(-400.0,-100.0);
    glVertex2f(-200.0,500.0);
    glVertex2f(-200.0,100.0);
    glVertex2f(-500.0,500.0);
    glVertex2f(-500.0,-100.0);
    glVertex2f(-400.0,500.0);
    glVertex2f(-400.0,-100.0);
    glVertex2f(-300.0,500.0);
    glVertex2f(-300.0,-100.0);
    glVertex2f(79.0,396.0);
    glVertex2f(456.0,401.0);
    glVertex2f(89.0,199.0);
    glVertex2f(566.0,200.0);
    glVertex2f(215.0,00.0);
    glVertex2f(617.0,00.0);
    glVertex2f(200.0,500.0);
    glVertex2f(199.0,82.0);
    glVertex2f(300.0,500.0);
    glVertex2f(300.0,-100.0);
    glVertex2f(400.0,500.0);
    glVertex2f(400.0,-100.0);
    glVertex2f(200.0,100.0);
    glEnd();


///OtherVillage
glBegin(GL_POLYGON); ///villageCircle1
float x10 = -4300.0f;
float y10 = 3000.0f;
for (int i = 0; i <= 180; i++) {
    glColor3ub(0, 100, 0);
    float r = 750.0f;
    float pi = 3.1416f;
    float a = (i * pi) / 180;
    float x = r * cos(a) + x10;
    float y = r * sin(a) + y10;
    glVertex2f(x, y);
}
glEnd();
glBegin(GL_POLYGON); ///villageCircle2
float x11 = -3000.0f;
float y11 = 3000.0f;
for (int i = 0; i <= 180; i++) {
    glColor3ub(0, 100, 0);
    float r = 570.0f;
    float pi = 3.1416f;
    float a = (i * pi) / 180;
    float x = r * cos(a) + x11;
    float y = r * sin(a) + y11;
    glVertex2f(x, y);
}
glEnd();
glBegin(GL_POLYGON); ///villageCircle3
float x12 = -2000.0f;
float y12 = 3000.0f;
for (int i = 0; i <= 180; i++) {
    glColor3ub(0, 100, 0);
    float r = 590.0f;
    float pi = 3.1416f;
    float a = (i * pi) / 180;
    float x = r * cos(a) + x12;
    float y = r * sin(a) + y12;
    glVertex2f(x, y);
}
glEnd();
glBegin(GL_POLYGON); ///villageCircle4
float x13 = -1000.0f;
float y13 = 3000.0f;
for (int i = 0; i <= 180; i++) {
    glColor3ub(0, 100, 0);
    float r = 600.0f;
    float pi = 3.1416f;
    float a = (i * pi) / 180;
    float x = r * cos(a) + x13;
    float y = r * sin(a) + y13;
    glVertex2f(x, y);
}
glEnd();
glBegin(GL_POLYGON); ///villageCircle5
float x14 = -100.0f;
float y14 = 3000.0f;
for (int i = 0; i <= 180; i++) {
    glColor3ub(0, 100, 0);
    float r = 600.0f;
    float pi = 3.1416f;
    float a = (i * pi) / 180;
    float x = r * cos(a) + x14;
    float y = r * sin(a) + y14;
    glVertex2f(x, y);
}
glEnd();
glBegin(GL_POLYGON); ///villageCircle6
float x15 = 1000.0f;
float y15 = 3000.0f;
for (int i = 0; i <= 180; i++) {
    glColor3ub(0, 100, 0);
    float r = 600.0f;
    float pi = 3.1416f;
    float a = (i * pi) / 180;
    float x = r * cos(a) + x15;
    float y = r * sin(a) + y15;
    glVertex2f(x, y);
}
glEnd();
glBegin(GL_POLYGON); ///villageCircle7
float x16 = 2000.0f;
float y16 = 3000.0f;
for (int i = 0; i <= 180; i++) {
    glColor3ub(0, 100, 0);
    float r = 600.0f;
    float pi = 3.1416f;
    float a = (i * pi) / 180;
    float x = r * cos(a) + x16;
    float y = r * sin(a) + y16;
    glVertex2f(x, y);
}
glEnd();
glBegin(GL_POLYGON); ///villageCircle8
float x17 = 3000.0f;
float y17 = 3000.0f;
for (int i = 0; i <= 180; i++) {
    glColor3ub(0, 100, 0);
    float r = 600.0f;
    float pi = 3.1416f;
    float a = (i * pi) / 180;
    float x = r * cos(a) + x17;
    float y = r * sin(a) + y17;
    glVertex2f(x, y);
}
glEnd();
glBegin(GL_POLYGON); ///villageCircle9
float x18 = 4400.0f;
float y18 = 3000.0f;
for (int i = 0; i <= 180; i++) {
    glColor3ub(0, 100, 0);
    float r = 800.0f;
    float pi = 3.1416f;
    float a = (i * pi) / 180;
    float x = r * cos(a) + x18;
    float y = r * sin(a) + y18;
    glVertex2f(x, y);
}
glEnd();
}

 void tree(){
    ///TreeCircle
        glBegin(GL_POLYGON); /// circleGround
    float x1 = 0.0f;
    float y1 =0.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(112,84,62);
        float r = 200.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + x1;
        float y = r * sin(a) + y1;
        glVertex2f(x, y);
    }
    glEnd();

     glLineWidth(4.5);
            glBegin(GL_LINE_LOOP); /// circleGroundBorder
    float x2 = 0.0f;
    float y2 =-0.38f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(170, 74, 68);
        float r = 220.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + x2;
        float y = r * sin(a) + y2;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_POLYGON);///treeGround1
    glColor3ub(170, 74, 68);
    glVertex2f(-215, -200.0);
    glVertex2f(216, -200.0);
    glVertex2f(216.0, -300.0);
    glVertex2f(-215.0, -300.0);
    glEnd();
    glBegin(GL_POLYGON);///treeGround2
    glVertex2f(-220.0, 00.0);
    glVertex2f(-215.0, -200.0);
    glVertex2f(-81.0, -200.0);
    glEnd();
    glBegin(GL_POLYGON);///treeGround2
    glVertex2f(215.0, 00.0);
    glVertex2f(216.0, -200.0);
    glVertex2f(77.0, -202.0);
    glEnd();
    glBegin(GL_POLYGON);///treeRoot1
    glColor3ub(165,99,60);
    glVertex2f(100.0, 0.0);
    glVertex2f(-100.0, 0.0);
    glVertex2f(-60.0, 780.0);
    glVertex2f(60.0, 780.0);
     glEnd();
    glBegin(GL_POLYGON);///treeRoot2
    glColor3ub(165,99,60);
    glVertex2f(-100.0, -0.38);
    glVertex2f(-138.0, -74.0);
    glVertex2f(0.0, -0.38);
    glEnd();
    glBegin(GL_POLYGON);///treeRoot3
    glColor3ub(165,99,60);
    glVertex2f(00.0, -0.38);
    glVertex2f(0.0, -123.0);
    glVertex2f(-39.0, -19.0);
    glEnd();
    glBegin(GL_POLYGON);///treeRoot3
    glColor3ub(165,99,60);
    glVertex2f(100.0, 0.0);
    glVertex2f(140.0, -80.0);
    glVertex2f(0.0, -.38);
    glEnd();
    glBegin(GL_POLYGON);///treeDal1
    glColor3ub(165,99,60);
    glVertex2f(245.0,975.0);
    glVertex2f(280.0, 990.0);
    glVertex2f(60.0,780.0);
    glVertex2f(29.0,860.0);
    glEnd();
    glBegin(GL_POLYGON);///treeWrong
    glColor3ub(165,99,60);
    glVertex2f(-61.0,839.0);
    glVertex2f(29.0, 859.0);
    glVertex2f(60.0,779.0);
    glVertex2f(-60.0,780.0);
    glEnd();
    glBegin(GL_POLYGON);///treeDal2
    glColor3ub(165,99,60);
    glVertex2f(-261.0,923.0);
    glVertex2f(28.0, 800.0);
    glVertex2f(-60.0,780.0);
    glVertex2f(-300.0,900.0);
    glEnd();
    glBegin(GL_POLYGON);///treeDal2
    glColor3ub(165,99,60);
    glVertex2f(0.0,1050.0);
    glVertex2f(29.0, 1050.0);
    glVertex2f(28.0,800.0);
    glVertex2f(-54.0,836.0);
    glEnd();
  glBegin(GL_POLYGON); /// TreeCircle
    float x3 = -289.0f;
    float y3 =1074.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,128,0);
        float r = 250.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + x3;
        float y = r * sin(a) + y3;
        glVertex2f(x, y);
    }
    glEnd();
      glBegin(GL_POLYGON); /// TreeCircle1
    float x4 = 0.0f;
    float y4 =1278.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,128,0);
        float r = 250.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + x4;
        float y = r * sin(a) + y4;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_POLYGON); /// TreeCircle2
    float x5 = 354.0f;
    float y5 =1094.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,128,0);
        float r = 290.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + x5;
        float y = r * sin(a) + y5;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_POLYGON); /// TreeCircle3
    float x6 = -570.0f;
    float y6 =1384.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,128,0);
        float r = 280.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + x6;
        float y = r * sin(a) + y6;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_POLYGON); /// TreeCircle4
    float x7 = -100.0f;
    float y7 =1566.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,128,0);
        float r = 280.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + x7;
        float y = r * sin(a) + y7;
        glVertex2f(x, y);
    }
    glEnd();
        glBegin(GL_POLYGON); /// TreeCircle5
    float x8 = 343.0f;
    float y8 =1490.0f;
    for (int i = 0; i < 300; i++)
    {
        glColor3ub(0,128,0);
        float r = 280.0f;
        float pi = 3.1416f;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + x8;
        float y = r * sin(a) + y8;
        glVertex2f(x, y);
    }
    glEnd();
 }
void renderDaySceneVillage() {
///GreenGrass BackGround
    glBegin(GL_POLYGON);
    glColor3ub(130,210,90);
    glVertex2f(-5000.0,800.0);
    glVertex2f(6000.0,800.0);
    glVertex2f(6000.0,-5000.0);
    glVertex2f(-5000.0,-5000.0);
    glEnd();

///SkyBackGround
    glBegin(GL_POLYGON);
    glColor3ub(135,206,250);
    glVertex2f(-5000.0,7000.0);
    glVertex2f(6000.0,7000.0);
    glVertex2f(6000.0,3000.0);
    glVertex2f(-5000.0,3000.0);
    glEnd();
///RiverWaterBackground
    glBegin(GL_POLYGON); ///rectangle1
    glColor3ub( 128,197,222);
    glVertex2f(-5000.0, 3000.0);
    glVertex2f(-5000.0, 800.0);
    glVertex2f(6000.0, 800.0);
    glVertex2f(6000.0, 3000.0);
    glEnd();
        ///LeftSideRiverRoad
    glBegin(GL_POLYGON);///Road
    glColor3ub(192, 147, 114);
    glVertex2f(2804.0,-497.0);
    glVertex2f(5000.0,-500.0);
    glVertex2f(5000.0,-800.0);
    glVertex2f(2721.0,-859.0);
    glEnd();
if (village.isRaining) {
        village.rightRiverOffset += 1.0f;
    }

    glPushMatrix();  // Save the current state


    glBegin(GL_POLYGON);  // Square1
    glColor3ub( 128,197,222);
    glVertex2f(739.0, -4980.0);
    glVertex2f(2800.0 + village.rightRiverOffset, -5000.0);
    glVertex2f(2986.0 + village.rightRiverOffset, -2935.0);
    glVertex2f(1111.0, -2880.0);
    glEnd();

    glBegin(GL_POLYGON);  // Square2
    glColor3ub( 128,197,222);
    glVertex2f(693.0, -2069.0);
    glVertex2f(2513.0 + village.rightRiverOffset, -1769.0);
    glVertex2f(2986.0 + village.rightRiverOffset, -2935.0);
    glVertex2f(1111.0, -2880.0);
    glEnd();

    glBegin(GL_POLYGON);  // Square3
    glColor3ub( 128,197,222);
    glVertex2f(693.0, -2069.0);  // Left vertex stays the same
    glVertex2f(2513.0 + village.rightRiverOffset, -1769.0);
    glVertex2f(2721.0 + village.rightRiverOffset, -859.0);
    glVertex2f(1159.0, -875.0);
    glVertex2f(892.0, -972.0);
    glEnd();

    glBegin(GL_POLYGON);  // Square4
    glColor3ub( 128,197,222);
    glVertex2f(1139.0, -525.0);  //
    glVertex2f(2804.0 + village.rightRiverOffset, -497.0);
    glVertex2f(2721.0 + village.rightRiverOffset, -859.0);
    glVertex2f(1159.0, -875.0);
    glEnd();

    glBegin(GL_POLYGON);  // Square5
    glColor3ub( 128,197,222);
    glVertex2f(1139.0, -525.0);
    glVertex2f(2804.0 + village.rightRiverOffset, -497.0);
    glVertex2f(2000.0 + village.rightRiverOffset, 800.0);
    glVertex2f(800.0, 800.0);
    glEnd();

    glBegin(GL_POLYGON);  // Square6
    glColor3ub( 128,197,222);
    glVertex2f(528.50, 346.50);
    glVertex2f(761.0, -532.0);
    glVertex2f(1139.0, -525.0);
    glVertex2f(902.0 + village.rightRiverOffset, 400.0);
    glEnd();

    glBegin(GL_POLYGON);  // Square7
    glColor3ub( 128,197,222);
    glVertex2f(528.50, 346.50);  // Left vertex stays the same
    glVertex2f(902.0 + village.rightRiverOffset, 400.0);  // Right vertex moves to the right
    glVertex2f(800.0, 800.0);  // Left vertex stays the same
    glVertex2f(100.0, 800.0);  // Left vertex stays the same
    glEnd();

    glPopMatrix();

    ///SmallBoat
    glBegin(GL_POLYGON);///trianale0fboat
    glColor3ub(0,0,0);
    glVertex2f(1200.0,-600.0);
    glVertex2f(1400.0, -740.0);
    glVertex2f(1430.0,-670.0);
    glEnd();
    glBegin(GL_POLYGON);///trianale0fboat1
    glColor3ub(0,0,0);
    glVertex2f(1400.0, -740.0);
    glVertex2f(1430.0,-670.0);
    glVertex2f(1720.0,-670.0);
    glVertex2f(1800.0,-740.0);
    glEnd();
    glBegin(GL_POLYGON);///trianale0fboat1
    glColor3ub(0,0,0);
    glVertex2f(1800.0,-740.0);
    glVertex2f(2000.0, -600.0);
    glVertex2f(1720.0,-670.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);///boatLine
    glColor3ub(0,0,0);
    glVertex2f(1200.0, -600.0);
    glVertex2f(1430.0,-580.0);
    glVertex2f(1430.0,-580.0);
    glVertex2f(1720.0,-580.0);
    glVertex2f(1720.0,-580.0);
    glVertex2f(2000.0,-600.0);
    glEnd();
    glBegin(GL_POLYGON);///trianale0fboat2
    glColor3ub(210,180,140);
    glVertex2f(1200.0,-600.0);
    glVertex2f(1430.0,-580.0);
    glVertex2f(1430.0,-670.0);
    glEnd();
    glBegin(GL_POLYGON);///trianale0fboat3
    glColor3ub(210,180,140);
    glVertex2f(1430.0,-580.0);
    glVertex2f(1720.0,-580.0);
    glVertex2f(1720.0,-670.0);
    glVertex2f(1430.0,-670.0);
    glEnd();
    glBegin(GL_POLYGON);///trianale0fboat4
    glColor3ub(210,180,140);
    glVertex2f(1720.0,-580.0);
    glVertex2f(2000.0,-600.0);
    glVertex2f(1720.0,-670.0);
    glEnd();
     glLineWidth(2);
    glBegin(GL_LINES);///triangle0fboat5
    glColor3ub(0,0,0);
    glVertex2f(1430.0,-580.0);
    glVertex2f(1430.0,-670.0);
    glVertex2f(1520.0,-580.0);
    glVertex2f(1519.5,-670.0);
    glVertex2f(1620.0,-580.0);
    glVertex2f(1620.0,-670.0);
    glVertex2f(1720.0,-580.0);
    glVertex2f(1720.0,-670.0);
    glVertex2f(1800.0,-585.0);
    glVertex2f(1799.0,-650.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);///triangle0fboat6
    glColor3ub(218,165,32);
    glVertex2f(1200.0,-600.0);
    glVertex2f(998.0,-648.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);///triangle0fboat7
    glColor3ub(218,165,32);
    glVertex2f(997.0,-578.0);
    glVertex2f(1000.0,-800.0);
    glEnd();


///sun
    glBegin(GL_POLYGON); ///sun
float x28= 1564.0f;
float y28 = 3861.0f;
for (int i = 0; i <= 300; i++) {
    glColor3ub(253, 184, 19 );
    float r = 170.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x28;
    float y = r * sin(a) + y28;
    glVertex2f(x, y);
}
glEnd();

}

// Function to render the night scene

void renderNightSceneVillage() {
    ///GreenGrass BackGround
    glBegin(GL_POLYGON);
    glColor3ub(0,100,0);
    glVertex2f(-5000.0,800.0);
    glVertex2f(6000.0,800.0);
    glVertex2f(6000.0,-5000.0);
    glVertex2f(-5000.0,-5000.0);
    glEnd();

///SkyBackGround
    glBegin(GL_POLYGON);
    glColor3ub(0,0,31);
    glVertex2f(-5000.0,7000.0);
    glVertex2f(6000.0,7000.0);
    glVertex2f(6000.0,3000.0);
    glVertex2f(-5000.0,3000.0);
    glEnd();
///RiverWaterBackground
    glBegin(GL_POLYGON); ///rectangle1
    glColor3ub( 0,0,31);
    glVertex2f(-5000.0, 3000.0);
    glVertex2f(-5000.0, 800.0);
    glVertex2f(6000.0, 800.0);
    glVertex2f(6000.0, 3000.0);
    glEnd();
        ///LeftSideRiverRoad
    glBegin(GL_POLYGON);///Road
    glColor3ub(192, 147, 114);
    glVertex2f(2804.0,-497.0);
    glVertex2f(5000.0,-500.0);
    glVertex2f(5000.0,-800.0);
    glVertex2f(2721.0,-859.0);
    glEnd();
      if (village.isRaining) {
        village.rightRiverOffset += .5f;
    }

    glPushMatrix();  // Save the current state

    // Draw the river polygons
    // SmallRiverFromBottom
    glBegin(GL_POLYGON);  // Square1
    glColor3ub(0,0,31);
    glVertex2f(739.0, -4980.0);
    glVertex2f(2800.0 + village.rightRiverOffset, -5000.0);
    glVertex2f(2986.0 + village.rightRiverOffset, -2935.0);
    glVertex2f(1111.0, -2880.0);
    glEnd();

    glBegin(GL_POLYGON);  // Square2
    glColor3ub(0,0,31);
    glVertex2f(693.0, -2069.0);
    glVertex2f(2513.0 + village.rightRiverOffset, -1769.0);  // Right vertex moves to the right
    glVertex2f(2986.0 + village.rightRiverOffset, -2935.0);  // Right vertex moves to the right
    glVertex2f(1111.0, -2880.0);  // Left vertex stays the same
    glEnd();

    glBegin(GL_POLYGON);  // Square3
    glColor3ub(0,0,31);
    glVertex2f(693.0, -2069.0);  // Left vertex stays the same
    glVertex2f(2513.0 + village.rightRiverOffset, -1769.0);  // Right vertex moves to the right
    glVertex2f(2721.0 + village.rightRiverOffset, -859.0);  // Right vertex moves to the right
    glVertex2f(1159.0, -875.0);  // Left vertex stays the same
    glVertex2f(892.0, -972.0);  // Left vertex stays the same
    glEnd();

    glBegin(GL_POLYGON);  // Square4
    glColor3ub(0,0,31);
    glVertex2f(1139.0, -525.0);  // Left vertex stays the same
    glVertex2f(2804.0 + village.rightRiverOffset, -497.0);  // Right vertex moves to the right
    glVertex2f(2721.0 + village.rightRiverOffset, -859.0);  // Right vertex moves to the right
    glVertex2f(1159.0, -875.0);  // Left vertex stays the same
    glEnd();

    glBegin(GL_POLYGON);  // Square5
    glColor3ub(0,0,31);
    glVertex2f(1139.0, -525.0);  // Left vertex stays the same
    glVertex2f(2804.0 + village.rightRiverOffset, -497.0);  // Right vertex moves to the right
    glVertex2f(2000.0 + village.rightRiverOffset, 800.0);  // Right vertex moves to the right
    glVertex2f(800.0, 800.0);  // Left vertex stays the same
    glEnd();

    glBegin(GL_POLYGON);  // Square6
    glColor3ub(0,0,31);
    glVertex2f(528.50, 346.50);  // Left vertex stays the same
    glVertex2f(761.0, -532.0);  // Left vertex stays the same
    glVertex2f(1139.0, -525.0);  // Left vertex stays the same
    glVertex2f(902.0 + village.rightRiverOffset, 400.0);  // Right vertex moves to the right
    glEnd();

    glBegin(GL_POLYGON);  // Square7
    glColor3ub(0,0,31);
    glVertex2f(528.50, 346.50);  // Left vertex stays the same
    glVertex2f(902.0 + village.rightRiverOffset, 400.0);  // Right vertex moves to the right
    glVertex2f(800.0, 800.0);  // Left vertex stays the same
    glVertex2f(100.0, 800.0);  // Left vertex stays the same
    glEnd();

    glPopMatrix();


///Moon
    glBegin(GL_POLYGON); ///moon
float x28= 2143.0f;
float y28 = 5503.0f;
for (int i = 0; i <= 300; i++) {
    glColor3ub(255,255,255 );
    float r = 300.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x28;
    float y = r * sin(a) + y28;
    glVertex2f(x, y);
}
glEnd();
///Star
glPointSize(3.0f);
glBegin(GL_POINTS);

    glVertex2f(-3450.23, 6521.56);
    glVertex2f(1200.34, 6894.33);
    glVertex2f(2800.78, 6100.01);
    glVertex2f(4850.67, 6556.45);
    glVertex2f(1333.45, 5123.22);
    glVertex2f(2987.64, 4850.01);
    glVertex2f(-2800.77, 4905.19);
    glVertex2f(4500.34, 6011.76);
    glVertex2f(-4001.49, 5129.11);
    glVertex2f(3212.22, 5345.12);
    glVertex2f(-4800.89, 6211.44);
    glVertex2f(2001.32, 5421.89);
    glVertex2f(4001.57, 3219.44);
    glVertex2f(-1501.67, 4561.22);
    glVertex2f(3129.44, 4099.33);
    glVertex2f(2401.23, 4950.88);
    glVertex2f(1073.41, 4782.56);
    glVertex2f(-4999.00, 6289.45);
    glVertex2f(-1999.77, 5290.78);
    glVertex2f(3000.12, 5310.22);
    glVertex2f(-3600.45, 6902.34);
    glVertex2f(4700.23, 6725.67);
    glVertex2f(2100.12, 6850.78);
    glVertex2f(3500.56, 6501.45);
    glVertex2f(-4400.89, 6122.56);
    glVertex2f(-1200.77, 6803.12);
    glVertex2f(2500.45, 6791.11);
    glVertex2f(1000.67, 6300.45);
    glVertex2f(-3000.23, 6600.12);
    glVertex2f(5000.88, 6450.78);
    glVertex2f(-3900.56, 6311.99);
    glVertex2f(2800.23, 6150.34);
    glVertex2f(3700.67, 5902.88);
    glVertex2f(-4500.45, 5789.22);
    glVertex2f(5200.12, 6010.45);
    glVertex2f(600.56, 6450.89);
    glVertex2f(-1600.88, 6340.23);
    glVertex2f(4400.78, 6111.67);
    glVertex2f(5100.45, 6540.22);
    glVertex2f(-4700.67, 6200.11);
    glVertex2f(3900.89, 6802.33);
    glVertex2f(1800.23, 6720.45);
    glVertex2f(4200.56, 6401.12);
    glVertex2f(-2000.45, 6901.78);
    glVertex2f(1500.89, 6890.33);


glEnd();



}
    ///BigBoatRight1
    void boat1(){
        glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef( village.boat1Position, 0.0f, 0.0f);
    glBegin(GL_POLYGON);///trianale0fboat1
    glColor3ub(0,0,0);
    glVertex2f(1600.0,1900.0);
    glVertex2f(2000.0, 1600.0);
    glVertex2f(2200.0,1800.0);
    glEnd();
    glBegin(GL_POLYGON);///Square0fboat2
    glColor3ub(0,0,0);
    glVertex2f(2200.0,1800.0);
    glVertex2f(2000.0, 1600.0);
    glVertex2f(2860.0,1520.0);
    glVertex2f(3600.0,1600.0);
    glVertex2f(3400.0,1800.0);
    glEnd();
    glBegin(GL_POLYGON);///Triangle0fboat2
    glColor3ub(0,0,0);
    glVertex2f(3600.0,1600.0);
    glVertex2f(4000.0,1900.0);
    glVertex2f(3400.0, 1800.0);
    glEnd();
    glBegin(GL_POLYGON);///BoatUpper
    glColor3ub(139,69,19);
    glVertex2f(2600.0,2100.0);
    glVertex2f(3300.0,2100.0);
    glVertex2f(3400.0, 1800.0);
    glVertex2f(2400.0, 1800.0);
    glEnd();
     glLineWidth(1);
    glBegin(GL_LINES);///BoatUpperLINe
    glColor3ub(0,0,0);
    glVertex2f(2600.0,2100.0);
    glVertex2f(2600.0,1800.0);
    glVertex2f(2796.0, 2100.0);
    glVertex2f(2796.0, 1800.0);
    glVertex2f(3000.0, 2100.0);
    glVertex2f(3000.0, 1800.0);
    glVertex2f(3200.0, 2100.0);
    glVertex2f(3200.0, 1800.0);
    glVertex2f(3300.0, 2100.0);
    glVertex2f(3400.0, 1800.0);
    glVertex2f(2600.0, 2100.0);
    glVertex2f(3300.0, 2100.0);
    glVertex2f(2600.0, 2100.0);
    glVertex2f(2400.0, 1800.0);
    glVertex2f(2535.0, 2002.0);
    glVertex2f(3333.0, 2000.0);
    glVertex2f(2469.0, 1903.0);
    glVertex2f(3366.0, 1900.0);

    glEnd();
    glBegin(GL_POLYGON);///BoatPaal
    glColor3ub(255,228,225);
    glVertex2f(2450.0,2650.0);
    glVertex2f(2100.0,2400.0);
    glVertex2f(2050.0, 2200.0);
    glVertex2f(2100.0, 2000.0);
    glVertex2f(2400.0,1800.0);
    glVertex2f(2200.0, 2200.0);
    glVertex2f(2450.0,2650.0);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);///BoatUpperLINe
    glColor3ub(139,69,19);
    glVertex2f(2400.0, 2600.0);
    glVertex2f(3300.0, 2100.0);
    glVertex2f(2400.0, 2400.0);
    glVertex2f(3300.0, 2100.0);
    glVertex2f(2400.0, 2700.0);
    glVertex2f(2400.0, 1800.0);
    glEnd();
    glBegin(GL_POLYGON);///Boitha
    glColor3ub(139,69,19);
    glVertex2f(3600.0, 2100.0);
    glVertex2f(3700.0, 1450.0);
    glVertex2f(3800.0, 1450.0);
    glEnd();
    glPopMatrix();
    }
void boat2(){
       ///BigBoatLeftt2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(village. boat2Position, 0.0f, 0.0f);
    glBegin(GL_POLYGON);///Squarebody
            glColor3ub(0,0,0);
    glVertex2f(-2100.0, 2400.0);
    glVertex2f(-1300.0, 2400.0);
    glVertex2f(-1200.0, 2200.0);
    glVertex2f(-1660.0, 2140.0);
    glVertex2f(-2200.0, 2200.0);
    glEnd();
    glBegin(GL_POLYGON);///triangle1
            glColor3ub(0,0,0);
    glVertex2f(-2600.0, 2500.0);
    glVertex2f(-2100.0, 2400.0);
    glVertex2f(-2200.0, 2200.0);
    glEnd();
        glBegin(GL_POLYGON);///triangle1
            glColor3ub(0,0,0);
    glVertex2f(-1300.0, 2400.0);
    glVertex2f(-800.0, 2500.0);
    glVertex2f(-1200.0, 2200.0);
    glEnd();
       glBegin(GL_POLYGON);///choi
            glColor3ub(218,165,32);
    glVertex2f(-2050.0, 2600.0);
    glVertex2f(-1400.0, 2600.0);
    glVertex2f(-1300.0, 2400.0);
    glVertex2f(-2100.0, 2400.0);
    glEnd();
    glPopMatrix();
    }
    void windmill()
    {

    }


      ///Megh
void cloud(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(village._cloud, 0.0f, 0.0f);
    glBegin(GL_POLYGON); ///meghCircle1
float x19 = -2976.0f;
float y19 = 4649.0f;
for (int i = 0; i <360; i++) {
    glColor3ub(255,255,255);
    float r = 300.0f;
    float pi = 3.1416f;
    float a = (i * 2*pi) / 360;
    float x = r * cos(a) + x19;
    float y = r * sin(a) + y19;
    glVertex2f(x, y);
}
glEnd();
    glBegin(GL_POLYGON); ///meghCircle2
float x20 = -2592.0f;
float y20 = 4863.0f;
for (int i = 0; i <300; i++) {
    glColor3ub(255,255,255);
    float r = 400.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x20;
    float y = r * sin(a) + y20;
    glVertex2f(x, y);
}
glEnd();
    glBegin(GL_POLYGON); ///meghCircle3
float x21 = -2196.0f;
float y21 = 4841.0f;
for (int i = 0; i <= 300; i++) {
    glColor3ub(255,255,255);
    float r = 300.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x21;
    float y = r * sin(a) + y21;
    glVertex2f(x, y);
}
glEnd();
    glBegin(GL_POLYGON); ///meghCircle4
float x22 = -658.0f;
float y22 = 4818.0f;
for (int i = 0; i <= 300; i++) {
    glColor3ub(255,255,255);
    float r = 300.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x22;
    float y = r * sin(a) + y22;
    glVertex2f(x, y);
}
glEnd();
    glBegin(GL_POLYGON); ///meghCircle5
float x23 = -200.0f;
float y23 = 4959.0f;
for (int i = 0; i <= 300; i++) {
    glColor3ub(255,255,255);
    float r = 300.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x23;
    float y = r * sin(a) + y23;
    glVertex2f(x, y);
}
glEnd();
    glBegin(GL_POLYGON); ///meghCircle6
float x24= -300.0f;
float y24 = 4652.0f;
for (int i = 0; i <= 300; i++) {
    glColor3ub(255,255,255);
    float r = 300.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x24;
    float y = r * sin(a) + y24;
    glVertex2f(x, y);
}
glEnd();
    glBegin(GL_POLYGON); ///meghCircle7
float x25= 4325.0f;
float y25 = 5179.0f;
for (int i = 0; i <= 300; i++) {
    glColor3ub(255,255,255);
    float r = 400.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x25;
    float y = r * sin(a) + y25;
    glVertex2f(x, y);
}
glEnd();
    glBegin(GL_POLYGON); ///meghCircle8
float x26= 3949.0f;
float y26 = 4881.0f;
for (int i = 0; i <= 300; i++) {
    glColor3ub(255,255,255);
    float r = 400.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x26;
    float y = r * sin(a) + y26;
    glVertex2f(x, y);
}
glEnd();

    glBegin(GL_POLYGON); ///meghCircle9
float x27= 3316.0f;
float y27 = 4861.0f;
for (int i = 0; i <= 300; i++) {
    glColor3ub(255,255,255);
    float r = 400.0f;
    float pi = 3.1416f;
    float a = (i *2* pi) / 300;
    float x = r * cos(a) + x27;
    float y = r * sin(a) + y27;
    glVertex2f(x, y);
}
glEnd();
glPopMatrix();
}
void toggleRain(bool startRain) {
    if (startRain) {
        village.isRaining = true;
    } else {
       village. isRaining = false;
    }
}

// Function to render rain
void Rain() {
    if (village.isRaining) {
        glPushMatrix();
        glTranslatef(0.0f, village.rainPositionY, 0.0f);  // Move raindrops downwards

        // Draw raindrops (as lines)
        glColor3ub(255,255,255);  // Light blue color for rain
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        for (float x = -5000.0f; x < 6000.0f; x += 200.0f) {
            for (float y = 9000.0f; y > -10000.0f; y -= 600.0f) {
                glVertex2f(x, y);
                glVertex2f(x, y - 100.0f);  // Length of raindrop
            }
        }
        glEnd();

        glPopMatrix();
    }
}





void villagescene() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    setOrtho();

    if (village.isDay) {
        renderDaySceneVillage(); // Render the day scene for the village
    } else {
        renderNightSceneVillage(); // Render the night scene for the village
    }

    // Additional village elements
    codes2();
    boat2();
    boat1();
    tree();
    cloud();
    Rain();

    glFlush();
}

void cityscene() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    setOrtho();

    if (city.isDay) {
        renderDayScene(); // Render the day scene for the city
    } else {
        renderNightScene(); // Render the night scene for the city
    }
    codes();  // allexceptanimation
    bus();  // Draw bus
    car();
    megh();
    palne();



    glFlush();
}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

if(currentscene==1)
{
    villagescene();
}
else if(currentscene==2)
{
    cityscene();
}
    glutSwapBuffers();
}

// Update function for both city and village
void update(int value) {
    if (currentscene == 1) { // Village scene
        if (village.isMoving) {
            village.boat1Position -= village.boat1Speed;
            if (village.boat1Position < -9000) {
                village.boat1Position = 8000;  // Reset position if it exceeds the boundary
            }
            village.boat2Position += village.boat2Speed;
            if (village.boat2Position > 15000) {
                village.boat2Position = -20000;  // Reset position if it exceeds the boundary
            }
        }

        // Update cloud position in village
        village._cloud += 10;  // Move cloud
        if (village._cloud > 10000) {
            village._cloud = -10000;  // Reset cloud position
        }

        // Handle rain falling
        if (village.isRaining) {
            village.rainPositionY -= 30.0f;  // Adjust speed of rain falling
            if (village.rainPositionY < -5000.0f) {  // Reset rain to top
                village.rainPositionY = 6000.0f;
            }
        }
    } else if (currentscene == 2) { // City scene
        if (city.isMoving) {
            city.busPosition += city.busSpeed;
            if (city.busPosition > 15000) {
                city.busPosition = -20000;  // Reset position if it exceeds the boundary
            }

            city.carPosition -= city.carSpeed;
            if (city.carPosition < -20000) {
                city.carPosition = 5700;  // Reset position if it exceeds the boundary
            }
        }

        // Update plane movement in city
        if (city.isPlaneMoving) {
            city._move2 -= 30;  // Move the plane left
            if (city._move2 < -7000) {  // If the plane moves too far left, reset its position
                city._move2 = 10000;
            }
        }

        // Update additional city variable
        city._move3 += 25;
        if (city._move3 > 10000) {
            city._move3 = -10000;
        }
    }

    glutPostRedisplay();  // Request display update
    glutTimerFunc(10, update, 0);  // Continue updating
}
void handlekeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'v':
   currentscene=1;
    break;
case 'c':
    currentscene=2;
    break;
        case 's':  // Stop movement
            if (currentscene == 1) {
                village.isMoving = false;
            } else if (currentscene == 2) {
                city.isMoving = false;
            }
            break;
        case 'm':  // Start movement
            if (currentscene == 1) {
                village.isMoving = true;
            } else if (currentscene == 2) {
                city.isMoving = true;
            }
            break;
        case 'd':  // Switch to day
            if (currentscene == 1) {
                village.isDay = true;
            } else if (currentscene == 2) {
                city.isDay = true;
            }
            break;
        case 'n':  // Switch to night
            if (currentscene == 1) {
                village.isDay = false;
            } else if (currentscene == 2) {
                city.isDay = false;
            }
            break;
        case 'r':  // Start raining in the village
            if (currentscene == 1) {
                village.isRaining = true;
            }
            break;
        case 'b':  // Stop raining in the village
            if (currentscene == 1) {
                village.isRaining = false;
            }
            break;
        case 'f':  // Start plane movement in the city
            if (currentscene == 2) {
                city.isPlaneMoving = true;
            }
            break;
    }

    glutPostRedisplay();  // Update the display after the key press
}
void handleMouse(int button, int state, int x, int y) {
    if (currentscene == 1) { // Village scene
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            village.boat1Speed += 5.0f; // Increase boat speed on left click
        }
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            village.boat1Speed = (village.boat1Speed > 5.0f) ? village.boat1Speed - 5.0f : 0; // Decrease boat speed
        }
    } else if (currentscene == 2) { // City scene
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            city.busSpeed += 25.0f; // Increase bus speed on left click
            city.carSpeed += 30.0f;
        }
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            city.busSpeed = (city.busSpeed > 25.0f) ? city.busSpeed - 25.0f : 0; // Decrease bus speed
            city.carSpeed = (city.carSpeed > 25.0f) ? city.carSpeed - 25.0f : 0;
        }
    }
    glutPostRedisplay();  // Request display update
}





int main(int argc, char** argv) {
    glutInit(&argc, argv);  // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set single buffering and RGB mode
    glutInitWindowSize(1000, 700);  // Set the window size
    glutCreateWindow("Village and City scene");  // Create the window with a title

 // Set the orthographic view
    glutDisplayFunc(display);  // Register display callback handler
    glutTimerFunc(10, update, 0); // Timer for the car movement
    glutKeyboardFunc(handlekeypress);
    glutMouseFunc(handleMouse);
    glutMainLoop();  // Enter the event-processing loop
    return 0;
}
