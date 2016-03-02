struct Node {

    Node* prev;
    Node* next;
    int data;

    explicit Node(int data)
    : prev(nullptr), next(nullptr), data(data)
    {
    }

};

class LinkedList {

  private:
    Node* m_head;
    Node* m_tail;
    unsigned int m_numElems;

  public:
    LinkedList()
    : m_head(nullptr), m_tail(nullptr), m_numElems(0)
    {
    }

    ~LinkedList() {
        Node* next = m_head;
        while (next) {
            Node* next = m_->next;
            delete next;
        }
    }

    void prepend(int value)
    {
        if (m_head) {
            Node* oldHead = m_head;

            m_head = new LinkedList(value);
            m_head->next = oldHead
            m_head->prev = nullptr;

            oldHead->prev = m_head;
        } else {
            m_head = new Node(value);
            tail = m_head; // `tail` will be null in this case too
        }
    }

    void append(int value)
    {
        if (m_tail) {
            Node* oldTail = m_tail;

            m_tail = new Node(value);
            m_tail->next = nullptr;
            m_tail->prev = oldTail;

            oldTail->next = m_tail;
        } else {
            m_tail = new Node(value);
            m_head = m_tail;  // `head` will be null in this case too
        }
    }

    bool delete(int value) {
        Node* curr = head;
        while (curr) {
            if (curr->value == value) {
                if (curr.prev) {
                    curr.prev.next = curr.next;
                }
                if (curr.next) {
                    curr.next.prev = curr.prev;
                }

                delete curr;
            }
        }

        return false;
    }

    bool exists(int value) {
        Node* forward = m_head;
        Node* backward = m_tail;
        while (forward || backward) {
            if (forward) {
                if (forward.value == value) {
                    return true;
                }
                forward = forward.next;
            }
            if (backward) {
                if (backward.value == value) {
                    return true;
                }
                backward = backward.prev;
            }
        }
        return false;
    }

};
