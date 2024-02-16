#include <iostream>
#include <unordered_map>
#include <random>
#include <string>

class URLShortener
{
private:
    std::unordered_map<std::string, std::string> urlMap;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int shortUrlLength = 6; // Tamanho da URL encurtada

public:
    std::string generateShortURL()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, alphabet.size() - 1);

        std::string shortURL;
        for (int i = 0; i < shortUrlLength; ++i)
        {
            shortURL += alphabet[dis(gen)];
        }

        return shortURL;
    }

    std::string shortenURL(const std::string &longURL)
    {
        std::string shortURL = generateShortURL();
        urlMap[shortURL] = longURL;
        return shortURL;
    }

    std::string redirect(const std::string &shortURL)
    {
        auto it = urlMap.find(shortURL);
        if (it != urlMap.end())
        {
            return it->second;
        }
        else
        {
            return "URL not found";
        }
    }
};

int main()
{
    URLShortener shortener;
    std::string longURL = "https://www.example.com/long-url";
    std::string shortURL = shortener.shortenURL(longURL);
    std::cout << "Shortened URL: " << shortURL << std::endl;

    std::string redirectURL = shortener.redirect(shortURL);
    std::cout << "Redirecting to: " << redirectURL << std::endl;

    return 0;
}
