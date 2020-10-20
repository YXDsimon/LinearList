#include <iostream>
#include <string>
using namespace std;

class ArrayList
{
private:
    int List[100];
    int len;

public:
    ArrayList(string input, int LenOfInput)
    {
        for (int i = 0; i < LenOfInput; i++)
        {
            List[i] = input[i];
        }
        len = LenOfInput;
    }
    bool insert_list(int index, string val)
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
    ArrayList operator+(const ArrayList &b)
    {
        string list;
        for (int i = 0; i < this->len; i++)
        {
            list[i] = this->List[i];
        }
        for (int i = 0; i < b.len; i++)
        {
            list[i + this->len] = b.List[i];
        }
        ArrayList c(list, this->len + b.len);
        return c;
    }
};

int main()
{
    string a = "I love";
    string b = "Data Structure";
    cout<<sizeof(a)/sizeof(a[0]);
    ArrayList array1(a,sizeof(a)/sizeof(a[0])) ;
}