#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <numeric> // Добавьте этот заголовок
#include <algorithm>
#include <unordered_map>

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    clear(root);
    root = nullptr;  // Убедимся, что корневой узел также сброшен
}

void BinaryTree::insert(Node*& node, int key) {
    if (!node) {
        node = new Node(key);
    }
    else if (key < node->key) {
        insert(node->left, key);
    }
    else {
        insert(node->right, key);
    }
}

void BinaryTree::generateRandomTree(int n, int minValue, int maxValue) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(minValue, maxValue);

    for (int i = 0; i < n; ++i) {
        int value = dist(gen);
        insertRandom(root, value); // Используем новый метод вставки
    }
}

void BinaryTree::insertRandom(Node*& current, int value) {
    if (!current) {
        current = new Node(value); // Создаём новый узел
        return;
    }

    // Генерация случайного выбора, куда вставить следующий элемент
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> choice(0, 1);

    if (choice(gen) == 0) {
        insertRandom(current->left, value); // Вставляем в левое поддерево
    }
    else {
        insertRandom(current->right, value); // Вставляем в правое поддерево
    }
}

int BinaryTree::calculateSum(Node* node) {
    if (!node) return 0;
    return node->key + calculateSum(node->left) + calculateSum(node->right);
}

std::string BinaryTree::processTasks(int x) {
    // Пример выполнения задач:
    std::string result;
    result += "Сумма элементов: " + std::to_string(calculateSum(root)) + "\n";
    // Аналогично вызываются другие методы
    return result;
}

void BinaryTree::findOddLevelSums(Node* node, int level, int& sum) {
    if (!node) return;
    if (level % 2 == 1) sum += node->key;
    findOddLevelSums(node->left, level + 1, sum);
    findOddLevelSums(node->right, level + 1, sum);
}

void BinaryTree::findMinMaxLeafPaths(Node* node, std::vector<int>& currentPath, int& minPath, int& maxPath) {
    if (!node) return;
    currentPath.push_back(node->key);
    if (!node->left && !node->right) {
        int pathSum = std::accumulate(currentPath.begin(), currentPath.end(), 0);
        minPath = std::min(minPath, pathSum);
        maxPath = std::max(maxPath, pathSum);
    }
    findMinMaxLeafPaths(node->left, currentPath, minPath, maxPath);
    findMinMaxLeafPaths(node->right, currentPath, minPath, maxPath);
    currentPath.pop_back();
}

void BinaryTree::convertToRedBlackTree(Node*& node) {
    // Преобразование можно выполнить через последовательный алгоритм добавления
    // узлов с корректировкой высоты и баланса.
    // Здесь код оставлен как пример на случай необходимости.
}

// Метод для вычисления произведения элементов, кратных числу
int BinaryTree::calculateProductOfMultiples(Node* node, int multiple) {
    if (!node) return 1; // Пустой узел, возвращаем 1, чтобы не влиять на произведение
    int product = 1;
    if (node->key % multiple == 0) {
        product *= node->key;
    }
    product *= calculateProductOfMultiples(node->left, multiple);  // Рекурсивно для левого поддерева
    product *= calculateProductOfMultiples(node->right, multiple); // Рекурсивно для правого поддерева
    return product;
}

// Метод для получения всех листьев дерева
std::vector<int> BinaryTree::getLeaves(Node* node) {
    std::vector<int> leaves;
    if (!node) return leaves;

    if (!node->left && !node->right) {  // Лист
        leaves.push_back(node->key);
    }
    std::vector<int> leftLeaves = getLeaves(node->left);  // Рекурсивно для левого поддерева
    leaves.insert(leaves.end(), leftLeaves.begin(), leftLeaves.end());

    std::vector<int> rightLeaves = getLeaves(node->right); // Рекурсивно для правого поддерева
    leaves.insert(leaves.end(), rightLeaves.begin(), rightLeaves.end());

    return leaves;
}

// Метод для вычисления высоты поддерева
int BinaryTree::getHeight(Node* node) {
    if (!node) return 0;
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Метод для проверки симметричности дерева
bool BinaryTree::isSymmetric(Node* node) {
    return isMirror(node, node);
}

// Вспомогательный метод для проверки зеркальности поддеревьев
bool BinaryTree::isMirror(Node* t1, Node* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;

    return (t1->key == t2->key) &&
        isMirror(t1->left, t2->right) &&
        isMirror(t1->right, t2->left);
}

// Метод для проверки, является ли дерево бинарным деревом поиска
bool BinaryTree::isBST(Node* node, Node* left, Node* right) {
    if (!node) return true;

    if (left && node->key <= left->key) return false;
    if (right && node->key >= right->key) return false;

    return isBST(node->left, left, node) && isBST(node->right, node, right);
}

// Метод для поиска максимального элемента в дереве и подсчета количества посещенных узлов
int BinaryTree::findMax(Node* node, int& count) {
    if (!node) {
        return INT_MIN;  // Если узел пустой, возвращаем минимальное возможное значение
    }

    // Увеличиваем счетчик посещенных узлов
    count++;

    // Рекурсивно ищем максимальное значение в левом и правом поддеревьях
    int leftMax = findMax(node->left, count);
    int rightMax = findMax(node->right, count);

    // Возвращаем максимальное из текущего узла, левого и правого поддеревьев
    return std::max(node->key, std::max(leftMax, rightMax));
}

std::vector<int> BinaryTree::findNodesWithUnequalSubtreeSizes(Node* node) {
    std::vector<int> result;
    countSubtreeNodes(node, result);
    return result;
}

int BinaryTree::countSubtreeNodes(Node* node, std::vector<int>& result) {
    if (!node) return 0;

    int leftCount = countSubtreeNodes(node->left, result);
    int rightCount = countSubtreeNodes(node->right, result);

    if (leftCount != rightCount) {
        result.push_back(node->key);
    }

    return leftCount + rightCount + 1;
}

// Метод для нахождения узлов с разными высотами поддеревьев
std::vector<int> BinaryTree::findNodesWithUnequalSubtreeHeights(Node* node) {
    std::vector<int> result;
    calculateSubtreeHeights(node, result);
    return result;
}

int BinaryTree::calculateSubtreeHeights(Node* node, std::vector<int>& result) {
    if (!node) return 0;

    int leftHeight = calculateSubtreeHeights(node->left, result);
    int rightHeight = calculateSubtreeHeights(node->right, result);

    if (leftHeight != rightHeight) {
        result.push_back(node->key);
    }

    return std::max(leftHeight, rightHeight) + 1;
}

int BinaryTree::countOccurrences(Node* node, int x) {
    if (!node) return 0;

    int count = (node->key == x) ? 1 : 0;
    return count + countOccurrences(node->left, x) + countOccurrences(node->right, x);
}

bool BinaryTree::hasDuplicates(Node* node, std::unordered_map<int, int>& valueCount) {
    if (!node) return false;

    valueCount[node->key]++;
    if (valueCount[node->key] > 1) return true;

    return hasDuplicates(node->left, valueCount) || hasDuplicates(node->right, valueCount);
}

bool BinaryTree::containsDuplicates() {
    std::unordered_map<int, int> valueCount;
    return hasDuplicates(root, valueCount);
}

void BinaryTree::countFrequency(Node* node, std::unordered_map<int, int>& frequency) {
    if (!node) return;
    frequency[node->key]++;
    countFrequency(node->left, frequency);
    countFrequency(node->right, frequency);
}

int BinaryTree::maxFrequency() {
    if (!root) return 0; // Если дерево пустое, возвращаем 0
    std::unordered_map<int, int> frequency;
    countFrequency(root, frequency);
    int maxCount = 0;
    for (const auto& pair : frequency) {
        maxCount = std::max(maxCount, pair.second);
    }
    return maxCount;
}

void BinaryTree::clear(Node* node) {
    if (!node) return;
    clear(node->left);  // Рекурсивно очищаем левое поддерево
    clear(node->right); // Рекурсивно очищаем правое поддерево
    delete node;        // Освобождаем память
}

void BinaryTree::printPathsWithMinSum(System::Text::StringBuilder^ sb) {
    int minSum = INT_MAX;
    findMinSum(root, 0, minSum);
    std::vector<int> currentPath;
    sb->Append("14. Пути у которых суммарный вес элементов \n");
    sb->Append("минимальный: ");
    sb->Append(minSum + ":\n");
    findAllMinSumPaths(root, currentPath, 0, minSum, sb);
}
// Вспомогательный метод для нахождения минимальной суммы пути
void BinaryTree::findMinSum(Node* node, int currentSum, int& minSum) {
    if (!node) return;

    currentSum += node->key;

    if (!node->left && !node->right) { // Лист
        if (currentSum < minSum) {
            minSum = currentSum;
        }
    }

    findMinSum(node->left, currentSum, minSum);
    findMinSum(node->right, currentSum, minSum);
}

// Вспомогательный метод для поиска путей с минимальной суммой
void BinaryTree::findAllMinSumPaths(Node* node, std::vector<int>& currentPath, int currentSum, int minSum, System::Text::StringBuilder^ sb) {
    if (!node) return;

    currentPath.push_back(node->key);
    currentSum += node->key;

    if (!node->left && !node->right) { // Лист
        if (currentSum == minSum) {
            for (int val : currentPath) {
                sb->Append(val + " ");
            }
            sb->Append("\n");
        }
    }
    else {
        findAllMinSumPaths(node->left, currentPath, currentSum, minSum, sb);
        findAllMinSumPaths(node->right, currentPath, currentSum, minSum, sb);
    }

    currentPath.pop_back(); // Убираем последний элемент для возврата к предыдущему уровню
}

int BinaryTree::findLastLevelWithPositiveElements() {
    int lastLevelWithPositives = -1;
    findPositiveLevels(root, 0, lastLevelWithPositives);
    return lastLevelWithPositives;
}

// Вспомогательный метод для поиска уровня с положительными элементами
void BinaryTree::findPositiveLevels(Node* node, int currentLevel, int& lastLevelWithPositives) {
    if (!node) return;

    if (node->key > 0) {
        lastLevelWithPositives = std::max(lastLevelWithPositives, currentLevel);
    }

    findPositiveLevels(node->left, currentLevel + 1, lastLevelWithPositives);
    findPositiveLevels(node->right, currentLevel + 1, lastLevelWithPositives);
}

std::vector<int> BinaryTree::findMaxElementPerLevel() {
    std::vector<int> maxElements;
    findMaxAtEachLevel(root, 0, maxElements);
    return maxElements;
}
// Вспомогательный метод для поиска максимального элемента на каждом уровне
void BinaryTree::findMaxAtEachLevel(Node* node, int currentLevel, std::vector<int>& maxElements) {
    if (!node) return;

    if (maxElements.size() <= currentLevel) {
        maxElements.push_back(node->key); // Добавляем первый элемент уровня
    }
    else {
        maxElements[currentLevel] = std::max(maxElements[currentLevel], node->key); // Обновляем максимум
    }

    findMaxAtEachLevel(node->left, currentLevel + 1, maxElements);
    findMaxAtEachLevel(node->right, currentLevel + 1, maxElements);
}

std::vector<std::pair<int, int>> BinaryTree::countInternalAndLeafNodesPerLevel() {
    std::vector<std::pair<int, int>> levelCounts;
    countNodesAtEachLevel(root, 0, levelCounts);
    return levelCounts;
}

// Вспомогательный метод для подсчёта внутренних вершин и листьев
void BinaryTree::countNodesAtEachLevel(Node* node, int currentLevel, std::vector<std::pair<int, int>>& levelCounts) {
    if (!node) return;

    // Расширяем вектор, если текущего уровня ещё нет
    if (levelCounts.size() <= currentLevel) {
        levelCounts.emplace_back(0, 0); // Добавляем пару (внутренние вершины, листья)
    }

    // Проверяем, является ли узел листом
    if (!node->left && !node->right) {
        levelCounts[currentLevel].second++; // Увеличиваем счётчик листьев
    }
    else {
        levelCounts[currentLevel].first++; // Увеличиваем счётчик внутренних вершин
    }

    // Рекурсивно обрабатываем поддеревья
    countNodesAtEachLevel(node->left, currentLevel + 1, levelCounts);
    countNodesAtEachLevel(node->right, currentLevel + 1, levelCounts);
}

int BinaryTree::sumOddLevelElements() {
    return sumElementsAtOddLevels(root, 0);
}

// Вспомогательный рекурсивный метод
int BinaryTree::sumElementsAtOddLevels(Node* node, int currentLevel) {
    if (!node) return 0;

    // Если уровень нечётный, включаем значение узла в сумму
    int sum = (currentLevel % 2 != 0) ? node->key : 0;

    // Рекурсивно добавляем суммы от левого и правого поддерева
    sum += sumElementsAtOddLevels(node->left, currentLevel + 1);
    sum += sumElementsAtOddLevels(node->right, currentLevel + 1);

    return sum;
}

std::pair<std::vector<int>, std::vector<int>> BinaryTree::findMinMaxLeafPaths() {
    std::vector<int> currentPath, minPath, maxPath;
    int minLength = INT_MAX, maxLength = INT_MIN;

    findLeafPaths(root, currentPath, minPath, maxPath, minLength, maxLength);

    return { minPath, maxPath };
}

// Вспомогательный рекурсивный метод
void BinaryTree::findLeafPaths(Node* node, std::vector<int>& currentPath, std::vector<int>& minPath, std::vector<int>& maxPath, int& minLength, int& maxLength) {
    if (!node) return;

    currentPath.push_back(node->key); // Добавляем текущий узел в путь

    // Если узел является листом
    if (!node->left && !node->right) {
        int pathLength = currentPath.size();

        // Проверка минимального пути
        if (pathLength < minLength) {
            minLength = pathLength;
            minPath = currentPath;
        }

        // Проверка максимального пути
        if (pathLength > maxLength) {
            maxLength = pathLength;
            maxPath = currentPath;
        }
    }

    // Рекурсивный вызов для левого и правого поддерева
    findLeafPaths(node->left, currentPath, minPath, maxPath, minLength, maxLength);
    findLeafPaths(node->right, currentPath, minPath, maxPath, minLength, maxLength);

    currentPath.pop_back(); // Удаляем текущий узел из пути
}

BinaryTree::Node* BinaryTree::copyTree(Node* node) {
    if (!node) return nullptr;
    Node* newNode = new Node(node->key); // Копируем ключ
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}

BinaryTree::Node* BinaryTree::makeStrictBinaryTree(Node* node) {
    if (!node) return nullptr;

    Node* copiedNode = copyTree(node); // Создаём копию дерева
    processStrictBinaryTree(copiedNode); // Преобразуем копию
    return copiedNode; // Возвращаем копию
}

void BinaryTree::processStrictBinaryTree(Node* node) {
    if (!node) return;

    // Рекурсивно обрабатываем поддеревья
    processStrictBinaryTree(node->left);
    processStrictBinaryTree(node->right);

    // Если у узла только один потомок, заменяем узел на его единственного потомка
    if (node->left && !node->right) {
        Node* tmp = node->left;
        node->key = tmp->key;
        node->right = tmp->right;
        node->left = tmp->left;
        delete tmp;
        processStrictBinaryTree(node); // Проверяем узел после замены
    }
    else if (!node->left && node->right) {
        Node* tmp = node->right;
        node->key = tmp->key;
        node->left = tmp->left;
        node->right = tmp->right;
        delete tmp;
        processStrictBinaryTree(node); // Проверяем узел после замены
    }
}

// Префиксный обход (pre-order traversal)
void BinaryTree::preOrder(Node* node, System::Text::StringBuilder^ sb) {
    if (node == nullptr) return;
    sb->Append(node->key + " ");  // Обработка корня
    preOrder(node->left, sb);     // Рекурсивный вызов для левого поддерева
    preOrder(node->right, sb);    // Рекурсивный вызов для правого поддерева
}

// Инфиксный обход (in-order traversal)
void BinaryTree::inOrder(Node* node, System::Text::StringBuilder^ sb) {
    if (node == nullptr) return;
    inOrder(node->left, sb);      // Рекурсивный вызов для левого поддерева
    sb->Append(node->key + " ");  // Обработка корня
    inOrder(node->right, sb);     // Рекурсивный вызов для правого поддерева
}

// Постфиксный обход (post-order traversal)
void BinaryTree::postOrder(Node* node, System::Text::StringBuilder^ sb) {
    if (node == nullptr) return;
    postOrder(node->left, sb);    // Рекурсивный вызов для левого поддерева
    postOrder(node->right, sb);   // Рекурсивный вызов для правого поддерева
    sb->Append(node->key + " ");  // Обработка корня
}

void BinaryTree::collectElements(Node* node, std::vector<int>& negatives, std::vector<int>& nonNegatives) {
    if (!node) return;

    if (node->key < 0)
        negatives.push_back(node->key);
    else
        nonNegatives.push_back(node->key);

    collectElements(node->left, negatives, nonNegatives);
    collectElements(node->right, negatives, nonNegatives);
}

BinaryTree::Node* BinaryTree::buildBalancedTree(const std::vector<int>& elements, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    Node* node = new Node(elements[mid]);
    node->left = buildBalancedTree(elements, start, mid - 1);
    node->right = buildBalancedTree(elements, mid + 1, end);
    return node;
}

void BinaryTree::splitAndBalance() {
    std::vector<int> negatives, nonNegatives;

    // Собираем элементы исходного дерева
    collectElements(root, negatives, nonNegatives);

    // Сортируем элементы для создания сбалансированных деревьев
    std::sort(negatives.begin(), negatives.end());
    std::sort(nonNegatives.begin(), nonNegatives.end());

    // Создаем два сбалансированных дерева
    negativesRoot = buildBalancedTree(negatives, 0, negatives.size() - 1);
    nonNegativesRoot = buildBalancedTree(nonNegatives, 0, nonNegatives.size() - 1);
}

void BinaryTree::generateRandomKeys(int n, int d_min, int d_max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(d_min, d_max);

    for (int i = 0; i < n; i++) {
        int key = dist(gen);
        //insertBPlus(key);
    }
}

void BinaryTree::insertRedBlack(int key) {
    // Реализация вставки в красно-чёрное дерево
    // Пока можно оставить пустым, если метод планируется позже
}

void BinaryTree::insert(int key) {
    insert(root, key);
}

void BinaryTree::convertToBPlusTree(int m) {
    std::vector<int> elements;
    inorderTraversal(root, elements);
    bPlusRoot = buildBPlusTree(elements, m);
}

void BinaryTree::inorderTraversal(Node* node, std::vector<int>& elements) {
    if (!node) return;
    inorderTraversal(node->left, elements);
    elements.push_back(node->key);
    inorderTraversal(node->right, elements);
}

BinaryTree::BPlusNode* BinaryTree::buildBPlusTree(const std::vector<int>& elements, int m) {
    if (elements.empty()) return nullptr;

    // Шаг 1: Сортируем все элементы
    std::vector<int> sortedElements = elements;
    std::sort(sortedElements.begin(), sortedElements.end());

    // Шаг 2: Создаем листья
    std::queue<BPlusNode*> queue;
    size_t i = 0;
    while (i < sortedElements.size()) {
        BPlusNode* leaf = new BPlusNode(true);

        // Заполняем текущий лист до m-1 элементов
        while (i < sortedElements.size() && leaf->keys.size() < m - 1) {
            leaf->keys.push_back(sortedElements[i++]);
        }

        // Связываем текущий лист с предыдущим
        if (!queue.empty()) {
            queue.back()->next = leaf;
        }

        queue.push(leaf);
    }

    // Шаг 3: Создаем внутренние узлы
    while (queue.size() > 1) {
        size_t size = queue.size();
        BPlusNode* parent = new BPlusNode(false);

        // Строим родительские узлы, собирая ключи из дочерних узлов
        while (!queue.empty()) {
            BPlusNode* child = queue.front();
            queue.pop();
            parent->children.push_back(child);

            // Добавляем первый ключ дочернего узла (если он есть)
            if (!child->keys.empty()) {
                parent->keys.push_back(child->keys.front());
            }

            // Если родитель переполнен, создаем новый родительский узел
            if (parent->keys.size() >= m - 1) {
                queue.push(parent);
                parent = new BPlusNode(false);
            }
        }

        // Добавляем последний родительский узел в очередь
        if (!parent->keys.empty()) {
            queue.push(parent);
        }
    }

    // Шаг 4: Возвращаем корень B+ дерева
    return queue.front();
}

// Преобразование B+ дерева в красно-чёрное дерево
void BinaryTree::convertBPlusToRB() {
    std::vector<int> keys;
    collectKeysFromBPlus(bPlusRoot, keys);
    rbRoot = nullptr;

    for (int key : keys) {
        insertRBNode(key);
    }
}

// Обход B+ дерева для сбора всех ключей
void BinaryTree::collectKeysFromBPlus(BPlusNode* node, std::vector<int>& keys) {
    if (node == nullptr) return;

    // Если узел - лист, собираем ключи
    if (node->isLeaf) {
        for (int key : node->keys) {
            keys.push_back(key);
        }
    }
    else {
        // Рекурсивно проходим по всем дочерним узлам
        for (BPlusNode* child : node->children) {
            collectKeysFromBPlus(child, keys);
        }
    }
}

// Вставка узла в красно-чёрное дерево
void BinaryTree::insertRBNode(int key) {
    RBNode* newNode = new RBNode(key);
    if (rbRoot == nullptr) {
        rbRoot = newNode;
        rbRoot->color = false;  // Корень всегда чёрный
    }
    else {
        RBNode* parent = nullptr;
        RBNode* current = rbRoot;
        while (current != nullptr) {
            parent = current;
            if (key < current->key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        newNode->parent = parent;
        if (key < parent->key) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }

        fixRBTreeViolation(newNode); // После вставки, корректируем дерево
    }
}

// Балансировка дерева (повороты и изменение цвета)
void BinaryTree::fixRBTreeViolation(RBNode* node) {
    while (node != rbRoot && node->parent->color == true) {
        if (node->parent == node->parent->parent->left) {
            RBNode* uncle = node->parent->parent->right;
            if (uncle != nullptr && uncle->color == true) {
                node->parent->color = false;
                uncle->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                rightRotate(node->parent->parent);
            }
        }
        else {
            RBNode* uncle = node->parent->parent->left;
            if (uncle != nullptr && uncle->color == true) {
                node->parent->color = false;
                uncle->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                leftRotate(node->parent->parent);
            }
        }
    }
    rbRoot->color = false;  // Корень всегда чёрный
}

// Левый поворот
void BinaryTree::leftRotate(RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        rbRoot = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Правый поворот
void BinaryTree:: rightRotate(RBNode* x) {
    RBNode* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        rbRoot = y;
    }
    else if (x == x->parent->right) {
        x->parent->right = y;
    }
    else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}
