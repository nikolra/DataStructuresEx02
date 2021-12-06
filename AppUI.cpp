#include "AppUI.h"

void AppUI::Run()
{
    int size = readInt();

    string input;
    getline(cin, input);
    char* delim = new char(' ');
    char action = input[0];
    char* token = strtok(stringToCharArray(input), delim);
    if((*(token + 1) != '\0') || *token != 'e')
        throw HeapException("wrong input");
    else{
        MinMaxMedianHeap heap = MinMaxMedianHeap(MAX_SIZE);
        for(int i = 1 ; i < size; i++)
        {
            checkInput(heap);
            cout << i << endl;
        }
    }
}

int AppUI::readInt()
{
    try{
        string input;
        char* delim = new char(' ');
        getline(cin, input);//reads the size of the array
        char* token = strtok(stringToCharArray(input), delim);
        if(token == nullptr)//to little numbers
            throw HeapException("wrong input");
        int num = stoi(input);
        token = strtok(nullptr, delim);
        if(token != nullptr)//to many numbers
            throw HeapException("wrong input");

        return num;
    }
    catch(exception e)
    {
        throw HeapException("wrong input");
    }


}

char* AppUI::stringToCharArray(string& s)
{
    char* res = new char[s.length() + 1];
    for(int i = 0; i < s.length(); i++)
    {
        res[i] = s[i];
    }

    res[s.length()] = '\0';

    return res;
}

void AppUI::commitAction(char c, MinMaxMedianHeap& heap)
{
    switch(c){
        case 'a':
                cout << heap.Max() << endl;
            break;
        case 'b':
                cout << heap.DeleteMax() << endl;
            break;
        case 'c':
                cout << heap.Min() << endl;
            break;
        case 'd':
                cout << heap.DeleteMin() << endl;
            break;
        case 'g':
                cout << heap.Median() << endl;
            break;
        default:
            throw HeapException("wrong input");
    }
}

void AppUI::checkInput(MinMaxMedianHeap& heap)
{
    string input;
    getline(cin, input);
    char* delim = new char(' ');
    char action = input[0];
    char* token = strtok(stringToCharArray(input), delim);
    if(*(token + 1) == '\0' && *token == 'f')
    {
        token = strtok(nullptr, delim);
        if(token == nullptr)
            throw HeapException("wrong input");
        try{
            int priority = stoi(token);
            token = strtok(nullptr, delim);
            if(token == nullptr)
                throw HeapException("wrong input");
            heap.Insert(priority, token);
        }
        catch (exception e)
        {
            throw HeapException("wrong input");
        }
    }
    else commitAction(action, heap);

}