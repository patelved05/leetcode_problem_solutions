class BrowserHistory {
private:
    struct Node {
        string url;
        Node* prev;
        Node* next;
        Node(string val) : url(val), prev(nullptr), next(nullptr) {}
    };

    Node* current;

public:
    BrowserHistory(string homepage) { current = new Node(homepage); }

    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    string back(int steps) {
        while (current && current->prev && steps > 0) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    string forward(int steps) {
        while (current && current->next && steps > 0) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */