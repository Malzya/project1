#include <iostream>    
#include <cstdlib>    
#include <ctime>    
#include <Windows.h>    

using namespace std;


bool isGameOver1(bool opened[3][2])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (!opened[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool isGameOver2(bool opened[2][4])
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (!opened[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool isGameOver3(bool opened[2][3])
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (!opened[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool isGameOver4(bool opened[4][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (!opened[i][j])
            {
                return false;
            }
        }
    }
    return true;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    int choicesize;
    cout << "Перед вами игра 'Память', ваша задача запомнить, где находятся две одинаковые карточки. Все что вам нужно - это выбрать размер поля" << endl;
    cout << "Выберите размер поля:\n1 - 2x3\n2 - 4x2\n3 - 3x2\n4 - 4x4" << endl << "" << endl;
    cin >> choicesize;
    cout << endl;
    cout << "Вводите сначала столбик, а потом строчку" << endl;
    const int pole_1_size_1 = 3;
    const int pole_1_size_2 = 2;
    const int pole_2_size_1 = 2;
    const int pole_2_size_2 = 4;
    const int pole_3_size_1 = 2;
    const int pole_3_size_2 = 3;
    const int pole_4_size_1 = 4;
    const int pole_4_size_2 = 4;
    bool opened1[pole_1_size_1][pole_1_size_2]{};
    bool opened2[pole_2_size_1][pole_2_size_2]{};
    bool opened3[pole_3_size_1][pole_3_size_2]{};
    bool opened4[pole_4_size_1][pole_4_size_2]{};
    int polesecret1[3][2] = {};
    int polesecret2[2][4] = {};
    int polesecret3[2][3] = {};
    int polesecret4[4][4] = {};

    if (choicesize == 1)
    {



        int arr[pole_1_size_1][pole_1_size_2]
        {
            {1, 1},     // первая строка    
            {2, 2},     // вторая строка    
            {3, 3}      // третья строка    
        };
        srand(time(0));
        for (unsigned i = 0; i < 3; ++i)
        {
            for (unsigned u = 0; u < 2; ++u)
            {
                swap(arr[i][u], arr[rand() % 3][rand() % 2]);
            }
        }

        int stolbs[2] = { 0, 1 };
        for (int i = 0; i < 2; i++)
        {
            cout << "     " << stolbs[i] << "";

        }
        cout << endl;
        int str[3] = { 0,1,2 };
        //Вывод двумерного массива на экран    
        for (int i = 0; i < 3; ++i)
        {
            cout << " " << str[i];
            for (int j = 0; j < 2; ++j)
            {
                cout << "   " << polesecret1[i][j] << "  ";
            }
            cout << endl;

        }
        while (!isGameOver1(opened1))
        {
            int x1, y1, x2, y2;
            cout << "Введите координаты первой карточки: ";
            cin >> y1 >> x1;
            if (x1 < 0 && x1 >= 2 && y1 < 0 && y1 >= 3 && opened1[x1][y1])
            {
                cout << "Неверные координаты или карточка уже открыта. Попробуйте снова." << std::endl;
                continue;
            }

            opened1[x1][y1] = true;
            int stolbs[2] = { 0, 1 };
            for (int i = 0; i < 2; i++)
            {
                cout << "      " << stolbs[i] << "";

            }
            int str[3] = { 0,1,2 };
            cout << endl;
            for (int i = 0; i < 3; ++i)
            {
                cout << " " << str[i];

                for (int j = 0; j < 2; ++j)
                {
                    if (opened1[i][j])
                    {
                        cout << "    " << arr[i][j] << "  ";
                    }
                    else {

                        std::cout << "    " << "*  ";
                    }

                }
                cout << endl;
            }


            cout << "Введите координаты второй карточки: ";
            cin >> y2 >> x2;

            if (x2 < 0 && x2 >= 2 && y2 < 0 && y2 >= 3 && opened1[x2][y2])
            {
                cout << "Неверные координаты или карточка уже открыта. Попробуйте снова." << endl;
                opened1[x1][y1] = false;
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 2; ++j)
                    {
                        if (opened1[i][j])
                        {
                            cout << arr[i][j] << " ";
                        }
                        else
                        {

                            cout << "* ";
                        }

                    }
                    cout << endl;
                }
            }

            opened1[x2][y2] = true;
            int stolbs_2[2] = { 0, 1 };
            for (int i = 0; i < 2; i++)
            {
                cout << "      " << stolbs_2[i] << "";

            }
            int str_2[3] = { 0,1,2 };
            cout << endl;
            for (int i = 0; i < 3; ++i)
            {
                cout << " " << str_2[i];
                for (int j = 0; j < 2; ++j)
                {
                    if (opened1[i][j])
                    {
                        cout << "    " << arr[i][j] << "  ";
                    }
                    else
                    {

                        cout << "    " << "*  ";
                    }
                }
                cout << endl;
            }


            if (arr[x1][y1] != arr[x2][y2])
            {
                opened1[x1][y1] = false;
                opened1[x2][y2] = false;

                cout << "Карточки не совпали. Попробуйте снова." << endl;
                int stolbs_3[2] = { 0, 1 };
                for (int i = 0; i < 2; i++)
                {
                    cout << "     " << stolbs_3[i] << "";

                }
                int str_3[3] = { 0,1,2 };
                cout << endl;
                for (int i = 0; i < 3; ++i)
                {
                    cout << " " << str_3[i];
                    for (int j = 0; j < 2; ++j)
                    {
                        if (opened1[i][j])
                        {
                            cout << "   " << arr[i][j] << "  ";
                        }
                        else
                        {

                            cout << "   " << "*  ";
                        }

                    }
                    cout << endl;
                }

            }
        }
        cout << "Поздравляем, вы нашли все пары!" << endl;

    }

    if (choicesize == 2)
    {
        int arr[pole_2_size_1][pole_2_size_2]
        {

            {1, 1, 2, 2},     // первая строка    
            {3, 3, 4, 4},     // третья строка    
        };
        srand(time(0));
        for (unsigned i = 0; i < 2; ++i)
        {
            for (unsigned u = 0; u < 4; ++u)
            {
                swap(arr[i][u], arr[rand() % 2][rand() % 4]);
            }
        }

        int stolbs[4] = { 0, 1,2, 3 };
        for (int i = 0; i < 4; i++)
        {
            cout << "     " << stolbs[i] << "";

        }
        cout << endl;
        int str[2] = { 0,1 };
        //Вывод двумерного массива на экран    
        for (int i = 0; i < 2; ++i)
        {
            cout << " " << str[i];
            for (int j = 0; j < 4; ++j)
            {
                cout << "   " << polesecret2[i][j] << "  ";
            }
            cout << endl;

        }
        while (!isGameOver2(opened2))
        {
            int x1, y1, x2, y2;
            cout << "Введите координаты первой карточки: ";
            cin >> y1 >> x1;
            if (x1 < 0 && x1 >= 4 && y1 < 0 && y1 >= 2 && opened2[x1][y1])
            {
                cout << "Неверные координаты или карточка уже открыта. Попробуйте снова." << endl;
                continue;
            }

            opened2[x1][y1] = true;
            int stolbs[4] = { 0, 1, 2, 3 };
            for (int i = 0; i < 4; i++)
            {
                cout << "       " << stolbs[i] << "";

            }
            int str[2] = { 0,1 };
            cout << endl;
            for (int i = 0; i < 2; ++i)
            {
                cout << " " << str[i];

                for (int j = 0; j < 4; ++j)
                {
                    if (opened2[i][j])
                    {
                        cout << "     " << arr[i][j] << "  ";
                    }
                    else {

                        cout << "     " << "*  ";
                    }

                }
                cout << endl;
            }


            cout << "Введите координаты второй карточки: ";
            cin >> y2 >> x2;

            if (x2 < 0 && x2 >= 4 && y2 < 0 && y2 >= 2 && opened2[x2][y2])
            {
                cout << "Неверные координаты или карточка уже открыта. Попробуйте снова." << endl;
                opened2[x1][y1] = false;
                for (int i = 0; i < 2; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (opened2[i][j])
                        {
                            cout << arr[i][j] << " ";
                        }
                        else
                        {

                            cout << "* ";
                        }

                    }
                    cout << endl;
                }
            }

            opened2[x2][y2] = true;
            int stolbs_2[4] = { 0, 1, 2, 3 };
            for (int i = 0; i < 4; i++)
            {
                cout << "      " << stolbs_2[i] << "";

            }
            int str_2[2] = { 0,1 };
            cout << endl;
            for (int i = 0; i < 2; ++i) {
                cout << " " << str_2[i];
                for (int j = 0; j < 4; ++j) {
                    if (opened2[i][j]) {
                        cout << "    " << arr[i][j] << "  ";
                    }
                    else
                    {

                        cout << "    " << "*  ";
                    }
                }
                cout << endl;
            }


            if (arr[x1][y1] != arr[x2][y2])
            {
                opened2[x1][y1] = false;
                opened2[x2][y2] = false;

                cout << "Карточки не совпали. Попробуйте снова." << endl;
                int stolbs_3[4] = { 0, 1, 2, 3 };
                for (int i = 0; i < 4; i++)
                {
                    cout << "     " << stolbs_3[i] << "";

                }
                int str_3[2] = { 0,1 };
                cout << endl;
                for (int i = 0; i < 2; ++i)
                {
                    cout << " " << str_3[i];
                    for (int j = 0; j < 4; ++j)
                    {
                        if (opened2[i][j]) {
                            cout << "   " << arr[i][j] << "  ";
                        }
                        else
                        {

                            cout << "   " << "*  ";
                        }

                    }
                    cout << endl;
                }

            }
        }
        cout << "Поздравляем, вы нашли все пары!" << endl;

    }



    if (choicesize == 3)
    {



        int arr[pole_3_size_1][pole_3_size_2]
        {
            {1, 1, 2},     // первая строка    
            {2, 3, 3},     // вторая строка      
        };
        srand(time(0));
        for (unsigned i = 0; i < 2; ++i)
        {
            for (unsigned u = 0; u < 3; ++u)
            {
                swap(arr[i][u], arr[rand() % 2][rand() % 3]);
            }
        }

        int stolbs[3] = { 0, 1, 2 };
        for (int i = 0; i < 3; i++)
        {
            cout << "     " << stolbs[i] << "";

        }
        cout << endl;
        int str[2] = { 0,1 };
        //Вывод двумерного массива на экран    
        for (int i = 0; i < 2; ++i)
        {
            cout << " " << str[i];
            for (int j = 0; j < 3; ++j)
            {
                cout << "   " << polesecret3[i][j] << "  ";
            }
            cout << endl;

        }
        while (!isGameOver3(opened3))
        {
            int x1, y1, x2, y2;
            cout << "Введите координаты первой карточки: ";
            cin >> y1 >> x1;
            if (x1 < 0 && x1 >= 3 && y1 < 0 && y1 >= 2 && opened3[x1][y1])
            {
                cout << "Неверные координаты или карточка уже открыта. Попробуйте снова." << std::endl;
                continue;
            }

            opened3[x1][y1] = true;
            int stolbs[3] = { 0, 1, 2 };
            for (int i = 0; i < 3; i++)
            {
                cout << "      " << stolbs[i] << "";

            }
            int str[2] = { 0,1 };
            cout << endl;
            for (int i = 0; i < 2; ++i)
            {
                cout << " " << str[i];

                for (int j = 0; j < 3; ++j)
                {
                    if (opened3[i][j])
                    {
                        cout << "    " << arr[i][j] << "  ";
                    }
                    else
                    {

                        cout << "    " << "*  ";
                    }

                }
                cout << endl;
            }


            cout << "Введите координаты второй карточки: ";
            cin >> y2 >> x2;

            if (x2 < 0 && x2 >= 3 && y2 < 0 && y2 >= 2 && opened3[x2][y2])
            {
                cout << "Неверные координаты или карточка уже открыта. Попробуйте снова." << std::endl;
                opened3[x1][y1] = false;
                for (int i = 0; i < 2; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        if (opened3[i][j])
                        {
                            cout << arr[i][j] << " ";
                        }
                        else
                        {

                            cout << "* ";
                        }

                    }
                    cout << endl;
                }
            }

            opened3[x2][y2] = true;
            int stolbs_2[3] = { 0, 1,2 };
            for (int i = 0; i < 3; i++)
            {
                cout << "      " << stolbs_2[i] << "";

            }
            int str_2[2] = { 0,1 };
            cout << endl;
            for (int i = 0; i < 2; ++i)
            {
                cout << " " << str_2[i];
                for (int j = 0; j < 3; ++j)
                {
                    if (opened3[i][j])
                    {
                        cout << "    " << arr[i][j] << "  ";
                    }
                    else {

                        cout << "    " << "*  ";
                    }
                }
                cout << endl;
            }


            if (arr[x1][y1] != arr[x2][y2])
            {
                opened3[x1][y1] = false;
                opened3[x2][y2] = false;

                cout << "Карточки не совпали. Попробуйте снова." << endl;
                int stolbs_3[3] = { 0, 1,2 };
                for (int i = 0; i < 3; i++)
                {
                    cout << "     " << stolbs_3[i] << "";

                }
                int str_3[2] = { 0,1 };
                cout << endl;
                for (int i = 0; i < 2; ++i)
                {
                    cout << " " << str_3[i];
                    for (int j = 0; j < 3; ++j)
                    {
                        if (opened3[i][j])
                        {
                            cout << "   " << arr[i][j] << "  ";
                        }
                        else
                        {

                            cout << "   " << "*  ";
                        }

                    }
                    cout << endl;
                }

            }
        }
        cout << "Поздравляем, вы нашли все пары!" << endl;


    }








    if (choicesize == 4)
    {
        int arr[pole_4_size_1][pole_4_size_2]
        {
             {1, 1, 2, 2},
             {3, 3, 4, 4},
             {5, 5, 6, 6},
             {7, 7, 8, 8}
        };
        srand(time(0));
        for (unsigned i = 0; i < 4; ++i)
        {
            for (unsigned u = 0; u < 4; ++u)
            {
                swap(arr[i][u], arr[rand() % 4][rand() % 4]);
            }
        }

        int stolbs[4] = { 0, 1, 2, 3 };
        for (int i = 0; i < 4; i++)
        {
            cout << "     " << stolbs[i] << "";

        }
        cout << endl;
        int str[4] = { 0,1, 2, 3 };
        //Вывод двумерного массива на экран    
        for (int i = 0; i < 4; ++i)
        {
            cout << " " << str[i];
            for (int j = 0; j < 4; ++j)
            {
                cout << "   " << polesecret4[i][j] << "  ";
            }
            cout << endl;

        }
        while (!isGameOver4(opened4))
        {
            int x1, y1, x2, y2;
            cout << "Введите координаты первой карточки: ";
            cin >> y1 >> x1;
            if (x1 < 0 && x1 >= 4 && y1 < 0 && y1 >= 4 && opened4[x1][y1])
            {
                cout << "Неверные координаты или карточка уже открыта. Попробуйте снова." << std::endl;
                continue;
            }

            opened4[x1][y1] = true;
            int stolbs[4] = { 0, 1, 2, 3 };
            for (int i = 0; i < 4; i++)
            {
                cout << "      " << stolbs[i] << "";

            }
            int str[4] = { 0,1, 2, 3 };
            cout << endl;
            for (int i = 0; i < 4; ++i)
            {
                cout << " " << str[i];

                for (int j = 0; j < 4; ++j)
                {
                    if (opened4[i][j])
                    {
                        cout << "    " << arr[i][j] << "  ";
                    }
                    else {

                        cout << "    " << "*  ";
                    }

                }
                cout << endl;
            }


            cout << "Введите координаты второй карточки: ";
            cin >> y2 >> x2;

            if (x2 < 0 && x2 >= 4 && y2 < 0 && y2 >= 4 && opened4[x2][y2])
            {
                std::cout << "Неверные координаты или карточка уже открыта. Попробуйте снова." << std::endl;
                opened4[x1][y1] = false;
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (opened4[i][j]) {
                            cout << arr[i][j] << " ";
                        }
                        else
                        {

                            cout << "* ";
                        }

                    }
                    cout << endl;
                }
            }

            opened4[x2][y2] = true;
            int stolbs_2[4] = { 0, 1,2,3 };
            for (int i = 0; i < 4; i++)
            {
                cout << "      " << stolbs_2[i] << "";

            }
            int str_2[4] = { 0,1, 2, 3 };
            cout << endl;
            for (int i = 0; i < 4; ++i)
            {
                cout << " " << str_2[i];
                for (int j = 0; j < 4; ++j)
                {
                    if (opened4[i][j])
                    {
                        cout << "    " << arr[i][j] << "  ";
                    }
                    else {

                        cout << "    " << "*  ";
                    }
                }
                cout << endl;
            }


            if (arr[x1][y1] != arr[x2][y2])
            {
                opened4[x1][y1] = false;
                opened4[x2][y2] = false;

                cout << "Карточки не совпали. Попробуйте снова." << endl;
                int stolbs_3[4] = { 0, 1,2, 3 };
                for (int i = 0; i < 4; i++)
                {
                    cout << "     " << stolbs_3[i] << "";

                }
                int str_3[4] = { 0,1, 2, 3 };
                cout << endl;
                for (int i = 0; i < 4; ++i)
                {
                    cout << " " << str_3[i];
                    for (int j = 0; j < 4; ++j)
                    {
                        if (opened4[i][j])
                        {
                            cout << "   " << arr[i][j] << "  ";
                        }
                        else {

                            cout << "   " << "*  ";
                        }

                    }
                    cout << endl;
                }

            }
        }
        cout << "Поздравляем, вы нашли все пары!" << endl;


    }

}
