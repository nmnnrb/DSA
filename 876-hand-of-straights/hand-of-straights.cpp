#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;  // Total cards must be divisible by groupSize
        }

        std::map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        for (auto& [card, count] : cardCount) {
            while (cardCount[card] > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (cardCount[card + i] > 0) {
                        cardCount[card + i]--;
                    } else {
                        return false;  // Not enough cards to form a consecutive group
                    }
                }
            }
        }

        return true;
    }
};