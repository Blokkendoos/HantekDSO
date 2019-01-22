#ifndef _GLBOX_H_
#define _GLBOX_H_
#include <qgl.h>
#include "hantekdsoathread.h"
#include "fht.h"
#include "sansfont.h"

#define DIVS_TIME 10.0
#define DIVS_VOLTAGE 8.0

#define DP_DEPTH 5

enum gl_object_types
{
    GLOBJ_GRID,
    GLOBJ_LAST
};

enum channels
{
    CHANNEL_CH2 = 0,
    CHANNEL_CH1
};

enum interpolation_modes
{
    INTERPOLATION_OFF = 0,
    INTERPOLATION_LINEAR,
    INTERPOLATION_SINC
};

enum view_modes
{
    VIEWMODE_XT = 0,
    VIEWMODE_XY,
    VIEWMODE_SPECTRUM
};

enum math_types
{
    MATHTYPE_OFF = 0,
    MATHTYPE_1ADD2,
    MATHTYPE_1SUB2,
    MATHTYPE_2SUB1
};

class GLBox : public QGLWidget
{
    Q_OBJECT
public:
    GLBox(QWidget* parent, const char* name);
    ~GLBox();

public:
    void setAThread(HantekDSOAThread* pAThread);
    void setViewMode(int mode);
    void setMathType(int type);
    void setInterpolation(int state);
    void setCalData(double data);
    void setDigitalPhosphor(int state);
    void setTimeDiv(double div);
    void setTimeShift(double shift);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    GLuint makeObject(int object);

private:
    HantekDSOAThread* aThread;
    GLuint gl_grid, gl_channels;
    SansFont font;
    static const GLfloat chColor[MAX_CHANNELS+1][4];
    double calData;
    int digitalPhosphor;
    int dpIndex;
    int viewMode;
    int mathType;
    int interpolationMode;
    double timeDiv;
    double timeShift;
};


#endif // GLBOX_H
