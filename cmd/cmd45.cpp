#include "header.h"

bool fileIsExist(string file)
{
    fstream f(file, ios::in);
    if (f.is_open())
    {
        f.close();
        return true;
    }
    cout << "File does not exist" << endl;
    f.close();
    return false;
}

int *initInputArray(string file, int &n)
{
    fstream f(file, ios::in);

    string size;
    getline(f, size);
    n = stoi(size);
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        string num;
        f >> num;
        if (num != " ")
        {
            arr[i] = stoi(num);
        }
    }

    f.close();
    return arr;
}

string inputOrder(string order, int *&a, int n)
{
    string order_name;
    a = new int[n];

    if (order == "-rand")
    {
        order_name = "Random";
        GenerateData(a, n, 0);
    }
    else if (order == "-nsorted")
    {
        order_name = "Nearly Sorted";
        GenerateData(a, n, 3);
    }
    else if (order == "-sorted")
    {
        order_name = "Sorted";
        GenerateData(a, n, 1);
    }
    else if (order == "-rev")
    {
        order_name = "Reserved";
        GenerateData(a, n, 2);
    }
    else
    {
        cout << "No data order existed" << endl;
        return "ERROR";
    }

    fstream f("input.txt", ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << a[i] << " ";
    }
    cout << endl;
    f.close();

    return order_name;
}

void measure(string sort_name, int *a, int n)
{
    if (sort_name == "flash-sort")
    {
        cout<<"Run flash";
        long long count_compare = 0;
        //Call measure function
    }
    else if (sort_name == "heap-sort")
    {
        cout<<"Run heap";
        long long count_compare = 0;
        //Call measure function
    }
    else if (sort_name == "merge-sort")
    {
        cout<<"Run merge";
        long long count_compare = 0;
        //Call measure function
    }
}

void cmd4(int argc, const char *argv[])
{
    if (argc != 5)
        return;

    string mode = argv[1];

    if (mode == "-c")
    {
        string sort1 = argv[2];
        string sort2 = argv[3];
        string input_file = argv[4];

        if (fileIsExist(input_file))
        {
            int size;
            int *a = initInputArray(input_file, size);

            cout << "COMPARE MODE" << endl;
            cout << "Algorithm: " << sort1 << " | " << sort2 << endl;
            cout << "Input file: " << input_file << endl;
            cout << "Input size: " << size << endl;

            cout << "Running time: ";
            measure(sort1, a, size);
            cout << " | ";
            measure(sort2, a, size);
            cout << endl;

            cout << "Comparisions: ";
            measure(sort1, a, size);
            cout << " | ";
            measure(sort2, a, size);
            cout << endl;
        }
    }
}

void cmd5(int argc, const char *argv[])
{
    if (argc != 6)
        return;

    string mode = argv[1];

    if (mode == "-c")
    {
        int *a;
        string sort1 = argv[2];
        string sort2 = argv[3];
        string size = argv[4];
        string order = argv[5];
        string order_name = inputOrder(order, a, stoi(size));

        cout << "COMPARE MODE" << endl;
        cout << "Algorithm: " << sort1 << " | " << sort2 << endl;
        cout << "Input size: " << size << endl;
        cout << "Input order: " << order_name << endl;
        cout << "-----------------" << endl;

        cout << "Running time: ";
        measure(sort1, a, stoi(size));
        cout << " | ";
        measure(sort2, a, stoi(size));
        cout << endl;

        cout << "Comparisions: ";
        measure(sort1, a, stoi(size));
        cout << " | ";
        measure(sort2, a, stoi(size));
        cout << endl;
    }
}