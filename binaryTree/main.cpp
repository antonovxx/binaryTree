#include<iostream>
using namespace std;

class Tree
{
    class Element
    {
        int Data;
        Element* pLeft;
        Element* pRight;
    public:
        Element(int Data, Element* pLeft=nullptr, Element* pRight=nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
        {
            //cout << "EConstructor:\t" << this << endl;
        }
        ~Element()
        {
            //cout << "EDestructor:\t" << this << endl;
        }
        friend class Tree;
    }*Root;
public:
    Element* getRoot()const
    {
        return Root;
    }
    Tree()
    {
        this->Root = nullptr;
        //cout << "TConstructor:\t" << this << endl;
    }
    ~Tree()
    {
        //cout << "TDestructor:\t" << this << endl;
    }

    void insert(int Data)
    {
        insert(Data, Root);
    }
    int minValue()const
    {
        return minValue(Root);
    }
    int maxValue()const
    {
        return maxValue(Root);
    }
    void print()
    {
        print(Root);
    }
    int size()const
    {
        return size(Root);
    }
    int sum(Element* Root)const
    {
        return sum(Root);
    }
    
private:
    void insert(int Data, Element* Root)
    {
        if (this->Root == nullptr)
        {
            this->Root = new Element(Data);
            return;
        }
        
        if (Root == nullptr)return;
        if (Data < Root->Data)
        {
            if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
            else insert(Data, Root->pLeft);
        }
        else
        {
            if (Root->pRight == nullptr)Root->pRight = new Element(Data);
            else insert(Data, Root->pRight);
        }
    }
    
    int minValue(Element* Root)const
    {
        if(Root == nullptr)
            return 0;
//        else if (Root -> pLeft == nullptr)
//            return Root -> Data;
//        else return minValue(Root -> pLeft);
        
        //return Root -> pLeft == nullptr ? Root -> Data : minValue(Root -> pLeft);
        return Root -> pLeft ? minValue(Root -> pLeft) : Root -> Data;
    }
    
    int maxValue(Element* Root)const
    {
        if(Root == nullptr)
            return 0;
//        else if (Root -> pRight == nullptr)
//            return Root -> Data;
//        else return maxValue(Root -> pRight);

        return Root -> pRight == nullptr ? Root -> Data : maxValue(Root -> pRight);
    }
    int size(Element* Root)const
    {
        if(Root == nullptr)
            return 0;
        return size(Root -> pLeft) + size(Root -> pRight) + 1;
    }
    
    int sum(Element* Root)const
    {
        int left, right;
        if(Root != nullptr)
        {
            left = (Root != nullptr) ? sum(Root -> pLeft) : 0;
            right = (Root != nullptr) ? sum(Root -> pRight) : 0;
            return left + right + Root -> Data;
        }
        return 0;
    }

    void print(Element* Root)const
    {
        if (Root == nullptr) return;
        print(Root->pLeft);
        cout << Root->Data << "\t";
        print(Root->pRight);
    }
    
};


int main()
{
    int n;
    cout << "Enter size of the tree: "; cin >> n;
    
    Tree tree;
    for (int i = 0; i < n; i++)
    {
        tree.insert(rand() % 100);
    }
    tree.print();
    cout << endl;
    
    cout << "Min value in the tree: " << tree.minValue() << endl;
    cout << "Max value in the tree: " << tree.maxValue() << endl;
    cout << "Size of the tree: " << tree.size() << endl;
    cout << "Sum of elements: " << tree.sum() << endl;
    
    
    return 0;
    
    
    
    
}
