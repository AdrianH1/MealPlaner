#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>


int main(int argc, char const *argv[])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> dis(0, 65535);

    std::string id{};

    // Format UUID string
    std::stringstream ss;
    ss << std::setw(5) << std::setfill('0') << static_cast<uint16_t>(dis(gen));
    // << std::setw(4) << static_cast<uint16_t>(dis(gen)) << "-"
    // << std::setw(4) << static_cast<uint16_t>(dis(gen)) << "-"
    // << std::setw(4) << static_cast<uint16_t>(dis(gen)) << "-"
    // << std::setw(12) << static_cast<uint64_t>(dis(gen));
    id = ss.str();

    std::cout << id;

    return 0;
}
