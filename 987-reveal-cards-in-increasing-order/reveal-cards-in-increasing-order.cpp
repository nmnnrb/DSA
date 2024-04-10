class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
         std::sort(deck.begin(), deck.end());
    std::queue<int> indices;
    for (int i = 0; i < deck.size(); ++i) {
        indices.push(i);
    }
    std::vector<int> result(deck.size());
    for (int card : deck) {
        result[indices.front()] = card;
        indices.pop();
        if (!indices.empty()) {
            indices.push(indices.front());
            indices.pop();
        }
    }
    return result;
        
    }
};