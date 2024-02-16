#include <iostream>
#include <unordered_map>
#include <random>
#include <string>

class URLShortener
{
private:
    std::unordered_map<std::string, std::string> urlMap;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int shortUrlLength = 6;

public:
    std::string generateShortURL()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
    }
};