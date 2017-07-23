/*!
    \file itch_handler.cpp
    \brief NASDAQ ITCH handler example
    \author Ivan Shynkarenka
    \date 23.07.2017
    \copyright MIT License
*/

#include "trader/providers/nasdaq/itch_handler.h"

#include "system/stream.h"

#include <iostream>

class MyHandler : public CppTrader::ITCH::ITCHHandler
{
protected:
    bool HandleMessage(const CppTrader::ITCH::SystemEventMessage& message) override
    {
        //std::cout << message << std::endl;
        return true;
    }

    bool HandleMessage(const CppTrader::ITCH::StockDirectoryMessage& message) override
    {
        //std::cout << message << std::endl;
        return true;
    }

    bool HandleMessage(const CppTrader::ITCH::StockTradingActionMessage& message) override
    {
        //std::cout << message << std::endl;
        return true;
    }

    bool HandleMessage(const CppTrader::ITCH::UnknownMessage& message) override
    {
        //std::cout << message << std::endl;
        return true;
    }
};

int main(int argc, char** argv)
{
    MyHandler handler;

    // Perform input
    size_t size;
    uint8_t buffer[1];
    CppCommon::StdInput input;
    while ((size = input.Read(buffer, sizeof(buffer))) > 0)
    {
        // Process the buffer
        handler.Process(buffer, size);
    }

    return 0;
}
