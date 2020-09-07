#include <ch554.h>
#include <debug.h>
#include <pwm.h>

//-------------------------------------------------------

#define VPP_EN P33
#define VPP_SEL P14

#define VPP_DISABLE 0
#define VPP_7V5     1
#define VPP_10V8    2

void vpp_set(uint8_t val)
{
    VPP_SEL = (val==VPP_7V5)1:0;
    VPP_EN = (val!=VPP_DISABLE)1:0;
}

#define VDD_EN P32

//VDD = val / 65535 * 10V

void vdd_set(uint16_t val)
{
    if(val)
    {
        
        VDD_EN = 1;
    }
    else
    {
        VDD_EN = 0;
    }
    
}

//-------------------------------------------------------

void main(void)
{
    //IO init

    //PWM init
    SetPWMClk(4);
    ForceClearPWMFIFO();
    CancelClearPWMFIFO();
    PWM2OutEnable();
    PWM2OutPolarHighAct();
    SetPWM2Dat(0xFF);

    //USB

    while(1)
    {

    }
}