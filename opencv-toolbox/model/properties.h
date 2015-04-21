#ifndef PROPERTIES_H
#define PROPERTIES_H

class Properties
{

private:
    Properties();
    ~Properties();
    static Properties *getInstance();
    int saltAndPepperNoise;

public:
    static int SaltAndPepperNoise();
    static void setSaltAndPepperNoise(int saltAndPepperNoise);

};

#endif // PROPERTIES_H
