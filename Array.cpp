#include <iostream>
#include <string>
using namespace std;

class ArrayList
{
private:
    string List;
    int len;

public:
    ArrayList(string input, int LenOfInput)
    {
        for (int i = 0; i < LenOfInput; i++)
        {
            List += input[i];
        }
        len = LenOfInput;
    }
    void print()
    {
        cout << "The List is:" << List << endl;
    }
    string operator+(const ArrayList &b)
    {
        return this->List +' '+ b.List;
    }
};

int main()
{
    string a = "I love";
    string b = "Data Structure";
    ArrayList array1(a, a.length());
    ArrayList array2(b, b.length());
    cout << array1 + array2 << endl;
}