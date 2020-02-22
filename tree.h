#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class TreeNode {
private:
    int value;
    TreeNode* root = nullptr;
    std::vector<unique_ptr<TreeNode>> children;

public:
    TreeNode(int val): value(val) {
    }

    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

    TreeNode* AddChild(int child_value) {
        children.push_back(unique_ptr<TreeNode>(new TreeNode(child_value)));
        children.back()->root=this;
        return children.back().get();
    }

    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i)
            std::cout << " ";
        std::cout << "- " << value << "\n";
        for (const auto& child : children)
            child->Print(depth + 1);
    }
};
