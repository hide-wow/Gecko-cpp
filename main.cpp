// Made with 💙 by hide-wow on github

#include <Gecko.cpp>

int main()
{
    Gecko Gecko; //Initialize Gecko class

    try
    {
        Gecko.Connect("192.168.0.114"); //Connect to the WiiU
    }
    catch(const std::exception& exc)
    {
        std::cerr << exc.what() << '\n'; //Print the error if there is one
    }
}