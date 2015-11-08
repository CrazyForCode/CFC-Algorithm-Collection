#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int x;
    int y;
    int value;
};

int main(int argc, const char * argv[]) {
    int width, height;
    char temp;
    stack<Node*> stack;
    Node * tempNode = new Node();
    Node * root = new Node();
    int result;
    while (true) {
        cin>>width>>height;
        if (width == 0) {
            return 0;
        }
        int *matrix = (int*)malloc(sizeof(int) * width * height);
        for (int j = 0; j < height; ++j) {
            for (int i = 0; i < width; ++i) {
                cin>>temp;
                if (temp == '.') {
                    matrix[j * width + i] = 1;
                } else if (temp  == '#') {
                    matrix[j * width + i] = 0;
                } else if (temp == '@') {
                    root->x = i;
                    root->y = j;
                    root->value = 1;
                    stack.push(root);
                }
            }
        }
        result = 0;
        while (!stack.empty()) {
            root = stack.top();
            matrix[root->y * width + root->x] = 0;
            stack.pop();
            result++;
            if (root->y - 1 > -1 && matrix[(root->y - 1) * width + root->x]) {//上
                stack.push(new Node());
                tempNode = stack.top();
                tempNode->y = root->y - 1;
                tempNode->x = root->x;
                matrix[tempNode->y * width + tempNode->x] = 0;
            }
            if (root->y + 1 < height && matrix[(root->y + 1) * width + root->x]) {//下
                stack.push(new Node());
                tempNode = stack.top();
                tempNode->y = root->y + 1;
                tempNode->x = root->x;
                matrix[tempNode->y * width + tempNode->x] = 0;
            }
            if (root->x - 1 > -1 && matrix[root->y * width + root->x - 1]) {//左
                stack.push(new Node());
                tempNode = stack.top();
                tempNode->y = root->y;
                tempNode->x = root->x - 1;
                matrix[tempNode->y * width + tempNode->x] = 0;
            }
            if (root->x + 1 < width && matrix[root->y * width + root->x + 1]) {//右
                stack.push(new Node());
                tempNode = stack.top();
                tempNode->y = root->y;
                tempNode->x = root->x + 1;
                matrix[tempNode->y * width + tempNode->x] = 0;
            }
        }
        free(matrix);
        cout<<result<<endl;
    }
    return 0;
}
