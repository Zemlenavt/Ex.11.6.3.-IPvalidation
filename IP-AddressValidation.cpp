#include <iostream>
//#include <string>

bool validAddrPart (std::string ipAddrPart)
{
    if (ipAddrPart.size()>3 || ipAddrPart.empty())  //если строка пустая или если количество символов в строке больше 3, то false
    {
        return false;
    }
    if (ipAddrPart.size()<=3 && ipAddrPart.size() >1)
    {
        if (ipAddrPart[0] == '0')
        {
            return false;
        }
    }
    for (char c: ipAddrPart)                        //посимвольно проверяем всю строку на наличие/отсутствие цифр
    {
        if (c < '0' || c > '9')
        {
            return false;
        }
    }
    int num = stoi(ipAddrPart);                     //приводим последовательность символов в int
    
    if (num >= 0 && num <= 255)                     //проверяем пределы, в которых лежит значение num
    {
        return true;
    }
    return false;
}

bool validIPv4 (std::string IP)
{
    int num_parts = 0;
    std::string part = "";
    for (char c: IP)
    {
        if (c == '.')
        {
            if (!validAddrPart(part))
            {
                return false;
            }
            num_parts++;
            part = "";
        }
        else if (c >= '0'  && c <= '9')
        {
            part += c;
        }
        else
        {
            return false;
        }
    }
    if (!validAddrPart(part))
    {
        return false;
    }
    num_parts++;
    return num_parts = 4;                           //если частей адреса 4, то вренётся true. Иначе false

}

int main()
{
    std::string address;
    std::cout << "Input IP-address (format xxx.xxx.xxx.xxx, where is every 'xxx' part from 0 to 255):";
    std::cin >> address;

    if(validIPv4 (address))
    {
        std::cout << "Valid" << std::endl;
    }
    else
    {
        std::cout << "Invalid" << std::endl;
    }
}

