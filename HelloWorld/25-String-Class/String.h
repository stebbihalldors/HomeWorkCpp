#pragma once
class String {
private:
    int length;
    char* buffer;
    std::size_t maxSize;

public:
    String(std::size_t maxsize);
    String(const char* defaultText, std::size_t maxsize);
    ~String();
    String(const String& original);
    void Copy(const String& a);
    String& operator=(const String& other);
    String(String&& other) noexcept;
    String& operator=(String&& other) noexcept;

    void Append(const char* text);
    void AppendLine(char* text);
    void Print();
    char* GetString();
};

