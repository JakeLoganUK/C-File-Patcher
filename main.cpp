    #include <windows.h>
    #include <iostream>
    #include <fstream>

// https://github.com/JakeLoganUK
    int main()
    {
        HANDLE hFile = CreateFile("jake.txt", FILE_ALL_ACCESS, FILE_SHARE_READ | FILE_SHARE_DELETE, 0, CREATE_ALWAYS, 0, 0);
        CloseHandle(hFile);

        std::fstream fs("jake.txt", std::ios::in | std::ios::out | std::ios::binary);

        fs.write("\x4A\x61\x6B\x65\x4C\x6F\x67\x61\x6E\x55\x4B", 12); //Hexadecimal Byte -> ASCII
        std::streampos size = fs.tellg();

        char* buffer = new char[size];

        fs.seekg(0, std::ios::beg); //CHANGE OFFSETS <----
        fs.read(buffer, size);

        std::cout << "File Says: " << buffer << std::endl;

        fs.seekg(0, std::ios::beg);
        fs.write("\x4A\x61\x6B\x65\x4C\x6F\x67\x61\x6E\x55\x4B", 12); //Hexadecimal Byte -> ASCII

        std::cout << "File Patched!\n";

        fs.seekg(0, std::ios::beg);
        fs.read(buffer, size);

        std::cout << "file says: " << buffer << std::endl;

        fs.close();
        delete[] buffer;

        return 0;
    }