#pragma once
class String {
private:
    int length;
    char* buffer;
    size_t maxSize;

public:
    String(const size_t maxsize);
    String(const char* defaultText, const size_t maxsize);
    ~String();
    String(const String& original);
    void Copy(const String& a) const;
    String& operator=(const String& other);
    String(String&& other) noexcept;
    String& operator=(String&& other) noexcept;
    //Working on:
    String operator+(const String& s) const;

    void Append(const char* text);
    void AppendLine(const char* text);
    void Print() const;
    char* GetString() const;
};

