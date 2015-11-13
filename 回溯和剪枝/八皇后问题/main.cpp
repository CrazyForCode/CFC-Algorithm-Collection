#include <iostream>
#include <stack>
#define matrix_side_length 12

using namespace std;

bool isSafe(int *queeenPlace, int index) {
    for (int i = 0; i < index; ++i) {
        if (queeenPlace[i] == queeenPlace[index] ||
            queeenPlace[i] - queeenPlace[index] == i - index ||
            queeenPlace[i] - queeenPlace[index] == index - i) {
            return false;
        }
    }
    return true;
}

int printResult(int *queenPlace, int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (queenPlace[j] == i) {
                cout<<"Q ";
            } else {
                cout<<". ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

int main(int argc, const char * argv[]) {
    int queenPlace[matrix_side_length] = {0};//用以表示皇后所在位置
    queenPlace[0] = 0;
    int pointer = 0;
    int count = 0;
    bool flag = false;
    while (true) {
        if (flag && pointer == 0) {
            cout<<count<<" in total"<<endl;
            return 1;
        }
        if (isSafe(queenPlace, pointer)) {//当前位置安全
            if (pointer == matrix_side_length - 1) {//找到解
                if (queenPlace[0] == matrix_side_length - 1) {
                    flag = true;
                }
                count++;
                printResult(queenPlace, matrix_side_length);
                for (int i = pointer; i >= 0; --i) {
                    if (queenPlace[pointer] == matrix_side_length - 1)
                        pointer--;
                    else
                        break;
                }
                queenPlace[pointer]++;
                for (int i = pointer + 1; i < matrix_side_length; ++i) {
                    queenPlace[i] = 0;
                }
                pointer--;
            }
            pointer++;
        } else if (queenPlace[pointer] < matrix_side_length - 1) {
            queenPlace[pointer]++;
        } else {
            for (int i = pointer; i >= 0; --i) {
                if (queenPlace[pointer] == matrix_side_length - 1) {
                    pointer--;
                } else {
                    break;
                }
            }
            queenPlace[pointer]++;
            for (int i = pointer + 1; i < matrix_side_length; ++i) {
                queenPlace[i] = 0;
            }
        }
    }
}
