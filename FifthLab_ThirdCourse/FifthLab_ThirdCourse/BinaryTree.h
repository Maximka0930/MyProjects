#pragma once
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

class BinaryTree {
public:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int value) : key(value), left(nullptr), right(nullptr) {}
    };

    struct BPlusNode {
        std::vector<int> keys;
        std::vector<BPlusNode*> children;
        bool isLeaf;
        BPlusNode* next;

        BPlusNode(bool isLeaf) : isLeaf(isLeaf), next(nullptr) {}
    };

    BPlusNode* bPlusRoot; // Корень B+ дерева
    
    struct RBNode {
        int key;
        bool color;  // true - красный, false - чёрный
        RBNode* left;
        RBNode* right;
        RBNode* parent;

        RBNode(int k) : key(k), color(true), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    RBNode* rbRoot; // Корень красно-чёрного дерева




    BinaryTree(int order = 3) : root(nullptr), bPlusRoot(nullptr){}
    int order;

    void generateRandomKeys(int n, int d_min, int d_max);
    void transformToBPlus();
    //void collectKeysInOrder(Node* node, std::vector<int>& keys);
    //BPlusNode* buildBPlusTree(const std::vector<int>& keys);
    void insertBPlus(int key);

    //void insertNonFull(BPlusNode* node, int key);
    //void split(BPlusNode* parent, BPlusNode* child, int index);
    //BPlusNode* findLeaf(BPlusNode* node, int key);
    void insertIntoRedBlackTree(int key);

    

    //RedBlackNode* redBlackRoot;

    void transformToRedBlack();
    void insertRedBlack(int key);

    Node* root;
    Node* negativesRoot = nullptr;
    Node* nonNegativesRoot = nullptr;


    // Вспомогательные функции
    void insert(Node*& node, int key);
    void clear(Node* node);
    Node* getRoot();

    int calculateSum(Node* node);
    int calculateProduct(Node* node);
    void findUnbalancedNodes(Node* node, std::vector<int>& result);
    void findNodesWithDifferentHeights(Node* node, std::vector<int>& result);

    int findMax(Node* node, int& count);
    bool checkDuplicates(Node* node, std::vector<int>& keys);
    int countMaxDuplicates(Node* node, std::map<int, int>& freq);
    bool isSymmetric(Node* left, Node* right);
    bool isBST(Node* node, int min, int max);
    void collectLeaves(Node* node, std::vector<int>& leaves);

    //Node* buildBalancedTree(const std::vector<int>& values, int start, int end);
    void collectPaths(Node* node, std::vector<std::vector<int>>& paths, std::vector<int>& currentPath);
    void findMinMaxLeafPaths(Node* node, std::vector<int>& currentPath, int& minPath, int& maxPath);
    int findLastPositiveLevel(Node* node, int level);
    void countInternalAndLeafNodes(Node* node, int level, std::vector<int>& internalCounts, std::vector<int>& leafCounts);
    void findOddLevelSums(Node* node, int level, int& sum);

    void inorderTraversal(Node* node, std::string& result);
    void preorderTraversal(Node* node, std::string& result);
    void postorderTraversal(Node* node, std::string& result);

    void convertToBPlusTree(Node*& node, int m);
    void convertToRedBlackTree(Node*& node);

    int calculateProductOfMultiples(Node* node, int multiple);
    std::vector<int> getLeaves(Node* node);
    int getHeight(Node* node);
    bool isSymmetric(Node* node);
    bool isMirror(Node* t1, Node* t2);
    bool isBST(Node* node, Node* left = nullptr, Node* right = nullptr);

    //Решение задачи #4
    std::vector<int> findNodesWithUnequalSubtreeSizes(Node* node);
    int countSubtreeNodes(Node* node, std::vector<int>& result);
    //Решение задачи #5
    std::vector<int> findNodesWithUnequalSubtreeHeights(Node* node);
    int calculateSubtreeHeights(Node* node, std::vector<int>& result);
    //Решение задачи #6
    int countOccurrences(Node* node, int x);
    //Решение задачи #8
    bool hasDuplicates(Node* node, std::unordered_map<int, int>& valueCount);
    bool containsDuplicates();
    //Решение задачи #9
    void countFrequency(Node* node, std::unordered_map<int, int>& frequency);
    int maxFrequency();


    //Решение задачи #13
    void splitAndBalance();// Разделить дерево и сбалансировать
    void collectElements(Node* node, std::vector<int>& negatives, std::vector<int>& nonNegatives);
    Node* buildBalancedTree(const std::vector<int>& elements, int start, int end);
    //Решение задачи #14
    void printPathsWithMinSum(System::Text::StringBuilder^ sb);
    void findMinSum(Node* node, int currentSum, int& minSum);
    void findAllMinSumPaths(Node* node, std::vector<int>& currentPath, int currentSum, int minSum, System::Text::StringBuilder^ sb);
    //Решение задачи #15
    int findLastLevelWithPositiveElements();
    void findPositiveLevels(Node* node, int currentLevel, int& lastLevelWithPositives);
    //Решение задачи #16
    std::vector<int> findMaxElementPerLevel();
    void findMaxAtEachLevel(Node* node, int level, std::vector<int>& maxElements);
    //Решение задачи #17
    std::vector<std::pair<int, int>> countInternalAndLeafNodesPerLevel();
    void countNodesAtEachLevel(Node* node, int currentLevel, std::vector<std::pair<int, int>>& levelCounts);
    //Решение задачи #18
    int sumOddLevelElements();
    int sumElementsAtOddLevels(Node* node, int currentLevel);
    //Решение задачи #19
    std::pair<std::vector<int>, std::vector<int>> findMinMaxLeafPaths();
    void findLeafPaths(Node* node, std::vector<int>& currentPath, std::vector<int>& minPath, std::vector<int>& maxPath, int& minLength, int& maxLength);
    //Задание задачи #20
    BinaryTree::Node* copyTree(Node* node);
    BinaryTree::Node* makeStrictBinaryTree(Node* node);
    void processStrictBinaryTree(Node* node);
    //Задание задачи #21
    void preOrder(Node* node, System::Text::StringBuilder^ sb);
    void inOrder(Node* node, System::Text::StringBuilder^ sb);
    void postOrder(Node* node, System::Text::StringBuilder^ sb);
    //Решение задачи #22
    void insert(int key);
    void convertToBPlusTree(int m);
    void inorderTraversal(Node* node, std::vector<int>& elements);
    BinaryTree::BPlusNode* buildBPlusTree(const std::vector<int>& elements, int m);

    //Решение задачи #23
    void convertBPlusToRB();
    void collectKeysFromBPlus(BPlusNode* node, std::vector<int>& keys);
    void insertRBNode(int key);
    void fixRBTreeViolation(RBNode* node);
    void leftRotate(RBNode* x);
    void rightRotate(RBNode* x);

public:
    BinaryTree();
    ~BinaryTree();

    void generateRandomTree(int n, int minValue, int maxValue);
    void insertRandom(Node*& current, int value);
    std::string processTasks(int x);
};

