#include <iostream>
#include <chrono>
#include <thread>
#include <sqlite3.h>
#include "Utils\Logger.hpp"

// #define ASIO_STANDALONE
// #include <asio.hpp>



int main(int, char **)
{
    // Obtain the singleton instance of the logger
    Utils::Logger& logger = Utils::Logger::getInstance();

    // Add output destinations (e.g., console and file)
    logger.addOutputDestination(std::cout);

    std::ofstream fileOutput("..\\logfile.log");
    if (fileOutput.is_open()) {
        logger.addOutputDestination(fileOutput);
    }
    else {
        std::cerr << "Error opening file for logging." << std::endl;
    }

    // Log messages
    logger.log("This is an informational message.", Utils::LogLevel::INFO);
    logger.log("This is a warning message.", Utils::LogLevel::WARNING);
    logger.log("This is an error message.", Utils::LogLevel::ERROR);

    // // Remove an output destination
    // logger.removeOutputDestination(fileOutput);

    // // Log messages again (file output destination removed)
    // logger.log("This message won't be written to the file.");

    return 0;

    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------

    // asio::error_code ec;

    // asio::io_context context;

    // asio::ip::tcp::endpoint endpoint(asio::ip::make_address("93.184.216.34", ec), 80);
    // // asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec), 80);

    // asio::ip::tcp::socket socket(context);

    // socket.connect(endpoint,ec);

    // if (!ec)
    // {
    //     std::cout << "Connected" << std::endl;
    // }
    // else
    // {
    //     std::cout << "not connected" << std::endl;
    // }

    // if (socket.is_open())
    // {
    //     std::string sRequest =
    //     "GET /index.html HTTP/1.1\r\n"
    //     "Host: localhost\r\n"
    //     "Connection: close\r\n\r\n";

    //     // // Specify the POST data
    //     // std::string postData = "message=Hello%20World";

    //     // // Construct the POST request
    //     // std::ostringstream sRequest;
    //     // sRequest << "POST " << "/test.php" << " HTTP/1.1\r\n";
    //     // sRequest << "Host: " << "localhost" << "\r\n";
    //     // sRequest << "Content-Type: application/x-www-form-urlencoded\r\n";
    //     // sRequest << "Content-Length: " << postData.length() << "\r\n";
    //     // sRequest << "Connection: close\r\n\r\n";
    //     // sRequest << postData;
    //     // std::cout << "post msg length: " << postData.length();

    //     socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

    //     using namespace std::chrono_literals;
    //     std::this_thread::sleep_for(200ms);

    //     size_t bytes = socket.available();
    //     std::cout << "Bytes available: " << bytes << std::endl;

    //     if (bytes > 0)
    //     {
    //         std::vector<char> vBuffer(bytes);
    //         socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);

    //         for (auto c : vBuffer)
    //         {
    //             std::cout << c;
    //         }
    //     }

    //     std::cout << "-----------------------------" << std::endl;

    //     std::this_thread::sleep_for(200ms);

    //     size_t bytes2 = socket.available();
    //     std::cout << std::endl << "Bytes available: " << bytes << std::endl;

    //     if (bytes2 > 0)
    //     {
    //         std::vector<char> vBuffer(bytes);
    //         socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);

    //         for (auto c : vBuffer)
    //         {
    //             std::cout << c;
    //         }
    //     }
    // }
}

// #include <iostream>
// #include <asio.hpp>

// void perform_post_request(const std::string& host, const std::string& path, const std::string& postData) {
//     try {
//         asio::io_context io_context;

//         // Create a TCP resolver and query
//         asio::ip::tcp::resolver resolver(io_context);
//         asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host, "http");

//         // Create and connect the socket
//         asio::ip::tcp::socket socket(io_context);
//         asio::connect(socket, endpoints);

//         // Construct the POST request
//         std::ostringstream request;
//         request << "POST " << path << " HTTP/1.1\r\n";
//         request << "Host: " << host << "\r\n";
//         request << "Content-Type: application/x-www-form-urlencoded\r\n";
//         request << "Content-Length: " << postData.length() << "\r\n";
//         request << "Connection: close\r\n\r\n";
//         request << postData;

//         // Send the request
//         asio::write(socket, asio::buffer(request.str()));

//         // Read the response
//         asio::streambuf response;
//         asio::read_until(socket, response, "\r\n");

//         // Print the response
//         std::istream response_stream(&response);
//         std::string http_version;
//         response_stream >> http_version;
//         unsigned int status_code;
//         response_stream >> status_code;

//         std::string status_message;
//         std::getline(response_stream, status_message);

//         std::cout << "Response: " << http_version << " " << status_code << " " << status_message << std::endl;

//         // Read and print the rest of the response
//         asio::read(socket, response, asio::transfer_all());
//         std::cout << asio::buffer_cast<const char*>(response.data()) << std::endl;
//     } catch (std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
// }

// int main() {
//     // Specify the server and path
//     std::string host = "localhost";
//     std::string path = "/test.php";
//     // std::string path = "/test.php?timestamp=" + std::to_string(std::time(nullptr));
//     // std::cout << path << std::endl;

//     // Specify the POST data
//     std::string postData = "message=Hello%20World";

//     // Perform the POST request
//     perform_post_request(host, path, postData);

//     return 0;
// }
