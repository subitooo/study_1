#include "func.hpp"

namespace sd
    // ‘орматирование времени
{
    void FormatedTime(char string[], char newform[], size_t lenght)
    {
        time_t t = std::time(nullptr);
        std::strftime(string, lenght, newform, std::localtime(&t));

        string[4] = '.'; // годы
        string[7] = '.'; // мес€цы
        string[13] = ':'; // секунды
        string[16] = ':'; // миллисекунды
        string[19] = '\n'; // нова€ строка
        string[20] = '\0'; // конец строки в текстовом файле
    }

    // —чЄтчик строк
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