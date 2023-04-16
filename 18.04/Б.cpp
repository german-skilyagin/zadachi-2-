#include <stack>
#include <string>
#include <iostream>
using namespace std;

int cursor_row = 0;
int cursor_col = 0;
string text;
stack<pair<int, char>> undo_stack;
stack<pair<int, char>> redo_stack;

void MoveCursorTo(int row, int col) {
    cursor_row = row;
    cursor_col = col;
}

void InsertChar(char c) {
    text.insert(cursor_row * cursor_col + cursor_col, 1, c);
    undo_stack.push(make_pair(cursor_row * cursor_col + cursor_col, c));
    cursor_col++;
}

void DeleteChar() {
    if (text.length() == 0 || cursor_col == 0) return;
    char c = text[cursor_row * cursor_col + cursor_col - 1];
    text.erase(cursor_row * cursor_col + cursor_col - 1, 1);
    undo_stack.push(make_pair(cursor_row * cursor_col + cursor_col - 1, c));
    cursor_col--;
}

void Undo() {
    if (undo_stack.empty()) return;
    pair<int, char> last_change = undo_stack.top();
    undo_stack.pop();
    redo_stack.push(make_pair(last_change.first, text[last_change.first]));
    text.erase(last_change.first, 1);
    MoveCursorTo(last_change.first / cursor_col, last_change.first % cursor_col);
}

void Redo() {
    if (redo_stack.empty()) return;
    pair<int, char> last_change = redo_stack.top();
    redo_stack.pop();
    InsertChar(last_change.second);
}



int main() {
    setlocale(LC_ALL, "RUSSIAN");
    MoveCursorTo(0, 0);
    InsertChar('П');
    InsertChar('О');
    InsertChar('Б');
    InsertChar('Е');
    InsertChar('Д');
    InsertChar('А');
    cout << text << endl;
    Undo();
    cout << text << endl;
    Redo();
    cout << text << endl;
    DeleteChar();
    cout << text << endl;
    return 0;
}