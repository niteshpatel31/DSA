
template <typename T>
struct Node{
    public:
        T val;
        Node *next{nullptr};
        Node(T val):val(val), next(nullptr){}
};
