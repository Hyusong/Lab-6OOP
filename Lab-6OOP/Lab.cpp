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

    void додати≈лемент(BinaryTreeNode<T>*& поточний¬узол, T значенн€) {
        if (поточний¬узол == nullptr) {
            поточний¬узол = new BinaryTreeNode<T>(значенн€);
        }
        else {
            if (значенн€ < поточний¬узол->data) {
                додати≈лемент(поточний¬узол->left, значенн€);
            }
            else {
                додати≈лемент(поточний¬узол->right, значенн€);
            }
        }
    }

    void проходженн€”—падномуѕор€дку(BinaryTreeNode<T>* поточний¬узол) const {
        if (поточний¬узол != nullptr) {
            проходженн€”—падномуѕор€дку(поточний¬узол->right);
            cout << поточний¬узол->data << " ";
            проходженн€”—падномуѕор€дку(поточний¬узол->left);
        }
    }

    void проходженн€”¬исх≥дномуѕор€дку(BinaryTreeNode<T>* поточний¬узол) const {
        if (поточний¬узол != nullptr) {
            проходженн€”¬исх≥дномуѕор€дку(поточний¬узол->left);
            cout << поточний¬узол->data << " ";
            проходженн€”¬исх≥дномуѕор€дку(поточний¬узол->right);
        }
    }

    BinaryTreeNode<T>* пошук≈лемента(BinaryTreeNode<T>* поточний¬узол, T значенн€) const {
        if (поточний¬узол == nullptr || поточний¬узол->data == значенн€) {
            return поточний¬узол;
        }

        if (значенн€ < поточний¬узол->data) {
            return пошук≈лемента(поточний¬узол->left, значенн€);
        }

        return пошук≈лемента(поточний¬узол->right, значенн€);
    }

public:
    BinaryTree() : root(nullptr) {}

    void додати(T значенн€) {
        додати≈лемент(root, значенн€);
    }

    void спаднийѕор€док() const {
        проходженн€”—падномуѕор€дку(root);
        cout << endl;
    }

    void висх≥днийѕор€док() const {
        проходженн€”¬исх≥дномуѕор€дку(root);
        cout << endl;
    }

    bool знайти≈лемент(T значенн€) const {
        return пошук≈лемента(root, значенн€) != nullptr;
    }
};

int main() {
    BinaryTree<int> дерево;
    setlocale(LC_ALL, "Ukranian");

    дерево.додати(50);
    дерево.додати(30);
    дерево.додати(70);
    дерево.додати(20);
    дерево.додати(40);
    дерево.додати(60);
    дерево.додати(80);

    cout << "Spadnyy poryadok: ";
    дерево.спаднийѕор€док();

    cout << "Vyskhidnyy poryadok: ";
    дерево.висх≥днийѕор€док();

    int елементƒл€ѕошуку = 40;
    if (дерево.знайти≈лемент(елементƒл€ѕошуку)) {
        cout << "Element " << елементƒл€ѕошуку << " znaydenyy v derevi." << endl;
    }
    else {
        cout << "Element " << елементƒл€ѕошуку << " ne znaydenyy v derevi." << endl;
    }

    return 0;
}
