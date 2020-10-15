#include <iostream>
#include <string>
using namespace std;

class ArrayList
{
private:
    int List[100];
    int len;

public:
    ArrayList(int *input, int LenOfInput)
    {
        for (int i = 0; i < LenOfInput; i++)
        {
            List[i] = input[i];
        }
        len = LenOfInput;
    }
    bool insert_list(int index, int val)
    {
        if (index < 0 || index > len)
        {
            cout << "illegal index!" << endl;
            return 0;
        }
        for (int i = len + 1; i > index; i--)
        {
            List[i] = List[i - 1];
            List[i - 1] = val;
        }
        len++;
        return 1;
    }
    int delete_list(int index)
    {
        if (index < 0 || index > len)
        {
            cout << "illegal index!" << endl;
            return 0;
        }
        for (int i = index; i < len - 1; i++)
        {
            List[i] = List[i + 1];
        }
        len--;
    }
    void print()
    {
        cout << "The List is:" << endl;
        for (int i = 0; i < len; i++)
        {
            cout << List[i];
            if (i == len - 1)
            {
                cout << endl;
            }
            else
            {
                cout << ' ';
            }
        }
    }
};

int main()
{
    int num[100]; //int型数组用于存储输入变量
    int i = 0;
    cout << "Please enter the list you want, elements separated by space:" << endl;
    while (cin >> num[i])
    {
        if (cin.get() == '\n')
            break;
        i++;
    }
    ArrayList arraylist(num, i + 1);
    arraylist.print();
    int index;
    int val;
    cout << "Enter index where you want to insert:" << endl;
    cin >> index;
    cout << "Enter value that you want to insert:" << endl;
    cin >> val;
    // arraylist.insert_list(index, val);
    // arraylist.print();
    // cout << "type in index where you want to delete:" << endl;
    // cin >> index;
    // arraylist.delete_list(index);
    // arraylist.print();
}