#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

// ============================================================
//      3D SPACE STATION & SOLAR SYSTEM SIMULATION
//                FINAL PROJECT VERSION
// ============================================================

#define PI 3.1415926f

// ============================================================
//                    ANIMATION VARIABLES
// ============================================================

float earthOrbit = 0.0f;
float moonOrbit = 0.0f;
float marsOrbit = 0.0f;
float saturnOrbit = 0.0f;

float satelliteOrbit = 0.0f;
float stationOrbit = 0.0f;

float sunRotation = 0.0f;
float earthRotation = 0.0f;
float moonRotation = 0.0f;
float marsRotation = 0.0f;
float saturnRotation = 0.0f;

float shootingStarX = -10.0f;
float shootingStarY = 6.0f;

bool animationRunning = true;


// ============================================================
//                      CAMERA VARIABLES
// ============================================================

float cameraX = 0.0f;
float cameraY = 5.0f;
float cameraZ = 16.0f;

float lookX = 0.0f;
float lookY = 0.0f;
float lookZ = 0.0f;


// ============================================================
//                         MATERIAL
// ============================================================

void setMaterial(float r, float g, float b)
{
    GLfloat material[] =
    {
        r, g, b, 1.0f
    };

    glMaterialfv(
        GL_FRONT,
        GL_AMBIENT_AND_DIFFUSE,
        material
    );
}


// ============================================================
//                         ORBIT
// ============================================================

void drawOrbit(float radius)
{
    glDisable(GL_LIGHTING);

    glColor3f(
        0.28f,
        0.28f,
        0.35f
    );

    glLineWidth(1.0f);

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 120; i++)
    {
        float angle =
            2.0f * PI * i / 120.0f;

        glVertex3f(
            radius * cos(angle),
            0.0f,
            radius * sin(angle)
        );
    }

    glEnd();

    glEnable(GL_LIGHTING);
}


// ============================================================
//                         STARS
// ============================================================

void drawStars()
{
    glDisable(GL_LIGHTING);

    glPointSize(2.0f);

    glBegin(GL_POINTS);

    glColor3f(
        1.0f,
        1.0f,
        1.0f
    );

    glVertex3f(-12,  7, -10);
    glVertex3f(-10,  3, -12);
    glVertex3f(-9,  -5, -8);
    glVertex3f(-8,   6, -14);
    glVertex3f(-7,  -4, -11);

    glVertex3f(-6,   8, -15);
    glVertex3f(-5,   2, -10);
    glVertex3f(-4,  -6, -12);
    glVertex3f(-3,   5, -14);
    glVertex3f(-2,  -4, -9);

    glVertex3f(-1,   7, -13);
    glVertex3f( 1,  -6, -12);
    glVertex3f( 2,   5, -15);
    glVertex3f( 3,  -3, -10);
    glVertex3f( 4,   8, -14);

    glVertex3f( 5,  -5, -11);
    glVertex3f( 6,   4, -13);
    glVertex3f( 7,  -7, -15);
    glVertex3f( 8,   6, -12);
    glVertex3f( 9,  -2, -10);

    glVertex3f(10,   7, -14);
    glVertex3f(11,  -4, -13);
    glVertex3f(12,   3, -11);

    glVertex3f(-11, -7, -16);
    glVertex3f(-7,   9, -17);
    glVertex3f(-3,  -8, -16);

    glVertex3f( 3,   9, -17);
    glVertex3f( 7,  -8, -16);
    glVertex3f(11,   8, -18);

    glEnd();

    glEnable(GL_LIGHTING);
}


// ============================================================
//                     SHOOTING STAR
// ============================================================

void drawShootingStar()
{
    glDisable(GL_LIGHTING);

    glLineWidth(3.0f);

    glBegin(GL_LINES);

    glColor3f(
        1.0f,
        1.0f,
        1.0f
    );

    glVertex3f(
        shootingStarX,
        shootingStarY,
        -6.0f
    );

    glColor3f(
        0.2f,
        0.2f,
        0.3f
    );

    glVertex3f(
        shootingStarX - 1.3f,
        shootingStarY + 0.6f,
        -6.0f
    );

    glEnd();

    glPointSize(6.0f);

    glBegin(GL_POINTS);

    glColor3f(
        1.0f,
        1.0f,
        0.8f
    );

    glVertex3f(
        shootingStarX,
        shootingStarY,
        -6.0f
    );

    glEnd();

    glEnable(GL_LIGHTING);
}


// ============================================================
//                           SUN
// ============================================================

void drawSun()
{
    glPushMatrix();

    glRotatef(
        sunRotation,
        0.0f,
        1.0f,
        0.0f
    );

    // Sun is self illuminated-looking
    glDisable(GL_LIGHTING);

    glColor3f(
        1.0f,
        0.55f,
        0.02f
    );

    glutSolidSphere(
        1.0,
        45,
        45
    );

    glEnable(GL_LIGHTING);

    glPopMatrix();
}


// ============================================================
//                          EARTH
// ============================================================

void drawEarth()
{
    glPushMatrix();

    glRotatef(
        earthRotation,
        0.0f,
        1.0f,
        0.0f
    );

    setMaterial(
        0.05f,
        0.30f,
        0.95f
    );

    glutSolidSphere(
        0.48,
        35,
        35
    );


    // --------------------------------------------------------
    // Simple green land section
    // --------------------------------------------------------

    glPushMatrix();

    glTranslatef(
        0.0f,
        0.15f,
        0.43f
    );

    setMaterial(
        0.10f,
        0.65f,
        0.18f
    );

    glScalef(
        0.45f,
        0.25f,
        0.08f
    );

    glutSolidSphere(
        0.5,
        15,
        15
    );

    glPopMatrix();


    glPopMatrix();
}


// ============================================================
//                           MOON
// ============================================================

void drawMoon()
{
    glPushMatrix();

    glRotatef(
        moonRotation,
        0.0f,
        1.0f,
        0.0f
    );

    setMaterial(
        0.65f,
        0.65f,
        0.65f
    );

    glutSolidSphere(
        0.17,
        20,
        20
    );

    glPopMatrix();
}


// ============================================================
//                           MARS
// ============================================================

void drawMars()
{
    glPushMatrix();

    glRotatef(
        marsRotation,
        0.0f,
        1.0f,
        0.0f
    );

    setMaterial(
        0.75f,
        0.12f,
        0.04f
    );

    glutSolidSphere(
        0.38,
        30,
        30
    );

    glPopMatrix();
}


// ============================================================
//                       SATURN RING
// ============================================================

void drawSaturnRing()
{
    glDisable(GL_LIGHTING);

    glColor3f(
        0.75f,
        0.65f,
        0.40f
    );

    glBegin(GL_QUAD_STRIP);

    for (int i = 0; i <= 100; i++)
    {
        float angle =
            2.0f * PI * i / 100.0f;

        float x1 =
            0.72f * cos(angle);

        float z1 =
            0.72f * sin(angle);

        float x2 =
            1.15f * cos(angle);

        float z2 =
            1.15f * sin(angle);

        glVertex3f(
            x1,
            0.0f,
            z1
        );

        glVertex3f(
            x2,
            0.0f,
            z2
        );
    }

    glEnd();

    glEnable(GL_LIGHTING);
}


// ============================================================
//                          SATURN
// ============================================================

void drawSaturn()
{
    glPushMatrix();

    glRotatef(
        saturnRotation,
        0.0f,
        1.0f,
        0.0f
    );

    setMaterial(
        0.85f,
        0.68f,
        0.35f
    );

    glutSolidSphere(
        0.62,
        35,
        35
    );

    drawSaturnRing();

    glPopMatrix();
}


// ============================================================
//                        SATELLITE
// ============================================================

void drawSatellite()
{
    // Main body
    glPushMatrix();

    setMaterial(
        0.75f,
        0.75f,
        0.80f
    );

    glScalef(
        0.28f,
        0.20f,
        0.20f
    );

    glutSolidCube(1.0);

    glPopMatrix();


    // Left solar panel
    glPushMatrix();

    glTranslatef(
        -0.38f,
        0.0f,
        0.0f
    );

    setMaterial(
        0.03f,
        0.15f,
        0.70f
    );

    glScalef(
        0.48f,
        0.04f,
        0.28f
    );

    glutSolidCube(1.0);

    glPopMatrix();


    // Right solar panel
    glPushMatrix();

    glTranslatef(
        0.38f,
        0.0f,
        0.0f
    );

    setMaterial(
        0.03f,
        0.15f,
        0.70f
    );

    glScalef(
        0.48f,
        0.04f,
        0.28f
    );

    glutSolidCube(1.0);

    glPopMatrix();
}


// ============================================================
//                     SPACE STATION
// ============================================================

void drawSpaceStation()
{
    // --------------------------------------------------------
    // Central body
    // --------------------------------------------------------

    glPushMatrix();

    setMaterial(
        0.75f,
        0.78f,
        0.82f
    );

    glScalef(
        0.9f,
        0.22f,
        0.25f
    );

    glutSolidCube(1.0);

    glPopMatrix();


    // --------------------------------------------------------
    // Left module
    // --------------------------------------------------------

    glPushMatrix();

    glTranslatef(
        -0.70f,
        0.0f,
        0.0f
    );

    setMaterial(
        0.60f,
        0.65f,
        0.70f
    );

    glScalef(
        0.45f,
        0.32f,
        0.32f
    );

    glutSolidCube(1.0);

    glPopMatrix();


    // --------------------------------------------------------
    // Right module
    // --------------------------------------------------------

    glPushMatrix();

    glTranslatef(
        0.70f,
        0.0f,
        0.0f
    );

    glScalef(
        0.45f,
        0.32f,
        0.32f
    );

    glutSolidCube(1.0);

    glPopMatrix();


    // --------------------------------------------------------
    // Vertical module
    // --------------------------------------------------------

    glPushMatrix();

    glTranslatef(
        0.0f,
        0.38f,
        0.0f
    );

    setMaterial(
        0.70f,
        0.72f,
        0.76f
    );

    glScalef(
        0.20f,
        0.65f,
        0.20f
    );

    glutSolidCube(1.0);

    glPopMatrix();


    // --------------------------------------------------------
    // Left large solar panel
    // --------------------------------------------------------

    glPushMatrix();

    glTranslatef(
        -1.35f,
        0.0f,
        0.0f
    );

    setMaterial(
        0.03f,
        0.10f,
        0.55f
    );

    glScalef(
        1.20f,
        0.05f,
        0.55f
    );

    glutSolidCube(1.0);

    glPopMatrix();


    // --------------------------------------------------------
    // Right large solar panel
    // --------------------------------------------------------

    glPushMatrix();

    glTranslatef(
        1.35f,
        0.0f,
        0.0f
    );

    setMaterial(
        0.03f,
        0.10f,
        0.55f
    );

    glScalef(
        1.20f,
        0.05f,
        0.55f
    );

    glutSolidCube(1.0);

    glPopMatrix();


    // --------------------------------------------------------
    // Communication dish
    // --------------------------------------------------------

    glPushMatrix();

    glTranslatef(
        0.0f,
        0.72f,
        0.0f
    );

    setMaterial(
        0.85f,
        0.85f,
        0.88f
    );

    glutSolidSphere(
        0.16,
        15,
        15
    );

    glPopMatrix();
}


// ============================================================
//                     ASTEROID BELT
// ============================================================

void drawAsteroidBelt()
{
    for (int i = 0; i < 45; i++)
    {
        float angle =
            i * (360.0f / 45.0f);

        float rad =
            angle * PI / 180.0f;

        float radius =
            8.2f + (i % 4) * 0.12f;

        float x =
            radius * cos(rad);

        float z =
            radius * sin(rad);

        float y =
            ((i % 5) - 2) * 0.06f;


        glPushMatrix();

        glTranslatef(
            x,
            y,
            z
        );

        glRotatef(
            angle * 2.0f,
            1.0f,
            1.0f,
            0.0f
        );

        setMaterial(
            0.35f,
            0.30f,
            0.25f
        );

        float size =
            0.06f + (i % 3) * 0.025f;

        glutSolidSphere(
            size,
            8,
            8
        );

        glPopMatrix();
    }
}


// ============================================================
//                     EARTH SYSTEM
// ============================================================

void drawEarthSystem()
{
    glPushMatrix();


    // ========================================================
    //               EARTH ORBITS AROUND SUN
    // ========================================================

    glRotatef(
        earthOrbit,
        0.0f,
        1.0f,
        0.0f
    );

    glTranslatef(
        4.0f,
        0.0f,
        0.0f
    );


    // ========================================================
    //                         EARTH
    // ========================================================

    drawEarth();


    // ========================================================
    //                     MOON ORBIT LINE
    // ========================================================

    drawOrbit(0.95f);


    // ========================================================
    //                          MOON
    // ========================================================

    glPushMatrix();

    glRotatef(
        moonOrbit,
        0.0f,
        1.0f,
        0.0f
    );

    glTranslatef(
        0.95f,
        0.0f,
        0.0f
    );

    drawMoon();

    glPopMatrix();


    // ========================================================
    //                        SATELLITE
    // ========================================================

    glPushMatrix();

    glRotatef(
        satelliteOrbit,
        0.0f,
        1.0f,
        0.0f
    );

    glTranslatef(
        1.35f,
        0.18f,
        0.0f
    );

    glRotatef(
        satelliteOrbit,
        0.0f,
        1.0f,
        0.0f
    );

    glScalef(
        0.55f,
        0.55f,
        0.55f
    );

    drawSatellite();

    glPopMatrix();


    // ========================================================
    //                      SPACE STATION
    // ========================================================

    glPushMatrix();

    glRotatef(
        stationOrbit,
        0.0f,
        1.0f,
        0.0f
    );

    glTranslatef(
        1.90f,
        0.35f,
        0.0f
    );

    glRotatef(
        stationOrbit * 2.0f,
        0.0f,
        1.0f,
        0.0f
    );

    glScalef(
        0.40f,
        0.40f,
        0.40f
    );

    drawSpaceStation();

    glPopMatrix();


    glPopMatrix();
}


// ============================================================
//                         DISPLAY
// ============================================================

void display()
{
    glClearColor(
        0.0f,
        0.0f,
        0.025f,
        1.0f
    );

    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );


    glMatrixMode(
        GL_MODELVIEW
    );

    glLoadIdentity();


    // ========================================================
    //                          CAMERA
    // ========================================================

    gluLookAt(
        cameraX,
        cameraY,
        cameraZ,

        lookX,
        lookY,
        lookZ,

        0.0f,
        1.0f,
        0.0f
    );


    // ========================================================
    //                         SUN LIGHT
    // ========================================================

    GLfloat lightPosition[] =
    {
        0.0f,
        0.0f,
        0.0f,
        1.0f
    };

    GLfloat lightDiffuse[] =
    {
        1.0f,
        0.95f,
        0.80f,
        1.0f
    };

    GLfloat lightSpecular[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    glLightfv(
        GL_LIGHT0,
        GL_POSITION,
        lightPosition
    );

    glLightfv(
        GL_LIGHT0,
        GL_DIFFUSE,
        lightDiffuse
    );

    glLightfv(
        GL_LIGHT0,
        GL_SPECULAR,
        lightSpecular
    );


    // ========================================================
    //                         BACKGROUND
    // ========================================================

    drawStars();

    drawShootingStar();


    // ========================================================
    //                            SUN
    // ========================================================

    drawSun();


    // ========================================================
    //                        ORBIT PATHS
    // ========================================================

    drawOrbit(4.0f);   // Earth
    drawOrbit(6.3f);   // Mars
    drawOrbit(10.0f);  // Saturn


    // ========================================================
    //                       EARTH SYSTEM
    // ========================================================

    drawEarthSystem();


    // ========================================================
    //                            MARS
    // ========================================================

    glPushMatrix();

    glRotatef(
        marsOrbit,
        0.0f,
        1.0f,
        0.0f
    );

    glTranslatef(
        6.3f,
        0.0f,
        0.0f
    );

    drawMars();

    glPopMatrix();


    // ========================================================
    //                       ASTEROID BELT
    // ========================================================

    drawAsteroidBelt();


    // ========================================================
    //                           SATURN
    // ========================================================

    glPushMatrix();

    glRotatef(
        saturnOrbit,
        0.0f,
        1.0f,
        0.0f
    );

    glTranslatef(
        10.0f,
        0.0f,
        0.0f
    );

    glRotatef(
        18.0f,
        1.0f,
        0.0f,
        1.0f
    );

    drawSaturn();

    glPopMatrix();


    glutSwapBuffers();
}


// ============================================================
//                          UPDATE
// ============================================================

void update(int value)
{
    if (animationRunning)
    {
        // ====================================================
        //                     PLANET ORBITS
        // ====================================================

        earthOrbit += 0.30f;

        marsOrbit += 0.20f;

        saturnOrbit += 0.10f;


        // ====================================================
        //                    EARTH SYSTEM
        // ====================================================

        moonOrbit += 1.8f;

        satelliteOrbit += 2.8f;

        stationOrbit += 1.0f;


        // ====================================================
        //                  OWN AXIS ROTATION
        // ====================================================

        sunRotation += 0.15f;

        earthRotation += 2.0f;

        moonRotation += 1.0f;

        marsRotation += 1.3f;

        saturnRotation += 1.0f;


        // ====================================================
        //                    SHOOTING STAR
        // ====================================================

        shootingStarX += 0.08f;
        shootingStarY -= 0.035f;

        if (shootingStarX > 12.0f)
        {
            shootingStarX = -12.0f;
            shootingStarY = 7.0f;
        }


        // ====================================================
        //                    RESET ANGLES
        // ====================================================

        if (earthOrbit > 360)
            earthOrbit -= 360;

        if (marsOrbit > 360)
            marsOrbit -= 360;

        if (saturnOrbit > 360)
            saturnOrbit -= 360;

        if (moonOrbit > 360)
            moonOrbit -= 360;

        if (satelliteOrbit > 360)
            satelliteOrbit -= 360;

        if (stationOrbit > 360)
            stationOrbit -= 360;

        if (sunRotation > 360)
            sunRotation -= 360;

        if (earthRotation > 360)
            earthRotation -= 360;

        if (moonRotation > 360)
            moonRotation -= 360;

        if (marsRotation > 360)
            marsRotation -= 360;

        if (saturnRotation > 360)
            saturnRotation -= 360;
    }


    glutPostRedisplay();


    glutTimerFunc(
        20,
        update,
        0
    );
}


// ============================================================
//                         KEYBOARD
// ============================================================

void keyboard(
    unsigned char key,
    int x,
    int y
)
{
    switch (key)
    {
        // ====================================================
        //                    FREE CAMERA
        // ====================================================

        case 'w':
        case 'W':

            cameraZ -= 0.5f;

            break;


        case 's':
        case 'S':

            cameraZ += 0.5f;

            break;


        case 'a':
        case 'A':

            cameraX -= 0.5f;

            break;


        case 'd':
        case 'D':

            cameraX += 0.5f;

            break;


        // ====================================================
        //                  CAMERA VIEW 1
        //                FRONT / MAIN VIEW
        // ====================================================

        case '1':

            cameraX = 0.0f;
            cameraY = 5.0f;
            cameraZ = 16.0f;

            lookX = 0.0f;
            lookY = 0.0f;
            lookZ = 0.0f;

            break;


        // ====================================================
        //                  CAMERA VIEW 2
        //                     TOP VIEW
        // ====================================================

        case '2':

            cameraX = 0.1f;
            cameraY = 17.0f;
            cameraZ = 0.1f;

            lookX = 0.0f;
            lookY = 0.0f;
            lookZ = 0.0f;

            break;


        // ====================================================
        //                  CAMERA VIEW 3
        //                   SIDE VIEW
        // ====================================================

        case '3':

            cameraX = 15.0f;
            cameraY = 5.0f;
            cameraZ = 5.0f;

            lookX = 0.0f;
            lookY = 0.0f;
            lookZ = 0.0f;

            break;


        // ====================================================
        //                       RESET
        // ====================================================

        case 'r':
        case 'R':

            cameraX = 0.0f;
            cameraY = 5.0f;
            cameraZ = 16.0f;

            lookX = 0.0f;
            lookY = 0.0f;
            lookZ = 0.0f;

            break;


        // ====================================================
        //                   PAUSE / RESUME
        // ====================================================

        case 32:

            animationRunning =
                !animationRunning;

            break;


        // ====================================================
        //                         EXIT
        // ====================================================

        case 27:

            exit(0);

            break;
    }


    glutPostRedisplay();
}


// ============================================================
//                       SPECIAL KEYS
// ============================================================

void specialKeys(
    int key,
    int x,
    int y
)
{
    switch (key)
    {
        case GLUT_KEY_UP:

            cameraY += 0.5f;

            break;


        case GLUT_KEY_DOWN:

            cameraY -= 0.5f;

            break;


        case GLUT_KEY_LEFT:

            cameraX -= 0.5f;

            break;


        case GLUT_KEY_RIGHT:

            cameraX += 0.5f;

            break;
    }


    glutPostRedisplay();
}


// ============================================================
//                         RESHAPE
// ============================================================

void reshape(
    int width,
    int height
)
{
    if (height == 0)
    {
        height = 1;
    }


    glViewport(
        0,
        0,
        width,
        height
    );


    glMatrixMode(
        GL_PROJECTION
    );

    glLoadIdentity();


    gluPerspective(
        60.0,
        (float)width / (float)height,
        0.1,
        100.0
    );


    glMatrixMode(
        GL_MODELVIEW
    );
}


// ============================================================
//                      INITIALIZATION
// ============================================================

void init()
{
    // ========================================================
    //                        DEPTH
    // ========================================================

    glEnable(
        GL_DEPTH_TEST
    );


    // ========================================================
    //                       LIGHTING
    // ========================================================

    glEnable(
        GL_LIGHTING
    );

    glEnable(
        GL_LIGHT0
    );


    // ========================================================
    //                    SMOOTH SHADING
    // ========================================================

    glShadeModel(
        GL_SMOOTH
    );


    // ========================================================
    //                    NORMALIZATION
    // ========================================================

    glEnable(
        GL_NORMALIZE
    );


    // ========================================================
    //                    AMBIENT LIGHT
    // ========================================================

    GLfloat ambientLight[] =
    {
        0.18f,
        0.18f,
        0.20f,
        1.0f
    };

    glLightModelfv(
        GL_LIGHT_MODEL_AMBIENT,
        ambientLight
    );


    // ========================================================
    //                    SPECULAR EFFECT
    // ========================================================

    GLfloat specular[] =
    {
        0.6f,
        0.6f,
        0.6f,
        1.0f
    };

    glMaterialfv(
        GL_FRONT,
        GL_SPECULAR,
        specular
    );

    glMaterialf(
        GL_FRONT,
        GL_SHININESS,
        40.0f
    );
}


// ============================================================
//                           MAIN
// ============================================================

int main(
    int argc,
    char** argv
)
{
    glutInit(
        &argc,
        argv
    );


    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );


    glutInitWindowSize(
        1200,
        700
    );


    glutInitWindowPosition(
        50,
        50
    );


    glutCreateWindow(
        "3D Space Station & Solar System Simulation"
    );


    // OpenGL initialization
    init();


    // Display function
    glutDisplayFunc(
        display
    );


    // Reshape
    glutReshapeFunc(
        reshape
    );


    // Normal keyboard
    glutKeyboardFunc(
        keyboard
    );


    // Arrow keyboard
    glutSpecialFunc(
        specialKeys
    );


    // Animation timer
    glutTimerFunc(
        20,
        update,
        0
    );


    // Full screen
    glutFullScreen();


    // Start GLUT
    glutMainLoop();


    return 0;
}
