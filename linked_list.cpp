#include <iostream>
int n, m, t;
template <typename T>
class linked_list {
   private:
    struct node {
        T data;
        node* next;
    };
    node* head;

   public:
    linked_list(T data) {
        head = new node;
        head->data = data;
        head->next = nullptr;
    }
    linked_list() { head = nullptr; }
    ~linked_list() {
        node* temp = head;
        while (temp != nullptr) {
            node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
    void add_tail(T data) {
        node* temp = head;
        if (temp == nullptr) {
            head = new node;
            head->data = data;
            head->next = nullptr;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new node;
        temp->next->data = data;
        temp->next->next = nullptr;
    }
    void add_head(T data) {
        node* temp = new node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    T at(int index) {
        node* temp = head;
        if (temp == nullptr) throw "Index out of range";
        for (int i = 0; i < index; i++) {
            temp = temp->next;
            if (temp == nullptr) throw "Index out of range";
        }
        return temp->data;
    }
    int length() {
        node* temp = head;
        int len = 0;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    void remove(int index) {
        node* temp = head;
        if (temp == nullptr) throw "Index out of range";
        if (index == 0) {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
            if (temp == nullptr) throw "Index out of range";
        }
        node* to_delete = temp->next;
        temp->next = temp->next->next;
        delete to_delete;
    }
    void sort() {
        for (node* i = head; i != nullptr; i = i->next) {
            for (node* j = i->next; j != nullptr; j = j->next) {
                if (i->data > j->data) {
                    T temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
    void merge(linked_list<T>& l) {
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = l.head;
    }
    T operator[](int index) { return at(index); }
};

int main() {
    linked_list<int> l1, l2;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> t;
        l1.add_tail(t);
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> t;
        l2.add_tail(t);
    }
    l1.merge(l2);
    l1.sort();
    for (int i = 0; i < l1.length(); i++) {
        std::cout << l1.at(i) << ' ';
    }
    std::cout << "\n";
    return 0;
}