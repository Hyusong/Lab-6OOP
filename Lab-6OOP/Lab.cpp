#include <iostream>

using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    BinaryTreeNode<T>* root;

    void �������������(BinaryTreeNode<T>*& �������������, T ��������) {
        if (������������� == nullptr) {
            ������������� = new BinaryTreeNode<T>(��������);
        }
        else {
            if (�������� < �������������->data) {
                �������������(�������������->left, ��������);
            }
            else {
                �������������(�������������->right, ��������);
            }
        }
    }

    void ���������������������������(BinaryTreeNode<T>* �������������) const {
        if (������������� != nullptr) {
            ���������������������������(�������������->right);
            cout << �������������->data << " ";
            ���������������������������(�������������->left);
        }
    }

    void �����������������������������(BinaryTreeNode<T>* �������������) const {
        if (������������� != nullptr) {
            �����������������������������(�������������->left);
            cout << �������������->data << " ";
            �����������������������������(�������������->right);
        }
    }

    BinaryTreeNode<T>* �������������(BinaryTreeNode<T>* �������������, T ��������) const {
        if (������������� == nullptr || �������������->data == ��������) {
            return �������������;
        }

        if (�������� < �������������->data) {
            return �������������(�������������->left, ��������);
        }

        return �������������(�������������->right, ��������);
    }

public:
    BinaryTree() : root(nullptr) {}

    void ������(T ��������) {
        �������������(root, ��������);
    }

    void ��������������() const {
        ���������������������������(root);
        cout << endl;
    }

    void ����������������() const {
        �����������������������������(root);
        cout << endl;
    }

    bool �������������(T ��������) const {
        return �������������(root, ��������) != nullptr;
    }
};

int main() {
    BinaryTree<int> ������;
    setlocale(LC_ALL, "Ukranian");

    ������.������(50);
    ������.������(30);
    ������.������(70);
    ������.������(20);
    ������.������(40);
    ������.������(60);
    ������.������(80);

    cout << "Spadnyy poryadok: ";
    ������.��������������();

    cout << "Vyskhidnyy poryadok: ";
    ������.����������������();

    int ���������������� = 40;
    if (������.�������������(����������������)) {
        cout << "Element " << ���������������� << " znaydenyy v derevi." << endl;
    }
    else {
        cout << "Element " << ���������������� << " ne znaydenyy v derevi." << endl;
    }

    return 0;
}
