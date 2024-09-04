#include "DLinkedInt.hpp"
#include <iostream>

int main() {
    DLinkedInt list;
    // Test 1: Insert elements at the start
    list.insertList(10, Position::START);
    list.insertList(20, Position::START);
    list.insertList(30, Position::START);

    std::cout << "After inserting 30, 20, 10 at the start:" << std::endl;
    list.printList(); // Expected Output: 30 -> 20 -> 10

    // Test 2: Insert elements at the end
    list.insertList(40, Position::FINAL);
    list.insertList(50, Position::FINAL);

    std::cout << "After inserting 40, 50 at the end:" << std::endl;
    list.printList(); // Expected Output: 30 -> 20 -> 10 -> 40 -> 50

    // Test 3: Remove element from the start
    list.removeValue(30, false);
    std::cout << "After removing 30 from the start:" << std::endl;
    list.printList(); // Expected Output: 20 -> 10 -> 40 -> 50

    // Test 4: Remove element from the end
    list.removeValue(50, false);
    std::cout << "After removing 50 from the end:" << std::endl;
    list.printList(); // Expected Output: 20 -> 10 -> 40

    // Test 5: Remove a middle element
    list.removeValue(10, false);
    std::cout << "After removing 10 (middle element):" << std::endl;
    list.printList(); // Expected Output: 20 -> 40

    // Test 6: Try removing a non-existent element
    list.removeValue(100, false);
    std::cout << "After trying to remove non-existent 100:" << std::endl;
    list.printList(); // Expected Output: 20 -> 40

    // Test 7: Remove all elements
    list.removeValue(20, false);
    list.removeValue(40, false);
    std::cout << "After removing all elements:" << std::endl;
    list.printList(); // Expected Output: Empty list

    return 0;
}