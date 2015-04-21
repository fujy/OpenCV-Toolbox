#include "properties.h"

static Properties *singleton = 0;

Properties::Properties()
{
    saltAndPepperNoise = 1000;
}

Properties::~Properties()
{

}

Properties* Properties::getInstance()
{
    if (singleton == 0)
        singleton = new Properties();
    return singleton;
}

int Properties::SaltAndPepperNoise()
{
    return Properties::getInstance()->saltAndPepperNoise;
}

void Properties::setSaltAndPepperNoise(int saltAndPepperNoise)
{
    Properties::getInstance()->saltAndPepperNoise = saltAndPepperNoise;
}

