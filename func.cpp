#include "func.hpp"

namespace sd
    // �������������� �������
{
    void FormatedTime(char string[], char newform[], size_t lenght)
    {
        time_t t = std::time(nullptr);
        std::strftime(string, lenght, newform, std::localtime(&t));

        string[4] = '.'; // ����
        string[7] = '.'; // ������
        string[13] = ':'; // �������
        string[16] = ':'; // ������������
        string[19] = '\n'; // ����� ������
        string[20] = '\0'; // ����� ������ � ��������� �����
    }

    // ������� �����
    int Lines(const char& file_name)
    {
        std::ifstream in(&file_name);
        int count = 0;
        std::string tmp;

        while (!in.eof())
        {
            std::getline(in, tmp);
            count++;
        }
        return count;
    }
}