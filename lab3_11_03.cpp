#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
class Function_graph
{
public:
    int count_line;
    string s;
    float foo(float param_x)
    {
        double y;
        // cout << x << endl;
        // Проверяем условия и вычисляем значение Y
        if (param_x < -3 || param_x > 7) {
            y = 0;
        } else if (-3 <= param_x && param_x <= -2) {
            // Вычисляем значение Y для прямой
            y = -1*param_x - 2;
        } else if (-2 < param_x && param_x <= 0) {
            // Вычисляем значение Y для полуокружности
            y = sqrt(1 - pow(param_x + 1, 2));
        } else if (0 < param_x && param_x < 4) {
            // Вычисляем значение Y для полуокружности
            y = -sqrt(4 - pow(param_x - 2, 2));
        } else if (4 <= param_x && param_x <= 6) {
            // Вычисляем значение Y для прямой
            y = -1.0 / 2.0 * (param_x - 4);
        } else if (6 < param_x && param_x <= 7) {
            // Вычисляем значение Y для прямой
            y = -1;
        }
        return y;
    }
    void writing_to_file()
    {
        double rez_y;
        ofstream output_file("output.txt"); 
        count_line = 0;
        for (double x = -3.0; x <= 7; x += 0.5) {
            rez_y = foo(x);
            output_file << rez_y << endl;
            count_line++;
        }

        output_file.close(); 
    }
    void reading_from_file()
    {
        ifstream input_file("output.txt");
        double values[count_line]; 

        for (int i = 0; i < count_line; i++) {
            input_file >> values[i];
        }

        input_file.close();

        for (int i = 0; i < count_line; i++) {
            cout << "Y[" << i << "] = " << values[i] << endl;
        }
    }
};

int main()
{
    Function_graph graph18;
    graph18.writing_to_file();
    graph18.reading_from_file();
}