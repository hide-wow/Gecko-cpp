// Made with 💙 by hide-wow on github

#include <Gecko.h>

class Gecko
{
    
    public: SOCKET sock;
            std::string ip;

    void Gecko::Connect(std::string ip, int port=7331)
    {
        // Da winsock ma boi
        WSAData data;
        WORD ver = MAKEWORD(2, 2);
        int wsResult = WSAStartup(ver, &data);
        if (wsResult != 0) {
            std::cerr << "Failed to init winsock\n(ask to the dev if skid)" << wsResult << std::endl;
            return;
        }
        
        // Da socket ma boiii
        SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == INVALID_SOCKET) {
            std::cerr << "Can't connect to the wiiu\n(ask to the dev if skid)\n" << WSAGetLastError() << std::endl;
            WSACleanup();
            return;
        }

        // Structure
        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &hint.sin_addr);

        this->sock = sock;
        this->ip = ip;
    }

    void Gecko::Disconnect(std::string ip, int port)
    {
        try
        {
            closesocket(this->sock);
            WSACleanup();
        }
        catch(const std::exception& exc)
        {
            std::cerr << 
            "Maybe not connected, Error while trying to disconnect\n(ask to the dev if skid)\n" 
            << WSAGetLastError() 
            << std::endl;
        }
    }

    void Gecko::ReadMem(int Address, int Length)
    {

    }

    bool Gecko::validRange(int Address, int Length)
    {
        if      (0x01000000 <= Address && Address + Length <= 0x01800000)  {return  true;}
        else if (0x02000000 <= Address && Address + Length <= 0x10000000)  {return  true;}
        else if (0x10000000 <= Address && Address + Length <= 0x50000000)  {return  true;}
        else if (0xE0000000 <= Address && Address + Length <= 0xE4000000)  {return  true;}
        else if (0xE8000000 <= Address && Address + Length <= 0xEA000000)  {return  true;}
        else if (0xF4000000 <= Address && Address + Length <= 0xF6000000)  {return  true;}
        else if (0xF6000000 <= Address && Address + Length <= 0xF6800000)  {return  true;}
        else if (0xF8000000 <= Address && Address + Length <= 0xFB000000)  {return  true;}
        else if (0xFB000000 <= Address && Address + Length <= 0xFB800000)  {return  true;}
        else if (0xFFFE0000 <= Address && Address + Length <= 0xFFFFFFFF)  {return  true;}
        else                                                               {return  true;}
    }

    bool Gecko::validAccess(int Address, int Length, std::string Access)
    {
        if (0x01000000 <= Address && Address + Length <= 0x01800000)
        {
            if (Access == "read")  {return true;}
            if (Access == "write") {return true;}
        }
        else if (0x02000000 <= Address && Address + Length <= 0x10000000) // Depends on game, may be EG 0x0E3
        {
            if (Access == "read")  {return true;}
            if (Access == "write") {return true;}
        }
        else if (0x10000000 <= Address && Address + Length <= 0x50000000)
        {    
            if (Access == "read")  {return true;}
            if (Access == "write") {return true;}
        }
        else if (0xE0000000 <= Address && Address + Length <= 0xE4000000)
        {
            if (Access == "read")  {return true;}
            if (Access == "write") {return true;}
        }
        else if (0xE8000000 <= Address && Address + Length <= 0xEA000000)
        {
            if (Access == "read")  {return true;}
            if (Access == "write") {return true;}
        }
        else if (0xF4000000 <= Address && Address + Length <= 0xF6000000)
        {
            if (Access == "read")  {return true;}
            if (Access == "write") {return true;}
        }
        else if (0xF6000000 <= Address && Address + Length <= 0xF6800000)
        {
            if (Access == "read")  {return true;}
            if (Access == "write") {return true;}
        }
        else if (0xF8000000 <= Address && Address + Length <= 0xFB000000)
        {
            if (Access == "read")  {return true;}
            if (Access == "write") {return true;}
        }
        else if (0xFB000000 <= Address && Address + Length <= 0xFB800000)
        {
            if (Access == "read") {return true;}
            if (Access == "write") {return true;}
        }
        else if (0xFFFE0000 <= Address && Address + Length <= 0xFFFFFFFF)
        {
            if (Access == "read")  {return true;}
            if (Access == "write") {return true;}
        }
        else{return false;}
    }

};