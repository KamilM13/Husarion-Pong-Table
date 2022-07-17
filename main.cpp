#include <hFramework.h>
#include <Lego_Touch.h>
#include <Lego_Ultrasonic.h>
#include <DistanceSensor.h>
#include <stdio.h>
#include <stdlib.h>
#include <Mindsensors_NumericPad.h>
using namespace hModules;
using namespace hSensors;
using namespace hFramework;
/////////////////////////////////////////////////////////////  TILTING TABLE  /////////////////////////////////////////////////////
void tilt()
{
    while (true)
    {
        hMot3.setPower(500);
        sys.delay(2000);
        hMot3.setPower(-500);
        sys.delay(2000);
    }
}
///////////////////////////////////////////////////////////////  CONTROLS  ///////////////////////////////////////////////////////////////////
void controls()
{
    int mode = 0;
    while (true)
    {
        bool autonomous = hBtn1.isPressed();
        bool manual = hBtn2.isPressed();
        if (autonomous)
            mode = 1;
        if (manual)
            mode = 0;
    }
/////////////////////////////////////////////////////////   MANUAL CONTROL MODE   ////////////////////////////////////////////////////////////
    while (mode == 0)
    {
        hLegoSensor_i2c ns(hSens1);
        Mindsensors_NumericPad sensor1(ns);
        Pressed p;
        while (true)
        {
            sys.delay(100);
            sensor1.scanKeys(p);
            p.whichOne();
            if(p.one())
                hMot1.setPower(-700);
            if(p.three())
                hMot2.setPower(-700);
            if(p.four())
                hMot1.setPower(0);
            if(p.six())
                hMot2.setPower(0);
            if(p.seven())
                hMot1.setPower(0);
            if(p.nine())
                hMot2.setPower(0);
            if(p.hash())
                hMot2.setPower(700);
            if(p.star())
               hMot1.setPower(700);
        }
    }
/////////////////////////////////////////////////////////   AUTONOMOUS CONTROL MODE   ////////////////////////////////////////////////////////////
    while (mode == 1)
    {
        while (true)
        {
            int oleft;
            int ileft;
            int middle;
            int iright;
            int oright;
            DistanceSensor sens2(hSens2);
            oleft = sens2.getDistance();
            DistanceSensor sens3(hSens3);
            ileft = sens3.getDistance();
            DistanceSensor sens4(hSens4);
            middle = sens4.getDistance();
            DistanceSensor sens5(hSens5);
            iright = sens5.getDistance();
            DistanceSensor sens6(hSens6);
            oright = sens6.getDistance();
            printf(" %d || %d || %d || %d || %d \n", oleft, ileft, middle, iright, oright);
            sys.delay(100);
            if ((oleft<9)&&(oleft>5))
            {
                hMot1.rotAbs(-280, 1000, false, INFINITE);
                hMot2.rotAbs(-280, 1000, false, INFINITE);
            }
            if ((oleft<9)&&(oleft>5)&&(ileft<9)&&(ileft>5))
            {
                hMot1.rotAbs(-210, 1000, false, INFINITE);
                hMot2.rotAbs(-210, 1000, false, INFINITE);
            }
            if ((ileft<9)&&(ileft>5))
            {
                hMot1.rotAbs(-140, 1000, false, INFINITE);
                hMot2.rotAbs(-140, 1000, false, INFINITE);
            }
            if ((ileft<9)&&(ileft>5)&&(middle<9)&&(middle>5))
            {
                hMot1.rotAbs(-70, 1000, false, INFINITE);
                hMot2.rotAbs(-70, 1000, false, INFINITE);
            }
            if ((middle<9)&&(middle>5))
            {
                hMot1.rotAbs(0, 1000, false, INFINITE);
                hMot2.rotAbs(0, 1000, false, INFINITE);
            }
            if ((middle<9)&&(middle>5)&&(iright<9)&&(iright>5))
            {
                hMot1.rotAbs(70, 1000, false, INFINITE);
                hMot2.rotAbs(70, 1000, false, INFINITE);
            }
            if ((iright<9)&&(iright>5))
            {
                hMot1.rotAbs(140, 1000, false, INFINITE);
                hMot2.rotAbs(140, 1000, false, INFINITE);
            }
            if ((iright<9)&&(iright>5)&&(oright<9)&&(oright>5))
            {
                hMot1.rotAbs(210, 1000, false, INFINITE);
                hMot2.rotAbs(210, 1000, false, INFINITE);
            }
            if ((oright<9)&&(oright>5))
            {
                hMot1.rotAbs(280, 1000, false, INFINITE);
                hMot2.rotAbs(280, 1000, false, INFINITE);
            }
        }
    }
}
/////////////////////////////////////////////////////////////  MAIN FUNCTION  ///////////////////////////////////////////////////////////////
void hMain()
{
    hMot1.setEncoderPolarity(Polarity::Reversed);  // necessary, husarion cant figure out where minus and plus actually are
    hMot2.setEncoderPolarity(Polarity::Reversed);
    hMot3.setEncoderPolarity(Polarity::Reversed);
    sys.taskCreate(tilt);
    sys.taskCreate(controls);
}